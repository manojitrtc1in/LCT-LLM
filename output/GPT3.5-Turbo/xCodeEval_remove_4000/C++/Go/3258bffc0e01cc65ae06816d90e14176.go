package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
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

const (
	Mod  int64   = 1000000007
	INF  int64   = 1e9
	LINF int64   = 1e18
	Pi   float64 = 3.141592653589793116
	EPS  float64 = 1e-9
	Gold float64 = (1 + math.Sqrt(5)) / 2
)

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

var TimeStart time.Time
var TimeEnd time.Time

var s string
var Map map[byte]int64
var q int64

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
	return strings.Count(strconv.FormatInt(s, 2), "1")
}

func Input() {
	fmt.Scan(&s)
}

func Solve() {
	baseAnswer := int64(1)
	for i := 0; i < len(s); i++ {
		x := s[i]
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
	Input()
	TimerStart()
	Solve()
	TimerStop()
}
