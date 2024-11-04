package main

import (
	"fmt"
	"math"
)

type mint struct {
	v uint
}

type modinfo struct {
	mod  uint
	root uint
	im   uint64
}

type modular struct {
	v uint
}

type vc []mint
type vvc []vc

func multiply(x vc, y vc, same bool) vc {
	n := len(x)
	m := len(y)
	c := make(vc, n+m-1)
	len := 1 << (int(math.Log2(float64(n+m-2))) + 1)
	for i := 0; i < n; i += len {
		for j := 0; j < m; j += len {
			xSub := x[i : i+len]
			ySub := y[j : j+len]
			d := sub(xSub, ySub, same)
			for k := 0; k < len(d); k++ {
				c[i+j+k] += d[k]
			}
		}
	}
	return c
}

func sub(x vc, y vc, same bool) vc {
	n := len(x) + len(y) - 1
	s := 1
	for s < n {
		s *= 2
	}
	z := make(vc, s)
	for i := 0; i < len(x); i++ {
		z[i] = x[i]
	}
	id1(z, false)
	if !same {
		w := make(vc, s)
		for i := 0; i < len(y); i++ {
			w[i] = y[i]
		}
		id1(w, false)
		for i := 0; i < s; i++ {
			z[i] *= w[i]
		}
	} else {
		for i := 0; i < s; i++ {
			z[i] *= z[i]
		}
	}
	id1(z, true)
	z = z[:n]
	return z
}

func id1(f vc, inv bool) {
	const mod uint = 998244353
	const mod2 uint = mod * 2
	const L int = 30
	g := make([]mint, L)
	ig := make([]mint, L)
	p2 := make([]mint, L)
	if g[0].v == 0 {
		for i := 0; i < L; i++ {
			w := mint(-modular{3}.pow(((mod-1)>>(i+2))*3))
			g[i] = w
			ig[i] = w.inv()
			p2[i] = mint(1 << i).inv()
		}
	}
	if !inv {
		b := len(f)
		if b >>= 1 {
			for i := 0; i < b; i++ {
				x := f[i+b].v
				f[i+b].v = f[i].v + mod - x
				f[i].v += x
			}
		}
		if b >>= 1 {
			p := mint(1)
			for i := 0; i < len(f); i += b * 2 {
				for j := i; j < i+b; j++ {
					x := (f[j+b] * p).v
					f[j+b].v = f[j].v + mod - x
					f[j].v += x
				}
				p *= g[bits(i/b)]
			}
		}
		for b > 0 {
			if b >>= 1 {
				p := mint(1)
				for i := 0; i < len(f); i += b * 2 {
					for j := i; j < i+b; j++ {
						x := (f[j+b] * p).v
						f[j+b].v = f[j].v + mod - x
						f[j].v += x
					}
					p *= g[bits(i/b)]
				}
			}
			if b >>= 1 {
				p := mint(1)
				for i := 0; i < len(f); i += b * 2 {
					for j := i; j < i+b; j++ {
						x := (f[j+b] * p).v
						f[j].v = (f[j].v + mod2) % mod2
						f[j+b].v = f[j].v + mod - x
						f[j].v += x
					}
					p *= g[bits(i/b)]
				}
			}
		}
	} else {
		b := 1
		if b < len(f)/2 {
			p := mint(1)
			for i := 0; i < len(f); i += b * 2 {
				for j := i; j < i+b; j++ {
					x := (f[j].v + mod - f[j+b].v) % mod
					f[j].v += f[j+b].v
					f[j+b].v = x * p.v % mod
				}
				p *= ig[bits(i/b)]
			}
			b <<= 1
		}
		for b < len(f)/2 {
			p := mint(1)
			for i := 0; i < len(f); i += b * 2 {
				for j := i; j < i+b/2; j++ {
					x := (f[j].v + mod2 - f[j+b].v) % mod2
					f[j].v += f[j+b].v
					f[j].v = f[j].v % mod2
					f[j+b].v = x * p.v % mod
				}
				for j := i + b/2; j < i+b; j++ {
					x := (f[j].v + mod - f[j+b].v) % mod
					f[j].v += f[j+b].v
					f[j+b].v = x * p.v % mod
				}
				p *= ig[bits(i/b)]
			}
			b <<= 1
		}
		if b < len(f) {
			for i := 0; i < b; i++ {
				x := f[i+b].v
				f[i+b].v = f[i].v + mod2 - x
				f[i].v += x
			}
		}
		z := p2[bits(len(f))]
		for i := 0; i < len(f); i++ {
			f[i] *= z
		}
	}
}

func bits(a int) int {
	if a == 0 {
		return -1
	}
	return 31 - bits.Len(uint(a))
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	ls := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ls[i])
	}
	tot := 0
	for _, l := range ls {
		tot += l
	}
	buf := make([]vvc, n)
	for idx, l := range ls {
		s := (l - 1) / k + 1
		f := make(vvc, s)
		for num := 0; num < s; num++ {
			w := mint(ls[idx]-k*num) / mint(tot)
			if num > 0 {
				f[num][0] = w.pow(num-1) * finv[num-1]
			}
			f[num][1] = w.pow(num) * finv[num]
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
		buf[i] = id0(buf[i], buf[j])
		buf[j] = nil
		pq.Push(&Item{value: getsz(buf[i]), priority: i})
	}
	ans := buf[pq.Pop().(*Item).priority]
	sum := mint(0)
	for num := 1; num < len(ans); num++ {
		f := make(vc, num+1)
		for i := 0; i < len(ans[num]); i++ {
			if i+num-n >= 0 {
				f[i+num-n] = ans[num][i]
			} else {
				if ans[num][i] != 0 {
					panic("assertion failed")
				}
			}
		}
		w := mint(tot-num*k) / mint(tot)
		val := id6(w, f)
		if num%2 == 0 {
			val = -val
		}
		sum += val
	}
	fmt.Println(sum)
}

type Item struct {
	value    int
	priority int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].value < pq[j].value
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}
