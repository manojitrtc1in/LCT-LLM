package main

import (
	"fmt"
	"math"
)

func modMul(x, y, n int64) int64 {
	d := int64(float64(x*y) / float64(n))
	d = x*y - n*d
	for d < 0 {
		d += n
	}
	for d >= n {
		d -= n
	}
	return d
}

func powMod(x, t, base int64) int64 {
	res := int64(1)
	for t > 0 {
		if t&1 == 1 {
			res = modMul(res, x, base)
		}
		x = modMul(x, x, base)
		t >>= 1
	}
	return res
}

func strongPseudoPrimeTest(n, base int64) bool {
	n2 := n - 1
	s := 0
	for n2&1 == 0 {
		n2 >>= 1
		s++
	}
	res := powMod(base, n2, n)
	if res == 1 || res == n-1 {
		return true
	}
	s--
	for s >= 0 {
		res = modMul(res, res, n)
		if res == n-1 {
			return true
		}
		s--
	}
	return false
}

func isPrime(n int64) bool {
	if n < 2 {
		return false
	}
	if n < 4 {
		return true
	}
	if strongPseudoPrimeTest(n, 2) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 3) == false {
		return false
	}
	if n < 1373653 {
		return true
	}
	if strongPseudoPrimeTest(n, 5) == false {
		return false
	}
	if n < 25326001 {
		return true
	}
	if strongPseudoPrimeTest(n, 7) == false {
		return false
	}
	if n == 3215031751 {
		return false
	}
	if n < 25000000000 {
		return true
	}
	if strongPseudoPrimeTest(n, 11) == false {
		return false
	}
	if n < 2152302898747 {
		return true
	}
	if strongPseudoPrimeTest(n, 13) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 17) == false {
		return false
	}
	if n < 341550071728321 {
		return true
	}
	if strongPseudoPrimeTest(n, 19) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 23) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 29) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 31) == false {
		return false
	}
	if strongPseudoPrimeTest(n, 37) == false {
		return false
	}
	return true
}

func solve(l, r int) int {
	if l > r {
		return 0
	}
	sum := 0
	for i := l; i <= r; i++ {
		if i%2 == 0 || i%3 == 0 || i%7 == 0 || !isPrime(int64(i)) {
			continue
		}
		if i%4 == 1 {
			sum++
		}
	}
	return sum
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	l--
	L := l / 100000
	R := r / 100000
	sum1 := 0
	for i := 0; i <= L; i++ {
		sum1 += ans[i]
	}
	sum1 += solve(L*100000+1, l)
	if l >= 2 && l < 100000 {
		sum1++
	}
	sum2 := 0
	for i := 0; i <= R; i++ {
		sum2 += ans[i]
	}
	sum2 += solve(R*100000+1, r)
	if r >= 2 && r < 100000 {
		sum2++
	}
	fmt.Println(sum2 - sum1)
}
