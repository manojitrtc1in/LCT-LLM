package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"sort"
)

const mod = 1e9 + 7
const mod1 = 998244353

type FastIO struct {
	buf    *bytes.Buffer
	reader io.Reader
}

func NewFastIO(r io.Reader) *FastIO {
	return &FastIO{
		buf:    new(bytes.Buffer),
		reader: r,
	}
}

func (f *FastIO) Read() []byte {
	f.buf.Reset()
	_, _ = io.Copy(f.buf, f.reader)
	return f.buf.Bytes()
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

type AVLTree struct {
	tree *TreeNode
}

func NewAVLTree() *AVLTree {
	return &AVLTree{}
}

func (t *AVLTree) Add(k, v int) {
	if t.tree == nil {
		t.tree = &TreeNode{key: k, value: v, height: 1, numLeft: 1, numTotal: 1}
		return
	}
	node := t.add(k, v)
	if node != nil {
		t.rebalance(node)
	}
}

func (t *AVLTree) add(k, v int) *TreeNode {
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

func (t *AVLTree) getHeight(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.height
}

func (t *AVLTree) id1(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.numTotal
}

func (t *AVLTree) rebalance(node *TreeNode) {
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

func (t *AVLTree) rotateRight(node *TreeNode) {
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

func (t *AVLTree) rotateLeft(node *TreeNode) {
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

func (t *AVLTree) isLeft(node *TreeNode) bool {
	return node.parent.left == node
}

func (t *AVLTree) isLeaf(node *TreeNode) bool {
	return node.left == nil && node.right == nil
}

func (t *AVLTree) get(k int) int {
	node := t.getNode(k)
	if node == nil {
		return -1
	}
	return node.value
}

func (t *AVLTree) getNode(k int) *TreeNode {
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

type SegmentTree struct {
	data []int
	size int
}

func NewSegmentTree(data []int, defaultValue int) *SegmentTree {
	n := len(data)
	size := 1 << (n - 1).bitLength()
	st := &SegmentTree{data: make([]int, 2*size), size: size}
	for i := 0; i < n; i++ {
		st.data[size+i] = data[i]
	}
	for i := size - 1; i > 0; i-- {
		st.data[i] = max(st.data[2*i], st.data[2*i+1])
	}
	return st
}

func (st *SegmentTree) Update(idx, value int) {
	idx += st.size
	st.data[idx] = value
	for idx > 1 {
		idx >>= 1
		st.data[idx] = max(st.data[2*idx], st.data[2*idx+1])
	}
}

func (st *SegmentTree) Query(start, stop int) int {
	if start == stop {
		return st.data[start+st.size]
	}
	stop++
	start += st.size
	stop += st.size

	res := 0
	for start < stop {
		if start&1 != 0 {
			res = max(res, st.data[start])
			start++
		}
		if stop&1 != 0 {
			stop--
			res = max(res, st.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	cnt := make([]int, m+1)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cnt[a-1]++
		cnt[b]--
	}
	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}
	l := make([]int, m)
	l1 := make([]int, m)
	cntPairs := make([][2]int, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = [2]int{cnt[i], i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		return cntPairs[i][0] < cntPairs[j][0]
	})
	ind := make(map[int]int)
	for i := range cntPairs {
		ind[cntPairs[i][1]] = i
	}
	s := NewSegmentTree(l, 0)
	s1 := NewSegmentTree(l1, 0)
	cou := make([]int, m)
	cur := 0
	cur1 := 0
	fi := make([]int, m)

	for i := 0; i < m; i++ {
		mw := s.Query(0, ind[i]) + 1
		l[ind[i]] = mw
		fi[i] = mw
		cur1 = max(cur1, mw)
		s.Update(ind[i], mw)
	}

	cntPairs = make([][2]int, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = [2]int{cnt[i], -cnt[i]}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		return cntPairs[i][0] < cntPairs[j][0]
	})
	for i := range cntPairs {
		ind[-cntPairs[i][1]] = i
	}
	for i := m - 1; i >= 0; i-- {
		mw := s1.Query(0, ind[i]) + 1
		fi[i] += mw
		l1[ind[i]] = mw
		s1.Update(ind[i], mw)
	}
	fmt.Println(max(fi...) - 1)
}
