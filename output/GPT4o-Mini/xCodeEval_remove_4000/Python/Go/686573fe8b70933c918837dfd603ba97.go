package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

const mod = 1e9 + 7
const mod1 = 998244353

type FastIO struct {
	buf    bytes.Buffer
	writer io.Writer
}

func NewFastIO(w io.Writer) *FastIO {
	return &FastIO{writer: w}
}

func (f *FastIO) ReadLine() string {
	line := make([]byte, 0, 100)
	for {
		b := make([]byte, 1)
		_, err := os.Stdin.Read(b)
		if err != nil || b[0] == '\n' {
			break
		}
		line = append(line, b[0])
	}
	return string(line)
}

func (f *FastIO) WriteString(s string) {
	f.buf.WriteString(s)
}

func (f *FastIO) Flush() {
	f.writer.Write(f.buf.Bytes())
	f.buf.Reset()
}

type TreeNode struct {
	key       int
	value     int
	left      *TreeNode
	right     *TreeNode
	parent    *TreeNode
	height    int
	numLeft   int
	numTotal  int
}

type Id8 struct {
	tree *TreeNode
}

func NewId8() *Id8 {
	return &Id8{}
}

func (t *Id8) Add(k, v int) {
	if t.tree == nil {
		t.tree = &TreeNode{key: k, value: v, height: 1, numLeft: 1, numTotal: 1}
		return
	}
	node := t.add(k, v)
	if node != nil {
		t.rebalance(node)
	}
}

func (t *Id8) add(k, v int) *TreeNode {
	node := t.tree
	for node != nil {
		if k < node.key {
			if node.left != nil {
				node = node.left
			} else {
				node.left = &TreeNode{key: k, value: v, parent: node}
				return node.left
			}
		} else if node.key < k {
			if node.right != nil {
				node = node.right
			} else {
				node.right = &TreeNode{key: k, value: v, parent: node}
				return node.right
			}
		} else {
			node.value = v
			return nil
		}
	}
	return nil
}

func (t *Id8) getHeight(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.height
}

func (t *Id8) id1(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.numTotal
}

func (t *Id8) rebalance(node *TreeNode) {
	n := node
	for n != nil {
		lh := t.getHeight(n.left)
		rh := t.getHeight(n.right)
		n.height = max(lh, rh) + 1
		balanceFactor := lh - rh
		n.numTotal = 1 + t.id1(n.left) + t.id1(n.right)
		n.numLeft = 1 + t.id1(n.left)

		if balanceFactor > 1 {
			if t.getHeight(n.left.left) < t.getHeight(n.left.right) {
				t.rotateLeft(n.left)
			}
			t.rotateRight(n)
		} else if balanceFactor < -1 {
			if t.getHeight(n.right.right) < t.getHeight(n.right.left) {
				t.rotateRight(n.right)
			}
			t.rotateLeft(n)
		} else {
			n = n.parent
		}
	}
}

func (t *Id8) rotateRight(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.left
		node.left.parent = nil
	} else if t.isLeft(node) {
		node.parent.left = node.left
		node.left.parent = node.parent
	} else {
		node.parent.right = node.left
		node.left.parent = node.parent
	}
	bk := node.left.right
	node.left.right = node
	node.parent = node.left
	node.left = bk
	if bk != nil {
		bk.parent = node
	}
	node.height = max(t.getHeight(node.left), t.getHeight(node.right)) + 1
	node.numTotal = 1 + t.id1(node.left) + t.id1(node.right)
	node.numLeft = 1 + t.id1(node.left)
}

func (t *Id8) rotateLeft(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.right
		node.right.parent = nil
	} else if t.isLeft(node) {
		node.parent.left = node.right
		node.right.parent = node.parent
	} else {
		node.parent.right = node.right
		node.right.parent = node.parent
	}
	bk := node.right.left
	node.right.left = node
	node.parent = node.right
	node.right = bk
	if bk != nil {
		bk.parent = node
	}
	node.height = max(t.getHeight(node.left), t.getHeight(node.right)) + 1
	node.numTotal = 1 + t.id1(node.left) + t.id1(node.right)
	node.numLeft = 1 + t.id1(node.left)
}

func (t *Id8) isLeft(node *TreeNode) bool {
	return node.parent.left == node
}

func (t *Id8) isLeaf(node *TreeNode) bool {
	return node.left == nil && node.right == nil
}

func (t *Id8) Remove(k int) {
	node := t.getNode(k)
	if node == nil {
		return
	}
	if t.isLeaf(node) {
		t.removeLeaf(node)
		return
	}
	if node.left != nil && node.right != nil {
		nxt := t.getNext(node)
		node.key = nxt.key
		node.value = nxt.value
		if t.isLeaf(nxt) {
			t.removeLeaf(nxt)
		} else {
			t.removeOne(nxt)
		}
		t.rebalance(node)
	} else {
		t.removeOne(node)
	}
}

func (t *Id8) getNode(k int) *TreeNode {
	if t.tree == nil {
		return nil
	}
	node := t.tree
	for node != nil {
		if k < node.key {
			node = node.left
		} else if node.key < k {
			node = node.right
		} else {
			return node
		}
	}
	return nil
}

func (t *Id8) getNext(node *TreeNode) *TreeNode {
	if node.right == nil {
		return node.parent
	}
	n := node.right
	for n.left != nil {
		n = n.left
	}
	return n
}

func (t *Id8) removeOne(node *TreeNode) {
	replacement := node.left
	if replacement == nil {
		replacement = node.right
	}
	if node.parent != nil {
		if t.isLeft(node) {
			node.parent.left = replacement
		} else {
			node.parent.right = replacement
		}
		if replacement != nil {
			replacement.parent = node.parent
		}
		node.parent = nil
	} else {
		t.tree = replacement
		if replacement != nil {
			replacement.parent = nil
		}
	}
	node.left = nil
	node.right = nil
	node.parent = nil
	t.rebalance(replacement)
}

func (t *Id8) removeLeaf(node *TreeNode) {
	if node.parent != nil {
		if t.isLeft(node) {
			node.parent.left = nil
		} else {
			node.parent.right = nil
		}
		t.rebalance(node.parent)
	} else {
		t.tree = nil
	}
	node.parent = nil
	node.left = nil
	node.right = nil
}

func (t *Id8) Get(k int) int {
	node := t.getNode(k)
	if node == nil {
		return -1
	}
	return node.value
}

func (t *Id8) GetAt(pos int) (int, int) {
	x := pos + 1
	node := t.tree
	for node != nil {
		if x < node.numLeft {
			node = node.left
		} else if node.numLeft < x {
			x -= node.numLeft
			node = node.right
		} else {
			return node.key, node.value
		}
	}
	panic("Out of ranges")
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	l := make([][]int, n)
	for i := 0; i < n; i++ {
		l[i] = make([]int, 5)
		for j := 0; j < 5; j++ {
			fmt.Scan(&l[i][j])
		}
	}
	if n >= 50 {
		fmt.Println(0)
		return
	}
	if n <= 2 {
		fmt.Println(n)
		for i := 0; i < n; i++ {
			fmt.Println(i + 1)
		}
		return
	}
	er := make(map[int]struct{})
	for i := 0; i < n; i++ {
		f := 0
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if i == j || i == k || j == k {
					continue
				}
				w := 0
				for d := 0; d < 5; d++ {
					w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d])
				}
				if w > 0 {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 0 {
			er[i+1] = struct{}{}
		}
	}
	fmt.Println(len(er))
	for key := range er {
		fmt.Println(key)
	}
}
