package main

import (
	"container/heap"
	"fmt"
	"math"
)

type LinkedListNodeBase struct {
	prev, next *LinkedListNodeBase
}

func (node *LinkedListNodeBase) connect(nextNode *LinkedListNodeBase) *LinkedListNodeBase {
	node.next = nextNode
	nextNode.prev = node
	return nextNode
}

func (node *LinkedListNodeBase) splice(fragment *LinkedListNodeBase) *LinkedListNodeBase {
	if fragment.prev != nil {
		fragment.prev.next = nil
	}

	u := node
	v := fragment
	w := node.next

	u.connect(v)
	for v.next != nil {
		v = v.next
	}
	v.connect(w)

	return v
}

func (node *LinkedListNodeBase) splice1(newNode *LinkedListNodeBase) {
	newNode.connect(node.next)
	node.connect(newNode)
}

func (node *LinkedListNodeBase) eject() {
	node.prev.connect(node.next)
}

func (node *LinkedListNodeBase) iterate() <-chan *LinkedListNodeBase {
	ch := make(chan *LinkedListNodeBase)
	go func() {
		u := node
		for {
			ch <- u
			u = u.next
			if u == nil || u == node {
				break
			}
		}
		close(ch)
	}()
	return ch
}

type AbstractHeap interface {
	Bool() bool
	Len() int
	Contains(value interface{}) bool
	GetItem(value interface{}) interface{}
	Push(key, value interface{})
	Pop() (interface{}, interface{})
	DecreaseKey(value interface{}, key interface{})
	Merge(other AbstractHeap)
}

type FibHeapNode struct {
	LinkedListNodeBase
	key, value interface{}
	parent, child *FibHeapNode
	degree int
	mark bool
}

type FibonacciHeap struct {
	n      int
	root   *FibHeapNode
	index  map[interface{}]*FibHeapNode
}

func NewFibonacciHeap(iterable []struct{ Key, Value interface{} }) *FibonacciHeap {
	heap := &FibonacciHeap{
		index: make(map[interface{}]*FibHeapNode),
	}
	for _, kv := range iterable {
		heap.Push(kv.Key, kv.Value)
	}
	return heap
}

func (h *FibonacciHeap) Bool() bool {
	return h.n > 0
}

func (h *FibonacciHeap) Len() int {
	return h.n
}

func (h *FibonacciHeap) Contains(value interface{}) bool {
	_, exists := h.index[value]
	return exists
}

func (h *FibonacciHeap) GetItem(value interface{}) interface{} {
	return h.index[value].key
}

func (h *FibonacciHeap) Push(key, value interface{}) {
	node := &FibHeapNode{key: key, value: value}
	h.index[value] = node

	if h.root == nil {
		node.connect(node)
		h.root = node
		h.n = 1
	} else {
		h.root.splice1(node)
		if key.(int) < h.root.key.(int) {
			h.root = node
		}
		h.n++
	}
}

func (h *FibonacciHeap) Pop() (interface{}, interface{}) {
	z := h.root

	if z.child != nil {
		for c := range z.child.iterate() {
			c.parent = nil
		}
		z.splice(z.child)
	}

	if z.next == z {
		h.root = nil
	} else {
		h.root = z.next
		z.eject()
		h.consolidate()
	}

	h.n--
	delete(h.index, z.value)
	return z.key, z.value
}

func (h *FibonacciHeap) consolidate() {
	A := make(map[int]*FibHeapNode)
	for x := range h.root.iterate() {
		d := x.degree
		for {
			if y, exists := A[d]; exists {
				if x.key.(int) > y.key.(int) {
					x, y = y, x
				}
				h.link(y, x)
				delete(A, d)
				d++
			} else {
				break
			}
		}
		A[d] = x
	}

	var root *FibHeapNode
	for _, x := range A {
		if root == nil {
			root = x
			root.connect(root)
		} else {
			root.splice1(x)
			if x.key.(int) < root.key.(int) {
				root = x
			}
		}
	}
	h.root = root
}

