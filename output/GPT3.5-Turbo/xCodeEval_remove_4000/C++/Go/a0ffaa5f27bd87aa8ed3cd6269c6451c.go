package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var pr = bufio.NewWriter(os.Stdout)

func read() int {
	sc.Scan()
	x, _ := strconv.Atoi(sc.Text())
	return x
}

func main() {
	sc.Split(bufio.ScanWords)
	n, m, mod := read(), read(), read()

	C := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		C[i] = make([]int, n+1)
	}
	C[0][0] = 1
	for i := 1; i <= n; i++ {
		C[i][0] = 1
		for j := 1; j <= n; j++ {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod
		}
	}

	g := make([]int, n+1)
	for i := 0; i <= n; i++ {
		g[i] = i * (i + 1) / 2
	}

	type pair struct {
		first, second int
	}
	f := make([]pair, n+1)
	f[0] = pair{1, 0}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			z := f[j].first * f[i-1-j].first * C[i-1][j] % mod
			f[i].first = (f[i].first + z*(i+1)) % mod
			f[i].second = (f[i].second + z*(g[j]+g[i-1-j])) % mod
			f[i].second = (f[i].second + (f[i-1-j].first*f[j].second+f[j].first*f[i-1-j].second)*C[i-1][j]*(i+1)) % mod
		}
	}

	dp := make([][]pair, n+2)
	for i := 0; i <= n+1; i++ {
		dp[i] = make([]pair, m+1)
	}
	dp[0][0] = pair{1, 0}
	for l := 0; l <= n; l++ {
		for r := l + 1; r <= n+1; r++ {
			di := r - l - 1
			for i := 0; i+di <= m; i++ {
				z := dp[l][i].first * f[di].first % mod
				dp[r][i+di].first = (dp[r][i+di].first + z*C[i+di][di]) % mod
				dp[r][i+di].second = (dp[r][i+di].second + (dp[l][i].second*f[di].first+dp[l][i].first*f[di].second)*C[i+di][di]) % mod
			}
		}
	}

	fmt.Fprintln(pr, dp[n+1][m].second)
	pr.Flush()
}
