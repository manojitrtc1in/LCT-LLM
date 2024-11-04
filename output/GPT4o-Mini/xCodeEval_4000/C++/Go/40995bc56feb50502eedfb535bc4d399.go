package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const MAXV = 1e6 + 1
const MOD = 1e9 + 7

type modnum struct {
	v int
}

func newModnum(_v int) modnum {
	v := _v % MOD
	if v < 0 {
		v += MOD
	}
	return modnum{v}
}

func (n modnum) add(o modnum) modnum {
	n.v += o.v
	if n.v >= MOD {
		n.v -= MOD
	}
	return n
}

func (n modnum) sub(o modnum) modnum {
	n.v -= o.v
	if n.v < 0 {
		n.v += MOD
	}
	return n
}

func (n modnum) mul(o modnum) modnum {
	n.v = (n.v * o.v) % MOD
	return n
}

func (n modnum) pow(e int) modnum {
	if e == 0 {
		return newModnum(1)
	}
	if e%2 == 1 {
		return n.mul(n.pow(e - 1))
	}
	return n.mul(n).pow(e / 2)
}

func (n modnum) inv() modnum {
	return n.pow(MOD - 2)
}

func (n modnum) div(o modnum) modnum {
	return n.mul(o.inv())
}

type sieve struct {
	primes []int
	nums   []num
}

type num struct {
	leastPrime      int
	divLeastPrime   int
	lpMultiplicity  int
	mu              int
	phi             int
}

func newSieve() sieve {
	s := sieve{nums: make([]num, MAXV)}
	s.nums[1] = num{leastPrime: math.MaxInt32, divLeastPrime: 1, lpMultiplicity: 0, mu: 1, phi: 1}
	for v := 2; v < MAXV; v++ {
		n := &s.nums[v]
		if n.leastPrime == 0 {
			*n = s.nums[1].prod(1, v)
			s.primes = append(s.primes, v)
		}
		for _, p := range s.primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			s.nums[v*p] = n.prod(v, p)
		}
	}
	return s
}

func (n num) prod(myValue, p int) num {
	if p < n.leastPrime {
		return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: 1, mu: -n.mu, phi: n.phi * (p - 1)}
	}
	return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: n.lpMultiplicity + 1, mu: 0, phi: n.phi * p}
}

func (s sieve) factor(v int) []int {
	res := []int{}
	for v > 1 {
		res = append(res, s.nums[v].leastPrime)
		v = s.eliminateLeastPrime(v)
	}
	return res
}

func (s sieve) eliminateLeastPrime(v int) int {
	for m := s.nums[v].lpMultiplicity; m > 0; m-- {
		v = s.nums[v].divLeastPrime
	}
	return v
}

func (s sieve) unorderedDivisors(v int) []int {
	res := []int{}
	s.forEachDivisorUnordered(v, func(d int) {
		res = append(res, d)
	})
	return res
}

func (s sieve) forEachDivisorUnordered(v int, f func(int)) {
	if v == 1 {
		f(1)
		return
	}
	w := s.eliminateLeastPrime(v)
	for m := 0; m <= s.nums[v].lpMultiplicity; m++ {
		c := int(math.Pow(float64(s.nums[v].leastPrime), float64(m)))
		f(c)
		s.forEachDivisorUnordered(w, f)
	}
}

func nCr(n, r int) modnum {
	if r < 0 || n < r {
		return newModnum(0)
	}
	return factorial(n).mul(inverseFactorial(r)).mul(inverseFactorial(n - r))
}

var fact []modnum
var finv []modnum

func factorial(n int) modnum {
	if len(fact) <= n {
		had := len(fact)
		fact = append(fact, make([]modnum, n-had+1)...)
		for i := had; i <= n; i++ {
			fact[i] = fact[i-1].mul(newModnum(i))
		}
	}
	return fact[n]
}

func inverseFactorial(n int) modnum {
	if len(finv) <= n {
		had := len(finv)
		finv = append(finv, make([]modnum, n-had+1)...)
		finv[n] = factorial(n).inv()
		for i := n - 1; i >= had; i-- {
			finv[i] = finv[i+1].mul(newModnum(i + 1))
		}
	}
	return finv[n]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	sv := newSieve()

	var N, K, Q int
	fmt.Fscan(reader, &N, &K, &Q)
	a := make([]int, N)
	q := make([]int, Q)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i])
	}
	for i := 0; i < Q; i++ {
		fmt.Fscan(reader, &q[i])
	}

	ans := newModnum(0)
	ct := make([]int, MAXV)
	coeff := make([]modnum, MAXV)

	for _, e := range a {
		ct[e]++
	}
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g {
			coeff[m] = coeff[m].add(newModnum(g).mul(newModnum(sv.nums[c].mu)))
			if c > 1 {
				ct[g] += ct[m]
			}
		}
		ans = ans.add(coeff[g].mul(nCr(ct[g], K)))
	}

	for _, qv := range q {
		sv.forEachDivisorUnordered(qv, func(d int) {
			ans = ans.add(coeff[d].mul(nCr(ct[d]+1, K).sub(nCr(ct[d], K))))
			ct[d]++
		})
		fmt.Fprintln(writer, ans.v)
	}
}
