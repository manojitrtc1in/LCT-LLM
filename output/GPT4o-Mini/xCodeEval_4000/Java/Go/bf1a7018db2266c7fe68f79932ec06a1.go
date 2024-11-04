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
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)
	return &FastReader{scanner: scanner}
}

func (fr *FastReader) next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) nextInt() int {
	val, _ := strconv.Atoi(fr.next())
	return val
}

func (fr *FastReader) nextLong() int64 {
	val, _ := strconv.ParseInt(fr.next(), 10, 64)
	return val
}

type Node struct {
	lo, hi int
}

func (n Node) Less(o Node) bool {
	if n.lo != o.lo {
		return n.lo < o.lo
	}
	return n.hi < o.hi
}

func main() {
	fr := NewFastReader()
	nt := fr.nextInt()

	for it := 0; it < nt; it++ {
		n := fr.nextInt()
		m := fr.nextInt()
		s := fr.nextInt()
		t := fr.nextInt()

		sz := make([]int, n+1)
		nbs := make([][]int, n+1)
		es := make([][2]int, m)

		for i := 0; i < m; i++ {
			es[i][0] = fr.nextInt()
			es[i][1] = fr.nextInt()
			sz[es[i][0]]++
			sz[es[i][1]]++
		}

		for i := 1; i <= n; i++ {
			nbs[i] = make([]int, sz[i])
			sz[i] = 0
		}

		for _, e := range es {
			p, q := e[0], e[1]
			nbs[p][sz[p]] = q
			sz[p]++
			nbs[q][sz[q]] = p
			sz[q]++
		}

		subTreeSize := make([]int, n+1)
		visited := make([]bool, n+1)
		l := dfs(s, 0, s, t, nbs, subTreeSize, visited)

		for i := 1; i <= n; i++ {
			subTreeSize[i] = 0
			visited[i] = false
		}

		r := dfs(t, 0, t, s, nbs, subTreeSize, visited)
		tot := (n - 1 - l) * (n - 1 - r)
		fmt.Println(tot)
	}
}

func dfs(root, par, chosenRoot, special int, nbs [][]int, size []int, visited []bool) int64 {
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
			sub := dfs(next, root, chosenRoot, special, nbs, size, visited)
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

func pow(v, p int64) int64 {
	ans := int64(1)
	for p > 0 {
		if p%2 == 1 {
			ans = ans * v % MOD
		}
		v = v * v % MOD
		p /= 2
	}
	return ans
}

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func abs(v int64) int64 {
	if v > 0 {
		return v
	}
	return -v
}
