package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

type Pair struct {
	first, second int64
}

var (
	Mod       = int64(1000000007)
	INF       = int64(1e9)
	LINF      = int64(1e18)
	Pi        = 3.141592653589793116
	EPS       = 1e-9
	Gold      = (1 + math.Sqrt(5)) / 2
	keymod    = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount  = int64(len(keymod))
)

var (
	s   string
	Map = make(map[rune]int64)
	q   int64
)

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
	return int(math.PopCount(uint64(s)))
}

func ControlIO() {
	infile := "FILE.IN"
	outfile := "FILE.OUT"

	fmt.Printf("Source code by \n")
	fmt.Printf("Current time: %s\n\n", time.Now().Format("2006-01-02 15:04:05"))

	fmt.Printf("OI-Mode: ON\n")
	fmt.Printf("Input file: %s\n", infile)
	fmt.Printf("Output file: %s\n\n", outfile)

	fmt.Printf("OI-Mode: OFF\n")
	fmt.Printf("Input file: NULL\n")
	fmt.Printf("Output file: NULL\n\n")

	fmt.Printf("MultiTest-Mode: ON\n")
	fmt.Printf("MultiTest-Mode: OFF\n")

	fmt.Printf("Interactive-Mode: ON\n\n")
	fmt.Printf("Interactive-Mode: OFF\n\n")

	if len(os.Args) > 1 {
		file, err := os.Open(os.Args[1])
		if err != nil {
			panic(err)
		}
		defer file.Close()
	}

	if len(os.Args) > 2 {
		file, err := os.Create(os.Args[2])
		if err != nil {
			panic(err)
		}
		defer file.Close()
	}

	inputFile, err := os.Open(infile)
	if err != nil {
		panic(err)
	}
	defer inputFile.Close()

	outputFile, err := os.Create(outfile)
	if err != nil {
		panic(err)
	}
	defer outputFile.Close()
}

func Input() {
	fmt.Scan(&s)
}

func Solve() {
	baseAnswer := int64(1)
	for _, x := range s {
		if x >= '0' && x <= '9' {
			continue
		}
		if x == '?' {
			q++
			continue
		}
		Map[x]++
	}

	for i := int64(10); i > 10-int64(len(Map)); i-- {
		baseAnswer *= i
	}

	if s[0] >= 'A' && s[0] <= 'J' {
		baseAnswer /= 10
		baseAnswer *= 9
	}
	if s[0] == '?' {
		baseAnswer *= 9
		q--
	}

	fmt.Print(baseAnswer)
	for i := int64(0); i < q; i++ {
		fmt.Print("0")
	}
}

func main() {
	ControlIO()

	var T int
	fmt.Scan(&T)
	for i := 0; i < T; i++ {
		Input()
		Solve()
	}
}
