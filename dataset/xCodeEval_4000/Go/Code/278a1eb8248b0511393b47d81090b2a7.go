package main

import (

	"fmt"
	"math/rand"

	"time"

	"bufio"
	"os"
)

type edit struct {
	msg string
	op int
}

type interval struct {
	l, r int
}

const LOCAL = false

func main() {

	if LOCAL {
		rand.Seed(time.Now().UnixNano())

		choices := []string{"lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"}

		var n, t int
		n = 1000
		t = 1000

		for p := 0; p < 100; p++ {

			ops := make([]string, n + 1)
			for i := 1; i <= n; i++ {
				id := rand.Intn(9)
				ops[i] = choices[id]
			}


			edits := make([]edit, t)
			for j := 0; j < t; j++ {
				n := 1 + rand.Intn(1000)
				id := rand.Intn(9)

				edits[j] = edit{ choices[id], n}
			}

			o1 := make([]string, n + 1)
			o2 := make([]string, n + 1)

			for i := 1; i <= n; i++ {
				o1[i] = ops[i]
				o2[i] = ops[i]
			}

			fmt.Println("OPS and Edits--")
			fmt.Println(ops)
			fmt.Println(edits)

			a1 := solve(o1, edits, n,  t)
			

			fmt.Println(len(a1))

			
		}

	} else {

		w := bufio.NewWriter(os.Stdout)
		r := bufio.NewReader(os.Stdin)
		var n, t int
		fmt.Fscan(r, &n)

		ops := make([]string, n + 1)
		for i := 1; i <= n; i++ {
			fmt.Fscan(r, &ops[i])
		}

		fmt.Fscan(r, &t)

		edits := make([]edit, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(r, &edits[j].op, &edits[j].msg)
		}


		o1 := make([]string, n + 1)
		o2 := make([]string, n + 1)

		for i := 1; i <= n; i++ {
			o1[i] = ops[i]
			o2[i] = ops[i]
		}

		a1 := solve(o1, edits, n,  t)

		for i := 0; i < len(a1); i++ {
			fmt.Fprintln(w, a1[i])
		}
		w.Flush()
	}

}

func solve_stupid(ops []string, edits []edit , n int, t int) []string {

	color := "blue"
	locked := false
	var resp []string


	for i := 1; i <= n; i++ {
		o := ops[i]

		if o == "lock" {
			locked = true

		} else if o == "unlock" {
			locked = false

		} else {
			if locked {
				continue
			}

			color = o
		}
	}
	resp = append(resp, color)


	for i := 0 ; i < t; i++ {

		e := edits[i]
		ops[e.op] = e.msg


		color := "blue"
		locked := false

		for i := 1; i <= n; i++ {
			o := ops[i]

			if o == "lock" {
				locked = true

			} else if o == "unlock" {
				locked = false

			} else {
				if locked {
					continue
				}

				color = o
			}
		}

		resp = append(resp, color)
	}

	return resp

}



