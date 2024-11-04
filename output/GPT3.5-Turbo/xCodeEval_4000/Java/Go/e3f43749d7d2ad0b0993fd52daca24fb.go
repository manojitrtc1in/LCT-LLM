package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &MyScanner{scanner}
}

func (s *MyScanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *MyScanner) NextInt() int {
	val, _ := strconv.Atoi(s.Next())
	return val
}

func (s *MyScanner) NextLong() int64 {
	val, _ := strconv.ParseInt(s.Next(), 10, 64)
	return val
}

func (s *MyScanner) NextDouble() float64 {
	val, _ := strconv.ParseFloat(s.Next(), 64)
	return val
}

func (s *MyScanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *MyScanner) NextPairs(n int) (u, v []int) {
	u = make([]int, n)
	v = make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = s.NextInt()
		v[i] = s.NextInt()
	}
	return u, v
}

type MyPrintWriter struct {
	writer *bufio.Writer
}

func NewMyPrintWriter() *MyPrintWriter {
	return &MyPrintWriter{bufio.NewWriter(os.Stdout)}
}

func (p *MyPrintWriter) Print(a ...interface{}) {
	fmt.Fprint(p.writer, a...)
}

func (p *MyPrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(p.writer, a...)
}

func (p *MyPrintWriter) Printf(format string, a ...interface{}) {
	fmt.Fprintf(p.writer, format, a...)
}

func (p *MyPrintWriter) Flush() {
	p.writer.Flush()
}

func main() {
	scanner := NewMyScanner()
	writer := NewMyPrintWriter()
	defer writer.Flush()

	t := 1

	for i := 1; i <= t; i++ {
		n := scanner.NextInt()
		m := scanner.NextInt()
		u, v := scanner.NextPairs(m)

		ans := solve2(u, v, n)
		writer.Println(ans)
	}
}

func solve2(u, v []int, n int) int64 {
	dp := make([]int64, 1<<RADIX)
	for j := 0; j < RADIX; j++ {
		dp[1<<j] = 1
	}

	cmp := make([][]int, RADIX)
	for i := 0; i < RADIX; i++ {
		cmp[i] = make([]int, RADIX)
	}

	for i := 0; i < len(u); i++ {
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
				if 1<<k&mask == 0 {
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
				next[mask2] = val % MOD
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
