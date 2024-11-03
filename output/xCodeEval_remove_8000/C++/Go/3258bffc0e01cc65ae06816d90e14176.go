package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

type i64 int64
type ld float64

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
	Mod  = 1000000007LL
	INF  = 1e9
	LINF = 1e18
	Pi   = 3.141592653589793116
	EPS  = 1e-9
	Gold = ((1 + sqrt(5)) / 2)
)

var (
	keymod   = []int64{1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL}
	keyCount = len(keymod)
)

func getbit(s int64, i int) int {
	return int((s >> i) & 1)
}

func onbit(s int64, i int) int64 {
	return s | (int64(1) << i)
}

func offbit(s int64, i int) int64 {
	return s &^ (int64(1) << i)
}

func cntbit(s int64) int {
	return bits.OnesCount64(uint64(s))
}

var TimeStart time.Time
var TimeEnd time.Time

var s string
var Map map[string]int64
var q int64

func Input() {
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	s = strings.TrimSpace(s)
}

func Solve() {
	baseAnswer := int64(1)
	Map = make(map[string]int64)
	for _, x := range s {
		if x >= '0' && x <= '9' {
			continue
		}
		if x == '?' {
			q++
			continue
		}
		Map[string(x)]++
	}
	for i := int64(10); i > 10-Map.size(); i-- {
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
	Solve()
}
