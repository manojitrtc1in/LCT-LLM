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

	// Count the frequency of each number in K
	C := make([]int, MX+1)
	for _, k := range K {
		C[k]++
	}

	// Generate primes up to MX
	P := sieve(MX)
	M := len(P)

	// Generate the D matrix
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

	// Generate the prefix sum matrix
	Pref := make([][]int, MX+1)
	for i := 0; i <= MX; i++ {
		Pref[i] = make([]int, M+1)
	}
	for i := 0; i <= MX; i++ {
		for j := 0; j < M; j++ {
			Pref[i][j+1] = Pref[i][j] + D[i][j]
		}
	}

	// Calculate the prefix sum of C
	CountPref := make([]int, MX+2)
	tot := 0
	for i := 0; i <= MX; i++ {
		CountPref[i+1] = CountPref[i] + C[i]
		tot += C[i] * Pref[i][M]
	}

	// Find the number with median frequency
	use := K[N/2]

	// Calculate the base value
	base := 0
	for i := 0; i <= MX; i++ {
		if C[i] == 0 {
			continue
		}
		x := 0
		len := 0
		for x < M && D[i][x] == D[use][x] {
			len += D[i][x]
			x++
		}
		if x < M {
			len += min(D[i][x], D[use][x])
		}
		base += (Pref[i][M] - len) * C[i]
	}

	// Calculate the answer
	ans := int(1e18)
	for i := 0; i <= MX; i++ {
		if C[i] == 0 {
			continue
		}
		cur := 0
		for j := 0; j <= MX; j++ {
			if C[j] == 0 {
				continue
			}
			cur += abs(Pref[j][M]-Pref[i][M]) * C[j]
		}
		ans = min(ans, base+cur)
	}

	// Print the answer
	fmt.Println(ans)
}

func sieve(n int) []int {
	isPrime := make([]bool, n+1)
	for i := 2; i <= n; i++ {
		isPrime[i] = true
	}
	for i := 2; i*i <= n; i++ {
		if isPrime[i] {
			for j := i * i; j <= n; j += i {
				isPrime[j] = false
			}
		}
	}
	primes := make([]int, 0)
	for i := 2; i <= n; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	return primes
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

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	solve()
}
