package main

import (
	"fmt"
	"math"
	"sort"
)

type CPaintTree struct{}

func (c *CPaintTree) solve() {
	var n int
	fmt.Scan(&n)

	// Read the tree
	tree := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		tree[u] = append(tree[u], v)
		tree[v] = append(tree[v], u)
	}

	// Read the points
	points := make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&points[i][0], &points[i][1])
	}

	// Sort the points by angle
	angles := make([]float64, n)
	for i := 0; i < n; i++ {
		angles[i] = math.Atan2(float64(points[i][1]), float64(points[i][0]))
	}
	sort.Slice(angles, func(i, j int) bool {
		return angles[i] < angles[j]
	})

	// Create a mapping from points to tree nodes
	mapping := make([]int, n)
	for i := 0; i < n; i++ {
		mapping[i] = i + 1
	}

	// Print the mapping
	for _, node := range mapping {
		fmt.Println(node)
	}
}

func main() {
	solver := CPaintTree{}
	solver.solve()
}
