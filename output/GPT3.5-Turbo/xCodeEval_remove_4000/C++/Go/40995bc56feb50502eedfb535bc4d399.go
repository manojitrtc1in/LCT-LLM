package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type modnum int

const MOD = int(1e9 + 7)

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
	g := MOD
	x := 0
	y := 1
	r := int(n)
	for r != 0 {
		q := g / r
		g, r = r, g-q*r
		x, y = y-q*x, x
	}
	if g == 1 {
		if y < 0 {
			y += MOD
		}
		return modnum(y)
	}
	return 0
}

func (n modnum) factorial() modnum {
	fact := modnum(1)
	for i := 2; i <= int(n); i++ {
		fact *= modnum(i)
	}
	return fact
}

func (n modnum) inverseFactorial() modnum {
	finv := make([]modnum, int(n)+1)
	finv[int(n)] = n.factorial().inv()
	for i := int(n) - 1; i >= 0; i-- {
		finv[i] = finv[i+1] * modnum(i+1)
	}
	return finv
}

func (n modnum) smallInv() modnum {
	return n.factorial() * n.inverseFactorial()
}

func (n modnum) ncr(r int) modnum {
	if r < 0 || int(n) < r {
		return 0
	}
	return n.factorial() * n.inverseFactorial() * (n - modnum(r)).inverseFactorial()
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

	N := readInt()
	K := readInt()
	Q := readInt()

	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = readInt()
	}

	q := make([]int, Q)
	for i := 0; i < Q; i++ {
		q[i] = readInt()
	}

	ans := modnum(0)
	ct := make([]int, 1000001)
	coeff := make([]modnum, 1000001)

	for _, e := range a {
		ct[e]++
	}

	for g := 1; g < 1000001; g++ {
		for m, c := g, 1; m < 1000001; m += g {
			coeff[m] += modnum(g) * modnum(c)
			if c > 1 {
				ct[g] += ct[m]
			}
			c++
		}
		ans += coeff[g] * modnum(ct[g]).ncr(K)
	}

	for _, qv := range q {
		for d := qv; d > 1; {
			ans += coeff[d] * (modnum(ct[d]+1).ncr(K) - modnum(ct[d]).ncr(K))
			ct[d]++
			d = eliminateLeastPrime(d)
		}
		fmt.Println(ans)
	}
}

func eliminateLeastPrime(v int) int {
	for m := sv[v].lpMultiplicity; m > 0; m-- {
		v = sv[v].divLeastPrime
	}
	return v
}

type num struct {
	leastPrime      int
	divLeastPrime   int
	lpMultiplicity int
	mu              int
	phi             int
}

type sieve struct {
	primes []int
	nums   []num
}

var sv sieve

func init() {
	sv.nums = make([]num, 1000001)
	sv.nums[1] = num{INT_MAX, 1, 0, 1, 1}
	for v := 2; v < 1000001; v++ {
		n := &sv.nums[v]
		if n.leastPrime == 0 {
			n.leastPrime = v
			n.divLeastPrime = v
			n.lpMultiplicity = 1
			n.mu = -sv.nums[1].mu
			n.phi = (v - 1) * sv.nums[1].phi
			sv.primes = append(sv.primes, v)
		}
		for _, p := range sv.primes {
			if p > n.leastPrime || v*p >= 1000001 {
				break
			}
			sv.nums[v*p] = num{p, v, n.lpMultiplicity + 1, 0, n.phi * p}
		}
	}
}

func (s sieve) isPrime(v int) bool {
	return s.nums[v].leastPrime == v
}

func (s sieve) factor(v int) []int {
	res := make([]int, 0)
	for v > 1 {
		res = append(res, s.nums[v].leastPrime)
		v = eliminateLeastPrime(v)
	}
	return res
}

func (s sieve) id0(v int, f func(int), c int) {
	if v == 1 {
		f(c)
		return
	}
	w := eliminateLeastPrime(v)
	for m := 0; m <= s.nums[v].lpMultiplicity; m, c = m+1, c*s.nums[v].leastPrime {
		s.id0(w, f, c)
	}
}

func (s sieve) unorderedDivisors(v int) []int {
	res := make([]int, 0)
	s.id0(v, func(d int) {
		res = append(res, d)
	}, 1)
	return res
}
