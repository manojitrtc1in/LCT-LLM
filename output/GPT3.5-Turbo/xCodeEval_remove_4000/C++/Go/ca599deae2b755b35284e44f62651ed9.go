package main

import (
	"fmt"
)

func c132() int {
	var str string
	var n int
	fmt.Scan(&str, &n)

	soln := make([][]int, 2)
	id12 := make([][]int, 2)
	for i := 0; i < 2; i++ {
		soln[i] = make([]int, n+1)
		id12[i] = make([]int, n+1)
	}

	if str[len(str)-1] == 'F' {
		for j := 0; j < n+1; j++ {
			if j&1 == 1 {
				soln[0][j] = 0
			} else {
				soln[0][j] = 1
			}
		}
	} else {
		for j := 0; j < n+1; j++ {
			if j&1 == 1 {
				soln[0][j] = 1
			} else {
				soln[0][j] = 0
			}
		}
	}

	copy(soln[0], soln[1])

	for i := len(str) - 2; i >= 0; i-- {
		id12, soln = soln, id12
		if str[i] == 'F' {
			soln[0][0] = 1 + id12[0][0]
			soln[1][0] = 1 + id12[1][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(1+id12[0][j], -id12[1][j-1])
				soln[1][j] = min(1+id12[1][j], -id12[0][j-1])
			}
		} else {
			soln[0][0] = -id12[1][0]
			soln[1][0] = -id12[0][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(-id12[1][j], 1+id12[0][j-1])
				soln[1][j] = min(-id12[0][j], 1+id12[1][j-1])
			}
		}
	}

	return max(soln[0][n], -soln[1][n])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(c132())
}
