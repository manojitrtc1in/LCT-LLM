package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	// Call the function here
	c388()
}

func c388() {
	var n int
	fmt.Scan(&n)

	xs := make([][]int, n)
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)
		xs[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&xs[i][j])
		}
	}

	k := 0
	for _, row := range xs {
		k += len(row)
	}
	fmt.Println(k)

	acc := 0
	for _, row := range xs {
		for _, val := range row {
			acc += val
		}
	}
	fmt.Println(acc)

	left := make([]int, n)
	right := make([]int, n)

	leftAcc := 0
	for j := 0; j < k; j++ {
		imax := 0
		for xs[imax] == nil || len(xs[imax]) == left[imax]+right[imax] {
			imax++
		}

		val := getGain(xs[imax], left[imax], right[imax])

		for i := imax + 1; i < n; i++ {
			if xs[i] != nil && left[i]+right[i] < len(xs[i]) {
				g := getGain(xs[i], left[i], right[i])
				if val < g {
					val = g
					imax = i
				}
			}
		}

		if j%2 == 1 {
			right[imax]++
		} else {
			leftAcc += xs[imax][left[imax]]
			left[imax]++
		}
	}

	fmt.Println(leftAcc, acc-leftAcc)
}

func getGain(xs []int, l, r int) int {
	len := len(xs) - l - r
	if len%2 == 1 {
		return xs[l+len/2]
	}
	return 0
}
