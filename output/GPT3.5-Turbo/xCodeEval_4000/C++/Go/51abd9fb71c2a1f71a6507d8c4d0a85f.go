package main

import (
	"fmt"
	"math"
	"time"
)

var (
	Min int64 = math.MaxInt64
	Max int64 = math.MinInt64
	A   []pii
)

type pii struct {
	fi int64
	se int64
}

func Pow(a, b int64) int64 {
	if b == 0 {
		return 1
	}
	tmp := Pow(a, b/2)
	if b%2 == 0 {
		return tmp * tmp
	}
	return tmp * tmp * a
}

func Try(id, x1, x2, x3 int64) {
	if id == len(A) {
		Min = min(Min, (x1+1)*(x2+2)*(x3+2))
		Min = min(Min, (x1+2)*(x2+1)*(x3+2))
		Min = min(Min, (x1+2)*(x2+2)*(x3+1))
		Max = max(Max, (x1+1)*(x2+2)*(x3+2))
		Max = max(Max, (x1+2)*(x2+1)*(x3+2))
		Max = max(Max, (x1+2)*(x2+2)*(x3+1))
		return
	}
	key := A[id].fi
	v := A[id].se
	for i := int64(0); i <= v; i++ {
		for j := int64(0); j <= v; j++ {
			for k := int64(0); k <= v; k++ {
				if i+j+k != v {
					continue
				}
				Try(id+1, x1*Pow(key, i), x2*Pow(key, j), x3*Pow(key, k))
			}
		}
	}
}

func Input() {
	fmt.Scan(&n)
}

func Solve() {
	Map := make(map[int64]int64)
	N := n
	for i := int64(2); i <= int64(math.Sqrt(float64(n))); i++ {
		for n%i == 0 {
			Map[i]++
			n /= i
		}
	}
	if n > 1 {
		Map[n]++
	}
	for k, v := range Map {
		A = append(A, pii{k, v})
	}
	Try(0, 1, 1, 1)
	fmt.Println(Min-N, Max-N)
}

func main() {
	Input()
	start := time.Now()
	Solve()
	elapsed := time.Since(start)
	fmt.Printf("\nTime elapsed: %s\n", elapsed)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
