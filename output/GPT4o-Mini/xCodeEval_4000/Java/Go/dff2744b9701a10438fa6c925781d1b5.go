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
	edges       [][]Edge
}

type Edge struct {
	to   int
	weight int64
}

type TaskD struct {
	graph  *Graph
	weight []int
	path   []int
}

func (t *TaskD) solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.readInt()
	k := in.readInt()
	a := readIntArray(in, n)
	u := make([]int, n-1)
	v := make([]int, n-1)
	readIntArrays(in, u, v)
	decreaseByOne(u, v)
	t.graph = createGraph(n, u, v)
	order := createOrder(a)
	sort.Sort(sort.Reverse(sort.IntSlice(order)))
	left, right := k, n
	t.weight = make([]int, n)
	degree := make([]int, n)
	for i := 0; i < n-1; i++ {
		degree[u[i]]++
		degree[v[i]]++
	}
	remaining := make([]int, n)
	queue := make([]int, n)
	t.path = make([]int, n)

	for left < right {
		middle := (left + right) >> 1
		threshold := a[order[middle-1]]
		for i := range t.weight {
			t.weight[i] = 0
		}
		for i := 0; i < n; i++ {
			if a[i] >= threshold {
				t.weight[i] = 1
			}
		}
		copy(remaining, degree)
		size := 0
		for i := 0; i < n; i++ {
			if degree[i] == 1 && t.weight[i] > 0 {
				queue[size] = i
				size++
			}
		}
		for i := 0; i < size; i++ {
			current := queue[i]
			for _, edge := range t.graph.edges[current] {
				next := edge.to
				if t.weight[next] != 0 {
					t.weight[next] += t.weight[current]
					t.weight[current] = 0
					remaining[next]--
					if remaining[next] == 1 {
						queue[size] = next
						size++
					}
				}
			}
		}
		result := t.dfs(0, -1)
		if result >= k {
			right = middle
		} else {
			left = middle + 1
		}
	}
	out.printLine(a[order[left-1]])
}

func (t *TaskD) dfs(current, last int) int {
	result := 0
	max, second := 0, 0
	for _, edge := range t.graph.edges[current] {
		next := edge.to
		if next == last {
			continue
		}
		result = maxInt(result, t.dfs(next, current))
		if t.path[next] > max {
			second = max
			max = t.path[next]
		} else {
			second = maxInt(second, t.path[next])
		}
	}
	if t.weight[current] != 0 {
		t.path[current] = t.weight[current] + max
		result = maxInt(result, max+second+t.weight[current])
	} else {
		t.path[current] = 0
	}
	return result
}

func createGraph(vertexCount int, from, to []int) *Graph {
	graph := &Graph{vertexCount: vertexCount, edges: make([][]Edge, vertexCount)}
	for i := 0; i < len(from); i++ {
		graph.edges[from[i]] = append(graph.edges[from[i]], Edge{to: to[i]})
		graph.edges[to[i]] = append(graph.edges[to[i]], Edge{to: from[i]})
	}
	return graph
}

func readIntArray(in *InputReader, size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = in.readInt()
	}
	return array
}

func readIntArrays(in *InputReader, arrays ...[]int) {
	for i := 0; i < len(arrays[0]); i++ {
		for j := range arrays {
			arrays[j][i] = in.readInt()
		}
	}
}

func decreaseByOne(arrays ...[]int) {
	for _, array := range arrays {
		for i := range array {
			array[i]--
		}
	}
}

func createOrder(array []int) []int {
	order := make([]int, len(array))
	for i := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return array[order[i]] < array[order[j]]
	})
	return order
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{scanner: bufio.NewScanner(r)}
}

func (in *InputReader) readInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) printLine(i int) {
	fmt.Fprintln(out.writer, i)
}

func (out *OutputWriter) close() {
	out.writer.Flush()
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := &TaskD{}
	solver.solve(1, in, out)
	out.close()
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
