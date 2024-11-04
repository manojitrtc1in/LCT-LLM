package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOut    []int
	from        []int
	to          []int
	weight      []int64
	capacity    []int64
	reverseEdge []int
	flags       []int
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("InputMismatchException")
		}
		res *= 10
		res += int(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) read() int {
	c, err := in.reader.ReadByte()
	if err != nil {
		panic(err)
	}
	return int(c)
}

func isWhitespace(c int) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Print(args ...interface{}) {
	for _, arg := range args {
		_, err := fmt.Fprint(out.writer, arg)
		if err != nil {
			panic(err)
		}
	}
}

func (out *OutputWriter) Println(args ...interface{}) {
	out.Print(args...)
	out.Print("\n")
}

func (out *OutputWriter) Close() {
	err := out.writer.Flush()
	if err != nil {
		panic(err)
	}
}

type Pair struct {
	first  int64
	second int64
}

func MakePair(first, second int64) Pair {
	return Pair{first: first, second: second}
}

type ID2Solver struct {
	graph       Graph
	source      int
	sink        int
	rowCount    int
	columnCount int
}

func (solver *ID2Solver) solve(in *InputReader, out *OutputWriter) {
	solver.rowCount = in.ReadInt()
	solver.columnCount = in.ReadInt()
	solver.graph = NewGraph(solver.rowCount*solver.columnCount + 2)
	solver.source = solver.graph.vertexCount - 2
	solver.sink = solver.graph.vertexCount - 1
	for i := 0; i < solver.rowCount; i++ {
		for j := 0; j < solver.columnCount; j++ {
			index := i*solver.columnCount + j
			if (i+j)&1 == 0 {
				solver.graph.addEdge(solver.source, index, 1, 0, 1)
				for k := 0; k < 4; k++ {
					row := i + dx4[k]
					column := j + dy4[k]
					if id19(row, column, solver.rowCount, solver.columnCount) {
						solver.graph.addEdge(index, row*solver.columnCount+column, 1, 1, 1)
					}
				}
			} else {
				solver.graph.addEdge(index, solver.sink, 1, 0, 1)
			}
		}
	}
	result := solver.maxFlowMinCost()
	out.Println(result.first)
}

