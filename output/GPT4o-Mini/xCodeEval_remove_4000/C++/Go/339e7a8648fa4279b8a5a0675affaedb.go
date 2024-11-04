package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

const INF = math.MaxInt64
const id10 = 1000000007

type Node struct {
	lp     *Node
	rp     *Node
	sum    int64
	minVal int64
	s      int
	free   int
}

var nodes [101010 * 32]Node
var lastn *Node
var root *Node

func (cur *Node) update(tl, tr int) {
	if cur.lp == nil && cur.rp == nil {
		return
	}
	if cur.lp == nil {
		cur.sum = cur.rp.sum
		cur.minVal = cur.rp.minVal
		cur.s = cur.rp.s
		cur.free = cur.rp.free
		cur.free += tl
		return
	}
	if cur.rp == nil {
		cur.sum = cur.lp.sum
		cur.minVal = cur.lp.minVal
		cur.s = cur.lp.s
		cur.free = cur.lp.free
		cur.sum += int64(cur.lp.s) * int64(tr)
		cur.minVal = min(cur.minVal, cur.sum)
		return
	}
	cur.sum = cur.lp.sum + int64(cur.rp.free)*int64(cur.lp.s) + cur.rp.sum
	cur.minVal = min(cur.lp.minVal, cur.lp.sum+int64(cur.rp.free)*int64(cur.lp.s)+cur.rp.minVal)
	cur.s = cur.rp.s
	cur.free = cur.lp.free
}

func update(cur **Node, l, r, pos, val int) {
	if *cur == nil {
		*cur = &lastn
		lastn = (*cur)[1:]
	}
	if l == r {
		(*cur).s = val
		(*cur).free = 0
		(*cur).minVal = min(0, (*cur).s)
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
		getAns(cur.lp, l, m, x, min(y, m), v, s)
		if *v == 0 {
			return
		}
	}
	getAns(cur.rp, m+1, r, max(x, m+1), y, v, s)
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solve() {
	q := readInt()
	for i := 0; i < q; i++ {
		t := readInt()
		if t == 1 {
			w := readInt()
			s := readInt()
			update(&root, 0, INF, w, s)
		} else if t == 2 {
			w := readInt()
			del(&root, 0, INF, w)
		} else {
			l := readInt()
			r := readInt()
			v := int64(readInt())
			ans = 1e20
			if v == 0 {
				ans = float64(l)
			}
			if l < r && v != 0 {
				s := 0
				getAns(root, 0, INF, l, r-1, &v, &s)
			}
			if v != 0 {
				fmt.Println(-1)
			} else {
				fmt.Printf("%.8f\n", ans)
			}
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	defer reader.Flush()
	solve()
}
