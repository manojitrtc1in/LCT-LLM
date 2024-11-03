package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"strings"
	"time"
)

type Noisy struct {
	msg string
}

func NewNoisy(msg string) *Noisy {
	fmt.Println(" Noisy (", msg, ")\t@ ", &Noisy{})
	return &Noisy{msg: msg}
}

func (n *Noisy) Beep() {
	fmt.Println(" beep (", n.msg, ")\t@ ", &Noisy{})
}

func (n *Noisy) BeepConst() {
	fmt.Println(" const beep (", n.msg, ")\t@ ", &Noisy{})
}

func main() {
	rand.Seed(time.Now().UnixNano())

	// C388
	var n int
	fmt.Scan(&n)
	xs := make([][]int, n)
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)
		xs[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&xs[i][j])
		}
	}

	k := 0
	for _, row := range xs {
		k += len(row)
	}
	fmt.Println(k)

	acc := 0
	for _, row := range xs {
		for _, val := range row {
			acc += val
		}
	}
	fmt.Println(acc)

	left := make([]int, n)
	right := make([]int, n)
	leftAcc := 0

	for j := 0; j < k; j++ {
		imax := 0
		for xs[imax] == nil || len(xs[imax]) == left[imax]+right[imax] {
			imax++
		}

		val := 0
		if len(xs[imax]) > 0 {
			val = xs[imax][left[imax]+(len(xs[imax])-left[imax]-right[imax])/2]
		}

		for i := imax + 1; i < n; i++ {
			if xs[i] != nil && len(xs[i]) > left[i]+right[i] {
				g := xs[i][left[i]+(len(xs[i])-left[i]-right[i])/2]
				if val < g {
					val = g
					imax = i
				}
			}
		}

		if j%2 == 0 {
			leftAcc += val
		} else {
			right[imax]++
		}
		left[imax]++
	}

	fmt.Println(leftAcc, acc-leftAcc)
}

func c20() {
	var n, m int
	fmt.Scan(&n, &m)

	adj := make([][]edge, n)
	for i := 0; i < m; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		u--
		v--
		adj[u] = append(adj[u], edge{v, w})
		adj[v] = append(adj[v], edge{u, w})
	}

	const inf = math.MaxInt64
	dist := make([]int, n)
	for i := 0; i < n; i++ {
		dist[i] = inf
	}

	dist[0] = 0
	heap := NewHeap()
	heap.Push(&item{0, 0})

	for !heap.Empty() {
		u := heap.Pop().(*item)
		if u.dist == dist[u.vertex] {
			for _, e := range adj[u.vertex] {
				if dist[e.vertex] > u.dist+e.weight {
					dist[e.vertex] = u.dist + e.weight
					heap.Push(&item{dist[e.vertex], e.vertex})
				}
			}
		}
	}

	if dist[n-1] == inf {
		fmt.Println(-1)
	} else {
		path := []int{n}
		for u := n - 1; u != 0; u = prev[u] {
			path = append(path, u+1)
		}
		for i := len(path) - 1; i >= 0; i-- {
			fmt.Print(path[i], " ")
		}
		fmt.Println()
	}
}

type item struct {
	dist, vertex int
}

type Heap struct {
	items []*item
}

func NewHeap() *Heap {
	return &Heap{items: make([]*item, 0)}
}

func (h *Heap) Empty() bool {
	return len(h.items) == 0
}

func (h *Heap) Push(x *item) {
	h.items = append(h.items, x)
	h.up(len(h.items) - 1)
}

func (h *Heap) Pop() *item {
	n := len(h.items) - 1
	h.items[0], h.items[n] = h.items[n], h.items[0]
	h.down(0, n)
	x := h.items[n]
	h.items = h.items[:n]
	return x
}

func (h *Heap) up(j int) {
	for {
		i := (j - 1) / 2
		if i == j || h.items[j].dist >= h.items[i].dist {
			break
		}
		h.items[i], h.items[j] = h.items[j], h.items[i]
		j = i
	}
}

func (h *Heap) down(i, n int) {
	for {
		j1 := 2*i + 1
		if j1 >= n || j1 < 0 {
			break
		}
		j := j1
		if j2 := j1 + 1; j2 < n && h.items[j1].dist > h.items[j2].dist {
			j = j2
		}
		if h.items[j].dist >= h.items[i].dist {
			break
		}
		h.items[i], h.items[j] = h.items[j], h.items[i]
		i = j
	}
}

type edge struct {
	vertex, weight int
}

