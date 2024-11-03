package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	X, Y int
}

type Solver struct {
	N          int
	Tree       map[int][]int
	Points     []Point
	SubtreeSz  []int
	XYMapping  []int
	XYSIdx     []float64
	XY         []Point
}

func NewSolver() *Solver {
	return &Solver{}
}

func (s *Solver) ReadTree() {
	s.Tree = make(map[int][]int)
	for i := 0; i < s.N-1; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		s.Tree[u] = append(s.Tree[u], v)
		s.Tree[v] = append(s.Tree[v], u)
	}
}

func (s *Solver) ReadPoints() {
	s.Points = make([]Point, s.N)
	for i := 0; i < s.N; i++ {
		fmt.Scan(&s.Points[i].X, &s.Points[i].Y)
	}
}

func (s *Solver) XDist(i, j int) int {
	return s.XY[j].X - s.XY[i].X
}

func (s *Solver) YDist(i, j int) int {
	return s.XY[j].Y - s.XY[i].Y
}

func (s *Solver) GetAngle(i, j int) float64 {
	return math.Atan2(float64(s.YDist(i, j)), float64(s.XDist(i, j)))
}

func (s *Solver) SortByAngle(l, r, curXY int) {
	if r < l {
		return
	}
	for i := l; i <= r; i++ {
		s.XYSIdx[i] = s.GetAngle(curXY, int(s.XYSIdx[i]))
	}
	maxAngle := s.XYSIdx[l]
	for i := l; i <= r; i++ {
		if s.XYSIdx[i]+math.Pi < maxAngle {
			s.XYSIdx[i] += 2 * math.Pi
		}
	}
	sort.Slice(s.XYSIdx[l:r+1], func(i, j int) bool {
		return s.XYSIdx[l+i] < s.XYSIdx[l+j]
	})
}

func (s *Solver) SolveRec(l, r, root, parent int) {
	currXY := int(s.XYSIdx[r])
	s.XYMapping[currXY] = root
	s.SortByAngle(l, r-1, currXY)
	curL := l
	for _, i := range s.Tree[root] {
		if i == parent {
			continue
		}
		curR := curL + s.SubtreeSz[i]
		s.SolveRec(curL, curR-1, i, root)
		curL = curR
	}
}

func (s *Solver) CalculateSubtreeSizes(i, p int) {
	s.SubtreeSz[i] = 1
	for _, j := range s.Tree[i] {
		if j == p {
			continue
		}
		s.CalculateSubtreeSizes(j, i)
		s.SubtreeSz[i] += s.SubtreeSz[j]
	}
}

func (s *Solver) Solve() {
	fmt.Scan(&s.N)
	s.SubtreeSz = make([]int, s.N)
	s.ReadTree()
	s.ReadPoints()
	s.XYMapping = make([]int, s.N)
	s.CalculateSubtreeSizes(0, -1)
	s.XYSIdx = make([]float64, s.N)
	for i := 0; i < s.N; i++ {
		s.XYSIdx[i] = float64(i)
	}
	sort.Slice(s.XYSIdx, func(i, j int) bool {
		return s.Points[int(s.XYSIdx[i])].X > s.Points[int(s.XYSIdx[j])].X
	})
	s.SolveRec(0, s.N-1, 0, -1)
	for i := 0; i < s.N; i++ {
		s.XYMapping[i]++
	}
	for _, v := range s.XYMapping {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
