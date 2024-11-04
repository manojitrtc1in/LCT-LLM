package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const MX = 5000

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read N
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Read K
	K := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		K[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Ints(K)

	C := make([]int, MX+1)
	for _, k := range K {
		C[k]++
	}

	P := sieve(MX)
	M := len(P)

	D := make([][]int, MX+1)
	for i := 0; i <= MX; i++ {
		D[i] = make([]int, M)
	}
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
		reverse(D[i])
	}

	Pref := make([][]int64, MX+1)
	for i := 0; i <= MX; i++ {
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
	var W []pair
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
		W = append(W, pair{len, int64(C[i])})
		base += (Pref[i][M] - len) * int64(C[i])
	}
	sort.Slice(W, func(i, j int) bool {
		return W[i].x < W[j].x
	})

	var ans int64 = 1e18
	for _, w := range W {
		var cur int64
		for _, ww := range W {
			cur += abs(ww.x-w.x) * ww.y
		}
		ans = min(ans, base+cur)
	}

	fmt.Println(ans)
}

func sieve(n int) []int {
	primes := make([]bool, n+1)
	for i := 2; i <= n; i++ {
		primes[i] = true
	}
	for i := 2; i*i <= n; i++ {
		if primes[i] {
			for j := i * i; j <= n; j += i {
				primes[j] = false
			}
		}
	}
	var result []int
	for i := 2; i <= n; i++ {
		if primes[i] {
			result = append(result, i)
		}
	}
	return result
}

func reverse(arr []int) {
	i, j := 0, len(arr)-1
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
}

func min(a, b int) int {
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

type pair struct {
	x, y int64
}

func main() {
	solve()
}
