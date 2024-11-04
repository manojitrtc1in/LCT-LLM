package main

import (
	"fmt"
	"sort"
)

func solve() int {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)
	k++
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[n-1-i] = int64(a[n-1-i]) * int64(i/max(k, 1))
	}
	for i := n - 1; i >= 0; i-- {
		b[i] += b[i+1]
	}
	cum := int64(0)
	sum := int64(0)
	ans := b[0]
	if k > 0 {
		for i := 0; i < n; i++ {
			res := sum + b[i]
			longest := (n - i - 1) / k + 1
			ans = max(ans, res+cum*int64(longest))
			sum += cum
			cum += int64(a[i])
		}
	}
	fmt.Println(ans)
	return 0
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	solve()
}
