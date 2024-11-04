package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAXV = 1000001

var primes []int
var nums [MAXV]num

type num struct {
	leastPrime      int
	divLeastPrime   int
	lpMultiplicity int
	mu              int
	phi             int
}

func (n num) prod(myValue, p int) num {
	if p < n.leastPrime {
		return num{p, myValue, 1, -n.mu, n.phi * (p - 1)}
	}
	return num{p, myValue, n.lpMultiplicity + 1, 0, n.phi * p}
}

func eliminateLeastPrime(v int) int {
	for m := nums[v].lpMultiplicity; m > 0; m-- {
		v = nums[v].divLeastPrime
	}
	return v
}

func factor(v int) []int {
	res := []int{}
	for v > 1 {
		v = eliminateLeastPrime(v)
		res = append(res, nums[v].leastPrime)
	}
	return res
}

func for_each_divisor_unordered(v int, f func(int), c int) {
	if v == 1 {
		f(c)
		return
	}
	w := eliminateLeastPrime(v)
	for m := 0; m <= nums[v].lpMultiplicity; m, c = m+1, c*nums[v].leastPrime {
		for_each_divisor_unordered(w, f, c)
	}
}

func unordered_divisors(v int) []int {
	res := []int{}
	for_each_divisor_unordered(v, func(d int) {
		res = append(res, d)
	}, 1)
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	K := nextInt(scanner)
	Q := nextInt(scanner)
	a := make([]int, N)
	q := make([]int, Q)
	for i := 0; i < N; i++ {
		a[i] = nextInt(scanner)
	}
	for i := 0; i < Q; i++ {
		q[i] = nextInt(scanner)
	}

	ans := 0
	ct := make([]int, MAXV)
	coeff := make([]int, MAXV)

	for _, e := range a {
		ct[e]++
	}

	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m, c = m+g, c+1 {
			coeff[m] += g * sv[c].mu
			if c > 1 {
				ct[g] += ct[m]
			}
		}
		ans += coeff[g] * (ncr(ct[g], K) - ncr(ct[g]-1, K))
	}

	for _, qv := range q {
		for _, d := range unordered_divisors(qv) {
			ans += coeff[d] * (ncr(ct[d]+1, K) - ncr(ct[d], K))
			ct[d]++
		}
		fmt.Println(ans)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func ncr(n, r int) int {
	if r < 0 || n < r {
		return 0
	}
	numerator := 1
	denominator := 1
	for i := 0; i < r; i++ {
		numerator *= n - i
		denominator *= i + 1
	}
	return numerator / denominator
}

func init() {
	nums[1] = num{MAXV, 1, 0, 1, 1}
	for v := 2; v < MAXV; v++ {
		if nums[v].leastPrime == 0 {
			nums[v] = num{v, v, 1, -nums[1].mu, nums[1].phi * (v - 1)}
			primes = append(primes, v)
		}
		for _, p := range primes {
			if p > nums[v].leastPrime || v*p >= MAXV {
				break
			}
			nums[v*p] = nums[v].prod(v, p)
		}
	}
}
