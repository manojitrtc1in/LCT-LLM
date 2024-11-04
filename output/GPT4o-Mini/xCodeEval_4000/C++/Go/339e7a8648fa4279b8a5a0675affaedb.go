package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const (
	USUAL_MOD = 1000000007
	INF       = 1011111111
)

type Node struct {
	lp      *Node
	rp      *Node
	sum     int64
	minVal  int64
	s       int
	free    int
}

func (cur *Node) update(tl, tr int) {
	if cur.lp == nil && cur.rp == nil {
		return
	}
	if cur.lp == nil {
		cur.sum = cur.rp.sum
		cur.minVal = cur.rp.minVal
		cur.s = cur.rp.s
		cur.free += tl
		return
	}
	if cur.rp == nil {
		cur.sum = cur.lp.sum
		cur.minVal = cur.lp.minVal
		cur.s = cur.lp.s
		cur.free = cur.lp.free
		cur.sum += int64(cur.lp.s) * int64(tr)
		cur.minVal = int64(math.Min(float64(cur.minVal), float64(cur.sum)))
		return
	}
	cur.sum = cur.lp.sum + int64(cur.rp.free)*int64(cur.lp.s) + cur.rp.sum
	cur.minVal = int64(math.Min(float64(cur.lp.minVal), float64(cur.lp.sum+int64(cur.rp.free)*int64(cur.lp.s)+cur.rp.minVal)))
	cur.s = cur.rp.s
	cur.free = cur.lp.free
}

var nodes [101010 * 32]Node
var lastn *Node
var root *Node

func update(cur **Node, l, r, pos, val int) {
	if *cur == nil {
		*cur = &nodes[len(nodes)-1]
		lastn = *cur
	}
	if l == r {
		(*cur).s = val
		(*cur).free = 0
		(*cur).minVal = int64(math.Min(0, float64((*cur).s)))
		(*cur).sum = int64(val)
	} else {
		m := (l + r) / 2
		if pos <= m {
			update(&(*cur).lp, l, m, pos, val)
		} else {
			update(&(*cur).rp, m+1, r, pos, val)
		}
		(*cur).update(m-l+1, r-m)
	}
}

func del(cur **Node, l, r, pos int) {
	if l == r {
		*cur = nil
	} else {
		m := (l + r) / 2
		if pos <= m {
			del(&(*cur).lp, l, m, pos)
		} else {
			del(&(*cur).rp, m+1, r, pos)
		}
		if (*cur).lp == nil && (*cur).rp == nil {
			*cur = nil
			return
		}
		(*cur).update(m-l+1, r-m)
	}
}

var ans float64 = 1e20

func getAns(cur *Node, l, r, x, y int, v *int64, s *int) {
	if y < l || x > r {
		return
	}
	if cur == nil || l == r {
		if cur != nil {
			*s = cur.s
		}
		tot := int64(*s) * int64(y-x+1)
		if tot+*v > 0 {
			*v += tot
			return
		}
		ans = float64(x) + *v*-1/float64(*s)
		*v = 0
		return
	}
	m := (l + r) / 2
	if x <= l && r <= y {
		minVal := cur.minVal + int64(cur.free)*int64(*s)
		if minVal+*v > 0 {
			*v += cur.sum + int64(cur.free)*int64(*s)
			*s = cur.s
			return
		} else {
			getAns(cur.lp, l, m, x, m, v, s)
			if *v == 0 {
				return
			}
			getAns(cur.rp, m+1, r, m+1, y, v, s)
			return
		}
	}
	if x <= m {
		getAns(cur.lp, l, m, x, int(math.Min(float64(y), float64(m))), v, s)
		if *v == 0 {
			return
		}
	}
	getAns(cur.rp, m+1, r, int(math.Max(float64(x), float64(m+1))), y, v, s)
}

func solve() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var q int
	fmt.Fscan(reader, &q)
	for q > 0 {
		q--
		var t int
		fmt.Fscan(reader, &t)
		if t == 1 {
			var w, s int
			fmt.Fscan(reader, &w, &s)
			update(&root, 0, INF, w, s)
		} else if t == 2 {
			var w int
			fmt.Fscan(reader, &w)
			del(&root, 0, INF, w)
		} else {
			var l, r int64
			var v int64
			fmt.Fscan(reader, &l, &r, &v)

			ans = 1e20
			if v == 0 {
				ans = float64(l)
			}
			if l < r && v != 0 {
				s := 0
				getAns(root, 0, INF, int(l), int(r-1), &v, &s)
			}
			if v != 0 {
				fmt.Fprintln(writer, -1)
			} else {
				fmt.Fprintf(writer, "%.8f\n", ans)
			}
		}
	}
}

func main() {
	solve()
}
