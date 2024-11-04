package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

const (
	IMPOSSIBLE = "IMPOSSIBLE"
	POSSIBLE   = "POSSIBLE"
	YES        = "YES"
	NO         = "NO"
	MOD        = 998244353
	RADIX      = 10
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (ms *MyScanner) nextInt() int {
	ms.scanner.Scan()
	var x int
	fmt.Sscanf(ms.scanner.Text(), "%d", &x)
	return x
}

func (ms *MyScanner) nextPairs(n int) (u, v []int) {
	u = make([]int, n)
	v = make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = ms.nextInt()
		v[i] = ms.nextInt()
	}
	return
}

type MyPrintWriter struct {
	writer *bufio.Writer
}

func NewMyPrintWriter() *MyPrintWriter {
	return &MyPrintWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (mpw *MyPrintWriter) println(s string) {
	mpw.writer.WriteString(s + "\n")
}

func (mpw *MyPrintWriter) flush() {
	mpw.writer.Flush()
}

func main() {
	sol := &Round791F{}
	sol.run()
}

type Round791F struct {
	out *MyPrintWriter
	in  *MyScanner
}

func (r *Round791F) run() {
	r.in = NewMyScanner()
	r.out = NewMyPrintWriter()

	t := 1
	for i := 1; i <= t; i++ {
		n := r.in.nextInt()
		m := r.in.nextInt()
		u, v := r.in.nextPairs(m)

		ans := r.solve2(u, v, n)
		r.out.println(fmt.Sprintf("%d", ans))
	}

	r.out.flush()
}

func (r *Round791F) solve2(u, v []int, n int) int64 {
	dp := make([]int64, 1<<RADIX)
	for j := 0; j < RADIX; j++ {
		dp[1<<j] = 1
	}

	cmp := make([][]int, RADIX)
	for i := range cmp {
		cmp[i] = make([]int, RADIX)
	}

	m := len(u)
	for i := 0; i < m; i++ {
		small := min(u[i], v[i])
		larger := max(u[i], v[i])
		cmp[small][larger] = -1
		cmp[larger][small] = 1
	}

	isValid := make([][]bool, 1<<RADIX)
	mapMask := make([][]int, 1<<RADIX)
	for mask := 0; mask < 1<<RADIX; mask++ {
		isValid[mask] = make([]bool, RADIX)
		mapMask[mask] = make([]int, RADIX)
		for j := 0; j < RADIX; j++ {
			ok := true
			next := 1 << j
			for k := 0; k < RADIX; k++ {
				if (1<<k&mask) == 0 {
					continue
				}
				if cmp[j][k] == 0 {
				} else if cmp[j][k] == -1 {
					next |= 1 << k
				} else {
					ok = false
				}
			}
			isValid[mask][j] = ok
			mapMask[mask][j] = next
		}
	}

	for i := n - 2; i >= 0; i-- {
		next := make([]int64, 1<<RADIX)
		for mask := 0; mask < 1<<RADIX; mask++ {
			for j := 0; j < RADIX; j++ {
				if !isValid[mask][j] {
					continue
				}
				mask2 := mapMask[mask][j]
				val := next[mask2] + dp[mask]
				if val < MOD {
					next[mask2] = val
				} else {
					next[mask2] = val - MOD
				}
			}
		}
		dp = next
	}

	sum := int64(0)
	for mask := 0; mask < 1<<RADIX; mask++ {
		sum += dp[mask]
	}

	return sum % MOD
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
