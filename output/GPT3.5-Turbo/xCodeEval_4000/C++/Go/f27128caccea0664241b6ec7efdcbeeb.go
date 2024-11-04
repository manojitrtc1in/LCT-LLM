package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const md = int(1e9) + 7

type Mint struct {
	value int
}

func NewMint(x int) Mint {
	return Mint{normalize(x)}
}

func normalize(x int) int {
	v := x % md
	if v < 0 {
		v += md
	}
	return v
}

func (m Mint) Add(other Mint) Mint {
	return NewMint(m.value + other.value)
}

func (m Mint) Subtract(other Mint) Mint {
	return NewMint(m.value - other.value)
}

func (m Mint) Multiply(other Mint) Mint {
	return NewMint(m.value * other.value)
}

func (m Mint) Divide(other Mint) Mint {
	return m.Multiply(other.Inverse())
}

func (m Mint) Inverse() Mint {
	u, v := 0, 1
	a, b := m.value, md
	for a != 0 {
		t := b / a
		b -= t * a
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	return NewMint(u)
}

func (m Mint) Power(b int) Mint {
	res := NewMint(1)
	x := m
	for b > 0 {
		if b&1 == 1 {
			res = res.Multiply(x)
		}
		x = x.Multiply(x)
		b >>= 1
	}
	return res
}

func (m Mint) String() string {
	return strconv.Itoa(m.value)
}

type segtree struct {
	n    int
	tree []node
}

type node struct {
	w  int
	Wp Mint
	fp Mint
	tp Mint
}

func (s *segtree) unite(a, b node) node {
	res := node{}
	res.w = a.w + b.w
	res.Wp = a.Wp.Add(b.Wp)
	res.fp = a.fp.Add(b.fp)
	res.tp = a.tp.Add(b.tp)
	return res
}

func (s *segtree) push(x, l, r int) {

}

func (s *segtree) pull(x, z int) {
	s.tree[x] = s.unite(s.tree[x+1], s.tree[z])
}

func (s *segtree) build(x, l, r int) {
	if l == r {
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	s.build(x+1, l, y)
	s.build(z, y+1, r)
	s.pull(x, z)
}

func (s *segtree) buildWithValues(x, l, r int, v, a []int) {
	if l == r {
		s.tree[x].apply(l, r, v[l], l, s.n-1-r, a[l])
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	s.buildWithValues(x+1, l, y, v, a)
	s.buildWithValues(z, y+1, r, v, a)
	s.pull(x, z)
}

func (s *segtree) get(x, l, r, ll, rr int) node {
	if ll <= l && r <= rr {
		return s.tree[x]
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	s.push(x, l, r)
	var res node
	if rr <= y {
		res = s.get(x+1, l, y, ll, rr)
	} else {
		if ll > y {
			res = s.get(z, y+1, r, ll, rr)
		} else {
			res = s.unite(s.get(x+1, l, y, ll, rr), s.get(z, y+1, r, ll, rr))
		}
	}
	s.pull(x, z)
	return res
}

func (s *segtree) modify(x, l, r, ll, rr, v, id, rid, a int) {
	if ll <= l && r <= rr {
		s.tree[x].apply(l, r, v, id, rid, a)
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	s.push(x, l, r)
	if ll <= y {
		s.modify(x+1, l, y, ll, rr, v, id, rid, a)
	}
	if rr > y {
		s.modify(z, y+1, r, ll, rr, v, id, rid, a)
	}
	s.pull(x, z)
}

func (s *segtree) findFirstKnowingly(x, l, r int, f func(node) bool) int {
	if l == r {
		return l
	}
	s.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if f(s.tree[x+1]) {
		res = s.findFirstKnowingly(x+1, l, y, f)
	} else {
		res = s.findFirstKnowingly(z, y+1, r, f)
	}
	s.pull(x, z)
	return res
}

func (s *segtree) findFirst(x, l, r, ll, rr int, f func(node) bool) int {
	if ll <= l && r <= rr {
		if !f(s.tree[x]) {
			return -1
		}
		return s.findFirstKnowingly(x, l, r, f)
	}
	s.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if ll <= y {
		res = s.findFirst(x+1, l, y, ll, rr, f)
	}
	if rr > y && res == -1 {
		res = s.findFirst(z, y+1, r, ll, rr, f)
	}
	s.pull(x, z)
	return res
}

func (s *segtree) findLastKnowingly(x, l, r int, f func(node) bool) int {
	if l == r {
		return l
	}
	s.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if f(s.tree[z]) {
		res = s.findLastKnowingly(z, y+1, r, f)
	} else {
		res = s.findLastKnowingly(x+1, l, y, f)
	}
	s.pull(x, z)
	return res
}

func (s *segtree) findLast(x, l, r, ll, rr int, f func(node) bool) int {
	if ll <= l && r <= rr {
		if !f(s.tree[x]) {
			return -1
		}
		return s.findLastKnowingly(x, l, r, f)
	}
	s.push(x, l, r)
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	var res int
	if rr > y {
		res = s.findLast(z, y+1, r, ll, rr, f)
	}
	if ll <= y && res == -1 {
		res = s.findLast(x+1, l, y, ll, rr, f)
	}
	s.pull(x, z)
	return res
}

func newSegtree(n int) *segtree {
	s := &segtree{n: n}
	s.tree = make([]node, 2*n-1)
	s.build(0, 0, n-1)
	return s
}

func (n *node) apply(l, r, v, id, rid, a int) {
	n.w = v
	n.Wp = NewMint(v).Multiply(NewMint(a))
	n.fp = NewMint(v).Multiply(NewMint(id))
	n.tp = NewMint(v).Multiply(NewMint(rid))
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n)
	w := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	for i := 0; i < n; i++ {
		scanner.Scan()
		w[i], _ = strconv.Atoi(scanner.Text())
	}

	st := newSegtree(n)

	for i := 0; i < q; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())

		if x < 0 {
			x = -x
			x--
			st.modify(x, x, y, x, n-1-x, a[x])
		} else {
			x--
			y--
			v := 0
			sum := st.get(x, y).w
			pos := st.findFirst(x, y, func(a node) bool {
				if (v+a.w)*2 >= sum {
					return true
				}
				v += a.w
				return false
			})
			l := st.get(x, pos)
			r := st.get(pos, y)
			res := NewMint(0)

			res = res.Add(r.Wp).Subtract(r.fp).Subtract(NewMint(a[pos]-pos).Multiply(NewMint(r.w)))

			res = res.Add(NewMint(a[pos]-pos).Multiply(NewMint(l.w))).Add(l.fp).Subtract(l.Wp)

			fmt.Println(res)
		}
	}
}
