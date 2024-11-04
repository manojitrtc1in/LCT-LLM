package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	maxn = 1003
	md   = 998244353
)

var (
	s   string
	it  int
	e   [maxn][]int
	id  [maxn]int
	mas [maxn]int
	seg [maxn][2]int
)

func can(n int) bool {
	if n == 1 {
		return true
	}
	x := n / 2
	y := (n + 1) / 2
	if !can(x) || !can(y) {
		return false
	}
	a, b := 0, 0
	for it < len(s) {
		if s[it] == '0' {
			a++
		} else {
			b++
		}
		it++
		if a == x || b == y {
			break
		}
	}
	return a == x || b == y
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
			c++
			a++
		} else {
			mas[c] = id[b]
			c++
			b++
		}
		it++
	}
	for a <= m {
		mas[c] = id[a]
		c++
		a++
	}
	for b <= r {
		mas[c] = id[b]
		c++
		b++
	}
	for i := l; i <= r; i++ {
		id[i] = mas[i]
		if i > l {
			e[id[i-1]] = append(e[id[i-1]], id[i])
		}
	}
}

func go(n int) {
	it = 0
	if !can(n) || it != len(s) {
		return
	}

	it = 0
	for i := 0; i < n; i++ {
		id[i] = i
	}
	gen(0, n-1)
	if it != len(s) {
		return
	}
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[id[i]] = i
	}
	fmt.Println(n)
	for _, v := range p {
		fmt.Print(v + 1, " ")
	}
	fmt.Println()
	os.Exit(0)
}

func solve() {
	for i := 2; i < maxn; i++ {
		x := (i + 1) / 2
		y := i - x
		for t := 0; t < 2; t++ {
			seg[i][t] = seg[x][t] + seg[y][t]
		}
		seg[i][0] += x
		seg[i][1] += y
	}
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	s = s[:len(s)-1] // Remove newline
	counter := [2]int{0, 0}
	for _, c := range s {
		counter[c-48]++
	}
	for n := maxn - 1; n > 0; n-- {
		if seg[n][0] >= counter[0] && seg[n][1] >= counter[1] {
			go(n)
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	// Uncomment for file input/output
	// f, _ := os.Open("../a.in")
	// defer f.Close()
	// reader = bufio.NewReader(f)
	
	solve()
}
