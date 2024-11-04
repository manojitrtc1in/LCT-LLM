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

type Edge struct {
	id int
}

type IntList []int

func (list IntList) Len() int {
	return len(list)
}

func (list IntList) Less(i, j int) bool {
	return list[i] < list[j]
}

func (list IntList) Swap(i, j int) {
	list[i], list[j] = list[j], list[i]
}

func (list *IntList) Push(x interface{}) {
	*list = append(*list, x.(int))
}

func (list *IntList) Pop() interface{} {
	old := *list
	n := len(old)
	x := old[n-1]
	*list = old[0 : n-1]
	return x
}

func (graph *Graph) AddEdge(fromID, toID int) {
	graph.ensureEdgeCapacity(graph.edgeCount + 1)
	if graph.firstOut[fromID] != -1 {
		graph.nextOut[graph.edgeCount] = graph.firstOut[fromID]
	} else {
		graph.nextOut[graph.edgeCount] = -1
	}
	graph.firstOut[fromID] = graph.edgeCount
	graph.from[graph.edgeCount] = fromID
	graph.to[graph.edgeCount] = toID
	graph.flags[graph.edgeCount] = 0
	graph.edgeCount++
}

func (graph *Graph) ensureEdgeCapacity(size int) {
	if len(graph.from) < size {
		newSize := max(size, 2*len(graph.from))
		newFrom := make([]int, newSize)
		newTo := make([]int, newSize)
		newNextOut := make([]int, newSize)
		newFlags := make([]int, newSize)
		copy(newFrom, graph.from)
		copy(newTo, graph.to)
		copy(newNextOut, graph.nextOut)
		copy(newFlags, graph.flags)
		graph.from = newFrom
		graph.to = newTo
		graph.nextOut = newNextOut
		graph.flags = newFlags
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(testNumber int, in *InputReader, out io.Writer) {
	n := in.readInt()
	k := in.readInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.readInt()
	}
	u := make([]int, n-1)
	v := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		u[i] = in.readInt()
		v[i] = in.readInt()
	}
	graph := createGraph(n, u, v)
	order := make(IntList, n)
	for i := 0; i < n; i++ {
		order[i] = i
	}
	sort.Sort(sort.Reverse(order))
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
		result := dfs(0, -1, graph, weight, path)
		if result >= k {
			right = middle
		} else {
			left = middle + 1
		}
	}
	fmt.Fprintln(out, a[order[left-1]])
}

func dfs(current, last int, graph *Graph, weight, path []int) int {
	result := 0
	max := 0
	second := 0
	for i := graph.firstOut[current]; i != -1; i = graph.nextOut[i] {
		next := graph.to[i]
		if next == last {
			continue
		}
		result = max(result, dfs(next, current, graph, weight, path))
		if path[next] > max {
			second = max
			max = path[next]
		} else {
			second = max(second, path[next])
		}
	}
	if weight[current] != 0 {
		path[current] = weight[current] + max
		result = max(result, max+second+weight[current])
	} else {
		path[current] = 0
	}
	return result
}

func createGraph(vertexCount int, from, to []int) *Graph {
	graph := &Graph{vertexCount: vertexCount, firstOut: make([]int, vertexCount)}
	for i := 0; i < vertexCount; i++ {
		graph.firstOut[i] = -1
	}
	graph.from = make([]int, 2*len(from))
	graph.to = make([]int, 2*len(from))
	graph.nextOut = make([]int, 2*len(from))
	graph.flags = make([]int, 2*len(from))
	for i := 0; i < len(from); i++ {
		graph.AddEdge(from[i], to[i])
		graph.AddEdge(to[i], from[i])
	}
	return graph
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(reader io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(reader)}
}

func (in *InputReader) readInt() int {
	var sign, res int
	var err error
	for {
		sign = 1
		res = 0
		var flag bool
		var c byte
		for {
			c, err = in.reader.ReadByte()
			if err != nil {
				return res * sign
			}
			if c >= '0' && c <= '9' {
				res = int(c - '0')
				break
			}
			if c == '-' {
				sign = -1
				break
			}
			flag = true
		}
		if flag {
			break
		}
		for {
			c, err = in.reader.ReadByte()
			if err != nil {
				return res * sign
			}
			if c < '0' || c > '9' {
				return res * sign
			}
			res = res*10 + int(c-'0')
		}
		break
	}
	for {
		c, err := in.reader.ReadByte()
		if err != nil || c == '\n' || c == ' ' {
			return res * sign
		}
	}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(1, in, out)
}
