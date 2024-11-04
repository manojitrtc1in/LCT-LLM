package main

import (
	"fmt"
	"math"
)

type mint struct {
	val uint
}

func newMint(val int64, mod uint) mint {
	if val >= 0 {
		return mint{uint(val % int64(mod))}
	}
	return mint{uint((mod - (-val % int64(mod))) % int64(mod))}
}

func (m *mint) add(other mint, mod uint) {
	m.val += other.val
	if m.val >= mod {
		m.val -= mod
	}
}

func (m *mint) sub(other mint, mod uint) {
	m.val += mod - other.val
	if m.val >= mod {
		m.val -= mod
	}
}

func (m *mint) mul(other mint, mod uint) {
	m.val = uint(int64(m.val) * int64(other.val) % int64(mod))
}

func (m *mint) inverse(mod uint) mint {
	a, b, u, v := int(m.val), int(mod), 1, 0
	for b > 0 {
		t := a / b
		a, b = b, a-t*b
		u, v = v, u-t*v
	}
	return newMint(u, mod)
}

func (m *mint) pow(n int64, mod uint) mint {
	ret := newMint(1, mod)
	mul := m.val
	for n > 0 {
		if n&1 == 1 {
			ret.mul(newMint(mul, mod), mod)
		}
		mul = (mul * mul) % mod
		n >>= 1
	}
	return ret
}

type GroupAdd struct{}

func (g GroupAdd) op(x, y mint) mint {
	res := x
	res.add(y, mod)
	return res
}

func (g GroupAdd) unit() mint {
	return newMint(0, mod)
}

type DualSegTree struct {
	n   int
	log int
	size int
	laz []mint
}

func NewDualSegTree(n int) *DualSegTree {
	log := 1
	for (1 << log) < n {
		log++
	}
	size := 1 << log
	laz := make([]mint, size<<1)
	for i := range laz {
		laz[i] = newMint(0, mod)
	}
	return &DualSegTree{n: n, log: log, size: size, laz: laz}
}

func (seg *DualSegTree) allApply(k int, a mint) {
	seg.laz[k] = seg.laz[k].add(a, mod)
}

func (seg *DualSegTree) get(p int) mint {
	p += seg.size
	for i := seg.log; i >= 1; i-- {
		seg.push(p >> i)
	}
	return seg.laz[p]
}

func (seg *DualSegTree) apply(l, r int, a mint) {
	if l == r {
		return
	}
	l += seg.size
	r += seg.size
	for i := seg.log; i >= 1; i-- {
		if ((l >> i) << i) != l {
			seg.push(l >> i)
		}
		if ((r >> i) << i) != r {
			seg.push((r - 1) >> i)
		}
	}
	l2, r2 := l, r
	for l < r {
		if l&1 == 1 {
			seg.allApply(l, a)
			l++
		}
		if r&1 == 1 {
			r--
			seg.allApply(r, a)
		}
		l >>= 1
		r >>= 1
	}
}

func (seg *DualSegTree) push(k int) {
	seg.allApply(2*k, seg.laz[k])
	seg.allApply(2*k+1, seg.laz[k])
	seg.laz[k] = newMint(0, mod)
}

var mod uint

func solve() {
	var N, m int
	fmt.Scan(&N, &m)
	mod = uint(m)

	seg := NewDualSegTree(N + 1)
	seg.apply(1, 2, newMint(1, mod))

	for n := 1; n <= N; n++ {
		dp := seg.get(n)
		seg.apply(n+1, N+1, dp)
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
			seg.apply(l, r, dp)
		}
	}
	fmt.Println(seg.get(N).val)
}

func main() {
	var T int = 1
	for i := 0; i < T; i++ {
		solve()
	}
}
