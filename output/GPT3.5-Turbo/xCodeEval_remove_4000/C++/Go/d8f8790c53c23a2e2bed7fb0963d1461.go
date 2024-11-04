package main

import (
	"fmt"
	"sort"
)

type Fraction struct {
	a int64
	b int64
}

type Pair struct {
	first  Fraction
	second Fraction
}

type ByFirst []Pair

func (a ByFirst) Len() int           { return len(a) }
func (a ByFirst) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByFirst) Less(i, j int) bool { return a[i].first.a*a[j].first.b < a[j].first.a*a[i].first.b }

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func solve() {
	var n, w int
	fmt.Scan(&n, &w)
	FI := make([]Pair, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		Left := Fraction{-int64(a), int64(b - w)}
		Right := Fraction{-int64(a), int64(b + w)}
		hoge := gcd(abs(Left.a), abs(Left.b))
		Left.a /= hoge
		Left.b /= hoge
		hoge = gcd(abs(Right.a), abs(Right.b))
		Right.a /= hoge
		Right.b /= hoge
		if Left.b < 0 {
			Left.a *= -1
			Left.b *= -1
		}
		if Right.b < 0 {
			Right.a *= -1
			Right.b *= -1
		}
		Right.a *= -1
		FI[i] = Pair{Left, Right}
	}
	sort.Sort(ByFirst(FI))
	ans := 0
	zip := make(map[Fraction]int)
	for i := 0; i < len(FI); i++ {
		FI[i].second.a *= -1
		if _, ok := zip[FI[i].second]; !ok {
			zip[FI[i].second] = 1
		}
	}
	seg := make([]int, 2*n)
	for i := 0; i < len(FI); i++ {
		hoge := zip[FI[i].second]
		ans += seg[hoge]
		tmp := seg[hoge]
		seg[hoge]++
	}
	fmt.Println(ans)
}

func main() {
	solve()
}
