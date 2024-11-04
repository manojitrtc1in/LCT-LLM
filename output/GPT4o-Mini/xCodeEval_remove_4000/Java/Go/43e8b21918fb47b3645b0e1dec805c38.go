package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const id32 = 1000000007

var fr = bufio.NewReader(os.Stdin)

func main() {
	t := 1
	for tc := 0; tc < t; tc++ {
		var n int
		var mod int64
		fmt.Fscan(fr, &n, &mod)

		dp := make([]int64, n+1)
		dp[n] = 1

		for i := n - 1; i > 0; i-- {
			dp[i] += dp[i+1]
			dp[i] %= mod

			for div := int64(1); div*i <= int64(n); div++ {
				lb := div * int64(i)
				ub := int64(math.Min(float64(div*(i+1)-1), float64(n)))
				segSum := dp[lb]
				if ub+1 <= int64(n) {
					segSum -= dp[ub+1]
				}
				dp[i] += segSum
				dp[i] %= mod
			}

			dp[i] += dp[i+1]
			dp[i] %= mod
		}

		fmt.Println((dp[1] - dp[2] + mod) % mod)
	}
}

type Edge struct {
	from, to int
	weight   int64
	id       int
}

func (e Edge) Compare(that Edge) int {
	if e.id < that.id {
		return -1
	} else if e.id > that.id {
		return 1
	}
	return 0
}

func id28(a []int64) [][]int64 {
	n := len(a)
	b := 32 - int(math.Log2(float64(n)))
	ret := make([][]int64, b)
	for i, l := 0, 1; i < b; i, l = i+1, l*2 {
		if i == 0 {
			ret[i] = a
		} else {
			ret[i] = make([]int64, n-l+1)
			for j := 0; j < n-l+1; j++ {
				ret[i][j] = min(ret[i-1][j], ret[i-1][j+l/2])
			}
		}
	}
	return ret
}

func id13(table [][]int64, l, r int) int64 {
	if l >= r {
		return math.MaxInt64
	}

	t := 31 - int(math.Log2(float64(r-l)))
	return min(table[t][l], table[t][r-(1<<t)])
}

type Point struct {
	x, y, z, id int64
}

func (p Point) Compare(o Point) int {
	if p.x < o.x {
		return -1
	} else if p.x > o.x {
		return 1
	} else if p.y < o.y {
		return -1
	} else if p.y > o.y {
		return 1
	} else if p.z < o.z {
		return -1
	} else if p.z > o.z {
		return 1
	}
	return 0
}

func (p Point) Equals(that Point) bool {
	return p.Compare(that) == 0
}

type BinaryLift struct {
	parentOf []int
	id14     int
	id38     [][]int
	n        int
	lvlOf    []int
}

func NewBinaryLift(tree UGraph) *BinaryLift {
	n := tree.V()
	id14 := logk(n, 2) + 1
	parentOf := make([]int, n)
	id38 := make([][]int, n)
	for i := range id38 {
		id38[i] = make([]int, id14)
		for j := range id38[i] {
			id38[i][j] = -1
		}
	}
	lvlOf := make([]int, n)
	b := &BinaryLift{parentOf: parentOf, id14: id14, id38: id38, n: n, lvlOf: lvlOf}
	b.parentConstruct(0, -1, tree, 0)
	b.binConstruct()
	return b
}

func (b *BinaryLift) parentConstruct(current, from int, tree UGraph, depth int) {
	b.parentOf[current] = from
	b.lvlOf[current] = depth
	for _, adj := range tree.adj(current) {
		if adj != from {
			b.parentConstruct(adj, current, tree, depth+1)
		}
	}
}

func (b *BinaryLift) binConstruct() {
	for node := 0; node < b.n; node++ {
		for lvl := 0; lvl < b.id14; lvl++ {
			b.binConstructHelper(node, lvl)
		}
	}
}

func (b *BinaryLift) binConstructHelper(node, lvl int) int {
	if node < 0 {
		return -1
	}
	if lvl == 0 {
		return b.id38[node][lvl] = b.parentOf[node]
	}
	if node == 0 {
		return b.id38[node][lvl] = -1
	}

	if b.id38[node][lvl] != -1 {
		return b.id38[node][lvl]
	}
	return b.id38[node][lvl] = b.binConstructHelper(b.binConstructHelper(node, lvl-1), lvl-1)
}

func (b *BinaryLift) ancestor(node, k int) int {
	if node < 0 {
		return -1
	}
	if node == 0 {
		if k == 0 {
			return node
		}
		return -1
	}
	if k > (1 << b.id14) - 1 {
		return -1
	}
	if k == 0 {
		return node
	}

	ancestor := node
	highestBit := highestOneBit(k)

	for k > 0 && ancestor != -1 {
		ancestor = b.id38[ancestor][logk(highestBit, 2)]
		k -= highestBit
		highestBit = highestOneBit(k)
	}

	return ancestor
}

func (b *BinaryLift) lca(u, v int) int {
	if u == v {
		return u
	}

	if b.lvlOf[u] < b.lvlOf[v] {
		u, v = v, u
	}

	u = b.ancestor(u, b.lvlOf[u]-b.lvlOf[v])

	if u == v {
		return u
	}

	for power := b.id14 - 1; power > -1; power-- {
		if b.id38[u][power] != b.id38[v][power] {
			u = b.id38[u][power]
			v = b.id38[v][power]
		}
	}

	return b.ancestor(u, 1)
}

type UGraph struct {
	adj []map[int]struct{}
	E   int
}

func NewUGraph(V int) *UGraph {
	adj := make([]map[int]struct{}, V)
	for i := range adj {
		adj[i] = make(map[int]struct{})
	}
	return &UGraph{adj: adj}
}

func (g *UGraph) addEdge(from, to int) {
	if _, exists := g.adj[from][to]; exists {
		return
	}
	g.E++
	g.adj[from][to] = struct{}{}
	g.adj[to][from] = struct{}{}
}

func (g *UGraph) adj(from int) []int {
	neighbors := make([]int, 0, len(g.adj[from]))
	for neighbor := range g.adj[from] {
		neighbors = append(neighbors, neighbor)
	}
	return neighbors
}

func (g *UGraph) V() int {
	return len(g.adj)
}

func (g *UGraph) E() int {
	return g.E
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func logk(n, k int64) int {
	return int(math.Log(float64(n)) / math.Log(float64(k)))
}

func highestOneBit(x int) int {
	return 1 << (int(math.Log2(float64(x))))
}
