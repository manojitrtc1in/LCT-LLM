package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 998244353
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, m, k := readThreeNums(reader)

	res := solve(n, m, k)

	fmt.Fprintf(writer, "%d\n", res)
}

func solve(n, m, k int) int {
	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = pow(i, k)
	}

	ans := 0
	for t := 0; t <= k; t++ {
		p1 := get(n, k, mod, t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := composite(t, i, mod)
			contrib = mul(contrib, xk[t-i], mod)
			if i%2 == 1 {
				contrib = valueOf(-contrib, mod)
			}
			p2 = plus(p2, contrib, mod)
		}
		p3 := inverse(t, mod)

		contrib := mul(p1, p2, mod)
		contrib = mul(contrib, p3, mod)
		ans = plus(ans, contrib, mod)
	}

	return ans
}

func get(n, k, mod, t int) int {
	bc := newID1(n, k, mod)
	p2 := 0
	for i := 0; i <= t; i++ {
		contrib := composite(t, i, mod)
		contrib = mul(contrib, pow(i, k), mod)
		if i%2 == 1 {
			contrib = valueOf(-contrib, mod)
		}
		p2 = plus(p2, contrib, mod)
	}

	p3 := inverse(t, mod)

	contrib := mul(bc.get(t), p2, mod)
	contrib = mul(contrib, p3, mod)
	return contrib
}

func pow(a, b int) int {
	if b == 0 {
		return 1
	}
	if b&1 == 1 {
		return mul(a, pow(a, b-1), mod)
	}
	c := pow(a, b/2)
	return mul(c, c, mod)
}

func plus(a, b, mod int) int {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func mul(a, b, mod int) int {
	return int(int64(a) * int64(b) % int64(mod))
}

func valueOf(a, mod int) int {
	if a < 0 {
		a += mod
	}
	return a
}

func inverse(a, mod int) int {
	return pow(a, mod-2)
}

func composite(n, k, mod int) int {
	return mul(fact(n, mod), mul(invFact(k, mod), invFact(n-k, mod), mod), mod)
}

func fact(n, mod int) int {
	f := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = mul(f[i-1], i, mod)
	}
	return f[n]
}

func invFact(n, mod int) int {
	inv := make([]int, n+1)
	inv[0] = 1
	for i := 1; i <= n; i++ {
		inv[i] = mul(inv[i-1], inverse(i, mod), mod)
	}
	return inv[n]
}

type ID1 struct {
	n, k int
	mod  int
	fact []int
	inv  []int
}

func newID1(n, k, mod int) *ID1 {
	fact := make([]int, k+1)
	inv := make([]int, k+1)
	fact[0] = 1
	for i := 1; i <= k; i++ {
		fact[i] = mul(fact[i-1], i, mod)
	}
	inv[k] = inverse(fact[k], mod)
	for i := k - 1; i >= 0; i-- {
		inv[i] = mul(inv[i+1], i+1, mod)
	}
	return &ID1{n, k, mod, fact, inv}
}

func (id *ID1) get(t int) int {
	return mul(id.fact[id.n], mul(id.inv[t], id.inv[id.n-t], id.mod), id.mod)
}

func readThreeNums(reader io.Reader) (int, int, int) {
	var a, b, c int
	if _, err := fmt.Fscanf(reader, "%d %d %d\n", &a, &b, &c); err != nil {
		panic(err)
	}
	return a, b, c
}
