package main

import (
	"fmt"
	"math"
)

func solve() int {
	var n, r int
	fmt.Scan(&n, &r)
	f := make([]int, n)
	s := make([]int, n)
	p := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&f[i], &s[i], &p[i])
		p[i] *= 0.01
	}

	const K = 50*100 + 1

	dans := make([][]float64, n)
	for i := 0; i < n; i++ {
		dans[i] = make([]float64, K)
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
				dans[i][j] = math.Min(z, (float64(fi) + dans[i+1][j-fi])*pi+(float64(si)+z)*(1-pi))
			}
			for j := s[i]; j < K; j++ {
				dans[i][j] = math.Min(z, (float64(fi)+dans[i+1][j-fi])*pi+(float64(si)+dans[i+1][j-si])*(1-pi))
			}
		}
		if dans[0][r] < z-1e-10 {
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
