package main

import (
	"fmt"
	"math/big"
	"strings"
)

const MAXN = 200200

var (
	st  [MAXN]int
	p   [MAXN]int
	f   [MAXN]int
	s   string
	t   string
	h1  [MAXN]*big.Int
	h2  [MAXN]*big.Int
	p1  = big.NewInt(7)
	p2  = big.NewInt(13)
)

func buildHash() {
	cp := new(big.Int).Set(p1)
	h1[0] = big.NewInt(int64(t[0]))
	for i := 1; i < len(t); i++ {
		h1[i] = new(big.Int).Set(h1[i-1])
		h1[i].Add(h1[i], new(big.Int).Mul(big.NewInt(int64(t[i])), cp))
		cp.Mul(cp, p1)
	}

	cp.Set(p2)
	h2[0] = big.NewInt(int64(t[0]))
	for i := 1; i < len(t); i++ {
		h2[i] = new(big.Int).Set(h2[i-1])
		h2[i].Add(h2[i], new(big.Int).Mul(big.NewInt(int64(t[i])), cp))
		cp.Mul(cp, p2)
	}
}

func getH(l, r int) (pair [2]*big.Int, length int) {
	if l+f[l]-1 >= r {
		return [2]*big.Int{big.NewInt(-1), big.NewInt(-1)}, -1
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	length = e - b + 1

	hm1 := new(big.Int).Sub(h1[e], h1[b-1])
	hm1.Div(hm1, new(big.Int).Exp(p1, big.NewInt(int64(b)), nil))
	if p[r]%2 == 1 {
		length++
		hm1.Add(hm1, new(big.Int).Exp(p1, big.NewInt(int64(e-b+1)), nil))
	}

	if f[l]%2 == 1 {
		length++
		hm1.Set(new(big.Int).Add(big.NewInt(1), new(big.Int).Mul(hm1, p1)))
	}

	hm2 := new(big.Int).Sub(h2[e], h2[b-1])
	hm2.Div(hm2, new(big.Int).Exp(p2, big.NewInt(int64(b)), nil))
	if p[r]%2 == 1 {
		hm2.Add(hm2, new(big.Int).Exp(p2, big.NewInt(int64(e-b+1)), nil))
	}

	if f[l]%2 == 1 {
		hm2.Set(new(big.Int).Add(big.NewInt(1), new(big.Int).Mul(hm2, p2)))
	}

	return [2]*big.Int{hm1, hm2}, length
}

func getH2(l, r int) string {
	if l+f[l]-1 >= r {
		return "-1"
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	ans := t[b:e+1]
	if p[r]%2 == 1 {
		ans += "1"
	}
	if f[l]%2 == 1 {
		ans = "1" + ans
	}
	return ans
}

type DDostizhimieStroki struct{}

func (solver *DDostizhimieStroki) solve(in *strings.Reader, out *strings.Builder) {
	var n int
	fmt.Fscan(in, &n, &s)
	n = len(s)

	s = "0" + s + "0"

	for i := 0; i < len(s); i++ {
		if s[i] == '1' && s[i+1] == '1' {
			i++
			continue
		}
		t += string(s[i])
		st[i] = len(t) - 1
	}

	p[0] = 0
	if s[0] == '1' {
		p[0] = 1
	}

	for i := 1; i < len(s); i++ {
		if s[i] == '0' {
			p[i] = 0
		} else {
			p[i] = p[i-1] + 1
		}
	}

	f[len(s)-1] = 0

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '0' {
			f[i] = 0
		} else {
			f[i] = f[i+1] + 1
		}
	}

	buildHash()

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		var a, b, c int
		fmt.Fscan(in, &a, &b, &c)

		if getH(a, a+c-1) == getH(b, b+c-1) {
			out.WriteString("Yes\n")
		} else {
			out.WriteString("No\n")
		}
	}
}

func main() {
	var solver DDostizhimieStroki
	in := strings.NewReader("input data here") // Replace with actual input
	out := &strings.Builder{}
	solver.solve(in, out)
	fmt.Print(out.String())
}
