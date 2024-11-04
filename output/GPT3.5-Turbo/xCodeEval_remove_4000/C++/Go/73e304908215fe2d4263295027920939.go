package main

import (
	"fmt"
	"math"
	"time"
)

type i64 int64
type ld float64

type vi []i64
type vd []ld
type vs []string
type vc []byte
type vb []bool
type pii struct {
	first  i64
	second i64
}
type pip struct {
	first  i64
	second pii
}
type ppi struct {
	first  pii
	second i64
}

const Mod int64 = 1000000007, INF int64 = 1e9, LINF int64 = 1e18
const Pi float64 = 3.141592653589793116, EPS float64 = 1e-9, Gold float64 = ((1 + math.Sqrt(5)) / 2)
var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

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
	return bits.OnesCount64(uint64(s))
}

var TimeStart time.Time
var TimeEnd time.Time

var m, h1, a1, x1, y1, h2, a2, x2, y2 i64
var vis1, vis2 vi

func Input() {
	fmt.Scan(&m, &h1, &a1, &x1, &y1)
	fmt.Scan(&h2, &a2, &x2, &y2)
	vis1 = make(vi, m)
	vis2 = make(vi, m)
}

func Solve() {
	vis1[h1] = 0
	id4, id5 := -1, -1
	for {
		z := (h1*x1 + y1) % m
		if vis1[z] != 0 {
			id4 = vis1[z]
			id5 = (vis1[h1] + 1) - vis1[z]
			break
		} else {
			vis1[z] = vis1[h1] + 1
		}
		h1 = z
	}
	vis2[h2] = 0
	id0, id2 := -1, -1
	for {
		z := (h2*x2 + y2) % m
		if vis2[z] != 0 {
			id0 = vis2[z]
			id2 = (vis2[h2] + 1) - vis2[z]
			break
		} else {
			vis2[z] = vis2[h2] + 1
		}
		h2 = z
	}
	if vis1[a1] == 0 || vis2[a2] == 0 {
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
	Input()
	TimerStart()
	Solve()
	TimerStop()
}
