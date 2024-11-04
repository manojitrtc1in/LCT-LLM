package main

import (
	"fmt"
	"sort"
)

type pii struct {
	first  int
	second int
}

type F struct {
	p int
	q int
}

type Fenw struct {
	tr [202020]int
}

func (f *Fenw) add(pos int) {
	for i := pos; i <= 200020; i |= i + 1 {
		f.tr[i]++
	}
}

func (f *Fenw) sum(pos int) int {
	res := 0
	for i := pos; i >= 0; i = (i & (i + 1)) - 1 {
		res += f.tr[i]
	}
	return res
}

func (f *Fenw) rangeSum(l, r int) int {
	return f.sum(r) - f.sum(l-1)
}

func solve1(v []pii, w int) int64 {
	allF := make([]F, 0)
	for _, p := range v {
		from := F{p.first, p.second + w}
		to := F{p.first, p.second - w}
		allF = append(allF, from)
		allF = append(allF, to)
	}
	allF = append(allF, F{0, 1})
	sort.Slice(allF, func(i, j int) bool {
		return allF[i].p*int64(allF[j].q) < allF[j].p*int64(allF[i].q)
	})
	allF = unique(allF)
	for i, p := range v {
		from := F{p.first, p.second + w}
		to := F{p.first, p.second - w}
		v[i] = pii{lowerBound(allF, from), lowerBound(allF, to)}
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i].first < v[j].first || (v[i].first == v[j].first && v[i].second > v[j].second)
	})
	var res int64
	f1 := Fenw{}
	for i := 0; i < len(v); i++ {
		res += int64(i - f1.sum(v[i].second-1))
		f1.add(v[i].second)
	}
	return res
}

func solve2(v [2][]pii, w int) int64 {
	allF := make([]F, 0)
	for _, p := range v {
		for _, q := range p {
			from := F{q.first, q.second + w}
			to := F{q.first, q.second - w}
			allF = append(allF, from)
			allF = append(allF, to)
		}
	}
	allF = append(allF, F{0, 1})
	sort.Slice(allF, func(i, j int) bool {
		return allF[i].p*int64(allF[j].q) < allF[j].p*int64(allF[i].q)
	})
	allF = unique(allF)
	var res int64
	f := [2]Fenw{}
	for i := 0; i < 2; i++ {
		for j := 0; j < len(v[i]); j++ {
			from := F{v[i][j].first, v[i][j].second + w}
			to := F{v[i][j].first, v[i][j].second - w}
			v[i][j] = pii{lowerBound(allF, from), lowerBound(allF, to)}
			f[i].add(v[i][j].first)
		}
	}
	for _, p := range v[0] {
		res += int64(f[1].rangeSum(p.first, p.second))
	}
	for _, p := range v[1] {
		res += int64(f[0].rangeSum(p.first+1, p.second))
	}
	return res
}

func lowerBound(arr []F, target F) int {
	left, right := 0, len(arr)
	for left < right {
		mid := left + (right-left)/2
		if arr[mid].p < target.p || (arr[mid].p == target.p && arr[mid].q < target.q) {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func unique(arr []F) []F {
	j := 0
	for i := 1; i < len(arr); i++ {
		if arr[i] != arr[j] {
			j++
			arr[j] = arr[i]
		}
	}
	return arr[:j+1]
}

func main() {
	var n, w int
	fmt.Scan(&n, &w)
	x := make([]int, n)
	a := make([]int, n)
	v := [2][]pii{}
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &a[i])
		if x[i] < 0 {
			v[0] = append(v[0], pii{abs(x[i]), abs(a[i])})
		} else {
			v[1] = append(v[1], pii{abs(x[i]), abs(a[i])})
		}
	}
	ans := solve1(v[0], w) + solve1(v[1], w) + solve2(v, w)
	fmt.Println(ans)
}
