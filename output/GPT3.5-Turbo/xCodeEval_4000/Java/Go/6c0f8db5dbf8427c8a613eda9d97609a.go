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

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanInt64() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanFloat() float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}

func printString(str string) {
	fmt.Fprint(writer, str)
}

func printInt(num int) {
	fmt.Fprint(writer, num)
}

func printInt64(num int64) {
	fmt.Fprint(writer, num)
}

func printFloat(num float64, precision int) {
	fmt.Fprintf(writer, "%.*f", precision, num)
}

func println() {
	fmt.Fprintln(writer)
}

func pow(a, n, mod int) int {
	ret := 1
	x := 63 - bits.LeadingZeros64(uint64(n))
	for ; x >= 0; x-- {
		ret = ret * ret % mod
		if n<<63-x < 0 {
			ret = ret * a % mod
		}
	}
	return ret
}

func invl(a, mod int) int {
	b := mod
	p, q := 1, 0
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

func C(n, r, mod int, fif [][]int) int {
	if n < 0 || r < 0 || r > n {
		return 0
	}
	return (fif[0][n] * fif[1][r] % mod * fif[1][n-r]) % mod
}

func enumFIF(n, mod int) [][]int {
	f := make([]int, n+1)
	invf := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = (f[i-1] * i) % mod
	}
	a := f[n]
	b := mod
	p, q := 1, 0
	for b > 0 {
		c := a / b
		d := a
		a = b
		b = d % b
		d = p
		p = q
		q = d - c*q
	}
	invf[n] = p
	for i := n - 1; i >= 0; i-- {
		invf[i] = (invf[i+1] * (i + 1)) % mod
	}
	return [][]int{f, invf}
}

func solve() {
	const mod = 998244353
	n := scanInt()
	a := make([]int, 26)
	for i := 0; i < 26; i++ {
		a[i] = scanInt()
	}
	all := (26 * 26 * pow(25, n-2, mod)) % mod

	dp := make([][][]int, 3)
	for i := 0; i < 3; i++ {
		dp[i] = make([][]int, n+1)
		for j := 0; j <= n; j++ {
			dp[i][j] = make([]int, n+1)
		}
	}
	dp[0][1][0] = 1
	dp[1][0][1] = 1
	dp[2][0][0] = 1
	for i := 0; i < n-1; i++ {
		ndp := make([][][]int, 3)
		for j := 0; j < 3; j++ {
			ndp[j] = make([][]int, n+1)
			for k := 0; k <= n; k++ {
				ndp[j][k] = make([]int, n+1)
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

	sdp := make([]int, n+1)
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
	printInt(all)
}

func main() {
	initIO()
	solve()
	flush()
}
