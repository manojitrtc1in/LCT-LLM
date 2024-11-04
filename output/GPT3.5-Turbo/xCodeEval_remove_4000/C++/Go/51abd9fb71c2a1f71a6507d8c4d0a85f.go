package main

import (
	"fmt"
	"math"
	"time"
)

type pii struct {
	first  int64
	second int64
}

var (
	Mod     int64 = 1000000007
	INF     int64 = 1e9
	LINF    int64 = 1e18
	Pi      float64 = 3.141592653589793116
	EPS     float64 = 1e-9
	Gold    float64 = (1 + math.Sqrt(5)) / 2
	keymod         = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount       = int64(len(keymod))
	TimeStart      time.Time
	TimeEnd        time.Time
)

func getbit(s int64, i int) int {
	return int((s >> i) & 1)
}

func onbit(s int64, i int) int64 {
	return s | (1 << i)
}

func offbit(s int64, i int) int64 {
	return s &^ (1 << i)
}

func cntbit(s int64) int {
	return int(math.Log2(float64(s & -s)))
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

func Try(id, x1, x2, x3 int64, A []pii, Min, Max *int64) {
	if id == len(A) {
		*Min = min(*Min, (x1+1)*(x2+2)*(x3+2))
		*Min = min(*Min, (x1+2)*(x2+1)*(x3+2))
		*Min = min(*Min, (x1+2)*(x2+2)*(x3+1))
		*Max = max(*Max, (x1+1)*(x2+2)*(x3+2))
		*Max = max(*Max, (x1+2)*(x2+1)*(x3+2))
		*Max = max(*Max, (x1+2)*(x2+2)*(x3+1))
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
				Try(id+1, x1*Pow(key, i), x2*Pow(key, j), x3*Pow(key, k), A, Min, Max)
			}
		}
	}
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

func Input() int64 {
	var n int64
	fmt.Scan(&n)
	return n
}

func Solve(n int64) (int64, int64) {
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
	A := make([]pii, 0)
	for k, v := range Map {
		A = append(A, pii{k, v})
	}
	var Min, Max int64 = LINF, -LINF
	Try(0, 1, 1, 1, A, &Min, &Max)
	return Min - N, Max - N
}

func main() {
	TimeStart = time.Now()

	n := Input()
	minDiff, maxDiff := Solve(n)
	fmt.Println(minDiff, maxDiff)

	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}
