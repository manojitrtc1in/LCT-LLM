package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"time"
)

const MAXN = 3e5 + 42
const INF = 1e18

type Treap struct {
	left                   *Treap
	right                  *Treap
	t                      int64
	y                      int
	prefixSum              int64
	speed                  int64
	push                   int64
	minPrefixSumInSubtree  int64
}

func newTreap(t, val, speed int64) *Treap {
	return &Treap{
		t:                     t,
		y:                     rand.Int(),
		prefixSum:            val,
		speed:                speed,
		minPrefixSumInSubtree: val,
	}
}

func vertexAdd(a *Treap, push int64) {
	a.prefixSum += push
	a.minPrefixSumInSubtree += push
	a.push += push
}

func push(a *Treap) {
	if a.push == 0 {
		return
	}
	if a.left != nil {
		vertexAdd(a.left, a.push)
	}
	if a.right != nil {
		vertexAdd(a.right, a.push)
	}
	a.push = 0
}

func smin(a *Treap) int64 {
	if a == nil {
		return INF
	}
	return a.minPrefixSumInSubtree
}

func recalc(a *Treap) {
	a.minPrefixSumInSubtree = min(smin(a.left), min(smin(a.right), a.prefixSum))
}

func merge(a, b *Treap) *Treap {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}
	if a.y < b.y {
		push(a)
		a.right = merge(a.right, b)
		recalc(a)
		return a
	}
	push(b)
	b.left = merge(a, b.left)
	recalc(b)
	return b
}

func split(a *Treap, k int64) (*Treap, *Treap) {
	if a == nil {
		return a, a
	}
	push(a)
	if a.t < k {
		l, r := split(a.right, k)
		a.right = l
		recalc(a)
		return a, r
	}
	l, r := split(a.left, k)
	a.left = r
	recalc(a)
	return l, a
}

func getLeast(a *Treap) *Treap {
	push(a)
	if a.left == nil {
		return a
	}
	return getLeast(a.left)
}

func getGreatest(a *Treap) *Treap {
	push(a)
	if a.right == nil {
		return a
	}
	return getGreatest(a.right)
}

func findFirstLess(a *Treap, v int64) *Treap {
	push(a)
	if smin(a.left) <= v {
		return findFirstLess(a.left, v)
	}
	if a.prefixSum <= v {
		return a
	}
	return findFirstLess(a.right, v)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	rand.Seed(time.Now().UnixNano())
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	root := newTreap(0, 0, 0)
	root = merge(root, newTreap(2e9, 0, 0))

	var q int
	fmt.Fscan(reader, &q)

	for i := 0; i < q; i++ {
		var t, s, typ int64
		fmt.Fscan(reader, &typ)

		if typ == 1 {
			fmt.Fscan(reader, &t, &s)
			l, r := split(root, t)
			vr := getLeast(r)
			vl := getGreatest(l)
			psum := vl.prefixSum + (t-vl.t)*vl.speed
			newPsum := psum + (vr.t-t)*s
			vertexAdd(r, newPsum-vr.prefixSum)
			root = merge(l, merge(newTreap(t, psum, s), r))
		} else if typ == 2 {
			fmt.Fscan(reader, &t)
			l, tr := split(root, t)
			y, r := split(tr, t+1)
			vl := getGreatest(l)
			vr := getLeast(r)
			newPsum := vl.prefixSum + (vr.t-vl.t)*vl.speed
			vertexAdd(r, newPsum-vr.prefixSum)
			root = merge(l, r)
		} else {
			var L, R int64
			var v int64
			fmt.Fscan(reader, &L, &R, &v)
			if v == 0 {
				fmt.Fprintln(writer, L)
				continue
			}
			l, yr := split(root, L)
			y, r := split(yr, R+1)
			if y == nil {
				fmt.Fprintln(writer, -1)
			} else {
				vl := getLeast(y)
				vr := getGreatest(y)

				searchingV := vl.prefixSum - v

				if y.minPrefixSumInSubtree > searchingV {
					newPsum := vr.prefixSum + (R-vr.t)*vr.speed

					if newPsum > searchingV {
						fmt.Fprintln(writer, "-1")
					} else {
						fmt.Fprintf(writer, "%.10f\n", float64(searchingV-vr.prefixSum)/float64(vr.speed)+float64(vr.t))
					}
				} else {
					h := findFirstLess(y, searchingV)
					yl, yr := split(y, h.t)
					vyl := getGreatest(yl)
					fmt.Fprintf(writer, "%.10f\n", float64(searchingV-vyl.prefixSum)/float64(vyl.speed)+float64(vyl.t))
					y = merge(yl, yr)
				}
			}
			root = merge(l, merge(y, r))
		}
	}
}
