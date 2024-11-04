package main

import (
	"fmt"
	"math/big"
)

type Modular struct {
	value *big.Int
	mod   *big.Int
}

func NewModular(value, mod int64) *Modular {
	m := new(big.Int).SetInt64(mod)
	v := new(big.Int).SetInt64(value)
	v.Mod(v, m)
	if v.Sign() < 0 {
		v.Add(v, m)
	}
	return &Modular{value: v, mod: m}
}

func (m *Modular) Add(other *Modular) *Modular {
	result := new(big.Int).Set(m.value)
	result.Add(result, other.value)
	result.Mod(result, m.mod)
	return &Modular{value: result, mod: m.mod}
}

func (m *Modular) Sub(other *Modular) *Modular {
	result := new(big.Int).Set(m.value)
	result.Sub(result, other.value)
	result.Mod(result, m.mod)
	return &Modular{value: result, mod: m.mod}
}

func (m *Modular) Mul(other *Modular) *Modular {
	result := new(big.Int).Set(m.value)
	result.Mul(result, other.value)
	result.Mod(result, m.mod)
	return &Modular{value: result, mod: m.mod}
}

func (m *Modular) Inverse() *Modular {
	a := new(big.Int).Set(m.value)
	mm := new(big.Int).Set(m.mod)
	u, v := big.NewInt(0), big.NewInt(1)

	for a.Sign() != 0 {
		t := new(big.Int).Div(mm, a)
		mm.Sub(mm, new(big.Int).Mul(t, a))
		a, mm = mm, a
		u.Sub(u, new(big.Int).Mul(t, v))
		u, v = v, u
	}
	if mm.Cmp(big.NewInt(1)) != 0 {
		panic("modular inverse does not exist")
	}
	if u.Sign() < 0 {
		u.Add(u, m.mod)
	}
	return &Modular{value: u, mod: m.mod}
}

type Node struct {
	w  int64
	Wp *Modular
	fp *Modular
	tp *Modular
}

type Id0 struct {
	n    int
	tree []Node
}

func (id *Id0) Unite(a, b Node) Node {
	return Node{
		w:  a.w + b.w,
		Wp: a.Wp.Add(b.Wp),
		fp: a.fp.Add(b.fp),
		tp: a.tp.Add(b.tp),
	}
}

func (id *Id0) Build(x, l, r int, v, a []int64) {
	if l == r {
		id.tree[x] = Node{
			w:  v[l],
			Wp: NewModular(v[l], 1e9+7).Mul(NewModular(a[l], 1e9+7)),
			fp: NewModular(v[l], 1e9+7).Mul(NewModular(int64(x), 1e9+7)),
			tp: NewModular(v[l], 1e9+7).Mul(NewModular(int64(id.n-1-r), 1e9+7)),
		}
		return
	}
	y := (l + r) >> 1
	id.Build(x+1, l, y, v, a)
	id.Build(x+((y-l+1)<<1), y+1, r, v, a)
	id.tree[x] = id.Unite(id.tree[x+1], id.tree[x+((y-l+1)<<1)])
}

func (id *Id0) Get(x, l, r, ll, rr int) Node {
	if ll <= l && r <= rr {
		return id.tree[x]
	}
	y := (l + r) >> 1
	res := Node{}
	if rr <= y {
		res = id.Get(x+1, l, y, ll, rr)
	} else if ll > y {
		res = id.Get(x+((y-l+1)<<1), y+1, r, ll, rr)
	} else {
		res = id.Unite(id.Get(x+1, l, y, ll, rr), id.Get(x+((y-l+1)<<1), y+1, r, ll, rr))
	}
	return res
}

func (id *Id0) Modify(x, l, r, ll, rr int, v, idVal, rid, a int64) {
	if ll <= l && r <= rr {
		id.tree[x] = Node{
			w:  v,
			Wp: NewModular(v, 1e9+7).Mul(NewModular(a, 1e9+7)),
			fp: NewModular(v, 1e9+7).Mul(NewModular(idVal, 1e9+7)),
			tp: NewModular(v, 1e9+7).Mul(NewModular(rid, 1e9+7)),
		}
		return
	}
	y := (l + r) >> 1
	if ll <= y {
		id.Modify(x+1, l, y, ll, rr, v, idVal, rid, a)
	}
	if rr > y {
		id.Modify(x+((y-l+1)<<1), y+1, r, ll, rr, v, idVal, rid, a)
	}
	id.tree[x] = id.Unite(id.tree[x+1], id.tree[x+((y-l+1)<<1)])
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int64, n)
	w := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	st := Id0{n: n, tree: make([]Node, 2*n-1)}
	st.Build(0, 0, n-1, w, a)

	for q > 0 {
		q--
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			x = -x - 1
			st.Modify(x, x, x, x, n-1-x, y, int64(x), int64(n-1-x), a[x])
		} else {
			x--
			y--
			sum := st.Get(0, 0, n-1, x, y).w
			v := int64(0)
			pos := -1
			for i := x; i <= y; i++ {
				if (v+a[i])*2 >= sum {
					pos = i
					break
				}
				v += a[i]
			}
			if pos == -1 {
				panic("position not found")
			}
			l := st.Get(0, 0, n-1, x, pos)
			r := st.Get(0, 0, n-1, pos, y)
			res := NewModular(0, 1e9+7)
			res = res.Add(r.Wp).Sub(r.fp).Sub(NewModular(a[pos]-pos, 1e9+7).Mul(r))
			res = res.Add(NewModular(a[pos]-pos, 1e9+7).Mul(l)).Add(l.fp).Sub(l.Wp)
			fmt.Println(res.value.String())
		}
	}
}
