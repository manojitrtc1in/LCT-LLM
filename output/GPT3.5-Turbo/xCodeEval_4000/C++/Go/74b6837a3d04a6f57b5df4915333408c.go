package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	s string
	it int
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
	a := 0
	b := 0
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
	if a != x && b != y {
		return false
	}
	return true
}

func gen(l, r int, id []int, mas []int) {
	if l == r {
		return
	}
	m := (l + r - 1) / 2
	gen(l, m, id, mas)
	gen(m+1, r, id, mas)
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
		if i > l {
			e[id[i-1]] = append(e[id[i-1]], id[i])
		}
	}
}

func goFunc(n int) {
	it = 0
	if !can(n) || it != len(s) {
		return
	}
	it = 0
	id := make([]int, n)
	for i := 0; i < n; i++ {
		id[i] = i
	}
	mas := make([]int, n)
	gen(0, n-1, id, mas)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[id[i]] = i
	}
	fmt.Println(n)
	for _, val := range p {
		fmt.Print(val+1, " ")
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s = scanner.Text()
	counter := [2]int{}
	for _, c := range s {
		counter[c-'0']++
	}
	for n := maxn - 1; n > 0; n-- {
		if seg[n][0] >= counter[0] && seg[n][1] >= counter[1] {
			goFunc(n)
		}
	}
}

const (
	maxn = 1e3 + 100
	maxw = (1 << 20) + 5
	inf  = 1e9 + 100
	LG   = 18
)

var (
	e   [maxn][]int
	seg [maxn][2]int
)

func main() {
	solve()
}
