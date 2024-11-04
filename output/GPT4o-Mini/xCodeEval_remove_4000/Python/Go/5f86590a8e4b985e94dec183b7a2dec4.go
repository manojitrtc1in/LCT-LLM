package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Node struct {
	key   int
	value int
	prev  *Node
	next  *Node
}

func (n *Node) connect(node *Node) *Node {
	n.next = node
	node.prev = n
	return node
}

func (n *Node) splice(fragment *Node) *Node {
	if fragment.prev != nil {
		fragment.prev.next = nil
	}

	u := n
	v := fragment
	w := n.next

	u.connect(v)
	for v.next != nil {
		v = v.next
	}
	v.connect(w)

	return v
}

func (n *Node) splice1(node *Node) {
	node.connect(n.next)
	n.connect(node)
}

func (n *Node) eject() {
	n.prev.connect(n.next)
}

func (n *Node) iterate() <-chan *Node {
	ch := make(chan *Node)
	go func() {
		u := n
		for {
			ch <- u
			u = u.next
			if u == nil || u == n {
				break
			}
		}
		close(ch)
	}()
	return ch
}

type AbstractHeap interface {
	id6() bool
	id18() int
	id14(value int) bool
	id21(value int) int
	push(key, value int)
	pop() (int, int)
	id28(value, key int)
	merge(other AbstractHeap)
}

type id13 struct {
	Node
	key    int
	value  int
	parent *id13
	child  *id13
	degree int
	mark   bool
}

type id0 struct {
	_      int
	_n     int
	_root  *id13
	_index map[int]*id13
}

func NewId0(iterable []struct{ key, value int }) *id0 {
	h := &id0{
		_index: make(map[int]*id13),
	}
	for _, kv := range iterable {
		h.push(kv.key, kv.value)
	}
	return h
}

func (h *id0) id6() bool {
	return h._n > 0
}

func (h *id0) id18() int {
	return h._n
}

func (h *id0) id14(value int) bool {
	_, exists := h._index[value]
	return exists
}

func (h *id0) id21(value int) int {
	return h._index[value].key
}

func (h *id0) push(key, value int) {
	node := &id13{key: key, value: value}
	h._index[value] = node

	if h._root == nil {
		node.connect(node)
		h._root = node
		h._n = 1
	} else {
		h._root.splice1(node)
		if key < h._root.key {
			h._root = node
		}
		h._n++
	}
}

func (h *id0) pop() (int, int) {
	z := h._root

	if z.child != nil {
		for c := range z.child.iterate() {
			c.parent = nil
		}
		z.splice(z.child)
	}

	if z.next == z {
		h._root = nil
	} else {
		h._root = z.next
		z.eject()
		h.id31()
	}

	h._n--
	delete(h._index, z.value)
	return z.key, z.value
}

func (h *id0) id31() {
	A := make(map[int]*id13)
	for x := range h._root.iterate() {
		d := x.degree
		for {
			if _, exists := A[d]; !exists {
				break
			}
			y := A[d]
			if x.key > y.key {
				x, y = y, x
			}
			h._link(y, x)
			delete(A, d)
			d++
		}
		A[d] = x
	}

	i := 0
	for _, x := range A {
		if i == 0 {
			h._root = x
			h._root.connect(h._root)
		} else {
			h._root.splice1(x)
			if x.key < h._root.key {
				h._root = x
			}
		}
		i++
	}
}

func (h *id0) _link(y, x *id13) {
	y.eject()
	y.parent = x
	if x.child != nil {
		x.child.splice1(y)
	} else {
		x.child = y
		y.connect(y)
	}
	x.degree++
	y.mark = false
}

func (h *id0) id28(value, key int) {
	x := h._index[value]
	x.key = key
	delete(h._index, value)
	h._index[value] = x

	y := x.parent
	if y != nil && x.key < y.key {
		h._cut(x, y)
		h.id2(y)
	}

	if x.key < h._root.key {
		h._root = x
	}
}

func (h *id0) _cut(x, y *id13) {
	if x.next == x {
		y.child = nil
	} else {
		y.child = x.next
	}
	x.parent = nil
	x.eject()
	y.degree--

	h._root.splice1(x)
	x.mark = false
}

func (h *id0) id2(y *id13) {
	z := y.parent
	if z != nil {
		if !y.mark {
			y.mark = true
		} else {
			h._cut(y, z)
			h.id2(z)
		}
	}
}

func (h *id0) merge(other AbstractHeap) {
	if other == nil {
		return
	}

	if h != nil {
		h._root.splice(other.(*id0)._root)
		if other.(*id0)._root.key < h._root.key {
			h._root = other.(*id0)._root
		}
		for k, v := range other.(*id0)._index {
			h._index[k] = v
		}
	} else {
		h._root = other.(*id0)._root
		h._index = other.(*id0)._index
	}

	h._n += other.(*id0)._n
	other.(*id0)._root = nil
	other.(*id0)._n = 0
	other.(*id0)._index = make(map[int]*id13)
}

type Graph struct {
	maxV    int
	isflow  bool
	sparse  bool
	_V      []int
	_V_index map[int]int
	_E      [][]int
	_adj    [][]int
	_levels map[int][]int
}

