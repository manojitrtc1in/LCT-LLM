package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{scanner: bufio.NewScanner(r)}
}

func (in *InputReader) NextInt() int {
	in.scanner.Scan()
	var n int
	fmt.Sscanf(in.scanner.Text(), "%d", &n)
	return n
}

func (in *InputReader) NextString() string {
	in.scanner.Scan()
	return in.scanner.Text()
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

func (out *OutputWriter) Println(i int64) {
	fmt.Fprintln(out.writer, i)
}

type Graph struct {
	vertexCount int
	edges       [][]Edge
}

type Edge struct {
	to       int
	weight   int64
	capacity int64
}

func NewGraph(vertexCount int) *Graph {
	edges := make([][]Edge, vertexCount)
	return &Graph{vertexCount: vertexCount, edges: edges}
}

func (g *Graph) AddEdge(from, to int, weight int64, capacity int64) {
	g.edges[from] = append(g.edges[from], Edge{to: to, weight: weight, capacity: capacity})
}

type MinCostFlow struct {
	graph      *Graph
	source     int
	destination int
}

func NewMinCostFlow(graph *Graph, source, destination int) *MinCostFlow {
	return &MinCostFlow{graph: graph, source: source, destination: destination}
}

func (m *MinCostFlow) MinCostMaxFlow() (int64, int64) {
	// Implement the min-cost max-flow algorithm here
	return 0, 0 // Placeholder return
}

type TaskF struct{}

func (t *TaskF) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.NextInt()
	s := in.NextString()
	a := make([]int, n)
	cnt := make([]int, 26)

	for i := 0; i < n; i++ {
		a[i] = in.NextInt()
		cnt[s[i]-'a']++
	}

	g := NewGraph(n + 100)
	source := n + 100 - 2
	target := source + 1

	for i := 0; i*2 < n; i++ {
		g.AddEdge(i, target, 0, 2)
	}

	for i := 0; i < 26; i++ {
		g.AddEdge(source, i+n, 0, int64(cnt[i]))
		for j := 0; j*2 < n; j++ {
			w := int64(0)
			if s[j] == s[n-j-1] {
				if s[j] == rune(i+'a') {
					w = -int64(max(a[j], a[n-j-1]))
				}
				g.AddEdge(i+n, j, w, 1)
			} else {
				if s[j] == rune(i+'a') {
					w -= int64(a[j])
				}
				if s[n-j-1] == rune(i+'a') {
					w -= int64(a[n-j-1])
				}
				g.AddEdge(i+n, j, w, 1)
			}
		}
	}

	mcmf := NewMinCostFlow(g, source, target)
	cost, _ := mcmf.MinCostMaxFlow()
	out.Println(-cost)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := TaskF{}
	solver.Solve(1, in, out)
	out.Close()
}
