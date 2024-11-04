package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	br       *bufio.Reader
	st       []string
	tokenIdx int
}

func NewFastScanner(f *os.File) *FastScanner {
	return &FastScanner{
		br: bufio.NewReader(f),
	}
}

func (fs *FastScanner) nextLine() string {
	str, _ := fs.br.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func (fs *FastScanner) next() string {
	if fs.tokenIdx >= len(fs.st) {
		fs.tokenIdx = 0
		fs.st = strings.Split(fs.nextLine(), " ")
	}
	fs.tokenIdx++
	return fs.st[fs.tokenIdx-1]
}

func (fs *FastScanner) nextInt() int {
	num, _ := strconv.Atoi(fs.next())
	return num
}

func (fs *FastScanner) nextLong() int64 {
	num, _ := strconv.ParseInt(fs.next(), 10, 64)
	return num
}

func (fs *FastScanner) nextDouble() float64 {
	num, _ := strconv.ParseFloat(fs.next(), 64)
	return num
}

type DSU struct {
	sz []int
	p  []int
}

func NewDSU(n int) *DSU {
	sz := make([]int, n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		sz[i] = 1
	}
	return &DSU{
		sz: sz,
		p:  p,
	}
}

func (dsu *DSU) get(x int) int {
	if x == dsu.p[x] {
		return x
	}
	par := dsu.get(dsu.p[x])
	dsu.p[x] = par
	return par
}

func (dsu *DSU) unite(a, b int) bool {
	pa := dsu.get(a)
	pb := dsu.get(b)
	if pa == pb {
		return false
	}
	if dsu.sz[pa] < dsu.sz[pb] {
		dsu.p[pa] = pb
		dsu.sz[pb] += dsu.sz[pa]
	} else {
		dsu.p[pb] = pa
		dsu.sz[pa] += dsu.sz[pb]
	}
	return true
}

type SegmentTreeAdd struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func NewSegmentTreeAdd(a []int64) *SegmentTreeAdd {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	flag := make([]bool, 2*pow)
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	for i := 0; i < len(max); i++ {
		max[i] = int64(-1e18)
	}
	for i := 0; i < len(a); i++ {
		max[pow+i] = a[i]
	}
	for i := pow - 1; i > 0; i-- {
		max[i] = f(max[2*i], max[2*i+1])
	}
	return &SegmentTreeAdd{
		pow:   pow,
		max:   max,
		delta: delta,
		flag:  flag,
	}
}

func (st *SegmentTreeAdd) get(v, tl, tr, l, r int) int64 {
	st.push(v, tl, tr)
	if l > r {
		return int64(-1e18)
	}
	if l == tl && r == tr {
		return st.max[v]
	}
	tm := (tl + tr) / 2
	return f(st.get(2*v, tl, tm, l, min(r, tm)), st.get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (st *SegmentTreeAdd) set(v, tl, tr, l, r int, x int64) {
	st.push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		st.delta[v] += x
		st.flag[v] = true
		st.push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	st.set(2*v, tl, tm, l, r, x)
	st.set(2*v+1, tm+1, tr, l, r, x)
	st.max[v] = f(st.max[2*v], st.max[2*v+1])
}

func (st *SegmentTreeAdd) push(v, tl, tr int) {
	if st.flag[v] {
		if v < st.pow {
			st.flag[2*v] = true
			st.flag[2*v+1] = true
			st.delta[2*v] += st.delta[v]
			st.delta[2*v+1] += st.delta[v]
		}
		st.flag[v] = false
		st.max[v] += st.delta[v]
		st.delta[v] = 0
	}
}

func f(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	fs := NewFastScanner(os.Stdin)
	n := fs.nextInt()
	m := fs.nextInt()
	q := fs.nextInt()
	v := make([]int, n)
	inv := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = fs.nextInt()
		inv[v[i]-1] = i
	}
	a := make([]int, m)
	b := make([]int, m)
	for i := 0; i < m; i++ {
		a[i] = fs.nextInt() - 1
		b[i] = fs.nextInt() - 1
	}
	typeArr := make([]bool, q)
	x := make([]int, q)
	removed := make([]bool, m)
	for i := 0; i < q; i++ {
		if fs.nextInt() == 1 {
			x[i] = fs.nextInt() - 1
			typeArr[i] = true
		} else {
			x[i] = fs.nextInt() - 1
			removed[x[i]] = true
		}
	}
	dsu := NewDSU(n)
	for i := 0; i < m; i++ {
		if !removed[i] {
			dsu.unite(a[i], b[i])
		}
	}
	for i := q - 1; i >= 0; i-- {
		if !typeArr[i] {
			dsu.unite(a[x[i]], b[x[i]])
		}
	}
	for i := 0; i < q; i++ {
		if typeArr[i] {
			fmt.Println(dsu.poll(x[i]))
		} else {
			dsu.popEdge()
		}
	}
}

