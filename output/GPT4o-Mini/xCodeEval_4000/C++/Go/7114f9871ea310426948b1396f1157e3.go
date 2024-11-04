package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const MAXV = int(1e6 + 1)
const MOD = int(1e9 + 7)

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
	return newModnum(n.v + o.v)
}

func (n modnum) sub(o modnum) modnum {
	return newModnum(n.v - o.v)
}

func (n modnum) mul(o modnum) modnum {
	return newModnum(n.v * o.v)
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

func newNum() num {
	return num{math.MaxInt32, 1, 0, 1, 1}
}

func (n num) prod(myValue, p int) num {
	if p < n.leastPrime {
		return num{p, myValue, 1, -n.mu, n.phi * (p - 1)}
	}
	return num{p, myValue, n.lpMultiplicity + 1, 0, n.phi * p}
}

func newSieve() sieve {
	sv := sieve{nums: make([]num, MAXV)}
	sv.nums[1] = newNum()
	for v := 2; v < MAXV; v++ {
		n := &sv.nums[v]
		if n.leastPrime == 0 {
			*n = sv.nums[1].prod(1, v)
			sv.primes = append(sv.primes, v)
		}
		for _, p := range sv.primes {
			if p > n.leastPrime || v*p >= MAXV {
				break
			}
			sv.nums[v*p] = n.prod(v, p)
		}
	}
	return sv
}

func (sv sieve) isPrime(v int) bool {
	return sv.nums[v].leastPrime == v
}

func (sv sieve) eliminateLeastPrime(v int) int {
	for m := sv.nums[v].lpMultiplicity; m > 0; m-- {
		v = sv.nums[v].divLeastPrime
	}
	return v
}

func (sv sieve) factor(v int) []pair {
	res := []pair{}
	for v > 1 {
		res = append(res, pair{sv.nums[v].leastPrime, sv.nums[v].lpMultiplicity})
		v = sv.eliminateLeastPrime(v)
	}
	reverse(res)
	return res
}

func (sv sieve) unorderedDivisors(v int) []int {
	res := []int{}
	sv.forEachDivisorUnordered(v, func(d int) {
		res = append(res, d)
	})
	return res
}

func (sv sieve) forEachDivisorUnordered(v int, f func(int)) {
	if v == 1 {
		f(1)
		return
	}
	w := sv.eliminateLeastPrime(v)
	for m := 0; m <= sv.nums[v].lpMultiplicity; m++ {
		c := int(math.Pow(float64(sv.nums[v].leastPrime), float64(m)))
		f(c)
		sv.forEachDivisorUnordered(w, f)
	}
}

type pair struct {
	first, second int
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

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g {
			coeff[m] = coeff[m].add(newModnum(g * sv.nums[c].mu))
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
		ans = ans.add(coeff[g].mul(newModnum(nCr(ct[g], K))))
	}

	intro := func(v int) {
		sv.forEachDivisorUnordered(v, func(d int) {
			ans = ans.add(coeff[d].mul(newModnum(nCr(ct[d]+1, K) - nCr(ct[d], K))))
			ct[d]++
		})
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
	return factorial(n) * inverseFactorial(r) * inverseFactorial(n - r) % MOD
}

func factorial(n int) int {
	res := 1
	for i := 2; i <= n; i++ {
		res = res * i % MOD
	}
	return res
}

func inverseFactorial(n int) int {
	return pow(factorial(n), MOD-2)
}

func pow(x, y int) int {
	res := 1
	for y > 0 {
		if y&1 == 1 {
			res = res * x % MOD
		}
		x = x * x % MOD
		y >>= 1
	}
	return res
}

func reverse(arr []pair) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}
