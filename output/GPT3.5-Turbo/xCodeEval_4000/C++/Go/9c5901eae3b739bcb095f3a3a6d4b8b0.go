package main

import (
	"bufio"
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

type pair struct {
	x int
	y int
}

func makePair(x, y int) pair {
	return pair{x, y}
}

type vector []int

func (v vector) String() string {
	result := "["
	for i, val := range v {
		if i > 0 {
			result += ", "
		}
		result += strconv.Itoa(val)
	}
	result += "]"
	return result
}

func sqr(a int) int {
	return a * a
}

func sz(a []int) int {
	return len(a)
}

func all(a []int) []int {
	return a
}

func forn(n int) []int {
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = i
	}
	return result
}

func fore(l, r int) []int {
	result := make([]int, r-l)
	for i := l; i < r; i++ {
		result[i-l] = i
	}
	return result
}

type li int64
type ld float64
type pt pair

func (p pair) String() string {
	return "(" + strconv.Itoa(p.x) + ", " + strconv.Itoa(p.y) + ")"
}

func (v vector) push_back(a int) vector {
	return append(v, a)
}

func rnd() *rand.Rand {
	return rand.New(rand.NewSource(time.Now().UnixNano()))
}

const (
	INF   = int(1e9)
	INF64 = li(1e18)
	MOD   = 998244353
	EPS   = 1e-9
	PI    = math.Acos(-1.0)
)

const N = 300*1000 + 13

var (
	n  int
	g  [N][]int
	dp [N][3]int
)

func read() bool {
	var err error
	n, err = nextInt()
	if err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		g[i] = nil
	}
	for i := 0; i < n-1; i++ {
		v, err := nextInt()
		if err != nil {
			return false
		}
		u, err := nextInt()
		if err != nil {
			return false
		}
		v--
		u--
		g[v] = append(g[v], u)
		g[u] = append(g[u], v)
	}
	return true
}

func add(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	if a < 0 {
		a += MOD
	}
	return a
}

func mul(a, b int) int {
	return a * b % MOD
}

func dfs(v, p int) {
	dp[v][0] = 1
	dp[v][1] = 1
	vals := make([]int, 0)
	init := make([]int, 0)
	for _, u := range g[v] {
		if u != p {
			dfs(u, v)
			vals = append(vals, add(dp[u][1], add(dp[u][2], dp[u][2])))
			init = append(init, add(dp[u][0], dp[u][1]))
			dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])))
			dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]))
		}
	}
	dp[v][0] = add(dp[v][0], -dp[v][1])

	pr := []int{1}
	su := []int{1}
	for _, it := range vals {
		pr = append(pr, mul(pr[len(pr)-1], it))
	}
	reverse(vals)
	for _, it := range vals {
		su = append(su, mul(su[len(su)-1], it))
	}
	reverse(vals)
	reverse(su)

	dp[v][2] = 0
	for i, val := range vals {
		dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i+1])))
	}
}

func solve() {
	dfs(0, -1)
	fmt.Fprintln(writer, add(dp[0][1], dp[0][2]))
}

func main() {
	// Uncomment the code below to read from a file
	// file, _ := os.Open("input.txt")
	// reader = bufio.NewReader(file)

	// Uncomment the code below to write to a file
	// file, _ := os.Create("output.txt")
	// writer = bufio.NewWriter(file)

	defer writer.Flush()

	for read() {
		solve()
	}
}

// Helper functions
func next() (string, error) {
	return reader.ReadString('\n')
}

func nextInt() (int, error) {
	str, err := next()
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(str[:len(str)-1])
}

func nextInts(n int) ([]int, error) {
	str, err := next()
	if err != nil {
		return nil, err
	}
	str = str[:len(str)-1]
	strs := split(str, " ")
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i], _ = strconv.Atoi(strs[i])
	}
	return result, nil
}

func split(s, sep string) []string {
	var result []string
	for {
		i := indexOf(s, sep)
		if i == -1 {
			result = append(result, s)
			break
		}
		result = append(result, s[:i])
		s = s[i+len(sep):]
	}
	return result
}

func indexOf(s, substr string) int {
	for i := 0; i < len(s)-len(substr)+1; i++ {
		found := true
		for j := 0; j < len(substr); j++ {
			if s[i+j] != substr[j] {
				found = false
				break
			}
		}
		if found {
			return i
		}
	}
	return -1
}
