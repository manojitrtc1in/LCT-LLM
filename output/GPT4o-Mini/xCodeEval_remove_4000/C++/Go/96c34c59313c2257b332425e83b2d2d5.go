package main

import (
	"fmt"
	"math/big"
	"sort"
)

type Fraction struct {
	a, b int64
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func NewFraction(c, d int64) Fraction {
	hoge := gcd(abs(c), abs(d))
	c /= hoge
	d /= hoge
	if d < 0 {
		d *= -1
		c *= -1
	}
	return Fraction{c, d}
}

func (f Fraction) Less(rhs Fraction) bool {
	return f.a*rhs.b < rhs.a*f.b
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func solve() {
	var n, w int
	fmt.Scan(&n, &w)
	FI := make([][2]Fraction, n)

	for i := 0; i < n; i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		Left := NewFraction(-a, b-w)
		Right := NewFraction(-a, b+w)
		Right.a *= -1
		FI[i] = [2]Fraction{Left, Right}
	}

	sort.Slice(FI, func(i, j int) bool {
		return FI[i][0].Less(FI[j][0])
	})

	ans := 0
	zip := make(map[Fraction]int)
	seg := make([]int, 2*n)

	for _, pair := range FI {
		pair[1].a *= -1
		zip[pair[1]] = 0
	}

	keys := make([]Fraction, 0, len(zip))
	for k := range zip {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return keys[i].Less(keys[j])
	})

	for i, key := range keys {
		zip[key] = i
	}

	for _, pair := range FI {
		hoge := zip[pair[1]]
		for j := hoge; j < 2*n; j++ {
			ans += seg[j]
		}
		seg[hoge]++
	}

	fmt.Println(ans)
}

func main() {
	solve()
}
