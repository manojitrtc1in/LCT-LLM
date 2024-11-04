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
	pm := NewCachedPow(m, mod)
	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = pm.Pow(i, k)
	}

	ans := 0
	bc := NewBinomialComposite(n, k, mod)
	for t := 0; t <= k; t++ {
		p1 := bc.Get(t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := bc.Composite(t, i)
			contrib = modMul(contrib, xk[t-i])
			if i%2 == 1 {
				contrib = modMinus(0, contrib)
			}
			p2 = modPlus(p2, contrib)
		}
		p3 := pm.Inverse(t)

		contrib := modMul(p1, p2)
		contrib = modMul(contrib, p3)
		ans = modPlus(ans, contrib)
	}

	return ans
}

func modPlus(a, b int) int {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func modMinus(a, b int) int {
	c := a - b
	if c < 0 {
		c += mod
	}
	return c
}

func modMul(a, b int) int {
	return int(int64(a) * int64(b) % int64(mod))
}

type CachedPow struct {
	first  []int
	second []int
	mod    int
	powMod int
}

func NewCachedPow(x, mod int) *CachedPow {
	return NewCachedPowWithMaxExp(x, mod, mod)
}

func NewCachedPowWithMaxExp(x, maxExp, mod int) *CachedPow {
	powMod := mod - 1
	k := max(1, int(sqrt(float64(maxExp))))
	first := make([]int, k)
	second := make([]int, maxExp/k+1)
	first[0] = 1
	for i := 1; i < k; i++ {
		first[i] = modMul(x, first[i-1])
	}
	second[0] = 1
	step := modMul(x, first[k-1])
	for i := 1; i < len(second); i++ {
		second[i] = modMul(second[i-1], step)
	}
	return &CachedPow{first, second, mod, powMod}
}

func (cp *CachedPow) Pow(exp int) int {
	return modMul(cp.first[exp%len(cp.first)], cp.second[exp/len(cp.first)])
}

func (cp *CachedPow) Inverse(exp int) int {
	return cp.Pow(cp.powMod - exp)
}

type BinomialComposite struct {
	m    int
	mod  int
	fact []int
	inv  []int
}

func NewBinomialComposite(n, m, mod int) *BinomialComposite {
	fact := make([]int, m+1)
	inv := make([]int, m+1)
	fact[0] = 1
	for i := 1; i <= m; i++ {
		fact[i] = modMul(fact[i-1], i)
	}
	inv[m] = modInverse(fact[m], mod)
	for i := m - 1; i >= 0; i-- {
		inv[i] = modMul(inv[i+1], i+1)
	}
	return &BinomialComposite{n, mod, fact, inv}
}

func (bc *BinomialComposite) Get(i int) int {
	return bc.fact[i]
}

func (bc *BinomialComposite) Composite(m, n int) int {
	if n > m {
		return 0
	}
	return modMul(modMul(bc.fact[m], bc.inv[n]), bc.inv[m-n])
}

func modInverse(a, mod int) int {
	b := mod
	u, v := 1, 0
	for b > 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	if u < 0 {
		u += mod
	}
	return u
}

func readThreeNums(reader *bufio.Reader) (int, int, int) {
	a, b, c := 0, 0, 0
	s, _ := reader.ReadString('\n')
	pos := 0
	for i := 0; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			pos = i
			break
		}
	}
	for i := pos; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			pos = i
			break
		}
		a = a*10 + int(s[i]-'0')
	}
	for i := pos; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			pos = i
			break
		}
	}
	for i := pos; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			pos = i
			break
		}
		b = b*10 + int(s[i]-'0')
	}
	for i := pos; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			pos = i
			break
		}
	}
	for i := pos; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			pos = i
			break
		}
		c = c*10 + int(s[i]-'0')
	}
	return a, b, c
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func sqrt(x float64) float64 {
	return float64(int64(x))
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = modMul(r, r)
	if n&1 == 1 {
		r = modMul(r, x)
	}
	return r
}
