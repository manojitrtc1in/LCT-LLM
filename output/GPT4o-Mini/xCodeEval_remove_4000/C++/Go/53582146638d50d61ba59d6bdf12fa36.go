package main

import (
	"bufio"
	"fmt"
	"os"
)

type modint int

const mod = 998244353

func (m modint) value() int {
	return int(m)
}

func (m *modint) add(rhs modint) {
	*m = (*m + rhs) % modint(mod)
}

func (m *modint) sub(rhs modint) {
	*m = (*m - rhs + modint(mod)) % modint(mod)
}

func (m *modint) mul(rhs modint) {
	*m = (*m * rhs) % modint(mod)
}

func (m *modint) pow(e int) modint {
	res := modint(1)
	base := *m
	for e > 0 {
		if e&1 == 1 {
			res.mul(base)
		}
		base.mul(base)
		e >>= 1
	}
	return res
}

type Solver struct {
	n   int
	tree [][]int
	dp   [][]modint
}

func (s *Solver) leaf(v int) bool {
	return len(s.tree[v]) == 1
}

func (s *Solver) treedp(now, pre int) {
	ndp := &s.dp[now]
	(*ndp)[2] = 1
	for _, to := range s.tree[now] {
		if to == pre {
			continue
		}
		tmp := make([]modint, 3)
		s.treedp(to, now)
		tdp := s.dp[to]

		for i := 0; i < 3; i++ {
			tmp[i] = tdp[2] * (*ndp)[i]
		}

		tmp[0].add((*ndp)[2] * tdp[2])
		tmp[0].add((*ndp)[1] * tdp[2])
		tmp[0].add(((*ndp)[1] + (*ndp)[2]) * tdp[1])
		tmp[0].add(2 * (*ndp)[0] * tdp[0])
		tmp[1].add(((*ndp)[1]*2 + (*ndp)[2]) * tdp[0])
		tmp[2].add((*ndp)[2] * tdp[0])

		*ndp = tmp
	}
}

func NewSolver() *Solver {
	var n int
	fmt.Scan(&n)
	tree := make([][]int, n)
	dp := make([][]modint, n)
	for i := range dp {
		dp[i] = make([]modint, 3)
	}
	for i := 1; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a--
		b--
		tree[a] = append(tree[a], b)
		tree[b] = append(tree[b], a)
	}
	s := &Solver{n: n, tree: tree, dp: dp}
	s.treedp(0, -1)
	rdp := s.dp[0]
	fmt.Println(rdp[0] + rdp[2])
	return s
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	NewSolver()
}
