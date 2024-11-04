package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func solve2(x, y, k, bonus int) int {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := pow2(y)
	tx := pow2(x)
	var res int
	txk := min(tx, k)
	if tx == ty {
		res = txk * ty % mod * (txk + 1 + bonus*2) % mod
		res += solve2(x-tx, tx, k-tx, bonus+tx)
		res += solve2(y-tx, tx, k-tx, bonus+tx)
		res += solve2(x-tx, y-tx, k, bonus)
	} else {
		res = txk * y % mod * (txk + 1 + bonus*2) % mod
		res += solve2(x-tx, y, k-tx, bonus+tx)
	}
	return res
}

func pow2(v int) int {
	return 1 << (63 - __builtin_clzll(uint64(v)))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc.Split(bufio.ScanWords)

	q := nextInt()
	for i := 0; i < q; i++ {
		x1 := nextInt()
		y1 := nextInt()
		x2 := nextInt()
		y2 := nextInt()
		k := nextInt()

		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2) % mod)
	}
}

func powmod(x, n int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}
