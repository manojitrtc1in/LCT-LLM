package main

import (
	"fmt"
	"math"
)

const MOD = 998244353
const MAXN = 200005

var N int
var K int64
var A [MAXN]int64
var comb Combinatorics

type Combinatorics struct {
	fact    [MAXN]int64
	invFact [MAXN]int64
}

func (c *Combinatorics) init(N int, P int64) {
	c.fact[0] = 1
	for i := 1; i <= N; i++ {
		c.fact[i] = mulMod(c.fact[i-1], int64(i), P)
	}
	c.invFact[N] = mulInvPrime(c.fact[N], P)
	for i := N - 1; i >= 0; i-- {
		c.invFact[i] = mulMod(c.invFact[i+1], int64(i+1), P)
	}
}

func mulMod(a, b, mod int64) int64 {
	return (a * b) % mod
}

func powMod(base, pow, mod int64) int64 {
	x := int64(1)
	for pow > 0 {
		if pow&1 == 1 {
			x = mulMod(x, base, mod)
		}
		base = mulMod(base, base, mod)
		pow >>= 1
	}
	return x
}

func mulInvPrime(i, p int64) int64 {
	return powMod(i, p-2, p)
}

func choose(N, K int, P int64) int64 {
	return mulMod(mulMod(comb.fact[N], comb.invFact[K], P), comb.invFact[N-K], P)
}

func main() {
	fmt.Scan(&N, &K)
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}
	A[0] = A[N]

	if K == 1 {
		fmt.Println(0)
		return
	}

	comb.init(N, MOD)
	cnt := int64(0)
	for i := 0; i < N; i++ {
		if A[i] != A[i+1] {
			cnt++
		}
	}

	ans := int64(0)
	for i := int64(0); i*2 <= cnt; i++ {
		add := mulMod(choose(int(cnt), int(i), MOD), choose(int(cnt-i), int(i), MOD), MOD)
		add = mulMod(add, powMod(K, N-cnt, MOD), MOD)
		add = mulMod(add, powMod(K-2, cnt-2*i, MOD), MOD)
		ans = (ans + add) % MOD
	}

	ans = (powMod(K, N, MOD) - ans + MOD) % MOD
	ans = divModPrime(ans, 2, MOD)
	fmt.Println(ans)
}

func divModPrime(i, j, p int64) int64 {
	return mulMod(i, mulInvPrime(j, p), p)
}
