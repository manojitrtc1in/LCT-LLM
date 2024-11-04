package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	fftmod = 998244353
)

var (
	fact     []int
	revFact  []int
)

func cnk(n, k int) int64 {
	return int64(fact[n]) * int64(revFact[k]) % int64(fftmod) * int64(revFact[n-k]) % int64(fftmod)
}

func solve() int {
	fact = make([]int, 201010)
	revFact = make([]int, 202020)

	fact[0] = 1
	const N = 200000
	for i := 1; i <= N; i++ {
		fact[i] = fact[i-1] * i % fftmod
	}

	revFact[N] = int(powmod(int64(fact[N]), int64(fftmod-2), int64(fftmod)))
	for i := N - 1; i >= 0; i-- {
		revFact[i] = revFact[i+1] * (i+1) % fftmod
	}

	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	a[n] = a[0]

	cnt := 0
	for i := 0; i < n; i++ {
		if a[i] != a[i+1] {
			cnt++
		}
	}

	if k == 1 || n == 1 {
		fmt.Println(0)
		return 0
	}

	ans := int64(0)
	freeChoices := k - 2
	for i := 0; i <= cnt/2; i++ {
		cur := cnk(cnt, i) * cnk(cnt-i, i) % int64(fftmod) * powmod(int64(freeChoices), int64(cnt-2*i), int64(fftmod)) % int64(fftmod) * powmod(int64(k), int64(n-cnt), int64(fftmod)) % int64(fftmod)
		ans += cur
	}
	ans %= int64(fftmod)
	tot := powmod(int64(k), int64(n), int64(fftmod)) - ans
	if tot < 0 {
		tot += int64(fftmod)
	}
	fmt.Println(tot * powmod(int64(2), int64(fftmod-2), int64(fftmod)) % int64(fftmod))

	return 0
}

func powmod(x, n, m int64) int64 {
	r := int64(1)
	x %= m
	for n > 0 {
		if n&1 == 1 {
			r *= x
			r %= m
		}
		x *= x
		x %= m
		n /= 2
	}
	return r
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}
