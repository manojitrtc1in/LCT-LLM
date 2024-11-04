package main

import (
	"fmt"
	"math"
	"strings"
	"time"
)

const (
	Mod  = 1000000007
	INF  = 1e9
	LINF = 1e18
	Pi   = 3.141592653589793116
	EPS  = 1e-9
	Gold = ((1 + math.Sqrt(5)) / 2)
)

var (
	keymod    = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount  = int64(len(keymod))
	TimeStart time.Time
	TimeEnd   time.Time
)

type pii struct {
	first  int64
	second int64
}

type pip struct {
	first  int64
	second pii
}

type ppi struct {
	first  pii
	second int64
}

type ppp struct {
	first  pii
	second pii
}

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

func ProceedVirus(NextCommonPrefix [][]int64, nv int64, virus string) {
	for i := int64(0); i < nv; i++ {
		for j := 0; j < 26; j++ {
			pref2 := virus[:i] + string(65+j)
			for x := i + 1; x >= 0; x-- {
				if pref2[i+1-x:x] == virus[:x] {
					NextCommonPrefix[i][j] = x
					break
				}
			}
		}
	}
}

func Solve() {
	var s1, s2, virus string
	var n1, n2, nv int64
	fmt.Scan(&s1, &s2, &virus)
	n1 = int64(len(s1))
	n2 = int64(len(s2))
	nv = int64(len(virus))

	List1 := make([][]int64, 26)
	List2 := make([][]int64, 26)
	for i := 0; i < 26; i++ {
		List1[i] = []int64{}
		List2[i] = []int64{}
	}

	for i := int64(0); i < n1; i++ {
		List1[s1[i]-'A'] = append(List1[s1[i]-'A'], i)
	}

	for i := int64(0); i < n2; i++ {
		List2[s2[i]-'A'] = append(List2[s2[i]-'A'], i)
	}

	NextCommonPrefix := make([][]int64, nv)
	for i := int64(0); i < nv; i++ {
		NextCommonPrefix[i] = make([]int64, 26)
	}

	ProceedVirus(NextCommonPrefix, nv, virus)

	Default := ppp{pii{-1, -1}, pii{-1, -1}}
	dp := make([][][][]bool, n1)
	Last := make([][][][]ppp, n1)
	for i := int64(0); i < n1; i++ {
		dp[i] = make([][][]bool, n2)
		Last[i] = make([][][]ppp, n2)
		for j := int64(0); j < n2; j++ {
			dp[i][j] = make([][]bool, int(math.Min(float64(n1), float64(n2)))+1)
			Last[i][j] = make([][]ppp, nv+1)
			for x := int64(0); x <= int64(math.Min(float64(n1), float64(n2))); x++ {
				dp[i][j][x] = make([]bool, nv+1)
				Last[i][j][x] = make([]ppp, nv+1)
			}
		}
	}

	for i := int64(0); i < n1; i++ {
		for j := int64(0); j < n2; j++ {
			if s1[i] == s2[j] {
				dp[i][j][1][NextCommonPrefix[0][s1[i]-'A']] = true
			} else {
				dp[i][j][0][0] = true
			}
		}
	}

	for x := int64(1); x < int64(math.Min(float64(n1), float64(n2))); x++ {
		for i := int64(0); i < n1-1; i++ {
			for j := int64(0); j < n2-1; j++ {
				for y := int64(0); y < nv; y++ {
					if !dp[i][j][x][y] {
						continue
					}
					for z := 0; z < 26; z++ {
						if len(List1[z]) == 0 || len(List2[z]) == 0 {
							continue
						}
						if List1[z][len(List1[z])-1] <= i || List2[z][len(List2[z])-1] <= j {
							continue
						}
						i1 := List1[z][upperBound(List1[z], i)]
						j1 := List2[z][upperBound(List2[z], j)]
						dp[i1][j1][x+1][NextCommonPrefix[y][z]] = true
						Last[i1][j1][x+1][NextCommonPrefix[y][z]] = ppp{pii{i, j}, pii{x, y}}
					}
				}
			}
		}
	}

	for x := int64(math.Min(float64(n1), float64(n2))); x > 0; x-- {
		for y := int64(0); y < nv; y++ {
			for i := int64(0); i < n1; i++ {
				for j := int64(0); j < n2; j++ {
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

func upperBound(arr []int64, target int64) int {
	left := 0
	right := len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] <= target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func main() {
	Input()
	TimerStart()
	Solve()
	TimerStop()
}

func Input() {
	var s1, s2, virus string
	fmt.Scan(&s1, &s2, &virus)
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}
