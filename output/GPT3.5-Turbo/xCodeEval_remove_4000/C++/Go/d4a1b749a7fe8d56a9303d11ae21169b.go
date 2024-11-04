package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = INF + 7
	EPS   = 1e-9
	PI    = acos(-1.0)

	N  = 1000*1000 + 13
	AL = 26
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

type pair struct {
	A interface{}
	B interface{}
}

func (a pair) String() string {
	return fmt.Sprintf("(%v, %v)", a.A, a.B)
}

type li int64
type ld float64

func (a li) String() string {
	return strconv.FormatInt(int64(a), 10)
}

func (a ld) String() string {
	return strconv.FormatFloat(float64(a), 'f', -1, 64)
}

func (a pair) String() string {
	return fmt.Sprintf("(%v, %v)", a.A, a.B)
}

func (v []interface{}) string {
	str := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			str += ", "
		}
		str += fmt.Sprintf("%v", v[i])
	}
	return str + "]"
}

func readStringSlice(scanner *bufio.Scanner) []string {
	scanner.Scan()
	str := scanner.Text()
	return strings.Fields(str)
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	str := scanner.Text()
	num, _ := strconv.Atoi(str)
	return num
}

func readLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	str := scanner.Text()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func readFloat(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	str := scanner.Text()
	num, _ := strconv.ParseFloat(str, 64)
	return num
}

func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	str := scanner.Text()
	return str
}

func readIntSlice(scanner *bufio.Scanner) []int {
	strs := readStringSlice(scanner)
	arr := make([]int, len(strs))
	for i := 0; i < len(strs); i++ {
		arr[i], _ = strconv.Atoi(strs[i])
	}
	return arr
}

func readLongSlice(scanner *bufio.Scanner) []int64 {
	strs := readStringSlice(scanner)
	arr := make([]int64, len(strs))
	for i := 0; i < len(strs); i++ {
		arr[i], _ = strconv.ParseInt(strs[i], 10, 64)
	}
	return arr
}

func readFloatSlice(scanner *bufio.Scanner) []float64 {
	strs := readStringSlice(scanner)
	arr := make([]float64, len(strs))
	for i := 0; i < len(strs); i++ {
		arr[i], _ = strconv.ParseFloat(strs[i], 64)
	}
	return arr
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := readInt(scanner)
	s := readString(scanner)
	m := readInt(scanner)
	t := make([]int, m)
	for i := 0; i < m; i++ {
		t[i] = readInt(scanner)
	}

	nxt := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		nxt[i] = make([]int, AL)
	}
	for i := 0; i < AL; i++ {
		nxt[n][i] = n
	}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < AL; j++ {
			nxt[i][j] = nxt[i+1][j]
		}
		nxt[i][s[i]-'a'] = i
	}

	masks := make(map[int]int)
	cnt := make([]int, N)
	mx := make([]int, N)

	for i := 0; i < m; i++ {
		if _, ok := masks[t[i]]; !ok {
			k := len(masks)
			masks[t[i]] = k
		}
	}

	for i := 0; i < n; i++ {
		lst := i
		cur := 1 << (s[lst] - 'a')
		for {
			mn := n
			for j := 0; j < AL; j++ {
				if (cur>>j)&1 == 0 {
					mn = min(mn, nxt[lst][j])
				}
			}
			if _, ok := masks[cur]; ok {
				x := masks[cur]
				if mx[x] != mn-1 {
					mx[x] = mn - 1
					cnt[x]++
				}
			}
			if mn == n {
				break
			}
			lst = mn
			cur |= 1 << (s[lst] - 'a')
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(cnt[masks[t[i]]])
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	tt := time.Now()

	for {
		if !scanner.Scan() {
			break
		}
		if scanner.Text() == "" {
			continue
		}
		solve()
	}

	fmt.Println("TIME =", time.Since(tt))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
