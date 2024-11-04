package main

import (
	"fmt"
	"math"
	"sort"
)

type pi struct {
	first, second int64
}

type vi []int64

type spi map[pi]bool

type Node struct {
	a, del int64
	l, r   int
	lChildren, rChildren *Node
}

type LCA struct {
	N, n   int64
	up     [][]int64
	g      [][]int64
	lvl    []int64
}

type SNM struct {
	parent, size []int64
}

var zero = pi{-1, -1}

func gcd(a, b int64) int64 {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcdExtended(a, b int64) (int64, int64, int64) {
	if a == 0 {
		return 0, 1, b
	}
	x1, y1, d := gcdExtended(b%a, a)
	x := y1 - (b/a)*x1
	y := x1
	return x, y, d
}

func nok(a, b int64) int64 {
	nnod := gcd(a, b)
	ans := a / nnod * b
	return ans
}

func divup(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	} else {
		return a/b + 1
	}
}

func chec(day int64, pr spi, arr vi) bool {
	bue := make([]pi, 0)
	sum := int64(0)
	for i := 0; i < len(arr); i++ {
		p := pi{i, -day}
		it := pr.lower_bound(p)
		if it == pr.end() || it->first != i {
			sum += arr[i]
		} else {
			bue = append(bue, pi{-(it->second), i})
		}
	}
	sort.Slice(bue, func(i, j int) bool {
		return bue[i].first < bue[j].first
	})

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
	arr := make(vi, n)
	for i := 0; i < int(n); i++ {
		fmt.Scan(&arr[i])
	}
	pr := make(spi)
	for i := 0; i < int(m); i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		pr[pi{b - 1, -a}] = true
	}
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
