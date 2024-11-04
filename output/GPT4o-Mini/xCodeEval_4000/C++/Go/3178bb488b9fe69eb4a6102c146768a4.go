package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const inf = 1234000000
const llinf = 1234567890000000000

type Pair struct {
	first, second int
}

type Graph struct {
	adjacencyList [][]int
}

func NewGraph(n int) *Graph {
	return &Graph{adjacencyList: make([][]int, n)}
}

func (g *Graph) AddEdge(a, b int) {
	g.adjacencyList[a] = append(g.adjacencyList[a], b)
	g.adjacencyList[b] = append(g.adjacencyList[b], a)
}

var (
	n    int
	g    *Graph
	siz  []int
	dep  []int
	ans  []Pair
	ava  []int
)

func dfs1(x, y, d int) {
	siz[x] = 1
	dep[x] = d
	for _, v := range g.adjacencyList[x] {
		if v != y {
			dfs1(v, x, d+1)
			siz[x] += siz[v]
		}
	}
}

func dfs2(x, y, d int) {
	t := ava[0]
	ava = ava[1:]
	if t <= d {
		panic("assertion failed")
	}
	ans = append(ans, Pair{first: x, second: y})
	for _, v := range g.adjacencyList[x] {
		if v != y {
			dfs2(v, x, t)
		}
	}
}

func dfs3(x, y, d int, seen map[int]struct{}) {
	seen[d] = struct{}{}
	for _, e := range g.adjacencyList[x] {
		if e != y {
			dfs3(e, x, d+1)
		}
	}
}

func testAns() {
	g2 := NewGraph(n)
	seen := make(map[int]struct{})
	for _, x := range ans {
		g2.AddEdge(x.first, x.second)
	}
	for i := 1; i <= n; i++ {
		dfs3(i, -1, 0, seen)
	}
	for i := 1; i <= n*n*2/9; i++ {
		if _, ok := seen[i]; !ok {
			panic("assertion failed")
		}
	}
}

func main() {
	fmt.Scan(&n)
	if n == 1 {
		return
	}
	g = NewGraph(n)
	siz = make([]int, n)
	dep = make([]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g.AddEdge(a-1, b-1)
	}
	dfs1(0, -1, 0)
	M := n * 2 / 3
	for i := 0; i < n; i++ {
		sizes := []Pair{{1, i}}
		p := -1
		for _, v := range g.adjacencyList[i] {
			if dep[v] == dep[i]+1 {
				sizes = append(sizes, Pair{first: siz[v], second: v})
			} else {
				p = v
			}
		}
		if i != 0 {
			sizes = append(sizes, Pair{first: n - siz[i], second: p})
		}
		good := true
		for _, x := range sizes {
			if x.first > M {
				good = false
			}
		}
		if good {
			v1, v2 := []Pair{}, []Pair{}
			sort.Slice(sizes, func(a, b int) bool {
				return sizes[a].first > sizes[b].first
			})
			sum1, sum2 := 0, 0
			whme := 0
			for _, c := range sizes {
				if sum1+c.first > M {
					v2 = append(v2, c)
					sum2 += c.first
					if c.second == i {
						whme = 2
					}
				} else {
					v1 = append(v1, c)
					sum1 += c.first
					if c.second == i {
						whme = 1
					}
				}
			}
			if sum1*sum2 < n*n*2/9 {
				panic("assertion failed")
			}
			if whme == 2 {
				v1, v2 = v2, v1
				sum1, sum2 = sum2, sum1
			}
			for j := 1; j <= sum1-1; j++ {
				ava = append(ava, j)
			}
			for _, x := range v1 {
				if x.second != i {
					dfs2(x.second, i, 0)
				}
			}
			if len(ava) != 0 {
				panic("assertion failed")
			}
			for j := 0; j < sum2; j++ {
				ava = append(ava, 1+j*sum1)
			}
			for _, x := range v2 {
				dfs2(x.second, i, 0)
			}
			if len(ava) != 0 {
				panic("assertion failed")
			}
			for _, x := range ans {
				fmt.Printf("%d %d %d\n", x.first, x.second)
			}
			testAns()
			return
		}
	}
	panic("assertion failed")
}
