package main

import (
	"fmt"
	"math"
	"sort"
)

type pii struct {
	first, second int64
}

func main() {
	var n int64
	fmt.Scan(&n)
	tot := int64(0)
	data := make([][]int64, n)

	for i := int64(0); i < n; i++ {
		var k, a, x, y, m int64
		fmt.Scan(&k, &a, &x, &y, &m)
		tot += k
		tmp := make([]int64, 0)
		tmp = append(tmp, a)
		for j := int64(2); j <= k; j++ {
			tmp = append(tmp, (tmp[len(tmp)-1]*x+y)%m)
		}
		data[i] = tmp
	}

	q := make([]pair, 0)
	for i := int64(0); i < n; i++ {
		q = append(q, pair{data[i][0], pii{i, 0}})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].first < q[j].first
	})

	ans := make([]int64, 0)
	sol := make([]pii, 0)
	p := int64(0)

	for int64(len(ans)) < tot {
		var it int
		for it = 0; it < len(q); it++ {
			if q[it].first >= p {
				break
			}
		}
		if it == len(q) {
			it = 0
		}
		v := q[it].first
		p = v
		o := q[it].second
		ans = append(ans, v)
		sol = append(sol, pii{v, o.first + 1})
		q = append(q[:it], q[it+1:]...) // remove the element at index it
		if o.second+1 < len(data[o.first]) {
			q = append(q, pair{data[o.first][o.second+1], pii{o.first, o.second + 1}})
		}
		sort.Slice(q, func(i, j int) bool {
			return q[i].first < q[j].first
		})
	}

	bad := int64(0)
	for i := int64(1); i < int64(len(ans)); i++ {
		if ans[i-1] > ans[i] {
			bad++
		}
	}
	fmt.Println(bad)
	if tot <= 200000 {
		for i := int64(0); i < int64(len(sol)); i++ {
			fmt.Println(sol[i].first, sol[i].second)
		}
	}
}

type pair struct {
	first int64
	second pii
}
