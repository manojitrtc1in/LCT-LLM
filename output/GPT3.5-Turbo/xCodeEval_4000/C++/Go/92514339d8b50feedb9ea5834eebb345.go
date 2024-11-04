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

func pow2(v int64) int64 {
	return 1 << (63 - __builtin_clzll(v))
}

func solve2(x, y, k, bonus int64) int64 {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := pow2(y)
	tx := pow2(x)
	var res int64
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

		ans := solve2(int64(x2), int64(y2), int64(k)) - solve2(int64(x1-1), int64(y2), int64(k)) - solve2(int64(x2), int64(y1-1), int64(k)) + solve2(int64(x1-1), int64(y1-1), int64(k))
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

func powmod(x, n, m int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % m
		}
		x = (x * x) % m
		n >>= 1
	}
	return res
}
