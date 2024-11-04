package main

import (
	"fmt"
)

type modint struct {
	val int
}

func newModint(v int) modint {
	v %= 998244353
	if v < 0 {
		v += 998244353
	}
	return modint{val: v}
}

func (m modint) add(rhs modint) modint {
	m.val += rhs.val
	if m.val >= 998244353 {
		m.val -= 998244353
	}
	return m
}

func (m modint) sub(rhs modint) modint {
	m.val -= rhs.val
	if m.val < 0 {
		m.val += 998244353
	}
	return m
}

func (m modint) mul(rhs modint) modint {
	m.val = (m.val * rhs.val) % 998244353
	return m
}

func (m modint) pow(e int) modint {
	res := newModint(1)
	for e > 0 {
		if e&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		e >>= 1
	}
	return res
}

func (m modint) inv() modint {
	return m.pow(998244353 - 2)
}

func (m modint) div(rhs modint) modint {
	return m.mul(rhs.inv())
}

func (m modint) equal(rhs modint) bool {
	return m.val == rhs.val
}

func (m modint) notEqual(rhs modint) bool {
	return m.val != rhs.val
}

func (m modint) toString() string {
	return fmt.Sprintf("%d", m.val)
}

type solver struct {
	n    int
	tree [][]int
	dp   [][]modint
}

func (s *solver) leaf(v int) bool {
	return len(s.tree[v]) == 1
}

func (s *solver) treedp(now, pre int) {
	ndp := make([]modint, 3)
	ndp[2] = newModint(1)
	for _, to := range s.tree[now] {
		if to == pre {
			continue
		}
		var tmp [3]modint
		s.treedp(to, now)
		tdp := s.dp[to]

		for i := 0; i < 3; i++ {
			tmp[i] = tdp[2].mul(ndp[i])
		}

		tmp[0] = tmp[0].add(tdp[2].mul(ndp[0])).add(tdp[2].mul(ndp[1]))
		tmp[0] = tmp[0].add((ndp[1].add(ndp[2])).mul(tdp[1]))
		tmp[0] = tmp[0].add(newModint(2).mul(ndp[0]).mul(tdp[0]))
		tmp[1] = tmp[1].add((ndp[1].mul(newModint(2)).add(ndp[2])).mul(tdp[0]))
		tmp[2] = tmp[2].add(ndp[2].mul(tdp[0]))

		copy(ndp, tmp[:])
	}
	s.dp[now] = ndp
}

func newSolver() *solver {
	var s solver
	fmt.Scan(&s.n)
	s.tree = make([][]int, s.n)
	s.dp = make([][]modint, s.n)
	for i := 1; i < s.n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		s.tree[a] = append(s.tree[a], b)
		s.tree[b] = append(s.tree[b], a)
	}
	s.treedp(0, -1)
	rdp := s.dp[0]
	return &s
}

func (s *solver) solve() {
	fmt.Println(s.dp[0][0].add(s.dp[0][2]).toString())
}

func main() {
	s := newSolver()
	s.solve()
}
