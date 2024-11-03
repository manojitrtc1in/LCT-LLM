package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	Mod             int64 = 1000000007
	INF             int64 = 1e9
	LINF            int64 = 1e18
	Pi              float64 = 3.141592653589793116
	EPS             float64 = 1e-9
	Gold            float64 = (1 + math.Sqrt(5)) / 2
	keymod          = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount        = len(keymod)
	TimeStart       time.Time
	TimeEnd         time.Time
	OImode          int    = 227420978
	MultiTest       int    = 227420978
	Interactive     int    = 227420978
	cppstr_infile   string = "FILE.IN"
	cppstr_outfile  string = "FILE.OUT"
)

type pair struct {
	first  int64
	second int64
}

type triple struct {
	first  int64
	second pair
}

type quad struct {
	first  pair
	second pair
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
	return bits.OnesCount64(uint64(s))
}

func ProceedVirus() {
	NextCommonPrefix = make([][]int, nv)
	for i := 0; i < nv; i++ {
		NextCommonPrefix[i] = make([]int, 26)
		for j := 0; j < 26; j++ {
			pref2 := virus[:i]
			pref2 += string(65 + j)
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	s1 = scanner.Text()
	scanner.Scan()
	s2 = scanner.Text()
	scanner.Scan()
	virus = scanner.Text()
	nv = int64(len(virus))
	n1 = int64(len(s1))
	n2 = int64(len(s2))
}

func Solve() {
	List1 := make([][]int64, 26)
	List2 := make([][]int64, 26)
	for i := 0; i < int(n1); i++ {
		List1[s1[i]-'A'] = append(List1[s1[i]-'A'], int64(i))
	}
	for i := 0; i < int(n2); i++ {
		List2[s2[i]-'A'] = append(List2[s2[i]-'A'], int64(i))
	}
	ProceedVirus()
	Default := quad{pair{-1, -1}, pair{-1, -1}}
	dp := make([][][][]bool, n1)
	Last := make([][][][]quad, n1)
	for i := 0; i < int(n1); i++ {
		dp[i] = make([][][]bool, n2)
		Last[i] = make([][][]quad, n2)
		for j := 0; j < int(n2); j++ {
			dp[i][j] = make([][]bool, min(int(n1), int(n2))+1)
			Last[i][j] = make([][]quad, nv+1)
			for x := 0; x <= int(min(int(n1), int(n2))); x++ {
				dp[i][j][x] = make([]bool, nv+1)
				Last[i][j][x] = make([]quad, nv+1)
			}
		}
	}
	for i := 0; i < int(n1); i++ {
		for j := 0; j < int(n2); j++ {
			if s1[i] == s2[j] {
				dp[i][j][1][NextCommonPrefix[0][s1[i]-'A']] = true
			} else {
				dp[i][j][0][0] = true
			}
		}
	}
	for x := 1; x < int(min(int(n1), int(n2))); x++ {
		for i := 0; i < int(n1)-1; i++ {
			for j := 0; j < int(n2)-1; j++ {
				for y := 0; y < int(nv); y++ {
					if !dp[i][j][x][y] {
						continue
					}
					for z := 0; z < 26; z++ {
						if len(List1[z]) == 0 || len(List2[z]) == 0 {
							continue
						}
						i1 := sort.Search(len(List1[z]), func(i int) bool { return List1[z][i] > int64(i) })
						j1 := sort.Search(len(List2[z]), func(i int) bool { return List2[z][i] > int64(j) })
						dp[i1][j1][x+1][NextCommonPrefix[y][z]] = true
						Last[i1][j1][x+1][NextCommonPrefix[y][z]] = quad{pair{i, j}, pair{x, y}}
					}
				}
			}
		}
	}
	for x := int(min(int(n1), int(n2))); x > 0; x-- {
		for y := 0; y < int(nv); y++ {
			for i := 0; i < int(n1); i++ {
				for j := 0; j < int(n2); j++ {
					if !dp[i][j][x][y] {
						continue
					}
					I := i
					J := j
					X := x
					Y := y
					s := ""
					for I != -1 {
						s = s1[I:I+1] + s
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
	ControlIO()
	Input()
	Solve()
}

func ControlIO() {
	infile := cppstr_infile
	outfile := cppstr_outfile
	#ifdef Akikaze
	fmt.Println("Source code by #Team4T-Akikaze.")
	fmt.Println("Current time:", time.Now().Format("2006-01-02 | 15:04:05"))
	#ifdef OImode
	fmt.Println("OI-Mode: ON")
	fmt.Println("Input file:", infile)
	fmt.Println("Output file:", outfile)
	#else
	fmt.Println("OI-Mode: OFF")
	fmt.Println("Input file: NULL")
	fmt.Println("Output file: NULL")
	#endif
	#ifdef MultiTest
	fmt.Println("MultiTest-Mode: ON")
	#else
	fmt.Println("MultiTest-Mode: OFF")
	#endif
	#ifdef Interactive
	fmt.Println("Interactive-Mode: ON")
	#else
	fmt.Println("Interactive-Mode: OFF")
	#endif
	#endif
	#ifdef OImode
	fi, _ := os.Open(infile)
	fo, _ := os.Create(outfile)
	scanner := bufio.NewScanner(fi)
	writer := bufio.NewWriter(fo)
	scanner.Split(bufio.ScanWords)
	#else
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	#endif
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func pow(a, b int64) int64 {
	if b == 0 {
		return 1
	}
	if b%2 == 1 {
		return a * pow(a, b-1) % Mod
	}
	temp := pow(a, b/2)
	return temp * temp % Mod
}

func Exit() {
	TimerStop()
	os.Exit(0)
}
