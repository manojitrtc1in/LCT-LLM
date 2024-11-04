package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const (
	jt = 998244353
)

type point struct {
	x, y float64
	ang  float64
}

type line struct {
	a, b point
}

type bitmod struct {
	dt [][2]int
}

type DSU struct {
	fa, sz []int
}

type matrix struct {
	mat [][]int
}

func id0(a, b int) int {
	if b < 0 {
		return id0(id0(a, 0), -b)
	}
	if b == 0 {
		return 1
	}
	x := id0(a, b>>1)
	x = (x * x) % jt
	if b&1 == 1 {
		x = (x * a) % jt
	}
	return x
}

func qp(a int, b int) int {
	if b == 0 {
		return 1
	}
	x := qp(a, b>>1)
	x = x * x
	if b&1 == 1 {
		x = x * a
	}
	return x
}

func intersect(x line, y line) point {
	p1 := x.a
	v1 := point{x.b.x - x.a.x, x.b.y - x.a.y}
	p2 := y.a
	v2 := point{y.b.x - y.a.x, y.b.y - y.a.y}
	return point{p1.x + v1.x*((p2.y-p1.y)/(v1.y*v2.x-v1.x*v2.y)), p1.y + v1.y*((p2.y-p1.y)/(v1.y*v2.x-v1.x*v2.y))}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := 0
	fmt.Fscan(reader, &n)

	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s[i])
	}

	m := len(s[0])
	dy := make([]int64, 1<<m)
	dp := make([]float64, 1<<m)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			num := 0
			for k := 0; k < m; k++ {
				if s[i][k] == s[j][k] {
					num |= 1 << k
				}
			}
			dy[num] |= 1<<i | 1<<j
		}
	}

	for i := 0; i < 1<<m; i++ {
		for j := i; j&(j-1) > 0; j -= j & -j {
			lst := j & -j
			dy[i^lst] |= dy[i]
		}
	}

	dp[0] = 1
	ans := 0.0
	for i := 0; i < 1<<m; i++ {
		v := dp[i] / float64(m-int(popcount(i)))
		for j := (1<<m - 1) ^ i; j&(j-1) > 0; j -= j & -j {
			dp[i|(j&-j)] += v
		}
		ans += dp[i] * float64(popcountll(dy[i]))
	}

	fmt.Fprintln(writer, ans/float64(n))
}

func popcount(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}

func popcountll(x int64) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}
