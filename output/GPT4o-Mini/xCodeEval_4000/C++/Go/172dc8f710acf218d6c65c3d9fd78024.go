package main

import (
	"bufio"
	"fmt"
	"os"
)

type pii struct {
	first  int
	second int
}

var s string
var tr [1010101]pii

func merge(a, b pii) pii {
	if b.first == 0 {
		a.second += b.second
		return a
	} else {
		b.first += a.first
		return b
	}
}

func build(cur, l, r int) {
	if l == r {
		if s[l] == 'A' {
			tr[cur] = pii{0, 1}
		} else {
			tr[cur] = pii{1, 0}
		}
	} else {
		m := (l + r) / 2
		dcur := cur + cur
		build(dcur, l, m)
		build(dcur+1, m+1, r)
		tr[cur] = merge(tr[dcur], tr[dcur+1])
	}
}

func get(cur, l, r, x, y int) pii {
	if x > r || y < l {
		return pii{}
	}
	if x <= l && r <= y {
		return tr[cur]
	}
	m := (l + r) / 2
	dcur := cur + cur
	return merge(get(dcur, l, m, x, y), get(dcur+1, m+1, r, x, y))
}

func solve() {
	var t string
	fmt.Scan(&s, &t)
	n := len(s)
	s += t
	sn := len(s)
	build(1, 0, sn-1)
	var q int
	fmt.Scan(&q)
	ans := ""

	for i := 0; i < q; i++ {
		var l [2]int
		var r [2]int
		for j := 0; j < 2; j++ {
			fmt.Scan(&l[j], &r[j])
			l[j] += n
			r[j] += n
			l[j]--
			r[j]--
		}
		a := get(1, 0, sn-1, l[0], r[0])
		b := get(1, 0, sn-1, l[1], r[1])
		if a.first > b.first || a.first%2 != b.first%2 || a.second < b.second {
			ans += "0"
			continue
		}
		if (a.first == b.first && a.second%3 == b.second%3) ||
			(a.first != b.first && a.first > 0) ||
			(a.second > b.second && a.first != b.first) {
			ans += "1"
		} else {
			ans += "0"
		}
	}
	fmt.Println(ans)
}

func main() {
	solve()
}
