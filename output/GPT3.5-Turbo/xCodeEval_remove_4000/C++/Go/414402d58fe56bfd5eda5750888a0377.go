package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = int(1e9) + 7

type Mint int

func (m Mint) Add(a Mint) Mint {
	m += a
	if m >= mod {
		m -= mod
	}
	return m
}

func (m Mint) Sub(a Mint) Mint {
	m -= a
	if m < 0 {
		m += mod
	}
	return m
}

func (m Mint) Mul(a Mint) Mint {
	return Mint(int(m) * int(a) % mod)
}

func (m Mint) Pow(n int) Mint {
	res := Mint(1)
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(m)
		}
		m = m.Mul(m)
		n >>= 1
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(mod - 2)
}

func (m Mint) Div(a Mint) Mint {
	return m.Mul(a.Inv())
}

func (m Mint) String() string {
	return strconv.Itoa(int(m))
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	tt := nextInt(scanner)
	for tt > 0 {
		m := nextInt64(scanner)
		d := make([]int, 0)
		for m > 0 {
			d = append(d, int(m&1))
			m >>= 1
		}
		dp := make([]Mint, 7)
		newDp := make([]Mint, 7)
		dp[0] = 1
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
		tt--
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return n
}
