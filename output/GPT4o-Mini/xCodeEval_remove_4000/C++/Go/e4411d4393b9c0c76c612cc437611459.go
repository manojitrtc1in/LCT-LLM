package main

import (
	"fmt"
	"math"
	"sort"
)

type Int64 int64

type Pair struct {
	first, second size_t
}

func touchPos(r, c, d size_t, len []size_t, dist [][]size_t, q *[]Pair) Pair {
	pos := Pair{r, min(c, len[r])}
	if d < dist[r][pos.second] {
		dist[r][pos.second] = d
		*q = append(*q, pos)
	}
	return pos
}

func c253() {
	var nrow size_t
	var len []size_t
	fmt.Scan(&len)

	nrow = size_t(len.size())
	var first, last Pair
	fmt.Scan(&first, &last)

	first = Pair{first.first - 1, first.second - 1}
	last = Pair{last.first - 1, last.second - 1}

	if first == last {
		fmt.Println(0)
		return
	}

	const INF = math.MaxUint64
	dist := make([][]size_t, nrow)
	for j := size_t(0); j < nrow; j++ {
		dist[j] = make([]size_t, len[j]+1)
		for k := range dist[j] {
			dist[j][k] = INF
		}
	}

	q := []Pair{first}
	dist[first.first][first.second] = 0

	touch := func(r, c, d size_t) Pair {
		return touchPos(r, c, d, len, dist, &q)
	}

	for len(q) > 0 {
		r := q[0].first
		c := q[0].second
		d := dist[r][c] + 1
		q = q[1:]

		if r > 0 && last == touch(r-1, c, d) {
			break
		}

		if r+1 < nrow && last == touch(r+1, c, d) {
			break
		}

		if c > 0 && last == touch(r, c-1, d) {
			break
		}

		if c < len[r] && last == touch(r, c+1, d) {
			break
		}
	}
	fmt.Println(dist[last.first][last.second])
}

func d34() {
	var n, fst, lst size_t
	fmt.Scan(&n, &fst, &lst)
	fst--
	lst--

	a := make([]size_t, n-1)
	fmt.Scan(&a)
	for j := range a {
		a[j] = a[j] - 1
	}

	adj := make([][]size_t, n)
	for j := size_t(0); j < n-1; j++ {
		var u, v size_t
		if j < fst {
			u = j
		} else {
			u = j + 1
		}
		v = a[j]
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	const NIL = n + 1
	tag := make([]size_t, n)
	for j := range tag {
		tag[j] = NIL
	}
	q := []size_t{lst}

	tag[lst] = lst
	for len(q) > 0 {
		u := q[0]
		q = q[1:]

		for _, v := range adj[u] {
			if tag[v] == NIL {
				tag[v] = u
				q = append(q, v)
			}
		}
	}

	tag = append(tag[:lst], tag[lst+1:]...)
	for j := range tag {
		tag[j]++
	}
	fmt.Println(tag)
}

func b140() {
	var n size_t
	fmt.Scan(&n)
	l := make([][]size_t, n)
	for j := range l {
		fmt.Scan(&l[j])
	}

	xs := make([]size_t, n)
	fmt.Scan(&xs)

	a := make([]size_t, n)
	b := make([]size_t, n)
	a[0] = xs[0]
	b[0] = math.MaxUint64

	for j := size_t(1); j < n; j++ {
		if xs[j] < a[j-1] {
			b[j] = a[j-1]
			a[j] = xs[j]
		} else {
			a[j] = a[j-1]
			b[j] = min(b[j-1], xs[j])
		}
	}

	var pos []size_t
	for j := range xs {
		pos[xs[j]] = j
	}

	var soln []size_t
	for j := size_t(0); j < n; j++ {
		for i := size_t(0); i < n; i++ {
			if l[j][i] != j+1 {
				k := pos[l[j][i]]
				runMin := a[k]
				if runMin != j+1 {
					runMin = b[k]
				}

				if l[j][i] <= runMin {
					soln = append(soln, l[j][i])
					break
				}
			}
		}
	}

	for _, s := range soln {
		fmt.Print(s, " ")
	}
}

func a51() size_t {
	var n size_t
	fmt.Scan(&n)

	xs := make([][]size_t, n)
	for j := size_t(0); j < n; j++ {
		var a, b size_t
		fmt.Scan(&a, &b)
		xs[j] = []size_t{a / 10, a % 10, b % 10, b / 10}

		if j+1 != n {
			var str string
			fmt.Scan(&str)
		}
	}

	for i := range xs {
		b := xs[i]
		for j := size_t(0); j < 4; j++ {
			rotate(b)
			if b < xs[i] {
				xs[i] = b
			}
		}
	}

	sort.Slice(xs, func(i, j int) bool {
		return xs[i] < xs[j]
	})
	return size_t(len(xs))
}

func b444() {
	var n, d size_t
	var x Int64
	fmt.Scan(&n, &d, &x)

	a := make([]Int64, n)
	b := make([]bool, n)
	for i := size_t(0); i < n; i++ {
		a[i] = Int64(i + 1)
	}

	for i := size_t(0); i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		a[i], a[x%(i+1)] = a[x%(i+1)], a[i]
	}

	for i := size_t(0); i < d; i++ {
		b[i] = true
	}
	for i := size_t(0); i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		c := b[i]
		b[i] = b[x%(i+1)]
		b[x%(i+1)] = c
	}

	soln := make([]Int64, n)
	var idx []size_t
	for j := size_t(0); j < n; j++ {
		if b[j] {
			idx = append(idx, j)
		}
	}

	const budget = 1000000
	heap := make([]Pair, 0)

	for j := size_t(0); j < n; j++ {
		heap = append(heap, Pair{a[j], j})
		if budget < size_t(len(heap))*size_t(len(idx)) {
			heap = heap[1:]
		}
	}

	for len(heap) > 0 {
		i := heap[0].second
		val := heap[0].first
		heap = heap[1:]

		for _, j := range idx {
			if j+i < n {
				soln[j+i] = val
			} else {
				break
			}
		}
	}

	for j := size_t(0); j < n; j++ {
		if soln[j] == 0 {
			for _, i := range idx {
				if j < i {
					break
				} else {
					soln[j] = max(soln[j], a[j-i])
				}
			}
		}
	}

	for _, s := range soln {
		fmt.Println(s)
	}
}

func main() {
	b444()
}
