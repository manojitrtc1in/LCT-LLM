package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type mint struct {
	v int
}

func (m mint) add(a mint) mint {
	return mint{(m.v + a.v) % mod}
}

func (m mint) sub(a mint) mint {
	return mint{(m.v - a.v + mod) % mod}
}

func (m mint) mul(a mint) mint {
	return mint{(m.v * a.v) % mod}
}

func (m mint) pow(n int) mint {
	res := mint{1}
	for n > 0 {
		if n&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		n >>= 1
	}
	return res
}

func (m mint) inv() mint {
	return m.pow(mod - 2)
}

func (m mint) div(a mint) mint {
	return m.mul(a.inv())
}

func (m mint) String() string {
	return strconv.Itoa(m.v)
}

const mod int = 998244353

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	ls := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		ls[i], _ = strconv.Atoi(scanner.Text())
	}

	tot := 0
	for _, l := range ls {
		tot += l
	}

	buf := make([][][]mint, n)
	for idx, l := range ls {
		s := (l - 1) / k + 1
		f := make([][]mint, s)
		for num := 0; num < s; num++ {
			w := mint{(l - k*num) / tot}
			f[num] = make([]mint, 2)
			if num > 0 {
				f[num][0] = w.pow(num - 1).mul(mint{num - 1}.inv())
			}
			f[num][1] = w.pow(num).mul(mint{num}.inv())
		}
		buf[idx] = f
	}

	pq := make(PriorityQueue, 0)
	for i := 0; i < n; i++ {
		pq.Push(&Item{value: getsz(buf[i]), priority: i})
	}

	for pq.Len() > 1 {
		i := pq.Pop().(*Item).priority
		j := pq.Pop().(*Item).priority
		buf[i] = convolute2d(buf[i], buf[j])
		buf[j] = nil
		pq.Push(&Item{value: getsz(buf[i]), priority: i})
	}

	ans := buf[pq.Pop().(*Item).priority]
	sum := mint{0}
	for num := 1; num < len(ans); num++ {
		f := make([]mint, num+1)
		for i := 0; i < len(ans[num]); i++ {
			if i+num-n >= 0 {
				f[i+num-n] = ans[num][i]
			}
		}
		w := mint{(tot - num*k) / tot}
		val := expGenCoeffSum(w, f)
		if num%2 == 0 {
			val = val.mul(mint{-1})
		}
		sum = sum.add(val)
	}

	fmt.Println(sum)
}

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].value < pq[j].value
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func getsz(x [][][]mint) int {
	return len(x) + len(x[0])
}

func convolute2d(x, y [][][]mint) [][][]mint {
	n1, m1 := len(x), len(x[0])
	n2, m2 := len(y), len(y[0])
	n, m := n1+n2-1, m1+m2-1
	s := 1
	for s < n*m {
		s *= 2
	}
	p := make([]mint, s)
	q := make([]mint, s)
	for i := 0; i < n1; i++ {
		for j := 0; j < m1; j++ {
			p[i*m+j] = x[i][j]
		}
	}
	for i := 0; i < n2; i++ {
		for j := 0; j < m2; j++ {
			q[i*m+j] = y[i][j]
		}
	}
	inplaceFmt(p, false)
	inplaceFmt(q, false)
	for i := 0; i < s; i++ {
		p[i] = p[i].mul(q[i])
	}
	inplaceFmt(p, true)
	res := make([][][]mint, n)
	for i := 0; i < n; i++ {
		res[i] = make([][]mint, m)
		for j := 0; j < m; j++ {
			res[i][j] = p[i*m+j]
		}
	}
	return res
}

func inplaceFmt(f []mint, inv bool) {
	s := len(f)
	L := 30
	g := make([]mint, L)
	ig := make([]mint, L)
	p2 := make([]mint, L)
	if g[0].v == 0 {
		for i := 0; i < L; i++ {
			w := mint{-mint{3}.pow(((mod - 1) >> (i + 2)) * 3)}
			g[i] = w
			ig[i] = w.inv()
			p2[i] = mint{1 << i}.inv()
		}
	}
	if !inv {
		b := s
		if b >>= 1; b > 0 {
			for i := 0; i < b; i++ {
				x := f[i+b].v
				f[i+b].v = f[i].v + mod - x
				f[i].v += x
			}
		}
		if b >>= 1; b > 0 {
			p := mint{1}
			for i := 0; i < s; i += b * 2 {
				for j := i; j < i+b; j++ {
					x := f[j+b].mul(p).v
					f[j+b].v = f[j].v + mod - x
					f[j].v += x
				}
				p = p.mul(g[ctz(i/b+1)])
			}
		}
		for b > 0 {
			if b >>= 1; b > 0 {
				p := mint{1}
				for i := 0; i < s; i += b * 2 {
					for j := i; j < i+b; j++ {
						x := f[j+b].mul(p).v
						f[j].v = (f[j].v + mod2) % mod2
						f[j+b].v = f[j].v + mod - x
						f[j].v += x
					}
					p = p.mul(g[ctz(i/b+1)])
				}
			}
			if b >>= 1; b > 0 {
				p := mint{1}
				for i := 0; i < s; i += b * 2 {
					for j := i; j < i+b; j++ {
						x := f[j+b].mul(p).v
						f[j].v = (f[j].v + mod2) % mod2
						f[j+b].v = f[j].v + mod - x
						f[j].v += x
					}
					p = p.mul(g[ctz(i/b+1)])
				}
			}
		}
	} else {
		b := 1
		if b < s/2 {
			p := mint{1}
			for i := 0; i < s; i += b * 2 {
				for j := i; j < i+b; j++ {
					x := f[j].v + mod2 - f[j+b].v
					f[j].v += f[j+b].v
					f[j].v = f[j].v % mod2
					f[j+b].v = x * p.v % mod
				}
				p = p.mul(ig[ctz(i/b+1)])
			}
			b <<= 1
		}
		for ; b < s/2; b <<= 1 {
			p := mint{1}
			for i := 0; i < s; i += b * 2 {
				for j := i; j < i+b/2; j++ {
					x := f[j].v + mod2 - f[j+b].v
					f[j].v += f[j+b].v
					f[j].v = f[j].v % mod2
					f[j+b].v = x * p.v % mod
				}
				for j := i + b/2; j < i+b; j++ {
					x := f[j].v + mod - f[j+b].v
					f[j].v += f[j+b].v
					f[j+b].v = x * p.v % mod
				}
				p = p.mul(ig[ctz(i/b+1)])
			}
		}
		if b < s {
			for i := 0; i < b; i++ {
				x := f[i+b].v
				f[i+b].v = f[i].v + mod2 - x
				f[i].v += x
			}
		}
		z := p2[lg(s)]
		for i := 0; i < s; i++ {
			f[i] = f[i].mul(z)
		}
	}
}

func ctz(x int) int {
	return bits.TrailingZeros(uint(x))
}

func lg(x int) int {
	return bits.Len(uint(x)) - 1
}

func expGenCoeffSum(a mint, f []mint) mint {
	ans := mint{0}
	w := mint{(1 - a).inv()}
	cur := mint{1}
	for k := 0; k < len(f); k++ {
		cur = cur.mul(w)
		ans = ans.add(fact[k].mul(cur).mul(f[k]))
	}
	return ans
}
