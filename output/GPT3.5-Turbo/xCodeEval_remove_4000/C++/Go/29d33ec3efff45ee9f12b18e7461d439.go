package main

import (
	"fmt"
	"math"
	"strings"
	"time"
)

type i64 int64
type ld float64

type vi []i64
type vd []ld
type vs []string
type vc []rune
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

const Mod int64 = 1000000007, INF = 1e9, LINF = 1e18
const Pi float64 = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + math.Sqrt(5)) / 2)

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = int64(len(keymod))

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
	return strings.Count(fmt.Sprintf("%b", s), "1")
}

var TimeStart time.Time
var TimeEnd time.Time

var id0 = "FILE.IN"
var id2 = "FILE.OUT"

type ppp struct {
	first  pii
	second pii
}

var s1, s2, virus string
var n1, n2, nv i64
var id1 [][]i64

func ProceedVirus() {
	id1 = make([][]i64, nv)
	for i := i64(0); i < nv; i++ {
		id1[i] = make([]i64, 26)
		for j := i64(0); j < 26; j++ {
			pref2 := virus[:i] + string(65+j)
			for x := i + 1; x >= 0; x-- {
				if pref2[i+1-x:i+1] == virus[:x] {
					id1[i][j] = x
					break
				}
			}
		}
	}
}

func Input() {
	fmt.Scan(&s1, &s2, &virus)
	nv = i64(len(virus))
	n1 = i64(len(s1))
	n2 = i64(len(s2))
}

func Solve() {
	List1 := make([][]i64, 26)
	List2 := make([][]i64, 26)
	for i := i64(0); i < n1; i++ {
		List1[s1[i]-'A'] = append(List1[s1[i]-'A'], i)
	}
	for i := i64(0); i < n2; i++ {
		List2[s2[i]-'A'] = append(List2[s2[i]-'A'], i)
	}
	ProceedVirus()
	Default := ppp{pii{-1, -1}, pii{-1, -1}}
	dp := make([][][][]bool, n1)
	Last := make([][][][]ppp, n1)
	for i := i64(0); i < n1; i++ {
		dp[i] = make([][][]bool, n2)
		Last[i] = make([][][]ppp, n2)
		for j := i64(0); j < n2; j++ {
			dp[i][j] = make([][]bool, min(n1, n2)+1)
			Last[i][j] = make([][]ppp, nv+1)
			for x := i64(0); x <= min(n1, n2); x++ {
				dp[i][j][x] = make([]bool, nv+1)
				Last[i][j][x] = make([]ppp, nv+1)
			}
		}
	}
	for i := i64(0); i < n1; i++ {
		for j := i64(0); j < n2; j++ {
			if s1[i] == s2[j] {
				dp[i][j][1][id1[0][s1[i]-'A']] = true
			} else {
				dp[i][j][0][0] = true
			}
		}
	}
	for x := i64(1); x < min(n1, n2); x++ {
		for i := i64(0); i < n1-1; i++ {
			for j := i64(0); j < n2-1; j++ {
				for y := i64(0); y < nv; y++ {
					if !dp[i][j][x][y] {
						continue
					}
					for z := i64(0); z < 26; z++ {
						if len(List1[z]) == 0 || len(List2[z]) == 0 {
							continue
						}
						i1 := List1[z][upperBound(List1[z], i)]
						j1 := List2[z][upperBound(List2[z], j)]
						dp[i1][j1][x+1][id1[y][z]] = true
						Last[i1][j1][x+1][id1[y][z]] = ppp{pii{i, j}, pii{x, y}}
					}
				}
			}
		}
	}
	for x := min(n1, n2); x > 0; x-- {
		for y := i64(0); y < nv; y++ {
			for i := i64(0); i < n1; i++ {
				for j := i64(0); j < n2; j++ {
					if !dp[i][j][x][y] {
						continue
					}
					I := i
					J := j
					X := x
					Y := y
					s := ""
					for I != -1 {
						s = string(s1[I]) + s
						Token := Last[I][J][X][Y]
						I = Token.first.first
						J = Token.first.second
						X = Token.second.first
						Y = Token.second.second
					}
					fmt.Println(s)
					return
				}
			}
		}
	}
	fmt.Println("0")
}

func upperBound(arr []i64, target i64) int {
	low := 0
	high := len(arr)
	for low < high {
		mid := (low + high) / 2
		if arr[mid] <= target {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}

func min(a, b i64) i64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	ControlIO()
	Input()
	TimerStart()
	Solve()
	TimerStop()
}

func ControlIO() {
	infile := id0
	outfile := id2

	t := time.Now()
	fmt.Println("Source code by")
	fmt.Println("Current time:", t.Format("2006-01-02 | 15:04:05"), "\n")

	fmt.Println("OI-Mode: ON")
	fmt.Println("Input file:", infile)
	fmt.Println("Output file:", outfile, "\n")

	fmt.Println("OI-Mode: OFF")
	fmt.Println("Input file: NULL")
	fmt.Println("Output file: NULL", "\n")

	fmt.Println("MultiTest-Mode: ON")

	fmt.Println("MultiTest-Mode: OFF")

	fmt.Println("Interactive-Mode: ON\n")

	fmt.Println("Interactive-Mode: OFF\n")

	// if len(os.Args) > 1 {
	// 	assert(freopen(os.Args[1], "r", stdin))
	// }
	// if len(os.Args) > 2 {
	// 	assert(freopen(os.Args[2], "w", stdout))
	// }

	// freopen(infile, "r", stdin)
	// freopen(outfile, "w", stdout)
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Println("\n\nTime elapsed:", ElapsedTime.Seconds(), "seconds.")
}

func Exit() {
	TimerStop()
}

