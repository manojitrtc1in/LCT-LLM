package main

import (
	

	"fmt"
	

	"sort"
	"math/rand"
	"time"
	"bufio"
	"os"
	"strconv"
)


var n, m int

var p,k,a,b, c int64

var qu []int64

type edge struct {
	from, to int
	w int64
}

var e []*edge

type ByW []*edge

func (a ByW) Len() int           { return len(a) }
func (a ByW) Less(i, j int) bool { return a[i].w < a[j].w }
func (a ByW) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }


var r *bufio.Reader

const WRITE = false

func main() {

	rand.Seed(time.Now().UnixNano())
	f, _ := os.OpenFile("D:\\GO\\src\\codeforces\\edu122\\5\\in.txt", os.O_RDWR, 0)
	defer f.Close()


	if WRITE {

		for i := 0; i < 100; i++ {
			n = 5
			m = 10

			f.WriteString("5 10\n")


			for j := 0; j < m; j++ {
				var from, to, w int
				from = 1 + rand.Intn(n)
				for ;; {
					to = 1 + rand.Intn(n)
					if to != from {
						break
					}
				}
				w = 1 + rand.Intn(1e2)

				f.WriteString(strconv.Itoa(from))
				f.WriteString(" ")
				f.WriteString(strconv.Itoa(to))
				f.WriteString(" ")
				f.WriteString(strconv.Itoa(w))
				f.WriteString("\n")
			}


			

			

			

			

			


			f.WriteString("5 10 7 13 100\n")

			for j := 1; j <= 5; j++ {
				x := rand.Intn(1e2)
				f.WriteString(strconv.Itoa(x))
				f.WriteString(" ")
			}

			f.WriteString("\n")
		}


		return
	}


	r = bufio.NewReader(os.Stdin)

	fmt.Fscan(r, &n, &m)

	e = make([]*edge, m)

	for i := 0; i < m; i++ {
		var from, to int
		var w int64
		fmt.Fscan(r, &from)
		fmt.Fscan(r, &to)
		fmt.Fscan(r, &w)

		from--
		to--

		ed := &edge{from, to, w}
		e[i] = ed
	}

	fmt.Fscan(r, &p, &k, &a, &b, &c)

	qu = make([]int64, p)

	for i := 0; i < int(p); i++ {
		var x int64
		fmt.Fscan(r, &x)
		qu[i] = x
	}

	


	ans := solve()

	

	

	


	fmt.Println(ans)



}

type pair struct {
	v, id int
}

type ByV []*pair

func (a ByV) Len() int           { return len(a) }
func (a ByV) Less(i, j int) bool { return a[i].v < a[j].v }
func (a ByV) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

type item struct {
	la, ra int
	lb, rb int
}


const MAX int = 1e6
var cost []int

const INF = int(1e9) + 5;

type value struct {
	l, r int
	val int64
}


func solve_stupid() int64 {
	var xMax int64 = 1000

	ans := make([]int64, xMax + 1)

	var x int64
	for x = 0; x <= xMax; x++ {
		sum := computeMST(x)
		ans[x] = sum
	}


	var aa int64

	var xIn int64

	var i int64
	for i = 0; i < p; i++ {
		xIn = qu[i]

		aa = aa ^ ans[xIn]
	}

	for i := p; i < k; i++ {
		xIn = (xIn * a + b) % c

		aa = aa ^ ans[xIn]
	}

	return aa

}









func computeMST(x int64) int64 {
	e2 := make([]*edge, m)

	for i := 0; i < m; i++ {
		ed := e[i]

		ed2 := edge{ed.from, ed.to, abs(ed.w - x)}

		e2[i] = &ed2
	}

	sort.Sort(ByW(e2))

	parent := make([]int, n)
	rank := make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
		rank[i] = 0
	}

	var sum int64

	for i := 0; i < m;  i++ {
		ed := e2[i]

		a := ed.from
		b := ed.to

		rootA := find(&parent, a)
		rootB := find(&parent, b)

		if rootA==rootB {
			continue
		}

		sum += int64(abs(ed.w))

		if  (rank)[rootA] < (rank)[rootB]{
			(parent)[rootA] = rootB

		} else if (rank)[rootA] > (rank)[rootB] {
			(parent)[rootB] = rootA

		} else {
			(parent)[rootB] = rootA
			(rank)[rootA]++
		}
	}

	return sum

}

