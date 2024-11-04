package main

import (
	"fmt"
)

const (
	MOD = 1000000007
	INF = 0x7fffffff
	PI  = 3.14159265358979323846264338327950288419716939937510582097494459
	EPS = 1e-6
	OO  = 1e15
)

func checkMin(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func checkMax(a *int, b int) {
	if b > *a {
		*a = b
	}
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		} else {
			return c
		}
	} else {
		if b < c {
			return b
		} else {
			return c
		}
	}
}

func max(a, b, c int) int {
	if a > b {
		if a > c {
			return a
		} else {
			return c
		}
	} else {
		if b > c {
			return b
		} else {
			return c
		}
	}
}

func sqr(a int) int {
	return a * a
}

func cub(a int) int {
	return a * a * a
}

func Ceil(x, y int) int {
	return (x - 1) / y + 1
}

func countBits(x int) int {
	x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1)
	x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2)
	x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4)
	x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8)
	x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16)
	return x
}

func lowBit(x int) int {
	return x & -x
}

func highBit(x int) int {
	p := lowBit(x)
	for p != x {
		x -= p
		p = lowBit(x)
	}
	return p
}

func INC(a *int, b int) {
	*a += b
	if *a >= MOD {
		*a -= MOD
	}
}

func sum(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	return a
}

func DEC(a *int, b int) {
	*a -= b
	if *a < 0 {
		*a += MOD
	}
}

func dff(a, b int) int {
	a -= b
	if a < 0 {
		a += MOD
	}
	return a
}

func MUL(a *int, b int) {
	*a = (int64(*a) * int64(b)) % MOD
}

func pdt(a, b int) int {
	return (int64(a) * int64(b)) % MOD
}

func RD(x *int) {
	fmt.Scan(x)
}

func OT(x int) {
	fmt.Print(x, " ")
}

func main() {
	var n, k int
	RD(&n)
	RD(&k)
	k -= 2000

	adj := make([]int, n)
	for i := 0; i < n; i++ {
		var m int
		RD(&m)
		for j := 0; j < m; j++ {
			var x int
			RD(&x)
			adj[i] |= (1 << (x - 1))
		}
	}

	P := make([]int, n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		P[i] = -1
	}

	pos := func(s int) int {
		cnt := countBits(s)
		if cnt == 0 {
			return -1
		}
		for i := 0; i < n; i++ {
			if _1(s, i) {
				return i
			}
		}
		return -1
	}

	dfs := func() int64 {
		F := make([]int64, 1<<n)
		F[0] = 1
		for s := 0; s < (1 << n); s++ {
			if F[s] != 0 {
				for i := 0; i < n; i++ {
					if !_1(s, i) && (pos(s) == -1 || pos(s) == i) && (s&adj[i]) == 0 {
						F[s|(1<<i)] += F[s]
					}
				}
			}
		}
		return F[(1<<n)-1]
	}

	if dfs() < int64(k) {
		fmt.Println("The times have changed")
	} else {
		s := (1 << n) - 1
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if _1(s, j) {
					P[A[i]] = i
					t := dfs()
					if t < int64(k) {
						k -= t
						P[j] = -1
					} else {
						s ^= (1 << j)
						fmt.Print(j+1, " ")
						break
					}
				}
			}
		}
	}
}