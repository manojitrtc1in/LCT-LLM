package main

import (
	"fmt"
	"math"
)

const (
	INF     = 1011111111
	LLINF   = 1000111000111000111
	EPS     = 1e-10
	mod     = 998244353
	PI      = 3.14159265358979323846264
	K       = 50 * 100 + 1
)

var (
	f, s [55]int
	p    [55]float64
	dans [55][5010]float64
)

func solve() int {
	var n, r int
	fmt.Scan(&n, &r)

	for i := 0; i < n; i++ {
		fmt.Scan(&f[i], &s[i], &p[i])
		p[i] *= 0.01
	}

	lp := 0.0
	rp := 1e8

	for iter := 0; iter < 100; iter++ {
		z := (lp + rp) * 0.5
		for i := 0; i < n; i++ {
			for j := 0; j < K; j++ {
				dans[i][j] = z
			}
		}

		for i := n - 1; i >= 0; i-- {
			for j := 0; j < f[i]; j++ {
				dans[i][j] = z
			}
			fi := f[i]
			si := s[i]
			pi := p[i]

			for j := fi; j < si; j++ {
				dans[i][j] = math.Min(z, (float64(fi)+dans[i+1][j-fi])*pi+(float64(si)+z)*(1-pi)))
			}
			for j := si; j < K; j++ {
				dans[i][j] = math.Min(z, (float64(fi)+dans[i+1][j-fi])*pi+(float64(si)+dans[i+1][j-si])*(1-pi)))
			}
		}

		if dans[0][r] < z-EPS {
			rp = z
		} else {
			lp = z
		}
	}

	fmt.Printf("%.10f\n", (lp+rp)*0.5)
	return 0
}

func main() {
	solve()
}
