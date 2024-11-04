package main

import (
	"fmt"
	"math/big"
	"sort"
)

type Modular struct {
	value *big.Int
	mod   *big.Int
}

func NewModular(x, m *big.Int) *Modular {
	return &Modular{value: new(big.Int).Mod(x, m), mod: m}
}

func (m *Modular) Add(other *Modular) *Modular {
	return NewModular(new(big.Int).Add(m.value, other.value), m.mod)
}

func (m *Modular) Sub(other *Modular) *Modular {
	return NewModular(new(big.Int).Sub(m.value, other.value), m.mod)
}

func (m *Modular) Mul(other *Modular) *Modular {
	return NewModular(new(big.Int).Mul(m.value, other.value), m.mod)
}

func (m *Modular) Inv() *Modular {
	return NewModular(new(big.Int).ModInverse(m.value, m.mod), m.mod)
}

func (m *Modular) Div(other *Modular) *Modular {
	return m.Mul(other.Inv())
}

func (m *Modular) String() string {
	return m.value.String()
}

type Frac struct {
	p, q int64
}

func (f Frac) Less(other Frac) bool {
	return f.p*other.q < f.q*other.p
}

func getMid(l, r int) int {
	return l + (r-l)/2
}

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println(0)
		return
	}

	x := make([]int64, n)
	v := make([]int64, n)
	p := make([]*Modular, n)
	inv100 := NewModular(big.NewInt(1), big.NewInt(100))

	for i := 0; i < n; i++ {
		var xi, vi, pi int64
		fmt.Scan(&xi, &vi, &pi)
		x[i] = xi
		v[i] = vi
		p[i] = NewModular(big.NewInt(pi), big.NewInt(100))
	}

	allowedCollisions := make([]*Mat, n-1)
	for i := 0; i < n-1; i++ {
		allowedCollisions[i] = &Mat{[2][2]*Modular{nil, nil}, [2][2]*Modular{nil, nil}}
		allowedCollisions[i][0][1] = p[i+1]
	}

	a := make([]*Mat, 2*(n-1)-1)
	getProb := func(toRight *Modular, mat *Mat) *Modular {
		return toRight.Mul(mat[1][0].Add(mat[1][1])).Add(new(Modular).Sub(big.NewInt(1), toRight).Mul(mat[0][0].Add(mat[0][1])))
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
		a[getId(l, r)] = a[getId(l, mid)].Mul(a[getId(mid+1, r)])
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
		a[getId(l, r)] = a[getId(l, mid)].Mul(a[getId(mid+1, r)])
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
		}{Frac{d, v[i+1] + v[i]}, i<<2 | 1}
		events[i*3+1] = struct {
			frac Frac
			id   int
		}{Frac{0, 1}, i<<2 | 0}
		events[i*3+2] = struct {
			frac Frac
			id   int
		}{Frac{0, 1}, i<<2 | 3}
	}

	sort.Slice(events, func(i, j int) bool {
		return events[i].frac.Less(events[j].frac)
	})

	prevProb := getProb(p[0], a[getId(0, n-2)])
	ans := new(Modular)

	for i := len(events) - 1; i >= 0; i-- {
		event := events[i]
		i := event.id >> 2
		dir1 := getBit(event.id, 0)
		dir2 := getBit(event.id, 1)

		if dir2 == 1 {
			allowedCollisions[i][dir1][dir2] = p[i+1]
		} else {
			allowedCollisions[i][dir1][dir2] = new(Modular).Sub(big.NewInt(1), p[i+1])
		}
		modify(0, n-2, i)
		prob := getProb(p[0], a[getId(0, n-2)])
		if event.frac.q != 0 {
			ans.Add(prob.Sub(prevProb).Mul(event.frac))
		}
		prevProb = prob
	}

	fmt.Println(ans)
}
