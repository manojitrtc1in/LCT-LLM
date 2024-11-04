package main

import (
	"fmt"
	"math/big"
)

const MAXMEM = 200 * 1000 * 1024
var _memory [MAXMEM]byte
var _ptr int

func new(size int) *byte {
	_ptr += size
	if _ptr >= MAXMEM {
		panic("Memory limit exceeded")
	}
	return &_memory[_ptr-size]
}

func delete(ptr *byte) {}

func fastScanInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func fastScanInt64() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func fastScanUint64() uint64 {
	var x uint64
	fmt.Scan(&x)
	return x
}

func fastScanFloat64() float64 {
	var x float64
	fmt.Scan(&x)
	return x
}

func fastScanString() string {
	var x string
	fmt.Scan(&x)
	return x
}

func fastPrint(x interface{}) {
	fmt.Print(x)
}

type Ring struct {
	value *big.Int
}

func NewRing(value int64) Ring {
	r := Ring{value: big.NewInt(value)}
	return r
}

func (r *Ring) Pow(p int64) Ring {
	result := NewRing(1)
	x := *r
	for p > 0 {
		if p&1 == 1 {
			result *= x
		}
		x *= x
		p >>= 1
	}
	return result
}

func (r *Ring) Inv() Ring {
	return r.Pow(MOD - 2)
}

func (r *Ring) Mul(b Ring) Ring {
	r.value.Mul(r.value, b.value)
	r.value.Mod(r.value, big.NewInt(MOD))
	return *r
}

func (r *Ring) Add(b Ring) Ring {
	r.value.Add(r.value, b.value)
	r.value.Mod(r.value, big.NewInt(MOD))
	return *r
}

func (r *Ring) Sub(b Ring) Ring {
	r.value.Sub(r.value, b.value)
	r.value.Mod(r.value, big.NewInt(MOD))
	return *r
}

func (r *Ring) Div(b Ring) Ring {
	return r.Mul(b.Inv())
}

func (r *Ring) Equal(b Ring) bool {
	return r.value.Cmp(b.value) == 0
}

func (r *Ring) NotEqual(b Ring) bool {
	return r.value.Cmp(b.value) != 0
}

func (r Ring) String() string {
	return r.value.String()
}

const MOD = 1e9 + 7

var fact []Ring

func binom(n, k int) Ring {
	if k > n {
		return NewRing(0)
	}
	return fact[n].Div(fact[n-k].Mul(fact[k]))
}

func main() {
	n := fastScanInt()
	fact = append(fact, NewRing(1))
	for i := 0; i < n+100; i++ {
		fact = append(fact, fact[len(fact)-1].Mul(NewRing(int64(i + 1))))
	}
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = fastScanInt()
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

	c := make([]int, 0)
	for _, pp := range cnt {
		c = append(c, pp)
	}

	dp := make([]Ring, n+10)
	dp[0] = NewRing(1)
	for _, x := range c {
		ndp := make([]Ring, n+10)
		for i := 0; i < len(dp); i++ {
			if dp[i].value.Cmp(big.NewInt(0)) != 0 {
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
	fastPrint(final.String())
}
