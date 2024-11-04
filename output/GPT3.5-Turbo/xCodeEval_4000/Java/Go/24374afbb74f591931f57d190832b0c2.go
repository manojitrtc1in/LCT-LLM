package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc *bufio.Scanner

func init() {
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
}

func main() {
	ttt := 1

outer:
	for ttt > 0 {
		ttt--

		A := s()

		if len(A) == 1 && A[0] == '0' {
			fmt.Println("1")
			return
		}

		if A[0] == '0' {
			fmt.Println("0")
			return
		}

		if len(A) == 1 {
			if A[0] == 'X' || A[0] == '_' {
				fmt.Println("1")
				return
			}
		}

		dp := make([][][]int64, len(A)+1)
		for i := range dp {
			dp[i] = make([][]int64, 25)
			for j := range dp[i] {
				dp[i][j] = make([]int64, 11)
			}
		}

		fill(dp)

		fmt.Println(goFunc(A, 0, 0, 10))
	}
}

func goFunc(A string, i, pv, v int) int64 {
	if i == len(A) {
		if pv == 0 {
			return 1
		}
		return 0
	}

	if dp[i][pv][v] != -1 {
		return dp[i][pv][v]
	}

	var ans int64

	if A[i] == '_' {
		for j := 0; j < 10; j++ {
			if i == 0 && j == 0 {
				continue
			}
			y := (pv*10 + j) % 25
			ans += goFunc(A, i+1, y, v)
		}
	} else if A[i] == 'X' {
		if v != 10 {
			ans += goFunc(A, i+1, (pv*10+v)%25, v)
		} else {
			for j := 0; j < 10; j++ {
				if i == 0 && j == 0 {
					continue
				}
				y := (pv*10 + j) % 25
				ans += goFunc(A, i+1, y, j)
			}
		}
	} else {
		num, _ := strconv.Atoi(string(A[i]))
		ans += goFunc(A, i+1, (pv*10+num)%25, v)
	}

	dp[i][pv][v] = ans
	return ans
}

func fill(dp [][][]int64) {
	for i := range dp {
		for j := range dp[i] {
			for k := range dp[i][j] {
				dp[i][j][k] = -1
			}
		}
	}
}

func s() string {
	sc.Scan()
	return sc.Text()
}

func i() int {
	n, _ := strconv.Atoi(s())
	return n
}

func l() int64 {
	n, _ := strconv.ParseInt(s(), 10, 64)
	return n
}
