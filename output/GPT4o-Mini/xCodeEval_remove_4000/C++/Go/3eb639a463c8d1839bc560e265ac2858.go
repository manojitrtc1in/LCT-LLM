package main

import (
	"fmt"
	"math"
	"sort"
	"time"
)

type li int64
type ld float64
type pt struct {
	x, y int
}

type node struct {
	s      int
	sum    li
	minsum li
}

var (
	n      int
	a      [100013]struct{ x, y pt }
	vals   []int
	t      [4 * 100013]node
	val    [100013]int
	len    [100013]int
	cur    map[int]struct{}
)

const (
	INF    = int(1e9)
	INF64  = li(1e18)
	MOD    = INF + 7
	EPS    = 1e-9
	PI     = math.Acos(-1.0)
)

func read() bool {
	if _, err := fmt.Scan(&n); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x.x)
		if a[i].x.x == 1 {
			fmt.Scan(&a[i].x.y, &a[i].y.x)
		} else if a[i].x.x == 2 {
			fmt.Scan(&a[i].x.y)
		} else if a[i].x.x == 3 {
			fmt.Scan(&a[i].x.y, &a[i].y.x, &a[i].y.y)
		}
	}
	return true
}

func merge(a, b node) node {
	return node{
		sum:    a.sum + b.sum,
		minsum: min(a.minsum, a.sum+b.minsum),
	}
}

func build(v, l, r int) {
	if l == r-1 {
		if l == 0 {
			t[v] = node{0, INF64 + 1, 0}
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
		t[v] = node{val.x, li(val.y)}
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

func ask(v, l, r, L, R int, x *li) ld {
	if L >= R {
		return 2 * INF
	}
	if l == L && r == R {
		if t[v].minsum+*x > 0 {
			*x += t[v].sum
			return 2 * INF
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
			return ld(vals[l])
		}

		if t[v].minsum+*x > 0 || t[v].s >= 0 {
			panic("assertion failed")
		}
		res := ld(vals[l]) + (ld(*x) / ld(-t[v].s))
		*x = 0
		return res
	}
	m := (l + r) / 2
	tmp := ask(v*2, l, m, L, min(m, R), x)
	if *x == 0 {
		return tmp
	}
	if *x <= 0 {
		panic("assertion failed")
	}
	return ask(v*2+1, m, r, max(m, L), R, x)
}

func solve() {
	vals = []int{}
	for i := 0; i < n; i++ {
		if a[i].x.x == 1 {
			vals = append(vals, a[i].x.y)
		}
	}
	vals = append(vals, 0, INF+1)
	sort.Ints(vals)
	vals = unique(vals)

	cur = make(map[int]struct{})
	build(1, 0, len(vals))

	val[0] = 0
	len[0] = INF + 1

	cur[0] = struct{}{}
	cur[len(vals)-1] = struct{}{}

	for i := 0; i < n; i++ {
		if a[i].x.x == 1 {
			pos := sort.Search(len(vals), func(j int) bool { return vals[j] >= a[i].x.y })
			pos2 := findKey(cur, pos)
			val[pos] = a[i].y.x
			delete(cur, pos2)
			len[pos2] = vals[pos] - vals[pos2]
			upd(1, 0, len(vals), pos2, pt{val[pos2], len[pos2]})
			cur[pos] = struct{}{}
		} else if a[i].x.x == 2 {
			pos := sort.Search(len(vals), func(j int) bool { return vals[j] >= a[i].x.y })
			pos2 := findKey(cur, pos)
			val[pos2] = len[pos2] = 0
			upd(1, 0, len(vals), pos2, pt{val[pos2], len[pos2]})
			delete(cur, pos2)
			pos2 = findKey(cur, pos2)
			l := vals[pos2]
			l -= vals[pos2]
			len[pos2] = l
			upd(1, 0, len(vals), pos2, pt{val[pos2], len[pos2]})
		} else {
			l := sort.Search(len(vals), func(j int) bool { return vals[j] >= a[i].x.y })
			lit := findKey(cur, l)
			r := a[i].y.x
			x := a[i].y.y
			if x == 0 {
				fmt.Printf("%.15f\n", ld(a[i].x.y))
				continue
			}

			res := ask(1, 0, len(vals), lit, len(vals), &x)
			if x == 0 && res < ld(r)+EPS {
				fmt.Printf("%.15f\n", res)
			} else {
				fmt.Println("-1")
			}
		}
	}
}

func unique(ints []int) []int {
	seen := make(map[int]struct{})
	result := []int{}
	for _, v := range ints {
		if _, ok := seen[v]; !ok {
			seen[v] = struct{}{}
			result = append(result, v)
		}
	}
	return result
}

func findKey(m map[int]struct{}, key int) int {
	for k := range m {
		if k == key {
			return k
		}
	}
	return -1
}

func main() {
	start := time.Now()

	for read() {
		solve()
	}

	fmt.Printf("TIME = %v\n", time.Since(start))
}
