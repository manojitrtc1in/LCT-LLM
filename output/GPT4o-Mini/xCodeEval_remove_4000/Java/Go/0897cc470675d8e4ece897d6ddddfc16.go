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
	var res int
	fmt.Sscanf(in.scanner.Text(), "%d", &res)
	return res
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

func (out *OutputWriter) Println(i int) {
	fmt.Fprintln(out.writer, i)
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOutbound []int
	nextOutbound []int
	from []int
	to []int
	weight []int64
	capacity []int64
	reverseEdge []int
}

func NewGraph(vertexCount int) *Graph {
	return &Graph{
		vertexCount: vertexCount,
		firstOutbound: make([]int, vertexCount),
		nextOutbound: make([]int, vertexCount),
		from: make([]int, vertexCount),
		to: make([]int, vertexCount),
		weight: make([]int64, vertexCount),
		capacity: make([]int64, vertexCount),
		reverseEdge: make([]int, vertexCount),
	}
}

func (g *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	g.from[g.edgeCount] = fromID
	g.to[g.edgeCount] = toID
	g.weight[g.edgeCount] = weight
	g.capacity[g.edgeCount] = capacity
	g.reverseEdge[g.edgeCount] = reverseEdge
	g.edgeCount++
	return g.edgeCount - 1
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
		g.AddEdge(i, target, 0, 2, -1)
	}
	for i := 0; i < 26; i++ {
		g.AddEdge(source, i+n, 0, int64(cnt[i]), -1)
		for j := 0; j*2 < n; j++ {
			w := int64(0)
			if s[j] == s[n-j-1] {
				if s[j] == rune(i+'a') {
					w = -int64(max(a[j], a[n-j-1]))
				}
				g.AddEdge(i+n, j, w, 1, -1)
			} else {
				if s[j] == rune(i+'a') {
					w -= int64(a[j])
				}
				if s[n-j-1] == rune(i+'a') {
					w -= int64(a[n-j-1])
				}
				g.AddEdge(i+n, j, w, 1, -1)
			}
		}
	}
	id3 := NewId6(g, source, target, true)
	out.Println(-id3.Id1().First)
}

type Pair struct {
	First  int64
	Second int64
}

func NewPair(first, second int64) Pair {
	return Pair{First: first, Second: second}
}

type Id6 struct {
	graph      *Graph
	source     int
	destination int
	phi        []int64
	id4        []int64
	lastEdge   []int
}

func NewId6(graph *Graph, source, destination int, id11 bool) *Id6 {
	id6 := &Id6{
		graph:      graph,
		source:     source,
		destination: destination,
		phi:        make([]int64, graph.vertexCount),
		id4:        make([]int64, graph.vertexCount),
		lastEdge:   make([]int, graph.vertexCount),
	}
	if id11 {
		id6.Id7()
	}
	return id6
}

func (id6 *Id6) Id7() {
	for i := range id6.phi {
		id6.phi[i] = 1<<63 - 1
	}
	id6.phi[id6.source] = 0
	// Implement the rest of the logic for Id7
}

func (id6 *Id6) Id1() Pair {
	return id6.Id1(1<<63 - 1)
}

func (id6 *Id6) Id1(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	// Implement the rest of the logic for Id1
	return NewPair(cost, flow)
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
	solver := &TaskF{}
	solver.Solve(1, in, out)
	out.Close()
}
