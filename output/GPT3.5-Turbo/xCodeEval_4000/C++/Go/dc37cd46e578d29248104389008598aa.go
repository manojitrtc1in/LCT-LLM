package main

import (
	"fmt"
	"sort"
)

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

func solve1(v []pair) int64 {
	var allF []F
	for _, p := range v {
		from := F{p.first, p.second + w}
		to := F{p.first, p.second - w}
		allF = append(allF, from, to)
	}
	allF = append(allF, F{0, 1})
	sort.Slice(allF, func(i, j int) bool {
		return allF[i].p*int64(allF[j].q) < allF[j].p*int64(allF[i].q)
	})
	for i, p := range v {
		from := F{p.first, p.second + w}
		to := F{p.first, p.second - w}
		p.first = sort.Search(len(allF), func(j int) bool {
			return allF[j].p*int64(allF[j].q) >= from.p*int64(from.q)
		})
		p.second = sort.Search(len(allF), func(j int) bool {
			return allF[j].p*int64(allF[j].q) >= to.p*int64(to.q)
		})
		v[i] = p
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i].first < v[j].first || (v[i].first == v[j].first && v[i].second > v[j].second)
	})
	var res int64
	var f1 Fenw
	for i := 0; i < len(v); i++ {
		res += int64(i - f1.rangeSum(v[i].second-1, v[i].second-1))
		f1.add(v[i].second)
	}
	return res
}

func solve2(v [2][]pair) int64 {
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
		return allF[i].p*int64(allF[j].q) < allF[j].p*int64(allF[i].q)
	})
	var res int64
	var f [2]Fenw
	for i := 0; i < 2; i++ {
		for _, p := range v[i] {
			from := F{p.first, p.second + w}
			to := F{p.first, p.second - w}
			p.first = sort.Search(len(allF), func(j int) bool {
				return allF[j].p*int64(allF[j].q) >= from.p*int64(from.q)
			})
			p.second = sort.Search(len(allF), func(j int) bool {
				return allF[j].p*int64(allF[j].q) >= to.p*int64(to.q)
			})
			v[i] = append(v[i], p)
			f[i].add(p.first)
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

type pair struct {
	first  int
	second int
}

func main() {
	var n, w int
	fmt.Scan(&n, &w)
	x := make([]int, n)
	a := make([]int, n)
	v := [2][]pair{}
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &a[i])
		if x[i] < 0 {
			v[0] = append(v[0], pair{abs(x[i]), abs(a[i])})
		} else {
			v[1] = append(v[1], pair{abs(x[i]), abs(a[i])})
		}
	}
	ans := int64(0)
	ans += solve1(v[0])
	ans += solve1(v[1])
	ans += solve2(v)
	fmt.Println(ans)
}
