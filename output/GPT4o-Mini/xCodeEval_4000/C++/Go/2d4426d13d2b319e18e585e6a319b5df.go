package main

import (
	"fmt"
	"math"
)

const jt = 998244353

var (
	n, m int
	s    [55][25]byte
	val  [55]int
	dy   [1 << 20]uint64
	dp   [1 << 20]float64
)

func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	m = len(s[0])

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			num := 0
			for k := 0; k < m; k++ {
				if s[i][k] == s[j][k] {
					num |= 1 << k
				}
			}
			dy[num] |= (1 << i) | (1 << j)
		}
	}

	for i := 0; i < (1 << m); i++ {
		for j := i; j > 0; j &= j - 1 {
			lst := j & -j
			dy[i^lst] |= dy[i]
		}
	}

	dp[0] = 1
	ans := 0.0
	for i := 0; i < (1 << m); i++ {
		v := dp[i] / float64(m-ones(i))
		for j := (1 << m) - 1 - i; j > 0; j &= j - 1 {
			dp[i|(j&-j)] += v
		}
		ans += dp[i] * float64(ones(dy[i]))
	}
	fmt.Printf("%.10f\n", ans/float64(n))
}

func ones(x uint64) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}
