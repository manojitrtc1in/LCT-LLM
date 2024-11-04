package main

import (
	"fmt"
	"math"
)

const mod = 1e9 + 7

var dp [20][2][2][10][10]int64
var memo [20][2][2][10][10]int64
var num []int64
var n int64

func solve(ind int64, ti int64, st int64, f int64, pd int64) int64 {
	if ind == n {
		if st > 0 && f == pd {
			return 1
		}
		return 0
	}
	if memo[ind][ti][st][f][pd] != 0 {
		return dp[ind][ti][st][f][pd]
	}
	res := int64(0)
	memo[ind][ti][st][f][pd] = 1
	if ti == 1 {
		for i := int64(0); i < num[ind]; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i)
				} else {
					res += solve(ind+1, 0, st, f, i)
				}
			}
		}
		if num[ind] == 0 {
			res += solve(ind+1, 1, st, f, 0)
		} else {
			if st == 0 {
				res += solve(ind+1, 1, 1, num[ind], num[ind])
			} else {
				res += solve(ind+1, 1, st, f, num[ind])
			}
		}
	} else {
		for i := int64(0); i < 10; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i)
				} else {
					res += solve(ind+1, 0, st, f, i)
				}
			}
		}
	}
	dp[ind][ti][st][f][pd] = res
	return res
}

func main() {
	var l, r int64
	fmt.Scan(&l, &r)

	for r > 0 {
		num = append(num, r%10)
		r /= 10
	}
	n = int64(len(num))
	ans := int64(0)
	for i := range dp {
		for j := range dp[i] {
			for k := range dp[i][j] {
				for m := range dp[i][j][k] {
					for n := range dp[i][j][k][m] {
						dp[i][j][k][m][n] = 0
						memo[i][j][k][m][n] = 0
					}
				}
			}
		}
	}
	ans += solve(0, 1, 0, 0, 0)

	num = nil
	for i := range dp {
		for j := range dp[i] {
			for k := range dp[i][j] {
				for m := range dp[i][j][k] {
					for n := range dp[i][j][k][m] {
						dp[i][j][k][m][n] = 0
						memo[i][j][k][m][n] = 0
					}
				}
			}
		}
	}
	k := l
	for l > 0 {
		num = append(num, l%10)
		l /= 10
	}
	n = int64(len(num))
	ans -= solve(0, 1, 0, 0, 0)

	num = nil
	for k > 0 {
		num = append(num, k%10)
		k /= 10
	}
	if num[0] == num[len(num)-1] {
		ans++
	}
	fmt.Println(ans)
}
