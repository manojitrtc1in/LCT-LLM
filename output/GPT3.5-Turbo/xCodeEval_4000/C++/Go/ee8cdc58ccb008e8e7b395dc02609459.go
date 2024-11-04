package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var stringInBuffer []byte

func fastScan(x *int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	*x, _ = strconv.Atoi(scanner.Text())
}

func fastPrint(x interface{}) {
	fmt.Print(x)
}

const MOD = 1e9 + 7

type Ring struct {
	value int
}

func NewRing(value int) *Ring {
	r := new(Ring)
	r.value = value
	r.value = floorMod(r.value, MOD)
	return r
}

func (r *Ring) Pow(p int) *Ring {
	res := NewRing(1)
	x := NewRing(r.value)
	for p > 0 {
		if p&1 == 1 {
			res.Multiply(x)
		}
		x.Multiply(x)
		p /= 2
	}
	return res
}

func (r *Ring) Inverse() *Ring {
	return r.Pow(MOD - 2)
}

func (r *Ring) Multiply(b *Ring) {
	r.value *= b.value
	r.value = floorMod(r.value, MOD)
}

func (r *Ring) Add(b *Ring) {
	r.value += b.value
	r.value -= (r.value >= MOD) * MOD
}

func (r *Ring) Subtract(b *Ring) {
	r.value -= b.value
	r.value += (r.value < 0) * MOD
}

func (r *Ring) Divide(b *Ring) {
	r.Multiply(b.Inverse())
}

func floorMod(a, b int) int {
	a %= b
	if a < 0 {
		a += b
	}
	return a
}

func binom(n, k int) *Ring {
	if k > n {
		return NewRing(0)
	}
	fact := make([]*Ring, n+1)
	fact[0] = NewRing(1)
	for i := 1; i <= n; i++ {
		fact[i] = NewRing(i + 1)
		fact[i].Multiply(fact[i-1])
	}
	return fact[n].Divide(fact[n-k]).Divide(fact[k])
}

func main() {
	var n int
	fastScan(&n)

	fact := make([]*Ring, n+101)
	fact[0] = NewRing(1)
	for i := 1; i <= n+100; i++ {
		fact[i] = NewRing(i + 1)
		fact[i].Multiply(fact[i-1])
	}

	v := make([]int, n)
	for i := 0; i < n; i++ {
		fastScan(&v[i])
		for j := 2; j*j <= v[i]; j++ {
			for v[i]%j == 0 && v[i]/j%j == 0 {
				v[i] /= j
				v[i] /= j
			}
		}
	}

	cnt := make(map[int]int)
	for _, x := range v {
		cnt[x]++
	}

	c := make([]int, 0)
	for _, val := range cnt {
		c = append(c, val)
	}

	dp := make([]*Ring, n+10)
	dp[0] = NewRing(1)
	for _, x := range c {
		ndp := make([]*Ring, n+10)
		for i := 0; i < len(dp); i++ {
			if dp[i] != nil {
				for j := 0; j < x; j++ {
					dist := x - j
					ndp[i+dist] = NewRing(0)
					ndp[i+dist].Add(dp[i].Multiply(binom(x-1, j)).Multiply(binom(i+dist, dist)))
				}
			}
		}
		dp = ndp
	}

	conds := n - len(c)

	final := NewRing(0)
	sign := NewRing(1)
	for i := 0; i <= conds; i++ {
		final.Add(sign.Multiply(dp[n-i]))
		sign.Multiply(NewRing(-1))
	}
	for _, x := range c {
		final.Multiply(fact[x])
	}

	fastPrint(final)
}
