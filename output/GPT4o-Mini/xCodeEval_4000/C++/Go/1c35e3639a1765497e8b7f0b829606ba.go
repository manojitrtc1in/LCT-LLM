package main

import (
	"fmt"
	"math/cmplx"
)

const mod = 998244353

type mint int

func (m mint) inv() mint {
	return pow(m, mod-2)
}

func (m mint) pow(exp int) mint {
	if exp == 0 {
		return 1
	}
	res := mint(1)
	base := m
	for exp > 0 {
		if exp%2 == 1 {
			res = res * base % mod
		}
		base = base * base % mod
		exp /= 2
	}
	return res
}

func (m mint) String() string {
	return fmt.Sprintf("%d", m)
}

func choose(a, b int) mint {
	if b < 0 || a < b {
		return 0
	}
	return fact[a] * ifact[b] * ifact[a-b] % mod
}

var fact, ifact []mint

func initFact(N int) {
	fact = make([]mint, N)
	ifact = make([]mint, N)
	fact[0] = 1
	for i := 1; i < N; i++ {
		fact[i] = fact[i-1] * mint(i) % mod
	}
	ifact[N-1] = fact[N-1].inv()
	for i := N - 2; i >= 0; i-- {
		ifact[i] = ifact[i+1] * mint(i+1) % mod
	}
}

func solve(N int) mint {
	res := mint(0)
	for i := 0; i <= N; i++ {
		if i == 0 {
			for j := 1; j <= N; j++ {
				res += mint(-1).pow(i+j) * choose(N, j) * mint(3).pow(j+N*(N-j))
			}
		} else {
			res += mint(-1).pow(i) * choose(N, i) * ((mint(3).pow(N-i) - 1).pow(N) - mint(3).pow((N-i)*N)) * 3
			res += mint(-1).pow(i) * choose(N, i) * mint(3).pow(i + N*(N-i))
		}
	}
	return -res
}

func main() {
	var N int
	fmt.Scan(&N)
	initFact(2000010)
	fmt.Println(solve(N))
}
