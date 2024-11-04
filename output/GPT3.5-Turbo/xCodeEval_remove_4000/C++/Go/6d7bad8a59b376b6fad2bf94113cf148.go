package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"time"
)

type pt struct {
	x int
	y int
}

type mat [70][70]int64

var (
	x, k, n, q int
	c          [70]int
	a          [70]pt
)

func read() bool {
	_, err := fmt.Scanf("%d%d%d%d", &x, &k, &n, &q)
	if err != nil {
		return false
	}
	for i := 0; i < k; i++ {
		fmt.Scanf("%d", &c[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scanf("%d%d", &a[i].x, &a[i].y)
		a[i].x--
	}
	return true
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
				*mx = int(math.Min(float64(*mx), float64(a[i].x-(pos+k))))
			}
		}
	}
	res := mat{}
	for i := 0; i < 70; i++ {
		for j := 0; j < 70; j++ {
			res[i][j] = math.MaxInt64
		}
	}
	for mask := 0; mask < (1 << k); mask++ {
		if bitCount(mask) == x {
			if mask&1 != 0 {
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
	return res
}

func bitCount(n int) int {
	count := 0
	for n > 0 {
		count++
		n &= n - 1
	}
	return count
}

func binpow(a mat, b int) mat {
	res := mat{}
	for i := 0; i < 70; i++ {
		for j := 0; j < 70; j++ {
			if i == j {
				res[i][j] = 0
			} else {
				res[i][j] = math.MaxInt64
			}
		}
	}
	for b > 0 {
		if b&1 != 0 {
			res = multiply(res, a)
		}
		a = multiply(a, a)
		b >>= 1
	}
	return res
}

func multiply(a, b mat) mat {
	c := mat{}
	for i := 0; i < 70; i++ {
		for j := 0; j < 70; j++ {
			c[i][j] = math.MaxInt64
		}
	}
	for i := 0; i < 70; i++ {
		for j := 0; j < 70; j++ {
			for k := 0; k < 70; k++ {
				c[i][j] = int64(math.Min(float64(c[i][j]), float64(a[i][k]+b[k][j])))
			}
		}
	}
	return c
}

var num [1 << 8]int

func solve() {
	cnt := 0
	for mask := 0; mask < (1 << k); mask++ {
		if bitCount(mask) == x {
			num[mask] = cnt
			cnt++
		}
	}

	cur := mat{}
	for i := 0; i < 70; i++ {
		for j := 0; j < 70; j++ {
			if i == j {
				cur[i][j] = 0
			} else {
				cur[i][j] = math.MaxInt64
			}
		}
	}
	sort.Slice(a[:q], func(i, j int) bool {
		return a[i].x < a[j].x
	})
	i := 0
	for i < n-x {
		var mx int
		tmp := get(i, &mx)
		i += mx
		cur = multiply(cur, binpow(tmp, mx))
	}

	fmt.Printf("%d\n", cur[0][0])
}

func main() {
	rand.Seed(time.Now().UnixNano())

	tt := time.Now()

	for read() {
		solve()
	}

	fmt.Printf("TIME = %v\n", time.Since(tt))
}
