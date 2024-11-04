package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	adj          [][]int
	out          = bufio.NewWriter(os.Stdout)
	mod          = 1000000007
	notmemo      [][]int
	k            int
	a            []int64
	b            []int
	m            int
	c            []rune
	trace        []int
	h            int
	x            int
	ans1         int
	ans2         int
	mulpath      []bool
	dist         []int
)

func main() {
	defer out.Flush()
	sc := NewScanner(os.Stdin)
	n := sc.NextInt()
	m := sc.NextInt()
	adj = make([][]int, n)
	for i := 0; i < n; i++ {
		adj[i] = []int{}
	}
	for m > 0 {
		m--
		u := sc.NextInt() - 1
		v := sc.NextInt() - 1
		adj[v] = append(adj[v], u)
	}
	dist = make([]int, n)
	mulpath = make([]bool, n)
	k = sc.NextInt()
	p := make([]int, k)
	for i := 0; i < k; i++ {
		p[i] = sc.NextInt() - 1
	}
	bfs(p[k-1])
	min, max := 0, 0
	for i := 0; i < k-1; i++ {
		if dist[p[i+1]]+1 == dist[p[i]] {
			if mulpath[p[i]] {
				max++
			}
		} else {
			min++
			max++
		}
	}
	fmt.Fprintf(out, "%d %d\n", min, max)
}

func bfs(s int) {
	for i := range dist {
		dist[i] = int(1e9)
	}
	dist[s] = 0
	q := []int{s}
	for len(q) > 0 {
		u := q[0]
		q = q[1:]
		for _, v := range adj[u] {
			if dist[v] == int(1e9) {
				dist[v] = dist[u] + 1
				q = append(q, v)
			} else if dist[v] == dist[u]+1 {
				mulpath[v] = true
			}
		}
	}
}

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	return &Scanner{scanner: s}
}

func (s *Scanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *Scanner) NextInt() int {
	return int(s.NextInt64())
}

func (s *Scanner) NextInt64() int64 {
	val, _ := strconv.ParseInt(s.Next(), 10, 64)
	return val
}

func (s *Scanner) NextFloat64() float64 {
	val, _ := strconv.ParseFloat(s.Next(), 64)
	return val
}

func (s *Scanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}
