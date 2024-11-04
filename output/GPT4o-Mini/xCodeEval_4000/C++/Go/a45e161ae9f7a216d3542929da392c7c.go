package main

import (
	"fmt"
	"math"
)

const L = 360360
const INF = math.MaxInt32

var a, b, k int64
var aa, bb, lcm int
var D [3 * L]int
var adj [L][]int

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func checkMin(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func bfs() {
	s := aa
	for i := range D {
		D[i] = INF
	}
	D[0] = 0

	for i := 0; i < 3*lcm; i++ {
		u := (s - i) % lcm
		if u < 0 {
			u += lcm
		}

		Du := D[i]
		if Du == INF {
			continue
		}

		for _, v := range adj[u] {
			checkMin(&D[i+v], Du+1)
		}
	}
}

func main() {
	fmt.Scan(&a, &b, &k)

	lcm = 1
	for i := 2; i <= int(k); i++ {
		lcm = lcm(lcm, i)
	}

	for i := 0; i < lcm; i++ {
		adj[i] = append(adj[i], 1)
		for j := 2; j <= int(k); j++ {
			if i%j != 0 {
				adj[i] = append(adj[i], i%j)
			}
		}
	}

	tt := (a - b) / lcm
	aa = int(a % lcm)
	bb = int(b % lcm)

	step := INF
	bfs()

	bb = (aa - bb + 3*lcm) % lcm
	tt *= int64(D[bb+lcm] - D[bb])

	fmt.Println(D[bb] + int(tt))
}