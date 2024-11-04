package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
	"sort"
)

const MAXV = int(1e6 + 1)

type modnum struct {
	v int
}

func newModnum(_v int) modnum {
	v := _v % (1e9 + 7)
	if v < 0 {
		v += int(1e9 + 7)
	}
	return modnum{v}
}

func (n modnum) add(o modnum) modnum {
	n.v += o.v
	if n.v >= int(1e9+7) {
		n.v -= int(1e9 + 7)
	}
	return n
}

func (n modnum) sub(o modnum) modnum {
	n.v -= o.v
	if n.v < 0 {
		n.v += int(1e9 + 7)
	}
	return n
}

func (n modnum) mul(o modnum) modnum {
	n.v = (n.v * o.v) % int(1e9 + 7)
	return n
}

func (n modnum) pow(e int) modnum {
	if e == 0 {
		return newModnum(1)
	}
	if e%2 == 1 {
		return n.mul(n.pow(e - 1))
	}
	x := n.mul(n)
	return x.pow(e / 2)
}

type sieve struct {
	primes []int
	nums   []num
}

type num struct {
	leastPrime       int
	divLeastPrime    int
	lpMultiplicity   int
	mu               int
	phi              int
}

func newSieve() sieve {
	nums := make([]num, MAXV)
	nums[1] = num{leastPrime: math.MaxInt32, divLeastPrime: 1, lpMultiplicity: 0, mu: 1, phi: 1}
	primes := []int{}

	for v := 2; v < MAXV; v++ {
		n := &nums[v]
		if n.leastPrime == 0 {
			*n = nums[1].prod(1, v)
			primes = append(primes, v)
		}
		for _, p := range primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			nums[v*p] = n.prod(v, p)
		}
	}
	return sieve{primes: primes, nums: nums}
}

func (n num) prod(myValue, p int) num {
	if p < n.leastPrime {
		return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: 1, mu: -n.mu, phi: n.phi * (p - 1)}
	}
	return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: n.lpMultiplicity + 1, mu: 0, phi: n.phi * p}
}

func (s *sieve) factor(v int) []int {
	res := []int{}
	for v > 1 {
		res = append(res, s.nums[v].leastPrime)
		v = s.eliminateLeastPrime(v)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(res)))
	return res
}

func (s *sieve) eliminateLeastPrime(v int) int {
	for m := s.nums[v].lpMultiplicity; m > 0; m-- {
		v = s.nums[v].divLeastPrime
	}
	return v
}

func (s *sieve) forEachDivisorUnordered(v int, f func(int), c int) {
	if v == 1 {
		f(c)
		return
	}
	w := s.eliminateLeastPrime(v)
	for m := 0; m <= s.nums[v].lpMultiplicity; m, c = m+1, c*s.nums[v].leastPrime {
		s.forEachDivisorUnordered(w, f, c)
	}
}

func (s *sieve) unorderedDivisors(v int) []int {
	res := []int{}
	s.forEachDivisorUnordered(v, func(d int) {
		res = append(res, d)
	}, 1)
	return res
}

var sv = newSieve()

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

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g {
			coeff[m] = coeff[m].add(newModnum(g).mul(modnum{sv.nums[c].mu}))
		}
	}

	ans := newModnum(0)
	ct := make([]int, MAXV)

	intro := func(v int) {
		sv.forEachDivisorUnordered(v, func(d int) {
			ans = ans.add(coeff[d].mul(newModnum(nCr(ct[d]+1, K) - nCr(ct[d], K))))
			ct[d]++
		})
	}

	for _, v := range a {
		intro(v)
	}

	for _, qv := range q {
		intro(qv)
		fmt.Fprintln(writer, ans.v)
	}
}

func nCr(n, r int) int {
	if r < 0 || n < r {
		return 0
	}
	return factorial(n) * inverseFactorial(r) * inverseFactorial(n - r) % int(1e9 + 7)
}

func factorial(n int) int {
	res := 1
	for i := 2; i <= n; i++ {
		res = res * i % int(1e9 + 7)
	}
	return res
}

func inverseFactorial(n int) int {
	return pow(factorial(n), int(1e9+5)) // Fermat's little theorem
}

func pow(x, y int) int {
	res := 1
	for y > 0 {
		if y&1 == 1 {
			res = res * x % int(1e9 + 7)
		}
		x = x * x % int(1e9 + 7)
		y >>= 1
	}
	return res
}
