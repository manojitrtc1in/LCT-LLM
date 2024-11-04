package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	N     = 70
	INF   = int(1e9)
	INF64 = int64(1e18)
)

var (
	x, k, n, q int
	c          [N]int
	a          [N][2]int
	num        [1 << 8]int
	cnt        int
)

type mat [N][N]int64

func read() bool {
	if _, err := fmt.Scan(&x, &k, &n, &q); err != nil {
		return false
	}
	for i := 0; i < k; i++ {
		fmt.Scan(&c[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i][0], &a[i][1])
		a[i][0]-- // zero-indexing
	}
	return true
}

func (a mat) multiply(b mat) mat {
	var c mat
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
			c[i][j] = INF64
			for k := 0; k < cnt; k++ {
				c[i][j] = min(c[i][j], a[i][k]+b[k][j])
			}
		}
	}
	return c
}

func (a mat) binpow(b int) mat {
	var res mat
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
			if i == j {
				res[i][j] = 0
			} else {
				res[i][j] = INF64
			}
		}
	}
	for b > 0 {
		if b&1 == 1 {
			res = res.multiply(a)
		}
		a = a.multiply(a)
		b >>= 1
	}
	return res
}

func get(pos int) (mat, int) {
	mx := n - x - pos
	pr := make([]int, k)
	for i := 0; i < q; i++ {
		if pos < a[i][0] {
			if a[i][0] <= pos+k {
				pr[a[i][0]-pos-1] = a[i][1]
				mx = 1
			} else {
				mx = min(mx, a[i][0]-(pos+k))
			}
		}
	}
	var res mat
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
			res[i][j] = INF64
		}
	}
	for mask := 0; mask < (1 << k); mask++ {
		if popcount(mask) == x {
			if mask&1 == 1 {
				for i := 1; i <= k; i++ {
					if (mask>>i)&1 == 0 {
						res[num[mask]][num[(mask|(1<<i))>>1]] = int64(c[i-1]) + int64(pr[i-1])
					}
				}
			} else {
				res[num[mask]][num[mask>>1]] = 0
			}
		}
	}
	return res, mx
}

func solve() {
	cnt = 0
	for mask := 0; mask < (1 << k); mask++ {
		if popcount(mask) == x {
			num[mask] = cnt
			cnt++
		}
	}
	var cur mat
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
			if i == j {
				cur[i][j] = 0
			} else {
				cur[i][j] = INF64
			}
		}
	}
	sort.Slice(a[:q], func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	for i := 0; i < n-x; {
		mx := 0
		tmp, mx := get(i)
		i += mx
		cur = cur.multiply(tmp.binpow(mx))
	}
	fmt.Println(cur[0][0])
}

func popcount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	for read() {
		solve()
	}
}