func solve() int64 {
	sort.Sort(ByW(e))

	mp := make(map[int64]int)

	for i := 0; i < len(e); i++ {
		w1 := e[i].w
		for j := i + 1; j < len(e); j++ {
			w2 := e[j].w

			

			


			if w2 > w1 {
				key := (w1 + w2)/2 + 1
				mp[int64(key)] = 0
			}
		}
	}
	for i := 0; i < len(e); i++ {
		w := e[i].w
		mp[int64(w)] = 1
	}

	tree := newInt64InterfaceTreeMap(func(a int64, b int64) bool {
		return a < b
	})

	aa := doCompute(0)
	tree.Set(0, aa)


	for k, _ := range mp {
		ans := doCompute(k)

		tree.Set(k, ans)
	}

	var ans int64

	var x int64

	var i int64
	for i = 0; i < p; i++ {
		x = qu[i]

		lb := tree.LowerBound(x)

		if lb.Key() == x {
			ans = ans ^ lb.Value().(*value).val
			continue
		}

		lb.Prev()

		k := lb.Key()

		left := lb.Value().(*value).l
		right := lb.Value().(*value).r
		val := lb.Value().(*value).val

		res := val + int64(left) * int64(x - k) - int64(right) * int64(x - k)

		ans = ans ^ res

	}

	for i := p; i < k; i++ {
		x = (x * a + b) % c

		lb := tree.LowerBound(x)

		if lb.Key() == x {
			ans = ans ^ lb.Value().(*value).val
			continue
		}

		lb.Prev()

		k := lb.Key()

		left := lb.Value().(*value).l
		right := lb.Value().(*value).r
		val := lb.Value().(*value).val

		res := val + int64(left) * int64(x - k) - int64(right) * int64(x - k)
		ans = ans ^ res
	}

	return ans
}

func doCompute(x int64) *value {
	parent := make([]int, n)
	rank := make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
		rank[i] = 0
	}

	idx := sort.Search(m, func(i int) bool {
		ed := e[i]
		return ed.w > x
	})

	var ans *value

	if idx == 0 {
		ans = goFromStart(&parent, &rank, x)

	} else if idx == m {
		ans = goFromEnd(&parent, &rank, x)

	} else {
		ans = goFrom(idx, &parent, &rank, x)
	}

	return ans
}



func find(parent *[]int, p int) int {
	for ; p != (*parent)[p]; {
		(*parent)[p] = (*parent)[(*parent)[p]]
		p = (*parent)[p]
	}

	return p
}

func goFromStart(parent *[]int, rank *[]int, x int64) *value {

	sum := &value{}

	for i := 0; i < m;  i++ {
		ed := e[i]

		a := ed.from
		b := ed.to

		rootA := find(parent, a)
		rootB := find(parent, b)

		if rootA==rootB {
			continue
		}

		sum.val += int64(abs(ed.w - x))
		sum.r++

		if  (*rank)[rootA] < (*rank)[rootB]{
			(*parent)[rootA] = rootB

		} else if (*rank)[rootA] > (*rank)[rootB] {
			(*parent)[rootB] = rootA

		} else {
			(*parent)[rootB] = rootA
			(*rank)[rootA]++
		}
	}

	return sum
}


func goFromEnd(parent *[]int, rank *[]int, x int64) *value {

	sum := &value{}

	for i := m - 1; i >= 0;  i-- {
		ed := e[i]

		a := ed.from
		b := ed.to

		rootA := find(parent, a)
		rootB := find(parent, b)

		if rootA==rootB {
			continue
		}

		sum.val += int64(abs(ed.w - x))
		sum.l++

		if  (*rank)[rootA] < (*rank)[rootB]{
			(*parent)[rootA] = rootB

		} else if (*rank)[rootA] > (*rank)[rootB] {
			(*parent)[rootB] = rootA

		} else {
			(*parent)[rootB] = rootA
			(*rank)[rootA]++
		}
	}

	return sum
}

