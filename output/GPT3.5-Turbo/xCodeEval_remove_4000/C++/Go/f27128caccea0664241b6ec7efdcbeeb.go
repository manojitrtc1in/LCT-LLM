package main

import (
	"fmt"
)

type Mint struct {
	value int
}

func inverse(a, m int) int {
	u, v := 0, 1
	for a != 0 {
		t := m / a
		m -= t * a
		a, m = m, a
		u -= t * v
		u, v = v, u
	}
	return u
}

type id0 struct {
	node []struct {
		w  int
		Wp Mint
		fp Mint
		tp Mint
	}
}

func (i *id0) unite(a, b struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
} {
	res := struct {
		w  int
		Wp Mint
		fp Mint
		tp Mint
	}{}
	res.w = a.w + b.w
	res.Wp = a.Wp + b.Wp
	res.fp = a.fp + b.fp
	res.tp = a.tp + b.tp
	return res
}

func (i *id0) push(x, l, r int) {

}

func (i *id0) pull(x, z int) {
	i.node[x] = i.unite(i.node[x+1], i.node[z])
}

func (i *id0) build(x, l, r int) {
	if l == r {
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	i.build(x+1, l, y)
	i.build(z, y+1, r)
	i.pull(x, z)
}

func (i *id0) buildWithValues(x, l, r int, v, a []int) {
	if l == r {
		i.node[x].apply(l, r, v[l], l, n-1-r, a[l])
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	i.buildWithValues(x+1, l, y, v, a)
	i.buildWithValues(z, y+1, r, v, a)
	i.pull(x, z)
}

func (i *id0) get(x, l, r, ll, rr int) struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
} {
	if ll <= l && r <= rr {
		return i.node[x]
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	i.push(x, l, r)
	res := struct {
		w  int
		Wp Mint
		fp Mint
		tp Mint
	}{}
	if rr <= y {
		res = i.get(x+1, l, y, ll, rr)
	} else {
		if ll > y {
			res = i.get(z, y+1, r, ll, rr)
		} else {
			res = i.unite(i.get(x+1, l, y, ll, rr), i.get(z, y+1, r, ll, rr))
		}
	}
	i.pull(x, z)
	return res
}

func (i *id0) modify(x, l, r, ll, rr, v, id, rid, a int) {
	if ll <= l && r <= rr {
		i.node[x].apply(l, r, v, id, rid, a)
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	i.push(x, l, r)
	if ll <= y {
		i.modify(x+1, l, y, ll, rr, v, id, rid, a)
	}
	if rr > y {
		i.modify(z, y+1, r, ll, rr, v, id, rid, a)
	}
	i.pull(x, z)
}

func (i *id0) findFirstKnowingly(x, l, r int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	if l == r {
		return l
	}
	i.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if f(i.node[x+1]) {
		res = i.findFirstKnowingly(x+1, l, y, f)
	} else {
		res = i.findFirstKnowingly(z, y+1, r, f)
	}
	i.pull(x, z)
	return res
}

func (i *id0) findFirst(x, l, r, ll, rr int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	if ll <= l && r <= rr {
		if !f(i.node[x]) {
			return -1
		}
		return i.findFirstKnowingly(x, l, r, f)
	}
	i.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	res := -1
	if ll <= y {
		res = i.findFirst(x+1, l, y, ll, rr, f)
	}
	if rr > y && res == -1 {
		res = i.findFirst(z, y+1, r, ll, rr, f)
	}
	i.pull(x, z)
	return res
}

func (i *id0) findLastKnowingly(x, l, r int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	if l == r {
		return l
	}
	i.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if f(i.node[z]) {
		res = i.findLastKnowingly(z, y+1, r, f)
	} else {
		res = i.findLastKnowingly(x+1, l, y, f)
	}
	i.pull(x, z)
	return res
}

func (i *id0) findLast(x, l, r, ll, rr int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	if ll <= l && r <= rr {
		if !f(i.node[x]) {
			return -1
		}
		return i.findLastKnowingly(x, l, r, f)
	}
	i.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	res := -1
	if rr > y {
		res = i.findLast(z, y+1, r, ll, rr, f)
	}
	if ll <= y && res == -1 {
		res = i.findLast(x+1, l, y, ll, rr, f)
	}
	i.pull(x, z)
	return res
}

func (i *id0) findFirst(ll, rr int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	return i.findFirst(0, 0, n-1, ll, rr, f)
}

func (i *id0) findLast(ll, rr int, f func(struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}) bool) int {
	return i.findLast(0, 0, n-1, ll, rr, f)
}

func (i *id0) apply(l, r, v, id, rid, a int) {
	i.node[l].w = v
	i.node[l].Wp = Mint(v) * a
	i.node[l].fp = Mint(v) * id
	i.node[l].tp = Mint(v) * rid
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	st := id0{}
	st.node = make([]struct {
		w  int
		Wp Mint
		fp Mint
		tp Mint
	}, 2*n-1)
	st.buildWithValues(0, 0, n-1, w, a)
	for q > 0 {
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			x = -x
			x--
			st.modify(x, x, y, x, n-1-x, a[x])
		} else {
			x--
			y--
			v := 0
			sum := st.get(x, y).w
			pos := st.findFirst(x, y, func(a struct {
				w  int
				Wp Mint
				fp Mint
				tp Mint
			}) bool {
				if (v+a.w)*2 >= sum {
					return true
				}
				v += a.w
				return false
			})
			l := st.get(x, pos)
			r := st.get(pos, y)
			res := Mint(0)
			res += r.Wp - r.fp - Mint(a[pos]-pos)*r.w
			res += Mint(a[pos]-pos)*l.w + l.fp - l.Wp
			fmt.Println(res)
		}
		q--
	}
}
