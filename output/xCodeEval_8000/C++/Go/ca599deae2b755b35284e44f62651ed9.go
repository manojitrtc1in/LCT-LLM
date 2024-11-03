package main

import (
	"fmt"
	"math"
	"strings"
)

func chmod(num string, n, m int) string {
	digit := "0123456789abcdefghijklmnopqrstuvwxyz"
	num = strings.ToLower(num)

	if n == 10 {
		var val int
		fmt.Sscanf(num, "%d", &val)
		return fmt.Sprintf("%d", val)
	} else {
		val := 0
		for _, ch := range num {
			val = val*n + strings.Index(digit, string(ch))
		}

		if m == 10 {
			return fmt.Sprintf("%d", val)
		} else {
			res := ""
			for val > 0 {
				res = string(digit[val%m]) + res
				val /= m
			}

			if len(res) == 0 {
				return "0"
			}
			return res
		}
	}
}

func main() {
	str := ""
	n := 0
	fmt.Scan(&str, &n)

	soln := make([][]int, 2)
	xsoln := make([][]int, 2)

	if str[len(str)-1] == 'F' {
		for j := 0; j < n+1; j++ {
			if j&1 == 1 {
				soln[0] = append(soln[0], 0)
			} else {
				soln[0] = append(soln[0], 1)
			}
		}
	} else {
		for j := 0; j < n+1; j++ {
			if j&1 == 1 {
				soln[0] = append(soln[0], 1)
			} else {
				soln[0] = append(soln[0], 0)
			}
		}
	}

	copy(soln[0], soln[1])

	for i := len(str) - 2; i >= 0; i-- {
		xsoln, soln = soln, xsoln
		if str[i] == 'F' {
			soln[0][0] = 1 + xsoln[0][0]
			soln[1][0] = 1 + xsoln[1][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = int(math.Max(float64(1+xsoln[0][j]), -float64(xsoln[1][j-1])))
				soln[1][j] = int(math.Min(float64(1+xsoln[1][j]), -float64(xsoln[0][j-1])))
			}
		} else {
			soln[0][0] = -xsoln[1][0]
			soln[1][0] = -xsoln[0][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = int(math.Max(-float64(xsoln[1][j]), float64(1+xsoln[0][j-1])))
				soln[1][j] = int(math.Min(-float64(xsoln[0][j]), float64(1+xsoln[1][j-1])))
			}
		}
	}

	fmt.Println(int(math.Max(float64(soln[0][n]), -float64(soln[1][n]))))
}
