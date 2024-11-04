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

func lowBit(x int) int {
	return x & -x
}

func highBit(x int) int {
	p := lowBit(x)
	for p != x {
		x -= p
		p = lowBit(x)
	}
	return p
}

func dfs() int64 {
	for i := range F {
		F[i] = 0
	}
	F[0] = 1

	for s := 0; s < (1 << n); s++ {
		if F[s] > 0 {
			for i := 0; i < n; i++ {
				if (s&(1<<i)) == 0 && (P[bits.OnesCount(uint(s))] == -1 || P[bits.OnesCount(uint(s))] == i) && (s&adj[i]) == 0 {
					F[s|(1<<i)] += F[s]
				}
			}
		}
	}

	return F[(1<<n)-1]
}

func main() {
	fmt.Scan(&n, &k)
	k -= 2000

	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		adj[x-1] |= (1 << (fmt.Scan() - 1))
		for j := 0; j < n; j++ {
			P[j] = -1
		}
	}

	if dfs() < k {
		fmt.Println("The times have changed")
	} else {
		s := (1 << n) - 1
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if (s&(1<<j)) != 0 {
					P[A[i]] = j
					t = dfs()
					if t < k {
						k -= t
						P[j] = -1
					} else {
						s ^= (1 << j)
						fmt.Printf("%d ", j+1)
						break
					}
				}
			}
		}
	}
}