package main

import (
	"fmt"
	"math"
	"sort"
)

const jt = 998244353

type Point struct {
	x, y float64
	ang  float64
}

func (p *Point) getAngle() {
	p.ang = math.Atan2(p.y, p.x)
}

type Line struct {
	a, b Point
}

func intersect(x, y Line) Point {
	p1 := x.a
	v1 := Point{x: x.b.x - x.a.x, y: x.b.y - x.a.y}
	p2 := y.a
	v2 := Point{x: y.b.x - y.a.x, y: y.b.y - y.a.y}
	return Point{x: p1.x + v1.x * ((p2.x - p1.x) * v2.y - (p2.y - p1.y) * v2.x) / (v1.x * v2.y - v1.y * v2.x),
		y: p1.y + v1.y * ((p2.x - p1.x) * v2.y - (p2.y - p1.y) * v2.x) / (v1.x * v2.y - v1.y * v2.x)}
}

type BIT struct {
	dt []int
}

func (bit *BIT) add(a, x int) {
	for a < len(bit.dt) {
		bit.dt[a] = (bit.dt[a] + x) % jt
		a += a & -a
	}
}

func (bit *BIT) get(a int) int {
	ans := 0
	for a > 0 {
		ans = (ans + bit.dt[a]) % jt
		a -= a & -a
	}
	return ans
}

func main() {
	var n, m int
	fmt.Scan(&n)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	m = len(s[0])
	dy := make([]int64, 1<<20)
	dp := make([]float64, 1<<20)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			num := 0
			for k := 0; k < m; k++ {
				if s[i][k] == s[j][k] {
					num |= 1 << k
				}
			}
			dy[num] |= (1 << i) | (1 << j)
		}
	}

	for i := 0; i < (1 << m); i++ {
		for j := i; j&-j > 0; j -= j & -j {
			lst := j & -j
			dy[i^lst] |= dy[i]
		}
	}

	dp[0] = 1
	ans := 0.0
	for i := 0; i < (1 << m); i++ {
		v := dp[i] / float64(m-__builtin_popcount(i))
		for j := ^i & (1<<m - 1); j > 0; j -= j & -j {
			dp[i|j&-j] += v
		}
		ans += dp[i] * float64(__builtin_popcountll(dy[i]))
	}
	fmt.Printf("%.10f\n", ans/float64(n))
}

func __builtin_popcount(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}

func __builtin_popcountll(x int64) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}
