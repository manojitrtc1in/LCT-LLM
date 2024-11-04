package main

import (
	"fmt"
	"math"
)

type Triple struct {
	a, b, c float64
}

func countBits(v uint32) int {
	v = v - ((v >> 1) & 0x55555555)
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
	return int((v + (v >> 4) & 0xF0F0F0F) * 0x1010101 >> 24)
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func writeInt(x int) {
	fmt.Println(x)
}

func solve() int {
	n, r := readInt(), readInt()
	f := make([]int, 55)
	s := make([]int, 55)
	p := make([]float64, 55)

	for i := 0; i < n; i++ {
		fmt.Scan(&f[i], &s[i], &p[i])
		p[i] *= 0.01
	}

	const K = 50 * 100 + 1
	lp := 0.0
	rp := 1e8

	dans := make([][]float64, 55)
	for i := range dans {
		dans[i] = make([]float64, K)
	}

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
				dans[i][j] = math.Min(z, float64(fi)+dans[i+1][j-fi]*pi+(float64(si)+z)*(1-pi))
			}
			for j := si; j < K; j++ {
				dans[i][j] = math.Min(z, float64(fi)+dans[i+1][j-fi]*pi+(float64(si)+dans[i+1][j-si])*(1-pi))
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