func solve(ops []string, edits []edit , n int, t int) []string {
	var resp []string

	locks := newIntIntTreeMap(func(a int, b int) bool {
		return a < b
	})
	unlocks := newIntIntTreeMap(func(a int, b int) bool {
		return a < b
	})

	colors := newIntInterfaceTreeMap(func(a int, b int) bool {
		return a < b
	})


	color := "blue"
	locked := false
	start := -1

	for i := 1; i <= n; i++ {
		o := ops[i]

		if o == "lock" {
			locked = true
			locks.Set(i, 0)

			if start != -1 {
				colors.Set(start, &interval{start, i - 1})
				start = -1
			}

		} else if o == "unlock" {
			locked = false
			unlocks.Set(i, 0)

			if start != -1 {
				colors.Set(start, &interval{start, i - 1})
				start = -1
			}

		} else {
			if locked {
				continue
			}

			if start == -1 {
				start = i
			}

			color = o
		}
	}
	if start != -1 {
		colors.Set(start, &interval{start, n})
	}


	resp = append(resp, color)


	for i := 0; i < t; i++ {
		e := edits[i]


		msg := e.msg
		op := e.op

		if msg == "lock" {
			if ops[op] == "lock" {

			} else if ops[op] == "unlock" {
				itl := locks.UpperBound(op)
				itu := unlocks.UpperBound(op)

				var m int

				if itl.Valid() {
					if itu.Valid() {
						m = min(itl.Key(), itu.Key())

					} else {
						m = itl.Key()
					}


				} else {
					if itu.Valid() {
						m = itu.Key()

					} else {
						m = n
					}
				}

				if m >= op + 1 {
					colors.Del(op + 1)
				}


				locks.Set(op, 0)
				unlocks.Del(op)


			} else {
				it := colors.LowerBound(op)

				if it.Valid() {
					if it.Key() == op {
						colors.Del(op)
					}
				}
				it.Prev()
				if it.node != nil {
					ival := it.Value().(*interval)

					if ival.l < op && ival.r >= op {
						colors.Del(ival.l)
						colors.Set(ival.l, &interval{ival.l, op - 1})
					}
				}



				locks.Set(op, 0)
			}

			ops[op] = msg


		} else if msg == "unlock" {

			if ops[op] == "unlock" {

			} else if ops[op] == "lock" {
				itl := locks.UpperBound(op)
				itu := unlocks.LowerBound(op)

				if !itl.Valid() {
					var r int
					if !itu.Valid() {
						r = n
					} else {
						r = itu.Key() - 1
					}

					if op + 1 <= r {
						colors.Set(op + 1, &interval{op + 1, r})
					}


				} else {
					var r int
					if !itu.Valid() {
						r = itl.Key() - 1
					} else {
						r = min(itl.Key() - 1, itu.Key() - 1)
					}

					if r >= op + 1 {
						colors.Set(op + 1, &interval{op + 1, r})
					}
				}

				locks.Del(op)
				unlocks.Set(op, 0)



			} else {
				it := colors.LowerBound(op)

				if it.Valid() {
					if it.Key() == op {
						colors.Del(op)

						if op + 1 <= it.Value().(*interval).r {
							colors.Set(op + 1, &interval{op + 1, it.Value().(*interval).r})
						}
					}
				}
				it.Prev()

				if it.node != nil {
					ival := it.Value().(*interval)

					if ival.l < op && ival.r >= op {
						colors.Del(ival.l)

						if op == ival.r {
							colors.Set(ival.l, &interval{ival.l, op -  1})
						} else {
							colors.Set(ival.l, &interval{ival.l, op -  1})
							colors.Set(op +  1, &interval{op +  1, ival.r})
						}
					}
				}


				itl := locks.LowerBound(op)
				itu := unlocks.LowerBound(op)
				itu.Prev()
				itl.Prev()

				doScan := false

				if itl.node != nil {
					indexLock := itl.Key()

					if itu.node != nil {
						indexUnlock := itu.Key()

						if indexLock > indexUnlock {
							doScan = true
						}

					} else {
						doScan = true
					}

				}

				if doScan {
					itl := locks.UpperBound(op)
					itu := unlocks.UpperBound(op)

					var index int

					if itu.Valid() {
						if itl.Valid() {
							index = min(itu.Key(), itl.Key()) - 1

						} else {
							index = itu.Key() - 1
						}

					} else {
						if itl.Valid() {
							index = itl.Key() - 1

						} else {
							index = n
						}
					}

					if op + 1 <= index {
						colors.Set(op + 1, &interval{op + 1, index})
					}

				}

				unlocks.Set(op, 0)
			}

			ops[op] = msg



		} else {

			if ops[op] == "lock" {
				itl := locks.LowerBound(op)
				itu := unlocks.LowerBound(op)
				itl.Prev()
				itu.Prev()

				start := -1
				end := - 1

				if itl.node != nil {
					if itu.node != nil {

						if itu.Key() > itl.Key() {
							start = itu.Key() + 1
						}
					}

				} else {
					if itu.node != nil {
						start = itu.Key() + 1

					} else {
						start = 1
					}
				}

				itl = locks.UpperBound(op)
				itu = unlocks.UpperBound(op)

				if itl.Valid() {
					if itu.Valid() {
						m := min(itl.Key(), itu.Key())
						end = m - 1

					} else {
						end = itl.Key() - 1
					}
				} else {
					if itu.Valid() {
						end = itu.Key() - 1
					} else {
						end = n
					}
				}

				if start != -1 {
					colors.Del(start)
					colors.Set(start, &interval{start, end})
				}

				locks.Del(op)
				ops[op] = msg


			} else if ops[op] == "unlock" {
				itl := locks.LowerBound(op)
				itu := unlocks.LowerBound(op)
				itl.Prev()
				itu.Prev()

				start := -1
				end := -1

				if itl.node != nil {
					if itu.node != nil {

						if itu.Key() > itl.Key() {
							start = itu.Key() + 1
						}
					}

				} else {
					if itu.node != nil {
						start = itu.Key() + 1

					} else {
						start = 1
					}
				}


				itl = locks.UpperBound(op)
				itu = unlocks.UpperBound(op)

				if itl.Valid() {
					if itu.Valid() {
						m := min(itu.Key(), itl.Key())
						end = m - 1

					} else {
						end = itl.Key() - 1
					}

				} else {
					if itu.Valid() {
						end = itu.Key() - 1

					} else {
						end = n
					}
				}

				if colors.Contains(op + 1) {
					colors.Del(op + 1)
				}

				if start != -1 {
					colors.Set(start, &interval{start, end})
				}


				unlocks.Del(op)
				ops[op] = msg

			} else {
				ops[op] = msg
			}

		}


		it := colors.LowerBound(n)

		var rightMost *interval
		if it.Valid() {
			resp = append(resp, ops[n])

		} else {
			it.Prev()
			if it.node == nil {
				resp = append(resp, "blue")
			} else {
				rightMost = it.Value().(*interval)
				if rightMost.r == 0 {
					resp = append(resp, "blue")
				} else {
					resp = append(resp, ops[rightMost.r])
				}
			}
		}
	}

	return resp
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
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





func newIntIntTreeMap(less func(a int, b int) bool) *intIntTreeMap {
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
	removeNodeIntIntTreeMap(t.endNode.left, z)
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
		node = mostRightIntIntTreeMap(node)
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

func mostLeftIntIntTreeMap(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	for x.left != nil {
		x = x.left
	}
	return x
}

func mostRightIntIntTreeMap(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	for x.right != nil {
		x = x.right
	}
	return x
}

func successorIntIntTreeMap(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	if x.right != nil {
		return mostLeftIntIntTreeMap(x.right)
	}
	for x != x.parent.left {
		x = x.parent
	}
	return x.parent
}

func predecessorIntIntTreeMap(x *nodeIntIntTreeMap) *nodeIntIntTreeMap {
	if x.left != nil {
		return mostRightIntIntTreeMap(x.left)
	}
	for x.parent != nil && x != x.parent.right {
		x = x.parent
	}
	return x.parent
}

func rotateLeftIntIntTreeMap(x *nodeIntIntTreeMap) {
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

func rotateRightIntIntTreeMap(x *nodeIntIntTreeMap) {
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
					rotateLeftIntIntTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateRightIntIntTreeMap(x)
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
					rotateRightIntIntTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateLeftIntIntTreeMap(x)
				break
			}
		}
	}
}





