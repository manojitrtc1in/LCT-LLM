package main

import (
	"fmt"
	"math"
	"strings"
)

type Pair struct {
	fi, se int
}

type VectorInt []int
type VectorString []string
type VectorPair []Pair

const (
	pi   = math.Pi
	eps  = 1e-11
	M    = 1000000007
	id9  = 40
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	dp := make([][]int, len(s)+1)
	for i := range dp {
		dp[i] = make([]int, len(t)+1)
	}

	for i := 0; i < len(s); i++ {
		for j := 0; j < len(t); j++ {
			if s[i] == t[j] {
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j] + 1) % M
			} else {
				dp[i+1][j+1] = dp[i+1][j]
			}
		}
	}

	re := 0
	sz := len(t)
	for i := 0; i < len(s); i++ {
		re = (re + dp[i+1][sz]) % M
	}
	fmt.Println(re)
}

func dist(a, b Pair) float64 {
	return math.Sqrt(sqr(float64(a.fi)-float64(b.fi)) + sqr(float64(a.se)-float64(b.se)))
}

func sqr(x float64) float64 {
	return x * x
}

func isIntersect(a, b, c, d Pair) bool {
	return crossOper(a, b, c)*crossOper(a, b, d) < 0 && crossOper(c, d, a)*crossOper(c, d, b) < 0
}

func crossOper(c, a, b Pair) int {
	t := float64((a.fi - c.fi)*(b.se - c.se) - (b.fi - c.fi)*(a.se - c.se))
	if math.Abs(t) <= eps {
		return 0
	}
	if t < 0 {
		return -1
	}
	return 1
}
