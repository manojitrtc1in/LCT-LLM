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
		fmt.Println(go(A, 0, 0, 10))
	}
}

func go(A string, i, pv, v int) int64 {
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
			ans += go(A, i+1, y, v)
		}
	} else if A[i] == 'X' {
		if v != 10 {
			ans += go(A, i+1, (pv*10+v)%25, v)
		} else {
			for j := 0; j < 10; j++ {
				if i == 0 && j == 0 {
					continue
				}
				y := (pv*10 + j) % 25
				ans += go(A, i+1, y, j)
			}
		}
	} else {
		ans += go(A, i+1, (pv*10+int(A[i]-'0'))%25, v)
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
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func l() int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}
