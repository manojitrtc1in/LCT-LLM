package main

import (
	"fmt"
	"math"
	"strings"
)

type Pair struct {
	fi, se int
}

const (
	M     = 1000000007
	MAXI  = 1 << 30
	eps   = 1e-11
	id9   = 40
)

func reset(dp [][]int) {
	for i := range dp {
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}
}

func main() {
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	sz1 := len(s)
	sz2 := len(t)

	dp := make([][]int, sz1+1)
	for i := range dp {
		dp[i] = make([]int, sz2+1)
	}

	reset(dp)

	for i := 0; i < sz1; i++ {
		for j := 0; j < sz2; j++ {
			dp[i+1][j+1] = (dp[i+1][j] + (boolToInt(s[i] == t[j]) * (dp[i][j] + 1) % M)) % M) % M
		}
	}

	re := 0
	for i := 0; i < sz1; i++ {
		re = (re + dp[i+1][sz2]) % M
	}
	fmt.Println(re)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func dist(a, b Pair) float64 {
	return math.Sqrt(sqr(float64(a.fi)-float64(b.fi)) + sqr(float64(a.se)-float64(b.se)))
}

func sqr(x float64) float64 {
	return x * x
}

func cross(c, a, b Pair) int {
	return (a.fi-c.fi)*(b.se-c.se) - (b.fi-c.fi)*(a.se-c.se)
}

func crossOper(c, a, b Pair) int {
	t := (float64(a.fi)-float64(c.fi))*(float64(b.se)-float64(c.se)) - (float64(b.fi)-float64(c.fi))*(float64(a.se)-float64(c.se))
	if math.Abs(t) <= eps {
		return 0
	}
	if t < 0 {
		return -1
	}
	return 1
}

func isIntersect(a, b, c, d Pair) bool {
	return crossOper(a, b, c)*crossOper(a, b, d) < 0 && crossOper(c, d, a)*crossOper(c, d, b) < 0
}

func isMiddle(s, m, t float64) bool {
	return math.Abs(s-m) <= eps || math.Abs(t-m) <= eps || (s < m) != (t < m)
}

func isLetter(c byte) bool {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
}

func isDigit(c byte) bool {
	return c >= '0' && c <= '9'
}
