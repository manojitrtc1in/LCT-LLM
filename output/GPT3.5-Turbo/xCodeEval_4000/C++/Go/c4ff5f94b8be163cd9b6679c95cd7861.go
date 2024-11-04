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

type Mat [2][2]Mint

func NewMat() Mat {
	return Mat{}
}

func (m Mat) Mul(x Mat) Mat {
	res := NewMat()
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				res[i][j] = res[i][j].Add(m[i][k].Mul(x[k][j]))
			}
		}
	}
	return res
}

func (m Mat) Pow(n int) Mat {
	res := NewMat()
	for i := 0; i < 2; i++ {
		res[i][i] = 1
	}
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(m)
		}
		m = m.Mul(m)
		n >>= 1
	}
	return res
}

type Frac struct {
	p, q int
}

func NewFrac(p, q int) Frac {
	return Frac{p, q}
}

func (f Frac) Less(x Frac) bool {
	return f.p*x.q < x.p*f.q
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
	build := func(l, r int) {
		if l == r {
			a[2*l] = allowedCollisions[l]
			return
		}
		mid := (l + r) / 2
		build(l, mid)
		build(mid+1, r)
		a[(l+r)/2] = a[l].Mul(a[mid+1])
	}
	build(0, n-2)
	modify := func(l, r, k int) {
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
		a[(l+r)/2] = a[l].Mul(a[mid+1])
	}

	events := make([]struct {
		frac Frac
		id   int
	}, 3*(n-1))
	for i := 0; i < n-1; i++ {
		d := x[i+1] - x[i]
		events[i*3] = struct {
			frac Frac
			id   int
		}{NewFrac(d, v[i+1]+v[i]), i<<2 | 1}
		events[i*3+1] = struct {
			frac Frac
			id   int
		}{NewFrac(d, int(math.Abs(float64(v[i+1]-v[i])))), i<<2 | 0}
		events[i*3+2] = struct {
			frac Frac
			id   int
		}{NewFrac(d, int(math.Abs(float64(v[i]-v[i+1])))), i<<2 | 3}
	}

	sortEvents := func() {
		sort.Slice(events, func(i, j int) bool {
			return events[i].frac.Less(events[j].frac)
		})
	}
	sortEvents()

	prevProb := getProb(p[0], &a[get_id(0, n-2)])
	ans := Mint(0)
	for i := len(events) - 1; i >= 0; i-- {
		event := events[i]
		id := event.id >> 2
		dir1 := (event.id >> 0) & 1
		dir2 := (event.id >> 1) & 1
		allowedCollisions[id][dir1][dir2] = p[id+1]
		modify(0, n-2, id)
		prob := getProb(p[0], &a[get_id(0, n-2)])
		if event.frac.q != 0 {
			ans = ans.Add(prob.Sub(prevProb).Mul(Mint(event.frac.p).Div(Mint(event.frac.q))))
		}
		prevProb = prob
	}

	fmt.Println(ans)
}
