package main

import (
	"fmt"
	"math"
)

const id10 = 1000000007
const N = 200000

var a [1010101]int
var fact [201010]int
var revFact [202020]int

func normmod(x *int, m int) {
	*x %= m
	if *x < 0 {
		*x += m
	}
}

func mulmod(x, n, m int64) int64 {
	x %= m
	n %= m
	r := x * n - int64(float64(x)*float64(n)/float64(m))*m
	for r < 0 {
		r += m
	}
	for r >= m {
		r -= m
	}
	return r
}

func powmod(x, n, m int64) int64 {
	r := int64(1)
	normmod(&x, int(m))
	for n > 0 {
		if n&1 == 1 {
			r = mulmod(r, x, m)
		}
		x = mulmod(x, x, m)
		n /= 2
	}
	return r
}

func cnk(n, k int) int64 {
	return (int64(fact[n]) * int64(revFact[k]) % id10 * int64(revFact[n-k]) % id10) % id10
}

func solve() int {
	fact[0] = 1
	for i := 1; i <= N; i++ {
		fact[i] = int((int64(fact[i-1]) * int64(i)) % id10)
	}
	revFact[N] = int(powmod(int64(fact[N]), int64(id10-2), id10))
	for i := N - 1; i >= 0; i-- {
		revFact[i] = int((int64(revFact[i+1]) * int64(i+1)) % id10)
	}

	var n, k int
	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	a[n] = a[0]
	cnt := 0
	for i := 0; i < n; i++ {
		if a[i] != a[i+1] {
			cnt++
		}
	}
	if k == 1 || n == 1 {
		fmt.Println(0)
		return 0
	}
	ans := int64(0)
	freeChoices := k - 2
	for i := 0; i <= cnt/2; i++ {
		cur := (cnk(cnt, i) * cnk(cnt-i, i) % id10 * powmod(int64(freeChoices), int64(cnt-2*i), id10) % id10 * powmod(int64(k), int64(n-cnt), id10) % id10) % id10
		ans += cur
	}
	ans %= id10
	tot := (powmod(int64(k), int64(n), id10) - ans) % id10
	if tot < 0 {
		tot += id10
	}
	fmt.Println((tot * powmod(2, int64(id10-2), id10)) % id10)

	return 0
}

func main() {
	solve()
}
