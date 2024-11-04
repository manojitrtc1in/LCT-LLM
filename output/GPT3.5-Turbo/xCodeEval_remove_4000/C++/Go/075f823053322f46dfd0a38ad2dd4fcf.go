package main

import (
	"fmt"
	"math"
)

const (
	maxn = int(1.5 * 1e7)
	inf  = 1e9 + 7
	llInf = 1e18 + 420
	eps  = 1e-4
	N    = 1e6 + 7
	MAX  = 2e5 + 9
	MOD  = 1e9 + 7
	pi   = 3.14159265359
)

type pll struct {
	first, second int64
}

type vll []int64
type vvll [][]int64
type vi []int
type vvi [][]int
type vpii []pii
type ppiipii struct {
	first, second pii
}

type ld float64
type mii map[int]int
type mll map[int64]int64
type si map[int]bool
type sll map[int64]bool
type sull map[uint64]bool
type ss map[string]bool
type spii map[pii]bool
type spll map[pll]bool
type msi map[int]int
type mpiii map[pii]int
type mipii map[int]pii
type vpipii []pair

type orderedSet struct {
}

func bpow(a, b int, mod int) int64 {
	res := int64(a)
	ret := int64(1)
	for b > 0 {
		if b%2 == 1 {
			ret = (ret * res) % int64(mod)
		}
		res = (res * res) % int64(mod)
		b /= 2
	}
	return ret % int64(mod)
}

func Random() {
	var seed uint32
	asm("rdtsc" : "=A" (seed))
	rand.Seed(seed)
}

func fact(n int64, mod int) int64 {
	fuc := int64(1)
	for i := int64(2); i <= n; i++ {
		fuc = (fuc * i) % int64(mod)
	}
	return fuc
}

func Cnk(n, r int64, mod int) int64 {
	r = min(r, n-r)
	ans := int64(1)
	for i := n; i >= (n - r + 1); i-- {
		ans = (ans * i) % int64(mod)
	}
	for i := int64(1); i <= r; i++ {
		ans = (ans * bpow(int(i), mod-2, mod)) % int64(mod)
	}
	return ans
}

func main() {
	Random()

	var b, d int
	fmt.Scan(&b, &d)
	var a, c string
	fmt.Scan(&a, &c)
	s := 0
	n := len(c)
	t := make([]int, 128)
	for i := 0; i < len(c); i++ {
		k := &t[i]
		for j := 0; j < len(a); j++ {
			if a[j] == c[(i+*k)%n] {
				*k++
			}
		}
	}
	for i := 0; i < b; i++ {
		s += t[s%n]
	}
	fmt.Println(s / n / d)
}
