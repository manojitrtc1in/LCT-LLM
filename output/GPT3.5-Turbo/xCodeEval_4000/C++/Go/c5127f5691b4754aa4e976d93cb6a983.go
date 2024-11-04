package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	maxn = 1e5 + 100
)

var (
	s string
	o [2][]int
	ind []int
	nxt [][]int
	it int
)

func can(n int) bool {
	if n == 1 {
		return true
	}

	IT := it
	x := n / 2
	y := (n + 1) / 2
	if !can(x) || !can(y) {
		return false
	}
	p0 := nxt[it][0]
	p1 := nxt[it][1]
	if p0 == len(s) || ind[p0]+x-1 >= len(o[0]) {
		p0 = len(s)
	} else {
		p0 = o[0][ind[p0]+x-1]
	}
	if p1 == len(s) || ind[p1]+y-1 >= len(o[1]) {
		p1 = len(s)
	} else {
		p1 = o[1][ind[p1]+y-1]
	}
	p0 = min(p0, p1)
	if p0 == len(s) {
		return false
	}
	it = p0 + 1

	return true
}

func id(l, r int, mas, id []int) {
	if l == r {
		return
	}
	m := (l + r - 1) / 2
	id(l, m, mas, id)
	id(m+1, r, mas, id)
	a := l
	b := m + 1
	c := l
	for a <= m && b <= r {
		if s[it] == '0' {
			mas[c] = id[a]
			a++
		} else {
			mas[c] = id[b]
			b++
		}
		it++
		c++
	}
	for a <= m {
		mas[c] = id[a]
		a++
		c++
	}
	for b <= r {
		mas[c] = id[b]
		b++
		c++
	}
	for i := l; i <= r; i++ {
		id[i] = mas[i]
	}
}

func go(n int, cert bool) bool {
	it = 0
	if !cert {
		return can(n)
	}
	it = 0
	can(n)
	if it == len(s) {
		it = 0
		id := make([]int, n)
		for i := 0; i < n; i++ {
			id[i] = i
		}
		mas := make([]int, n)
		id(0, n-1, mas, id)
		it = 0
		p := make([]int, n)
		for i := 0; i < n; i++ {
			p[id[i]] = i
		}
		fmt.Println(n)
		for _, v := range p {
			fmt.Printf("%d ", v+1)
		}
		fmt.Println()
		os.Exit(0)
	}
	return true
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve() {
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	s = strings.TrimSpace(s)
	counter := [2]int{}
	nxt = make([][]int, len(s)+1)
	ind = make([]int, len(s))
	for i := 0; i < len(s); i++ {
		c, _ := strconv.Atoi(string(s[i]))
		counter[c]++
		ind[i] = len(o[c])
		o[c] = append(o[c], i)
	}
	nxt[len(s)][0] = nxt[len(s)][1] = len(s)
	for i := len(s) - 1; i >= 0; i-- {
		nxt[i] = make([]int, 2)
		nxt[i][0] = nxt[i+1][0]
		nxt[i][1] = nxt[i+1][1]
		nxt[i][int(s[i])-48] = i
	}
	l := 0
	r := 1e5 + 10
	for r-l > 1 {
		m := (l + r) / 2
		if go(m, false) {
			l = m
		} else {
			r = m
		}
	}
	go(l, true)
}

func main() {
	solve()
}
