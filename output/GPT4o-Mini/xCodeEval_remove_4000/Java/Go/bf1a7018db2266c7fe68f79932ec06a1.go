package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const MOD = 1000000007

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	reader := bufio.NewReader(os.Stdin)
	return &FastReader{scanner: bufio.NewScanner(reader)}
}

func (fr *FastReader) NextInt() int {
	fr.scanner.Scan()
	val, _ := strconv.Atoi(fr.scanner.Text())
	return val
}

func (fr *FastReader) NextLong() int64 {
	fr.scanner.Scan()
	val, _ := strconv.ParseInt(fr.scanner.Text(), 10, 64)
	return val
}

type Node struct {
	lo, hi int
}

func (n Node) Compare(o Node) int {
	if n.lo != o.lo {
		return n.lo - o.lo
	}
	return n.hi - o.hi
}

type Main struct {
	dirs8   [][2]int
	dirs4   [][2]int
	fac     []int
	ifac    []int
	pow2    []int
	mobius  []int
	sieve   []int
	factors [][]int
}

func NewMain() *Main {
	return &Main{
		dirs8:   [][2]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}},
		dirs4:   [][2]int{{0, 1}, {0, -1}, {-1, 0}, {1, 0}},
		fac:     make([]int, 1001),
		ifac:    make([]int, 1001),
		pow2:    make([]int, 1001),
		mobius:  make([]int, 1001),
		sieve:   make([]int, 1001),
		factors: make([][]int, 1001),
	}
}

func (m *Main) dfs(root, par, chosenRoot, special int, nbs [][]int, size []int, visited []bool) int64 {
	sz := 1
	visited[root] = true
	if len(nbs[root]) == 1 && par > 0 {
		size[root] = 1
		if root == special {
			return 1
		}
		return 0
	}

	ans := int64(0)
	if root == special {
		ans = 1
	}
	for _, next := range nbs[root] {
		if next != par && !visited[next] {
			sub := m.dfs(next, root, chosenRoot, special, nbs, size, visited)
			if root == chosenRoot {
				if sub > 0 {
					return sub
				}
			} else {
				ans += sub
			}
			sz += size[next]
		}
	}
	size[root] = sz
	if ans == 0 {
		return 0
	}
	return int64(sz)
}

func (m *Main) solve() {
	fr := NewFastReader()
	fr.scanner.Split(bufio.ScanWords)

	nt := fr.NextInt()
	var sb string

	for it := 0; it < nt; it++ {
		n := fr.NextInt()
		m := fr.NextInt()
		s := fr.NextInt()
		t := fr.NextInt()
		sz := make([]int, n+1)
		nbs := make([][]int, n+1)
		es := make([][2]int, m)

		for i := 0; i < m; i++ {
			es[i][0] = fr.NextInt()
			es[i][1] = fr.NextInt()
			sz[es[i][0]]++
			sz[es[i][1]]++
		}
		for i := 1; i <= n; i++ {
			nbs[i] = make([]int, sz[i])
			sz[i] = 0
		}

		for _, e := range es {
			p := e[0]
			q := e[1]
			nbs[p][sz[p]] = q
			nbs[q][sz[q]] = p
			sz[p]++
			sz[q]++
		}
		id2 := make([]int, n+1)
		visited := make([]bool, n+1)
		l := m.dfs(s, 0, s, t, nbs, id2, visited)

		for i := 1; i <= n; i++ {
			id2[i] = 0
			visited[i] = false
		}
		r := m.dfs(t, 0, t, s, nbs, id2, visited)
		tot := (int64(n-1-l) * int64(n-1-r)) % MOD
		sb += fmt.Sprintf("%d\n", tot)
	}
	fmt.Print(sb)
}

func main() {
	m := NewMain()
	m.solve()
}
