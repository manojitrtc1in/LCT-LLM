package main

import (
	"fmt"
)

type id32 struct {
	// Define the necessary fields and methods as per the C++ class
}

func (id *id32) setArc(id10, id28, lowBound, upBound int, cost int64) {
	// Implement the logic from the C++ set_arc method
}

func (id *id32) setSupplyDemandOfNode(id int, excess int) {
	// Implement the logic from the C++ set_supply_demand_of_node method
}

func (id *id32) runCs2() {
	// Implement the logic from the C++ run_cs2 method
}

func f(r, c, m int) int {
	return r*m + c + 1
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	grid := make([][]int, n)
	for i := range grid {
		grid[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&grid[i][j])
		}
	}

	var a, b, c []int
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 != 0 {
				if i > 0 {
					a = append(a, f(i, j, m))
					b = append(b, f(i-1, j, m))
					c = append(c, boolToInt(grid[i][j] != grid[i-1][j]))
				}
				if j > 0 {
					a = append(a, f(i, j, m))
					b = append(b, f(i, j-1, m))
					c = append(c, boolToInt(grid[i][j] != grid[i][j-1]))
				}
				if i+1 < n {
					a = append(a, f(i, j, m))
					b = append(b, f(i+1, j, m))
					c = append(c, boolToInt(grid[i][j] != grid[i+1][j]))
				}
				if j+1 < m {
					a = append(a, f(i, j, m))
					b = append(b, f(i, j+1, m))
					c = append(c, boolToInt(grid[i][j] != grid[i][j+1]))
				}
			}
		}
	}

	numNodes := n * m * 4
	id13 := len(a)

	id8 := id32{}
	for i := 0; i < id13; i++ {
		id8.setArc(a[i], b[i], 0, 1, int64(c[i]))
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 != 0 {
				id8.setSupplyDemandOfNode(f(i, j, m), 1)
			} else {
				id8.setSupplyDemandOfNode(f(i, j, m), -1)
			}
		}
	}
	id8.runCs2()
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}
