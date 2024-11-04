package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)

	N = 4*1000*1000 + 13
)

type pt struct {
	x, y int
}

func add(a, b int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	if a < 0 {
		a += mod
	}
	return a
}

func mul(a, b int) int {
	return a * b % mod
}

func solve() {
	dp := make([]int, N)
	pr := make([]int, N)
	pr[1] = 1
	pr[2] = mod - 1
	for i := 1; i <= n; i++ {
		dp[i] = pr[i]
		pr[i+1] = add(pr[i+1], dp[i])
		for j := 2; j*i <= n; j++ {
			pr[j*i] = add(pr[j*i], dp[i])
			if j*(i+1) < N {
				pr[j*(i+1)] = add(pr[j*(i+1)], -dp[i])
			}
		}
		pr[i+1] = add(pr[i+1], pr[i])
	}
	fmt.Printf("%d\n", dp[n])
}

func read() bool {
	if _, err := fmt.Scan(&n, &mod); err != nil {
		return false
	}
	return true
}

func main() {
	rand.Seed(time.Now().UnixNano())

	// Uncomment the line below if you want to read from a file
	// file, _ := os.Open("input.txt")
	// defer file.Close()
	// reader := bufio.NewReader(file)

	// Uncomment the line below if you want to read from standard input
	// reader := bufio.NewReader(os.Stdin)

	// Uncomment the line below if you want to read from a file or standard input
	// scanner := bufio.NewScanner(reader)

	// Uncomment the line below if you want to read from a file or standard input
	// scanner.Split(bufio.ScanWords)

	// Uncomment the line below if you want to read from a file or standard input
	// scanner.Scan()
	// fmt.Sscanf(scanner.Text(), "%d", &tc)

	// Uncomment the line below if you want to read from a file or standard input
	// for tc > 0 {
	for read() {
		solve()
		// tc--
	}
}
