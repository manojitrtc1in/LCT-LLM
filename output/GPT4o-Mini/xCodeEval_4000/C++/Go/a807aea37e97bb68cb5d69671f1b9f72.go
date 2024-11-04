package main

import (
	"bufio"
	"fmt"
	"math"
	"sort"
)

const MX = 5000

type vector2 [][]int

func newVector2(a, b int) vector2 {
	v := make(vector2, a)
	for i := range v {
		v[i] = make([]int, b)
	}
	return v
}

type Sieve struct {
	n int
}

func newSieve(n int) *Sieve {
	s := &Sieve{n: n}
	return s
}

func (s *Sieve) primes() []int {
	isPrime := make([]bool, s.n+1)
	for i := range isPrime {
		isPrime[i] = true
	}
	isPrime[0], isPrime[1] = false, false

	for i := 2; i*i <= s.n; i++ {
		if isPrime[i] {
			for j := i * i; j <= s.n; j += i {
				isPrime[j] = false
			}
		}
	}

	var primes []int
	for i := 2; i <= s.n; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	return primes
}

type DChaoticV struct{}

func (d *DChaoticV) solve(reader *bufio.Reader, writer *bufio.Writer) {
	var N int
	fmt.Fscan(reader, &N)
	K := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &K[i])
	}
	sort.Ints(K)

	C := make([]int, MX+1)
	for _, k := range K {
		C[k]++
	}

	P := newSieve(MX).primes()
	M := len(P)

	D := newVector2(MX+1, M)
	for i := 0; i < M; i++ {
		p := P[i]
		for p <= MX {
			for j := 0; j <= MX; j++ {
				D[j][i] += j / p
			}
			p *= P[i]
		}
	}
	for i := 0; i <= MX; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(D[i])))
	}

	Pref := newVector2(MX+1, M+1)
	for i := 0; i <= MX; i++ {
		for j := 0; j < M; j++ {
			Pref[i][j+1] = Pref[i][j] + D[i][j]
		}
	}

	CountPref := make([]int, MX+2)
	var tot int64
	for i := 0; i <= MX; i++ {
		CountPref[i+1] = CountPref[i] + C[i]
		tot += int64(C[i]) * int64(Pref[i][M])
	}

	use := K[N/2]
	var W []struct {
		x int64
		y int
	}
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
			len += int64(min(D[i][x], D[use][x]))
		}
		W = append(W, struct {
			x int64
			y int
		}{len, C[i]})
		base += (int64(Pref[i][M]) - len) * int64(C[i])
	}
	sort.Slice(W, func(i, j int) bool {
		return W[i].x < W[j].x
	})

	ans := int64(math.MaxInt64)
	for _, w := range W {
		var cur int64
		for _, ww := range W {
			cur += int64(abs(ww.x - w.x)) * int64(ww.y)
		}
		ans = min(ans, base+cur)
	}
	fmt.Fprintln(writer, ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024)
	writer := bufio.NewWriterSize(os.Stdout, 1024)
	defer writer.Flush()

	solver := DChaoticV{}
	solver.solve(reader, writer)
}
