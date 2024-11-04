package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type LinkedListNodeBase struct {
	prev *LinkedListNodeBase
	next *LinkedListNodeBase
}

func (node *LinkedListNodeBase) connect(next *LinkedListNodeBase) *LinkedListNodeBase {
	node.next = next
	next.prev = node
	return next
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

func (node *LinkedListNodeBase) splice1(node2 *LinkedListNodeBase) {
	node2.connect(node.next)
	node.connect(node2)
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
	push(key int, value interface{})
	pop() (int, interface{})
	decreaseKey(value interface{}, key int)
}

type FibHeapNode struct {
	LinkedListNodeBase
	key    int
	value  interface{}
	parent *FibHeapNode
	child  *FibHeapNode
	degree int
	mark   bool
}

type FibonacciHeap struct {
	root   *FibHeapNode
	index  map[interface{}]*FibHeapNode
	n      int
}

func NewFibonacciHeap() *FibonacciHeap {
	return &FibonacciHeap{
		root:   nil,
		index:  make(map[interface{}]*FibHeapNode),
		n:      0,
	}
}

func (heap *FibonacciHeap) push(key int, value interface{}) {
	node := &FibHeapNode{
		key:    key,
		value:  value,
		parent: nil,
		child:  nil,
		degree: 0,
		mark:   false,
	}
	heap.index[value] = node

	if heap.root == nil {
		node.connect(node)
		heap.root = node
		heap.n = 1
	} else {
		heap.root.splice1(node)
		if key < heap.root.key {
			heap.root = node
		}
		heap.n++
	}
}

func (heap *FibonacciHeap) pop() (int, interface{}) {
	z := heap.root

	if z.child != nil {
		for c := range z.child.iterate() {
			c.parent = nil
		}
		z.splice(z.child)
	}

	if z.next == z {
		heap.root = nil
	} else {
		heap.root = z.next
		z.eject()
		heap.consolidate()
	}

	delete(heap.index, z.value)
	heap.n--
	return z.key, z.value
}

func (heap *FibonacciHeap) consolidate() {
	A := make(map[int]*FibHeapNode)
	for x := range heap.root.iterate() {
		d := x.degree
		for A[d] != nil {
			y := A[d]
			if x.key > y.key {
				x, y = y, x
			}
			heap.link(y, x)
			delete(A, d)
			d++
		}
		A[d] = x
	}

	var i int
	for _, x := range A {
		if i == 0 {
			heap.root = x
			heap.root.connect(heap.root)
		} else {
			heap.root.splice1(x)
			if x.key < heap.root.key {
				heap.root = x
			}
		}
		i++
	}
}

func (heap *FibonacciHeap) link(y, x *FibHeapNode) {
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

type Implicit2Heap struct {
	tree  [][]int
	index map[interface{}]int
}

func NewImplicit2Heap() *Implicit2Heap {
	return &Implicit2Heap{
		tree:  make([][]int, 0),
		index: make(map[interface{}]int),
	}
}

func (heap *Implicit2Heap) push(key int, value interface{}) {
	heap.index[value] = len(heap.tree)
	heap.tree = append(heap.tree, []int{math.MaxInt64, value})
	heap.decreaseKey(value, key)
}

func (heap *Implicit2Heap) pop() (int, interface{}) {
	tree := heap.tree
	z := tree[0]
	tree[0] = tree[len(tree)-1]
	tree = tree[:len(tree)-1]
	heap.tree = tree
	if len(tree) > 0 {
		heap.heapify(0)
	}
	delete(heap.index, z[1])
	return z[0], z[1]
}

func (heap *Implicit2Heap) decreaseKey(value interface{}, key int) {
	tree := heap.tree
	i := heap.index[value]

	for i > 0 {
		p := (i+1)/2 - 1
		if !(key < tree[p][0]) {
			break
		}
		tree[i] = tree[p]
		heap.index[tree[i][1]] = i
		i = p
	}

	tree[i] = []int{key, value}
	heap.index[value] = i
}

type PairingHeapNode struct {
	key    int
	value  interface{}
	parent *PairingHeapNode
	left   *PairingHeapNode
	right  *PairingHeapNode
}

type PairingHeap struct {
	root  *PairingHeapNode
	index map[interface{}]*PairingHeapNode
}

func NewPairingHeap() *PairingHeap {
	return &PairingHeap{
		root:  nil,
		index: make(map[interface{}]*PairingHeapNode),
	}
}

func (heap *PairingHeap) push(key int, value interface{}) {
	node := &PairingHeapNode{
		key:    key,
		value:  value,
		parent: nil,
		left:   nil,
		right:  nil,
	}
	heap.index[value] = node

	if heap.root == nil {
		heap.root = node
	} else {
		heap.root = heap.root.link(node)
	}
}

func (heap *PairingHeap) decreaseKey(value interface{}, key int) {
	x := heap.index[value]

	x.key = key
	delete(heap.index, value)
	heap.index[value] = x
	if x.parent == nil {
		return
	}

	if x.parent.left == x {
		x.parent.left = x.right
	} else {
		x.parent.right = x.right
	}
	if x.right != nil {
		x.right.parent = x.parent
	}

	x.parent = nil
	x.right = nil
	heap.root = heap.root.link(x)
}

func (heap *PairingHeap) pop() (int, interface{}) {
	z := heap.root
	if z.left == nil {
		heap.root = nil
	} else {
		pass0 := make([]*PairingHeapNode, 0)
		i := z.left
		for i != nil {
			j := i.right
			i.parent = nil
			i.right = nil
			pass0 = append(pass0, i)
			i = j
		}

		pass1 := make([]*PairingHeapNode, 0)
		for i := 0; i < len(pass0)-1; i += 2 {
			pass1 = append(pass1, pass0[i].link(pass0[i+1]))
		}
		if len(pass0)%2 == 1 {
			pass1 = append(pass1, pass0[len(pass0)-1])
		}

		y := pass1[len(pass1)-1]
		pass1 = pass1[:len(pass1)-1]
		for len(pass1) > 0 {
			y = y.link(pass1[len(pass1)-1])
			pass1 = pass1[:len(pass1)-1]
		}

		heap.root = y
	}

	delete(heap.index, z.value)
	return z.key, z.value
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	readString := func() string {
		scanner.Scan()
		return scanner.Text()
	}

	readInt := func() int {
		i, _ := strconv.Atoi(readString())
		return i
	}

	n := readInt()
	m := readInt()
	roads := make([][2]int, m)
	for i := 0; i < m; i++ {
		u := readInt()
		v := readInt()
		roads[i] = [2]int{u, v}
	}
	k := readInt()
	p := make([]int, k)
	for i := 0; i < k; i++ {
		p[i] = readInt()
	}

	G := NewGraph(n, true, true)
	for _, road := range roads {
		u := road[1]
		v := road[0]
		G.AddEdge(v, u)
	}

	spaths := G.SingleSourceShortestPaths(p[k-1], nil, math.Inf(1), NewFibonacciHeap)

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

		adj := G.GetAdjacencyList()
		found := false
		for _, w := range adj[u] {
			if w != v && spaths[w] == vD {
				maxRebuild++
				found = true
				break
			}
		}

		if !found {
			minRebuild++
			maxRebuild++
		}
	}

	fmt.Println(minRebuild, maxRebuild)
}

type Graph struct {
	maxV   int
	isFlow bool
	sparse bool
	V      []interface{}
	adj    []map[int]bool
	E      [][]int
	levels map[interface{}][]int
}

func NewGraph(maxV int, isFlow bool, sparse bool) *Graph {
	return &Graph{
		maxV:   maxV,
		isFlow: isFlow,
		sparse: sparse,
		V:      make([]interface{}, 0),
		adj:    make([]map[int]bool, maxV),
		E:      make([][]int, maxV),
		levels: make(map[interface{}][]int),
	}
}

func (g *Graph) AddVertex(label interface{}) {
	g.V = append(g.V, label)
	g.adj[g.nV()] = make(map[int]bool)
}

func (g *Graph) AddEdge(uLabel, vLabel interface{}) {
	u := g.VIndex(uLabel)
	v := g.VIndex(vLabel)
	g._AddEdge(u, v, 1)
}

func (g *Graph) Trim(uLabel interface{}) {
	u := g.VIndex(uLabel)
	g.adj[u] = make(map[int]bool)
	if g.sparse {
		g.E[u] = make([]int, 0)
	} else {
		g.E[u] = make([]int, g.maxV)
		for i := 0; i < g.maxV; i++ {
			g.E[u][i] = math.MaxInt64
		}
	}
}

func (g *Graph) MaxFlow(sLabel, tLabel interface{}) int {
	Esaved := make([][]int, g.maxV)
	for i := 0; i < g.maxV; i++ {
		Esaved[i] = make([]int, g.maxV)
		copy(Esaved[i], g.E[i])
	}

	s := g.VIndex(sLabel)
	t := g.VIndex(tLabel)

	mf := 0
	for g._BFSLevels(s, t) != math.MaxInt64 {
		mf += g._PushBlockingFlow(s, t)
	}

	g.E = Esaved
	return mf
}

func (g *Graph) SingleSourceShortestPaths(sLabel interface{}, tLabels []interface{}, dLimit float64, Heap AbstractHeap) map[interface{}]float64 {
	s := g.VIndex(sLabel)
	tSet := make(map[int]bool)
	if tLabels == nil {
		for i := 0; i < g.nV(); i++ {
			tSet[i] = true
		}
	} else {
		for _, tLabel := range tLabels {
			tSet[g.VIndex(tLabel)] = true
		}
	}

	queue := Heap{}
	queue.Push(0, s)
	spaths := make(map[int]float64)
	parents := make(map[int]int)
	tFound := make([]int, 0)
	for len(queue) > 0 {
		su, u := queue.Pop()
		if su >= dLimit {
			break
		}

		spaths[u] = su
		if tSet[u] {
			delete(tSet, u)
			tFound = append(tFound, u)
			if len(tSet) == 0 {
				break
			}
		}

		for v := range g.adj[u] {
			sv := su + float64(g.E[u][v])
			if queue.Contains(v) {
				if sv < queue[v] {
					parents[v] = u
					queue.DecreaseKey(v, sv)
				}
			} else if _, ok := spaths[v]; !ok {
				parents[v] = u
				queue.Push(sv, v)
			}
		}
	}

	ret := make(map[interface{}]float64)
	for v, d := range spaths {
		ret[g.V[v]] = d
	}
	ret[sLabel] = 0
	ret.Parents = make(map[interface{}]interface{})
	for v, p := range parents {
		ret.Parents[g.V[v]] = g.V[p]
	}
	ret.Found = make([]interface{}, len(tFound))
	for i, t := range tFound {
		ret.Found[i] = g.V[t]
	}
	return ret
}

func (g *Graph) VIndex(label interface{}) int {
	for i, v := range g.V {
		if v == label {
			return i
		}
	}
	return -1
}

func (g *Graph) nV() int {
	return len(g.V)
}

func (g *Graph) _AddEdge(u, v, w int) {
	if g.isFlow {
		g.E[u][v] += w
		g.adj[u][v] = true
		g.adj[v][u] = true
	} else {
		g.E[u][v] = w
		g.adj[u][v] = true
	}
}

func (g *Graph) _BFSLevels(s, t int) int {
	g.levels[s] = make([]int, g.maxV)
	for i := 0; i < g.maxV; i++ {
		g.levels[s][i] = math.MaxInt64
	}
	g.levels[s][s] = 0

	queue := make([]int, 0)
	queue = append(queue, s)
	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		for v := range g.adj[u] {
			if g.E[u][v] > 0 && g.levels[s][v] == math.MaxInt64 {
				g.levels[s][v] = g.levels[s][u] + 1
				queue = append(queue, v)
			}
		}
	}

	return g.levels[s][t]
}

func (g *Graph) _PushBlockingFlow(s, t int) int {
	pointers := make([]map[int]bool, g.nV())
	for i := 0; i < g.nV(); i++ {
		pointers[i] = make(map[int]bool)
		for v := range g.adj[i] {
			pointers[i][v] = true
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
				break
			}
			delete(pointers[u], v)
			if g.levels[s][v] == g.levels[s][u]+1 && g.E[u][v] > 0 {
				vFlow := dfsPush(v, t, min(inflow, g.E[u][v]))
				g.E[u][v] -= vFlow
				g.E[v][u] += vFlow
				inflow -= vFlow
				uOutflow += vFlow
				if inflow == 0 {
					pointers[u][v] = true
					break
				}
			}
		}
		return uOutflow
	}

	blockingFlow := dfsPush(s, t, math.MaxInt64)
	g.levels = make(map[interface{}][]int)
	return blockingFlow
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	main()
}
