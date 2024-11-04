package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MAXV = 1000001

type modnum struct {
	v int
}

func newModnum(value int) modnum {
	return modnum{value: value % (int(1e9) + 7)}
}

func (n modnum) add(o modnum) modnum {
	return newModnum(n.v + o.v)
}

func (n modnum) subtract(o modnum) modnum {
	return newModnum(n.v - o.v)
}

func (n modnum) multiply(o modnum) modnum {
	return newModnum(n.v * o.v)
}

func (n modnum) pow(e int) modnum {
	if e < 0 {
		return modnum{1}.divide(n.pow(-e))
	}
	if e == 0 {
		return modnum{1}
	}
	if e&1 == 1 {
		return n.multiply(n.pow(e - 1))
	}
	return n.multiply(n).pow(e / 2)
}

func (n modnum) divide(o modnum) modnum {
	return n.multiply(o.inverse())
}

func (n modnum) inverse() modnum {
	g := int64(1e9) + 7
	x, y := int64(0), int64(1)
	a, b := int64(n.v), g
	for b != 0 {
		q := a / b
		a, b = b, a-q*b
		x, y = y, x-q*y
	}
	if x < 0 {
		x += g
	}
	return modnum{int(x)}
}

func (n modnum) factorial() modnum {
	fact := modnum{1}
	for i := 1; i <= n.v; i++ {
		fact = fact.multiply(modnum{i})
	}
	return fact
}

func (n modnum) inverseFactorial() modnum {
	finv := make([]modnum, n.v+1)
	finv[n.v] = n.factorial().inverse()
	for i := n.v - 1; i >= 0; i-- {
		finv[i] = finv[i+1].multiply(modnum{i + 1})
	}
	return finv
}

func (n modnum) smallInverse() modnum {
	return n.factorial().multiply(n.inverseFactorial())
}

func (n modnum) nCr(r int) modnum {
	if r < 0 || n.v < r {
		return modnum{0}
	}
	return n.factorial().multiply(n.inverseFactorial().multiply((modnum{n.v - r}).inverseFactorial()))
}

type sieve struct {
	primes []int
	nums   []struct {
		leastPrime       int
		divLeastPrime    int
		lpMultiplicity  int
		mu               int
		phi              int
	}
}

func newSieve() *sieve {
	s := &sieve{
		nums: make([]struct {
			leastPrime       int
			divLeastPrime    int
			lpMultiplicity  int
			mu               int
			phi              int
		}, MAXV),
	}
	s.nums[1] = struct {
		leastPrime       int
		divLeastPrime    int
		lpMultiplicity  int
		mu               int
		phi              int
	}{leastPrime: MAXV, mu: 1, phi: 1}
	for v := 2; v < MAXV; v++ {
		n := &s.nums[v]
		if n.leastPrime == 0 {
			n.leastPrime = v
			n.mu = -1
			s.primes = append(s.primes, v)
		}
		for _, p := range s.primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			n.divLeastPrime = v * p
			n.lpMultiplicity++
			s.nums[n.divLeastPrime].phi = n.phi * p
		}
	}
	return s
}

func (s *sieve) isPrime(v int) bool {
	return s.nums[v].leastPrime == v
}

func (s *sieve) eliminateLeastPrime(v int) int {
	for m := s.nums[v].lpMultiplicity; m > 0; m-- {
		v = s.nums[v].divLeastPrime
	}
	return v
}

func (s *sieve) factor(v int) []struct {
	prime int
	count int
} {
	res := make([]struct {
		prime int
		count int
	}, 0)
	for v > 1 {
		res = append(res, struct {
			prime int
			count int
		}{prime: s.nums[v].leastPrime, count: s.nums[v].lpMultiplicity})
		v = s.eliminateLeastPrime(v)
	}
	return res
}

func (s *sieve) id0(v int, f func(int), c int) {
	if v == 1 {
		f(c)
		return
	}
	w := s.eliminateLeastPrime(v)
	for m := 0; m <= s.nums[v].lpMultiplicity; m, c = m+1, c*s.nums[v].leastPrime {
		s.id0(w, f, c)
	}
}

func (s *sieve) unorderedDivisors(v int) []int {
	res := make([]int, 0)
	s.id0(v, func(d int) {
		res = append(res, d)
	}, 1)
	return res
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	sv := newSieve()

	var N, K, Q int
	fmt.Fscan(reader, &N, &K, &Q)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i])
	}
	q := make([]int, Q)
	for i := 0; i < Q; i++ {
		fmt.Fscan(reader, &q[i])
	}

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m, c = m+g, c+1 {
			coeff[m] = coeff[m].add(modnum(g).multiply(modnum(sv.nums[c].mu)))
		}
	}

	ans := modnum(0)
	ct := make([]int, MAXV)
	for _, e := range a {
		ct[e]++
	}
	for g := 1; g < MAXV; g++ {
		for m := 2 * g; m < MAXV; m += g {
			ct[g] += ct[m]
		}
		ans = ans.add(coeff[g].multiply(modnum(ct[g]).nCr(K)))
	}

	intro := func(v int) {
		sv.id0(v, func(d int) {
			ans = ans.add(coeff[d].multiply(modnum(ct[d]+1).nCr(K).subtract(modnum(ct[d]).nCr(K))))
			ct[d]++
		})
	}

	for _, qv := range q {
		intro(qv)
		fmt.Fprintln(writer, ans.v)
	}
}