func goFrom(idx int, parent *[]int, rank *[]int, x int64) *value {
	sum := &value{}

	var i, j int

	i = idx
	j = idx - 1

	for ; j >= 0 && i < m; {
		e1 := e[i]
		e2 := e[j]

		if abs(e1.w - x) <= abs(e2.w - x) {
			

			a := e1.from
			b := e1.to

			rootA := find(parent, a)
			rootB := find(parent, b)

			if rootA==rootB {
				i++
				continue
			}

			sum.r++
			sum.val += int64(abs(e1.w - x))

			if  (*rank)[rootA] < (*rank)[rootB]{
				(*parent)[rootA] = rootB

			} else if (*rank)[rootA] > (*rank)[rootB] {
				(*parent)[rootB] = rootA

			} else {
				(*parent)[rootB] = rootA
				(*rank)[rootA]++
			}

			i++
		} else {
			

			a := e2.from
			b := e2.to

			rootA := find(parent, a)
			rootB := find(parent, b)

			if rootA==rootB {
				j--
				continue
			}

			sum.l++
			sum.val += int64(abs(e2.w - x))

			if  (*rank)[rootA] < (*rank)[rootB]{
				(*parent)[rootA] = rootB

			} else if (*rank)[rootA] > (*rank)[rootB] {
				(*parent)[rootB] = rootA

			} else {
				(*parent)[rootB] = rootA
				(*rank)[rootA]++
			}

			j--
		}
	}

	for k := j; k >= 0; k-- {
		ed := e[k]

		a := ed.from
		b := ed.to

		rootA := find(parent, a)
		rootB := find(parent, b)

		if rootA == rootB {
			continue
		}

		sum.val += int64(abs(ed.w - x))
		sum.l++

		if (*rank)[rootA] < (*rank)[rootB] {
			(*parent)[rootA] = rootB

		} else if (*rank)[rootA] > (*rank)[rootB] {
			(*parent)[rootB] = rootA

		} else {
			(*parent)[rootB] = rootA
			(*rank)[rootA]++
		}

	}

	for k := i; k < m; k++ {
		ed := e[k]

		a := ed.from
		b := ed.to

		rootA := find(parent, a)
		rootB := find(parent, b)

		if rootA == rootB {
			continue
		}

		sum.val += int64(abs(ed.w - x))
		sum.r++

		if (*rank)[rootA] < (*rank)[rootB] {
			(*parent)[rootA] = rootB

		} else if (*rank)[rootA] > (*rank)[rootB] {
			(*parent)[rootB] = rootA

		} else {
			(*parent)[rootB] = rootA
			(*rank)[rootA]++
		}
	}


	return sum
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}


func add(idx int, delta int, bit *[]int, n int) {
	for ; idx <= n; idx += idx & -idx {
		(*bit)[idx] += delta
	}
}

func get(idx int, bit *[]int) int {
	ret := 0
	for ; idx > 0; idx -= idx & -idx {
		ret += (*bit)[idx];
	}
	return ret
}







func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


type int64InterfaceTreeMap struct {
	endNode   *nodeInt64InterfaceTreeMap
	beginNode *nodeInt64InterfaceTreeMap
	count     int
	

	Less func(a int64, b int64) bool
}

type nodeInt64InterfaceTreeMap struct {
	right   *nodeInt64InterfaceTreeMap
	left    *nodeInt64InterfaceTreeMap
	parent  *nodeInt64InterfaceTreeMap
	isBlack bool
	key     int64
	value   interface{}
}





func newInt64InterfaceTreeMap(less func(a int64, b int64) bool) *int64InterfaceTreeMap {
	endNode := &nodeInt64InterfaceTreeMap{isBlack: true}
	return &int64InterfaceTreeMap{beginNode: endNode, endNode: endNode, Less: less}
}





func (t *int64InterfaceTreeMap) Len() int { return t.count }





func (t *int64InterfaceTreeMap) Set(key int64, value interface{}) {
	parent := t.endNode
	current := parent.left
	less := true
	for current != nil {
		parent = current
		switch {
		case t.Less(key, current.key):
			current = current.left
			less = true
		case t.Less(current.key, key):
			current = current.right
			less = false
		default:
			current.value = value
			return
		}
	}
	x := &nodeInt64InterfaceTreeMap{parent: parent, value: value, key: key}
	if less {
		parent.left = x
	} else {
		parent.right = x
	}
	if t.beginNode.left != nil {
		t.beginNode = t.beginNode.left
	}
	t.insertFixup(x)
	t.count++
}





func (t *int64InterfaceTreeMap) Del(key int64) {
	z := t.findNode(key)
	if z == nil {
		return
	}
	if t.beginNode == z {
		if z.right != nil {
			t.beginNode = z.right
		} else {
			t.beginNode = z.parent
		}
	}
	t.count--
	removeNodeInt64InterfaceTreeMap(t.endNode.left, z)
}





func (t *int64InterfaceTreeMap) Clear() {
	t.count = 0
	t.beginNode = t.endNode
	t.endNode.left = nil
}





