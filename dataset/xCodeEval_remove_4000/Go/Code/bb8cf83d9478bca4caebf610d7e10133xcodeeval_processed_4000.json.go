




package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
	"strings"
)







type constraints_Signed interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64
}







type constraints_Unsigned interface {
	~uint | ~uint8 | ~uint16 | ~uint32 | ~uint64 | ~uintptr
}







type constraints_Integer interface {
	constraints_Signed | constraints_Unsigned
}







type constraints_Float interface {
	~float32 | ~float64
}







type constraints_Complex interface {
	~complex64 | ~complex128
}









type constraints_Ordered interface {
	constraints_Integer | constraints_Float | ~string
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := readInt(in)
	for i := 0; i < n; i++ {
		solution(in, out)
	}
}

func solution(in *bufio.Reader, out *bufio.Writer) {
	v := id11(in)
	q := v[1]

	arr := id11(in)
	sort.Sort(sort.Reverse(sort.IntSlice(arr)))
	tm := id4[int, int]()
	sum := 0
	for i, v := range arr {
		sum += v
		tm.Set(sum, i)
	}

	for i := 0; i < q; i++ {
		

		val := readInt(in)
		if val > sum {
			out.WriteString("-1\n")
			continue
		}
		ans := tm.LowerBound(val).Value() + 1
		out.WriteString(strconv.Itoa(ans) + "\n")
	}
}

func Max(sum int, sum2 int) int {
	if sum > sum2 {
		return sum
	}
	return sum2

}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func readInt(in *bufio.Reader) int {
	nStr, _ := in.ReadString('\n')
	nStr = strings.ReplaceAll(nStr, "\r", "")
	nStr = strings.ReplaceAll(nStr, "\n", "")
	n, _ := strconv.Atoi(nStr)
	return n
}

func readLine(in *bufio.Reader) string {
	line, _ := in.ReadString('\n')
	line = strings.ReplaceAll(line, "\r", "")
	line = strings.ReplaceAll(line, "\n", "")
	return line
}

func id12(in *bufio.Reader) []string {
	line, _ := in.ReadString('\n')
	line = strings.ReplaceAll(line, "\r", "")
	line = strings.ReplaceAll(line, "\n", "")
	numbs := strings.Split(line, " ")
	return numbs
}

func id11(in *bufio.Reader) []int {
	numbs := id12(in)
	arr := make([]int, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.Atoi(n)
		arr[i] = val
	}
	return arr
}

func id6(in *bufio.Reader) []int64 {
	numbs := id12(in)
	arr := make([]int64, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.ParseInt(n, 10, 64)
		arr[i] = val
	}
	return arr
}



type treemap_TreeMap[Key, Value any] struct {
	endNode    *treemap_node[Key, Value]
	beginNode  *treemap_node[Key, Value]
	count      int
	keyCompare func(a Key, b Key) bool
}

type treemap_node[Key, Value any] struct {
	right   *treemap_node[Key, Value]
	left    *treemap_node[Key, Value]
	parent  *treemap_node[Key, Value]
	isBlack bool
	key     Key
	value   Value
}



func id4[Key constraints_Ordered, Value any]() *treemap_TreeMap[Key, Value] {
	endNode := &treemap_node[Key, Value]{isBlack: true}
	return &treemap_TreeMap[Key, Value]{beginNode: endNode, endNode: endNode, keyCompare: id10[Key]}
}





func id2[Key, Value any](
	keyCompare func(a, b Key) bool,
) *treemap_TreeMap[Key, Value] {
	endNode := &treemap_node[Key, Value]{isBlack: true}
	return &treemap_TreeMap[Key, Value]{beginNode: endNode, endNode: endNode, keyCompare: keyCompare}
}





func (t *treemap_TreeMap[Key, Value]) Len() int { return t.count }





