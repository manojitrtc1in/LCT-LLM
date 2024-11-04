package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func printInt(val int) {
	writer.WriteString(strconv.Itoa(val))
}

func printInt64(val int64) {
	writer.WriteString(strconv.FormatInt(val, 10))
}

func solve() {
	n := scanInt()
	g := make([][]bool, 10)
	for i := 0; i < 10; i++ {
		g[i] = make([]bool, 10)
	}
	for m := scanInt(); m > 0; m-- {
		x := scanInt()
		y := scanInt()
		g[x][y] = true
		g[y][x] = true
	}
	for i := 0; i < 10; i++ {
		g[i][i] = true
	}

	njs := make([][]int, 1<<9)
	for j := 0; j < 1<<9; j++ {
		njs[j] = make([]int, 10)
		for k := 0; k < 10; k++ {
			if j<<^(k-1) >= 0 {
				nj := j
				for l := 0; l < 10; l++ {
					if g[k][l] {
						if k > l {
							nj |= 1 << l
						}
					} else {
						nj &= ^(1 << l)
					}
				}
				njs[j][k] = nj
			}
		}
	}

	mod := 998244353
	dp := make([]int64, 1<<9)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		ndp := make([]int64, 1<<9)
		for j := 0; j < 1<<9; j++ {
			for k := 0; k < 10; k++ {
				if j<<^(k-1) >= 0 {
					nj := njs[j][k]
					ndp[nj] += dp[j]
					if ndp[nj] >= int64(mod) {
						ndp[nj] -= int64(mod)
					}
				}
			}
		}
		dp = ndp
	}
	ans := sum(dp) % int64(mod)
	printInt64(ans)
}

func sum(a []int64) int64 {
	var ret int64
	for _, v := range a {
		ret += v
	}
	return ret
}

func main() {
	initIO()
	solve()
	flush()
}
