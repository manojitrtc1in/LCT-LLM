package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type ModInt struct {
	val uint32
	mod uint32
}

func NewModInt(val int64, mod uint32) ModInt {
	if val < 0 {
		val = (val % int64(mod) + int64(mod)) % int64(mod)
	}
	return ModInt{uint32(val % int64(mod)), mod}
}

func (m ModInt) Add(other ModInt) ModInt {
	return NewModInt(int64(m.val+other.val), m.mod)
}

func (m ModInt) Sub(other ModInt) ModInt {
	return NewModInt(int64(m.val+other.mod-other.val), m.mod)
}

func (m ModInt) Mul(other ModInt) ModInt {
	return NewModInt(int64(m.val)*int64(other.val), m.mod)
}

func (m ModInt) Inv() ModInt {
	a, b, u, v := int(m.val), int(m.mod), 1, 0
	for b > 0 {
		q := a / b
		a, b = b, a-q*b
		u, v = v, u-q*v
	}
	return NewModInt(int64(u), m.mod)
}

func (m ModInt) Pow(n int64) ModInt {
	res := NewModInt(1, m.mod)
	base := m
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(base)
		}
		base = base.Mul(base)
		n >>= 1
	}
	return res
}

type GroupAdd struct{}

func (GroupAdd) Op(x, y ModInt) ModInt {
	return x.Add(y)
}

func (GroupAdd) Unit() ModInt {
	return NewModInt(0, 0)
}

type SegmentTree struct {
	n   int
	log int
	size int
	laz []ModInt
}

func NewSegmentTree(n int) *SegmentTree {
	log := 1
	for (1 << log) < n {
		log++
	}
	size := 1 << log
	laz := make([]ModInt, size<<1)
	for i := range laz {
		laz[i] = NewModInt(0, 0)
	}
	return &SegmentTree{n, log, size, laz}
}

func (seg *SegmentTree) AllApply(k int, a ModInt) {
	seg.laz[k] = seg.laz[k].Add(a)
}

func (seg *SegmentTree) Get(p int) ModInt {
	p += seg.size
	for i := seg.log; i >= 1; i-- {
		seg.Push(p >> i)
	}
	return seg.laz[p]
}

func (seg *SegmentTree) Apply(l, r int, a ModInt) {
	if l == r {
		return
	}
	l += seg.size
	r += seg.size
	for l < r {
		if l&1 == 1 {
			seg.AllApply(l, a)
			l++
		}
		if r&1 == 1 {
			r--
			seg.AllApply(r, a)
		}
		l >>= 1
		r >>= 1
	}
}

func (seg *SegmentTree) Push(k int) {
	seg.AllApply(2*k, seg.laz[k])
	seg.AllApply(2*k+1, seg.laz[k])
	seg.laz[k] = seg.laz[k].Unit()
}

func solve() {
	var N, mod int
	fmt.Scan(&N, &mod)
	mint := NewModInt(0, uint32(mod))
	seg := NewSegmentTree(N + 1)
	seg.Apply(1, 2, NewModInt(1, uint32(mod)))

	for n := 1; n <= N; n++ {
		dp := seg.Get(n)
		seg.Apply(n+1, N+1, dp)
		z := 2
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
			seg.Apply(l, r, dp)
		}
	}
	fmt.Println(seg.Get(N).val)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int = 1
	for i := 0; i < T; i++ {
		solve()
	}
}
