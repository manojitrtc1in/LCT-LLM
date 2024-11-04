package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const maxn = 500005

type Node struct {
	lh  *ListHead
	sh  *Id14
	v   int
	pos int
}

type ListHead struct {
	prev, next *ListHead
}

func (lh *ListHead) reset() {
	lh.prev = lh
	lh.next = lh
}

func (lh *ListHead) insertNext(newNext *ListHead) {
	link(*lh.prev, *newNext)
	link(*lh, *newNext)
}

func (lh *ListHead) insertPrev(newPrev *ListHead) {
	link(*lh.prev, *newPrev)
	link(*newPrev, *lh)
}

func link(prev, next ListHead) {
	prev.next = &next
	next.prev = &prev
}

type Id14 struct {
	lc, rc, p *Id14
	size      int
}

func (id *Id14) reset() {
	id.lc = nil
	id.rc = nil
	id.p = nil
	id.size = 1
}

func (id *Id14) updateSize() {
	id.size = 1
	if id.lc != nil {
		id.size += id.lc.size
	}
	if id.rc != nil {
		id.size += id.rc.size
	}
}

type SplayTree struct {
	root *Id14
}

func (st *SplayTree) size() int {
	if st.root != nil {
		return st.root.size
	}
	return 0
}

func (st *SplayTree) insert(node *Node) {
	x := node.sh
	x.rc = st.root
	if st.root != nil {
		st.root.p = x
	}
	st.root = x
	x.updateSize()
}

func (st *SplayTree) erase(it *Id14) {
	next := it
	// Logic to erase the node from the tree
}

func (st *SplayTree) begin() *Id14 {
	return st.root // Placeholder for actual logic
}

func (st *SplayTree) findNth(k int) *Id14 {
	// Logic to find the k-th node
	return nil
}

func (st *SplayTree) getRank(it *Id14) int {
	// Logic to get the rank of the node
	return 0
}

var lst ListHead
var splay SplayTree
var arr [maxn]Node
var ans int64

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		var v int
		fmt.Fscan(reader, &v)
		arr[i].v = v
		arr[i].pos = i
	}

	for i := 0; i < n; i++ {
		splay.insert(&arr[i])
		lst.insertPrev(&arr[i].lh)
	}

	lastLeft := 0
	lastRight := 0

	for splay.size() > 0 {
		it := splay.begin()
		root := &lst
		left := next(root).pos
		right := prev(root).pos
		splay.erase(it)

		if it.pos == left && it.pos == right {
			ans += min(lastLeft, lastRight)
		} else if it.pos == left {
			ans += int64(lastLeft)
			lastLeft = it.v
		} else if it.pos == right {
			ans += int64(lastRight)
			lastRight = it.v
		} else {
			ans += int64(min(next(it).v, prev(it).v))
		}
		it.lh.unlink()
	}

	fmt.Println(ans)
}

func next(it *ListHead) *Node {
	return (*Node)(it.next)
}

func prev(it *ListHead) *Node {
	return (*Node)(it.prev)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
