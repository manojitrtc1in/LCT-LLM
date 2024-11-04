package main

import (
	"fmt"
	"sort"
)

const id10 = 1000000007

func normmod(x *int64, m int64) {
	*x %= m
	if *x < 0 {
		*x += m
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func solve() int64 {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)
	k++
	a := make([]int64, n)
	b := make([]int64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})

	for i := 0; i < n; i++ {
		b[n-1-i] = a[n-1-i] * int64(i/max(k, 1))
	}
	for i := n - 1; i >= 0; i-- {
		if i+1 < n {
			b[i] += b[i+1]
		}
	}

	var cum, sum, ans int64 = 0, 0, b[0]
	if k > 0 {
		for i := 0; i < n; i++ {
			res := sum + b[i]
			longest := (n - i - 1) / k + 1
			ans = max(ans, res+cum*longest)
			sum += cum
			cum += a[i]
		}
	}
	fmt.Println(ans)
	return ans
}

func main() {
	solve()
}
