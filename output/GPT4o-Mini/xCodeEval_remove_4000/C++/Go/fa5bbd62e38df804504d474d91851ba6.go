package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 998244353

type AssignmentHook struct {
	ref  *int
	hook func(prev, cur int)
}

func NewAssignmentHook(value *int, hook func(prev, cur int)) AssignmentHook {
	return AssignmentHook{ref: value, hook: hook}
}

func (ah *AssignmentHook) Set(rhs int) {
	prev := *ah.ref
	*ah.ref = rhs
	ah.hook(prev, rhs)
}

func (ah *AssignmentHook) Get() int {
	return *ah.ref
}

type CPaintTree struct {
	n           int
	e           [][]int
	subtreeSz   []int
	xyMapping   []int
	xysIdx      []struct {
		angle float64
		index int
	}
	xy [][]int
}

func (cpt *CPaintTree) ReadTree() {
	cpt.e = make([][]int, cpt.n)
	for i := 0; i < cpt.n-1; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		cpt.e[u] = append(cpt.e[u], v)
		cpt.e[v] = append(cpt.e[v], u)
	}
}

func (cpt *CPaintTree) ReadPoints() {
	cpt.xy = make([][]int, cpt.n)
	for i := 0; i < cpt.n; i++ {
		cpt.xy[i] = make([]int, 2)
		fmt.Scan(&cpt.xy[i][0], &cpt.xy[i][1])
	}
}

func (cpt *CPaintTree) XDist(i, j int) int {
	return cpt.xy[j][0] - cpt.xy[i][0]
}

func (cpt *CPaintTree) YDist(i, j int) int {
	return cpt.xy[j][1] - cpt.xy[i][1]
}

func (cpt *CPaintTree) GetAngle(i, j int) float64 {
	return math.Atan2(float64(cpt.YDist(i, j)), float64(cpt.XDist(i, j)))
}

func (cpt *CPaintTree) SortByAngle(l, r, curXY int) {
	if r < l {
		return
	}
	for i := l; i <= r; i++ {
		cpt.xysIdx[i].angle = cpt.GetAngle(curXY, cpt.xysIdx[i].index)
	}
	maxAngle := cpt.xysIdx[l].angle
	for i := l; i <= r; i++ {
		if cpt.xysIdx[i].angle > maxAngle {
			maxAngle = cpt.xysIdx[i].angle
		}
	}
	for i := l; i <= r; i++ {
		if cpt.xysIdx[i].angle+math.Pi < maxAngle {
			cpt.xysIdx[i].angle += 2 * math.Pi
		}
	}
	sort.Slice(cpt.xysIdx[l:r+1], func(i, j int) bool {
		return cpt.xysIdx[l+i].angle < cpt.xysIdx[l+j].angle
	})
}

func (cpt *CPaintTree) SolveRec(l, r, root, parent int) {
	currXY := cpt.xysIdx[r].index
	cpt.xyMapping[currXY] = root
	cpt.SortByAngle(l, r, currXY)
	curL := l
	for _, i := range cpt.e[root] {
		if i == parent {
			continue
		}
		curR := curL + cpt.subtreeSz[i] - 1
		id3 := curR + 1
		cpt.SolveRec(curL, curR, i, root)
		curL = id3
	}
}

func (cpt *CPaintTree) CalculateSubtreeSizes(i, p int) {
	cpt.subtreeSz[i] = 1
	for _, j := range cpt.e[i] {
		if j == p {
			continue
		}
		cpt.CalculateSubtreeSizes(j, i)
		cpt.subtreeSz[i] += cpt.subtreeSz[j]
	}
}

func (cpt *CPaintTree) Solve() {
	fmt.Scan(&cpt.n)
	cpt.subtreeSz = make([]int, cpt.n)
	cpt.ReadTree()
	cpt.ReadPoints()
	cpt.xyMapping = make([]int, cpt.n)
	cpt.CalculateSubtreeSizes(0, -1)
	cpt.xysIdx = make([]struct {
		angle float64
		index int
	}, cpt.n)
	for i := 0; i < cpt.n; i++ {
		cpt.xysIdx[i].index = i
	}
	sort.Slice(cpt.xysIdx, func(i, j int) bool {
		return cpt.xy[cpt.xysIdx[i].index][0] > cpt.xy[cpt.xysIdx[j].index][0]
	})
	cpt.SolveRec(0, cpt.n-1, 0, -1)
	for i := 0; i < cpt.n; i++ {
		cpt.xyMapping[i]++
	}
	for _, val := range cpt.xyMapping {
		fmt.Print(val, " ")
	}
	fmt.Println()
}

func main() {
	var solver CPaintTree
	solver.Solve()
}