func removeNodeIntIntTreeMap(root *nodeIntIntTreeMap, z *nodeIntIntTreeMap) {
	var y *nodeIntIntTreeMap
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = successorIntIntTreeMap(z)
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
						rotateLeftIntIntTreeMap(w.parent)
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
							rotateRightIntIntTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.right.isBlack = true
						rotateLeftIntIntTreeMap(w.parent)
						break
					}
				} else {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						rotateRightIntIntTreeMap(w.parent)
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
							rotateLeftIntIntTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.left.isBlack = true
						rotateRightIntIntTreeMap(w.parent)
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
	i.node = successorIntIntTreeMap(i.node)
}





func (i *forwardIteratorIntIntTreeMap) Prev() {
	i.node = predecessorIntIntTreeMap(i.node)
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
	i.node = predecessorIntIntTreeMap(i.node)
}





func (i *reverseIteratorIntIntTreeMap) Prev() {
	if i.node != nil {
		i.node = successorIntIntTreeMap(i.node)
	} else {
		i.node = i.tree.beginNode
	}
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
}



func (i reverseIteratorIntIntTreeMap) Key() int { return i.node.key }



func (i reverseIteratorIntIntTreeMap) Value() int { return i.node.value }






type intInterfaceTreeMap struct {
	endNode   *nodeIntInterfaceTreeMap
	beginNode *nodeIntInterfaceTreeMap
	count     int
	

	Less func(a int, b int) bool
}

