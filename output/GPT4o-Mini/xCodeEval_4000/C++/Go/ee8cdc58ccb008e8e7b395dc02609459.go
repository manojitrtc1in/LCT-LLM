package main

import (
	"fmt"
	"math"
)

const MOD = 1e9 + 7

type Ring struct {
	value int64
}

func floorMod(a, b int64) int64 {
	a %= b
	if a < 0 {
		a += b
	}
	return a
}

func NewRing(value int64) Ring {
	return Ring{floorMod(value, MOD)}
}

func (r Ring) Pow(p int64) Ring {
	res := NewRing(1)
	x := r
	for p > 0 {
		if p&1 == 1 {
			res *= x
		}
		x *= x
		p >>= 1
	}
	return res
}

func (r Ring) Inv() Ring {
	return r.Pow(MOD - 2)
}

func (r *Ring) Mul(b Ring) {
	r.value *= b.value
	r.value = floorMod(r.value, MOD)
}

func (r Ring) Mul(b Ring) Ring {
	res := r
	res.Mul(b)
	return res
}

func (r *Ring) Add(b Ring) {
	r.value += b.value
	r.value -= (r.value >= MOD) * MOD
}

func (r Ring) Add(b Ring) Ring {
	res := r
	res.Add(b)
	return res
}

func (r *Ring) Sub(b Ring) {
	r.value -= b.value
	r.value += (r.value < 0) * MOD
}

func (r Ring) Sub(b Ring) Ring {
	res := r
	res.Sub(b)
	return res
}

func (r *Ring) Div(b Ring) {
	*r *= b.Inv()
}

func (r Ring) Div(b Ring) Ring {
	res := r
	res.Div(b)
	return res
}

func (r Ring) Equals(b Ring) bool {
	return r.value == b.value
}

func (r Ring) NotEquals(b Ring) bool {
	return r.value != b.value
}

func (r Ring) String() string {
	return fmt.Sprintf("%d", r.value)
}

var fact []Ring

func binom(n, k int) Ring {
	if k > n {
		return NewRing(0)
	}
	return fact[n].Div(fact[n-k].Mul(fact[k]))
}

func main() {
	var n int
	fmt.Scan(&n)

	fact = make([]Ring, n+100)
	fact[0] = NewRing(1)
	for i := 1; i < n+100; i++ {
		fact[i] = fact[i-1].Mul(NewRing(int64(i)))
	}

	v := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}

	for i := 0; i < n; i++ {
		for j := 2; j*j <= v[i]; j++ {
			for v[i]%j == 0 && (v[i]/j)%j == 0 {
				v[i] /= j
				v[i] /= j
			}
		}
	}

	cnt := make(map[int]int)
	for _, x := range v {
		cnt[x]++
	}

	c := make([]int, 0, len(cnt))
	for _, pp := range cnt {
		c = append(c, pp)
	}

	dp := make([]Ring, n+10)
	dp[0] = NewRing(1)

	for _, x := range c {
		ndp := make([]Ring, n+10)
		for i := 0; i < len(dp); i++ {
			if dp[i].value != 0 {
				for j := 0; j < x; j++ {
					dist := x - j
					ndp[i+dist] = ndp[i+dist].Add(dp[i].Mul(binom(x-1, j)).Mul(binom(i+dist, dist)))
				}
			}
		}
		dp = ndp
	}

	conds := n - len(c)

	final := NewRing(0)
	sign := NewRing(1)
	for i := 0; i <= conds; i++ {
		final = final.Add(sign.Mul(dp[n-i]))
		sign = NewRing(-1).Mul(sign)
	}
	for _, x := range c {
		final = final.Mul(fact[x])
	}
	fmt.Println(final)
}
