package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var m, h1, a1, x1, y1, h2, a2, x2, y2 int64
var vis1, vis2 []int64

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
	count := 0
	for s > 0 {
		if s&1 == 1 {
			count++
		}
		s >>= 1
	}
	return count
}

func Input() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	m, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	h1, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	a1, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	x1, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	y1, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	scanner.Scan()
	h2, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	a2, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	x2, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	scanner.Scan()
	y2, _ = strconv.ParseInt(scanner.Text(), 10, 64)

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
	cycleStart1 := int64(-1)
	cycleLen1 := int64(-1)
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
	cycleStart2 := int64(-1)
	cycleLen2 := int64(-1)
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

func main() {
	Input()
	Solve()
}
