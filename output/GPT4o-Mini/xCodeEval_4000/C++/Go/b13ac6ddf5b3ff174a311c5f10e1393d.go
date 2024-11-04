package main

import (
	"fmt"
	"math"
)

const mod = 1000000007

var dx4 = []int{-1, 0, 1, 0}
var dy4 = []int{0, 1, 0, -1}
var dx8 = []int{-1, 0, 1, 0, -1, -1, 1, 1}
var dy8 = []int{0, 1, 0, -1, -1, 1, -1, 1}
var dxhorse = []int{-2, -2, -1, -1, 1, 1, 2, 2}
var dyhorse = []int{1, -1, 2, -2, 2, -2, 1, -1}

var s [50]string
var N, L int
var can [1 << 20]int64

func countBits(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func work() float64 {
	for i := range can {
		can[i] = ^int64(0)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i == j {
				continue
			}
			same := 0
			for k := 0; k < L; k++ {
				if s[i][k] == s[j][k] {
					same |= 1 << k
				}
			}
			can[same] &= ^(1 << i)
		}
	}

	for mask := (1 << L) - 1; mask >= 0; mask-- {
		for p := 0; p < L; p++ {
			if mask&(1<<p) != 0 {
				can[mask^(1<<p)] &= can[mask]
			}
		}
	}

	ret := 0.0
	cnt := make([]float64, 25)
	for mask := (1 << L) - 1; mask >= 0; mask-- {
		l := countBits(mask)
		for p := 0; p < L; p++ {
			if mask&(1<<p) != 0 {
				r := can[mask^(1<<p)] ^ can[mask]
				cnt[l] += float64(countBits(int(r)))
			}
		}
	}

	for i := 1; i <= L; i++ {
		t := cnt[i] * float64(i)

		c := 1.0
		for j := 1; j <= i-1; j++ {
			c *= float64(L - j + 1)
			c /= float64(j)
		}

		ret += t / c / float64(L-i+1)
	}
	return ret / float64(N)
}

func main() {
	for {
		if _, err := fmt.Scan(&N); err != nil {
			break
		}
		for i := 0; i < N; i++ {
			fmt.Scan(&s[i])
		}
		L = len(s[0])
		ans := work()
		fmt.Printf("%.12f\n", ans)
	}
}
