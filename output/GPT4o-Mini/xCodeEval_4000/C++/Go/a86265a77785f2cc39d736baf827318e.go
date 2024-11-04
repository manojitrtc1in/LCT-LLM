package main

import (
	"fmt"
	"math"
)

const maxn = 200005
const mod = 998244353

var n, k int
var aa, bb [maxn]int
var fac, inv [maxn]int64

func read() int {
	var x int
	fmt.Scan(&x)
	return x
}

func add(x *int64, y int64) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func ksm(a, b int64) int64 {
	ans := int64(1)
	for b > 0 {
		if b&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		b >>= 1
	}
	return ans
}

func C(n, m int) int64 {
	return (fac[n] * inv[m] % mod * inv[n-m] % mod) % mod
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
		fac[i] = (fac[i-1] * int64(i)) % mod
	}
	inv[n] = ksm(fac[n], mod-2)
	for i := n - 1; i >= 0; i-- {
		inv[i] = (inv[i+1] * int64(i+1)) % mod
	}
	ans := int64(1)
	cnt := 0

	for i := 1; i <= n; i++ {
		if aa[i] == bb[i] {
			ans = (ans * int64(k)) % mod
		} else {
			cnt++
		}
	}

	tmpans := int64(0)
	for i := 0; i <= cnt; i += 2 {
		anss := (ksm(int64(k-2), int64(cnt-i)) * C(i, i>>1) % mod * C(cnt, i) % mod) % mod
		add(&tmpans, anss)
	}
	ans = (tmpans * ans) % mod

	Ans := ksm(int64(k), int64(n))
	Ans -= ans
	if Ans < 0 {
		Ans += mod
	}
	fmt.Println((Ans * ksm(2, mod-2)) % mod)
}