func (h *FibonacciHeap) link(y, x *FibHeapNode) {
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

func (h *FibonacciHeap) DecreaseKey(value, key interface{}) {
	x := h.index[value]

	x.key = key
	delete(h.index, value)
	h.index[value] = x

	y := x.parent
	if y != nil && x.key.(int) < y.key.(int) {
		h.cut(x, y)
		h.cascadingCut(y)
	}

	if x.key.(int) < h.root.key.(int) {
		h.root = x
	}
}

func (h *FibonacciHeap) cut(x, y *FibHeapNode) {
	if x.next == x {
		y.child = nil
	} else {
		y.child = x.next
	}
	x.parent = nil
	x.eject()
	y.degree--

	h.root.splice1(x)
	x.mark = false
}

func (h *FibonacciHeap) cascadingCut(y *FibHeapNode) {
	z := y.parent
	if z != nil {
		if !y.mark {
			y.mark = true
		} else {
			h.cut(y, z)
			h.cascadingCut(z)
		}
	}
}

func (h *FibonacciHeap) Merge(other AbstractHeap) {
	if other == nil {
		return
	}

	if h.Bool() {
		h.root.splice(other.(*FibonacciHeap).root)
		if other.(*FibonacciHeap).root.key.(int) < h.root.key.(int) {
			h.root = other.(*FibonacciHeap).root
		}
		for k, v := range other.(*FibonacciHeap).index {
			h.index[k] = v
		}
	} else {
		h.root = other.(*FibonacciHeap).root
		h.index = other.(*FibonacciHeap).index
	}

	h.n += other.(*FibonacciHeap).n
	other.(*FibonacciHeap).root = nil
	other.(*FibonacciHeap).n = 0
	other.(*FibonacciHeap).index = make(map[interface{}]*FibHeapNode)
}

type Graph struct {
	maxV    int
	isflow  bool
	sparse  bool
	V       []interface{}
	VIndex  map[interface{}]int
	E       [][]int
	adj     []map[int]struct{}
	levels  map[int][]int
}

func NewGraph(maxV int, isflow, sparse bool) *Graph {
	g := &Graph{
		maxV:   maxV,
		isflow: isflow,
		sparse: sparse,
		V:      []interface{}{},
		VIndex: make(map[interface{}]int),
		levels: make(map[int][]int),
	}

	nonEdge := 0
	if !isflow {
		nonEdge = math.MaxInt
	}
	if sparse {
		g.E = make([][]int, maxV)
		for i := range g.E {
			g.E[i] = make([]int, maxV)
			for j := range g.E[i] {
				g.E[i][j] = nonEdge
			}
		}
	} else {
		g.adj = make([]map[int]struct{}, maxV)
		for i := range g.adj {
			g.adj[i] = make(map[int]struct{})
		}
	}
	return g
}

func (g *Graph) AddVertex(label interface{}) {
	g.VIndex[label] = len(g.V)
	g.V = append(g.V, label)
}

func (g *Graph) AddEdge(uLabel, vLabel interface{}, w int) {
	u := g.VIndex[uLabel]
	v := g.VIndex[vLabel]
	if g.isflow {
		g.E[u][v] += w
		g.adj[u][v] = struct{}{}
		g.adj[v][u] = struct{}{}
	} else {
		g.E[u][v] = w
		g.adj[u][v] = struct{}{}
	}
}

func (g *Graph) IsAdj(uLabel, vLabel interface{}) bool {
	u := g.VIndex[uLabel]
	v := g.VIndex[vLabel]
	_, exists := g.adj[u][v]
	return exists
}

func (g *Graph) Trim(uLabel interface{}) {
	u := g.VIndex[uLabel]
	g.adj[u] = make(map[int]struct{})
	if g.sparse {
		g.E[u] = make([]int, g.maxV)
	} else {
		for i := range g.E[u] {
			g.E[u][i] = math.MaxInt
		}
	}
}

func (g *Graph) BFSLevels(s, t int) int {
	g.levels[s] = make([]int, g.maxV)
	for i := range g.levels[s] {
		g.levels[s][i] = math.MaxInt
	}
	g.levels[s][s] = 0

	queue := []int{s}
	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		for v := range g.adj[u] {
			if g.E[u][v] > 0 && g.levels[s][v] == math.MaxInt {
				g.levels[s][v] = g.levels[s][u] + 1
				queue = append(queue, v)
			}
		}
	}
	return g.levels[s][t]
}

func (g *Graph) MaxFlow(sLabel, tLabel interface{}) int {
	E_saved := make([][]int, g.maxV)
	for i := range g.E {
		E_saved[i] = make([]int, g.maxV)
		copy(E_saved[i], g.E[i])
	}
	s := g.VIndex[sLabel]
	t := g.VIndex[tLabel]

	mf := 0
	for g.BFSLevels(s, t) != math.MaxInt {
		mf += g.PushBlockingFlow(s, t)
	}

	g.E = E_saved
	return mf
}

func (g *Graph) PushBlockingFlow(s, t int) int {
	pointers := make([]map[int]struct{}, g.maxV)
	for i := range pointers {
		pointers[i] = make(map[int]struct{})
		for v := range g.adj[i] {
			pointers[i][v] = struct{}{}
		}
	}

	var dfsPush func(u, t, inflow int) int
	dfsPush = func(u, t, inflow int) int {
		if u == t {
			return inflow
		}
		uOutflow := 0
		for len(pointers[u]) > 0 {
			var v int
			for v = range pointers[u] {
				delete(pointers[u], v)
				break
			}
			if g.levels[s][v] == g.levels[s][u]+1 && g.E[u][v] > 0 {
				vFlow := dfsPush(v, t, min(inflow, g.E[u][v]))
				g.E[u][v] -= vFlow
				g.E[v][u] += vFlow
				inflow -= vFlow
				uOutflow += vFlow
				if inflow == 0 {
					pointers[u][v] = struct{}{}
					break
				}
			}
		}
		return uOutflow
	}

	blockingFlow := dfsPush(s, t, math.MaxInt)
	g.levels = make(map[int][]int)
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
		G.AddVertex(i)
		adj[i] = make(map[int]struct{})
	}
	for _, road := range roads {
		G.AddEdge(road[1], road[0], 1)
		adj[road[0]][road[1]] = struct{}{}
	}

	spaths := G.SingleSourceSPaths(p[k-1], nil, math.MaxInt, NewFibonacciHeap)

	minRebuild := 0
	maxRebuild := 0
	for i := 0; i < k-1; i++ {
		u := p[i]
		uD := spaths[u]
		v := p[i+1]
		vD := spaths[v]

		if vD != uD-1 {
			minRebuild++
			maxRebuild++
			continue
		}

		for w := range adj[u] {
			if w != v && spaths[w] == vD {
				maxRebuild++
				break
			}
		}
	}

	fmt.Println(minRebuild, maxRebuild)
}
