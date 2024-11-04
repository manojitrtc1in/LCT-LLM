package main

import (
	"fmt"
	"math"
)

type LL int64
type DB float64
type VI []int
type VC []rune
type VS []string
type VL []LL
type VD []DB
type SI map[int]struct{}
type SS map[string]struct{}
type MII map[int]int
type MSI map[string]int
type PII struct{ first, second int }
type PLL struct{ first, second LL }
type VII []PII
type VVI [][]int
type VVII []VII

const mod = 1000000007

const inf = 0x3f3f3f3f
const inff = 1 << 60
const eps = 1e-9
const oo = 1e25
const pi = math.Acos(-1.0)

var dx4 = []int{-1, 0, 1, 0}
var dy4 = []int{0, 1, 0, -1}
var dx8 = []int{-1, 0, 1, 0, -1, -1, 1, 1}
var dy8 = []int{0, 1, 0, -1, -1, 1, -1, 1}
var dxhorse = []int{-2, -2, -1, -1, 1, 1, 2, 2}
var dyhorse = []int{1, -1, 2, -2, 2, -2, 1, -1}

func checkMin(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func checkMax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func countBits(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func work(s []string, N int, L int) float64 {
	can := make([]LL, 1<<20)
	for i := range can {
		can[i] = ^LL(0)
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
	var N int
	var s [50]string

	for {
		if _, err := fmt.Scan(&N); err != nil {
			break
		}
		for i := 0; i < N; i++ {
			fmt.Scan(&s[i])
		}
		L := len(s[0])
		ans := work(s[:N], N, L)
		fmt.Printf("%.12f\n", ans)
	}
}
