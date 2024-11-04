package main

import (
	"fmt"
	"sort"
)

type Fraction struct {
	a int64
	b int64
}

func NewFraction(c, d int64) Fraction {
	hoge := gcd(abs(c), abs(d))
	c /= hoge
	d /= hoge
	if d < 0 {
		d *= -1
		c *= -1
	}
	return Fraction{a: c, b: d}
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func solve() {
	var n, w int
	fmt.Scan(&n, &w)
	FI := make([][2]Fraction, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		left := NewFraction(-a, b-w)
		right := NewFraction(-a, b+w)
		right.a *= -1
		FI[i] = [2]Fraction{left, right}
	}
	sort.Slice(FI, func(i, j int) bool {
		return FI[i][0].a*FI[j][0].b < FI[j][0].a*FI[i][0].b
	})
	ans := 0
	zip := make(map[Fraction]int)
	for i := range FI {
		zip[FI[i][1]] = 1
	}
	cnt := 0
	for k := range zip {
		zip[k] = cnt
		cnt++
	}
	seg := make([]int, 2*n+1)
	for i := range FI {
		hoge := zip[FI[i][1]]
		ans += query(seg, hoge, 2*n)
		tmp := seg[hoge]
		update(seg, hoge, tmp+1)
	}
	fmt.Println(ans)
}

func query(seg []int, a, b int) int {
	L, R := 0, 0
	for a += len(seg) / 2; a < b; a >>= 1 {
		if a&1 == 1 {
			L += seg[a]
			a++
		}
		if b&1 == 1 {
			b--
			R += seg[b]
		}
	}
	return L + R
}

func update(seg []int, k, x int) {
	k += len(seg) / 2
	seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		seg[k] = seg[2*k] + seg[2*k+1]
	}
}

func main() {
	solve()
}
