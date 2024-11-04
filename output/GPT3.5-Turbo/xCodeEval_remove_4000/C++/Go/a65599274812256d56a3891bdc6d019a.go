package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
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

func bfs(adj [][]int, aa, lcm int) []int {
	D := make([]int, 3*lcm)
	for i := range D {
		D[i] = math.MaxInt32
	}
	D[0] = 0

	for i := 0; i < 3*lcm; i++ {
		u := (aa - i) % lcm
		if u < 0 {
			u += lcm
		}

		Du := D[i]

		if Du == math.MaxInt32 {
			continue
		}

		for _, v := range adj[u] {
			D[i+v] = min(D[i+v], Du+1)
		}
	}

	return D
}

func main() {
	var a, b, k int
	fmt.Scan(&a, &b, &k)

	lcm := 1
	for i := 2; i <= k; i++ {
		lcm = lcm * i / gcd(lcm, i)
	}

	adj := make([][]int, lcm)
	for i := range adj {
		adj[i] = []int{1}
		for j := 2; j <= k; j++ {
			if i%j != 0 {
				adj[i] = append(adj[i], i%j)
			}
		}
	}

	aa, bb := a%lcm, b%lcm

	D := bfs(adj, aa, lcm)

	tt := (a - b) / lcm
	tt *= int(D[bb+lcm] - D[bb])

	fmt.Println(D[bb] + tt)
}
