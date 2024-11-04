package main

import (
	"fmt"
	"sort"
)

type Fraction struct {
	a int64
	b int64
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func solve() {
	var n, w int
	fmt.Scan(&n, &w)
	FI := make([][2]Fraction, n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		left := Fraction{-int64(a), int64(b - w)}
		right := Fraction{-int64(a), int64(b + w)}
		right.a *= -1
		FI[i] = [2]Fraction{left, right}
	}
	sort.Slice(FI, func(i, j int) bool {
		return FI[i][0].a*FI[j][0].b < FI[j][0].a*FI[i][0].b
	})
	ans := 0
	zip := make(map[Fraction]int)
	for i := 0; i < len(FI); i++ {
		zip[FI[i][1]] = 1
	}
	cnt := 0
	for key := range zip {
		zip[key] = cnt
		cnt++
	}
	seg := make([]int, 2*n)
	for i := 0; i < len(FI); i++ {
		hoge := zip[FI[i][1]]
		ans += query(seg, hoge, 2*n)
		tmp := seg[hoge]
		update(seg, hoge, tmp+1)
	}
	fmt.Println(ans)
}

func query(seg []int, a, b int) int {
	L := 0
	R := 0
	for a < b {
		if a&1 == 1 {
			L += seg[a]
			a++
		}
		if b&1 == 1 {
			b--
			R += seg[b]
		}
		a >>= 1
		b >>= 1
	}
	return L + R
}

func update(seg []int, k, x int) {
	k += len(seg) / 2
	seg[k] = x
	for k > 1 {
		k >>= 1
		seg[k] = seg[2*k] + seg[2*k+1]
	}
}

func main() {
	solve()
}
