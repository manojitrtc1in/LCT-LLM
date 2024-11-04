package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func add(x *int64, y int64) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func sub(x *int64, y int64) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func solve2(x, y, k, bonus int64) int64 {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x == y && (x&(x-1)) == 0 {
		k = min(k, x)
		return (k * (k + 1) % mod * x + bonus * k * 2 % mod * x) % mod
	}
	if x < y {
		x, y = y, x
	}
	ty := int64(1)
	for ty*2 <= y {
		ty *= 2
	}
	tx := int64(1)
	for tx*2 <= x {
		tx *= 2
	}
	var res int64
	txk := min(tx, k)
	if tx == ty {
		res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty
		res %= mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y
		res %= mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	q := nextInt(scanner)
	for i := 0; i < q; i++ {
		x1 := nextInt(scanner)
		y1 := nextInt(scanner)
		x2 := nextInt(scanner)
		y2 := nextInt(scanner)
		k := nextInt(scanner)

		ans := solve2(int64(x2), int64(y2), int64(k)) - solve2(int64(x1-1), int64(y2), int64(k)) - solve2(int64(x2), int64(y1-1), int64(k)) + solve2(int64(x1-1), int64(y1-1), int64(k))
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2) % mod)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func powmod(x, n int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}
