package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type pt struct {
	x int
	y int
}

type node struct {
	s       int
	sum     int64
	minsum  int64
}

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = INF + 7
	EPS   = 1e-9
	PI    = acos(-1.0)
	N     = 100*1000 + 13
)

var (
	n   int
	a   [N]struct {
		x pt
		y pt
	}
	t    [4 * N]node
	vals []int
)

func read() bool {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i].x.x, _ = strconv.Atoi(scanner.Text())

		if a[i].x.x == 1 {
			scanner.Scan()
			a[i].x.y, _ = strconv.Atoi(scanner.Text())

			scanner.Scan()
			a[i].y.x, _ = strconv.Atoi(scanner.Text())
		} else if a[i].x.x == 2 {
			scanner.Scan()
			a[i].x.y, _ = strconv.Atoi(scanner.Text())
		} else if a[i].x.x == 3 {
			scanner.Scan()
			a[i].x.y, _ = strconv.Atoi(scanner.Text())

			scanner.Scan()
			a[i].y.x, _ = strconv.Atoi(scanner.Text())

			scanner.Scan()
			a[i].y.y, _ = strconv.Atoi(scanner.Text())
		}
	}

	return true
}

func printPair(a, b interface{}) {
	fmt.Printf("(%v, %v)", a, b)
}

func printVector(v interface{}) {
	fmt.Print("[")

	switch v := v.(type) {
	case []int:
		for i, val := range v {
			if i > 0 {
				fmt.Print(", ")
			}
			fmt.Print(val)
		}
	case []pt:
		for i, val := range v {
			if i > 0 {
				fmt.Print(", ")
			}
			printPair(val.x, val.y)
		}
	}

	fmt.Print("]")
}

func merge(a, b node) node {
	c := node{}
	c.sum = a.sum + b.sum
	c.minsum = min(a.minsum, a.sum+b.minsum)
	return c
}

func build(v, l, r int) {
	if l == r-1 {
		if l == 0 {
			t[v] = node{0, int64(INF + 1), int64(INF + 1)}
		} else {
			t[v] = node{0, 0, 0}
		}
		return
	}

	m := (l + r) / 2
	build(v*2, l, m)
	build(v*2+1, m, r)
	t[v] = merge(t[v*2], t[v*2+1])
}

func upd(v, l, r, pos int, val pt) {
	if l == r-1 {
		t[v] = node{val.x, int64(val.y), int64(val.y)}
		return
	}

	m := (l + r) / 2
	if pos < m {
		upd(v*2, l, m, pos, val)
	} else {
		upd(v*2+1, m, r, pos, val)
	}
	t[v] = merge(t[v*2], t[v*2+1])
}

func ask(v, l, r, L, R int, x *int64) float64 {
	if L >= R {
		return 2 * float64(INF)
	}

	if l == L && r == R {
		if t[v].minsum+*x > 0 {
			*x += t[v].sum
			return 2 * float64(INF)
		}

		for l < r-1 {
			m := (l + r) / 2

			if t[v*2].minsum+*x <= 0 {
				r = m
				v = v * 2
			} else {
				*x += t[v*2].sum
				l = m
				v = v*2 + 1
			}
		}

		if *x == 0 {
			return float64(vals[l])
		}

		assert(t[v].minsum+*x <= 0)
		assert(t[v].s < 0)
		res := float64(vals[l]) + (float64(*x) / float64(-t[v].s))
		*x = 0
		return res
	}

	m := (l + r) / 2
	tmp := ask(v*2, l, m, L, min(m, R), x)
	if *x == 0 {
		return tmp
	}
	assert(*x > 0)
	return ask(v*2+1, m, r, max(m, L), R, x)
}

func solve() {
	vals = make([]int, 0)
	for i := 0; i < n; i++ {
		if a[i].x.x == 1 {
			vals = append(vals, a[i].x.y)
		}
	}
	vals = append(vals, 0)
	vals = append(vals, INF+1)
	sort.Ints(vals)
	vals = vals[:unique(vals)]
	cur := make(map[int]bool)
	build(1, 0, len(vals))

	val := make([]int, N)
	len := make([]int, N)

	val[0] = 0
	len[0] = INF + 1

	cur[0] = true
	cur[len(vals)-1] = true

	for i := 0; i < n; i++ {
		if a[i].x.x == 1 {
			pos := sort.SearchInts(vals, a[i].x.y)
			pos2 := cur.lower_bound(pos)
			val[pos] = a[i].y.x
			pos2--
			len[*pos2] = vals[pos] - vals[*pos2]
			upd(1, 0, len(vals), *pos2, pt{val[*pos2], len[*pos2]})
			pos2++
			len[pos] = vals[*pos2] - vals[pos]
			upd(1, 0, len(vals), pos, pt{val[pos], len[pos]})
			cur[pos] = true
		} else if a[i].x.x == 2 {
			pos := sort.SearchInts(vals, a[i].x.y)
			pos2 := cur.lower_bound(pos)
			val[*pos2] = 0
			len[*pos2] = 0
			upd(1, 0, len(vals), *pos2, pt{val[*pos2], len[*pos2]})
			delete(cur, *pos2)
			l := vals[*pos2]
			pos2--
			l -= vals[*pos2]
			len[*pos2] = l
			upd(1, 0, len(vals), *pos2, pt{val[*pos2], len[*pos2]})
		} else {
			l := sort.SearchInts(vals, a[i].x.y)
			lit := cur.lower_bound(l)
			r := a[i].y.x
			x := a[i].y.y
			if x == 0 {
				fmt.Printf("%.15Lf\n", float64(a[i].x.y))
				continue
			}

			res := ask(1, 0, len(vals), *lit, len(vals), &x)
			if x == 0 && res < r+EPS {
				fmt.Printf("%.15Lf\n", res)
			} else {
				fmt.Println("-1")
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	tt := clock()

	for read() {
		solve()
	}

	fmt.Println("TIME =", clock()-tt)
}
