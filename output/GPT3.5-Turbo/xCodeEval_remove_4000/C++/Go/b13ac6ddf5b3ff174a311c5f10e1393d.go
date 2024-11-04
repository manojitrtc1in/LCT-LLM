package main

import (
	"fmt"
	"math"
)

func countBits(x int) int {
	count := 0
	for x > 0 {
		if x&1 == 1 {
			count++
		}
		x >>= 1
	}
	return count
}

func work() float64 {
	can := make([]int64, 1<<20)
	for i := 0; i < len(can); i++ {
		can[i] = math.MaxInt64
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
			c *= float64(L-j+1)
			c /= float64(j)
		}

		ret += t / c / float64(L-i+1)
	}
	return ret / float64(N)
}

func main() {
	for {
		_, err := fmt.Scan(&N)
		if err != nil {
			break
		}
		s := make([]string, N)
		for i := 0; i < N; i++ {
			fmt.Scan(&s[i])
		}
		L := len(s[0])
		ans := work()
		fmt.Printf("%.12f\n", ans)
	}
}