func (solver *ID2Solver) maxFlowMinCost() Pair {
	phi := make([]int64, solver.graph.vertexCount)
	id8 := make([]int64, solver.graph.vertexCount)
	lastEdge := make([]int, solver.graph.vertexCount)
	visited := make([]int, solver.graph.vertexCount)
	visitIndex := 0

	for {
		if solver.graph.isSparse() {
			solver.id18(phi, id8, lastEdge, visited, visitIndex)
		} else {
			solver.id14(phi, id8, lastEdge, visited, visitIndex)
		}
		if lastEdge[solver.sink] == -1 {
			return MakePair(0, 0)
		}
		for i := 0; i < len(id8); i++ {
			if id8[i] != math.MaxInt64 {
				phi[i] += id8[i]
			}
		}
		vertex := solver.sink
		currentFlow := int64(math.MaxInt64)
		currentCost := int64(0)
		for vertex != solver.source {
			edgeID := lastEdge[vertex]
			currentFlow = min(currentFlow, solver.graph.capacity[edgeID])
			currentCost += solver.graph.weight[edgeID]
			vertex = solver.graph.from[edgeID]
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = solver.sink
		for vertex != solver.source {
			edgeID := lastEdge[vertex]
			solver.graph.pushFlow(edgeID, currentFlow)
			vertex = solver.graph.from[edgeID]
		}
	}
}

func (solver *ID2Solver) id18(phi, id8 []int64, lastEdge, visited []int, visitIndex int) {
	for i := 0; i < len(id8); i++ {
		id8[i] = math.MaxInt64
	}
	for i := 0; i < len(lastEdge); i++ {
		lastEdge[i] = -1
	}
	id8[solver.source] = 0
	heap := NewHeap(solver.graph.vertexCount, func(a, b int) int {
		return int(id8[a] - id8[b])
	})
	heap.add(solver.source)
	for !heap.isEmpty() {
		current := heap.poll()
		edgeID := solver.graph.firstOut[current]
		for edgeID != -1 {
			if solver.graph.capacity[edgeID] != 0 {
				next := solver.graph.to[edgeID]
				total := solver.graph.weight[edgeID] - phi[next] + phi[current] + id8[current]
				if id8[next] > total {
					id8[next] = total
					if heap.getIndex(next) == -1 {
						heap.add(next)
					} else {
						heap.shiftUp(heap.getIndex(next))
					}
					lastEdge[next] = edgeID
				}
			}
			edgeID = solver.graph.nextOut[edgeID]
		}
	}
}

func (solver *ID2Solver) id14(phi, id8 []int64, lastEdge, visited []int, visitIndex int) {
	visitIndex++
	for i := 0; i < len(id8); i++ {
		id8[i] = math.MaxInt64
	}
	lastEdge[solver.sink] = -1
	id8[solver.source] = 0
	for i := 0; i < len(id8); i++ {
		index := -1
		length := int64(math.MaxInt64)
		for j := 0; j < len(id8); j++ {
			if visited[j] != visitIndex && id8[j] < length {
				length = id8[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		visited[index] = visitIndex
		edgeID := solver.graph.firstOut[index]
		for edgeID != -1 {
			if solver.graph.capacity[edgeID] != 0 {
				next := solver.graph.to[edgeID]
				if visited[next] != visitIndex {
					total := solver.graph.weight[edgeID] - phi[next] + phi[index] + length
					if id8[next] > total {
						id8[next] = total
						lastEdge[next] = edgeID
					}
				}
			}
			edgeID = solver.graph.nextOut[edgeID]
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func id19(row, column, rowCount, columnCount int) bool {
	return row >= 0 && row < rowCount && column >= 0 && column < columnCount
}

func NewGraph(vertexCount int) Graph {
	return Graph{
		vertexCount: vertexCount,
		firstOut:    make([]int, vertexCount),
		from:        make([]int, 0),
		to:          make([]int, 0),
		weight:      make([]int64, 0),
		capacity:    make([]int64, 0),
		reverseEdge: make([]int, 0),
		flags:       make([]int, 0),
	}
}

func (graph *Graph) addEdge(from, to int, weight, capacity int64, reverseEdge int) {
	graph.ensureCapacity(graph.edgeCount + 1)
	if graph.firstOut[from] != -1 {
		graph.nextOut[graph.edgeCount] = graph.firstOut[from]
	} else {
		graph.nextOut[graph.edgeCount] = -1
	}
	graph.firstOut[from] = graph.edgeCount
	graph.from[graph.edgeCount] = from
	graph.to[graph.edgeCount] = to
	if capacity != 0 {
		graph.capacity[graph.edgeCount] = capacity
	}
	if weight != 0 {
		graph.weight[graph.edgeCount] = weight
	}
	if reverseEdge != -1 {
		graph.reverseEdge[graph.edgeCount] = reverseEdge
	}
	graph.edgeCount++
}

func (graph *Graph) ensureCapacity(size int) {
	if len(graph.from) < size {
		newSize := int(math.Max(float64(size), float64(2*len(graph.from))))
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

func (graph *Graph) isSparse() bool {
	return graph.vertexCount == 0 || graph.edgeCount*20/graph.vertexCount <= graph.vertexCount
}

type Heap struct {
	list  IntList
	shift int
	index []int
}

func NewHeap(vertexCount int, intComparator func(a, b int) int) *Heap {
	return &Heap{
		list:  NewIntList(vertexCount),
		index: make([]int, vertexCount),
	}
}

func (heap *Heap) add(source int) {
	heap.index[source] = 0
	heap.list.add(source)
}

func (heap *Heap) isEmpty() bool {
	return heap.shift == heap.list.size()
}

func (heap *Heap) poll() int {
	result := heap.list.get(heap.shift)
	heap.index[result] = -1
	heap.shift++
	return result
}

func (heap *Heap) getIndex(next int) int {
	return heap.index[next]
}

func (heap *Heap) shiftUp(index int) {
}

func (heap *Heap) clear() {
	heap.list = NewIntList()
	heap.shift = 0
	for i := 0; i < len(heap.index); i++ {
		heap.index[i] = -1
	}
}

type IntList struct {
	array []int
	size  int
}

func NewIntList(capacity int) *IntList {
	return &IntList{
		array: make([]int, capacity),
	}
}

func (list *IntList) get(index int) int {
	if index >= list.size {
		panic("Index out of range")
	}
	return list.array[index]
}

func (list *IntList) size() int {
	return list.size
}

func (list *IntList) add(value int) {
	list.ensureCapacity(list.size + 1)
	list.array[list.size] = value
	list.size++
}

func (list *IntList) ensureCapacity(newCapacity int) {
	if newCapacity > len(list.array) {
		newArray := make([]int, int(math.Max(float64(newCapacity), float64(len(list.array)<<1))))
		copy(newArray, list.array)
		list.array = newArray
	}
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)

	var solver ID2Solver
	solver.solve(input, output)

	output.Close()
}
