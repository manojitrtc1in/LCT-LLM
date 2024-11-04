package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type Solver struct {
	scanner *bufio.Scanner
	writer  *bufio.Writer
}

func NewSolver() *Solver {
	return &Solver{
		scanner: bufio.NewScanner(os.Stdin),
		writer:  bufio.NewWriter(os.Stdout),
	}
}

func (s *Solver) Solve() {
	var n int
	s.scan(&n)

	e := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var u, v int
		s.scan(&u, &v)
		u--
		v--
		e[u] = append(e[u], v)
		e[v] = append(e[v], u)
	}

	xy := make([][2]int, n)
	for i := 0; i < n; i++ {
		s.scan(&xy[i][0], &xy[i][1])
	}

	subtreeSz := make([]int, n)
	xyMapping := make([]int, n)
	xysIdx := make([][2]float64, n)

	var dfs func(int, int)
	dfs = func(u, p int) {
		subtreeSz[u] = 1
		for _, v := range e[u] {
			if v == p {
				continue
			}
			dfs(v, u)
			subtreeSz[u] += subtreeSz[v]
		}
	}

	dfs(0, -1)

	var getAngle func(int, int) float64
	getAngle = func(i, j int) float64 {
		return math.Atan2(float64(xy[j][1]-xy[i][1]), float64(xy[j][0]-xy[i][0]))
	}

	var sortByAngle func(int, int, int)
	sortByAngle = func(l, r, curXY int) {
		if r < l {
			return
		}
		for i := l; i <= r; i++ {
			xysIdx[i][0] = getAngle(curXY, int(xysIdx[i][1]))
		}
		maxAngle := xysIdx[l][0]
		for i := l; i <= r; i++ {
			if xysIdx[i][0]+math.Pi < maxAngle {
				xysIdx[i][0] += 2 * math.Pi
			}
			maxAngle = math.Max(maxAngle, xysIdx[i][0])
		}
		sort.Slice(xysIdx[l:r+1], func(i, j int) bool {
			return xysIdx[i][0] < xysIdx[j][0]
		})
	}

	var solveRec func(int, int, int, int)
	solveRec = func(l, r, root, parent int) {
		currXY := int(xysIdx[r][1])
		xyMapping[currXY] = root
		sortByAngle(l, r-1, currXY)
		curL := l
		for _, i := range e[root] {
			if i == parent {
				continue
			}
			curR := curL + subtreeSz[i] - 1
			nxtL := curR + 1
			solveRec(curL, curR, i, root)
			curL = nxtL
		}
	}

	solveRec(0, n-1, 0, -1)

	for i := 0; i < n; i++ {
		xyMapping[i]++
	}

	for _, v := range xyMapping {
		fmt.Fprintln(s.writer, v)
	}

	s.writer.Flush()
}

func (s *Solver) scan(a ...interface{}) {
	for i := 0; i < len(a); i++ {
		s.scanner.Scan()
		fmt.Sscan(s.scanner.Text(), a[i])
	}
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
