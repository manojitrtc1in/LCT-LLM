package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func nextInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func solve2(x, y, k, bonus int) int {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	if (x & (x - 1)) == 0 {
		k = min(k, x)
		return k * y % mod * (k + 1 + bonus*2) % mod
	}
	ty := id3(y)
	tx := id3(x)
	var res int64
	txk := min(tx, k)
	if tx == ty {
		res = int64(txk) * int64(ty) % mod * (int64(txk) + 1 + int64(bonus)*2) +
			int64(solve2(x-tx, tx, k-tx, bonus+tx)) +
			int64(solve2(y-tx, tx, k-tx, bonus+tx)) +
			int64(solve2(x-tx, y-tx, k, bonus))
	} else {
		res = int64(txk) * int64(y) % mod * (int64(txk) + 1 + int64(bonus)*2) +
			int64(solve2(x-tx, y, k-tx, bonus+tx))
	}
	return int(res % mod)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
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
		fmt.Println(int(ans * powmod(2, mod-2) % mod))
	}
}

func powmod(x, n int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

func id3(v int) int {
	return 1 << (31 - bits.Len(uint(v)))
}