func (t *int64InterfaceTreeMap) Get(id int64) (interface{}, bool) {
	node := t.findNode(id)
	if node == nil {
		node = t.endNode
	}
	return node.value, node != t.endNode
}





func (t *int64InterfaceTreeMap) Contains(id int64) bool { return t.findNode(id) != nil }







func (t *int64InterfaceTreeMap) Range(from, to int64) (forwardIteratorInt64InterfaceTreeMap, forwardIteratorInt64InterfaceTreeMap) {
	return t.LowerBound(from), t.UpperBound(to)
}





func (t *int64InterfaceTreeMap) LowerBound(key int64) forwardIteratorInt64InterfaceTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorInt64InterfaceTreeMap{tree: t, node: t.endNode}
	}
	for {
		if t.Less(node.key, key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorInt64InterfaceTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorInt64InterfaceTreeMap{tree: t, node: result}
			}
		}
	}
}





func (t *int64InterfaceTreeMap) UpperBound(key int64) forwardIteratorInt64InterfaceTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorInt64InterfaceTreeMap{tree: t, node: t.endNode}
	}
	for {
		if !t.Less(key, node.key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorInt64InterfaceTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorInt64InterfaceTreeMap{tree: t, node: result}
			}
		}
	}
}









func (t *int64InterfaceTreeMap) Iterator() forwardIteratorInt64InterfaceTreeMap {
	return forwardIteratorInt64InterfaceTreeMap{tree: t, node: t.beginNode}
}









func (t *int64InterfaceTreeMap) Reverse() reverseIteratorInt64InterfaceTreeMap {
	node := t.endNode.left
	if node != nil {
		node = mostRightInt64InterfaceTreeMap(node)
	}
	return reverseIteratorInt64InterfaceTreeMap{tree: t, node: node}
}

func (t *int64InterfaceTreeMap) findNode(id int64) *nodeInt64InterfaceTreeMap {
	current := t.endNode.left
	for current != nil {
		switch {
		case t.Less(id, current.key):
			current = current.left
		case t.Less(current.key, id):
			current = current.right
		default:
			return current
		}
	}
	return nil
}

func mostLeftInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) *nodeInt64InterfaceTreeMap {
	for x.left != nil {
		x = x.left
	}
	return x
}

func mostRightInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) *nodeInt64InterfaceTreeMap {
	for x.right != nil {
		x = x.right
	}
	return x
}

func successorInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) *nodeInt64InterfaceTreeMap {
	if x.right != nil {
		return mostLeftInt64InterfaceTreeMap(x.right)
	}
	for x != x.parent.left {
		x = x.parent
	}
	return x.parent
}

func predecessorInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) *nodeInt64InterfaceTreeMap {
	if x.left != nil {
		return mostRightInt64InterfaceTreeMap(x.left)
	}
	for x.parent != nil && x != x.parent.right {
		x = x.parent
	}
	return x.parent
}

func rotateLeftInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) {
	y := x.right
	x.right = y.left
	if x.right != nil {
		x.right.parent = x
	}
	y.parent = x.parent
	if x == x.parent.left {
		x.parent.left = y
	} else {
		x.parent.right = y
	}
	y.left = x
	x.parent = y
}

func rotateRightInt64InterfaceTreeMap(x *nodeInt64InterfaceTreeMap) {
	y := x.left
	x.left = y.right
	if x.left != nil {
		x.left.parent = x
	}
	y.parent = x.parent
	if x == x.parent.left {
		x.parent.left = y
	} else {
		x.parent.right = y
	}
	y.right = x
	x.parent = y
}

