package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	maxn   = int(1.5 * 1e7)
	inf    = 1e9 + 7
	ll_inf  = 1e18 + 420
	eps    = 1e-4
	N      = 1e6 + 7
	MAX    = 2e5 + 9
	MOD    = 1e9 + 7
	pi     = 3.14159265359
)

func bpow(a, b int, mod int) int64 {
	res := int64(a)
	ret := int64(1)
	for b > 0 {
		if b%2 == 1 {
			ret = (ret * res) % int64(mod)
		}
		res = (res * res) % int64(mod)
		b /= 2
	}
	return ret % int64(mod)
}

func Random() {
	seed := time.Now().UnixNano()
	rand.Seed(seed)
}

func fact(n int64, mod int) int64 {
	fuc := int64(1)
	for i := int64(2); i <= n; i++ {
		fuc = fuc * i % int64(mod)
	}
	return fuc
}

func Cnk(n, r int64, mod int) int64 {
	r = min(r, n-r)
	ans := int64(1)
	for i := n; i >= (n - r + 1); i-- {
		ans = (ans * i) % int64(mod)
	}
	for i := int64(1); i <= r; i++ {
		ans = (ans * bpow(i, mod-2, mod)) % int64(mod)
	}
	return ans
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	Random()

	var b, d int
	var a, c [128]byte
	var t [128]int

	fmt.Scanf("%d%d", &b, &d)
	fmt.Scanf("%s%s", &a, &c)

	s := 0
	n := 0
	for c[n] != 0 {
		n++
	}

	for i := 0; c[i] != 0; i++ {
		k := &t[i]
		for j := 0; a[j] != 0; j++ {
			if a[j] == c[(i+*k)%n] {
				(*k)++
			}
		}
	}

	for i := 0; i < b; i++ {
		s += t[s%n]
	}
	fmt.Println(s / n / d)
}
