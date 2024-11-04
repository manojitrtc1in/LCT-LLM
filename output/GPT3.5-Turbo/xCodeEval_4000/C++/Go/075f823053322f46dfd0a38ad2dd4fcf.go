package main

import (
	"fmt"
	"math/rand"
)

func Random() {
	seed := rand.Uint32()
	rand.Seed(seed)
}

func bpow(a, b, mod int) int {
	res := a
	ret := 1
	for b > 0 {
		if b%2 == 1 {
			ret = (ret * res) % mod
		}
		res = (res * res) % mod
		b /= 2
	}
	return ret % mod
}

func fact(n, mod int) int {
	fuc := 1
	for i := 2; i <= n; i++ {
		fuc = (fuc * i) % mod
	}
	return fuc
}

func Cnk(n, r, mod int) int {
	r = min(r, n-r)
	ans := 1
	for i := n; i >= (n - r + 1); i-- {
		ans = (ans * i) % mod
	}
	for i := 1; i <= r; i++ {
		ans = (ans * bpow(i, mod-2)) % mod
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
