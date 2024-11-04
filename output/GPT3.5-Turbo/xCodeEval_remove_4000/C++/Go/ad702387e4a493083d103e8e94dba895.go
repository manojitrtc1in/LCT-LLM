package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = int(1e9 + 7)
const gmod = 2
const inf = 1039074182
const eps = 1e-9
const llinf = 1 * inf * inf

type pii struct {
	first  int
	second int
}

type pair struct {
	first  pii
	second int
}

func chmin(x *int, b int) {
	if b < *x {
		*x = b
	}
}

func chmax(x *int, b int) {
	if b > *x {
		*x = b
	}
}

func chadd(x *int, b int) {
	*x += b - mod
	*x += (*x >> 31 & mod)
}

func chmul(x *int, b int) {
	*x = 1 * *x * b % mod
}

func chmod(x *int, b int) {
	*x %= b
	*x += b
	if *x >= b {
		*x -= b
	}
}

func mabs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func id0(x int) {
	vec := make([]int, 0)
	for x != 0 {
		vec = append(vec, x&1)
		x >>= 1
	}
	for i := 0; i < len(vec); i++ {
		fmt.Print(vec[i])
	}
	fmt.Print(" ")
}

func id0WithLen(x int, length int) {
	vec := make([]int, 0)
	for x != 0 {
		vec = append(vec, x&1)
		x >>= 1
	}
	reverse(vec)
	for i := len(vec); i < length; i++ {
		fmt.Print("0")
	}
	for i := 0; i < len(vec); i++ {
		fmt.Print(vec[i])
	}
	fmt.Print(" ")
}

func reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func printVector(vec []int) {
	fmt.Print("{")
	for i := 0; i < len(vec); i++ {
		fmt.Print(vec[i])
		if i != len(vec)-1 {
			fmt.Print(",")
		}
	}
	fmt.Print("}")
}

func printPair(p pii) {
	fmt.Printf("(%d,%d)", p.first, p.second)
}

func printSet(s []int) {
	t := make([]int, 0)
	for _, x := range s {
		t = append(t, x)
	}
	printVector(t)
}

func printMultiset(s []int) {
	t := make([]int, 0)
	for _, x := range s {
		t = append(t, x)
	}
	printVector(t)
}

func printQueue(q []int) {
	t := make([]int, 0)
	for len(q) > 0 {
		t = append(t, q[0])
		q = q[1:]
	}
	printVector(t)
}

func printMap(m map[int]int) {
	for k, v := range m {
		fmt.Printf("Key: %d Value: %d\n", k, v)
	}
}

func dotProduct(v1 []int, v2 []int) int {
	n := len(v1)
	res := 0
	for i := 0; i < n; i++ {
		res += v1[i] * v2[i]
	}
	return res
}

func addPair(x pii, y pii) pii {
	return pii{x.first + y.first, x.second + y.second}
}

func negatePair(x pii) pii {
	return pii{-x.first, -x.second}
}

func transpose(vec [][]int) [][]int {
	n := len(vec)
	m := len(vec[0])
	v := make([][]int, m)
	for i := 0; i < m; i++ {
		v[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			v[i][j] = vec[j][i]
		}
	}
	return v
}

func dfs(x int, visit []int, c []int, cnt *int, edges [][]int) {
	visit[x] = 1
	c[x] = *cnt
	for _, u := range edges[x] {
		if visit[u] == 1 {
			continue
		}
		dfs(u, visit, c, cnt, edges)
	}
}

func bfs(src int, visit []int, dist []int, edges [][]int) {
	n := len(edges)
	visit[src] = 1
	dist[src] = 0
	que := make([]int, 0)
	que = append(que, src)
	for len(que) > 0 {
		x := que[0]
		que = que[1:]
		for _, u := range edges[x] {
			if visit[u] == 1 {
				continue
			}
			dist[u] = dist[x] + 1
			visit[u] = 1
			que = append(que, u)
		}
	}
}

func liu(x int, y int, flow int, a []int, res *[]pair) {
	a[x] -= flow
	a[y] += flow
	*res = append(*res, pair{pii{x, y}, flow})
}

func adjust(x int, y int, a []int, b []int, edges [][]int, res *[]pair) {
	if a[x] != b[x] && a[y] != b[y] {
		if a[x] < b[x] {
			x, y = y, x
		}
		flow := int(math.Min(float64(mabs(a[x]-b[x])), float64(mabs(a[y]-b[y]))))
		bfs(x, make([]int, len(edges)), make([]int, len(edges)), edges)
		routes := make([]int, 0)
		routes = append(routes, y)
		for y != x {
			step := dist[y]
			nxt := -1
			for _, ny := range edges[y] {
				if dist[ny] != step-1 {
					continue
				}
				nxt = ny
				break
			}
			y = nxt
			routes = append(routes, y)
		}
		reverse(routes)
		notEq := 0
		for _, x := range routes {
			if a[x] != b[x] {
				notEq++
			}
		}
		liu(0, flow, routes[1:], a, res)
		for _, x := range routes {
			if a[x] != b[x] {
				notEq--
			}
		}
		if notEq < 1 {
			panic("NO")
		}
	}
}

func main() {
	var n, v, m int
	fmt.Scan(&n, &v, &m)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	edges := make([][]int, n)
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		edges[x] = append(edges[x], y)
		edges[y] = append(edges[y], x)
	}
	visit := make([]int, n)
	c := make([]int, n)
	cnt := 0
	for i := 0; i < n; i++ {
		if visit[i] == 1 {
			continue
		}
		dfs(i, visit, c, &cnt, edges)
		cnt++
	}
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[c[i]] += a[i]
		s[c[i]] -= b[i]
	}
	for i := 0; i < n; i++ {
		if s[i] != 0 {
			panic("NO")
		}
	}
	res := make([]pair, 0)
	for i := 0; i < n; i++ {
		if a[i] == b[i] {
			continue
		}
		for j := i + 1; j < n; j++ {
			if c[i] != c[j] {
				continue
			}
			if a[j] == b[j] {
				continue
			}
			if a[i] < b[i] && a[j] < b[j] {
				continue
			}
			if a[i] > b[i] && a[j] > b[j] {
				continue
			}
			adjust(i, j, a, b, edges, &res)
			break
		}
		if a[i] != b[i] {
			i--
		}
	}
	fmt.Println(len(res))
	for _, e := range res {
		fmt.Printf("%d %d %d\n", e.first.first+1, e.first.second+1, e.second)
	}
}
