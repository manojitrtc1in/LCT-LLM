package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

var sc = bufio.NewScanner(os.Stdin)

func main() {
	test := 1
	for test > 0 {
		solve()
		test--
	}
}

func solve() {
	s := nextString()
	t := nextString()
	n := len(s)
	m := len(t)
	pre := make([]int, m)
	suf := make([]int, m)

	for i, j := 0, 0; i < m; i++ {
		for s[j] != t[i] {
			j++
		}
		pre[i] = j
		j++
	}

	for i, j := m-1, n-1; i >= 0; i-- {
		for s[j] != t[i] {
			j--
		}
		suf[i] = j
		j--
	}

	ans := max(suf[0], n-1-pre[m-1])
	for i := 0; i < m-1; i++ {
		ans = max(ans, suf[i+1]-1-pre[i])
	}
	fmt.Println(ans)
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lowerBound(key int, a []int) int {
	s, e := 0, len(a)-1
	if e == -1 {
		return 0
	}
	ans := -1
	for s <= e {
		m := s + (e-s)/2
		if a[m] >= key {
			ans = m
			e = m - 1
		} else {
			s = m + 1
		}
	}
	if ans == -1 {
		return s
	}
	return ans
}

func upperBound(key int, a []int) int {
	s, e := 0, len(a)-1
	if e == -1 {
		return 0
	}
	ans := -1
	for s <= e {
		m := s + (e-s)/2
		if a[m] > key {
			ans = m
			e = m - 1
		} else {
			s = m + 1
		}
	}
	if ans == -1 {
		return s
	}
	return ans
}

func mul(a, b int64) int64 {
	return (a % MOD) * (b % MOD) % MOD
}

func add(a, b int64) int64 {
	return (a % MOD + b % MOD) % MOD
}

func sub(a, b int64) int64 {
	return (a % MOD - b % MOD + MOD) % MOD
}

func primeFactors(n int64) []int64 {
	arr := []int64{}
	if n%2 == 0 {
		arr = append(arr, 2)
	}
	for n%2 == 0 {
		n /= 2
	}
	for i := int64(3); i <= int64(math.Sqrt(float64(n))); i += 2 {
		flag := 0
		for n%i == 0 {
			n /= i
			flag = 1
		}
		if flag == 1 {
			arr = append(arr, i)
		}
	}
	if n > 2 {
		arr = append(arr, n)
	}
	return arr
}

func countSetBits(n int64) int64 {
	if n == 0 {
		return 0
	}
	return 1 + countSetBits(n & (n - 1))
}

func gcd(A, B int64) int64 {
	if B == 0 {
		return A
	}
	return gcd(B, A%B)
}

func fastExpo(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		return fastExpo((x*x)%MOD, n/2) % MOD
	}
	return (x % MOD * fastExpo((x*x)%MOD, (n-1)/2)) % MOD
}

func nextInt() int {
	sc.Scan()
	val, _ := strconv.Atoi(sc.Text())
	return val
}

func nextLong() int64 {
	sc.Scan()
	val, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return val
}
