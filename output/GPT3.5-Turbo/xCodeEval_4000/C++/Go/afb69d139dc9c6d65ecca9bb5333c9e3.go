package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

type Treap struct {
	left                 *Treap
	right                *Treap
	t                    int64
	y                    int
	prefixSum            int64
	speed                int64
	push                 int64
	minPrefixSumInSubtree int64
}

func vertexAdd(a *Treap, push int64) {
	a.prefixSum += push
	a.minPrefixSumInSubtree += push
	a.push += push
}

func push(a *Treap) {
	push := a.push
	if push == 0 {
		return
	}
	if a.left != nil {
		vertexAdd(a.left, push)
	}
	if a.right != nil {
		vertexAdd(a.right, push)
	}
	a.push = 0
}

const INF = 1e18

func smin(a *Treap) int64 {
	if a != nil {
		return a.minPrefixSumInSubtree
	}
	return INF
}

func recalc(a *Treap) {
	a.minPrefixSumInSubtree = min(smin(a.left), smin(a.right), a.prefixSum)
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
	} else {
		push(b)
		b.left = merge(a, b.left)
		recalc(b)
		return b
	}
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
	} else {
		l, r := split(a.left, k)
		a.left = r
		recalc(a)
		return l, a
	}
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

func min(a, b, c int64) int64 {
	if a < b && a < c {
		return a
	} else if b < c {
		return b
	} else {
		return c
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	rand.Seed(time.Now().UnixNano())
	root := &Treap{t: 0, y: rand.Int(), prefixSum: 0, speed: 0}
	root = merge(root, &Treap{t: 2e9, y: rand.Int(), prefixSum: 0, speed: 0})

	var q int
	fmt.Fscan(reader, &q)

	for i := 0; i < q; i++ {
		var t, s, typ int
		fmt.Fscan(reader, &typ)

		if typ == 1 {
			fmt.Fscan(reader, &t, &s)
			l, r := split(root, t)
			vr := getLeast(r)
			vl := getGreatest(l)
			psum := vl.prefixSum + (t-vl.t)*vl.speed
			newPsum := psum + (vr.t-t)*s
			vertexAdd(r, newPsum-vr.prefixSum)
			root = merge(l, merge(&Treap{t: t, prefixSum: psum, speed: s}, r))
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
			var L, R, v int
			fmt.Fscan(reader, &L, &R, &v)
			if v == 0 {
				fmt.Fprintln(writer, L)
				continue
			}
			l, yr := split(root, int64(L))
			y, r := split(yr, int64(R+1))
			if y == nil {
				fmt.Fprintln(writer, -1)
			} else {
				vl := getLeast(y)
				vr := getGreatest(y)

				searchingV := vl.prefixSum - int64(v)

				if y.minPrefixSumInSubtree > searchingV {
					newPsum := vr.prefixSum + (int64(R)-vr.t)*vr.speed

					if newPsum > searchingV {
						fmt.Fprintln(writer, -1)
					} else {
						fmt.Fprintln(writer, vr.t+(float64(searchingV-vr.prefixSum)/float64(vr.speed)))
					}
				} else {
					h := findFirstLess(y, searchingV)
					yl, yr := split(y, h.t)
					vyl := getGreatest(yl)
					fmt.Fprintln(writer, vyl.t+(float64(searchingV-vyl.prefixSum)/float64(vyl.speed)))
					y = merge(yl, yr)
				}
			}
			root = merge(l, merge(y, r))
		}
	}
}
