package main

import (
	"fmt"
	"sort"
)

type pi struct {
	first  int64
	second int64
}

type spi []pi

func (s spi) Len() int           { return len(s) }
func (s spi) Less(i, j int) bool { return s[i].first < s[j].first }
func (s spi) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func cinArr(arr []int64) {
	for i := 0; i < len(arr); i++ {
		fmt.Scan(&arr[i])
	}
}

func chec(day int64, pr spi, arr []int64) bool {
	bue := make([]pi, 0)
	sum := int64(0)
	for i := 0; i < len(arr); i++ {
		p := pi{first: int64(i), second: -day}
		idx := sort.Search(len(pr), func(j int) bool { return pr[j].first >= p.first })
		if idx == len(pr) || pr[idx].first != p.first {
			sum += arr[i]
		} else {
			bue = append(bue, pi{first: -pr[idx].second, second: p.first})
		}
	}
	sort.Sort(spi(bue))

	moneyDelete := int64(0)
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
	var n, m int64
	fmt.Scan(&n, &m)
	arr := make([]int64, n)
	cinArr(arr)
	pr := make(spi, m)
	for i := 0; i < int(m); i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		pr[i] = pi{first: b - 1, second: -a}
	}
	sort.Sort(pr)
	l := int64(0)
	r := int64(1e6)
	for l < r {
		mid := (l + r) / 2
		if chec(mid, pr, arr) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	fmt.Println(l)
}
