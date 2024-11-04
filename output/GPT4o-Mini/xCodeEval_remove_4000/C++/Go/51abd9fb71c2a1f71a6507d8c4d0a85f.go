package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

type pii struct {
	first, second int64
}

var (
	n, Min, Max int64
	A           []pii
	keymod      = []int64{1000000007, 1000000009, 1000000021, 1000000033}
)

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
	if id == int64(len(A)) {
		Min = min(Min, (x1+1)*(x2+2)*(x3+2))
		Min = min(Min, (x1+2)*(x2+1)*(x3+2))
		Min = min(Min, (x1+2)*(x2+2)*(x3+1))
		Max = max(Max, (x1+1)*(x2+2)*(x3+2))
		Max = max(Max, (x1+2)*(x2+1)*(x3+2))
		Max = max(Max, (x1+2)*(x2+2)*(x3+1))
		return
	}
	key := A[id].first
	v := A[id].second
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
	fmt.Printf("%d %d\n", Min-N, Max-N)
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

func main() {
	start := time.Now()

	Input()
	Min = math.MaxInt64
	Max = math.MinInt64
	Solve()

	var T int
	fmt.Scan(&T)
	for T > 0 {
		T--
		Input()
		Solve()
	}

	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", elapsed.Seconds())
}
