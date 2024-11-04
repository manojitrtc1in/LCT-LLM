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

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func solve() {
	const mod = 998244353
	n := nextInt()
	a := make([]int, 26)
	for i := 0; i < 26; i++ {
		a[i] = nextInt()
	}
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

func pow(a, n, mod int) int64 {
	ret := int64(1)
	x := 63 - leadingZeros(n)
	for ; x >= 0; x-- {
		ret = (ret * ret) % int64(mod)
		if (n << (63 - x)) < 0 {
			ret = (ret * int64(a)) % int64(mod)
		}
	}
	return ret
}

func leadingZeros(l int) int {
	if l >= 1000000000 {
		return 0
	}
	if l >= 100000000 {
		return 1
	}
	if l >= 10000000 {
		return 2
	}
	if l >= 1000000 {
		return 3
	}
	if l >= 100000 {
		return 4
	}
	if l >= 10000 {
		return 5
	}
	if l >= 1000 {
		return 6
	}
	if l >= 100 {
		return 7
	}
	if l >= 10 {
		return 8
	}
	return 9
}

func next() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	n, _ := strconv.Atoi(next())
	return n
}

func nextInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt()
	}
	return arr
}

func nextInt64() int64 {
	n, _ := strconv.ParseInt(next(), 10, 64)
	return n
}

func nextInt64s(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64()
	}
	return arr
}

func nextFloat64() float64 {
	n, _ := strconv.ParseFloat(next(), 64)
	return n
}

func nextFloat64s(n int) []float64 {
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextFloat64()
	}
	return arr
}

func nextBytes() []byte {
	scanner.Scan()
	return scanner.Bytes()
}

func nextStrings(n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = next()
	}
	return arr
}

func nextStringSlice() []string {
	return strings.Fields(next())
}

func nextStringSlice2(n int) [][]string {
	arr := make([][]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextStringSlice()
	}
	return arr
}

func nextIntSlice() []int {
	return toIntSlice(nextStringSlice())
}

func nextIntSlice2(n int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextIntSlice()
	}
	return arr
}

func nextInt64Slice() []int64 {
	return toInt64Slice(nextStringSlice())
}

func nextInt64Slice2(n int) [][]int64 {
	arr := make([][]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64Slice()
	}
	return arr
}

func toIntSlice(arr []string) []int {
	res := make([]int, len(arr))
	for i, v := range arr {
		res[i], _ = strconv.Atoi(v)
	}
	return res
}

func toInt64Slice(arr []string) []int64 {
	res := make([]int64, len(arr))
	for i, v := range arr {
		res[i], _ = strconv.ParseInt(v, 10, 64)
	}
	return res
}
