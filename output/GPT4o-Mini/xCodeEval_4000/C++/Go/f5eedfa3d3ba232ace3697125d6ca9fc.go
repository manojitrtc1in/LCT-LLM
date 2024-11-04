package main

import (
	"fmt"
	"math"
)

const (
	T9         = 1000000000
	T18        = 1000000000000000000
	INF        = 1011111111
	LLINF      = 1000111000111000111
	mod        = 1000000007
	fftmod     = 998244353
	EPS        = 1e-10
	PI         = 3.14159265358979323846264
)

var (
	a       [1010101]int
	fact    [201010]int
	revFact [202020]int
)

func powmod(x, n, m int64) int64 {
	res := int64(1)
	x %= m
	for n > 0 {
		if n&1 == 1 {
			res = res * x % m
		}
		x = x * x % m
		n /= 2
	}
	return res
}

func cnk(n, k int) int64 {
	return (int64(fact[n]) * int64(revFact[k]) % fftmod * int64(revFact[n-k]) % fftmod) % fftmod
}

func solve() int {
	fact[0] = 1
	const N = 200000
	for i := 1; i <= N; i++ {
		fact[i] = fact[i-1] * i % fftmod
	}
	revFact[N] = int(powmod(int64(fact[N]), fftmod-2, fftmod))
	for i := N - 1; i >= 0; i-- {
		revFact[i] = revFact[i+1] * (i + 1) % fftmod
	}

	var n, k int
	fmt.Scan(&n, &k)
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
		cur := cnk(cnt, i) * cnk(cnt-i, i) % fftmod * powmod(int64(freeChoices), int64(cnt-2*i), fftmod) % fftmod * powmod(int64(k), int64(n-cnt), fftmod) % fftmod
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
