package main

import (
	"container/heap"
	"fmt"
	"math"
	"math/big"
)

type mint struct {
	v *big.Int
	mod *big.Int
}

func newMint(value int64, mod int64) mint {
	return mint{v: big.NewInt(value).Mod(big.NewInt(value), big.NewInt(mod)), mod: big.NewInt(mod)}
}

func (m mint) add(other mint) mint {
	return newMint(0, m.mod.Int64()).v.Add(m.v, other.v).Mod(m.v, m.mod)
}

func (m mint) sub(other mint) mint {
	return newMint(0, m.mod.Int64()).v.Sub(m.v, other.v).Mod(m.v, m.mod)
}

func (m mint) mul(other mint) mint {
	return newMint(0, m.mod.Int64()).v.Mul(m.v, other.v).Mod(m.v, m.mod)
}

func (m mint) pow(exp int64) mint {
	result := newMint(1, m.mod.Int64())
	base := m
	for exp > 0 {
		if exp%2 == 1 {
			result = result.mul(base)
		}
		base = base.mul(base)
		exp /= 2
	}
	return result
}

func (m mint) inv() mint {
	return m.pow(m.mod.Int64() - 2)
}

func choose(n, k int, mod int64) mint {
	if k > n || k < 0 {
		return newMint(0, mod)
	}
	num := big.NewInt(1)
	den := big.NewInt(1)
	for i := 0; i < k; i++ {
		num.Mul(num, big.NewInt(int64(n-i)))
		den.Mul(den, big.NewInt(int64(i+1)))
	}
	return newMint(0, mod).v.Set(num).Div(num, den).Mod(num, big.NewInt(mod))
}

func readInts(n int) []int {
	var arr []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		arr = append(arr, x)
	}
	return arr
}

func initFact(vmax int) ([]mint, []mint, []mint) {
	fact := make([]mint, vmax)
	finv := make([]mint, vmax)
	invs := make([]mint, vmax)

	fact[0] = newMint(1, 998244353)
	for i := 1; i < vmax; i++ {
		fact[i] = fact[i-1].mul(newMint(int64(i), 998244353))
	}
	finv[vmax-1] = fact[vmax-1].inv()
	for i := vmax - 2; i >= 0; i-- {
		finv[i] = finv[i+1].mul(newMint(int64(i+1), 998244353))
	}
	for i := vmax - 1; i >= 1; i-- {
		invs[i] = finv[i].mul(fact[i-1])
	}
	return fact, finv, invs
}

func slv(n, k int, ls []int, fact []mint, finv []mint) mint {
	tot := 0
	for _, x := range ls {
		tot += x
	}

	buf := make([][][]mint, n)
	for idx := 0; idx < n; idx++ {
		s := (ls[idx]-1)/k + 1
		f := make([][]mint, s)
		for num := 0; num < s; num++ {
			w := newMint(int64(ls[idx]-k*num), int64(tot))
			if num > 0 {
				f[num] = []mint{w.pow(int64(num - 1)).mul(finv[num-1])}
			}
			f[num] = append(f[num], w.pow(int64(num)).mul(finv[num]))
		}
		buf[idx] = f
	}

	pq := &PriorityQueue{}
	for i := 0; i < n; i++ {
		heap.Push(pq, &Item{len(buf[i]), i})
	}

	for i := 0; i < n-1; i++ {
		x := heap.Pop(pq).(*Item)
		y := heap.Pop(pq).(*Item)
		buf[x.index] = id0(buf[x.index], buf[y.index])
		heap.Push(pq, &Item{getsz(buf[x.index]), x.index})
	}

	ans := buf[pq.Top().index]
	sum := newMint(0, 998244353)
	for num := 1; num < len(ans); num++ {
		f := make([]mint, num+1)
		for i := 0; i <= n; i++ {
			if i+num-n >= 0 {
				f[i+num-n] = ans[num][i]
			}
		}
		w := newMint(int64(tot-num*k), int64(tot))
		val := id6(w, f)
		if num%2 == 0 {
			val = val.mul(newMint(-1, 998244353))
		}
		sum = sum.add(val)
	}
	return sum
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	ls := readInts(n)

	fact, finv, _ := initFact(1 << 21)
	result := slv(n, k, ls, fact, finv)
	fmt.Println(result.v)
}

type Item struct {
	value int
	index int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i].value < pq[j].value }

func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

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

func id0(x, y [][]mint) [][]mint {
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
	id1(p, false)
	id1(q, false)
	for i := 0; i < s; i++ {
		p[i] = p[i].mul(q[i])
	}
	id1(p, true)
	res := make([][]mint, n)
	for i := 0; i < n; i++ {
		res[i] = make([]mint, m)
		for j := 0; j < m; j++ {
			res[i][j] = p[i*m+j]
		}
	}
	return res
}

func id1(f []mint, inv bool) {
	// Implementation of id1 function
}

func id6(a mint, f []mint) mint {
	// Implementation of id6 function
}

func getsz(x [][]mint) int {
	return len(x) + len(x[0])
}
