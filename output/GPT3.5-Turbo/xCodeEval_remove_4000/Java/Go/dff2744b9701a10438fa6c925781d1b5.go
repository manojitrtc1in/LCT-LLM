package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOut    []int
	from        []int
	to          []int
	nextOut     []int
	flags       []int
}

func NewGraph(vertexCount, edgeCapacity int) *Graph {
	g := &Graph{
		vertexCount: vertexCount,
		edgeCount:   0,
		firstOut:    make([]int, vertexCount),
		from:        make([]int, edgeCapacity),
		to:          make([]int, edgeCapacity),
		nextOut:     make([]int, edgeCapacity),
		flags:       make([]int, edgeCapacity),
	}
	for i := 0; i < vertexCount; i++ {
		g.firstOut[i] = -1
	}
	return g
}

func (g *Graph) AddEdge(from, to int) {
	g.from[g.edgeCount] = from
	g.to[g.edgeCount] = to
	g.nextOut[g.edgeCount] = g.firstOut[from]
	g.firstOut[from] = g.edgeCount
	g.edgeCount++
}

type TaskD struct {
	graph    *Graph
	weight   []int
	path     []int
}

func (task *TaskD) Solve(input *InputReader, output *OutputWriter) {
	n := input.ReadInt()
	k := input.ReadInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = input.ReadInt()
	}
	u := make([]int, n-1)
	v := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		u[i] = input.ReadInt() - 1
		v[i] = input.ReadInt() - 1
	}
	graph := NewGraph(n, 2*(n-1))
	for i := 0; i < n-1; i++ {
		graph.AddEdge(u[i], v[i])
		graph.AddEdge(v[i], u[i])
	}
	order := make([]int, n)
	for i := 0; i < n; i++ {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return a[order[i]] > a[order[j]]
	})
	left := k
	right := n
	weight := make([]int, n)
	degree := make([]int, n)
	for i := 0; i < n-1; i++ {
		degree[u[i]]++
		degree[v[i]]++
	}
	remaining := make([]int, n)
	queue := make([]int, n)
	path := make([]int, n)
	for left < right {
		middle := (left + right) >> 1
		threshold := a[order[middle-1]]
		for i := 0; i < n; i++ {
			if a[i] >= threshold {
				weight[i] = 1
			} else {
				weight[i] = 0
			}
		}
		copy(remaining, degree)
		size := 0
		for i := 0; i < n; i++ {
			if degree[i] == 1 && weight[i] > 0 {
				queue[size] = i
				size++
			}
		}
		for i := 0; i < size; i++ {
			current := queue[i]
			for j := graph.firstOut[current]; j != -1; j = graph.nextOut[j] {
				next := graph.to[j]
				if weight[next] != 0 {
					weight[next] += weight[current]
					weight[current] = 0
					remaining[next]--
					if remaining[next] == 1 {
						queue[size] = next
						size++
					}
				}
			}
		}
		result := task.dfs(0, -1, graph, weight, path)
		if result >= k {
			right = middle
		} else {
			left = middle + 1
		}
	}
	output.PrintLine(a[order[left-1]])
}

func (task *TaskD) dfs(current, last int, graph *Graph, weight, path []int) int {
	result := 0
	max := 0
	second := 0
	for i := graph.firstOut[current]; i != -1; i = graph.nextOut[i] {
		next := graph.to[i]
		if next == last {
			continue
		}
		result = maxInt(result, task.dfs(next, current, graph, weight, path))
		if path[next] > max {
			second = max
			max = path[next]
		} else {
			second = maxInt(second, path[next])
		}
	}
	if weight[current] != 0 {
		path[current] = weight[current] + max
		result = maxInt(result, max+second+weight[current])
	} else {
		path[current] = 0
	}
	return result
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	var x int
	_, _ = fmt.Fscan(in.reader, &x)
	return x
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) PrintLine(a ...interface{}) {
	_, _ = fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	_ = out.writer.Flush()
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	task := &TaskD{}
	task.Solve(input, output)
	output.Flush()
}