func (t *treemap_TreeMap[Key, Value]) Set(key Key, value Value) {
	parent := t.endNode
	current := parent.left
	less := true
	for current != nil {
		parent = current
		switch {
		case t.keyCompare(key, current.key):
			current = current.left
			less = true
		case t.keyCompare(current.key, key):
			current = current.right
			less = false
		default:
			current.value = value
			return
		}
	}
	x := &treemap_node[Key, Value]{parent: parent, value: value, key: key}
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





func (t *treemap_TreeMap[Key, Value]) Del(key Key) {
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
	id8(t.endNode.left, z)
}





func (t *treemap_TreeMap[Key, Value]) Clear() {
	t.count = 0
	t.beginNode = t.endNode
	t.endNode.left = nil
}





func (t *treemap_TreeMap[Key, Value]) Get(id Key) (Value, bool) {
	node := t.findNode(id)
	if node == nil {
		node = t.endNode
	}
	return node.value, node != t.endNode
}





func (t *treemap_TreeMap[Key, Value]) Contains(id Key) bool { return t.findNode(id) != nil }







func (t *treemap_TreeMap[Key, Value]) Range(from, to Key) (treemap_ForwardIterator[Key, Value], treemap_ForwardIterator[Key, Value]) {
	return t.LowerBound(from), t.UpperBound(to)
}





func (t *treemap_TreeMap[Key, Value]) LowerBound(key Key) treemap_ForwardIterator[Key, Value] {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return treemap_ForwardIterator[Key, Value]{tree: t, node: t.endNode}
	}
	for {
		if t.keyCompare(node.key, key) {
			if node.right != nil {
				node = node.right
			} else {
				return treemap_ForwardIterator[Key, Value]{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return treemap_ForwardIterator[Key, Value]{tree: t, node: result}
			}
		}
	}
}





func (t *treemap_TreeMap[Key, Value]) UpperBound(key Key) treemap_ForwardIterator[Key, Value] {
	result := t.endNode
	node := t.endNode.left
	if node == nil {
		return treemap_ForwardIterator[Key, Value]{tree: t, node: t.endNode}
	}
	for {
		if !t.keyCompare(key, node.key) {
			if node.right != nil {
				node = node.right
			} else {
				return treemap_ForwardIterator[Key, Value]{tree: t, node: result}
			}
		} else {
			result = node
			if node.left != nil {
				node = node.left
			} else {
				return treemap_ForwardIterator[Key, Value]{tree: t, node: result}
			}
		}
	}
}









func (t *treemap_TreeMap[Key, Value]) Iterator() treemap_ForwardIterator[Key, Value] {
	return treemap_ForwardIterator[Key, Value]{tree: t, node: t.beginNode}
}









func (t *treemap_TreeMap[Key, Value]) Reverse() treemap_ReverseIterator[Key, Value] {
	node := t.endNode.left
	if node != nil {
		node = id1(node)
	}
	return treemap_ReverseIterator[Key, Value]{tree: t, node: node}
}

func id10[Key constraints_Ordered](
	a, b Key,
) bool {
	return a < b
}

func (t *treemap_TreeMap[Key, Value]) findNode(id Key) *treemap_node[Key, Value] {
	current := t.endNode.left
	for current != nil {
		switch {
		case t.keyCompare(id, current.key):
			current = current.left
		case t.keyCompare(current.key, id):
			current = current.right
		default:
			return current
		}
	}
	return nil
}

func id3[Key, Value any](
	x *treemap_node[Key, Value],
) *treemap_node[Key, Value] {
	for x.left != nil {
		x = x.left
	}
	return x
}

func id1[Key, Value any](
	x *treemap_node[Key, Value],
) *treemap_node[Key, Value] {
	for x.right != nil {
		x = x.right
	}
	return x
}

func id7[Key, Value any](
	x *treemap_node[Key, Value],
) *treemap_node[Key, Value] {
	if x.right != nil {
		return id3(x.right)
	}
	for x != x.parent.left {
		x = x.parent
	}
	return x.parent
}

func id9[Key, Value any](
	x *treemap_node[Key, Value],
) *treemap_node[Key, Value] {
	if x.left != nil {
		return id1(x.left)
	}
	for x.parent != nil && x != x.parent.right {
		x = x.parent
	}
	return x.parent
}

func id5[Key, Value any](
	x *treemap_node[Key, Value],
) {
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

func id0[Key, Value any](
	x *treemap_node[Key, Value],
) {
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

func (t *treemap_TreeMap[Key, Value]) insertFixup(x *treemap_node[Key, Value]) {
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
					id5(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				id0(x)
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
					id0(x)
				}
				x = x.parent
				x.isBlack = true
				x = x.parent
				x.isBlack = false
				id5(x)
				break
			}
		}
	}
}





func id8[Key, Value any](
	root, z *treemap_node[Key, Value],
) {
	var y *treemap_node[Key, Value]
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = id7(z)
	}
	var x *treemap_node[Key, Value]
	if y.left != nil {
		x = y.left
	} else {
		x = y.right
	}
	var w *treemap_node[Key, Value]
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
						id5(w.parent)
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
							id0(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.right.isBlack = true
						id5(w.parent)
						break
					}
				} else {
					if !w.isBlack {
						w.isBlack = true
						w.parent.isBlack = false
						id0(w.parent)
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
							id5(w)
							w = w.parent
						}
						w.isBlack = w.parent.isBlack
						w.parent.isBlack = true
						w.left.isBlack = true
						id0(w.parent)
						break
					}
				}
			}
		}
	}
}







type treemap_ForwardIterator[Key, Value any] struct {
	tree *treemap_TreeMap[Key, Value]
	node *treemap_node[Key, Value]
}





func (i treemap_ForwardIterator[Key, Value]) Valid() bool { return i.node != i.tree.endNode }





func (i *treemap_ForwardIterator[Key, Value]) Next() {
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
	i.node = id7(i.node)
}





func (i *treemap_ForwardIterator[Key, Value]) Prev() {
	i.node = id9(i.node)
	if i.node == nil {
		panic("out of bound iteration")
	}
}



func (i treemap_ForwardIterator[Key, Value]) Key() Key { return i.node.key }



func (i treemap_ForwardIterator[Key, Value]) Value() Value { return i.node.value }







type treemap_ReverseIterator[Key, Value any] struct {
	tree *treemap_TreeMap[Key, Value]
	node *treemap_node[Key, Value]
}





func (i treemap_ReverseIterator[Key, Value]) Valid() bool { return i.node != nil }





func (i *treemap_ReverseIterator[Key, Value]) Next() {
	if i.node == nil {
		panic("out of bound iteration")
	}
	i.node = id9(i.node)
}





func (i *treemap_ReverseIterator[Key, Value]) Prev() {
	if i.node != nil {
		i.node = id7(i.node)
	} else {
		i.node = i.tree.beginNode
	}
	if i.node == i.tree.endNode {
		panic("out of bound iteration")
	}
}



func (i treemap_ReverseIterator[Key, Value]) Key() Key { return i.node.key }



func (i treemap_ReverseIterator[Key, Value]) Value() Value { return i.node.value }
