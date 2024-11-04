package main

import (
	"container/heap"
	"fmt"
	"math/big"
)

type mint struct {
	v *big.Int
	mod *big.Int
}

func newMint(value int64, mod int64) mint {
	return mint{v: big.NewInt(value).Mod(big.NewInt(value), big.NewInt(mod)), mod: big.NewInt(mod)}
}

func (m mint) add(rhs mint) mint {
	return newMint(0, m.mod.Int64()).set(m.v.Add(m.v, rhs.v).Mod(m.v, m.mod))
}

func (m mint) sub(rhs mint) mint {
	return newMint(0, m.mod.Int64()).set(m.v.Sub(m.v, rhs.v).Mod(m.v, m.mod))
}

func (m mint) mul(rhs mint) mint {
	return newMint(0, m.mod.Int64()).set(m.v.Mul(m.v, rhs.v).Mod(m.v, m.mod))
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

func (m *mint) set(value *big.Int) mint {
	m.v.Set(value)
	return *m
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

func readGraph(n, m int) [][]int {
	g := make([][]int, n)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	return g
}

func convolute2D(x, y [][]mint) [][]mint {
	n1, m1 := len(x), len(x[0])
	n2, m2 := len(y), len(y[0])
	n, m := n1+n2-1, m1+m2-1
	p := make([]mint, n*m)
	q := make([]mint, n*m)

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

	// Placeholder for inplace_fmt function
	// Perform FFT or similar operation here

	for i := 0; i < len(p); i++ {
		p[i] = p[i].mul(q[i])
	}

	// Placeholder for inverse FFT or similar operation here

	res := make([][]mint, n)
	for i := range res {
		res[i] = make([]mint, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res[i][j] = p[i*m+j]
		}
	}
	return res
}

func expGenCoeffSum(a mint, f []mint) mint {
	if a.v.Cmp(big.NewInt(1)) == 0 {
		return mint{}
	}
	k := len(f) - 1
	if a.v.Cmp(big.NewInt(0)) == 0 {
		return f[0]
	}
	g := make([]mint, k+1)
	r := mint{v: big.NewInt(1), mod: a.mod}
	for i := 0; i <= k; i++ {
		g[i] = f[i].mul(r)
		r = r.mul(a)
	}
	var c mint
	w := mint{v: big.NewInt(0), mod: a.mod}
	r = mint{v: big.NewInt(1), mod: a.mod}
	for i := 0; i <= k; i++ {
		w = w.add(newMint(0, a.mod.Int64()).mul(newMint(int64(choose(k+1, i)), a.mod.Int64()), r))
		r = r.mul(newMint(-1, a.mod.Int64()))
		c = c.add(g[k-i].mul(w))
	}
	return c.mul(newMint(1, a.mod.Int64()).sub(a).inv().pow(k + 1))
}

func choose(n, k int) int64 {
	if k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}
	return choose(n-1, k-1) + choose(n-1, k)
}

func slv() {
	var n, k int
	fmt.Scan(&n, &k)
	ls := readInts(n)
	tot := 0
	for _, l := range ls {
		tot += l
	}
	buf := make([][][]mint, n)
	for idx := 0; idx < n; idx++ {
		s := (ls[idx]-1)/k + 1
		f := make([][]mint, s)
		for num := 0; num < s; num++ {
			w := newMint(int64(ls[idx]-k*num), int64(tot))
			if num > 0 {
				f[num] = append(f[num], w.pow(int64(num-1)).mul(newMint(1, int64(num-1))))
			}
			f[num] = append(f[num], w.pow(int64(num)).mul(newMint(1, int64(num))))
		}
		buf[idx] = f
	}

	pq := &PriorityQueue{}
	for i := 0; i < n; i++ {
		heap.Push(pq, &Item{value: getsz(buf[i]), index: i})
	}

	for i := 0; i < n-1; i++ {
		item1 := heap.Pop(pq).(*Item)
		item2 := heap.Pop(pq).(*Item)
		buf[item1.index] = convolute2D(buf[item1.index], buf[item2.index])
		buf[item2.index] = nil
		heap.Push(pq, &Item{value: getsz(buf[item1.index]), index: item1.index})
	}

	ans := buf[pq.Top().index]
	var sum mint
	for num := 1; num < len(ans); num++ {
		f := make([]mint, num+1)
		for i := 0; i <= n; i++ {
			if i+num-n >= 0 {
				f[i+num-n] = ans[num][i]
			} else {
				if ans[num][i].v.Cmp(big.NewInt(0)) != 0 {
					panic("unexpected value")
				}
			}
		}
		w := newMint(int64(tot-num*k), int64(tot))
		val := expGenCoeffSum(w, f)
		if num%2 == 0 {
			val = val.mul(newMint(-1, 0))
		}
		sum = sum.add(val)
	}
	fmt.Println(sum.v.String())
}

func main() {
	var mod int64 = 998244353
	mintMod := newMint(0, mod)
	initFact()
	slv()
}

func initFact() {
	// Placeholder for factorial initialization
}