type nodeIntInterfaceTreeMap struct {
	right   *nodeIntInterfaceTreeMap
	left    *nodeIntInterfaceTreeMap
	parent  *nodeIntInterfaceTreeMap
	isBlack bool
	key     int
	value   interface{}
}





func newIntInterfaceTreeMap(less func(a int, b int) bool) *intInterfaceTreeMap {
	endNode := &nodeIntInterfaceTreeMap{isBlack: true}
	return &intInterfaceTreeMap{beginNode: endNode, endNode: endNode, Less: less}
}





func (t *intInterfaceTreeMap) Len() int { return t.count }





func (t *intInterfaceTreeMap) Set(key int, value interface{}) {
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
	x := &nodeIntInterfaceTreeMap{parent: parent, value: value, key: key}
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





func (t *intInterfaceTreeMap) Del(key int) {
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
	removeNodeIntInterfaceTreeMap(t.endNode.left, z)
}





func (t *intInterfaceTreeMap) Clear() {
	t.count = 0
	t.beginNode = t.endNode
	t.endNode.left = nil
}





func (t *intInterfaceTreeMap) Get(id int) (interface{}, bool) {
	node := t.findNode(id)
	if node == nil {
		node = t.endNode
	}
	return node.value, node != t.endNode
}





func (t *intInterfaceTreeMap) Contains(id int) bool { return t.findNode(id) != nil }







func (t *intInterfaceTreeMap) Range(from, to int) (forwardIteratorIntInterfaceTreeMap, forwardIteratorIntInterfaceTreeMap) {
	return t.LowerBound(from), t.UpperBound(to)
}





func (t *intInterfaceTreeMap) LowerBound(key int) forwardIteratorIntInterfaceTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorIntInterfaceTreeMap{tree: t, node: t.endNode}
	}
	for {
		if t.Less(node.key, key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorIntInterfaceTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorIntInterfaceTreeMap{tree: t, node: result}
			}
		}
	}
}





func (t *intInterfaceTreeMap) UpperBound(key int) forwardIteratorIntInterfaceTreeMap {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return forwardIteratorIntInterfaceTreeMap{tree: t, node: t.endNode}
	}
	for {
		if !t.Less(key, node.key) {
			if node.right != nil {
				node = node.right
			} else {
				return forwardIteratorIntInterfaceTreeMap{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return forwardIteratorIntInterfaceTreeMap{tree: t, node: result}
			}
		}
	}
}









func (t *intInterfaceTreeMap) Iterator() forwardIteratorIntInterfaceTreeMap {
	return forwardIteratorIntInterfaceTreeMap{tree: t, node: t.beginNode}
}









func (t *intInterfaceTreeMap) Reverse() reverseIteratorIntInterfaceTreeMap {
	node := t.endNode.left
	if node != nil {
		node = mostRightIntInterfaceTreeMap(node)
	}
	return reverseIteratorIntInterfaceTreeMap{tree: t, node: node}
}

