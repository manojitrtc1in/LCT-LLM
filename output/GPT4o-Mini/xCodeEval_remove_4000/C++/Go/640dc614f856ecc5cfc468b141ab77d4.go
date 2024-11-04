package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

type pii struct {
	fi, se int64
}

var Mod int64 = 1000000007
var INF int64 = 1e9
var LINF int64 = 1e18
var Pi float64 = 3.141592653589793116
var EPS float64 = 1e-9
var Gold float64 = (1 + math.Sqrt(5)) / 2

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

var TimeStart, TimeEnd time.Time

var x int64

func getbit(s int64, i int) int {
	return int((s >> i) & 1)
}

func onbit(s int64, i int) int64 {
	return s | (1 << i)
}

func offbit(s int64, i int) int64 {
	return s & (^(1 << i))
}

func cntbit(s int64) int {
	return int(bits.OnesCount64(uint64(s)))
}

func ControlIO(argc int, argv []string) {
	infile := "FILE.IN"
	outfile := "FILE.OUT"

	t := time.Now()
	fmt.Printf("Source code by \n")
	fmt.Printf("Current time: %d-%02d-%02d | %02d:%02d:%02d\n\n",
		t.Year(), t.Month(), t.Day(), t.Hour(), t.Minute(), t.Second())

	fmt.Println("OI-Mode: ON")
	fmt.Printf("Input file: %s\n", infile)
	fmt.Printf("Output file: %s\n\n", outfile)

	fmt.Println("OI-Mode: OFF")
	fmt.Println("Input file: NULL")
	fmt.Println("Output file: NULL\n")

	fmt.Println("MultiTest-Mode: ON")
	fmt.Println("MultiTest-Mode: OFF")

	fmt.Println("Interactive-Mode: ON\n")
	fmt.Println("Interactive-Mode: OFF\n")

	if argc > 1 {
		file, err := os.Open(argv[1])
		if err != nil {
			panic(err)
		}
		defer file.Close()
	}

	if argc > 2 {
		file, err := os.Create(argv[2])
		if err != nil {
			panic(err)
		}
		defer file.Close()
	}
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	elapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %.6f seconds.\n", elapsedTime.Seconds())
}

func Exit() {
	TimerStop()
	os.Exit(0)
}

func funcRecursive(m, n, s int64) pii {
	if m == 0 {
		return pii{fi: n, se: s}
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(funcRecursive(m-x, n+1, s+x), funcRecursive(x-y-1, n+1, s+y))
}

func max(a, b pii) pii {
	if a.fi > b.fi || (a.fi == b.fi && a.se > b.se) {
		return a
	}
	return b
}

func Input() {
	fmt.Scan(&x)
}

func Solve() {
	Token := funcRecursive(x, 0, 0)
	fmt.Printf("%d %d\n", Token.fi, Token.se)
}

func main() {
	ControlIO(len(os.Args), os.Args)

	Input()
	TimerStart()
	Solve()
	TimerStop()

	var T int
	fmt.Scan(&T)
	TimerStart()
	for T > 0 {
		Input()
		Solve()
		T--
	}
	TimerStop()
}
