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
type VectorVectorInt [][]int
type VectorPair []Pair
type VectorString []string

const (
	MAXI = 1 << 30
	M    = 1000000007
	eps  = 1e-11
)

func main() {
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	sz1, sz2 := len(s), len(t)
	dp := make([][]int, sz1+1)
	for i := range dp {
		dp[i] = make([]int, sz2+1)
	}

	for i := 0; i < sz1; i++ {
		for j := 0; j < sz2; j++ {
			dp[i+1][j+1] = (dp[i+1][j] + boolToInt(s[i] == t[j])*(dp[i][j]+1)) % M
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
	return math.Sqrt(sqr(float64(a.fi-b.fi)) + sqr(float64(a.se-b.se)))
}

func sqr(x float64) float64 {
	return x * x
}

func cross(c, a, b Pair) int {
	return (a.fi-c.fi)*(b.se-c.se) - (b.fi-c.fi)*(a.se-c.se)
}

func isIntersect(a, b, c, d Pair) bool {
	return crossOper(a, b, c)*crossOper(a, b, d) < 0 && crossOper(c, d, a)*crossOper(c, d, b) < 0
}

func crossOper(c, a, b Pair) int {
	t := float64((a.fi-c.fi)*(b.se-c.se) - (b.fi-c.fi)*(a.se-c.se))
	if math.Abs(t) <= eps {
		return 0
	}
	if t < 0 {
		return -1
	}
	return 1
}
