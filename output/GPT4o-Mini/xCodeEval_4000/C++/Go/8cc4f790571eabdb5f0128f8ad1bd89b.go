package main

import (
	"fmt"
	"math/big"
	"sort"
)

type pipe struct {
	x, v, p int
}

type dir int

const (
	LL dir = iota
	RR
	RL
)

type event struct {
	i int
	d dir
	t *frac
}

type node struct {
	p     [4]*modnum
	noLL  bool
	noRR  bool
	noRL  bool
	none  bool
}

type frac struct {
	n, d int64
}

func newFrac(n, d int64) *frac {
	if n == 0 && d == 0 {
		panic("invalid fraction")
	}
	if d < 0 {
		n *= -1
		d *= -1
	}
	g := gcd(abs(n), d)
	return &frac{n / g, d / g}
}

func (f *frac) String() string {
	return fmt.Sprintf("%d/%d", f.n, f.d)
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

type modnum struct {
	v int
}

func newModnum(val int) *modnum {
	return &modnum{(val % 998244353 + 998244353) % 998244353}
}

func (m *modnum) add(o *modnum) *modnum {
	return newModnum(m.v + o.v)
}

func (m *modnum) sub(o *modnum) *modnum {
	return newModnum(m.v - o.v)
}

func (m *modnum) mul(o *modnum) *modnum {
	return newModnum(m.v * o.v)
}

func (m *modnum) String() string {
	return fmt.Sprintf("%d", m.v)
}

type segmentTree struct {
	SZ    int
	id    node
	tt    func(a, b node) node
	table []node
}

func newSegmentTree(sz int, id node, tt func(a, b node) node) *segmentTree {
	st := &segmentTree{SZ: sz, id: id, tt: tt}
	st.table = make([]node, 2*sz)
	return st
}

func (st *segmentTree) setLeaves(create func(i int) node) {
	for i := 0; i < st.SZ; i++ {
		st.table[st.SZ+i] = create(i)
	}
	for i := st.SZ - 1; i > 0; i-- {
		st.table[i] = st.tt(st.table[2*i], st.table[2*i+1])
	}
}

func (st *segmentTree) replace(i int, v node) {
	st.table[i+st.SZ] = v
	for i /= 2; i > 0; i /= 2 {
		st.table[i] = st.tt(st.table[2*i], st.table[2*i+1])
	}
}

func (st *segmentTree) query(i, j int) node {
	left, right := st.id, st.id
	for i += st.SZ; j += st.SZ; i < j {
		if i&1 != 0 {
			left = st.tt(left, st.table[i])
			i++
		}
		if j&1 != 0 {
			j--
			right = st.tt(st.table[j], right)
		}
		i /= 2
		j /= 2
	}
	return st.tt(left, right)
}

func main() {
	var N int
	fmt.Scan(&N)
	pipes := make([]pipe, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&pipes[i].x, &pipes[i].v, &pipes[i].p)
	}

	evs := []event{}
	for i := 0; i < N-1; i++ {
		dx := pipes[i+1].x - pipes[i].x
		dv := pipes[i+1].v - pipes[i].v

		evs = append(evs, event{i, RL, newFrac(int64(dx), int64(pipes[i+1].v+pipes[i].v))})

		if dv > 0 {
			evs = append(evs, event{i, LL, newFrac(int64(dx), int64(dv))})
		}
		if dv < 0 {
			evs = append(evs, event{i, RR, newFrac(int64(dx), int64(-dv))})
		}
	}
	sort.Slice(evs, func(i, j int) bool {
		return evs[i].t.n*evs[j].t.d < evs[j].t.n*evs[i].t.d
	})

	st := newSegmentTree(N, node{}, func(a, b node) node {
		if a.none {
			return b
		}
		if b.none {
			return a
		}
		r := b
		for i := 0; i < 4; i++ {
			for j := 0; j < 4; j++ {
				iF := i&1 != 0
				iB := (i>>1)&1 != 0
				jF := j&1 != 0
				jB := (j>>1)&1 != 0
				if a.noLL && !iB && !jF {
					continue
				}
				if a.noRR && iB && jF {
					continue
				}
				if a.noRL && iB && !jF {
					continue
				}
				r.p[iF+2*jB] = r.p[iF+2*jB].add(a.p[i].mul(b.p[j]))
			}
		}
		return r
	})

	st.setLeaves(func(i int) node {
		pR := newModnum(pipes[i].p * 100)
		r := node{}
		r.p = [4]*modnum{newModnum(1).sub(pR), newModnum(0), newModnum(0), pR}
		r.none = false
		return r
	})

	ans := newModnum(0)
	prob := newModnum(1)
	for _, e := range evs {
		c := st.table[e.i]
		switch e.d {
		case LL:
			c.noLL = true
		case RR:
			c.noRR = true
		case RL:
			c.noRL = true
		}
		st.replace(e.i, c)

		u := st.query(0, st.SZ)
		PROB := newModnum(0)
		for _, p := range u.p {
			PROB = PROB.add(p)
		}
		ans = ans.add(prob.sub(PROB).mul(newModnum(e.t.n).mul(newModnum(1).div(newModnum(e.t.d)))))
		prob = PROB
	}

	fmt.Println(ans)
}
