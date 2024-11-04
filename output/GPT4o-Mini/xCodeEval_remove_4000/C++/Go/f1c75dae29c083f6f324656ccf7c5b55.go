package main

import (
	"fmt"
	"math/bits"
)

const MOD = 1000000007
const N = 16
const S = 1 << 16

var F [S]int64
var k, t int64
var adj [N]int
var A [N]int
var P [N]int
var n int

func RST(A interface{}) {
	switch v := A.(type) {
	case *[S]int64:
		for i := range v {
			v[i] = 0
		}
	}
}

func _U(x int) int {
	return (1 << x) - 1
}

func _1(i int) int {
	return 1 << i
}

func dfs() int64 {
	RST(&F)
	F[0] = 1
	for s := 0; s <= _U(n); s++ {
		if F[s] > 0 {
			for i := 0; i < n; i++ {
				if (s&_1(i)) == 0 && (adj[i]&s) == 0 {
					F[s|_1(i)] += F[s]
				}
			}
		}
	}
	return F[_U(n)]
}

func main() {
	fmt.Scan(&n, &k)
	k -= 2000
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x)
		fmt.Scan(&y)
		adj[x-1] |= _1(y - 1)
		P[i] = -1
	}

	if dfs() < k {
		fmt.Println("The times have changed")
	} else {
		s := _U(n)
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if s&_1(j) > 0 {
					P[A[i]] = j
					t = dfs()
					if t < k {
						k -= t
						P[j] = -1
					} else {
						s ^= _1(j)
						fmt.Printf("%d ", j+1)
						break
					}
				}
			}
		}
	}
}
