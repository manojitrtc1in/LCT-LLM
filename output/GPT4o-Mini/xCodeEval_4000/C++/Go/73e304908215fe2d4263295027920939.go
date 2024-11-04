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
	m, h1, a1, x1, y1, h2, a2, x2, y2 int64
	vis1, vis2                         []int64
	TimeStart, TimeEnd                 time.Time
)

func ControlIO() {
	if len(os.Args) > 1 {
		file, err := os.Open(os.Args[1])
		if err != nil {
			panic(err)
		}
		defer file.Close()
		fmt.Scan(file)
	}
	if len(os.Args) > 2 {
		file, err := os.Create(os.Args[2])
		if err != nil {
			panic(err)
		}
		defer file.Close()
		os.Stdout = file
	}
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
	cycleStart1, cycleLen1 := int64(-1), int64(-1)
	for {
		z := (h1*x1 + y1) % m
		if vis1[z] != -1 {
			cycleStart1 = vis1[z]
			cycleLen1 = (vis1[h1] + 1) - vis1[z]
			break
		} else {
			vis1[z] = vis1[h1] + 1
		}
		h1 = z
	}

	vis2[h2] = 0
	cycleStart2, cycleLen2 := int64(-1), int64(-1)
	for {
		z := (h2*x2 + y2) % m
		if vis2[z] != -1 {
			cycleStart2 = vis2[z]
			cycleLen2 = (vis2[h2] + 1) - vis2[z]
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

	if vis1[a1] < cycleStart1 && vis2[a2] < cycleStart2 {
		if vis1[a1] == vis2[a2] {
			fmt.Println(vis1[a1])
		} else {
			fmt.Println("-1")
		}
		return
	}

	if vis1[a1] >= cycleStart1 && vis2[a2] >= cycleStart2 {
		ans := int64(-1)
		for i := int64(0); i <= 1000000; i++ {
			expected := vis1[a1] + cycleLen1*i
			if (expected-vis2[a2])%cycleLen2 == 0 && (expected-vis2[a2])/cycleLen2 >= 0 {
				ans = expected
				break
			}
		}
		fmt.Println(ans)
		return
	}

	if vis1[a1] < cycleStart1 && vis2[a2] >= cycleStart2 {
		if (vis1[a1]-vis2[a2])%cycleLen2 == 0 && (vis1[a1]-vis2[a2])/cycleLen2 >= 0 {
			fmt.Println(vis1[a1])
		} else {
			fmt.Println("-1")
		}
		return
	}

	if vis1[a1] >= cycleStart1 && vis2[a2] < cycleStart2 {
		if (vis2[a2]-vis1[a1])%cycleLen1 == 0 && (vis2[a2]-vis1[a1])/cycleLen1 >= 0 {
			fmt.Println(vis2[a2])
		} else {
			fmt.Println("-1")
		}
		return
	}
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	elapsed := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %.6f seconds.\n", elapsed.Seconds())
}

func main() {
	ControlIO()
	TimerStart()
	Input()
	Solve()
	TimerStop()
}
