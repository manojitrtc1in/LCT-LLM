package main

import (
	"fmt"
)

const mod = 998244353
const K = 18

type Mint struct {
	n int64
}

func NewMint(n int64) Mint {
	return Mint{(n % mod + mod) % mod}
}

func (m Mint) Add(rhs Mint) Mint {
	return NewMint(m.n + rhs.n)
}

func (m Mint) Sub(rhs Mint) Mint {
	return NewMint(m.n - rhs.n)
}

func (m Mint) Mul(rhs Mint) Mint {
	return NewMint(m.n * rhs.n)
}

func (m Mint) Pow(exp int64) Mint {
	res := Mint{1}
	base := m
	for exp > 0 {
		if exp%2 == 1 {
			res = res.Mul(base)
		}
		base = base.Mul(base)
		exp /= 2
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(mod - 2)
}

type Poly struct {
	c []Mint
}

func NewPoly(n int) Poly {
	return Poly{make([]Mint, n+1)}
}

func (p *Poly) Log() Poly {
	n := len(p.c) - 1
	if p.c[0].n != 0 {
		panic("Log of zero polynomial")
	}
	r := NewPoly(n - 1)
	for i := 1; i <= n; i++ {
		r.c[i-1] = p.c[i].Mul(NewMint(int64(i))).Inv()
	}
	return r
}

func (p *Poly) Exp() Poly {
	n := len(p.c) - 1
	if p.c[0].n != 0 {
		panic("Exp of non-zero polynomial")
	}
	r := NewPoly(n)
	r.c[0] = NewMint(1)
	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			r.c[i] = r.c[i].Add(r.c[j].Mul(p.c[i-j]))
		}
	}
	return r
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	hs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&hs[i])
	}

	cnt := 0
	for i := 0; i < n; i++ {
		if hs[i] == hs[(i+1)%n] {
			cnt++
		}
	}

	if cnt == n {
		fmt.Println(0)
		return
	}

	A := NewPoly(200000 + 1000)
	A.c[0] = NewMint(1)
	A.c[1] = NewMint(int64(k - 2))
	A.c[2] = NewMint(1)

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(NewMint(int64(n - cnt)))
	}

	C := B.Exp()

	ans := NewMint(int64(k)).Pow(int64(n - cnt))
	for i := 0; i <= n-cnt; i++ {
		ans = ans.Sub(C.c[i])
	}

	ans = ans.Mul(NewMint(int64(k)).Pow(int64(cnt)))
	fmt.Println(ans.n)
}
