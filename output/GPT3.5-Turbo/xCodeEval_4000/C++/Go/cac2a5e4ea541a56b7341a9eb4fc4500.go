package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type Mint int

func NewMint(x int) Mint {
	return Mint(x % mod)
}

func (m Mint) Add(x Mint) Mint {
	return Mint((int(m) + int(x)) % mod)
}

func (m Mint) Sub(x Mint) Mint {
	return Mint((int(m) - int(x) + mod) % mod)
}

func (m Mint) Mul(x Mint) Mint {
	return Mint((int(m) * int(x)) % mod)
}

func (m Mint) Pow(n int) Mint {
	if n == 0 {
		return Mint(1)
	}
	res := Mint(1)
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(m)
		}
		m = m.Mul(m)
		n >>= 1
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(mod - 2)
}

func (m Mint) Div(x Mint) Mint {
	return m.Mul(x.Inv())
}

func (m Mint) Neg() Mint {
	return Mint(-int(m))
}

func (m Mint) Equal(x Mint) bool {
	return int(m) == int(x)
}

func (m Mint) Less(x Mint) bool {
	return int(m) < int(x)
}

func (m Mint) String() string {
	return fmt.Sprintf("%d", int(m))
}

type Frac struct {
	P, Q int
}

func NewFrac(p, q int) Frac {
	return Frac{p, q}
}

func (f Frac) Add(x Frac) Frac {
	return Frac{f.P*x.Q + f.Q*x.P, f.Q * x.Q}
}

func (f Frac) Sub(x Frac) Frac {
	return Frac{f.P*x.Q - f.Q*x.P, f.Q * x.Q}
}

func (f Frac) Mul(x Frac) Frac {
	return Frac{f.P * x.P, f.Q * x.Q}
}

func (f Frac) Div(x Frac) Frac {
	return Frac{f.P * x.Q, f.Q * x.P}
}

func (f Frac) Less(x Frac) bool {
	return f.P*x.Q < f.Q*x.P
}

func (f Frac) String() string {
	return fmt.Sprintf("%d/%d", f.P, f.Q)
}

type Mat [2][2]Mint

func NewMat() Mat {
	return Mat{}
}

func (m Mat) Mul(b Mat) Mat {
	c := NewMat()
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				c[i][j] = c[i][j].Add(m[i][k].Mul(b[k][j]))
			}
		}
	}
	return c
}

func (m Mat) String() string {
	return fmt.Sprintf("%v\n%v", m[0], m[1])
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
	inv100 := NewMint(100).Inv()
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &v[i], &p[i])
		p[i] = p[i].Mul(inv100)
	}

	allowedCollisions := make([]Mat, n-1)
	for i := 0; i < n-1; i++ {
		allowedCollisions[i][0][1] = p[i+1]
	}

	a := make([]Mat, 2*(n-1)-1)
	getProb := func(toRight Mint, mat *Mat) Mint {
		return toRight.Mul(mat[1][0].Add(mat[1][1])).Add(Mint(1).Sub(toRight).Mul(mat[0][0].Add(mat[0][1])))
	}
	var build func(l, r int)
	build = func(l, r int) {
		if l == r {
			a[2*l] = allowedCollisions[l]
			return
		}
		mid := (l + r) / 2
		build(l, mid)
		build(mid+1, r)
		a[getID(l, r)] = a[getID(l, mid)].Mul(a[getID(mid+1, r)])
	}
	build(0, n-2)
	var modify func(l, r, k int)
	modify = func(l, r, k int) {
		if l == r {
			a[2*l] = allowedCollisions[k]
			return
		}
		mid := (l + r) / 2
		if k <= mid {
			modify(l, mid, k)
		} else {
			modify(mid+1, r, k)
		}
		a[getID(l, r)] = a[getID(l, mid)].Mul(a[getID(mid+1, r)])
	}

	events := make([][2]Frac, 3*(n-1))
	for i := 0; i < n-1; i++ {
		d := x[i+1] - x[i]
		events[i*3] = [2]Frac{{d, v[i+1] + v[i]}, Frac{i << 2 | 1, 0}}
		events[i*3+1] = [2]Frac{{d, v[i+1] - v[i]}, Frac{i << 2 | 0, 0}}
		events[i*3+2] = [2]Frac{{d, v[i] - v[i+1]}, Frac{i << 2 | 3, 0}}
	}
	sortEvents(events)
	prevProb := getProb(p[0], &a[getID(0, n-2)])
	ans := Mint(0)
	for _, event := range reverseEvents(events) {
		i := event[1].P >> 2
		dir1 := getBit(event[1].P, 0)
		dir2 := getBit(event[1].P, 1)
		allowedCollisions[i][dir1][dir2] = p[i+1]
		modify(0, n-2, i)
		prob := getProb(p[0], &a[getID(0, n-2)])
		if event[0].Q != 0 {
			ans = ans.Add(prob.Sub(prevProb).Mul(Mint(event[0].P).Div(Mint(event[0].Q))))
		}
		prevProb = prob
	}
	fmt.Println(ans)
}

func getID(l, r int) int {
	return l + r | bool(l != r)
}

func sortEvents(events [][2]Frac) {
	sort.Slice(events, func(i, j int) bool {
		return events[i][0].Less(events[j][0])
	})
}

func reverseEvents(events [][2]Frac) [][2]Frac {
	res := make([][2]Frac, len(events))
	for i := 0; i < len(events); i++ {
		res[i] = events[len(events)-1-i]
	}
	return res
}

func getBit(a int, i uint) int {
	return a >> i & 1
}
