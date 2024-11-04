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

func f(s, t int, D []int) int {
	return D[t]
}

func bfs(aa, bb, lcm int, adj [][]int, D []int) {
	s := aa
	D[0] = 0

	for i := 0; i < 3*lcm; i++ {
		u := (s - i) % lcm
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
}

func main() {
	var a, b, k int
	fmt.Scan(&a, &b, &k)

	lcm := 1
	for i := 2; i <= k; i++ {
		lcm = lcm * i / gcd(lcm, i)
	}

	adj := make([][]int, lcm)
	for i := 0; i < lcm; i++ {
		adj[i] = []int{1}
		for j := 2; j <= k; j++ {
			if i%j != 0 {
				adj[i] = append(adj[i], i%j)
			}
		}
	}

	aa := a % lcm
	bb := b % lcm

	D := make([]int, 3*lcm)
	for i := range D {
		D[i] = math.MaxInt32
	}

	bfs(aa, bb, lcm, adj, D)

	tt := (a - b) / lcm
	tt *= int(D[bb+lcm] - D[bb])

	fmt.Println(D[bb] + tt)
}
