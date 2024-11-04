package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Mint struct {
	value int
}

func NewMint(x int) Mint {
	return Mint{x}
}

func (m Mint) Add(other Mint) Mint {
	m.value += other.value
	if m.value >= mod {
		m.value -= mod
	}
	return m
}

func (m Mint) Subtract(other Mint) Mint {
	m.value -= other.value
	if m.value < 0 {
		m.value += mod
	}
	return m
}

func (m Mint) Multiply(other Mint) Mint {
	m.value = normalize(int64(m.value) * int64(other.value))
	return m
}

func (m Mint) Divide(other Mint) Mint {
	return m.Multiply(inverse(other.value, mod))
}

func (m Mint) Power(b int) Mint {
	res := Mint{1}
	x := m
	for b > 0 {
		if b&1 == 1 {
			res = res.Multiply(x)
		}
		x = x.Multiply(x)
		b >>= 1
	}
	return res
}

func (m Mint) Normalize(x int) int {
	v := x
	if -mod <= x && x < mod {
		v = x
	} else {
		v = x % mod
	}
	if v < 0 {
		v += mod
	}
	return v
}

func inverse(a, m int) int {
	u, v := 0, 1
	for a != 0 {
		t := m / a
		m -= t * a
		a, m = m, a
		u -= t * v
		u, v = v, u
	}
	if m == 1 {
		return u
	}
	return 0
}

const mod = 998244353

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s string
	fmt.Fscanln(reader, &s)

	counter := make([]int, 2)
	o := make([][]int, 2)
	ind := make([]int, len(s))
	nxt := make([][2]int, len(s)+1)

	for i := 0; i < len(s); i++ {
		c := int(s[i] - '0')
		counter[c]++
		ind[i] = len(o[c])
		o[c] = append(o[c], i)
	}

	nxt[len(s)][0] = len(s)
	nxt[len(s)][1] = len(s)
	for i := len(s) - 1; i >= 0; i-- {
		nxt[i][0] = nxt[i+1][0]
		nxt[i][1] = nxt[i+1][1]
		nxt[i][s[i]-'0'] = i
	}

	l := 0
	r := 1e5 + 10
	for r-l > 1 {
		m := (l + r) / 2
		if can(m, nxt, ind, o) {
			l = m
		} else {
			r = m
		}
	}

	go(l, nxt, ind, o, writer)
}

func can(n int, nxt [][2]int, ind []int, o [][]int) bool {
	if n == 1 {
		return true
	}

	x := n / 2
	y := (n + 1) / 2
	if !can(x, nxt, ind, o) || !can(y, nxt, ind, o) {
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

func go(n int, nxt [][2]int, ind []int, o [][]int, writer *bufio.Writer) {
	it := 0
	if !can(n, nxt, ind, o) {
		return
	}

	it = 0
	can(n, nxt, ind, o)
	if it != len(s) {
		return
	}

	it = 0
	id := make([]int, n)
	for i := 0; i < n; i++ {
		id[i] = i
	}
	gen(0, n-1, id)
	if it != len(s) {
		return
	}

	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[id[i]] = i
	}

	fmt.Fprintln(writer, n)
	fmt.Fprintln(writer, strings.Trim(fmt.Sprint(p), "[]"))
}

func gen(l, r int, id []int) {
	if l == r {
		return
	}

	m := (l + r - 1) / 2
	gen(l, m, id)
	gen(m+1, r, id)

	a := l
	b := m + 1
	c := l
	for a <= m && b <= r {
		if s[it] == '0' {
			id[c] = id[a]
			a++
		} else {
			id[c] = id[b]
			b++
		}
		it++
	}
	for a <= m {
		id[c] = id[a]
		a++
		c++
	}
	for b <= r {
		id[c] = id[b]
		b++
		c++
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