func NewGraph(maxV int, isflow, sparse bool) *Graph {
	g := &Graph{
		maxV:    maxV,
		isflow:  isflow,
		sparse:  sparse,
		_V:      []int{},
		_V_index: make(map[int]int),
		_levels: make(map[int][]int),
	}

	nonEdge := 0
	if !isflow {
		nonEdge = math.MaxInt
	}

	if sparse {
		g._E = make([][]int, maxV)
		for i := range g._E {
			g._E[i] = make([]int, maxV)
		}
	} else {
		g._E = make([][]int, maxV)
		for i := range g._E {
			g._E[i] = make([]int, maxV)
			for j := range g._E[i] {
				g._E[i][j] = nonEdge
			}
		}
	}

	g._adj = make([][]int, maxV)
	for i := range g._adj {
		g._adj[i] = []int{}
	}

	return g
}

func (g *Graph) addVertex(label int) {
	g._V_index[label] = len(g._V)
	g._V = append(g._V, label)
}

func (g *Graph) addEdge(uLabel, vLabel, w int) {
	u := g._V_index[uLabel]
	v := g._V_index[vLabel]
	if g.isflow {
		g._E[u][v] += w
		g._adj[u] = append(g._adj[u], v)
		g._adj[v] = append(g._adj[v], u)
	} else {
		g._E[u][v] = w
		g._adj[u] = append(g._adj[u], v)
	}
}

func (g *Graph) isAdj(uLabel, vLabel int) bool {
	u := g._V_index[uLabel]
	v := g._V_index[vLabel]
	for _, adj := range g._adj[u] {
		if adj == v {
			return true
		}
	}
	return false
}

func (g *Graph) trim(uLabel int) {
	u := g._V_index[uLabel]
	g._adj[u] = []int{}
	if g.sparse {
		g._E[u] = []int{}
	} else {
		for i := range g._E[u] {
			g._E[u][i] = math.MaxInt
		}
	}
}

func (g *Graph) maxFlow(sLabel, tLabel int) int {
	E_saved := make([][]int, g.maxV)
	for i := range g._E {
		E_saved[i] = make([]int, g.maxV)
		copy(E_saved[i], g._E[i])
	}
	s := g._V_index[sLabel]
	t := g._V_index[tLabel]

	mf := 0
	for {
		if g.id20(s, t) == math.MaxInt {
			break
		}
		mf += g.id30(s, t)
	}

	g._E = E_saved
	return mf
}

func (g *Graph) id20(s, t int) int {
	g._levels[s] = make([]int, g.maxV)
	for i := range g._levels[s] {
		g._levels[s][i] = math.MaxInt
	}
	g._levels[s][s] = 0

	queue := []int{s}
	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		for _, v := range g._adj[u] {
			if g._E[u][v] > 0 && g._levels[s][v] == math.MaxInt {
				g._levels[s][v] = g._levels[s][u] + 1
				queue = append(queue, v)
			}
		}
	}

	return g._levels[s][t]
}

func (g *Graph) id30(s, t int) int {
	pointers := make([][]int, g.maxV)
	for i := range g._adj {
		pointers[i] = append([]int{}, g._adj[i]...)
	}

	var dfsPush func(u, t, inflow int) int
	dfsPush = func(u, t, inflow int) int {
		if u == t {
			return inflow
		}
		id4 := 0
		for len(pointers[u]) > 0 {
			v := pointers[u][len(pointers[u])-1]
			pointers[u] = pointers[u][:len(pointers[u])-1]
			if g._levels[s][v] == g._levels[s][u]+1 && g._E[u][v] > 0 {
				vFlow := dfsPush(v, t, min(inflow, g._E[u][v]))
				g._E[u][v] -= vFlow
				g._E[v][u] += vFlow
				inflow -= vFlow
				id4 += vFlow
				if inflow == 0 {
					pointers[u] = append(pointers[u], v)
					break
				}
			}
		}
		return id4
	}

	blockingFlow := dfsPush(s, t, math.MaxInt)
	g._levels = make(map[int][]int)
	return blockingFlow
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	roads := make([][2]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&roads[i][0], &roads[i][1])
	}
	var k int
	fmt.Scan(&k)
	p := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&p[i])
	}

	G := NewGraph(n, false, true)
	adj := make(map[int]map[int]struct{})
	for i := 1; i <= n; i++ {
		adj[i] = make(map[int]struct{})
		G.addVertex(i)
	}
	for _, road := range roads {
		G.addEdge(road[1], road[0], 1)
		adj[road[0]][road[1]] = struct{}{}
	}

	spaths := G.id9(p[k-1], nil)

	id22 := 0
	id27 := 0
	for i := 0; i < k-1; i++ {
		u := p[i]
		u_d := spaths[u]
		v := p[i+1]
		v_d := spaths[v]

		if v_d != u_d-1 {
			id22++
			id27++
			continue
		}

		for w := range adj[u] {
			if w != v && spaths[w] == v_d {
				id27++
				break
			}
		}
	}

	fmt.Println(id22, id27)
}
