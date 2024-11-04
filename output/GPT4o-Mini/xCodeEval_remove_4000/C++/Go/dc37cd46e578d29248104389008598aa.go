package main

import (
	"fmt"
	"sort"
)

type pii struct {
	first, second int
}

type F struct {
	p, q int
}

func (f F) Less(other F) bool {
	return f.p*int64(other.q) < other.p*int64(f.q)
}

func (f F) Equal(other F) bool {
	return f.p*int64(other.q) == other.p*int64(f.q)
}

type Fenw struct {
	tr [202020]int
}

func (f *Fenw) Add(pos int) {
	for i := pos; i <= 200020; i |= i + 1 {
		f.tr[i]++
	}
}

func (f *Fenw) Sum(pos int) int {
	res := 0
	for i := pos; i >= 0; i = (i & (i + 1)) - 1 {
		res += f.tr[i]
	}
	return res
}

func (f *Fenw) RangeSum(l, r int) int {
	return f.Sum(r) - f.Sum(l - 1)
}

var w int
var f1 Fenw

func solve1(v []pii) int64 {
	var allF []F
	for _, p := range v {
		from := F{p.first, p.second + w}
		to := F{p.first, p.second - w}
		allF = append(allF, from, to)
	}
	allF = append(allF, F{0, 1})
	sort.Slice(allF, func(i, j int) bool {
		return allF[i].Less(allF[j])
	})

	for i := range v {
		from := F{v[i].first, v[i].second + w}
		to := F{v[i].first, v[i].second - w}
		v[i] = pii{lowerBound(allF, from), lowerBound(allF, to)}
	}

	sort.Slice(v, func(i, j int) bool {
		return v[i].first < v[j].first || (v[i].first == v[j].first && v[i].second > v[j].second)
	})

	res := int64(0)
	for i := 0; i < len(v); i++ {
		res += int64(i - f1.Sum(v[i].second - 1))
		f1.Add(v[i].second)
	}
	return res
}

var f [2]Fenw

func solve2(v [2][]pii) int64 {
	var allF []F
	for i := 0; i < 2; i++ {
		for _, p := range v[i] {
			from := F{p.first, p.second + w}
			to := F{p.first, p.second - w}
			allF = append(allF, from, to)
		}
	}
	allF = append(allF, F{0, 1})
	sort.Slice(allF, func(i, j int) bool {
		return allF[i].Less(allF[j])
	})

	res := int64(0)
	for i := 0; i < 2; i++ {
		for j := range v[i] {
			from := F{v[i][j].first, v[i][j].second + w}
			to := F{v[i][j].first, v[i][j].second - w}
			v[i][j] = pii{lowerBound(allF, from), lowerBound(allF, to)}
			f[i].Add(v[i][j].first)
		}
	}

	for _, p := range v[0] {
		res += int64(f[1].RangeSum(p.first, p.second))
	}
	for _, p := range v[1] {
		res += int64(f[0].RangeSum(p.first+1, p.second))
	}
	return res
}

func lowerBound(arr []F, target F) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid].Less(target) {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func solve() int64 {
	var n int
	fmt.Scan(&n)
	fmt.Scan(&w)

	x := make([]int, n)
	a := make([]int, n)
	v := [2][]pii{}

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &a[i])
		v[x[i] < 0] = append(v[x[i] < 0], pii{abs(x[i]), abs(a[i])})
	}

	ans := int64(0)
	ans += solve1(v[0])
	ans += solve1(v[1])
	ans += solve2(v)
	fmt.Println(ans)

	return 0
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	solve()
}
