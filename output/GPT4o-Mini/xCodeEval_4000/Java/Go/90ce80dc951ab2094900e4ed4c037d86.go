package main

import (
	"fmt"
	"math/big"
)

type Item struct {
	w    int64
	val  int64
	group int
}

type Solution struct {
	MAX int
	MIN int
}

func (sol *Solution) solution(K int, F []int64, W int) {
	res := int64(0)
	ten := []int{1, 10, 100, 1000, 10000, 100000}

	A := []Item{}
	K--

	if K == 0 {
		num := fmt.Sprintf("%d", W)
		score := int64(0)
		for k := 0; k < len(num); k++ {
			d := int(num[k] - '0')
			if d%3 == 0 {
				score += (F[k] * int64(d/3))
			}
		}
		fmt.Println(score)
		return
	}

	for i := 0; i < 6; i++ {
		weight := int64(ten[i] * 3)
		cur := 0
		for j := 0; j < 32; j++ {
			goVal := 1 << j
			if cur+goVal >= (3*K) {
				remain := int64(3*K - cur)
				item := Item{weight * remain, F[i] * remain, i}
				A = append(A, item)
				break
			}
			item := Item{weight * int64(1 << j), F[i] * int64(1 << j), i}
			cur += (1 << j)
			A = append(A, item)
		}
	}

	pre := make([]int64, W+1)
	dp := make([]int64, W+1)
	for i := range pre {
		pre[i] = -1
	}
	pre[0] = 0

	for i := 1; i < len(A); i++ {
		item := A[i-1]
		dp = make([]int64, W+1)
		for j := range dp {
			dp[j] = -1
		}
		dp[0] = 0
		for j := 1; j < len(dp); j++ {
			dp[j] = max(dp[j], pre[j])
			w := item.w
			val := item.val
			if j < w || pre[j-int(w)] == -1 {
				continue
			}
			dp[j] = max(dp[j], pre[j-int(w)]+val)
			num := fmt.Sprintf("%d", W-j)
			score := int64(0)
			for k := 0; k < len(num); k++ {
				d := int(num[k] - '0')
				if d%3 == 0 {
					score += (F[k] * int64(d/3))
				}
			}
			res = max(res, dp[j]+score)
		}
		pre = dp
	}

	fmt.Println(res)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var T int = 1
	var K int
	var F [6]int64
	var W int

	for t := 0; t < T; t++ {
		fmt.Scan(&K)
		for i := 0; i < 6; i++ {
			fmt.Scan(&F[i])
		}
		fmt.Scan(&W)

		sol := Solution{}
		sol.solution(K, F[:], W)
	}
}
