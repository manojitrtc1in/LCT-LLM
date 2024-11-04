package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const (
	T9      = 1000000000
	T18     = 1000000000000000000
	INF     = 1011111111
	LLINF   = 1000111000111000111
	mod     = 1000000007
	fftmod  = 998244353
	EPS     = 1e-10
	PI      = 3.14159265358979323846264
)

var (
	a [1010101]int
	b [1010101]int64
)

func solve() int {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)
	k++

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a[:n], func(i, j int) bool {
		return a[i] > a[j]
	})

	for i := 0; i < n; i++ {
		b[n-1-i] = int64(a[n-1-i]) * int64(i/max(k, 1))
	}
	for i := n - 1; i >= 0; i-- {
		b[i] += b[i+1]
	}

	cum := int64(0)
	sum := int64(0)
	ans := b[0]
	if k > 0 {
		for i := 0; i < n; i++ {
			res := sum + b[i]
			longest := (n - i - 1) / k + 1
			ans = max(ans, res+cum*longest)
			sum += cum
			cum += int64(a[i])
		}
	}
	fmt.Println(ans)
	return 0
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}
