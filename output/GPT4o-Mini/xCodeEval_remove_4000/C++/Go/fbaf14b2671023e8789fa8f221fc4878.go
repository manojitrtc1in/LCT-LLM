package main

import (
	"fmt"
	"math"
	"strings"
)

type Fraction struct {
	a, b int64
}

func NewFraction(a, b int64) Fraction {
	d := gcd(a, b)
	a /= d
	b /= d
	if b < 0 {
		a = -a
		b = -b
	}
	return Fraction{a, b}
}

func (f Fraction) ToString() string {
	return fmt.Sprintf("%d/%d", f.a, f.b)
}

func (p Fraction) Add(q Fraction) Fraction {
	return NewFraction(p.a*q.b+q.a*p.b, p.b*q.b)
}

func (p Fraction) Sub(q Fraction) Fraction {
	return NewFraction(p.a*q.b-q.a*p.b, p.b*q.b)
}

func (p Fraction) Mul(q Fraction) Fraction {
	return NewFraction(p.a*q.a, p.b*q.b)
}

func (p Fraction) Div(q Fraction) Fraction {
	return NewFraction(p.a*q.b, p.b*q.a)
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	const M = 1000000007
	var s, t string
	fmt.Scan(&s, &t)

	sz1 := len(s)
	sz2 := len(t)
	dp := make([][]int64, sz1+1)
	for i := range dp {
		dp[i] = make([]int64, sz2+1)
	}

	for i := 0; i < sz1; i++ {
		for j := 0; j < sz2; j++ {
			if s[i] == t[j] {
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j] + 1) % M
			} else {
				dp[i+1][j+1] = dp[i+1][j]
			}
		}
	}

	re := int64(0)
	for i := 0; i < sz1; i++ {
		re = (re + dp[i+1][sz2]) % M
	}
	fmt.Println(re)
}
