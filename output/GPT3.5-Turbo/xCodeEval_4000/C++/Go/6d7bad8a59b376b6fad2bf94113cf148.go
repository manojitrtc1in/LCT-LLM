package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = INF + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)
	N     = 70
)

type pt struct {
	x, y int
}

func read() (int, int, int, int, []int, []pt) {
	var x, k, n, q int
	if _, err := fmt.Scanf("%d%d%d%d", &x, &k, &n, &q); err != nil {
		return 0, 0, 0, 0, nil, nil
	}
	c := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scanf("%d", &c[i])
	}
	a := make([]pt, q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d%d", &a[i].x, &a[i].y)
		a[i].x--
	}
	return x, k, n, q, c, a
}

type mat [N][N]int64

func multiply(a, b mat) mat {
	c := mat{}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			c[i][j] = INF64
		}
	}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			for k := 0; k < N; k++ {
				c[i][j] = min(c[i][j], a[i][k]+b[k][j])
			}
		}
	}
	return c
}

func binpow(a mat, b int) mat {
	res := mat{}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			res[i][j] = i == j
		}
	}
	for b > 0 {
		if b&1 == 1 {
			res = multiply(res, a)
		}
		a = multiply(a, a)
		b >>= 1
	}
	return res
}

func get(pos int, x *int, k int, n int, a []pt, c []int) (mat, int) {
	mx := n - *x - pos
	pr := make([]int, k)
	for i := 0; i < len(a); i++ {
		if pos < a[i].x {
			if a[i].x <= pos+k {
				pr[a[i].x-pos-1] = a[i].y
				mx = 1
			} else {
				mx = min(mx, a[i].x-(pos+k))
			}
		}
	}
	res := mat{}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			res[i][j] = INF64
		}
	}
	for mask := 0; mask < (1 << k); mask++ {
		if countBits(mask) == *x {
			if mask&1 == 1 {
				for i := 1; i <= k; i++ {
					if mask>>i&1 == 0 {
						res[num[mask]][num[(mask|(1<<i))>>1]] = int64(c[i-1] + pr[i-1])
					}
				}
			} else {
				res[num[mask]][num[mask>>1]] = 0
			}
		}
	}
	return res, mx
}

func solve(x, k, n, q int, c []int, a []pt) {
	cnt := 0
	num := make([]int, 1<<8)
	for mask := 0; mask < (1 << k); mask++ {
		if countBits(mask) == x {
			num[mask] = cnt
			cnt++
		}
	}

	cur := mat{}
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			cur[i][j] = i == j
		}
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].x < a[j].x
	})
	for i := 0; i < n-x; {
		mx := 0
		tmp, mx := get(i, &x, k, n, a, c)
		i += mx
		cur = multiply(cur, binpow(tmp, mx))
	}

	fmt.Printf("%d\n", cur[0][0])
}

func main() {
	for {
		x, k, n, q, c, a := read()
		if c == nil {
			break
		}
		solve(x, k, n, q, c, a)
	}
}

func countBits(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
