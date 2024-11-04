package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type modint struct {
	val int
}

func newModint(x int) modint {
	if x >= 0 {
		return modint{x % mod}
	}
	return modint{(mod - (-x) % mod) % mod}
}

func (m modint) add(p modint) modint {
	m.val += p.val
	if m.val >= mod {
		m.val -= mod
	}
	return m
}

func (m modint) sub(p modint) modint {
	m.val += mod - p.val
	if m.val >= mod {
		m.val -= mod
	}
	return m
}

func (m modint) mul(p modint) modint {
	m.val = (m.val * p.val) % mod
	return m
}

func (m modint) inv() modint {
	a := m.val
	b := mod
	u := 1
	v := 0
	for b > 0 {
		t := a / b
		a, b = b, a-t*b
		u, v = v, u-t*v
	}
	if u < 0 {
		u += mod
	}
	return modint{u}
}

func (m modint) pow(n int64) modint {
	ret := modint{1}
	mul := m
	for n > 0 {
		if n&1 == 1 {
			ret = ret.mul(mul)
		}
		mul = mul.mul(mul)
		n >>= 1
	}
	return ret
}

const mod = 1000000007

type dualSegTree struct {
	n    int
	log  int
	size int
	laz  []modint
}

func newDualSegTree(n int) *dualSegTree {
	log := 1
	for 1<<log < n {
		log++
	}
	size := 1 << log
	laz := make([]modint, size<<1)
	for i := range laz {
		laz[i] = modint{0}
	}
	return &dualSegTree{
		n:    n,
		log:  log,
		size: size,
		laz:  laz,
	}
}

func (t *dualSegTree) reset() {
	for i := range t.laz {
		t.laz[i] = modint{0}
	}
}

func (t *dualSegTree) allApply(k int, a modint) {
	t.laz[k] = t.laz[k].add(a)
}

func (t *dualSegTree) get(p int) modint {
	p += t.size
	for i := t.log; i >= 1; i-- {
		t.push(p >> i)
	}
	return t.laz[p]
}

func (t *dualSegTree) getAll() []modint {
	for i := 0; i < t.size; i++ {
		t.push(i)
	}
	return t.laz[t.size : t.size+t.n]
}

func (t *dualSegTree) apply(l, r int, a modint) {
	if l == r {
		return
	}

	l += t.size
	r += t.size

	if true {
		for i := t.log; i >= 1; i-- {
			if (l>>i)<<i != l {
				t.push(l >> i)
			}
			if ((r - 1) >> i) << i != r-1 {
				t.push((r - 1) >> i)
			}
		}
	}

	{
		l2 := l
		r2 := r
		for l < r {
			if l&1 == 1 {
				t.allApply(l, a)
				l++
			}
			if r&1 == 1 {
				r--
				t.allApply(r, a)
			}
			l >>= 1
			r >>= 1
		}
		l = l2
		r = r2
	}
}

func (t *dualSegTree) debug() {
	fmt.Println("dualsegtree getall:", t.getAll())
}

type groupAdd struct{}

func (g groupAdd) op(x, y modint) modint {
	return x.add(y)
}

func (g groupAdd) inverse(x modint) modint {
	return modint{-x.val}
}

func (g groupAdd) power(x modint, n int64) modint {
	return modint{int(n) * x.val}
}

func (g groupAdd) unit() modint {
	return modint{0}
}

func (g groupAdd) commute() bool {
	return true
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	seg := newDualSegTree(N + 1)
	seg.apply(1, 2, modint{1})

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
	solve()
}
