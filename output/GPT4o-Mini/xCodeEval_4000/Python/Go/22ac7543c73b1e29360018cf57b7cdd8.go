package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
	"math"
	"os"
	"sort"
)

const mod = 1e9 + 7
const mod1 = 998244353

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

type AvlTree struct {
	tree *TreeNode
}

func NewAvlTree() *AvlTree {
	return &AvlTree{}
}

func (t *AvlTree) Add(k, v int) {
	if t.tree == nil {
		t.tree = &TreeNode{key: k, value: v, height: 1, numLeft: 1, numTotal: 1}
		return
	}
	node := t.add(k, v)
	if node != nil {
		t.rebalance(node)
	}
}

func (t *AvlTree) add(k, v int) *TreeNode {
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

func (t *AvlTree) getHeight(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.height
}

func (t *AvlTree) getNumTotal(x *TreeNode) int {
	if x == nil {
		return 0
	}
	return x.numTotal
}

func (t *AvlTree) rebalance(node *TreeNode) {
	n := node
	for n != nil {
		lh := t.getHeight(n.left)
		rh := t.getHeight(n.right)
		n.height = max(lh, rh) + 1
		balanceFactor := lh - rh
		n.numTotal = 1 + t.getNumTotal(n.left) + t.getNumTotal(n.right)
		n.numLeft = 1 + t.getNumTotal(n.left)

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

func (t *AvlTree) rotateRight(node *TreeNode) {
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
	node.numTotal = 1 + t.getNumTotal(node.left) + t.getNumTotal(node.right)
	node.numLeft = 1 + t.getNumTotal(node.left)
}

func (t *AvlTree) rotateLeft(node *TreeNode) {
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
	node.numTotal = 1 + t.getNumTotal(node.left) + t.getNumTotal(node.right)
	node.numLeft = 1 + t.getNumTotal(node.left)
}

func (t *AvlTree) isLeft(node *TreeNode) bool {
	return node.parent.left != nil && node.parent.left == node
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
		for i := 0; i < len(t); i++ {
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

	st := 1
	end := 2 * sum(l)
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
