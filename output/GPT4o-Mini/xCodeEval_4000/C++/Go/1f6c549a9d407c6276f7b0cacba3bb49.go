package main

import (
	"fmt"
)

const mod = 998244353
const K = 18

type Mint struct {
	n int
}

func NewMint(n int) Mint {
	n %= mod
	if n < 0 {
		n += mod
	}
	return Mint{n}
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

func (m Mint) Pow(exp int) Mint {
	res := NewMint(1)
	x := m
	for exp > 0 {
		if exp&1 == 1 {
			res = res.Mul(x)
		}
		x = x.Mul(x)
		exp >>= 1
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(mod - 2)
}

type Poly struct {
	c []Mint
}

func NewPoly(size int) Poly {
	return Poly{make([]Mint, size)}
}

func (p *Poly) Log() Poly {
	n := len(p.c)
	if n == 0 || p.c[0].n != 1 {
		return Poly{}
	}
	r := NewPoly(n - 1)
	for i := 1; i < n; i++ {
		r.c[i-1] = p.c[i].Mul(NewMint(i))
	}
	return r
}

func (p *Poly) Exp() Poly {
	n := len(p.c)
	if n == 0 || p.c[0].n != 0 {
		return Poly{}
	}
	r := NewPoly(n)
	r.c[0] = NewMint(1)
	for i := 1; i < n; i++ {
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
	A.c[1] = NewMint((k - 2) % mod)
	A.c[2] = NewMint(1)

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(NewMint(n - cnt))
	}

	C := B.Exp()

	ans := NewMint(k % mod).Pow(n - cnt)
	for i := 0; i <= n-cnt; i++ {
		ans = ans.Sub(C.c[i])
	}

	ans = ans.Mul(NewMint(k % mod).Pow(cnt))
	fmt.Println(ans.n)
}
