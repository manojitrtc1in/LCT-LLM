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
	return &listHead{nil, nil}
}

func (l *listHead) empty() bool {
	return l.next == l
}

func (l *listHead) unlink() {
	l.prev.next = l.next
	l.next.prev = l.prev
	l.prev = nil
	l.next = nil
}

func (l *listHead) insertNext(newNext *listHead) {
	newNext.next = l.next
	newNext.prev = l
	l.next.prev = newNext
	l.next = newNext
}

func (l *listHead) insertPrev(newPrev *listHead) {
	newPrev.prev = l.prev
	newPrev.next = l
	l.prev.next = newPrev
	l.prev = newPrev
}

type iterRange struct {
	first, second int
}

type intIter struct {
	i int
}

func newIntIter(i int) *intIter {
	return &intIter{i}
}

func (it *intIter) next() {
	it.i++
}

func (it *intIter) prev() {
	it.i--
}

func (it *intIter) add(step int) {
	it.i += step
}

func (it *intIter) sub(step int) {
	it.i -= step
}

func (it *intIter) diff(that *intIter) int {
	return it.i - that.i
}

func (it *intIter) equal(that *intIter) bool {
	return it.i == that.i
}

func (it *intIter) get() int {
	return it.i
}

type intRange struct {
	begin, end *intIter
}

func newIntRange(b, e int) *intRange {
	return &intRange{newIntIter(b), newIntIter(e)}
}

func (r *intRange) begin() *intIter {
	return r.begin
}

func (r *intRange) end() *intIter {
	return r.end
}

func rangeInt(b, e int) *intRange {
	return newIntRange(b, e)
}

func rangeIntN(n int) *intRange {
	return rangeInt(0, n)
}

func inRangeInt(b, e int) *intRange {
	return rangeInt(b, e+1)
}

type node struct {
	lh  *listHead
	sh  *splayHead
	v   int
	pos int
}

type splayHead struct {
	lc, rc, p *splayHead
	size      int
}

func newSplayHead() *splayHead {
	return &splayHead{nil, nil, nil, 1}
}

func (sh *splayHead) updateSize() {
	sh.size = 1
	if sh.lc != nil {
		sh.size += sh.lc.size
	}
	if sh.rc != nil {
		sh.size += sh.rc.size
	}
}

func rotate(x *splayHead) {
	y := x.p
	b := x.rc
	x.p = y.p
	y.p = x
	if b != nil {
		b.p = y
	}
	if x == y.lc {
		x.rc = y
		y.lc = b
	} else {
		x.lc = y
		y.rc = b
	}
}

func splay(x, target *splayHead) {
	for x.p != target {
		if x.p.p != target {
			if (x.p.lc == x) == (x.p.p.lc == x.p) {
				rotate(x.p)
			} else {
				rotate(x)
			}
		}
		rotate(x)
	}
	x.updateSize()
	if target == nil {
		root = x
	}
}

func insertBefore(x, y *splayHead) {
	if y == nil {
		x.lc = root
		if root != nil {
			root.p = x
		}
		root = x
		x.updateSize()
	} else {
		splay(y, nil)
		if y.lc == nil {
			y.lc = x
			x.p = y
			y.updateSize()
		} else {
			prev := rightmost(y.lc)
			splay(prev, y)
			prev.rc = x
			x.p = prev
			prev.updateSize()
			y.updateSize()
		}
	}
}

func erase(x *splayHead) {
	splay(x, nil)
	if x.lc == nil {
		if x.rc != nil {
			x.rc.p = nil
		}
		root = x.rc
	} else {
		prev := rightmost(x.lc)
		splay(prev, x)
		prev.rc = x.rc
		if x.rc != nil {
			x.rc.p = prev
		}
		prev.updateSize()
		prev.p = nil
		root = prev
	}
	x.lc = nil
	x.rc = nil
	x.p = nil
	x.size = 0
}

func getRank(x *splayHead) int {
	if x == nil {
		if root != nil {
			return root.size
		}
		return 0
	}
	splay(x, nil)
	if x.lc != nil {
		return x.lc.size
	}
	return 0
}

func findNth(k int) *splayHead {
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

func leftmost(x *splayHead) *splayHead {
	for x != nil && x.lc != nil {
		x = x.lc
	}
	return x
}

func rightmost(x *splayHead) *splayHead {
	for x != nil && x.rc != nil {
		x = x.rc
	}
	return x
}

type splayArray struct {
	root *splayHead
}

func newSplayArray() *splayArray {
	return &splayArray{}
}

func (sa *splayArray) size() int {
	if sa.root != nil {
		return sa.root.size
	}
	return 0
}

func (sa *splayArray) begin() *splayHead {
	return leftmost(sa.root)
}

func (sa *splayArray) end() *splayHead {
	return nil
}

func (sa *splayArray) findNth(k int) *splayHead {
	return findNth(k)
}

func (sa *splayArray) getRank(it *splayHead) int {
	return getRank(it)
}

func (sa *splayArray) insertFront(node *node) *splayHead {
	x := node.sh
	x.rc = sa.root
	if sa.root != nil {
		sa.root.p = x
	}
	sa.root = x
	x.updateSize()
	return x
}

func (sa *splayArray) insertBack(node *node) *splayHead {
	x := node.sh
	x.lc = sa.root
	if sa.root != nil {
		sa.root.p = x
	}
	sa.root = x
	x.updateSize()
	return x
}

func (sa *splayArray) insertNth(node *node, k int) *splayHead {
	if k == 0 {
		return sa.insertFront(node)
	} else if k < sa.size() {
		x := node.sh
		y := findNth(k)
		insertBefore(x, y)
		return x
	} else if k == sa.size() {
		return sa.insertBack(node)
	} else {
		panic("Invalid index")
	}
}

func (sa *splayArray) erase(it *splayHead) {
	erase(it)
}

var (
	root *splayHead
	ans  int64
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		v, _ := strconv.Atoi(scanner.Text())
		arr[i] = node{newListHead(), newSplayHead(), v, i}
	}

	for i := 0; i < n; i++ {
		splay.insert(&arr[i])
		lst.insertPrev(arr[i].lh)
	}

	lastLeft := 0
	lastRight := 0

	for splay.size() > 0 {
		it := splay.begin()
		lit := lit_t{it.lh}
		root := lit_t{lst}
		left := root.next().pos
		right := root.prev().pos
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
			ans += int64(min(lit.next().v, lit.prev().v))
		}

		it.lh.unlink()
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
