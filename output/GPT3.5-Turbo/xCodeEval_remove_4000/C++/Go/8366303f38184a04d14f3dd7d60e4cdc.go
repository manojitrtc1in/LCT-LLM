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

func id2(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var a, b, k int
	fmt.Scan(&a, &b, &k)

	lcm := 1
	for i := 2; i <= k; i++ {
		lcm = id2(lcm, i)
	}

	adj := make([][]int, lcm)
	for i := 0; i < lcm; i++ {
		adj[i] = make([]int, 0)
		adj[i] = append(adj[i], 1)
		for j := 2; j <= k; j++ {
			if i%j != 0 {
				adj[i] = append(adj[i], i%j)
			}
		}
	}

	tt := (a - b) / lcm

	aa := a % lcm
	bb := b % lcm

	D := make([]int, 3*lcm)
	for i := 0; i < 3*lcm; i++ {
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
			if D[i+v] > Du+1 {
				D[i+v] = Du + 1
			}
		}
	}

	bb = (aa - bb + 3*lcm) % lcm

	tt *= D[bb+lcm] - D[bb]

	fmt.Println(D[bb] + tt)
}
