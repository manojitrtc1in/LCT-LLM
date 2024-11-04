package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	inf     = int(1e8)
	modular = 998244353
	power   = Power{modular}
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, fW, hW int
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &m)
	a := make([]int, n)
	count := make([]int, 2)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
		count[a[i]%2]++
	}
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &w[i])
		if a[i]%2 == 0 {
			hW += w[i]
		} else {
			fW += w[i]
		}
	}

	inv := make([]int, m*2+1)
	for i := 0; i < m*2+1; i++ {
		inv[i] = power.inverse(hW + fW + i - m)
	}

	f := make([][]int, m+1)
	h := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		f[i] = make([]int, m+1)
		h[i] = make([]int, m+1)
	}

	for i := 0; i <= m; i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = -1
			h[i][j] = -1
		}
	}

	for i := 0; i <= m; i++ {
		f[i][0] = 1
		h[i][0] = 1
	}

	for i := 0; i < n; i++ {
		if a[i]%2 == 1 {
			fmt.Fprintln(writer, mul(w[i], f(0, m)))
		} else {
			fmt.Fprintln(writer, mul(w[i], h(0, m)))
		}
	}
}

func f(i, k int) int {
	if f[i][k] == -1 {
		j := (m - k) - i
		fixI := plus(i, fW)
		fixJ := plus(hW, -j)
		f[i][k] = 0
		inv := inv[i-j+m]
		f[i][k] = plus(f[i][k], mul(mul(plus(fixI, 1), inv), f(i+1, k-1)))
		f[i][k] = plus(f[i][k], mul(mul(fixJ, inv), f(i, k-1)))
	}
	return f[i][k]
}

func h(i, k int) int {
	if h[i][k] == -1 {
		j := (m - k) - i
		fixI := plus(i, fW)
		fixJ := plus(hW, -j)
		h[i][k] = 0
		inv := inv[i-j+m]
		h[i][k] = plus(h[i][k], mul(mul(plus(fixJ, -1), inv), h(i, k-1)))
		h[i][k] = plus(h[i][k], mul(mul(fixI, inv), h(i+1, k-1)))
	}
	return h[i][k]
}

func plus(a, b int) int {
	return (a + b) % modular
}

func mul(a, b int) int {
	return (a * b) % modular
}

type Power struct {
	modular int
}

func (p Power) pow(x int, n int) int {
	if n == 0 {
		return 1
	}
	r := p.pow(x, n>>1)
	r = mul(r, r)
	if n&1 == 1 {
		r = mul(r, x)
	}
	return r
}

func (p Power) inverse(x int) int {
	return p.pow(x, p.modular-2)
}
