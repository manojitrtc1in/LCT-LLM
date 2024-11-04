package main

import (
	"fmt"
	"math"
	"sort"
	"time"
)

type li int64
type ld float64
type pt struct {
	x, y int
}

const INF = int(1e9)
const INF64 = li(1e18)
const MOD = INF + 7
const EPS = 1e-9
const PI = math.Acos(-1.0)

const N = 70

var x, k, n, q int
var c [N]int
var a [N]pt

func read() bool {
	if _, err := fmt.Scan(&x, &k, &n, &q); err != nil {
		return false
	}
	for i := 0; i < k; i++ {
		fmt.Scan(&c[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].x-- // 0-based index
	}
	return true
}

type mat [N][N]li

var cnt int
var num [1 << 8]int

func (a mat) multiply(b mat) mat {
	var c mat
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
			c[i][j] = INF64
		}
	}
	for i := 0; i < cnt; i++ {
		for j := 0; j < cnt; j++ {
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

func get(pos int, mx *int) mat {
	*mx = n - x - pos
	pr := make([]int, k)
	for i := 0; i < q; i++ {
		if pos < a[i].x {
			if a[i].x <= pos+k {
				pr[a[i].x-pos-1] = a[i].y
				*mx = 1
			} else {
				*mx = min(*mx, a[i].x-(pos+k))
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
			if mask&1 != 0 {
				for i := 1; i <= k; i++ {
					if (mask>>i)&1 == 0 {
						res[num[mask]][num[(mask|(1<<i))>>1]] = c[i-1] + pr[i-1]
					}
				}
			} else {
				res[num[mask]][num[mask>>1]] = 0
			}
		}
	}
	return res
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
		return a[i].x < a[j].x
	})
	for i := 0; i < n-x; {
		var mx int
		tmp := get(i, &mx)
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

func min(a, b li) li {
	if a < b {
		return a
	}
	return b
}

func main() {
	start := time.Now()

	for read() {
		solve()
	}

	fmt.Printf("TIME = %v\n", time.Since(start))
}
