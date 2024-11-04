package main

import (
	"fmt"
)

func solve(ind, ti, st, f, pd int, num []int, dp [][][][][]int, memo [][][][][]int) int {
	if ind == len(num) {
		if st > 0 && f == pd {
			return 1
		}
		return 0
	}
	if memo[ind][ti][st][f][pd] != 0 {
		return dp[ind][ti][st][f][pd]
	}
	res := 0
	memo[ind][ti][st][f][pd] = 1
	if ti == 1 {
		for i := 0; i < num[ind]; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i, num, dp, memo)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i, num, dp, memo)
				} else {
					res += solve(ind+1, 0, st, f, i, num, dp, memo)
				}
			}
		}
		if num[ind] == 0 {
			res += solve(ind+1, 1, st, f, 0, num, dp, memo)
		} else {
			if st == 0 {
				res += solve(ind+1, 1, 1, num[ind], num[ind], num, dp, memo)
			} else {
				res += solve(ind+1, 1, st, f, num[ind], num, dp, memo)
			}
		}
	} else {
		for i := 0; i < 10; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i, num, dp, memo)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i, num, dp, memo)
				} else {
					res += solve(ind+1, 0, st, f, i, num, dp, memo)
				}
			}
		}
	}
	dp[ind][ti][st][f][pd] = res
	return res
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	num := make([]int, 0)
	for r > 0 {
		num = append(num, r%10)
		r /= 10
	}
	n := len(num)
	dp := make([][][][][]int, 20)
	memo := make([][][][][]int, 20)
	for i := 0; i < 20; i++ {
		dp[i] = make([][][][]int, 2)
		memo[i] = make([][][][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([][][]int, 2)
			memo[i][j] = make([][][]int, 2)
			for k := 0; k < 2; k++ {
				dp[i][j][k] = make([][]int, 10)
				memo[i][j][k] = make([][]int, 10)
				for l := 0; l < 10; l++ {
					dp[i][j][k][l] = make([]int, 10)
					memo[i][j][k][l] = make([]int, 10)
				}
			}
		}
	}

	ans := solve(0, 1, 0, 0, 0, num, dp, memo)

	num = make([]int, 0)
	for l > 0 {
		num = append(num, l%10)
		l /= 10
	}
	n = len(num)
	ans -= solve(0, 1, 0, 0, 0, num, dp, memo)

	ans += bool(num[0] == num[len(num)-1])
	fmt.Println(ans)
}
