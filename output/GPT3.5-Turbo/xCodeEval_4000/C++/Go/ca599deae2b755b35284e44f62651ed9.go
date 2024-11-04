package main

import (
	"fmt"
)

func c132() int {
	var str string
	var n int
	fmt.Scan(&str, &n)

	soln := make([][]int, 2)
	xsoln := make([][]int, 2)
	for i := 0; i < 2; i++ {
		soln[i] = make([]int, n+1)
		xsoln[i] = make([]int, n+1)
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

	for i := 0; i < 2; i++ {
		copy(soln[i], soln[1-i])
	}

	for _, ch := range str[:len(str)-1] {
		xsoln, soln = soln, xsoln
		if ch == 'F' {
			soln[0][0] = 1 + xsoln[0][0]
			soln[1][0] = 1 + xsoln[1][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(1+xsoln[0][j], -xsoln[1][j-1])
				soln[1][j] = min(1+xsoln[1][j], -xsoln[0][j-1])
			}
		} else {
			soln[0][0] = -xsoln[1][0]
			soln[1][0] = -xsoln[0][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(-xsoln[1][j], 1+xsoln[0][j-1])
				soln[1][j] = min(-xsoln[0][j], 1+xsoln[1][j-1])
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
