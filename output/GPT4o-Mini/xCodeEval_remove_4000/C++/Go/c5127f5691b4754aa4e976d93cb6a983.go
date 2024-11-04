package main

import (
	"bufio"
	"fmt"
	"os"
	"math/rand"
	"time"
)

const (
	maxn  = 1e5 + 100
	md    = 998244353
	inf   = 1e9 + 100
)

var (
	s    string
	o    [2][]int
	ind  []int
	nxt  [][]int
	it   int
	id   [maxn]int
	mas  [maxn]int
	seg  [maxn][2]int
	len  [maxn][2]int
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

func gen(l, r int) {
	if l == r {
		return
	}
	m := (l + r - 1) / 2
	gen(l, m)
	gen(m+1, r)
	a, b, c := l, m+1, l
	for a <= m && b <= r {
		if s[it] == '0' {
			mas[c] = id[a]
			a++
		} else {
			mas[c] = id[b]
			b++
		}
		c++
		it++
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
	if it != len(s) {
		panic("assertion failed")
	}

	it = 0
	for i := 0; i < n; i++ {
		id[i] = i
	}
	gen(0, n-1)
	if it != len(s) {
		panic("assertion failed")
	}
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[id[i]] = i
	}
	fmt.Println(n)
	for _, i := range p {
		fmt.Print(i + 1, " ")
	}
	fmt.Println()
	os.Exit(0)
	return true
}

func solve() {
	for i := 2; i < maxn; i++ {
		x := i / 2
		y := i - x
		len[i][0] = len[x][0] + len[y][0] + x
		len[i][1] = len[x][1] + len[y][1] + x + y - 1
		for t := 0; t < 2; t++ {
			seg[i][t] = seg[x][t] + seg[y][t]
		}
		seg[i][0] += x
		seg[i][1] += y
	}
	
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	s = s[:len(s)-1] // Remove newline character
	counter := [2]int{0, 0}
	nxt = make([][]int, len(s)+1)
	ind = make([]int, len(s))
	for i := 0; i < len(s); i++ {
		c := s[i] - '0'
		counter[c]++
		ind[i] = len(o[c])
		o[c] = append(o[c], i)
	}
	nxt[len(s)] = []int{len(s), len(s)}
	for i := len(s) - 1; i >= 0; i-- {
		for t := 0; t < 2; t++ {
			nxt[i][t] = nxt[i+1][t]
		}
		nxt[i][s[i]-'0'] = i
	}
	l, r := 0, 1e5 + 10
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	rand.Seed(time.Now().UnixNano())
	
	if false {
		te := 0
		for {
			fmt.Println(te + 1)
			solve()
			te++
		}
	}
	ts := 1

	for its := 1; its <= ts; its++ {
		solve()
	}
}
