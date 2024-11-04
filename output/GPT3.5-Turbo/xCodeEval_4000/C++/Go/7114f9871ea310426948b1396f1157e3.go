package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAXV = 1000001

type sieve struct {
	primes []int
	nums   []num
}

type num struct {
	leastPrime      int
	divLeastPrime   int
	lpMultiplicity int
	mu              int
	phi             int
}

func newSieve() *sieve {
	s := &sieve{
		primes: []int{},
		nums:   make([]num, MAXV),
	}
	s.nums[1] = num{INT_MAX, 1, 0, 1, 1}
	for v := 2; v < MAXV; v++ {
		n := &s.nums[v]
		if n.leastPrime == 0 {
			n.leastPrime = v
			n.divLeastPrime = 1
			n.lpMultiplicity = 1
			n.mu = -1
			n.phi = v - 1
			s.primes = append(s.primes, v)
		}
		for _, p := range s.primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			n.leastPrime = p
			n.divLeastPrime = v
			n.lpMultiplicity++
			n.mu = 0
			n.phi = n.phi * p
		}
	}
	return s
}

func (s *sieve) isPrime(v int) bool {
	if v < 1 || v >= MAXV {
		return false
	}
	return s.nums[v].leastPrime == v
}

func (s *sieve) eliminateLeastPrime(v int) int {
	if v <= 1 || v >= MAXV {
		return v
	}
	for m := s.nums[v].lpMultiplicity; m > 0; m-- {
		v = s.nums[v].divLeastPrime
	}
	return v
}

func (s *sieve) factor(v int) []pair {
	if v <= 1 || v >= MAXV {
		return nil
	}
	res := []pair{}
	for v > 1 {
		res = append(res, pair{s.nums[v].leastPrime, s.nums[v].lpMultiplicity})
		v = s.eliminateLeastPrime(v)
	}
	return res
}

func (s *sieve) forEachDivisorUnordered(v int, f func(int), c int) {
	if v <= 1 || v >= MAXV {
		return
	}
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
	if v <= 1 || v >= MAXV {
		return nil
	}
	res := []int{}
	s.forEachDivisorUnordered(v, func(d int) {
		res = append(res, d)
	}, 1)
	return res
}

type pair struct {
	first  int
	second int
}

type modnum struct {
	v int
}

func newModnum(_v int) *modnum {
	return &modnum{v: _v % MOD}
}

func (n *modnum) add(o *modnum) *modnum {
	n.v += o.v
	if n.v >= MOD {
		n.v -= MOD
	}
	return n
}

func (n *modnum) subtract(o *modnum) *modnum {
	n.v -= o.v
	if n.v < 0 {
		n.v += MOD
	}
	return n
}

func (n *modnum) multiply(o *modnum) *modnum {
	n.v = fastMod(int64(n.v)*int64(o.v), MOD)
	return n
}

func (n *modnum) pow(e int) *modnum {
	if e < 0 {
		return n.pow(-e).inverse()
	}
	if e == 0 {
		return newModnum(1)
	}
	if e&1 == 1 {
		return n.multiply(n.pow(e - 1))
	}
	return n.multiply(n).pow(e / 2)
}

func (n *modnum) inverse() *modnum {
	g := MOD
	x := 0
	y := 1
	r := n.v
	for r != 0 {
		q := g / r
		g, r = r, g-q*r
		x, y = y-q*x, x
	}
	if g != 1 {
		panic("inverse does not exist")
	}
	if y == MOD || y == -MOD {
		panic("inverse does not exist")
	}
	if x < 0 {
		x += MOD
	}
	return newModnum(x)
}

func (n *modnum) divide(o *modnum) *modnum {
	return n.multiply(o.inverse())
}

func (n *modnum) equals(o *modnum) bool {
	return n.v == o.v
}

func (n *modnum) notEquals(o *modnum) bool {
	return n.v != o.v
}

func fastMod(x int64, m int) int {
	if x >= 0 {
		return int(x % int64(m))
	}
	return int((x%m + int64(m)) % int64(m))
}

const MOD = 1000000007
const INT_MAX = int(^uint(0) >> 1)

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

	coeff := make([]*modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		coeff[g] = newModnum(0)
		for m, c := g, 1; m < MAXV; m, c = m+g, c+1 {
			coeff[m].add(newModnum(g).multiply(newModnum(sv.nums[c].mu)))
		}
	}

	ans := newModnum(0)
	ct := make([]int, MAXV)
	for _, e := range a {
		ct[e]++
	}
	for g := 1; g < MAXV; g++ {
		for m := 2 * g; m < MAXV; m += g {
			ct[g] += ct[m]
		}
		ans.add(coeff[g].multiply(newModnum(ct[g]).ncr(K)))
	}

	intro := func(v int) {
		factors := sv.unorderedDivisors(v)
		for _, d := range factors {
			ans.add(coeff[d].multiply(newModnum(ct[d]+1).ncr(K)).subtract(newModnum(ct[d]).ncr(K)))
			ct[d]++
		}
	}

	for _, qv := range q {
		intro(qv)
		fmt.Fprintln(writer, ans.v)
	}
}
