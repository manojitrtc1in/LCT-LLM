package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func solve() {
	const mod = 998244353
	n := ni()
	a := na(26)
	all := (26 * 26 * pow(25, n-2, mod)) % mod

	dp := make([][][]int64, 3)
	for i := 0; i < 3; i++ {
		dp[i] = make([][]int64, n+1)
		for j := 0; j <= n; j++ {
			dp[i][j] = make([]int64, n+1)
		}
	}

	dp[0][1][0] = 1
	dp[1][0][1] = 1
	dp[2][0][0] = 1

	for i := 0; i < n-1; i++ {
		ndp := make([][][]int64, 3)
		for j := 0; j < 3; j++ {
			ndp[j] = make([][]int64, n+1)
			for k := 0; k <= n; k++ {
				ndp[j][k] = make([]int64, n+1)
			}
		}

		if i == (n+1)/2-1 {
			for j := 0; j <= n; j++ {
				for k := 0; j+k <= n; k++ {
					if j+1 <= n {
						ndp[0][j+1][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24
						ndp[0][j+1][k] %= mod
					}
					if k+1 <= n {
						ndp[1][j][k+1] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24
						ndp[1][j][k+1] %= mod
					}
					ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24
					ndp[2][j][k] %= mod
				}
			}
		} else {
			for j := 0; j <= n; j++ {
				for k := 0; j+k <= n; k++ {
					if j+1 <= n {
						ndp[0][j+1][k] += dp[1][j][k] + dp[2][j][k]*24
						ndp[0][j+1][k] %= mod
					}
					if k+1 <= n {
						ndp[1][j][k+1] += dp[0][j][k] + dp[2][j][k]*24
						ndp[1][j][k+1] %= mod
					}
					ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*23
					ndp[2][j][k] %= mod
				}
			}
		}
		dp = ndp
	}

	sdp := make([]int64, n+1)
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			sdp[i] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j]*24
		}
		sdp[i] %= mod
	}

	for i := 0; i < 26; i++ {
		for k := a[i] + 1; k <= n; k++ {
			all -= sdp[k]
		}
	}

	for i := 0; i < 26; i++ {
		for j := i + 1; j < 26; j++ {
			for k := a[i] + 1; k <= n; k++ {
				for l := a[j] + 1; l+k <= n; l++ {
					all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l]*24)
				}
			}
			all %= mod
		}
	}
	all %= mod

	if all < 0 {
		all += mod
	}
	fmt.Fprintln(writer, all)
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - int64(numberOfLeadingZeros(n))
	for ; x >= 0; x-- {
		ret = (ret * ret) % mod
		if (n << (63 - x)) < 0 {
			ret = (ret * a) % mod
		}
	}
	return ret
}

func numberOfLeadingZeros(i int64) int {
	if i == 0 {
		return 64
	}
	n := int64(1)
	if i>>32 == 0 {
		n += 32
		i <<= 32
	}
	if i>>48 == 0 {
		n += 16
		i <<= 16
	}
	if i>>56 == 0 {
		n += 8
		i <<= 8
	}
	if i>>60 == 0 {
		n += 4
		i <<= 4
	}
	if i>>62 == 0 {
		n += 2
		i <<= 2
	}
	n -= int(i >> 63)
	return int(n)
}

func invl(a, mod int64) int64 {
	b := mod
	p := int64(1)
	q := int64(0)
	for b > 0 {
		c := a / b
		d := a
		a = b
		b = d % b
		d = p
		p = q
		q = d - c*q
	}
	if p < 0 {
		p += mod
	}
	return p
}

func C(n, r, mod int, fif [][]int) int64 {
	if n < 0 || r < 0 || r > n {
		return 0
	}
	return (int64(fif[0][n]) * int64(fif[1][r]) % int64(mod) * int64(fif[1][n-r])) % int64(mod)
}

func id0(n, mod int) [][]int {
	f := make([]int, n+1)
	invf := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = (f[i-1] * i) % mod
	}
	a := int64(f[n])
	b := int64(mod)
	p := int64(1)
	q := int64(0)
	for b > 0 {
		c := a / b
		d := a
		a = b
		b = d % b
		d = p
		p = q
		q = d - c*q
	}
	invf[n] = int(p)
	for i := n - 1; i >= 0; i-- {
		invf[i] = (invf[i+1] * (i + 1)) % mod
	}
	return [][]int{f, invf}
}

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func ni() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func na(n int) []int {
	scanner.Scan()
	nums := strings.Fields(scanner.Text())
	res := make([]int, n)
	for i, v := range nums {
		res[i], _ = strconv.Atoi(v)
	}
	return res
}
