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
	Mod      int64 = 1000000007
	INF      int64 = 1e9
	LINF     int64 = 1e18
	Pi       float64 = 3.141592653589793116
	EPS      float64 = 1e-9
	Gold     float64 = (1 + math.Sqrt(5)) / 2
	keymod   []int64 = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount int    = len(keymod)
)

var (
	TimeStart time.Time
	TimeEnd   time.Time
)

func main() {
	ControlIO()
	Input()
	TimerStart()
	Solve()
	TimerStop()
}

func ControlIO() {
	infile := "FILE.IN"
	outfile := "FILE.OUT"

	t := time.Now()
	fmt.Println("Source code by")
	fmt.Println("Current time:", t.Format("2006-01-02 | 15:04:05"))
	fmt.Println()

	fmt.Println("OI-Mode: ON")
	fmt.Println("Input file:", infile)
	fmt.Println("Output file:", outfile)
	fmt.Println()

	fmt.Println("OI-Mode: OFF")
	fmt.Println("Input file: NULL")
	fmt.Println("Output file: NULL")
	fmt.Println()

	fmt.Println("MultiTest-Mode: ON")
	fmt.Println()

	fmt.Println("MultiTest-Mode: OFF")
	fmt.Println()

	fmt.Println("Interactive-Mode: ON")
	fmt.Println()

	fmt.Println("Interactive-Mode: OFF")
	fmt.Println()

	// Uncomment the following lines if you want to read from a file and write to a file
	// os.Stdin, _ = os.Open(infile)
	// os.Stdout, _ = os.Create(outfile)
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}

func Input() {
	var n int64
	fmt.Scan(&n)
}

func Solve() {
	var n, Min, Max int64
	Min = LINF
	Max = -LINF
	var A []pii

	Pow := func(a, b int64) int64 {
		if b == 0 {
			return 1
		}
		tmp := Pow(a, b/2)
		if b%2 == 0 {
			return tmp * tmp
		}
		return tmp * tmp * a
	}

	Try := func(id, x1, x2, x3 int64) {
		if id == len(A) {
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
