package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INF = int(1e9)

type Node struct {
	lp      *Node
	rp      *Node
	sum     int
	minVal  int
	s       int
	free    int
}

var nodes [101010 * 32]Node
var lastn = &nodes[0]
var root *Node

func update(cur **Node, l, r, pos, val int) {
	if *cur == nil {
		*cur = lastn
		lastn++
	}
	if l == r {
		(*cur).s = val
		(*cur).free = 0
		(*cur).minVal = min(0, (*cur).s)
		(*cur).sum = val
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

var ans = 1e20

func getAns(cur *Node, l, r, x, y int, v *int64, s *int) {
	if y < l {
		return
	}
	if x > r {
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
		ans = float64(x) + float64(*v)/float64(-*s)
		*v = 0
		return
	}
	m := (l + r) / 2
	if x <= l && r <= y {
		minVal := cur.minVal + cur.free*(*s)

		if minVal+*v > 0 {
			*v += cur.sum + cur.free*(*s)
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve() int {
	q := readInt()
	for q > 0 {
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
			v := readInt64()

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
		q--
	}

	return 0
}

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)

	solve()
}

func readInt() int {
	scan.Scan()
	num, _ := strconv.Atoi(scan.Text())
	return num
}

func readInt64() int64 {
	scan.Scan()
	num, _ := strconv.ParseInt(scan.Text(), 10, 64)
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
