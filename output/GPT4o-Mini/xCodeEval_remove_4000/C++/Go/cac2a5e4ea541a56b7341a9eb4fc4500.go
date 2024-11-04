package main

import (
	"fmt"
	"math"
	"sort"
)

const md = 998244353

type Mint int

func (m Mint) normalize() Mint {
	if m < 0 {
		m += md
	}
	if m >= md {
		m -= md
	}
	return m
}

func (m Mint) inverse() Mint {
	u, v := Mint(0), Mint(1)
	a, b := m, md
	for a != 0 {
		t := b / a
		b -= t * a
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	if b != 1 {
		panic("inverse does not exist")
	}
	return u.normalize()
}

type Mat [2][2]Mint

func (a Mat) multiply(b Mat) Mat {
	var c Mat
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return c
}

type Frac struct {
	p, q int
}

func (f Frac) lessThan(other Frac) bool {
	return int64(f.p)*int64(other.q) < int64(other.p)*int64(f.q)
}

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println(0)
		return
	}

	x := make([]int, n)
	v := make([]int, n)
	p := make([]Mint, n)
	id1 := Mint(1) / Mint(100)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &v[i])
		p[i] = id1
	}

	id2 := make([]Mat, n-1)
	for i := 0; i < n-1; i++ {
		id2[i][0][1] = p[i+1]
	}

	a := make([]Mat, 2*(n-1)-1)
	getProb := func(toRight Mint, mat Mat) Mint {
		return toRight * (mat[1][0] + mat[1][1]) + (1 - toRight) * (mat[0][0] + mat[0][1])
	}

	var build func(l, r int)
	build = func(l, r int) {
		if l == r {
			a[2*l] = id2[l]
			return
		}
		mid := (l + r) / 2
		build(l, mid)
		build(mid+1, r)
		a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid+1, r)])
	}

	build(0, n-2)

	var modify func(l, r, k int)
	modify = func(l, r, k int) {
		if l == r {
			a[2*l] = id2[k]
			return
		}
		mid := (l + r) / 2
		if k <= mid {
			modify(l, mid, k)
		} else {
			modify(mid+1, r, k)
		}
		a[getId(l, r)] = a[getId(l, mid)].multiply(a[getId(mid+1, r)])
	}

	events := make([][2]Frac, 3*(n-1))
	for i := 0; i < n-1; i++ {
		d := x[i+1] - x[i]
		events[i*3] = [2]Frac{{d, v[i+1] + v[i]}, Frac{0, 0}}
		if v[i] < v[i+1] {
			events[i*3+1] = [2]Frac{{d, v[i+1] - v[i]}, Frac{0, 0}}
		} else {
			events[i*3+1] = [2]Frac{{1, 0}, Frac{0, 0}}
		}
		if v[i] > v[i+1] {
			events[i*3+2] = [2]Frac{{d, v[i] - v[i+1]}, Frac{0, 0}}
		} else {
			events[i*3+2] = [2]Frac{{1, 0}, Frac{0, 0}}
		}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i][0].lessThan(events[j][0])
	})

	prevProb := getProb(p[0], a[getId(0, n-2)])
	var ans Mint

	for i := len(events) - 1; i >= 0; i-- {
		event := events[i]
		i := event[1].p >> 2
		dir1 := event[1].p & 1
		dir2 := (event[1].p >> 1) & 1

		if dir2 == 1 {
			id2[i][dir1][dir2] = p[i+1]
		} else {
			id2[i][dir1][dir2] = 1 - p[i+1]
		}
		modify(0, n-2, i)
		prob := getProb(p[0], a[getId(0, n-2)])
		if event[0].q != 0 {
			ans += (prob - prevProb) * event[0]
		}
		prevProb = prob
	}

	fmt.Println(ans)
}

func getId(l, r int) int {
	return l + r | (l != r)
}
