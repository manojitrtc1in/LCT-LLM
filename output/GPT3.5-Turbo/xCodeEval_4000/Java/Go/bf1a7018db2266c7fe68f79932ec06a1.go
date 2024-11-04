package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader(br *bufio.Reader) *FastReader {
	return &FastReader{br: br}
}

func (r *FastReader) Next() string {
	for {
		line, err := r.br.ReadString('\n')
		if err != nil {
			return ""
		}
		line = strings.TrimSpace(line)
		if line != "" {
			return line
		}
	}
}

func (r *FastReader) NextInt() int {
	num, _ := strconv.Atoi(r.Next())
	return num
}

func (r *FastReader) NextLong() int64 {
	num, _ := strconv.ParseInt(r.Next(), 10, 64)
	return num
}

func (r *FastReader) NextDouble() float64 {
	num, _ := strconv.ParseFloat(r.Next(), 64)
	return num
}

func (r *FastReader) NextLine() string {
	line, _ := r.br.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	in := bufio.NewReader(os.Stdin)

	nt := NewFastReader(in).NextInt()

	var sb strings.Builder

	for it := 0; it < nt; it++ {
		n := NewFastReader(in).NextInt()
		m := NewFastReader(in).NextInt()
		s := NewFastReader(in).NextInt()
		t := NewFastReader(in).NextInt()
		sz := make([]int, n+1)
		nbs := make([][]int, n+1)
		es := make([][]int, m)
		for i := 0; i < m; i++ {
			es[i] = make([]int, 2)
			es[i][0] = NewFastReader(in).NextInt()
			es[i][1] = NewFastReader(in).NextInt()
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

		subTreeSize := make([]int, n+1)
		visited := make([]bool, n+1)
		l := dfs(s, 0, s, t, nbs, subTreeSize, visited)
		for i := 1; i <= n; i++ {
			subTreeSize[i] = 0
			visited[i] = false
		}
		r := dfs(t, 0, t, s, nbs, subTreeSize, visited)
		tot := (n - 1 - l) * (n - 1 - r)
		sb.WriteString(fmt.Sprintf("%d\n", tot))
	}
	fmt.Print(sb.String())
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
