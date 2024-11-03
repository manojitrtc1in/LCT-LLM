package main

import (
	"fmt"
	"math"
)

const (
	N = 50
	M = 20
)

var (
	S    [N]string
	f    [1 << M]int64
	ok   [M + 1]int64
	n, m int
)

func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}
	m = len(S[0])

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j {
				s := 0
				for k := 0; k < m; k++ {
					if S[i][k] == S[j][k] {
						s |= 1 << k
					}
				}
				f[s] |= 1 << i
			}
		}
	}

	for s := (1 << m) - 1; s >= 0; s-- {
		for i := 0; i < m; i++ {
			if s&(1<<i) != 0 {
				f[s^1<<i] |= f[s]
			}
		}
	}

	for s := 0; s < 1<<m; s++ {
		step := countBits(s) + 1
		for i := 0; i < m; i++ {
			if s&(1<<i) == 0 {
				d := f[s|1<<i] ^ f[s]
				ok[step] += countBits(d)
			}
		}
	}

	ans := 0.0
	for i := 1; i <= m; i++ {
		if ok[i] != 0 {
			t := float64(ok[i]) * float64(i)
			for j := 1; j < i; j++ {
				t *= float64(j)
			}
			for j := m - i + 1; j <= m; j++ {
				t /= float64(j)
			}
			ans += t
		}
	}

	ans /= float64(n)
	fmt.Printf("%.15f\n", ans)
}

func countBits(x int) int64 {
	return int64(math.Log2(float64(x&-x)) + 1)
}
