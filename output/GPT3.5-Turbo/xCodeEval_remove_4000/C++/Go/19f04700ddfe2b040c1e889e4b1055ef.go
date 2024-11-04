package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 998244353
const MAXN = 2e5 + 5

var N int
var K int64
var A [MAXN]int64
var comb Combinatorics

type Combinatorics struct {
	fact     [MAXN]int64
	invFact  [MAXN]int64
}

func (c *Combinatorics) init(N int) {
	c.fact[0] = 1
	for i := int64(1); i <= int64(N); i++ {
		c.fact[i] = c.fact[i-1] * i
	}
}

func (c *Combinatorics) initWithP(N int, P int64) {
	assert(N < P)
	c.fact[0] = 1
	for i := int64(1); i <= int64(N); i++ {
		c.fact[i] = mulMod(c.fact[i-1], i, P)
	}
	c.invFact[N] = id6(c.fact[N], P)
	for i := int64(N - 1); i >= 0; i-- {
		c.invFact[i] = mulMod(c.invFact[i+1], i+1, P)
	}
}

func (c *Combinatorics) factorial(N int) int64 {
	return c.fact[N]
}

func (c *Combinatorics) invFactorial(N int) int64 {
	return c.invFact[N]
}

func (c *Combinatorics) permute(N int, K int) int64 {
	return c.fact[N] / c.fact[N-K]
}

func (c *Combinatorics) permuteWithP(N int, K int, P int64) int64 {
	return mulMod(c.fact[N], c.invFact[N-K], P)
}

func (c *Combinatorics) choose(N int, K int) int64 {
	return c.fact[N] / (c.fact[K] * c.fact[N-K])
}

func (c *Combinatorics) chooseWithP(N int, K int, P int64) int64 {
	return mulMod(mulMod(c.fact[N], c.invFact[K], P), c.invFact[N-K], P)
}

func (c *Combinatorics) multiChoose(N int, K int) int64 {
	return c.choose(N+K-1, K)
}

func (c *Combinatorics) multiChooseWithP(N int, K int, P int64) int64 {
	return c.choose(N+K-1, K, P)
}

func posMod(a, mod int64) int64 {
	ret := -mod
	if ret < a && a < mod {
		ret = a
	} else {
		ret = a % mod
	}
	if ret >= 0 {
		return ret
	} else {
		return ret + mod
	}
}

func addMod(a, b, mod int64) int64 {
	ret := a + b
	if ret < mod {
		return ret
	} else {
		return ret - mod
	}
}

func subMod(a, b, mod int64) int64 {
	ret := a - b
	if ret >= 0 {
		return ret
	} else {
		return ret + mod
	}
}

func mulMod(a, b, mod int64) int64 {
	return a * b % mod
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

func id6(i, p int64) int64 {
	return powMod(i, p-2, p)
}

func id1(i, j, p int64) int64 {
	return mulMod(i, id6(j, p), p)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &N, &K)
	for i := 1; i <= N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	A[0] = A[N]
	if K == 1 {
		fmt.Fprintln(writer, 0)
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
	for i := 0; i*2 <= cnt; i++ {
		add := mulMod(comb.chooseWithP(cnt, i, MOD), comb.chooseWithP(cnt-i, i, MOD), MOD)
		add = mulMod(add, powMod(K, N-cnt, MOD), MOD)
		add = mulMod(add, powMod(K-2, cnt-2*i, MOD), MOD)
		ans = addMod(ans, add, MOD)
	}
	ans = subMod(powMod(K, N, MOD), ans, MOD)
	ans = id1(ans, 2, MOD)
	fmt.Fprintln(writer, ans)
}
