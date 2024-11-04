package main

import (
	"fmt"
)

func gcd(a, b int64) int64 {
	if a < b {
		a, b = b, a
	}

	if b == 0 {
		return a
	}

	if a%b == 0 {
		return b
	}

	return gcd(b, a%b)
}

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int64, N)
	mp := make(map[int64]int)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
		mp[a[i]]++
	}

	b := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&b[i])
	}

	vs := make([]int64, 0)
	for elem, count := range mp {
		if count > 1 {
			vs = append(vs, elem)
		}
	}

	ans := int64(0)
	for i := 0; i < N; i++ {
		isok := false
		for _, elem := range vs {
			if (elem & a[i]) == a[i] {
				isok = true
				break
			}
		}

		if isok {
			ans += b[i]
		}
	}

	fmt.Println(ans)
}
