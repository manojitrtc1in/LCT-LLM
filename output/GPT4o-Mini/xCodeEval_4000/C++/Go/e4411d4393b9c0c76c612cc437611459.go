package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type Pair struct {
	first  int
	second int
}

func touchPos(r, c, d int, len []int, dist [][]int, q *[]Pair) Pair {
	pos := Pair{r, min(c, len[r])}
	if d < dist[r][pos.second] {
		dist[r][pos.second] = d
		*q = append(*q, pos)
	}
	return pos
}

func c253() {
	fin, _ := os.Open("input.txt")
	defer fin.Close()
	fout, _ := os.Create("output.txt")
	defer fout.Close()

	reader := bufio.NewReader(fin)
	writer := bufio.NewWriter(fout)
	defer writer.Flush()

	var len []int
	var nrow int
	fmt.Fscan(reader, &nrow)
	len = make([]int, nrow)
	for i := 0; i < nrow; i++ {
		fmt.Fscan(reader, &len[i])
	}

	var first, last Pair
	fmt.Fscan(reader, &first.first, &first.second)
	fmt.Fscan(reader, &last.first, &last.second)

	first = Pair{first.first - 1, first.second - 1}
	last = Pair{last.first - 1, last.second - 1}

	if first == last {
		fmt.Fprintln(writer, 0)
		return
	}

	const INF = int(^uint(0) >> 1)
	dist := make([][]int, nrow)
	for j := 0; j < nrow; j++ {
		dist[j] = make([]int, len[j]+1)
		for k := range dist[j] {
			dist[j][k] = INF
		}
	}

	q := []Pair{first}
	dist[first.first][first.second] = 0

	touch := func(r, c, d int) Pair {
		return touchPos(r, c, d, len, dist, &q)
	}

	for len(q) > 0 {
		r, c := q[0].first, q[0].second
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
	fmt.Fprintln(writer, dist[last.first][last.second])
}

func d34() {
	var n, fst, lst int
	fmt.Scan(&n, &fst, &lst)
	fst--
	lst--

	a := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Scan(&a[i])
	}

	for i := range a {
		a[i]--
	}

	adj := make([][]int, n)
	for j := 0; j < n-1; j++ {
		u := j
		if j >= fst {
			u++
		}
		v := a[j]
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	const NIL = n + 1
	tag := make([]int, n)
	for i := range tag {
		tag[i] = NIL
	}
	q := []int{lst}
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
	for i := range tag {
		tag[i]++
	}
	for _, v := range tag {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func b140() {
	var n int
	fmt.Scan(&n)

	l := make([][]int, n)
	for i := 0; i < n; i++ {
		l[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&l[i][j])
		}
	}

	xs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xs[i])
	}

	a := make([]int, n)
	b := make([]int, n)
	a[0] = xs[0]
	b[0] = math.MaxInt32

	for j := 1; j < n; j++ {
		if xs[j] < a[j-1] {
			b[j] = a[j-1]
			a[j] = xs[j]
		} else {
			a[j] = a[j-1]
			b[j] = min(b[j-1], xs[j])
		}
	}

	pos := make([]int, n+1)
	for j := 0; j < n; j++ {
		pos[xs[j]] = j
	}

	var soln []int
	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			if l[j][i] != j+1 {
				k := pos[l[j][i]]
				runMin := a[k]
				if runMin != j+1 {
					soln = append(soln, l[j][i])
					break
				}
			}
		}
	}

	for _, v := range soln {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func a51() int {
	var n int
	fmt.Scan(&n)

	xs := make([][]int, n)
	for j := 0; j < n; j++ {
		var a, b int
		fmt.Scan(&a, &b)
		xs[j] = []int{a / 10, a % 10, b % 10, b / 10}
		if j+1 != n {
			var str string
			fmt.Scan(&str)
		}
	}

	for i := range xs {
		b := xs[i]
		for k := 0; k < 4; k++ {
			rotate(b)
			if less(b, xs[i]) {
				xs[i] = b
			}
		}
	}

	sort.Slice(xs, func(i, j int) bool {
		return xs[i][0] < xs[j][0]
	})

	return unique(xs)
}

func b444() {
	var n, d int
	var x int64
	fmt.Scan(&n, &d, &x)

	a := make([]int64, n)
	b := make([]bool, n)
	for i := range a {
		a[i] = int64(i + 1)
	}

	for i := 0; i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		a[i], a[x%(int64(i)+1)] = a[x%(int64(i)+1)], a[i]
	}

	for i := 0; i < d; i++ {
		b[i] = true
	}

	for i := 0; i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		c := b[i]
		b[i] = b[x%(int64(i)+1)]
		b[x%(int64(i)+1)] = c
	}

	soln := make([]int64, n)
	idx := []int{}
	for j := 0; j < n; j++ {
		if b[j] {
			idx = append(idx, j)
		}
	}

	heap := make([]Pair, 0)
	const budget = 1000000

	for j := 0; j < n; j++ {
		heap = append(heap, Pair{a[j], j})
		if len(heap) > budget {
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

	for j := 0; j < n; j++ {
		if soln[j] == 0 {
			for _, i := range idx {
				if j < i {
					break
				}
				soln[j] = max(soln[j], a[j-i])
			}
		}
	}

	for _, v := range soln {
		fmt.Println(v)
	}
}

func main() {
	c253()
	d34()
	b140()
	a51()
	b444()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func rotate(a []int) {
	if len(a) > 0 {
		first := a[0]
		copy(a, a[1:])
		a[len(a)-1] = first
	}
}

func less(a, b []int) bool {
	for i := range a {
		if a[i] < b[i] {
			return true
		} else if a[i] > b[i] {
			return false
		}
	}
	return false
}

func unique(xs [][]int) int {
	seen := make(map[string]struct{})
	count := 0
	for _, x := range xs {
		key := fmt.Sprintf("%v", x)
		if _, ok := seen[key]; !ok {
			seen[key] = struct{}{}
			count++
		}
	}
	return count
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
