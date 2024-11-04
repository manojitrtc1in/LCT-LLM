package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type ModInt struct {
	val uint
	mod uint
}

func NewModInt(val, mod uint) ModInt {
	return ModInt{val: val % mod, mod: mod}
}

func (m ModInt) Add(other ModInt) ModInt {
	return NewModInt(m.val+other.val, m.mod)
}

func (m ModInt) Sub(other ModInt) ModInt {
	return NewModInt(m.val+other.mod-other.val, m.mod)
}

func (m ModInt) Mul(other ModInt) ModInt {
	return NewModInt(m.val*other.val, m.mod)
}

func (m ModInt) Pow(exp uint) ModInt {
	result := NewModInt(1, m.mod)
	base := m
	for exp > 0 {
		if exp%2 == 1 {
			result = result.Mul(base)
		}
		base = base.Mul(base)
		exp /= 2
	}
	return result
}

type GroupAdd struct {
	val ModInt
}

type SegmentTree struct {
	n   int
	log int
	laz []GroupAdd
}

func NewSegmentTree(n int) *SegmentTree {
	log := 1
	for (1 << log) < n {
		log++
	}
	size := 1 << log
	laz := make([]GroupAdd, size<<1)
	for i := range laz {
		laz[i] = GroupAdd{val: NewModInt(0, 0)}
	}
	return &SegmentTree{n: n, log: log, laz: laz}
}

func (st *SegmentTree) Apply(l, r int, a GroupAdd) {
	if l == r {
		return
	}
	l += (1 << st.log)
	r += (1 << st.log)

	for l < r {
		if l&1 != 0 {
			st.laz[l] = GroupAdd{val: st.laz[l].val.Add(a.val)}
			l++
		}
		if r&1 != 0 {
			r--
			st.laz[r] = GroupAdd{val: st.laz[r].val.Add(a.val)}
		}
		l >>= 1
		r >>= 1
	}
}

func (st *SegmentTree) Get(p int) ModInt {
	p += (1 << st.log)
	for i := st.log; i >= 1; i-- {
		st.push(p >> i)
	}
	return st.laz[p].val
}

func (st *SegmentTree) push(k int) {
	st.laz[k<<1] = GroupAdd{val: st.laz[k<<1].val.Add(st.laz[k].val)}
	st.laz[k<<1|1] = GroupAdd{val: st.laz[k<<1|1].val.Add(st.laz[k].val)}
	st.laz[k] = GroupAdd{val: NewModInt(0, 0)}
}

func solve() {
	var N, mod uint
	fmt.Scan(&N, &mod)
	mint := NewModInt(0, mod)

	seg := NewSegmentTree(int(N + 1))
	dp := make([]ModInt, N+1)
	dp[1] = NewModInt(1, mod)

	for n := uint(1); n <= N; n++ {
		dp[n] = dp[n].Add(seg.Get(int(n)))
		seg.Apply(int(n+1), int(N+1), dp[n])
		z := uint(2)
		for {
			l := n * z
			r := (n + 1) * z
			if l > N {
				break
			}
			z++
			if r > N+1 {
				r = N + 1
			}
			seg.Apply(int(l), int(r), dp[n])
		}
	}

	fmt.Println(dp[N].val)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	T = 1

	for i := 0; i < T; i++ {
		solve()
	}
}
