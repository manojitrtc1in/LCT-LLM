package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type listHead struct {
	prev, next *listHead
}

func newListHead() *listHead {
	return &listHead{prev: nil, next: nil}
}

func (lh *listHead) empty() bool {
	return lh.next == lh
}

func (lh *listHead) unlink() {
	lh.prev.next = lh.next
	lh.next.prev = lh.prev
	lh.prev = nil
	lh.next = nil
}

func (lh *listHead) insertNext(newNext *listHead) {
	newNext.next = lh.next
	newNext.prev = lh
	lh.next.prev = newNext
	lh.next = newNext
}

func (lh *listHead) insertPrev(newPrev *listHead) {
	newPrev.prev = lh.prev
	newPrev.next = lh
	lh.prev.next = newPrev
	lh.prev = newPrev
}

type listIter struct {
	cur *listHead
}

func newListIter(head *listHead) *listIter {
	return &listIter{cur: head}
}

func (it *listIter) next() {
	it.cur = it.cur.next
}

func (it *listIter) prev() {
	it.cur = it.cur.prev
}

func (it *listIter) value() *node {
	return it.cur.value
}

type node struct {
	lh   *listHead
	sh   id14
	v    int
	pos  int
}

type id14 struct {
	lc, rc, p *id14
	size      int
}

func newID14() *id14 {
	return &id14{lc: nil, rc: nil, p: nil, size: 1}
}

func (x *id14) reset() {
	x.lc = nil
	x.rc = nil
	x.p = nil
	x.size = 1
}

func (x *id14) updateSize() {
	x.size = 1
	if x.lc != nil {
		x.size += x.lc.size
	}
	if x.rc != nil {
		x.size += x.rc.size
	}
}

func rotate(x *id14) {
	y := x.p
	z := y.p
	var b *id14
	if x == y.lc {
		b = x.rc
		x.rc = y
		y.lc = b
	} else {
		b = x.lc
		x.lc = y
		y.rc = b
	}
	x.p = z
	y.p = x
	if b != nil {
		b.p = y
	}
	if z != nil {
		if y == z.lc {
			z.lc = x
		} else {
			z.rc = x
		}
	}
	y.updateSize()
}

func prev(x *id14) *id14 {
	if x.lc != nil {
		return id8(x.lc)
	}
	p := x.p
	for p != nil && x == p.lc {
		x = p
		p = p.p
	}
	return p
}

func bstRotate(x *id14) {
	y := x.p
	z := y.p
	var b *id14
	if x == y.lc {
		b = x.rc
		x.rc = y
		y.lc = b
	} else {
		b = x.lc
		x.lc = y
		y.rc = b
	}
	x.p = z
	y.p = x
	if b != nil {
		b.p = y
	}
	if z != nil {
		if y == z.lc {
			z.lc = x
		} else {
			z.rc = x
		}
	}
}

func find(root *id14, k int) *id14 {
	p := root
	for {
		lsize := 0
		if p.lc != nil {
			lsize = p.lc.size
		}
		if k < lsize {
			p = p.lc
		} else if k == lsize {
			return p
		} else {
			k -= lsize + 1
			p = p.rc
		}
	}
	return p
}

func erase(root **id14, x *id14) {
	for x.p != nil {
		if x.p.p != nil {
			if (x.p.lc == x) == (x.p.p.lc == x.p) {
				bstRotate(x.p)
			} else {
				bstRotate(x)
			}
		}
		bstRotate(x)
	}
	x.updateSize()
	if x.lc == nil {
		if x.rc != nil {
			x.rc.p = nil
		}
		*root = x.rc
	} else {
		prev := id8(x.lc)
		erase(&prev, x)
		prev.rc = x.rc
		if x.rc != nil {
			x.rc.p = prev
		}
		prev.updateSize()
		prev.p = nil
		*root = prev
	}
	x.reset()
}

func getRank(root *id14, x *id14) int {
	if x == nil {
		if root != nil {
			return root.size
		}
		return 0
	}
	for x.p != nil {
		if x == x.p.rc {
			if x.p.lc != nil {
				return x.p.lc.size + 1
			}
			return 1
		}
		x = x.p
	}
	return 0
}

type id10 struct {
	root *id14
}

func newID10() *id10 {
	return &id10{root: nil}
}

func (t *id10) size() int {
	if t.root != nil {
		return t.root.size
	}
	return 0
}

func (t *id10) begin() *listIter {
	if t.root != nil {
		return newListIter(id7(t.root))
	}
	return nil
}

func (t *id10) end() *listIter {
	return nil
}

func (t *id10) findNth(k int) *listIter {
	if t.root != nil {
		return newListIter(find(t.root, k).sh.lh)
	}
	return nil
}

func (t *id10) getRank(it *listIter) int {
	if t.root != nil && it != nil {
		return getRank(t.root, it.cur.sh)
	}
	return 0
}

func (t *id10) erase(it *listIter) {
	if t.root != nil && it != nil {
		erase(&t.root, it.cur.sh)
	}
}

func (t *id10) find(k int) *listIter {
	if t.root != nil {
		x := find(t.root, k)
		if x != nil && x.sh.v == k {
			erase(&t.root, x)
			return newListIter(x.sh.lh)
		}
	}
	return nil
}

func (t *id10) lowerBound(k int) *listIter {
	if t.root != nil {
		x := find(t.root, k)
		if x != nil && x.sh.v == k {
			erase(&t.root, x)
			return newListIter(x.sh.lh)
		}
	}
	return nil
}

func (t *id10) upperBound(k int) *listIter {
	if t.root != nil {
		x := find(t.root, k+1)
		if x != nil && x.sh.v == k {
			erase(&t.root, x)
			return newListIter(x.sh.lh)
		}
	}
	return nil
}

func (t *id10) insert(node *node) *listIter {
	x := &node.sh
	y := find(t.root, node.v)
	if y != nil && y.sh.v == node.v {
		erase(&t.root, y)
	}
	if y == nil {
		t.root = x
	} else {
		if y.sh.lc == nil {
			y.sh.lc = x
			x.p = y
			y.updateSize()
		} else {
			prev := id8(y.sh.lc)
			erase(&t.root, prev)
			prev.rc = x
			x.p = prev
			prev.updateSize()
			y.updateSize()
		}
	}
	return newListIter(x.lh)
}

var (
	n   int
	arr []*node
	ans int64
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n = nextInt(scanner)
	arr = make([]*node, n)
	for i := 0; i < n; i++ {
		v := nextInt(scanner)
		arr[i] = &node{lh: newListHead(), v: v, pos: i}
	}

	lst := newListHead()
	splay := newID10()

	for i := 0; i < n; i++ {
		splay.insert(arr[i])
		lst.insertPrev(arr[i].lh)
	}

	lastLeft := 0
	lastRight := 0

	for splay.size() > 0 {
		it := splay.begin()
		lit := newListIter(it.cur.lh)
		root := newListIter(lst)
		left := root.next().value().pos
		right := root.prev().value().pos
		splay.erase(it)
		if it.cur.pos == left && it.cur.pos == right {
			ans += min(lastLeft, lastRight)
		} else if it.cur.pos == left {
			ans += int64(lastLeft)
			lastLeft = it.cur.v
		} else if it.cur.pos == right {
			ans += int64(lastRight)
			lastRight = it.cur.v
		} else {
			ans += int64(min(lit.next().value().v, lit.prev().value().v))
		}
		it.cur.lh.unlink()
	}

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
