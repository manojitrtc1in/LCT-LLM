package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type Mint int

const md = 998244353

func (m Mint) normalize() Mint {
	if m < 0 {
		m += md
	}
	if m >= md {
		m -= md
	}
	return m
}

func (m Mint) add(n Mint) Mint {
	return (m + n).normalize()
}

func (m Mint) sub(n Mint) Mint {
	return (m - n).normalize()
}

func (m Mint) mul(n Mint) Mint {
	return (m * n).normalize()
}

func (m Mint) inv() Mint {
	return pow(m, md-2)
}

func pow(a Mint, b int) Mint {
	res := Mint(1)
	for b > 0 {
		if b&1 == 1 {
			res = res.mul(a)
		}
		a = a.mul(a)
		b >>= 1
	}
	return res
}

type Frac struct {
	p, q int
}

func (f Frac) lessThan(other Frac) bool {
	return int64(f.p)*int64(other.q) < int64(other.p)*int64(f.q)
}

type Mat struct {
	m [2][2]Mint
}

func (a Mat) multiply(b Mat) Mat {
	var c Mat
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				c.m[i][j] = c.m[i][j].add(a.m[i][k].mul(b.m[k][j]))
			}
		}
	}
	return c
}

func getId(l, r int) int {
	return l + r | (l != r)
}

func getMid(l, r int) int {
	return l + (r-l)/2
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	if n == 1 {
		fmt.Fprintln(writer, 0)
		return
	}

	x := make([]int, n)
	v := make([]int, n)
	p := make([]Mint, n)

	inv100 := Mint(1).div(Mint(100))

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &x[i], &v[i])
		p[i] = inv100.mul(Mint(v[i]))
	}

	allowedCollisions := make([]Mat, n-1)

	for i := 0; i < n-1; i++ {
		allowedCollisions[i].m[0][1] = p[i+1]
	}

	a := make([]Mat, 2*(n-1)-1)

	getProb := func(toRight Mint, mat Mat) Mint {
		return toRight.mul(mat.m[1][0].add(mat.m[1][1])).add((1 - toRight).mul(mat.m[0][0].add(mat.m[0][1])))
	}

	var build func(l, r int)
	build = func(l, r int) {
		if l == r {
			a[2*l] = allowedCollisions[l]
			return
		}
		mid := getMid(l, r)
		build(l, mid)
		build(mid+1, r)
		a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid+1, r)])
	}
	build(0, n-2)

	var modify func(l, r, k int)
	modify = func(l, r, k int) {
		if l == r {
			a[2*l] = allowedCollisions[k]
			return
		}
		mid := getMid(l, r)
		if k <= mid {
			modify(l, mid, k)
		} else {
			modify(mid+1, r, k)
		}
		a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid+1, r)])
	}

	events := make([][2]interface{}, 3*(n-1))

	for i := 0; i < n-1; i++ {
		d := x[i+1] - x[i]
		events[i*3] = [2]interface{}{Frac{d, v[i+1] + v[i]}, i<<2 | 1}
		if v[i] < v[i+1] {
			events[i*3+1] = [2]interface{}{Frac{d, v[i+1] - v[i]}, i<<2 | 0}
		} else {
			events[i*3+1] = [2]interface{}{Frac{1, 0}, i<<2 | 0}
		}
		if v[i] > v[i+1] {
			events[i*3+2] = [2]interface{}{Frac{d, v[i] - v[i+1]}, i<<2 | 3}
		} else {
			events[i*3+2] = [2]interface{}{Frac{1, 0}, i<<2 | 3}
		}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i][0].(Frac).lessThan(events[j][0].(Frac))
	})

	prevProb := getProb(p[0], a[getId(0, n-2)])
	ans := Mint(0)

	for i := len(events) - 1; i >= 0; i-- {
		event := events[i]
		index := event[1].(int) >> 2
		dir1 := event[1].(int) & 1
		dir2 := (event[1].(int) >> 1) & 1

		if dir2 == 1 {
			allowedCollisions[index].m[dir1][dir2] = p[index+1]
		} else {
			allowedCollisions[index].m[dir1][dir2] = Mint(1).sub(p[index+1])
		}
		modify(0, n-2, index)

		prob := getProb(p[0], a[getId(0, n-2)])
		if event[0].(Frac).q != 0 {
			ans = ans.add(prob.sub(prevProb).mul(event[0].(Frac).p))
		}
		prevProb = prob
	}

	fmt.Fprintln(writer, ans)
}
