package main

import (
	"fmt"
	"math"
)

const mod = 998244353

var fact []int64
var revFact []int64

func preFact(n int) {
	fact = make([]int64, n+1)
	revFact = make([]int64, n+1)
	fact[0] = 1
	for i := 0; i < n; i++ {
		fact[i+1] = mul(int64(i+1), fact[i])
	}
	revFact[n] = div(1, fact[n])
	for i := n - 1; i >= 0; i-- {
		revFact[i] = mul(revFact[i+1], int64(i+1))
	}
}

func cmb(a, b int) int64 {
	if a < b {
		return 0
	}
	if len(fact) == 0 {
		fmt.Println("error : factorials has not been calculated!! do [pre_factorial] method")
		return 0
	}
	af := fact[a]
	bf := revFact[b]
	abf := revFact[a-b]
	return mul(mul(af, bf), abf)
}

func pow(x, y int64) int64 {
	if y < 0 {
		return 0
	}
	if y == 0 {
		return 1
	}
	if y%2 == 1 {
		return mul(x, pow(x, y-1))
	}
	root := pow(x, y/2)
	return mul(root, root)
}

func mul(x, y int64) int64 {
	res := (x * y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func div(x, y int64) int64 {
	res := x * pow(y, mod-2) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func solve() {
	var n int
	var tmp int64
	fmt.Scan(&n, &tmp)

	if n <= tmp {
		fmt.Println(0)
		return
	}
	k := int(tmp)
	preFact(400000)
	ans := int64(0)
	si := int64(1)
	t := cmb(n, n-k)

	for i := n - k; i >= 1; i-- {
		ans += si * cmb(n-k, i) * pow(int64(i), int64(n))
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		si *= -1
	}
	ans *= t
	ans %= mod
	if k != 0 {
		ans *= 2
		ans %= mod
	}
	if ans < 0 {
		ans += mod
	}
	fmt.Println(ans)
}

func main() {
	solve()
}