func (t *int64InterfaceTreeMap) insertFixup(x *nodeInt64InterfaceTreeMap) {
	root := t.endNode.left
	x.isBlack = x == root
	for x != root && !x.parent.isBlack {
		if x.parent == x.parent.parent.left {
			y := x.parent.parent.right
			if y != nil && !y.isBlack {
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = x == root
				y.isBlack = true
			} else {
				if x != x.parent.left {
					x = x.parent
					rotateLeftInt64InterfaceTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateRightInt64InterfaceTreeMap(x)
				break
			}
		} else {
			y := x.parent.parent.left
			if y != nil && !y.isBlack {
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = x == root
				y.isBlack = true
			} else {
				if x == x.parent.left {
					x = x.parent
					rotateRightInt64InterfaceTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateLeftInt64InterfaceTreeMap(x)
				break
			}
		}
	}
}





func removeNodeInt64InterfaceTreeMap(root *nodeInt64InterfaceTreeMap, z *nodeInt64InterfaceTreeMap) {
	var y *nodeInt64InterfaceTreeMap
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = successorInt64InterfaceTreeMap(z)
	}
	var x *nodeInt64InterfaceTreeMap
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}
	var w *nodeInt64InterfaceTreeMap
	if x != nil {
		x.parent = y.parent
	}
	if y == y.parent.left {
		y.parent.left = x
		if y != root {
			w = y.parent.right
		} else {
			root = x 

		}
	} else {
		y.parent.right = x
		w = y.parent.left
	}
	removedBlack := y.isBlack
	if y != z {
		y.parent = z.parent
		if z == z.parent.left {
			y.parent.left = y
		} else {
			y.parent.right = y
		}
		y.left = z.left
		y.left.parent = y
		y.right = z.right
		if y.right != nil {
			y.right.parent = y
		}
		y.isBlack = z.isBlack
		if root == z {
			root = y
		}
	}
	if removedBlack && root != nil {
		if x != nil {
			x.isBlack = true
		} else {
			for {
				if w != w.parent.left {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						rotateLeftInt64InterfaceTreeMap(w.parent)
						if root == w.left {
							root = w
						}
						w = w.left.right
					}
					if (w.left == nil || w.left.isBlack) && (w.right == nil || w.right.isBlack) {
						w.isBlack = false
						x = w.parent
						if x == root || !x.isBlack {
							x.isBlack = true
							break
						}
						if x == x.parent.left {
							w = x.parent.right
						} else {
							w = x.parent.left
						}
					} else {
						if w.right == nil || w.right.isBlack {
							w.left.isBlack = true
							w.isBlack = false
							rotateRightInt64InterfaceTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.right.isBlack = true
						rotateLeftInt64InterfaceTreeMap(w.parent)
						break
					}
				} else {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						rotateRightInt64InterfaceTreeMap(w.parent)
						if root == w.right {
							root = w
						}
						w = w.right.left
					}
					if (w.left == nil || w.left.isBlack) && (w.right == nil || w.right.isBlack) {
						w.isBlack = false
						x = w.parent
						if !x.isBlack || x == root {
							x.isBlack = true
							break
						}
						if x == x.parent.left {
							w = x.parent.right
						} else {
							w = x.parent.left
						}
					} else {
						if w.left == nil || w.left.isBlack {
							w.right.isBlack = true
							w.isBlack = false
							rotateLeftInt64InterfaceTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.left.isBlack = true
						rotateRightInt64InterfaceTreeMap(w.parent)
						break
					}
				}
			}
		}
	}
}







type forwardIteratorInt64InterfaceTreeMap struct {
	tree *int64InterfaceTreeMap
	node *nodeInt64InterfaceTreeMap
}





func (i forwardIteratorInt64InterfaceTreeMap) Valid() bool { return i.node != i.tree.endNode }





func (i *forwardIteratorInt64InterfaceTreeMap) Next() {
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
	i.node = successorInt64InterfaceTreeMap(i.node)
}





func (i *forwardIteratorInt64InterfaceTreeMap) Prev() {
	i.node = predecessorInt64InterfaceTreeMap(i.node)
	if i.node == nil {
		panic("out of bound iteration")
	}
}



func (i forwardIteratorInt64InterfaceTreeMap) Key() int64 { return i.node.key }



func (i forwardIteratorInt64InterfaceTreeMap) Value() interface{} { return i.node.value }







type reverseIteratorInt64InterfaceTreeMap struct {
	tree *int64InterfaceTreeMap
	node *nodeInt64InterfaceTreeMap
}





func (i reverseIteratorInt64InterfaceTreeMap) Valid() bool { return i.node != nil }





func (i *reverseIteratorInt64InterfaceTreeMap) Next() {
	if i.node == nil {
		panic("out of bound iteration")
	}
	i.node = predecessorInt64InterfaceTreeMap(i.node)
}





func (i *reverseIteratorInt64InterfaceTreeMap) Prev() {
	if i.node != nil {
		i.node = successorInt64InterfaceTreeMap(i.node)
	} else {
		i.node = i.tree.beginNode
	}
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
}



func (i reverseIteratorInt64InterfaceTreeMap) Key() int64 { return i.node.key }



func (i reverseIteratorInt64InterfaceTreeMap) Value() interface{} { return i.node.value }

