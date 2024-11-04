package main

import (
	"fmt"
	"sort"
)

type pair struct {
	first  int
	second int
}

type spi []pair

func (s spi) Len() int           { return len(s) }
func (s spi) Less(i, j int) bool { return s[i].first < s[j].first }
func (s spi) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func check(day int, pr spi, arr []int) bool {
	bue := make([]pair, 0)
	sum := 0
	for i := 0; i < len(arr); i++ {
		p := pair{i, -day}
		idx := sort.Search(len(pr), func(j int) bool { return pr[j].first >= p.first })
		if idx == len(pr) || pr[idx].first != p.first {
			sum += arr[i]
		} else {
			bue = append(bue, pair{-pr[idx].second, i})
		}
	}
	sort.Sort(spi(bue))

	moneyDelete := 0
	for _, p := range bue {
		money := p.first - moneyDelete
		need := arr[p.second]
		if need <= money {
			moneyDelete += need
		} else {
			moneyDelete += money
			sum += need - money
		}
	}
	return moneyDelete+sum*2 <= day
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	pr := make(spi, m)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		pr[i] = pair{b - 1, -a}
	}
	sort.Sort(pr)

	l := 0
	r := int(1e18)
	for l < r {
		mid := (l + r) / 2
		if check(mid, pr, arr) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	fmt.Println(l)
}
