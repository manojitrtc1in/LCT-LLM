package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 998244353

type modint int

func (m modint) Value() int {
	return int(m)
}

func (m *modint) Add(rhs modint) {
	*m = (*m + rhs) % modint(mod)
}

func (m *modint) Sub(rhs modint) {
	*m = (*m - rhs + modint(mod)) % modint(mod)
}

func (m *modint) Mul(rhs modint) {
	*m = (*m * rhs) % modint(mod)
}

type Solver struct {
	n   int
	tree [][]int
	dp   [][]modint
}

func NewSolver(n int) *Solver {
	return &Solver{
		n:    n,
		tree: make([][]int, n),
		dp:   make([][]modint, n),
	}
}

func (s *Solver) Leaf(v int) bool {
	return len(s.tree[v]) == 1
}

func (s *Solver) TreeDP(now, pre int) {
	ndp := s.dp[now]
	ndp[2] = 1
	for _, to := range s.tree[now] {
		if to == pre {
			continue
		}
		tmp := make([]modint, 3)
		s.TreeDP(to, now)
		tdp := s.dp[to]

		for i := 0; i < 3; i++ {
			tmp[i] = tdp[2] * ndp[i]
		}

		tmp[0] += ndp[2]*tdp[2] + ndp[1]*tdp[2]

		tmp[0] += (ndp[1] + ndp[2]) * tdp[1]

		tmp[0] += 2 * ndp[0] * tdp[0]
		tmp[1] += (ndp[1]*2 + ndp[2]) * tdp[0]
		tmp[2] += ndp[2] * tdp[0]

		copy(ndp, tmp)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	solver := NewSolver(n)
	for i := 1; i < n; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		a--
		b--
		solver.tree[a] = append(solver.tree[a], b)
		solver.tree[b] = append(solver.tree[b], a)
	}
	for i := range solver.dp {
		solver.dp[i] = make([]modint, 3)
	}
	solver.TreeDP(0, -1)

	rdp := solver.dp[0]
	fmt.Fprintln(writer, rdp[0]+rdp[2])
}
