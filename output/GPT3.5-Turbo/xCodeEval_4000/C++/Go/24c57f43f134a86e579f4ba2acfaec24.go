package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

func init() {
	scanner.Split(bufio.ScanWords)
}

func main() {
	defer writer.Flush()

	N := scanInt()
	K := scanInt()
	Q := scanInt()

	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = scanInt()
	}

	q := make([]int, Q)
	for i := 0; i < Q; i++ {
		q[i] = scanInt()
	}

	MAXV := 1e6 + 1
	sv := sieve(MAXV)

	coeff := make([]modnum, MAXV)
	for g := 1; g < MAXV; g++ {
		for m, c := g, 1; m < MAXV; m += g, c++ {
			coeff[m] += g * sv[c].mu
		}
	}

	ans := modnum(0)
	ct := make([]int, MAXV)

	intro := func(v int) {
		sv.for_each_divisor_unordered(v, func(d int) {
			ans += coeff[d] * (modnum.ncr(ct[d]+1, K) - modnum.ncr(ct[d], K))
			ct[d]++
		})
	}

	for _, v := range a {
		intro(v)
	}

	for _, qv := range q {
		intro(qv)
		fmt.Fprintln(writer, ans)
	}
}

func scanInt() int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

type modnum int

func (n *modnum) add(o modnum) {
	*n += o
	if *n >= mod {
		*n -= mod
	}
}

func (n *modnum) sub(o modnum) {
	*n -= o
	if *n < 0 {
		*n += mod
	}
}

func (n *modnum) mul(o modnum) {
	*n = modnum(int64(*n) * int64(o) % mod)
}

func (n modnum) neg() modnum {
	return mod - n
}

func (n modnum) pow(e int) modnum {
	res := modnum(1)
	x := n
	for e > 0 {
		if e&1 == 1 {
			res.mul(x)
		}
		x.mul(x)
		e >>= 1
	}
	return res
}

func (n modnum) inv() modnum {
	return n.pow(mod - 2)
}

func (n modnum) div(o modnum) modnum {
	return n * o.inv()
}

func (n *modnum) divAssign(o modnum) {
	*n = *n / o
}

func (n modnum) String() string {
	return strconv.Itoa(int(n))
}

const mod = int(1e9 + 7)

type sieve []struct {
	least_prime     int
	div_least_prime int
	lp_multiplicity int
	mu              int
	phi             int
}

func (s sieve) is_prime(v int) bool {
	return s[v].least_prime == v
}

func (s sieve) eliminate_least_prime(v int) int {
	for m := s[v].lp_multiplicity; m > 0; m-- {
		v = s[v].div_least_prime
	}
	return v
}

func (s sieve) factor(v int) []struct {
	prime int
	count int
} {
	res := []struct {
		prime int
		count int
	}{}
	for v > 1 {
		res = append(res, struct {
			prime int
			count int
		}{s[v].least_prime, s[v].lp_multiplicity})
		v = s.eliminate_least_prime(v)
	}
	return res
}

func (s sieve) for_each_divisor_unordered(v int, f func(int)) {
	if v == 1 {
		f(1)
		return
	}
	w := s.eliminate_least_prime(v)
	for m := 0; m <= s[v].lp_multiplicity; m++ {
		factor := 1
		for i := 0; i < m; i++ {
			factor *= s[v].least_prime
		}
		s.for_each_divisor_unordered(w, func(d int) {
			f(d * factor)
		})
	}
}

func sieve(MAXV int) sieve {
	sv := make(sieve, MAXV)
	primes := []int{}
	for v := 2; v < MAXV; v++ {
		if sv[v].least_prime == 0 {
			sv[v] = struct {
				least_prime     int
				div_least_prime int
				lp_multiplicity int
				mu              int
				phi             int
			}{v, v, 1, -1, v - 1}
			primes = append(primes, v)
		}
		for _, p := range primes {
			if p > sv[v].least_prime || v*p >= MAXV {
				break
			}
			sv[v*p] = struct {
				least_prime     int
				div_least_prime int
				lp_multiplicity int
				mu              int
				phi             int
			}{sv[v].least_prime, v, sv[v].lp_multiplicity + 1, 0, sv[v].phi * p}
		}
	}
	return sv
}

type modnum int

func (n *modnum) add(o modnum) {
	*n += o
	if *n >= mod {
		*n -= mod
	}
}

func (n *modnum) sub(o modnum) {
	*n -= o
	if *n < 0 {
		*n += mod
	}
}

func (n *modnum) mul(o modnum) {
	*n = modnum(int64(*n) * int64(o) % mod)
}

func (n modnum) neg() modnum {
	return mod - n
}

func (n modnum) pow(e int) modnum {
	res := modnum(1)
	x := n
	for e > 0 {
		if e&1 == 1 {
			res.mul(x)
		}
		x.mul(x)
		e >>= 1
	}
	return res
}

func (n modnum) inv() modnum {
	return n.pow(mod - 2)
}

func (n modnum) div(o modnum) modnum {
	return n * o.inv()
}

func (n *modnum) divAssign(o modnum) {
	*n = *n / o
}

func (n modnum) String() string {
	return strconv.Itoa(int(n))
}

func ncr(n, r int) modnum {
	if r < 0 || n < r {
		return 0
	}
	res := modnum(1)
	for i := 0; i < r; i++ {
		res.mul(modnum(n - i))
		res.divAssign(modnum(i + 1))
	}
	return res
}
