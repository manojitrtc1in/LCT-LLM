package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	mod = 1000000007
)

type mint struct {
	x int64
}

func (a mint) neg() mint {
	return mint(-a.x)
}

func (a *mint) add(b mint) {
	a.x += b.x
	if a.x >= mod {
		a.x -= mod
	}
}

func (a *mint) sub(b mint) {
	a.x += mod - b.x
	if a.x >= mod {
		a.x -= mod
	}
}

func (a *mint) mul(b mint) {
	a.x = (a.x * b.x) % mod
}

func (a mint) pow(t int64) mint {
	res := mint(1)
	for t > 0 {
		if t&1 == 1 {
			res.mul(a)
		}
		a.mul(a)
		t >>= 1
	}
	return res
}

func (a mint) inv() mint {
	return a.pow(mod - 2)
}

func (a *mint) div(b mint) {
	a.mul(b.inv())
}

func (a mint) String() string {
	return fmt.Sprintf("%d", a.x)
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func readInt64() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func main() {
	q := readInt()
	for i := 0; i < q; i++ {
		solve()
	}
}

func solve() {
	t := readInt64()

	dp := make([][][][]mint, 61)
	for i := 0; i < 61; i++ {
		dp[i] = make([][][]mint, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([][]mint, 2)
			for k := 0; k < 2; k++ {
				dp[i][j][k] = make([]mint, 2)
			}
		}
	}

	dp[0][0][0][0] = mint(1)
	for i := 0; i < 60; i++ {
		f2 := (t >> i) & 1
		if f2 == 1 {
			dp[i+1][0][0][0].add(dp[i][0][0][0])
			dp[i+1][1][0][0].add(dp[i][0][0][0])
			dp[i+1][0][1][0].add(dp[i][0][0][0])
			dp[i+1][1][1][0].add(dp[i][0][0][0])
			dp[i+1][0][1][0].add(dp[i][0][0][1])
			dp[i+1][1][1][0].add(dp[i][0][0][1])
			dp[i+1][0][0][1].add(dp[i][0][0][1])
			dp[i+1][1][0][1].add(dp[i][0][0][1])
			dp[i+1][1][0][0].add(dp[i][0][1][0])
			dp[i+1][0][1][0].add(dp[i][0][1][0])
			dp[i+1][1][1][0].add(dp[i][0][1][0])
			dp[i+1][0][0][1].add(dp[i][0][1][0])
			dp[i+1][1][1][0].add(dp[i][0][1][1])
			dp[i+1][0][0][1].add(dp[i][0][1][1])
			dp[i+1][1][0][1].add(dp[i][0][1][1])
			dp[i+1][0][1][1].add(dp[i][0][1][1])
			dp[i+1][0][0][0].add(dp[i][1][0][0])
			dp[i+1][1][0][0].add(dp[i][1][0][0])
			dp[i+1][0][1][0].add(dp[i][1][0][0])
			dp[i+1][1][1][0].add(dp[i][1][0][0])
			dp[i+1][0][1][0].add(dp[i][1][0][1])
			dp[i+1][1][1][0].add(dp[i][1][0][1])
			dp[i+1][0][0][1].add(dp[i][1][0][1])
			dp[i+1][1][0][1].add(dp[i][1][0][1])
			dp[i+1][1][0][0].add(dp[i][1][1][0])
			dp[i+1][0][1][0].add(dp[i][1][1][0])
			dp[i+1][1][1][0].add(dp[i][1][1][0])
			dp[i+1][0][0][1].add(dp[i][1][1][0])
			dp[i+1][1][1][0].add(dp[i][1][1][1])
			dp[i+1][0][0][1].add(dp[i][1][1][1])
			dp[i+1][1][0][1].add(dp[i][1][1][1])
			dp[i+1][0][1][1].add(dp[i][1][1][1])
		} else {
			dp[i+1][0][0][0].add(dp[i][0][0][0])
			dp[i+1][1][0][0].add(dp[i][0][0][0])
			dp[i+1][0][1][0].add(dp[i][0][0][0])
			dp[i+1][1][1][0].add(dp[i][0][0][0])
			dp[i+1][0][1][0].add(dp[i][0][0][1])
			dp[i+1][1][1][0].add(dp[i][0][0][1])
			dp[i+1][0][0][1].add(dp[i][0][0][1])
			dp[i+1][1][0][1].add(dp[i][0][0][1])
			dp[i+1][1][0][0].add(dp[i][0][1][0])
			dp[i+1][0][1][0].add(dp[i][0][1][0])
			dp[i+1][1][1][0].add(dp[i][0][1][0])
			dp[i+1][0][0][1].add(dp[i][0][1][0])
			dp[i+1][1][1][0].add(dp[i][0][1][1])
			dp[i+1][0][0][1].add(dp[i][0][1][1])
			dp[i+1][1][0][1].add(dp[i][0][1][1])
			dp[i+1][0][1][1].add(dp[i][0][1][1])
			dp[i+1][1][0][0].add(dp[i][1][0][0])
			dp[i+1][0][1][0].add(dp[i][1][0][0])
			dp[i+1][1][1][0].add(dp[i][1][0][0])
			dp[i+1][0][0][1].add(dp[i][1][0][0])
			dp[i+1][1][1][0].add(dp[i][1][0][1])
			dp[i+1][0][0][1].add(dp[i][1][0][1])
			dp[i+1][1][0][1].add(dp[i][1][0][1])
			dp[i+1][0][1][1].add(dp[i][1][0][1])
			dp[i+1][0][1][0].add(dp[i][1][1][0])
			dp[i+1][1][1][0].add(dp[i][1][1][0])
			dp[i+1][0][0][1].add(dp[i][1][1][0])
			dp[i+1][1][0][1].add(dp[i][1][1][0])
