package main

import (
	"fmt"
	"math"
	"sort"
)

const MX = 5000

type Sieve struct {
	n    int
	primes []int
	isPrime []bool
}

func NewSieve(n int) *Sieve {
	sieve := &Sieve{n: n, isPrime: make([]bool, n+1)}
	for i := 2; i <= n; i++ {
		sieve.isPrime[i] = true
	}
	sieve.isPrime[0], sieve.isPrime[1] = false, false
	for i := 2; i*i <= n; i++ {
		if sieve.isPrime[i] {
			for j := i * i; j <= n; j += i {
				sieve.isPrime[j] = false
			}
		}
	}
	for i := 2; i <= n; i++ {
		if sieve.isPrime[i] {
			sieve.primes = append(sieve.primes, i)
		}
	}
	return sieve
}

type DChaoticV struct{}

func (d *DChaoticV) solve(cin *fmt.Scanner, cout *fmt.Writer) {
	var N int
	cin.Scan(&N)
	K := make([]int, N)
	for i := 0; i < N; i++ {
		cin.Scan(&K[i])
	}
	sort.Ints(K)

	C := make([]int, MX+1)
	for _, k := range K {
		C[k]++
	}

	sieve := NewSieve(MX)
	M := len(sieve.primes)

	D := make([][]int, MX+1)
	for i := range D {
		D[i] = make([]int, M)
	}

	for i := 0; i < M; i++ {
		p := sieve.primes[i]
		for pp := p; pp <= MX; pp *= p {
			for j := 0; j <= MX; j++ {
				D[j][i] += j / pp
			}
		}
	}
	for i := 0; i <= MX; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(D[i])))
	}

	Pref := make([][]int64, MX+1)
	for i := range Pref {
		Pref[i] = make([]int64, M+1)
	}
	for i := 0; i <= MX; i++ {
		for j := 0; j < M; j++ {
			Pref[i][j+1] = Pref[i][j] + int64(D[i][j])
		}
	}

	CountPref := make([]int, MX+2)
	var tot int64
	for i := 0; i <= MX; i++ {
		CountPref[i+1] = CountPref[i] + C[i]
		tot += int64(C[i]) * Pref[i][M]
	}

	use := K[N/2]
	W := make([][2]int64, 0)
	var base int64
	for i := 0; i <= MX; i++ {
		if C[i] == 0 {
			continue
		}

		x := 0
		var len int64
		for x < M && D[i][x] == D[use][x] {
			len += int64(D[i][x])
			x++
		}
		if x < M {
			len += int64(math.Min(float64(D[i][x]), float64(D[use][x])))
		}
		W = append(W, [2]int64{len, int64(C[i])})
		base += (Pref[i][M] - len) * int64(C[i])
	}
	sort.Slice(W, func(i, j int) bool {
		return W[i][0] < W[j][0]
	})

	ans := int64(1e18)
	for _, w := range W {
		var cur int64
		for _, ww := range W {
			cur += int64(math.Abs(float64(ww[0] - w[0]))) * ww[1]
		}
		ans = int64(math.Min(float64(ans), float64(base+cur)))
	}
	fmt.Fprintln(cout, ans)
}

func main() {
	cin := fmt.NewScanner(os.Stdin)
	cout := os.Stdout
	solver := &DChaoticV{}
	solver.solve(cin, cout)
}
