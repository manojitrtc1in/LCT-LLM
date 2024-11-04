package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const gigamod = 1000000007

var fr *FastReader
var out *bufio.Writer

func main() {
	fr = NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := 1

	for tc := 0; tc < t; tc++ {
		n := fr.NextInt()
		mod := fr.NextLong()

		dp := make([]int64, n+1)
		dp[n] = 1

		for i := n - 1; i > 0; i-- {
			dp[i] += dp[i+1]
			dp[i] %= mod

			for div := int64(1); div*i <= int64(n); div++ {
				lb := div * int64(i)
				ub := int64(math.Min(float64(div*(i+1)-1), float64(n)))
				segSum := dp[lb]
				if ub+1 <= int64(n) {
					segSum -= dp[ub+1]
				}
				dp[i] += segSum
				dp[i] %= mod
			}

			dp[i] += dp[i+1]
			dp[i] %= mod
		}

		fmt.Fprintln(out, (dp[1]-dp[2]+mod)%mod)
	}
}

type FastReader struct {
	bfr *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{bfr: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) Next() string {
	s, _ := fr.bfr.ReadString('\n')
	return s
}

func (fr *FastReader) NextInt() int {
	var x int
	fmt.Fscan(fr.bfr, &x)
	return x
}

func (fr *FastReader) NextLong() int64 {
	var x int64
	fmt.Fscan(fr.bfr, &x)
	return x
}
