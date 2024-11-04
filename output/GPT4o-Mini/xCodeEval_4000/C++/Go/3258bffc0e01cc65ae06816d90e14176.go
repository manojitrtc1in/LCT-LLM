package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

const (
	Mod       = 1000000007
	INF       = 1e9
	LINF      = 1e18
	Pi        = 3.141592653589793116
	EPS       = 1e-9
	Gold      = (1 + math.Sqrt(5)) / 2
)

var (
	s       string
	Map     = make(map[rune]int64)
	q       int64
)

func ControlIO() {
	if len(os.Args) > 1 {
		fileIn, err := os.Open(os.Args[1])
		if err != nil {
			panic(err)
		}
		defer fileIn.Close()
		os.Stdin = fileIn
	}

	if len(os.Args) > 2 {
		fileOut, err := os.Create(os.Args[2])
		if err != nil {
			panic(err)
		}
		defer fileOut.Close()
		os.Stdout = fileOut
	}
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

	start := time.Now()

	var T int
	if _, err := fmt.Scan(&T); err == nil {
		for i := 0; i < T; i++ {
			Input()
			Solve()
		}
	} else {
		Input()
		Solve()
	}

	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", elapsed.Seconds())
}
