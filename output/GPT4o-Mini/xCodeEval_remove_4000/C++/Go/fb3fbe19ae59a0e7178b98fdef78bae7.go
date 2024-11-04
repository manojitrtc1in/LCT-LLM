package main

import (
	"fmt"
)

const Maxn = 100005

var l [Maxn]int
var r [Maxn]int
var sum [Maxn]int
var dp1 [Maxn]int
var dp2 [Maxn]int
var bit [Maxn]int

func modify(pos int, val int) {
	for pos < Maxn {
		if bit[pos] < val {
			bit[pos] = val
		}
		pos += pos & -pos
	}
}

func query(pos int) int {
	ans := 0
	for pos > 0 {
		if ans < bit[pos] {
			ans = bit[pos]
		}
		pos -= pos & -pos
	}
	return ans
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i], &r[i])
		sum[l[i]]++
		sum[r[i]+1]--
	}
	for i := 1; i <= m; i++ {
		sum[i] += sum[i-1]
	}
	dp1[0] = 0
	for i := 1; i <= m; i++ {
		dp1[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp1[i])
	}
	for i := range bit {
		bit[i] = 0
	}
	for i := m; i >= 1; i-- {
		dp2[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp2[i])
	}
	ans := 0
	for i := 1; i <= m; i++ {
		if ans < dp1[i]+dp2[i]-1 {
			ans = dp1[i] + dp2[i] - 1
		}
	}
	fmt.Println(ans)
}
