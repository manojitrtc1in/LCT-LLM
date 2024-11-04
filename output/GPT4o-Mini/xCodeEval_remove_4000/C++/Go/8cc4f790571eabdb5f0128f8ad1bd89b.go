package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
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
	t frac
}

type frac struct {
	n, d int64
}

func (f frac) String() string {
	return fmt.Sprintf("%d/%d", f.n, f.d)
}

func (f frac) lessThan(g frac) bool {
	return f.n*g.d < g.n*f.d
}

type node struct {
	p    [4]int64
	noLL bool
	noRR bool
	noRL bool
	none  bool
}

func combine(a, b node) node {
	if a.none {
		return b
	}
	if b.none {
		return a
	}
	r := b
	for i := 0; i < 4; i++ {
		r.p[i] = 0
	}
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			iF := i&1 == 1
			iB := (i>>1)&1 == 1
			jF := j&1 == 1
			jB := (j>>1)&1 == 1
			if a.noLL && !iB && !jF {
				continue
			}
			if a.noRR && iB && jF {
				continue
			}
			if a.noRL && iB && !jF {
				continue
			}
			r.p[iF+2*jB] += a.p[i] * b.p[j]
		}
	}
	return r
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

func (st *segmentTree) id1(create func(int) node) {
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
	for i, j = i+st.SZ, j+st.SZ; i < j; i /= 2 {
		if i&1 == 1 {
			left = st.tt(left, st.table[i])
			i++
		}
		if j&1 == 1 {
			j--
			right = st.tt(st.table[j], right)
		}
	}
	return st.tt(left, right)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)
	pipes := make([]pipe, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &pipes[i].x, &pipes[i].v, &pipes[i].p)
	}

	evs := []event{}
	for i := 0; i < N-1; i++ {
		dx := pipes[i+1].x - pipes[i].x
		dv := pipes[i+1].v - pipes[i].v

		evs = append(evs, event{i, RL, frac{int64(dx), int64(pipes[i+1].v + pipes[i].v)}})

		if dv > 0 {
			evs = append(evs, event{i, LL, frac{int64(dx), int64(dv)}})
		}
		if dv < 0 {
			evs = append(evs, event{i, RR, frac{int64(dx), -int64(dv)}})
		}
	}
	sort.Slice(evs, func(i, j int) bool {
		return evs[i].t.lessThan(evs[j].t)
	})

	st := newSegmentTree(N, node{}, combine)
	st.id1(func(i int) node {
		pR := int64(pipes[i].p) * (1 << 30) / 100
		r := node{}
		r.p = [4]int64{1 - pR, 0, 0, pR}
		r.none = false
		return r
	})

	var ans, prob int64
	prob = 1
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
		PROB := u.p[0] + u.p[1] + u.p[2] + u.p[3]
		ans += (prob - PROB) * e.t.n / e.t.d
		prob = PROB
	}

	fmt.Fprintln(writer, ans)
}
