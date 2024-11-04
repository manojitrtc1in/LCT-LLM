package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	mod = 1000000007
)

func add(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func sub(x *int, y int) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func powlog2(v int) int {
	return 1 << (31 - __builtin_clz(v))
}

func solve2(x, y, k, bonus int) int {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := powlog2(y)
	tx := powlog2(x)
	var res int
	txk := min(tx, k)
	if tx == ty {
		res = txk * ty % mod * (txk + 1 + bonus*2) % mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = txk * y % mod * (txk + 1 + bonus*2) % mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
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

		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2, mod) % mod)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func powmod(x, n, m int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % m
		}
		x = x * x % m
		n >>= 1
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
