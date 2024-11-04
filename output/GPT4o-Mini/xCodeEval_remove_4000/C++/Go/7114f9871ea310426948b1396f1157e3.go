package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type modnum int

const MOD = 1e9 + 7

func (n modnum) add(o modnum) modnum {
	return (n + o) % modnum(MOD)
}

func (n modnum) sub(o modnum) modnum {
	return (n - o + modnum(MOD)) % modnum(MOD)
}

func (n modnum) mul(o modnum) modnum {
	return (n * o) % modnum(MOD)
}

func (n modnum) pow(e int) modnum {
	if e == 0 {
		return 1
	}
	if e%2 == 1 {
		return n.mul(n.pow(e - 1))
	}
	return n.mul(n.pow(e / 2).mul(n.pow(e / 2)))
}

func nCr(n, r int) modnum {
	if r < 0 || n < r {
		return 0
	}
	return factorial(n).mul(inverseFactorial(r)).mul(inverseFactorial(n - r))
}

var fact []modnum

func factorial(n int) modnum {
	if len(fact) <= n {
		fact = append(fact, make([]modnum, n-len(fact)+1)...)
		fact[0] = 1
		for i := 1; i <= n; i++ {
			fact[i] = fact[i-1].mul(modnum(i))
		}
	}
	return fact[n]
}

func inverseFactorial(n int) modnum {
	return factorial(n).pow(MOD - 2)
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

func newSieve(maxV int) sieve {
	s := sieve{nums: make([]num, maxV)}
	s.nums[1] = num{leastPrime: int(1e9), divLeastPrime: 1, lpMultiplicity: 0, mu: 1, phi: 1}
	for v := 2; v < maxV; v++ {
		n := &s.nums[v]
		if n.leastPrime == 0 {
			*n = s.nums[1].prod(1, v)
			s.primes = append(s.primes, v)
		}
		for _, p := range s.primes {
			if p > n.leastPrime || v*p >= maxV {
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

func (s sieve) factor(v int) []pair {
	res := []pair{}
	for v > 1 {
		res = append(res, pair{s.nums[v].leastPrime, s.nums[v].lpMultiplicity})
		v = s.eliminateLeastPrime(v)
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i].first < res[j].first
	})
	return res
}

func (s sieve) eliminateLeastPrime(v int) int {
	for m := s.nums[v].lpMultiplicity; m > 0; m-- {
		v = s.nums[v].divLeastPrime
	}
	return v
}

type pair struct {
	first, second int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

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

	const MAXV = 1e6 + 1
	sv := newSieve(MAXV)

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g {
			coeff[m] = coeff[m].add(modnum(g).mul(modnum(sv.nums[c].mu)))
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
		ans = ans.add(coeff[g].mul(nCr(ct[g], K)))
	}

	intro := func(v int) {
		for _, d := range sv.factor(v) {
			ans = ans.add(coeff[d.first].mul(nCr(ct[d.first]+1, K).sub(nCr(ct[d.first], K))))
			ct[d.first]++
		}
	}

	for _, qv := range q {
		intro(qv)
		fmt.Fprintln(writer, ans)
	}
}