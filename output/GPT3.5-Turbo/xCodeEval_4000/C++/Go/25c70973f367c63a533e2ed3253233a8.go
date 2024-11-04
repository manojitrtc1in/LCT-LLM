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
	return NewMint(m.value + other.value)
}

func (m Mint) Subtract(other Mint) Mint {
	return NewMint(m.value - other.value)
}

func (m Mint) Multiply(other Mint) Mint {
	return NewMint(m.value * other.value)
}

func (m Mint) Power(n int) Mint {
	res := NewMint(1)
	x := m
	for n > 0 {
		if n&1 == 1 {
			res = res.Multiply(x)
		}
		x = x.Multiply(x)
		n >>= 1
	}
	return res
}

func (m Mint) String() string {
	return strconv.Itoa(m.value)
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func main() {
	tt := readInt()
	for tt > 0 {
		tt--
		m := int64(readInt())
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
		fmt.Println(dp[0])
	}
}
