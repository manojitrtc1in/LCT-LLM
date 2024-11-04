package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v []int) String() string {
	result := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			result += ", "
		}
		result += fmt.Sprintf("%d", v[i])
	}
	return result + "]"
}

var rnd = rand.New(rand.NewSource(time.Now().Unix()))

const INF = int(1e9)
const INF64 = int64(1e18)
const MOD = int(1e9) + 7
const EPS = 1e-9
const PI = math.Acos(-1.0)

const N = 4*1000*1000 + 13

var n, mod int

func read() bool {
	if _, err := fmt.Scanf("%d%d", &n, &mod); err != nil {
		return false
	}
	return true
}

var dp [N]int
var pr [N]int

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
	for i := 0; i < N; i++ {
		dp[i] = 0
		pr[i] = 0
	}
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

func main() {
	// freopen("input.txt", "r", stdin)

	tt := time.Now()

	// cerr.precision(15)
	// cout.precision(15)
	// cerr << fixed
	// cout << fixed

	var tc int
	fmt.Scanf("%d", &tc)
	for tc > 0 {
		if !read() {
			break
		}
		solve()

		// cerr << "TIME = " << clock() - tt << endl
		tt = time.Now()
		tc--
	}
}
