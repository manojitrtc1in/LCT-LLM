package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type id17 struct {
	id8   []string
	prev  *id17
	next  *id17
}

func (id *id17) connect(node *id17) *id17 {
	id.next = node
	node.prev = id
	return node
}

func (id *id17) splice(fragment *id17) *id17 {
	if fragment.prev != nil {
		fragment.prev.next = nil
	}

	u := id
	v := fragment
	w := id.next

	u.connect(v)
	for v.next != nil {
		v = v.next
	}
	v.connect(w)

	return v
}

func (id *id17) splice1(node *id17) {
	node.connect(id.next)
	id.connect(node)
}

func (id *id17) eject() {
	id.prev.connect(id.next)
}

func (id *id17) iterate() <-chan *id17 {
	ch := make(chan *id17)
	go func() {
		u := id
		for {
			ch <- u
			u = u.next
			if u == id || u == nil {
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
	id8    []string
	key    int
	value  int
	parent *id13
	child  *id13
	degree int
	mark   bool
}

func (id *id13) connect(node *id13) *id13 {
	id.next = node
	node.prev = id
	return node
}

func (id *id13) splice(fragment *id13) *id13 {
	if fragment.prev != nil {
		fragment.prev.next = nil
	}

	u := id
	v := fragment
	w := id.next

	u.connect(v)
	for v.next != nil {
		v = v.next
	}
	v.connect(w)

	return v
}

func (id *id13) splice1(node *id13) {
	node.connect(id.next)
	id.connect(node)
}

func (id *id13) eject() {
	id.prev.connect(id.next)
}

func (id *id13) iterate() <-chan *id13 {
	ch := make(chan *id13)
	go func() {
		u := id
		for {
			ch <- u
			u = u.next
			if u == id || u == nil {
				break
			}
		}
		close(ch)
	}()
	return ch
}

type id0 struct {
	AbstractHeap
	_n     int
	_root  *id13
	_index map[int]*id13
}

func (id *id0) id6() bool {
	return id._n > 0
}

func (id *id0) id18() int {
	return id._n
}

func (id *id0) id14(value int) bool {
	_, ok := id._index[value]
	return ok
}

func (id *id0) id21(value int) int {
	node, ok := id._index[value]
	if !ok {
		return 0
	}
	return node.key
}

func (id *id0) push(key, value int) {
	node := &id13{
		key:   key,
		value: value,
	}
	id._index[value] = node

	if id._root == nil {
		node.connect(node)
		id._root = node
		id._n = 1
	} else {
		id._root.splice1(node)
		if key < id._root.key {
			id._root = node
		}
		id._n++
	}
}

func (id *id0) pop() (int, int) {
	z := id._root

	if z.child != nil {
		c := z.child
		for c != nil {
			c.parent = nil
			c = c.next
		}
		z.splice(z.child)
	}

	if z.next == z {
		id._root = nil
	} else {
		id._root = z.next
		z.eject()
		id.id31()
	}

	id._n--
	delete(id._index, z.value)
	return z.key, z.value
}

func (id *id0) id31() {
	A := make(map[int]*id13)
	for x := range id._root.iterate() {
		d := x.degree
		for A[d] != nil {
			y := A[d]
			if x.key > y.key {
				x, y = y, x
			}
			id._link(y, x)
			delete(A, d)
			d++
		}
		A[d] = x
	}

	i := 0
	for _, x := range A {
		if i == 0 {
			id._root = x
			id._root.connect(id._root)
		} else {
			id._root.splice1(x)
			if x.key < id._root.key {
				id._root = x
			}
		}
		i++
	}
}

func (id *id0) _link(y, x *id13) {
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

func (id *id0) id28(value, key int) {
	x := id._index[value]

	x.key = key
	delete(id._index, value)
	id._index[value] = x

	y := x.parent
	if y != nil && x.key < y.key {
		id._cut(x, y)
		id.id2(y)
	}

	if x.key < id._root.key {
		id._root = x
	}
}

func (id *id0) _cut(x, y *id13) {
	if x.next == x {
		y.child = nil
	} else {
		y.child = x.next
	}
	x.parent = nil
	x.eject()
	y.degree--

	id._root.splice1(x)
	x.mark = false
}

func (id *id0) id2(y *id13) {
	z := y.parent
	if z != nil {
		if !y.mark {
			y.mark = true
		} else {
			id._cut(y, z)
			id.id2(z)
		}
	}
}

func (id *id0) merge(other AbstractHeap) {
	if other == nil {
		return
	}

	if id._root != nil {
		id._root.splice(other.(*id0)._root)
		if other.(*id0)._root.key < id._root.key {
			id._root = other.(*id0)._root
		}
		for k, v := range other.(*id0)._index {
			id._index[k] = v
		}
	} else {
		id._root = other.(*id0)._root
		id._index = other.(*id0)._index
	}

	id._n += other.(*id0)._n
	other.(*id0)._root = nil
	other.(*id0)._n = 0
	other.(*id0)._index = nil
}

type id5 struct {
	AbstractHeap
	_tree  [][]int
	_index map[int]int
}

func (id *id5) id6() bool {
	return len(id._tree) > 0
}

func (id *id5) id18() int {
	return len(id._tree)
}

func (id *id5) id14(value int) bool {
	_, ok := id._index[value]
	return ok
}

func (id *id5) id21(value int) int {
	index, ok := id._index[value]
	if !ok {
		return 0
	}
	return id._tree[index][0]
}

func (id *id5) push(key, value int) {
	id._index[value] = len(id._tree)
	id._tree = append(id._tree, []int{math.MinInt64, value})
	id.id28(value, key)
}

func (id *id5) pop() (int, int) {
	tree := id._tree
	z := tree[0]
	tree[0] = tree[len(tree)-1]
	tree = tree[:len(tree)-1]
	id._tree = tree
	if len(tree) > 0 {
		id._heapify(0)
	}

	delete(id._index, z[1])
	return z[0], z[1]
}

func (id *id5) _build_heap(iterable [][]int) {
	tree := make([][]int, len(iterable))
	copy(tree, iterable)
	size := len(tree)

	id._index = make(map[int]int)
	for i := size/2 - 1; i >= 0; i-- {
		id._heapify(i)
	}
}

func (id *id5) _heapify(i int) {
	tree := id._tree
	size := len(tree)
	left := (i+1)*2 - 1
	right := (i+1)*2 + 1 - 1

	z := i
	if left < size && tree[left][0] < tree[z][0] {
		z = left
	}
	if right < size && tree[right][0] < tree[z][0] {
		z = right
	}

	if z != i {
		tree[i], tree[z] = tree[z], tree[i]
		id._heapify(z)
	}

	id._index[tree[i][1]] = i
}

func (id *id5) id28(value, key int) {
	tree := id._tree
	i := id._index[value]

	for i > 0 {
		p := (i+1)/2 - 1
		if !(key < tree[p][0]) {
			break
		}
		tree[i] = tree[p]
		id._index[tree[i][1]] = i
		i = p
	}

	tree[i] = []int{key, value}
	id._index[value] = i
}

func (id *id5) merge(other AbstractHeap) {
	if other == nil {
		return
	}

	id._build_heap(append(id._tree, other.(*id5)._tree...))
	other.(*id5)._tree = nil
	other.(*id5)._index = nil
}

type id3 struct {
	id8   []string
	key   int
	value int
	left  *id3
	right *id3
}

func (id *id3) link(other *id3) *id3 {
	if other.key < id.key {
		id, other = other, id
	}
	if id.left == nil {
		id.left = other
		other.parent = id
	} else {
		r := id.left
		for r.right != nil {
			r = r.right
		}
		r.right = other
		other.parent = r
	}

	return id
}

type id16 struct {
	AbstractHeap
	_root  *id3
	_index map[int]*id3
}

func (id *id16) id6() bool {
	return id._root != nil
}

func (id *id16) id18() int {
	return len(id._index)
}

func (id *id16) id14(value int) bool {
	_, ok := id._index[value]
	return ok
}

func (id *id16) id21(value int) int {
	node, ok := id._index[value]
	if !ok {
		return 0
	}
	return node.key
}

func (id *id16) push(key, value int) {
	node := &id3{
		key:   key,
		value: value,
	}
	id._index[value] = node

	if id._root == nil {
		id._root = node
	} else {
		id._root = id._root.link(node)
	}
}

func (id *id16) id28(value, key int) {
	x := id._index[value]

	x.key = key
	delete(id._index, value)
	id._index[value] = x

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
	id._root = id._root.link(x)
}

func (id *id16) pop() (int, int) {
	z := id._root
	if z.left == nil {
		id._root = nil
	} else {
		pass0 := make([]*id3, 0)
		i := z.left
		for i != nil {
			j := i.right
			i.parent = nil
			i.right = nil
			pass0 = append(pass0, i)
			i = j
		}

		pass1 := make([]*id3, 0)
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

		id._root = y
	}

	delete(id._index, z.value)
	return z.key, z.value
}

type Graph struct {
	maxV   int
	isflow bool
	sparse bool
	_V     []int
	_VIndex map[int]int
	_E     [][]int
	_adj   [][]int
	_levels map[int][]int
}

func NewGraph(maxV int, isflow bool, sparse bool) *Graph {
	return &Graph{
		maxV:   maxV,
		isflow: isflow,
		sparse: sparse,
		_V:     make([]int, 0),
		_VIndex: make(map[int]int),
		_E:     make([][]int, maxV),
		_adj:   make([][]int, maxV),
		_levels: make(map[int][]int),
	}
}

func (g *Graph) addVertex(label int) {
	g._VIndex[label] = len(g._V)
	g._V = append(g._V, label)
}

func (g *Graph) addEdge(u, v, w int) {
	if g.isflow {
		g._E[u][v] += w
		g._adj[u] = append(g._adj[u], v)
		g._adj[v] = append(g._adj[v], u)
	} else {
		g._E[u][v] = w
		g._adj[u] = append(g._adj[u], v)
	}
}

func (g *Graph) trim(u int) {
	g._adj[u] = make([]int, 0)
	if g.sparse {
		g._E[u] = make([]int, 0)
	} else {
		g._E[u] = make([]int, g.maxV)
		for i := 0; i < g.maxV; i++ {
			g._E[u][i] = math.Inf(1)
		}
	}
}

func (g *Graph) bfs(s int) {
	g._levels[s] = make([]int, g.maxV)
	for i := 0; i < g.maxV; i++ {
		g._levels[s][i] = math.Inf(1)
	}
	g._levels[s][s] = 0

	queue := make([]int, 0)
	queue = append(queue, s)
	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]
		for _, v := range g._adj[u] {
			if g._E[u][v] > 0 && g._levels[s][v] == math.Inf(1) {
				g._levels[s][v] = g._levels[s][u] + 1
				queue = append(queue, v)
			}
		}
	}
}

func (g *Graph) dfsPush(u, t, inflow int) int {
	if u == t {
		return inflow
	}

	id4 := 0
	for len(g._adj[u]) > 0 {
		v := g._adj[u][len(g._adj[u])-1]
		g._adj[u] = g._adj[u][:len(g._adj[u])-1]
		if g._levels[s][v] == g._levels[s][u]+1 && g._E[u][v] > 0 {
			vFlow := g.dfsPush(v, t, min(inflow, g._E[u][v]))
			g._E[u][v] -= vFlow
			g._E[v][u] += vFlow
			inflow -= vFlow
			id4 += vFlow
			if inflow == 0 {
				g._adj[u] = append(g._adj[u], v)
				break
			}
		}
	}

	return id4
}

func (g *Graph) maxFlow(s, t int) int {
	Esaved := make([][]int, len(g._E))
	for i := 0; i < len(g._E); i++ {
		Esaved[i] = make([]int, len(g._E[i]))
		copy(Esaved[i], g._E[i])
	}

	mf := 0
	for g.bfs(s); g._levels[s][t] != math.Inf(1); mf += g.dfsPush(s, t, math.Inf(1)) {
		g._levels = make(map[int][]int)
	}

	g._E = Esaved
	return mf
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
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
	roads := make([][]int, m)
	for i := 0; i < m; i++ {
		u := readInt()
		v := readInt()
		roads[i] = []int{u, v}
	}
	k := readInt()
	p := make([]int, k)
	for i := 0; i < k; i++ {
		p[i] = readInt()
	}

	G := NewGraph(n, true, false)
	adj := make(map[int][]int)
	for _, road := range roads {
		u := road[0]
		v := road[1]
		G.addEdge(v, u, 1)
		adj[u] = append(adj[u], v)
	}

	spaths := G.id9(p[k-1], nil, math.Inf(1), &id0{})

	id22 := 0
	id27 := 0
	for i := 0; i < k-1; i++ {
		u := p[i]
		uD := spaths[u]
		v := p[i+1]
		vD := spaths[v]

		if vD != uD-1 {
			id22++
			id27++
			continue
		}

		for _, w := range adj[u] {
			if w != v && spaths[w] == vD {
				id27++
				break
			}
		}
	}

	fmt.Println(id22, id27)
}
