package main

import (
	"fmt"
)

const fftmod = 1000000007

func cnk(n, k int) int64 {
	fact := make([]int64, n+1)
	revFact := make([]int64, n+1)
	fact[0] = 1
	for i := 1; i <= n; i++ {
		fact[i] = fact[i-1] * int64(i) % fftmod
	}
	revFact[n] = powmod(fact[n], fftmod-2, fftmod)
	for i := n - 1; i >= 0; i-- {
		revFact[i] = revFact[i+1] * int64(i+1) % fftmod
	}
	return fact[n] * revFact[k] % fftmod * revFact[n-k] % fftmod
}

func powmod(x, n, m int64) int64 {
	r := int64(1)
	x %= m
	for n > 0 {
		if n&1 == 1 {
			r = r * x % m
		}
		x = x * x % m
		n >>= 1
	}
	return r
}

func solve() int {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	a = append(a, a[0])
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
		cur := cnk(cnt, i) * cnk(cnt-i, i) % fftmod * powmod(freeChoices, cnt-2*i, fftmod) % fftmod * powmod(int64(k), int64(n-cnt), fftmod) % fftmod
		ans += cur
	}
	ans %= fftmod
	tot := powmod(int64(k), int64(n), fftmod) - ans
	if tot < 0 {
		tot += fftmod
	}
	fmt.Println(tot * powmod(2, fftmod-2, fftmod) % fftmod)
	return 0
}

func main() {
	solve()
}
