package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strings"
	"time"
)

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

type pii struct {
	first, second int64
}

type ppp struct {
	first, second pii
}

var s1, s2, virus string
var n1, n2, nv int64
var NextCommonPrefix [][]int64

func ProceedVirus() {
	NextCommonPrefix = make([][]int64, nv)
	for i := int64(0); i < nv; i++ {
		NextCommonPrefix[i] = make([]int64, 26)
		for j := int64(0); j < 26; j++ {
			pref2 := virus[:i] + string(rune(65+j))
			for x := i + 1; x >= 0; x-- {
				if pref2[i+1-x:i+1] == virus[:x] {
					NextCommonPrefix[i][j] = x
					break
				}
			}
		}
	}
}

func Input() {
	fmt.Scan(&s1, &s2, &virus)
	nv = int64(len(virus))
	n1 = int64(len(s1))
	n2 = int64(len(s2))
}

func Solve() {
	List1 := make([][]int64, 26)
	List2 := make([][]int64, 26)
	for i := int64(0); i < n1; i++ {
		List1[s1[i]-'A'] = append(List1[s1[i]-'A'], i)
	}
	for i := int64(0); i < n2; i++ {
		List2[s2[i]-'A'] = append(List2[s2[i]-'A'], i)
	}
	ProceedVirus()
	Default := ppp{pii{-1, -1}, pii{-1, -1}}
	dp := make([][][][]bool, n1)
	Last := make([][][][]ppp, n1)
	for i := range dp {
		dp[i] = make([][][]bool, n2)
		Last[i] = make([][][]ppp, n2)
		for j := range dp[i] {
			dp[i][j] = make([][]bool, int(math.Min(float64(n1), float64(n2))+1))
			Last[i][j] = make([][]ppp, int(math.Min(float64(n1), float64(n2))+1))
			for k := range dp[i][j] {
				dp[i][j][k] = make([]bool, nv+1)
				Last[i][j][k] = make([]ppp, nv+1)
				for l := range Last[i][j][k] {
					Last[i][j][k][l] = Default
				}
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
					for z := int64(0); z < 26; z++ {
						if sort.Search(len(List1[z]), func(k int) bool { return List1[z][k] > i }) == len(List1[z]) {
							continue
						}
						if sort.Search(len(List2[z]), func(k int) bool { return List2[z][k] > j }) == len(List2[z]) {
							continue
						}
						i1 := List1[z][sort.Search(len(List1[z]), func(k int) bool { return List1[z][k] > i })]
						j1 := List2[z][sort.Search(len(List2[z]), func(k int) bool { return List2[z][k] > j })]
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
					I, J, X, Y := i, j, x, y
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

func main() {
	start := time.Now()
	Input()
	Solve()
	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %s seconds.\n", elapsed)
}
