package main

import (
	"fmt"
)

var a [101010]int64

func cnk(n, k int64) int64 {
	ret := int64(1)
	for i := n - k + 1; i <= n; i++ {
		ret *= i
	}
	for i := int64(1); i <= k; i++ {
		ret /= i
	}
	return ret
}

func solve() {
	var n, k int64
	fmt.Scan(&n, &k)
	if k == 1 {
		fmt.Println(1)
		return
	}
	a[2] = 1
	for i := 3; i <= 10; i++ {
		a[i] = (i - 1) * (a[i-1] + a[i-2])
	}

	ans := int64(1)
	for i := int64(0); i < k; i++ {
		ans += cnk(n, k-i) * a[k-i]
	}

	fmt.Println(ans)
}

func main() {
	solve()
}
