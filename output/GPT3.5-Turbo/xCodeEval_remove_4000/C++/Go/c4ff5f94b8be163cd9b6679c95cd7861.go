package main

import (
	"fmt"
	"math"
)

type Mint int

const mod Mint = 998244353

func (a Mint) Add(b Mint) Mint {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func (a Mint) Sub(b Mint) Mint {
	c := a - b
	if c < 0 {
		c += mod
	}
	return c
}

func (a Mint) Mul(b Mint) Mint {
	return Mint(int64(a) * int64(b) % int64(mod))
}

func (a Mint) Pow(b int) Mint {
	if b == 0 {
		return 1
	}
	if b%2 == 0 {
		c := a.Pow(b / 2)
		return c.Mul(c)
	}
	return a.Mul(a.Pow(b - 1))
}

func (a Mint) Inv() Mint {
	return a.Pow(int(mod) - 2)
}

func (a Mint) Div(b Mint) Mint {
	return a.Mul(b.Inv())
}

func (a Mint) Neg() Mint {
	return 0 - a
}

func (a Mint) String() string {
	return fmt.Sprintf("%d", a)
}

type Mat [2][2]Mint

func (a Mat) Mul(b Mat) Mat {
	c := Mat{}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				c[i][j] = c[i][j].Add(a[i][k].Mul(b[k][j]))
			}
		}
	}
	return c
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
	id1 := Mint(1).Div(100)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &v[i], &p[i])
		p[i] = p[i].Mul(id1)
	}
	id2 := make([]Mat, n-1)
	for i := 0; i < n-1; i++ {
		id2[i][0][1] = p[i+1]
	}
	a := make([]Mat, 2*(n-1)-1)
	getProb := func(toRight Mint, mat *Mat) Mint {
		return toRight.Mul(mat[1][0].Add(mat[1][1])).Add((1 - toRight).Mul(mat[0][0].Add(mat[0][1])))
	}
	build := func(l, r int) {
		if l == r {
			a[2*l] = id2[l]
			return
		}
		mid := (l + r) / 2
		build(l, mid)
		build(mid+1, r)
		a[getid(l, r)] = a[getid(l, mid)].Mul(a[getid(mid+1, r)])
	}
	build(0, n-2)
	modify := func(l, r, k int) {
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
		a[getid(l, r)] = a[getid(l, mid)].Mul(a[getid(mid+1, r)])
	}
	events := make([][2]int, 3*(n-1))
	for i := 0; i < n-1; i++ {
		d := x[i+1] - x[i]
		events[i*3] = [2]int{d, v[i+1] + v[i]}
		if v[i] < v[i+1] {
			events[i*3+1] = [2]int{d, v[i+1] - v[i]}
		} else {
			events[i*3+1] = [2]int{1, 0}
		}
		if v[i] > v[i+1] {
			events[i*3+2] = [2]int{d, v[i] - v[i+1]}
		} else {
			events[i*3+2] = [2]int{1, 0}
		}
	}
	sort.Slice(events, func(i, j int) bool {
		return events[i][0]*events[j][1] < events[j][0]*events[i][1]
	})
	prevProb := getProb(p[0], &a[getid(0, n-2)])
	ans := Mint(0)
	for i := len(events) - 1; i >= 0; i-- {
		d := events[i][0]
		v := events[i][1]
		k := i / 3
		dir1 := i%3 == 1
		dir2 := i%3 == 2
		id2[k][dir1][dir2] = p[k+1]
		modify(0, n-2, k)
		prob := getProb(p[0], &a[getid(0, n-2)])
		if v != 0 {
			ans += prob.Sub(prevProb).Mul(Mint(d).Div(Mint(v)))
		}
		prevProb = prob
	}
	fmt.Println(ans)
}
