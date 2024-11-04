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
	return Mint{x: normalize(x)}
}

func normalize(x int) int {
	v := x % md
	if v < 0 {
		v += md
	}
	return v
}

func (m Mint) Add(other Mint) Mint {
	return Mint{value: normalize(m.value + other.value)}
}

func (m Mint) Subtract(other Mint) Mint {
	return Mint{value: normalize(m.value - other.value)}
}

func (m Mint) Multiply(other Mint) Mint {
	return Mint{value: normalize(m.value * other.value)}
}

func (m Mint) Divide(other Mint) Mint {
	return Mint{value: normalize(m.value * inverse(other.value, md))}
}

func inverse(a, m int) int {
	u, v := 0, 1
	for a != 0 {
		t := m / a
		m -= t * a
		a, m = m, a
		u -= t * v
		u, v = v, u
	}
	if m == 1 {
		return u
	}
	panic("inverse does not exist")
}

func power(a Mint, b int) Mint {
	res := NewMint(1)
	for b > 0 {
		if b&1 == 1 {
			res = res.Multiply(a)
		}
		a = a.Multiply(a)
		b >>= 1
	}
	return res
}

func IsZero(number Mint) bool {
	return number.value == 0
}

func to_string(number Mint) string {
	return strconv.Itoa(number.value)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	tt, _ := strconv.Atoi(scanner.Text())
	for tt > 0 {
		scanner.Scan()
		m, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		len := 0
		d := make([]int, 123)
		for m > 0 {
			d[len] = int(m & 1)
			m >>= 1
			len++
		}
		dp := make([]Mint, 7)
		new_dp := make([]Mint, 7)
		for i := 0; i <= 6; i++ {
			dp[i] = NewMint(0)
			new_dp[i] = NewMint(0)
		}
		dp[0] = NewMint(1)
		for it := len - 1; it >= 0; it-- {
			if d[it] == 0 {
				new_dp[0] = dp[0].Add(dp[1]).Add(dp[2]).Add(dp[3])
				new_dp[1] = new_dp[2] = dp[1].Add(dp[2]).Add(dp[3]).Add(dp[4])
				new_dp[3] = new_dp[4] = dp[2].Add(dp[3]).Add(dp[4]).Add(dp[5])
				new_dp[5] = new_dp[6] = dp[3].Add(dp[4]).Add(dp[5]).Add(dp[6])
			} else {
				new_dp[0] = new_dp[1] = dp[0].Add(dp[1]).Add(dp[2]).Add(dp[3])
				new_dp[2] = new_dp[3] = dp[1].Add(dp[2]).Add(dp[3]).Add(dp[4])
				new_dp[4] = new_dp[5] = dp[2].Add(dp[3]).Add(dp[4]).Add(dp[5])
				new_dp[6] = dp[3].Add(dp[4]).Add(dp[5]).Add(dp[6])
			}
			dp, new_dp = new_dp, dp
		}
		fmt.Println(dp[0].value)
		tt--
	}
}
