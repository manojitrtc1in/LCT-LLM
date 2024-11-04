package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const MAXV = 1e6 + 1
const MOD = 1e9 + 7

type modnum int

func (n modnum) mod() modnum {
	if n < 0 {
		return n + modnum(MOD)
	}
	return n % modnum(MOD)
}

func (n *modnum) add(o modnum) {
	*n = (*n + o).mod()
}

func (n *modnum) sub(o modnum) {
	*n = (*n - o).mod()
}

func (n *modnum) mul(o modnum) {
	*n = (*n * o).mod()
}

func (n modnum) pow(e int) modnum {
	if e == 0 {
		return 1
	}
	if e%2 == 1 {
		return n.mul(n.pow(e - 1))
	}
	return n.mul(n).pow(e / 2)
}

func (n modnum) inv() modnum {
	return n.pow(int(MOD) - 2)
}

func (n *modnum) div(o modnum) {
	*n = (*n).mul(o.inv())
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

func newNum() num {
	return num{leastPrime: math.MaxInt32, divLeastPrime: 1, lpMultiplicity: 0, mu: 1, phi: 1}
}

func (n num) prod(myValue, p int) num {
	if p < n.leastPrime {
		return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: 1, mu: -n.mu, phi: n.phi * (p - 1)}
	}
	return num{leastPrime: p, divLeastPrime: myValue, lpMultiplicity: n.lpMultiplicity + 1, mu: 0, phi: n.phi * p}
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

func (sv *sieve) isPrime(v int) bool {
	return sv.nums[v].leastPrime == v
}

func (sv *sieve) eliminateLeastPrime(v int) int {
	for m := sv.nums[v].lpMultiplicity; m > 0; m-- {
		v = sv.nums[v].divLeastPrime
	}
	return v
}

func (sv *sieve) factor(v int) []pair {
	res := []pair{}
	for v > 1 {
		res = append(res, pair{sv.nums[v].leastPrime, sv.nums[v].lpMultiplicity})
		v = sv.eliminateLeastPrime(v)
	}
	sort.Slice(res, func(i, j int) bool {
		return res[i].first < res[j].first
	})
	return res
}

type pair struct {
	first  int
	second int
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
	ct := make([]int, MAXV)
	coeff := make([]modnum, MAXV)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &a[i])
		ct[a[i]]++
	}

	ans := modnum(0)

	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g {
			coeff[m].add(modnum(g * sv.nums[c].mu))
			if c > 1 {
				ct[g] += ct[m]
			}
		}
		ans.add(coeff[g].mul(nCr(ct[g], K)))
	}

	for _, qv := range q {
		sv.factor(qv)
		for _, d := range sv.factor(qv) {
			ans.add(coeff[d.first].mul(nCr(ct[d.first]+1, K).sub(nCr(ct[d.first], K))))
			ct[d.first]++
		}
		fmt.Fprintln(writer, ans)
	}
}

func nCr(n, r int) modnum {
	if r < 0 || n < r {
		return 0
	}
	return factorial(n).mul(inverseFactorial(r)).mul(inverseFactorial(n - r))
}

func factorial(n int) modnum {
	res := modnum(1)
	for i := 1; i <= n; i++ {
		res.mul(modnum(i))
	}
	return res
}

func inverseFactorial(n int) modnum {
	return factorial(n).inv()
}
