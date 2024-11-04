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
	return modint{x}
}

func (m modint) add(x modint) modint {
	m.val += x.val
	if m.val >= mod {
		m.val -= mod
	}
	return m
}

func (m modint) sub(x modint) modint {
	m.val += mod - x.val
	if m.val >= mod {
		m.val -= mod
	}
	return m
}

func (m modint) mul(x modint) modint {
	m.val = (m.val * x.val) % mod
	return m
}

func (m modint) pow(n int) modint {
	ret := newModint(1)
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
	for (1 << log) < n {
		log++
	}
	size := 1 << log
	laz := make([]modint, size<<1)
	for i := range laz {
		laz[i] = newModint(0)
	}
	return &dualSegTree{n, log, size, laz}
}

func (t *dualSegTree) reset() {
	for i := range t.laz {
		t.laz[i] = newModint(0)
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
			if ((l >> i) << i) != l {
				t.push(l >> i)
			}
			if ((r >> i) << i) != r {
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

func (t *dualSegTree) push(k int) {
	t.allApply(2*k, t.laz[k])
	t.allApply(2*k+1, t.laz[k])
	t.laz[k] = newModint(0)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	seg := newDualSegTree(N + 1)

	dp := make([]modint, N+1)
	dp[1] = newModint(1)
	for n := 1; n <= N; n++ {
		dp[n] = dp[n].add(seg.get(n))
		seg.apply(n+1, N+1, dp[n])
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
			seg.apply(l, r, dp[n])
		}
	}

	fmt.Println(dp[N].val)
}
