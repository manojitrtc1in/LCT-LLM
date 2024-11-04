package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type modnum int

func (n modnum) pow(e int) modnum {
	if e < 0 {
		return 1 / n.pow(-e)
	}
	if e == 0 {
		return 1
	}
	if e&1 == 1 {
		return n * n.pow(e-1)
	}
	return n * n.pow(e/2)
}

func (n modnum) inv() modnum {
	g := modnum(1e9 + 7)
	x, y := modnum(0), modnum(1)
	r := n
	for r != 0 {
		q := g / r
		g, r = r, g-q*r
		x, y = y-q*x, x
	}
	if g != 1 {
		panic("modular inverse does not exist")
	}
	if y < 0 {
		y += g
	}
	return y
}

func (n modnum) factorial() modnum {
	fact := modnum(1)
	for i := modnum(2); i <= n; i++ {
		fact *= i
	}
	return fact
}

func (n modnum) inverseFactorial() modnum {
	finv := make([]modnum, n+1)
	finv[n] = n.factorial().inv()
	for i := n - 1; i >= 0; i-- {
		finv[i] = finv[i+1] * (i + 1)
	}
	return finv
}

func (n modnum) ncr(r modnum) modnum {
	if r < 0 || n < r {
		return 0
	}
	return n.factorial() * r.inverseFactorial() * (n - r).inverseFactorial()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	readString := func() string {
		scanner.Scan()
		return scanner.Text()
	}

	readInt := func() int {
		i, _ := strconv.Atoi(readString())
		return i
	}

	readInt64 := func() int64 {
		i, _ := strconv.ParseInt(readString(), 10, 64)
		return i
	}

	readFloat := func() float64 {
		f, _ := strconv.ParseFloat(readString(), 64)
		return f
	}

	readStringSlice := func(n int) []string {
		s := make([]string, n)
		for i := 0; i < n; i++ {
			s[i] = readString()
		}
		return s
	}

	readIntSlice := func(n int) []int {
		s := make([]int, n)
		for i := 0; i < n; i++ {
			s[i] = readInt()
		}
		return s
	}

	readInt64Slice := func(n int) []int64 {
		s := make([]int64, n)
		for i := 0; i < n; i++ {
			s[i] = readInt64()
		}
		return s
	}

	readFloatSlice := func(n int) []float64 {
		s := make([]float64, n)
		for i := 0; i < n; i++ {
			s[i] = readFloat()
		}
		return s
	}

	N, K, Q := readInt(), readInt(), readInt()
	a := readIntSlice(N)
	q := readIntSlice(Q)

	const MAXV = 1e6 + 1
	sv := make([]struct {
		leastPrime      int
		divLeastPrime   int
		lpMultiplicity int
		mu              int
		phi             int
	}, MAXV)

	primes := []int{}
	nums := make([]struct {
		leastPrime      int
		divLeastPrime   int
		lpMultiplicity int
		mu              int
		phi             int
	}, MAXV)

	nums[1] = struct {
		leastPrime      int
		divLeastPrime   int
		lpMultiplicity int
		mu              int
		phi             int
	}{INT_MAX, 1, 0, 1, 1}

	for v := 2; v < MAXV; v++ {
		n := &nums[v]
		if n.leastPrime == 0 {
			n.leastPrime = v
			n.divLeastPrime = v
			n.lpMultiplicity = 1
			n.mu = -nums[1].mu
			n.phi = nums[1].phi * (v - 1)
			primes = append(primes, v)
		}
		for _, p := range primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			n := &nums[v*p]
			n.leastPrime = v
			n.divLeastPrime = v
			n.lpMultiplicity = n.lpMultiplicity + 1
			n.mu = 0
			n.phi = n.phi * p
		}
	}

	isPrime := func(v int) bool {
		return nums[v].leastPrime == v
	}

	eliminateLeastPrime := func(v int) int {
		for m := nums[v].lpMultiplicity; m > 0; m-- {
			v = nums[v].divLeastPrime
		}
		return v
	}

	factor := func(v int) []struct {
		prime int
		exp   int
	} {
		res := []struct {
			prime int
			exp   int
		}{}
		for v > 1 {
			res = append(res, struct {
				prime int
				exp   int
			}{nums[v].leastPrime, nums[v].lpMultiplicity})
			v = eliminateLeastPrime(v)
		}
		return res
	}

	id0 := func(v int, f func(int), c int) {
		if v == 1 {
			f(c)
			return
		}
		w := eliminateLeastPrime(v)
		for m := 0; m <= nums[v].lpMultiplicity; m, c = m+1, c*nums[v].leastPrime {
			id0(w, f, c)
		}
	}

	unorderedDivisors := func(v int) []int {
		res := []int{}
		id0(v, func(d int) {
			res = append(res, d)
		}, 1)
		return res
	}

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m, c = m+g, c+1 {
			coeff[m] += modnum(g) * modnum(nums[c].mu)
		}
	}

	ans := modnum(0)
	ct := make([]int, MAXV)

	intro := func(v int) {
		factors := factor(v)
		for _, f := range factors {
			d := f.prime
			ans += coeff[d] * (modnum(ct[d]+1).pow(K) - modnum(ct[d]).pow(K))
			ct[d]++
		}
	}

	for _, v := range a {
		intro(v)
	}

	for _, qv := range q {
		intro(qv)
		fmt.Println(ans)
	}
}
