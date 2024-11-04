package main

import (
	"fmt"
)

type lli int64

func gcd(a, b int) int {
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

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]lli, N)
	mp := make(map[lli]int)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
		mp[a[i]]++
	}

	b := make([]lli, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&b[i])
	}

	vs := make([]lli, 0)
	for elem, count := range mp {
		if count > 1 {
			vs = append(vs, elem)
		}
	}

	ans := lli(0)
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
