package main

import (
	"fmt"
	"math/rand"
	"time"
)

const INF = 1000000007
const MOD = 1000000007
const PI = 3.141592653589793

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

func gcdLong(a, b lli) lli {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	if a%b == 0 {
		return b
	}
	return gcdLong(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func lcmLong(a, b lli) lli {
	return a * b / gcdLong(a, b)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var N int
	fmt.Scan(&N)

	a := make([]lli, N)
	b := make([]lli, N)
	mp := make(map[lli]int)

	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
		mp[a[i]]++
	}

	for i := 0; i < N; i++ {
		fmt.Scan(&b[i])
	}

	var vs []lli
	for key, value := range mp {
		if value > 1 {
			vs = append(vs, key)
		}
	}

	var ans lli = 0
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
