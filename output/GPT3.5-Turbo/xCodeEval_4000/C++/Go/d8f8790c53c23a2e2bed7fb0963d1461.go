package main

import (
	"fmt"
	"sort"
)

type Fraction struct {
	a int
	b int
}

type Pair struct {
	left  Fraction
	right Fraction
}

type ByLeft []Pair

func (a ByLeft) Len() int           { return len(a) }
func (a ByLeft) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByLeft) Less(i, j int) bool { return a[i].left.a*a[j].left.b < a[j].left.a*a[i].left.b }

func gcd(a, b int) int {
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
		left := Fraction{-a, b - w}
		right := Fraction{-a, b + w}

		hoge := gcd(abs(left.a), abs(left.b))
		left.a /= hoge
		left.b /= hoge

		hoge = gcd(abs(right.a), abs(right.b))
		right.a /= hoge
		right.b /= hoge

		if left.b < 0 {
			left.a *= -1
			left.b *= -1
		}

		if right.b < 0 {
			right.a *= -1
			right.b *= -1
		}

		right.a *= -1

		FI[i] = Pair{left, right}
	}

	sort.Sort(ByLeft(FI))

	ans := 0
	zip := make(map[Fraction]int)
	for i := 0; i < len(FI); i++ {
		FI[i].right.a *= -1
		zip[FI[i].right] = 1
	}

	compressor := make(map[Fraction]int)
	cnt := 0
	for k := range zip {
		compressor[k] = cnt
		cnt++
	}

	seg := make([]int, 2*n)
	for i := 0; i < len(FI); i++ {
		hoge := compressor[FI[i].right]
		ans += query(seg, hoge, 2*n)
		tmp := seg[hoge]
		update(seg, hoge, tmp+1)
	}

	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func update(seg []int, k, x int) {
	k += len(seg) / 2
	seg[k] = x
	for k > 0 {
		k /= 2
		seg[k] = seg[2*k] + seg[2*k+1]
	}
}

func query(seg []int, a, b int) int {
	res := 0
	a += len(seg) / 2
	b += len(seg) / 2
	for a < b {
		if a%2 == 1 {
			res += seg[a]
			a++
		}
		if b%2 == 1 {
			b--
			res += seg[b]
		}
		a /= 2
		b /= 2
	}
	return res
}

func main() {
	solve()
}
