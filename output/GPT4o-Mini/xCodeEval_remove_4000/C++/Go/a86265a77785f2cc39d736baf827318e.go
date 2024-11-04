package main

import (
	"fmt"
	"math"
)

const (
	maxn = 200005
	mod  = 998244353
)

var (
	n, k int
	aa   [maxn]int
	bb   [maxn]int
	fac  [maxn]int
	inv  [maxn]int
)

func read() int {
	var x int
	fmt.Scan(&x)
	return x
}

func ksm(a, b int) int {
	ans := 1
	for b > 0 {
		if b&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		b >>= 1
	}
	return ans
}

func C(n, m int) int {
	return (fac[n] * inv[m] % mod * inv[n-m] % mod) % mod
}

func add(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func pre(x int) int {
	x--
	if x < 1 {
		x = n
	}
	return x
}

func main() {
	n = read()
	k = read()
	for i := 1; i <= n; i++ {
		aa[i] = read()
		bb[pre(i)] = aa[i]
	}
	fac[0] = 1
	for i := 1; i <= n; i++ {
		fac[i] = (fac[i-1] * i) % mod
	}
	inv[n] = ksm(fac[n], mod-2)
	for i := n - 1; i >= 0; i-- {
		inv[i] = (inv[i+1] * (i + 1)) % mod
	}
	ans := 1
	cnt := 0

	for i := 1; i <= n; i++ {
		if aa[i] == bb[i] {
			ans = (ans * k) % mod
		} else {
			cnt++
		}
	}

	tmpans := 0
	for i := 0; i <= cnt; i += 2 {
		anss := (ksm(k-2, cnt-i) * C(i, i>>1) % mod * C(cnt, i) % mod) % mod
		add(&tmpans, anss)
	}
	ans = (tmpans * ans) % mod

	Ans := ksm(k, n)
	Ans -= ans
	if Ans < 0 {
		Ans += mod
	}
	fmt.Println((Ans * ksm(2, mod-2)) % mod)
}
