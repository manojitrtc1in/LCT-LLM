package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	num, _ := strconv.Atoi(in.readString())
	return num
}

func (in *InputReader) ReadString() string {
	str, _ := in.reader.ReadString('\n')
	return str[:len(str)-1]
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

type Pair struct {
	first  int
	second int
}

func MakePair(first, second int) Pair {
	return Pair{first: first, second: second}
}

type TaskF struct {
	n        int
	s        []byte
	ugliness []int
}

func (task *TaskF) solve(testNumber int, in *InputReader, out *OutputWriter) {
	task.n = in.ReadInt()
	task.s = []byte(in.ReadString())
	task.ugliness = make([]int, task.n)
	for i := 0; i < task.n; i++ {
		task.ugliness[i] = -in.ReadInt()
	}

	graph := NewGraph(1 + 26 + task.n/2 + 1)
	for c := 'a'; c <= 'z'; c++ {
		for i := 0; i < task.n/2; i++ {
			cost := 0
			if c == rune(task.s[i]) {
				cost = min(cost, task.ugliness[i])
			}
			if c == rune(task.s[task.n-1-i]) {
				cost = min(cost, task.ugliness[task.n-1-i])
			}
			graph.AddFlowWeightedEdge(1+(c-'a'), 1+26+i, cost, 1)
		}
	}

	occurs := make([]int, 128)
	for i := 0; i < task.n; i++ {
		occurs[task.s[i]]++
	}
	for c := 'a'; c <= 'z'; c++ {
		graph.AddFlowWeightedEdge(0, 1+(c-'a'), 0, occurs[c])
	}

	for i := 0; i < task.n/2; i++ {
		graph.AddFlowWeightedEdge(1+26+i, 1+26+task.n/2, 0, 2)
	}

	flow := MinCostMaxFlow(graph, 0, 1+26+task.n/2, true, task.n)
	out.Println(-flow.first)
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOut    []int
	from        []int
	to          []int
	nextOut     []int
	flags       []int
	weight      []int64
	capacity    []int64
	reverseEdge []int
}

func NewGraph(vertexCount int) *Graph {
	return &Graph{
		vertexCount: vertexCount,
		firstOut:    make([]int, vertexCount),
		from:        make([]int, 0),
		to:          make([]int, 0),
		nextOut:     make([]int, 0),
		flags:       make([]int, 0),
		weight:      make([]int64, 0),
		capacity:    make([]int64, 0),
		reverseEdge: make([]int, 0),
	}
}

func (g *Graph) AddEdge(from, to int, weight int64, capacity int64, reverseEdge int) {
	g.ensureEdgeCapacity(g.edgeCount + 1)
	if g.firstOut[from] != -1 {
		g.nextOut[g.edgeCount] = g.firstOut[from]
	} else {
		g.nextOut[g.edgeCount] = -1
	}
	g.firstOut[from] = g.edgeCount
	g.from = append(g.from, from)
	g.to = append(g.to, to)
	g.flags = append(g.flags, 0)
	g.weight = append(g.weight, weight)
	g.capacity = append(g.capacity, capacity)
	g.reverseEdge = append(g.reverseEdge, reverseEdge)
	g.edgeCount++
}

func (g *Graph) AddFlowWeightedEdge(from, to int, weight int64, capacity int64) {
	if capacity == 0 {
		g.AddEdge(from, to, weight, 0, -1)
	} else {
		lastEdgeCount := g.edgeCount
		g.AddEdge(to, from, -weight, 0, lastEdgeCount+1)
		g.AddEdge(from, to, weight, capacity, lastEdgeCount)
	}
}

func (g *Graph) ensureEdgeCapacity(size int) {
	if len(g.from) < size {
		newSize := max(size, 2*len(g.from))
		g.from = resize(g.from, newSize)
		g.to = resize(g.to, newSize)
		g.nextOut = resize(g.nextOut, newSize)
		g.flags = resize(g.flags, newSize)
		g.weight = resize(g.weight, newSize)
		g.capacity = resize(g.capacity, newSize)
		g.reverseEdge = resize(g.reverseEdge, newSize)
	}
}

func resize(array []int, size int) []int {
	newArray := make([]int, size)
	copy(newArray, array)
	return newArray
}

func resize64(array []int64, size int) []int64 {
	newArray := make([]int64, size)
	copy(newArray, array)
	return newArray
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func MinCostMaxFlow(graph *Graph, source, destination int, hasNegativeEdges bool, maxFlow int) Pair {
	minCostFlow := NewMinCostFlow(graph, source, destination, hasNegativeEdges)
	return minCostFlow.MinCostMaxFlow(maxFlow)
}

type MinCostFlow struct {
	graph           *Graph
	source          int
	destination     int
	phi             []int64
	dijkstraResult  []int64
	lastEdge        []int
	heap            *Heap
	vertexCount     int
	visited         []int
	visitIndex      int
}

func NewMinCostFlow(graph *Graph, source, destination int, hasNegativeEdges bool) *MinCostFlow {
	minCostFlow := &MinCostFlow{
		graph:        graph,
		source:       source,
		destination:  destination,
		vertexCount:  graph.vertexCount,
		phi:          make([]int64, graph.vertexCount),
		dijkstraResult: make([]int64, graph.vertexCount),
		lastEdge:     make([]int, graph.vertexCount),
		visitIndex:   0,
	}
	if hasNegativeEdges {
		minCostFlow.fordBellman()
	}
	if graph.isSparse() {
		minCostFlow.heap = NewHeap(graph.vertexCount, func(a, b int) int {
			return IntegerUtilsLongCompare(minCostFlow.dijkstraResult[a], minCostFlow.dijkstraResult[b])
		})
		minCostFlow.visited = nil
	} else {
		minCostFlow.heap = nil
		minCostFlow.visited = make([]int, graph.vertexCount)
	}
	return minCostFlow
}

func (mcf *MinCostFlow) fordBellman() {
	for i := 0; i < mcf.vertexCount; i++ {
		mcf.phi[i] = 1 << 60
	}
	mcf.phi[mcf.source] = 0
	inQueue := make([]bool, mcf.vertexCount)
	queue := make([]int, mcf.vertexCount+1)
	queue[0] = mcf.source
	inQueue[mcf.source] = true
	stepCount := 0
	head := 0
	end := 1
	maxSteps := 2 * mcf.vertexCount * mcf.vertexCount
	for head != end {
		vertex := queue[head]
		head++
		if head == len(queue) {
			head = 0
		}
		inQueue[vertex] = false
		edgeID := mcf.graph.firstOut[vertex]
		for edgeID != -1 {
			total := mcf.phi[vertex] + mcf.graph.weight[edgeID]
			destination := mcf.graph.to[edgeID]
			if mcf.graph.capacity[edgeID] != 0 && mcf.phi[destination] > total {
				mcf.phi[destination] = total
				if !inQueue[destination] {
					queue[end] = destination
					end++
					if end == len(queue) {
						end = 0
					}
					inQueue[destination] = true
				}
			}
			edgeID = mcf.graph.nextOut[edgeID]
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (mcf *MinCostFlow) MinCostMaxFlow(maxFlow int) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		if mcf.graph.isSparse() {
			mcf.dijkstraAlgorithm()
		} else {
			mcf.dijkstraAlgorithmFull()
		}
		if mcf.lastEdge[mcf.destination] == -1 {
			return MakePair(int(cost), int(flow))
		}
		for i := 0; i < len(mcf.dijkstraResult); i++ {
			if mcf.dijkstraResult[i] != 1<<60 {
				mcf.phi[i] += mcf.dijkstraResult[i]
			}
		}
		vertex := mcf.destination
		currentFlow := int64(maxFlow)
		currentCost := int64(0)
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			currentFlow = min(currentFlow, mcf.graph.capacity[edgeID])
			currentCost += mcf.graph.weight[edgeID]
			vertex = mcf.graph.from[edgeID]
		}
		maxFlow -= int(currentFlow)
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = mcf.destination
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			mcf.graph.pushFlow(edgeID, currentFlow)
			vertex = mcf.graph.from[edgeID]
		}
	}
	return MakePair(int(cost), int(flow))
}

func (mcf *MinCostFlow) dijkstraAlgorithm() {
	for i := 0; i < mcf.vertexCount; i++ {
		mcf.dijkstraResult[i] = 1 << 60
	}
	for i := 0; i < mcf.vertexCount; i++ {
		mcf.lastEdge[i] = -1
	}
	mcf.dijkstraResult[mcf.source] = 0
	mcf.heap.Add(mcf.source)
	for !mcf.heap.IsEmpty() {
		current := mcf.heap.Poll()
		edgeID := mcf.graph.firstOut[current]
		for edgeID != -1 {
			if mcf.graph.capacity[edgeID] != 0 {
				next := mcf.graph.to[edgeID]
				total := mcf.graph.weight[edgeID] - mcf.phi[next] + mcf.phi[current] + mcf.dijkstraResult[current]
				if mcf.dijkstraResult[next] > total {
					mcf.dijkstraResult[next] = total
					if mcf.heap.GetIndex(next) == -1 {
						mcf.heap.Add(next)
					} else {
						mcf.heap.ShiftUp(mcf.heap.GetIndex(next))
					}
					mcf.lastEdge[next] = edgeID
				}
			}
			edgeID = mcf.graph.nextOut[edgeID]
		}
	}
}

func (mcf *MinCostFlow) dijkstraAlgorithmFull() {
	mcf.visitIndex++
	for i := 0; i < mcf.vertexCount; i++ {
		mcf.dijkstraResult[i] = 1 << 60
		mcf.lastEdge[i] = -1
	}
	mcf.dijkstraResult[mcf.source] = 0
	for i := 0; i < mcf.vertexCount; i++ {
		index := -1
		length := int64(1 << 60)
		for j := 0; j < mcf.vertexCount; j++ {
			if mcf.visited[j] != mcf.visitIndex && mcf.dijkstraResult[j] < length {
				length = mcf.dijkstraResult[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		mcf.visited[index] = mcf.visitIndex
		edgeID := mcf.graph.firstOut[index]
		for edgeID != -1 {
			if mcf.graph.capacity[edgeID] != 0 {
				next := mcf.graph.to[edgeID]
				if mcf.visited[next] != mcf.visitIndex {
					total := mcf.graph.weight[edgeID] - mcf.phi[next] + mcf.phi[index] + length
					if mcf.dijkstraResult[next] > total {
						mcf.dijkstraResult[next] = total
						mcf.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = mcf.graph.nextOut[edgeID]
		}
	}
}

type Heap struct {
	comparator func(a, b int) int
	size       int
	elements   []int
	at         []int
}

func NewHeap(maxElement int, comparator func(a, b int) int) *Heap {
	return &Heap{
		comparator: comparator,
		size:       0,
		elements:   make([]int, maxElement),
		at:         make([]int, maxElement),
	}
}

func (h *Heap) IsEmpty() bool {
	return h.size == 0
}

func (h *Heap) Add(element int) {
	h.ensureCapacity(h.size + 1)
	h.elements[h.size] = element
	h.at[element] = h.size
	h.shiftUp(h.size)
	h.size++
}

func (h *Heap) shiftUp(index int) {
	value := h.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := h.elements[parent]
		if h.comparator(parentValue, value) <= 0 {
			break
		}
		h.elements[index] = parentValue
		h.at[parentValue] = index
		index = parent
	}
	h.elements[index] = value
	h.at[value] = index
}

func (h *Heap) Poll() int {
	if h.IsEmpty() {
		panic("Heap is empty")
	}
	result := h.elements[0]
	h.at[result] = -1
	if h.size == 1 {
		h.size = 0
		return result
	}
	h.elements[0] = h.elements[h.size-1]
	h.at[h.elements[0]] = 0
	h.size--
	h.shiftDown(0)
	return result
}

func (h *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= h.size {
			return
		}
		if child+1 < h.size && h.comparator(h.elements[child], h.elements[child+1]) > 0 {
			child++
		}
		if h.comparator(h.elements[index], h.elements[child]) <= 0 {
			return
		}
		h.swap(index, child)
		index = child
	}
}

func (h *Heap) GetIndex(element int) int {
	return h.at[element]
}

func (h *Heap) swap(first, second int) {
	temp := h.elements[first]
	h.elements[first] = h.elements[second]
	h.elements[second] = temp
	h.at[h.elements[first]] = first
	h.at[h.elements[second]] = second
}

func (h *Heap) ensureCapacity(size int) {
	if len(h.elements) < size {
		newSize := max(size, 2*len(h.elements))
		newElements := make([]int, newSize)
		copy(newElements, h.elements)
		h.elements = newElements
	}
}

func IntegerUtilsLongCompare(a, b int64) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	task := &TaskF{}
	task.solve(1, input, output)
	output.Flush()
}
