package main

import (
	"fmt"
	"math/big"
)

const MOD = 998244353
const MAXN = 200005

var N int
var K int64
var A [MAXN]int64
var comb Combinatorics

type Combinatorics struct {
	fact    [MAXN]*big.Int
	invFact [MAXN]*big.Int
}

func (c *Combinatorics) init(N int, P int64) {
	c.fact[0] = big.NewInt(1)
	for i := 1; i <= N; i++ {
		c.fact[i] = new(big.Int).Mul(c.fact[i-1], big.NewInt(int64(i)))
		c.fact[i].Mod(c.fact[i], big.NewInt(P))
	}
	c.invFact[N] = new(big.Int).ModInverse(c.fact[N], big.NewInt(P))
	for i := N - 1; i >= 0; i-- {
		c.invFact[i] = new(big.Int).Mul(c.invFact[i+1], big.NewInt(int64(i+1)))
		c.invFact[i].Mod(c.invFact[i], big.NewInt(P))
	}
}

func mulMod(a, b, mod int64) int64 {
	return (a * b) % mod
}

func powMod(base, exp, mod int64) int64 {
	result := int64(1)
	for exp > 0 {
		if exp&1 == 1 {
			result = mulMod(result, base, mod)
		}
		base = mulMod(base, base, mod)
		exp >>= 1
	}
	return result
}

func addMod(a, b, mod int64) int64 {
	ret := a + b
	if ret >= mod {
		ret -= mod
	}
	return ret
}

func subMod(a, b, mod int64) int64 {
	ret := a - b
	if ret < 0 {
		ret += mod
	}
	return ret
}

func (c *Combinatorics) choose(N, K int, P int64) int64 {
	if K > N {
		return 0
	}
	return mulMod(mulMod(c.fact[N].Int64(), c.invFact[K].Int64(), P), c.invFact[N-K].Int64(), P)
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
		add := mulMod(comb.choose(int(cnt), int(i), MOD), comb.choose(int(cnt-i), int(i), MOD), MOD)
		add = mulMod(add, powMod(K, N-cnt, MOD), MOD)
		add = mulMod(add, powMod(K-2, cnt-2*i, MOD), MOD)
		ans = addMod(ans, add, MOD)
	}
	ans = subMod(powMod(K, N, MOD), ans, MOD)
	ans = mulMod(ans, powMod(2, MOD-2, MOD), MOD)
	fmt.Println(ans)
}
