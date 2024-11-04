package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	dp      [][][]int64
	mod     = int64(998244353)
	bit     []int64
	bit1    []int64
	m       = make(map[int]int)
	scanner = bufio.NewScanner(os.Stdin)
)

func main() {
	ttt := 1
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
		dp = make([][][]int64, len(A)+1)
		for i := range dp {
			dp[i] = make([][]int64, 25)
			for j := range dp[i] {
				dp[i][j] = make([]int64, 11)
				fill(dp[i][j])
			}
		}
		fmt.Println(goFunc(A, 0, 0, 10))
	}
}

func goFunc(A []byte, i, pv, v int) int64 {
	if i == len(A) {
		if pv == 0 {
			return 1
		}
		return 0
	}
	if dp[i][pv][v] != -1 {
		return dp[i][pv][v]
	}
	ans := int64(0)
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
		ans += goFunc(A, i+1, (pv*10+int(A[i]-'0'))%25, v)
	}
	return dp[i][pv][v] = ans
}

func fill(dp []int64) {
	for i := range dp {
		dp[i] = -1
	}
}

func s() []byte {
	scanner.Scan()
	return []byte(scanner.Text())
}

func i() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func l() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}
