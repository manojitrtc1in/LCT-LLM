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

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readInt64() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func writeString(s string) {
	fmt.Fprint(writer, s)
}

func writeInt(num int) {
	fmt.Fprint(writer, num)
}

func writeInt64(num int64) {
	fmt.Fprint(writer, num)
}

func solve() {
	n := readInt()
	g := make([][]bool, 10)
	for i := 0; i < 10; i++ {
		g[i] = make([]bool, 10)
	}
	for m := readInt(); m > 0; m-- {
		x := readInt()
		y := readInt()
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
			if j<<^k >= 0 {
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
				if j<<^k >= 0 {
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
	writeInt64(ans)
}

func sum(a []int64) int64 {
	ret := int64(0)
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
