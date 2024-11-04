package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const md = int(1e9) + 7

type Mint struct {
	value int
}

func NewMint(x int) Mint {
	x %= md
	if x < 0 {
		x += md
	}
	return Mint{x}
}

func (m Mint) Add(other Mint) Mint {
	m.value += other.value
	if m.value >= md {
		m.value -= md
	}
	return m
}

func (m Mint) Sub(other Mint) Mint {
	m.value -= other.value
	if m.value < 0 {
		m.value += md
	}
	return m
}

func (m Mint) Mul(other Mint) Mint {
	m.value = (m.value * other.value) % md
	return m
}

func (m Mint) Pow(n int) Mint {
	res := Mint{1}
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(m)
		}
		m = m.Mul(m)
		n >>= 1
	}
	return res
}

func (m Mint) String() string {
	return strconv.Itoa(m.value)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var tt int
	fmt.Fscan(reader, &tt)
	for tt > 0 {
		var m int64
		fmt.Fscan(reader, &m)
		d := make([]int, 0)
		for m > 0 {
			d = append(d, int(m&1))
			m >>= 1
		}
		dp := make([]Mint, 7)
		newDp := make([]Mint, 7)
		dp[0] = NewMint(1)
		for it := len(d) - 1; it >= 0; it-- {
			if d[it] == 0 {
				newDp[0] = dp[0].Add(dp[1]).Add(dp[2]).Add(dp[3])
				newDp[1] = newDp[2] = dp[1].Add(dp[2]).Add(dp[3]).Add(dp[4])
				newDp[3] = newDp[4] = dp[2].Add(dp[3]).Add(dp[4]).Add(dp[5])
				newDp[5] = newDp[6] = dp[3].Add(dp[4]).Add(dp[5]).Add(dp[6])
			} else {
				newDp[0] = newDp[1] = dp[0].Add(dp[1]).Add(dp[2]).Add(dp[3])
				newDp[2] = newDp[3] = dp[1].Add(dp[2]).Add(dp[3]).Add(dp[4])
				newDp[4] = newDp[5] = dp[2].Add(dp[3]).Add(dp[4]).Add(dp[5])
				newDp[6] = dp[3].Add(dp[4]).Add(dp[5]).Add(dp[6])
			}
			dp, newDp = newDp, dp
		}
		fmt.Fprintln(writer, dp[0])
		tt--
	}
}
