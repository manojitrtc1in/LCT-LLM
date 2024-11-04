package main

import (
	"bufio"
	"os"
	"fmt"
	"time"
)


const MOD int64 = 1000000007

var n, k int

var a[]int



type ByV []*pair

func (a ByV) Len() int           { return len(a) }
func (a ByV) Less(i, j int) bool { return a[i].v < a[j].v }
func (a ByV) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }


type Item struct {
	rightEnd int
	divideBy int
}

const LOCAL = false


func main() {

	read := bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(read, &t)

	if LOCAL {

		n = 1e5
		k = 1e5

		a = make([]int, 1e5)

		for i := 1; i <= 1e5; i++ {
			a[i - 1] = i
		}

		st := time.Now().UnixNano()
		solve()
		en := time.Now().UnixNano()

		fmt.Println((en - st)/1000000)

		return
	}

	for i := 0; i < t; i++ {

		fmt.Fscan(read, &n, &k)

		a = make([]int, n)

		for j := 0; j < n; j++ {
			fmt.Fscan(read, &a[j])
		}

		fmt.Println(solve())
	}
}

type pair struct {
	v int
	idx []int
}

func solve() int {

	var mn2 int = 1e6

	for i := a[n - 1]; i >= a[n - 1]/k; i-- {
		mx := i

		if i == 0 {
			return 0
		}

		var mn int = 1e6

		can := false

		for j := 0; j < n; j++ {
			if a[j] < mx {
				mn = min(mn, a[j])

			} else if a[j] > mx {
				if a[j]/k > mx {
					break
				}

				d := a[j]/mx
				if d > k {
					d = k
				} else {
					if a[j]/(d) > mx {
						d++
					}
				}


				t := a[j]/d

				if t == mx {
					can = true
				}

				mn = min(mn, t)

			} else {
				can = true
				mn = min(mn, a[j])
			}
		}

		if can {
			mn2 = min(mn2, mx - mn)
		}
	}
	return mn2
}


func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}


type intIntTreeMap struct {
	endNode   *nodeIntIntTreeMap
	beginNode *nodeIntIntTreeMap
	count     int
	

	Less func(a int, b int) bool
}

type nodeIntIntTreeMap struct {
	right   *nodeIntIntTreeMap
	left    *nodeIntIntTreeMap
	parent  *nodeIntIntTreeMap
	isBlack bool
	key     int
	value   int
}





func id7(less func(a int, b int) bool) *intIntTreeMap {
	endNode := &nodeIntIntTreeMap{isBlack: true}
	return &intIntTreeMap{beginNode: endNode, endNode: endNode, Less: less}
}





func (t *intIntTreeMap) Len() int { return t.count }





func (t *intIntTreeMap) Set(key int, value int) {
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
	x := &nodeIntIntTreeMap{parent: parent, value: value, key: key}
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





func (t *intIntTreeMap) Del(key int) {
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
	id6(t.endNode.left, z)
}





func (t *intIntTreeMap) Clear() {
	t.count = 0
	t.beginNode = t.endNode
	t.endNode.left = nil
}





func (t *intIntTreeMap) Get(id int) (int, bool) {
	node := t.findNode(id)
	if node == nil {
		node = t.endNode
	}
	return node.value, node != t.endNode
}





func (t *intIntTreeMap) Contains(id int) bool { return t.findNode(id) != nil }







func (t *intIntTreeMap) Range(from, to int) (forwardIteratorIntIntTreeMap, forwardIteratorIntIntTreeMap) {
	return t.LowerBound(from), t.UpperBound(to)
}





func (t *intIntTreeMap) LowerBound(key int) forwardIteratorIntIntTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorIntIntTreeMap{tree: t, node: t.endNode}
	}
	for {
		if t.Less(node.key, key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorIntIntTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorIntIntTreeMap{tree: t, node: result}
			}
		}
	}
}





func (t *intIntTreeMap) UpperBound(key int) forwardIteratorIntIntTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorIntIntTreeMap{tree: t, node: t.endNode}
	}
	for {
		if !t.Less(key, node.key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorIntIntTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorIntIntTreeMap{tree: t, node: result}
			}
		}
	}
}









func (t *intIntTreeMap) Iterator() forwardIteratorIntIntTreeMap {
	return forwardIteratorIntIntTreeMap{tree: t, node: t.beginNode}
}









func (t *intIntTreeMap) Reverse() reverseIteratorIntIntTreeMap {
	node := t.endNode.left
	if node != nil {
		node = id2(node)
	}
	return reverseIteratorIntIntTreeMap{tree: t, node: node}
}

func (t *intIntTreeMap) findNode(id int) *nodeIntIntTreeMap {
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

func id5(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	for x.left != nil {
		x = x.left
	}
	return x
}

func id2(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	for x.right != nil {
		x = x.right
	}
	return x
}

func id1(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	if x.right != nil {
		return id5(x.right)
	}
	for x != x.parent.left {
		x = x.parent
	}
	return x.parent
}

func id4(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	if x.left != nil {
		return id2(x.left)
	}
	for x.parent != nil && x != x.parent.right {
		x = x.parent
	}
	return x.parent
}

func id0(x *nodeIntIntTreeMap) {
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

func id3(x *nodeIntIntTreeMap) {
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

func (t *intIntTreeMap) insertFixup(x *nodeIntIntTreeMap) {
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
					id0(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				id3(x)
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
					id3(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				id0(x)
				break
			}
		}
	}
}





func id6(root *nodeIntIntTreeMap, z *nodeIntIntTreeMap) {
	var y *nodeIntIntTreeMap
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = id1(z)
	}
	var x *nodeIntIntTreeMap
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}
	var w *nodeIntIntTreeMap
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
						id0(w.parent)
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
							id3(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.right.isBlack = true
						id0(w.parent)
						break
					}
				} else {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						id3(w.parent)
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
							id0(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.left.isBlack = true
						id3(w.parent)
						break
					}
				}
			}
		}
	}
}







type forwardIteratorIntIntTreeMap struct {
	tree *intIntTreeMap
	node *nodeIntIntTreeMap
}





func (i forwardIteratorIntIntTreeMap) Valid() bool { return i.node != i.tree.endNode }





func (i *forwardIteratorIntIntTreeMap) Next() {
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
	i.node = id1(i.node)
}





func (i *forwardIteratorIntIntTreeMap) Prev() {
	i.node = id4(i.node)
	if i.node == nil {
		

	}
}



func (i forwardIteratorIntIntTreeMap) Key() int { return i.node.key }



func (i forwardIteratorIntIntTreeMap) Value() int { return i.node.value }







type reverseIteratorIntIntTreeMap struct {
	tree *intIntTreeMap
	node *nodeIntIntTreeMap
}





func (i reverseIteratorIntIntTreeMap) Valid() bool { return i.node != nil }





func (i *reverseIteratorIntIntTreeMap) Next() {
	if i.node == nil {
		panic("out of bound iteration")
	}
	i.node = id4(i.node)
}





func (i *reverseIteratorIntIntTreeMap) Prev() {
	if i.node != nil {
		i.node = id1(i.node)
	} else {
		i.node = i.tree.beginNode
	}
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
}



func (i reverseIteratorIntIntTreeMap) Key() int { return i.node.key }



func (i reverseIteratorIntIntTreeMap) Value() int { return i.node.value }


