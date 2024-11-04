package main

import (
	"bytes"
	"fmt"
	"os"
)

const mod = 1e9 + 7

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	if n >= 100 {
		fmt.Println(1)
		return
	}
	ans := n * n
	cur := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cur[i] = cur[i-1] ^ l[i-1]
	}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			for k := j + 1; k <= n; k++ {
				if cur[j]^cur[i-1] > cur[k]^cur[j] {
					ans = min(ans, k-i-1)
				}
			}
		}
	}
	if ans == n*n {
		ans = -1
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
