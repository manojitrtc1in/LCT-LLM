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
	res := m.value + other.value
	if res >= md {
		res -= md
	}
	return Mint{res}
}

func (m Mint) Sub(other Mint) Mint {
	res := m.value - other.value
	if res < 0 {
		res += md
	}
	return Mint{res}
}

func (m Mint) Mul(other Mint) Mint {
	return Mint{(m.value * other.value) % md}
}

func (m Mint) Pow(n int) Mint {
	res := Mint{1}
	x := m
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(x)
		}
		x = x.Mul(x)
		n >>= 1
	}
	return res
}

func (m Mint) String() string {
	return strconv.Itoa(m.value)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())
	return x
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
