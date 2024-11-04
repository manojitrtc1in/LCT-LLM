package main

import (
	"bytes"
	"fmt"
	"os"
	"sort"
)

const mod = 1e9 + 7

type TreeNode struct {
	key      int
	value    int
	left     *TreeNode
	right    *TreeNode
	parent   *TreeNode
	height   int
	numLeft  int
	numTotal int
}

type id10 struct {
	tree *TreeNode
}

func (t *id10) add(k, v int) {
	if t.tree == nil {
		t.tree = &TreeNode{key: k, value: v, height: 1, numLeft: 1, numTotal: 1}
		return
	}
	node := t._add(k, v)
	if node != nil {
		t._rebalance(node)
	}
}

func (t *id10) _add(k, v int) *TreeNode {
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

func (t *id10) _rebalance(node *TreeNode) {
	n := node
	for n != nil {
		lh := t.getHeight(n.left)
		rh := t.getHeight(n.right)
		n.height = max(lh, rh) + 1
		balanceFactor := lh - rh
		n.numTotal = 1 + t.id2(n.left) + t.id2(n.right)
		n.numLeft = 1 + t.id2(n.left)

		if balanceFactor > 1 {
			if t.getHeight(n.left.left) < t.getHeight(n.left.right) {
				t._rotateLeft(n.left)
			}
			t._rotateRight(n)
		} else if balanceFactor < -1 {
			if t.getHeight(n.right.right) < t.getHeight(n.right.left) {
				t._rotateRight(n.right)
			}
			t._rotateLeft(n)
		} else {
			n = n.parent
		}
	}
}

func (t *id10) getHeight(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.height
}

func (t *id10) id2(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.numTotal
}

func (t *id10) _rotateRight(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.left
		node.left.parent = nil
	} else if t._isLeft(node) {
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
	node.numTotal = 1 + t.id2(node.left) + t.id2(node.right)
	node.numLeft = 1 + t.id2(node.left)
}

func (t *id10) _rotateLeft(node *TreeNode) {
	if node.parent == nil {
		t.tree = node.right
		node.right.parent = nil
	} else if t._isLeft(node) {
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
	node.numTotal = 1 + t.id2(node.left) + t.id2(node.right)
	node.numLeft = 1 + t.id2(node.left)
}

func (t *id10) _isLeft(node *TreeNode) bool {
	return node.parent.left == node
}

func (t *id10) _isLeaf(node *TreeNode) bool {
	return node.left == nil && node.right == nil
}

func (t *id10) remove(k int) {
	node := t._getNode(k)
	if node == nil {
		return
	}
	if t._isLeaf(node) {
		t._removeLeaf(node)
		return
	}
	if node.left != nil && node.right != nil {
		nxt := t._getNext(node)
		node.key = nxt.key
		node.value = nxt.value
		if t._isLeaf(nxt) {
			t._removeLeaf(nxt)
		} else {
			t._removeOne(nxt)
		}
		t._rebalance(node)
	} else {
		t._removeOne(node)
	}
}

func (t *id10) _removeOne(node *TreeNode) {
	replacement := node.left
	if replacement == nil {
		replacement = node.right
	}
	if node.parent != nil {
		if t._isLeft(node) {
			node.parent.left = replacement
		} else {
			node.parent.right = replacement
		}
		if replacement != nil {
			replacement.parent = node.parent
		}
	} else {
		t.tree = replacement
		if replacement != nil {
			replacement.parent = nil
		}
	}
	node.left = nil
	node.right = nil
	node.parent = nil
	t._rebalance(replacement)
}

func (t *id10) _removeLeaf(node *TreeNode) {
	if node.parent != nil {
		if t._isLeft(node) {
			node.parent.left = nil
		} else {
			node.parent.right = nil
		}
		t._rebalance(node.parent)
	} else {
		t.tree = nil
	}
	node.parent = nil
	node.left = nil
	node.right = nil
}

func (t *id10) _getNode(k int) *TreeNode {
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

func (t *id10) _getNext(node *TreeNode) *TreeNode {
	if node.right == nil {
		return node.parent
	}
	n := node.right
	for n.left != nil {
		n = n.left
	}
	return n
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	t := make([][2]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&t[i][0], &t[i][1])
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] < t[j][0]
	})

	check := func(x int) bool {
		now := x
		c := sum(l)
		cur := 0
		last := 0
		ld := make(map[int]int)
		for i := 0; i < m; i++ {
			if t[i][0] <= x {
				ld[t[i][1]] = i
			}
		}
		for i := 0; i < m; i++ {
			if ld[t[i][1]] != i {
				continue
			}
			if t[i][0] > x {
				break
			}
			cur += t[i][0] - last
			rt := min(cur, l[t[i][1]-1])
			cur -= rt
			now -= rt
			c -= rt
			last = t[i][0]
		}
		return now >= 2*c
	}

	st, end := 1, 2*sum(l)
	ans := end
	for st <= end {
		mid := (st + end) / 2
		if check(mid) {
			ans = mid
			end = mid - 1
		} else {
			st = mid + 1
		}
	}
	fmt.Println(ans)
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