func (t *intInterfaceTreeMap) findNode(id int) *nodeIntInterfaceTreeMap {
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

func mostLeftIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) *nodeIntInterfaceTreeMap {
	for x.left != nil {
		x = x.left
	}
	return x
}

func mostRightIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) *nodeIntInterfaceTreeMap {
	for x.right != nil {
		x = x.right
	}
	return x
}

func successorIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) *nodeIntInterfaceTreeMap {
	if x.right != nil {
		return mostLeftIntInterfaceTreeMap(x.right)
	}
	for x != x.parent.left {
		x = x.parent
	}
	return x.parent
}

func predecessorIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) *nodeIntInterfaceTreeMap {
	if x.left != nil {
		return mostRightIntInterfaceTreeMap(x.left)
	}
	for x.parent != nil && x != x.parent.right {
		x = x.parent
	}
	return x.parent
}

func rotateLeftIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) {
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

func rotateRightIntInterfaceTreeMap(x *nodeIntInterfaceTreeMap) {
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

func (t *intInterfaceTreeMap) insertFixup(x *nodeIntInterfaceTreeMap) {
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
					rotateLeftIntInterfaceTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateRightIntInterfaceTreeMap(x)
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
					rotateRightIntInterfaceTreeMap(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				rotateLeftIntInterfaceTreeMap(x)
				break
			}
		}
	}
}





func removeNodeIntInterfaceTreeMap(root *nodeIntInterfaceTreeMap, z *nodeIntInterfaceTreeMap) {
	var y *nodeIntInterfaceTreeMap
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = successorIntInterfaceTreeMap(z)
	}
	var x *nodeIntInterfaceTreeMap
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}
	var w *nodeIntInterfaceTreeMap
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
						rotateLeftIntInterfaceTreeMap(w.parent)
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
							rotateRightIntInterfaceTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.right.isBlack = true
						rotateLeftIntInterfaceTreeMap(w.parent)
						break
					}
				} else {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						rotateRightIntInterfaceTreeMap(w.parent)
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
							rotateLeftIntInterfaceTreeMap(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.left.isBlack = true
						rotateRightIntInterfaceTreeMap(w.parent)
						break
					}
				}
			}
		}
	}
}







type forwardIteratorIntInterfaceTreeMap struct {
	tree *intInterfaceTreeMap
	node *nodeIntInterfaceTreeMap
}





func (i forwardIteratorIntInterfaceTreeMap) Valid() bool { return i.node != i.tree.endNode }





func (i *forwardIteratorIntInterfaceTreeMap) Next() {
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
	i.node = successorIntInterfaceTreeMap(i.node)
}





func (i *forwardIteratorIntInterfaceTreeMap) Prev() {
	i.node = predecessorIntInterfaceTreeMap(i.node)
	if i.node == nil {

	}
}



func (i forwardIteratorIntInterfaceTreeMap) Key() int { return i.node.key }



func (i forwardIteratorIntInterfaceTreeMap) Value() interface{} { return i.node.value }







type reverseIteratorIntInterfaceTreeMap struct {
	tree *intInterfaceTreeMap
	node *nodeIntInterfaceTreeMap
}





func (i reverseIteratorIntInterfaceTreeMap) Valid() bool { return i.node != nil }





func (i *reverseIteratorIntInterfaceTreeMap) Next() {
	if i.node == nil {
		panic("out of bound iteration")
	}
	i.node = predecessorIntInterfaceTreeMap(i.node)
}





func (i *reverseIteratorIntInterfaceTreeMap) Prev() {
	if i.node != nil {
		i.node = successorIntInterfaceTreeMap(i.node)
	} else {
		i.node = i.tree.beginNode
	}
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
}



func (i reverseIteratorIntInterfaceTreeMap) Key() int { return i.node.key }



func (i reverseIteratorIntInterfaceTreeMap) Value() interface{} { return i.node.value }