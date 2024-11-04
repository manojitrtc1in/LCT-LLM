package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 998244353

type CPaintTree struct{}

type Solver struct {
	n          int
	e          [][]int
	subtreeSz  []int
	xyMapping  []int
	xysIdx     []struct {
		angle float64
		index int
	}
	xy [][]int
}

func (s *Solver) readTree() {
	s.e = make([][]int, s.n)
	for i := 0; i < s.n-1; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		s.e[u] = append(s.e[u], v)
		s.e[v] = append(s.e[v], u)
	}
}

func (s *Solver) readPoints() {
	s.xy = make([][]int, s.n)
	for i := 0; i < s.n; i++ {
		s.xy[i] = make([]int, 2)
		fmt.Scan(&s.xy[i][0], &s.xy[i][1])
	}
}

func (s *Solver) xDist(i, j int) int64 {
	return int64(s.xy[j][0]) - int64(s.xy[i][0])
}

func (s *Solver) yDist(i, j int) int64 {
	return int64(s.xy[j][1]) - int64(s.xy[i][1])
}

func (s *Solver) getAngle(i, j int) float64 {
	return math.Atan2(float64(s.yDist(i, j)), float64(s.xDist(i, j)))
}

func (s *Solver) sortByAngle(l, r, curXY int) {
	if r < l {
		return
	}
	for i := l; i <= r; i++ {
		s.xysIdx[i].angle = s.getAngle(curXY, s.xysIdx[i].index)
	}
	maxAngle := s.xysIdx[l].angle
	for i := l; i <= r; i++ {
		if s.xysIdx[i].angle+math.Pi < maxAngle {
			s.xysIdx[i].angle += 2 * math.Pi
		}
	}
	sort.Slice(s.xysIdx[l:r+1], func(i, j int) bool {
		return s.xysIdx[l+i].angle < s.xysIdx[l+j].angle
	})
}

func (s *Solver) solveRec(l, r, root, parent int) {
	currXY := s.xysIdx[r].index
	s.xyMapping[currXY] = root
	s.sortByAngle(l, r, currXY)
	curL := l
	for _, i := range s.e[root] {
		if i == parent {
			continue
		}
		curR := curL + s.subtreeSz[i] - 1
		nxtL := curR + 1
		s.solveRec(curL, curR, i, root)
		curL = nxtL
	}
}

func (s *Solver) calculateSubtreeSizes(i, p int) {
	s.subtreeSz[i] = 1
	for _, j := range s.e[i] {
		if j == p {
			continue
		}
		s.calculateSubtreeSizes(j, i)
		s.subtreeSz[i] += s.subtreeSz[j]
	}
}

func (s *Solver) solve() {
	fmt.Scan(&s.n)
	s.subtreeSz = make([]int, s.n)
	s.readTree()
	s.readPoints()
	s.xyMapping = make([]int, s.n)
	s.calculateSubtreeSizes(0, -1)
	s.xysIdx = make([]struct {
		angle float64
		index int
	}, s.n)
	for i := 0; i < s.n; i++ {
		s.xysIdx[i].index = i
	}
	api := func(i int) (int, int) {
		return s.xy[i][0], s.xy[i][1]
	}
	sort.Slice(s.xysIdx, func(i, j int) bool {
		return api(s.xysIdx[i].index) > api(s.xysIdx[j].index)
	})
	s.solveRec(0, s.n-1, 0, -1)
	for i := 0; i < s.n; i++ {
		s.xyMapping[i]++
	}
	for _, v := range s.xyMapping {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func (c *CPaintTree) Solve() {
	solver := Solver{}
	solver.solve()
}

func main() {
	var cp CPaintTree
	cp.Solve()
}
