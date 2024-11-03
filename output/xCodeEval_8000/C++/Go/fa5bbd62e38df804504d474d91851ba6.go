package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type CPaintTree struct{}

func (c *CPaintTree) solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	e := make([][]int, n)
	for i := 0; i < n-1; i++ {
		u := nextInt(scanner) - 1
		v := nextInt(scanner) - 1
		e[u] = append(e[u], v)
		e[v] = append(e[v], u)
	}

	xy := make([][2]int, n)
	for i := 0; i < n; i++ {
		xy[i][0] = nextInt(scanner)
		xy[i][1] = nextInt(scanner)
	}

	subtreeSz := make([]int, n)
	xyMapping := make([]int, n)
	xysIdx := make([][2]float64, n)
	for i := 0; i < n; i++ {
		xysIdx[i][1] = float64(i)
	}
	sort.Slice(xysIdx, func(i, j int) bool {
		return xy[xysIdx[i][1]][0] > xy[xysIdx[j][1]][0] || (xy[xysIdx[i][1]][0] == xy[xysIdx[j][1]][0] && xy[xysIdx[i][1]][1] > xy[xysIdx[j][1]][1])
	})

	var calculateSubtreeSizes func(int, int)
	calculateSubtreeSizes = func(i, p int) {
		subtreeSz[i] = 1
		for _, j := range e[i] {
			if j == p {
				continue
			}
			calculateSubtreeSizes(j, i)
			subtreeSz[i] += subtreeSz[j]
		}
	}

	calculateSubtreeSizes(0, -1)

	var solveRec func(int, int, int, int)
	solveRec = func(l, r, root, parent int) {
		currXY := int(xysIdx[r][1])
		xyMapping[currXY] = root
		sortByAngle(l, r, currXY)
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
		fmt.Printf("%d ", xyMapping[i])
	}
	fmt.Println()
}

func sortByAngle(l, r, curXY int) {
	if r < l {
		return
	}
	maxAngle := getAngle(curXY, int(xysIdx[l][1]), int(xysIdx[l][1]))
	for i := l; i <= r; i++ {
		angle := getAngle(curXY, int(xysIdx[i][1]), int(xysIdx[l][1]))
		if angle+math.Pi < maxAngle {
			angle += 2 * math.Pi
		}
		xysIdx[i][0] = angle
	}
	sort.Slice(xysIdx[l:r+1], func(i, j int) bool {
		return xysIdx[i][0] < xysIdx[j][0]
	})
}

func getAngle(i, j, k int) float64 {
	xDist := float64(xy[j][0] - xy[i][0])
	yDist := float64(xy[j][1] - xy[i][1])
	return math.Atan2(yDist, xDist)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num := 0
	sign := 1
	for _, c := range scanner.Bytes() {
		if c == '-' {
			sign = -1
			continue
		}
		num = num*10 + int(c-'0')
	}
	return num * sign
}

func main() {
	solver := CPaintTree{}
	solver.solve()
}
