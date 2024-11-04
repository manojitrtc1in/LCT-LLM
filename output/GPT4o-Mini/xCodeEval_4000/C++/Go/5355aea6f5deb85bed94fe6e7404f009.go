package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	first  int64
	second int64
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

	q := make([]Pair, 0)
	for i := int64(0); i < n; i++ {
		q = append(q, Pair{data[i][0], i})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].first < q[j].first
	})

	ans := make([]int64, 0)
	sol := make([]Pair, 0)
	p := int64(0)

	for int64(len(ans)) < tot {
		index := sort.Search(len(q), func(i int) bool {
			return q[i].first >= p
		})

		if index == len(q) {
			index = 0
		}

		v := q[index].first
		p = v
		o := q[index].second
		ans = append(ans, v)
		sol = append(sol, Pair{v, o + 1})

		q = append(q[:index], q[index+1:]...) // Remove element at index

		if o+1 < len(data[o]) {
			q = append(q, Pair{data[o][o+1], o})
			sort.Slice(q, func(i, j int) bool {
				return q[i].first < q[j].first
			})
		}
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
