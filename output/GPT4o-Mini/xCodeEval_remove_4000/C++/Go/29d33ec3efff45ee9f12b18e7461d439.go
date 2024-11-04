package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

type vi []int64
type vb []bool
type ppi struct {
	first  [2]int64
	second int64
}

const (
	Mod   = 1000000007
	INF   = 1e9
	LINF  = 1e18
	Pi    = 3.141592653589793116
	EPS   = 1e-9
	Gold  = (1 + math.Sqrt(5)) / 2
)

var (
	keymod   = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount = int64(len(keymod))
	TimeStart time.Time
	TimeEnd   time.Time
	id0       = "FILE.IN"
	id2       = "FILE.OUT"
	s1, s2, virus string
	n1, n2, nv   int64
	id1         [][]int64
)

func getbit(s int64, i int) int {
	return int((s >> i) & 1)
}

func onbit(s int64, i int) int64 {
	return s | (1 << i)
}

func offbit(s int64, i int) int64 {
	return s & (^(1 << i))
}

func cntbit(s int64) int {
	return int(popcount(s))
}

func popcount(x int64) int64 {
	var count int64
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func ControlIO() {
	infile, outfile := id0, id2
	t := time.Now()
	fmt.Printf("Source code by\n")
	fmt.Printf("Current time: %d-%02d-%02d | %02d:%02d:%02d\n\n",
		t.Year(), t.Month(), t.Day(), t.Hour(), t.Minute(), t.Second())

	fmt.Println("OI-Mode: ON")
	fmt.Printf("Input file: %s\n", infile)
	fmt.Printf("Output file: %s\n\n", outfile)

	fmt.Println("OI-Mode: OFF")
	fmt.Println("Input file: NULL")
	fmt.Println("Output file: NULL\n")

	fmt.Println("MultiTest-Mode: ON")
	fmt.Println("MultiTest-Mode: OFF")

	fmt.Println("Interactive-Mode: ON\n")
	fmt.Println("Interactive-Mode: OFF\n")

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

func ProceedVirus() {
	id1 = make([][]int64, nv)
	for i := range id1 {
		id1[i] = make([]int64, 26)
	}
	for i := int64(0); i < nv; i++ {
		for j := int64(0); j < 26; j++ {
			pref2 := virus[:i] + string(rune(65+j))
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
	Default := ppi{[2]int64{-1, -1}, -1}
	dp := make([][][][]bool, n1)
	Last := make([][][][]ppi, n1)
	for i := range dp {
		dp[i] = make([][][]bool, n2)
		Last[i] = make([][][]ppi, n2)
		for j := range dp[i] {
			dp[i][j] = make([][]bool, int(math.Min(float64(n1), float64(n2))+1))
			Last[i][j] = make([][]ppi, int(math.Min(float64(n1), float64(n2))+1))
			for k := range dp[i][j] {
				dp[i][j][k] = make([]bool, nv+1)
				Last[i][j][k] = make([]ppi, nv+1)
				for l := range Last[i][j][k] {
					Last[i][j][k][l] = Default
				}
			}
		}
	}
	for i := int64(0); i < n1; i++ {
		for j := int64(0); j < n2; j++ {
			if s1[i] == s2[j] {
				dp[i][j][1][id1[0][s1[i]-'A']] = true
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
						if len(List1[z]) == 0 || List1[z][len(List1[z])-1] <= i {
							continue
						}
						if len(List2[z]) == 0 || List2[z][len(List2[z])-1] <= j {
							continue
						}
						i1 := List1[z][0]
						j1 := List2[z][0]
						dp[i1][j1][x+1][id1[y][z]] = true
						Last[i1][j1][x+1][id1[y][z]] = ppi{[2]int64{i, j}, [2]int64{x, y}}
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
						I = Token.first[0]
						J = Token.first[1]
						X = Token.second
						Y = Token.second
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
	ControlIO()
	Input()
	TimerStart()
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
