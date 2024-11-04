package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	inf      = int(1e8)
	modular  = 998244353
	power    = 998244353
	f        [][]int
	h        [][]int
	n        int
	m        int
	fW       int
	hW       int
	inv      []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, _ = strconv.Atoi(readLine(reader))
	m, _ = strconv.Atoi(readLine(reader))
	a := make([]int, n)
	count := make([]int, 2)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine(reader))
		count[a[i]%2]++
	}
	w := make([]int, n)
	for i := 0; i < n; i++ {
		w[i], _ = strconv.Atoi(readLine(reader))
		if a[i]%2 == 0 {
			hW += w[i]
		} else {
			fW += w[i]
		}
	}

	inv = make([]int, m*2+1)
	for i := 0; i < m*2+1; i++ {
		inv[i] = inverse(power, hW+fW+i-m)
	}

	f = make([][]int, m+1)
	h = make([][]int, m+1)
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

func inverse(a, b int) int {
	return pow(a, b-2)
}

func pow(a, b int) int {
	if b == 0 {
		return 1
	}
	r := pow(a, b>>1)
	r = mul(r, r)
	if b&1 == 1 {
		r = mul(r, a)
	}
	return r
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str[:len(str)-1]
}
