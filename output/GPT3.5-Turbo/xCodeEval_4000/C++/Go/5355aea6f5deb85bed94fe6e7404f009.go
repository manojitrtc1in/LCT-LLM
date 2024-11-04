package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second int
}

type Triple struct {
	first  int
	second Pair
}

type PairPair struct {
	first  int
	second Triple
}

func main() {
	var n int
	fmt.Scan(&n)
	tot := 0
	data := make([][]int, n)
	for i := 1; i <= n; i++ {
		var k, a, x, y, m int
		fmt.Scan(&k, &a, &x, &y, &m)
		tot += k
		tmp := make([]int, k)
		tmp[0] = a
		for j := 2; j <= k; j++ {
			tmp[j-1] = (tmp[j-2]*x + y) % m
		}
		data[i-1] = tmp
	}
	q := make([]PairPair, 0)
	for i := 0; i < n; i++ {
		q = append(q, PairPair{data[i][0], Triple{i, Pair{0, 0}}})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].first < q[j].first
	})
	ans := make([]int, 0)
	sol := make([]Pair, 0)
	p := 0
	for len(ans) < tot {
		it := 0
		for it < len(q) && q[it].first <= p {
			it++
		}
		if it == len(q) {
			it = 0
		}
		v := q[it].first
		p = v
		o := q[it].second
		ans = append(ans, v)
		sol = append(sol, Pair{v, o.first + 1})
		q = append(q[:it], q[it+1:]...)
		if o.second.second+1 < len(data[o.second.first]) {
			q = append(q, PairPair{data[o.second.first][o.second.second+1], Triple{o.second.first, Pair{o.second.second + 1, 0}}})
		}
	}

	bad := 0
	for i := 1; i < len(ans); i++ {
		if ans[i-1] > ans[i] {
			bad++
		}
	}
	fmt.Println(bad)
	if tot <= 200000 {
		for i := 0; i < len(sol); i++ {
			fmt.Println(sol[i].first, sol[i].second)
		}
	}
}
