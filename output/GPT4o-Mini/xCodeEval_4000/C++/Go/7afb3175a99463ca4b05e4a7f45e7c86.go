package main

import (
	"fmt"
	"math/bits"
)

const N = 50
const M = 20

var S [N]string
var f [1 << M]int64
var ok [M + 1]int64
var n, m int

func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}
	m = len(S[0])

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j {
				s := int64(0)
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
				f[s^(1<<i)] |= f[s]
			}
		}
	}

	var ans float64
	for step := 1; step <= m; step++ {
		if ok[step] > 0 {
			t := float64(ok[step]) * float64(step)
			for j := 1; j < step; j++ {
				t *= float64(j)
			}
			for j := m - step + 1; j <= m; j++ {
				t /= float64(j)
			}
			ans += t
		}
	}

	ans /= float64(n)
	fmt.Printf("%.15f\n", ans)
}