func b319() int {
	var n int
	fmt.Scan(&n)

	xs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xs[i])
	}

	m := make(map[int]int)
	m[xs[0]] = 0
	val := 0

	for i := 1; i < n; i++ {
		if _, ok := m[xs[i]]; ok {
			m[xs[i]]++
			for k, v := range m {
				if v == 0 {
					delete(m, k)
				}
			}
		} else {
			val = max(val, len(m))
			m = make(map[int]int)
		}
		m[xs[i]] = 0
	}

	val = max(val, len(m))

	return val
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func b41() int {
	var n, b int
	fmt.Scan(&n, &b)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	m := make([]int, n)
	m[n-1] = a[n-1]
	for i := n - 2; i >= 0; i-- {
		m[i] = max(m[i+1], a[i])
	}

	val := b
	for i := 0; i < n; i++ {
		val = max(val, b%a[i]+b/a[i]*m[i])
	}

	return val
}

func b99() string {
	var n int
	fmt.Scan(&n)

	cards := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&cards[i])
	}

	i, j := 0, 0
	for k := 1; k < n; k++ {
		if cards[k] < cards[i] {
			i = k
		}
		if cards[k] > cards[j] {
			j = k
		}
	}

	if i == j {
		return "Exemplary pages."
	} else if (cards[i][0]+cards[j][0])%2 == 1 {
		return "Unrecoverable configuration."
	} else {
		v := (cards[j][1] - cards[i][1]) / 2
		cards[i] = string(cards[i][0]) + string(cards[i][1]+v)
		cards[j] = string(cards[j][0]) + string(cards[j][1]-v)

		if len(set(cards)) == 1 {
			return fmt.Sprintf("%d ml. from cup %d to cup %d.", v, i+1, j+1)
		} else {
			return "Unrecoverable configuration."
		}
	}
}

func set(xs []string) []string {
	m := make(map[string]bool)
	for _, x := range xs {
		m[x] = true
	}
	res := make([]string, 0, len(m))
	for x := range m {
		res = append(res, x)
	}
	return res
}

func b70() {
	var n int
	fmt.Scan(&n)

	var str string
	fmt.Scan(&str)

	xs := make([]int, 0)
	i := 0
	for i < len(str) {
		for i < len(str) && str[i] == ' ' {
			i++
		}
		j := i
		for j < len(str) && str[j] != '.' && str[j] != '?' && str[j] != '!' {
			j++
		}
		if j < len(str) {
			j++
		}
		if j > i {
			xs = append(xs, j-i)
		}
		i = j
	}

	pred := func(a int) bool {
		return a < n
	}
	if sort.SearchInts(xs, n, pred) != len(xs) {
		fmt.Println("Impossible")
	} else {
		k := 0
		i := 0
		for i < len(xs) {
			k++
			len := xs[i]
			i++
			for i < len(xs) && len+xs[i] < n {
				len += 1 + xs[i]
				i++
			}
		}
		fmt.Println(k)
	}
}

func countUnique(xs []string, k int) int {
	m := make(map[byte]bool)
	for _, x := range xs {
		m[x[k]] = true
	}
	return len(m)
}

func id12(a int) int {
	k := 0
	for a > 0 {
		k += a & 1
		a >>= 1
	}
	return k
}

func a442() int {
	var n int
	fmt.Scan(&n)

	cards := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&cards[i])
	}

	id25 := countUnique(cards, 0)
	id21 := countUnique(cards, 1)

	charMap := make(map[byte]int)
	charMap['R'] = 0
	charMap['G'] = 1
	charMap['B'] = 2
	charMap['Y'] = 3
	charMap['W'] = 4

	type cardType struct {
		color, number int
	}
	xs := make([]cardType, n)
	for i := 0; i < n; i++ {
		xs[i] = cardType{1 << charMap[cards[i][0]], 1 << (cards[i][1] - '0')}
	}

	val := id25 + id21 - 2

	for i := 0; i < (1 << 6) - 1; i++ {
		icnt := id12(i)
		if icnt < val {
			for j := 0; j < (1 << 6) - 1; j++ {
				jcnt := id12(j)
				if icnt+jcnt < val {
					flag := true
					for _, a := range xs {
						for _, b := range xs {
							if a != b {
								u := a.color == b.color || icnt+1 < id25 && a.color&(1<<i) == 0 && b.color&(1<<i) == 0
								v := a.number == b.number || jcnt+1 < id21 && a.number&(1<<j) == 0 && b.number&(1<<j) == 0
								if v && u {
									flag = false
									break
								}
							}
						}
					}
					if flag {
						val = icnt + jcnt
					}
				}
			}
		}
	}

	return val
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(a442())
}
