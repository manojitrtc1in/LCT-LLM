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

const (
	Mod     = 1000000007
	INF     = 1e9
	LINF    = 1e18
	Pi      = 3.141592653589793116
	EPS     = 1e-9
	Gold    = (1 + math.Sqrt(5)) / 2
)

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

var TimeStart, TimeEnd time.Time

var m, h1, a1, x1, y1, h2, a2, x2, y2 int64
var vis1, vis2 []int64

func ControlIO() {
	infile := "FILE.IN"
	outfile := "FILE.OUT"

	fmt.Printf("Source code by\n")
	fmt.Printf("Current time: %s\n\n", time.Now().Format("2006-01-02 15:04:05"))

	fmt.Printf("OI-Mode: ON\n")
	fmt.Printf("Input file: %s\n", infile)
	fmt.Printf("Output file: %s\n\n", outfile)

	fmt.Printf("MultiTest-Mode: ON\n")
	fmt.Printf("MultiTest-Mode: OFF\n")

	fmt.Printf("Interactive-Mode: ON\n\n")
	fmt.Printf("Interactive-Mode: OFF\n\n")

	file, err := os.Open(infile)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	outFile, err := os.Create(outfile)
	if err != nil {
		panic(err)
	}
	defer outFile.Close()
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	elapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", elapsedTime.Seconds())
}

func Input() {
	fmt.Scan(&m, &h1, &a1, &x1, &y1)
	fmt.Scan(&h2, &a2, &x2, &y2)
	vis1 = make([]int64, m)
	vis2 = make([]int64, m)
	for i := range vis1 {
		vis1[i] = -1
	}
	for i := range vis2 {
		vis2[i] = -1
	}
}

func Solve() {
	vis1[h1] = 0
	id4, id5 := int64(-1), int64(-1)
	for {
		z := (h1*x1 + y1) % m
		if vis1[z] != -1 {
			id4 = vis1[z]
			id5 = (vis1[h1] + 1) - vis1[z]
			break
		} else {
			vis1[z] = vis1[h1] + 1
		}
		h1 = z
	}

	vis2[h2] = 0
	id0, id2 := int64(-1), int64(-1)
	for {
		z := (h2*x2 + y2) % m
		if vis2[z] != -1 {
			id0 = vis2[z]
			id2 = (vis2[h2] + 1) - vis2[z]
			break
		} else {
			vis2[z] = vis2[h2] + 1
		}
		h2 = z
	}

	if vis1[a1] == -1 || vis2[a2] == -1 {
		fmt.Println("-1")
		return
	}
	if vis1[a1] < id4 && vis2[a2] < id0 {
		if vis1[a1] == vis2[a2] {
			fmt.Println(vis1[a1])
		} else {
			fmt.Println("-1")
		}
		return
	}
	if vis1[a1] >= id4 && vis2[a2] >= id0 {
		ans := int64(-1)
		for i := int64(0); i <= 1000000; i++ {
			expected := vis1[a1] + id5*i
			if (expected-vis2[a2])%id2 == 0 && (expected-vis2[a2])/id2 >= 0 {
				ans = expected
				break
			}
		}
		fmt.Println(ans)
		return
	}
	if vis1[a1] < id4 && vis2[a2] >= id0 {
		if (vis1[a1]-vis2[a2])%id2 == 0 && (vis1[a1]-vis2[a2])/id2 >= 0 {
			fmt.Println(vis1[a1])
		} else {
			fmt.Println("-1")
		}
		return
	}
	if vis1[a1] >= id4 && vis2[a2] < id0 {
		if (vis2[a2]-vis1[a1])%id5 == 0 && (vis2[a2]-vis1[a1])/id5 >= 0 {
			fmt.Println(vis2[a2])
		} else {
			fmt.Println("-1")
		}
		return
	}
}

func main() {
	ControlIO()
	TimerStart()
	Input()
	Solve()
	TimerStop()

	var T int
	fmt.Scan(&T)
	TimerStart()
	for T > 0 {
		T--
		Input()
		Solve()
	}
	TimerStop()
}
