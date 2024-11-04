package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func f(s, t int, D []int) int {
	return D[t]
}

func main() {
	var a, b, k int64
	fmt.Scan(&a, &b, &k)

	lcm := 1
	for i := int64(2); i <= k; i++ {
		lcm = lcm * int(i) / gcd(lcm, int(i))
	}

	adj := make([][]int, lcm)
	for i := 0; i < lcm; i++ {
		adj[i] = []int{1}
		for j := 2; j <= int(k); j++ {
			if i%j != 0 {
				adj[i] = append(adj[i], i%j)
			}
		}
	}

	tt := (a - b) / int64(lcm)

	aa := int(a % int64(lcm))
	bb := int(b % int64(lcm))

	D := make([]int, 3*lcm)
	for i := 0; i < 3*lcm; i++ {
		D[i] = math.MaxInt32
	}
	D[0] = 0

	for i := 0; i < 3*lcm; i++ {
		u := (aa - i + lcm) % lcm

		Du := D[i]

		if Du == math.MaxInt32 {
			continue
		}

		for _, v := range adj[u] {
			D[i+v] = min(D[i+v], Du+1)
		}
	}

	bb = (aa - bb + 3*lcm) % lcm

	tt *= int64(D[bb+lcm] - D[bb])

	fmt.Println(D[bb] + int(tt))
}
