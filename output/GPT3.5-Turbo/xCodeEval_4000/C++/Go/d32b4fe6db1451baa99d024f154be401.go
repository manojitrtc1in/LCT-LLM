package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = 1011111111
	LLINF = 1000111000111000111
	EPS   = 1e-10
	mod   = 1000000007
	PI    = 3.14159265358979323
)

func add(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
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
	if (x & (x - 1)) == 0 {
		k = min(k, x)
		return k * (ll) y % mod * (k + 1 + bonus*2) % mod
	}
	ty := powlog2(y)
	tx := powlog2(x)
	var res int
	txk := min(tx, k)
	if tx == ty {
		res = txk * (ll) ty % mod * (txk + 1 + bonus*2) % mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = txk * (ll) y % mod * (txk + 1 + bonus*2) % mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < q; i++ {
		scanner.Scan()
		input := strings.Split(scanner.Text(), " ")
		x1, _ := strconv.Atoi(input[0])
		y1, _ := strconv.Atoi(input[1])
		x2, _ := strconv.Atoi(input[2])
		y2, _ := strconv.Atoi(input[3])
		k, _ := strconv.Atoi(input[4])

		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2LL, mod-2, mod) % mod)
	}
}
