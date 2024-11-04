package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
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

func (in *InputReader) readString() string {
	str, _ := in.reader.ReadString('\n')
	return str[:len(str)-1]
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Print(args ...interface{}) {
	fmt.Fprint(out.writer, args...)
}

func (out *OutputWriter) PrintLine(args ...interface{}) {
	out.Print(args...)
	out.Print("\n")
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

type Pair struct {
	first  int
	second int
}

func NewPair(first, second int) Pair {
	return Pair{first: first, second: second}
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOut    []int
	firstIn     []int
	from        []int
	to          []int
	weight      []int64
	capacity    []int64
	reverseEdge []int
	flags       []int
}

func NewGraph(vertexCount, edgeCapacity int) *Graph {
	graph := &Graph{
		vertexCount: vertexCount,
		firstOut:    make([]int, vertexCount),
		from:        make([]int, edgeCapacity),
		to:          make([]int, edgeCapacity),
		weight:      make([]int64, edgeCapacity),
		capacity:    make([]int64, edgeCapacity),
		reverseEdge: make([]int, edgeCapacity),
		flags:       make([]int, edgeCapacity),
	}
	for i := 0; i < vertexCount; i++ {
		graph.firstOut[i] = -1
	}
	return graph
}

func (graph *Graph) AddEdge(from, to int, weight, capacity int64, reverseEdge int) {
	graph.from[graph.edgeCount] = from
	graph.to[graph.edgeCount] = to
	graph.weight[graph.edgeCount] = weight
	graph.capacity[graph.edgeCount] = capacity
	graph.reverseEdge[graph.edgeCount] = reverseEdge
	if graph.firstOut[from] != -1 {
		graph.flags[graph.edgeCount] = graph.firstOut[from]
	} else {
		graph.flags[graph.edgeCount] = -1
	}
	graph.firstOut[from] = graph.edgeCount
	graph.edgeCount++
}

type TaskC1 struct {
}

func (task *TaskC1) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	rowCount := in.ReadInt()
	columnCount := in.ReadInt()
	typ := make([][]int, rowCount)
	for i := 0; i < rowCount; i++ {
		typ[i] = make([]int, columnCount)
		for j := 0; j < columnCount; j++ {
			typ[i][j] = in.ReadInt()
		}
	}
	graph := NewGraph(rowCount*columnCount+2, rowCount*columnCount*5)
	source := graph.vertexCount - 2
	sink := graph.vertexCount - 1
	for i := 0; i < rowCount; i++ {
		for j := 0; j < columnCount; j++ {
			index := i*columnCount + j
			if (i+j)&1 == 0 {
				graph.AddEdge(source, index, 1, 0, -1)
				for k := 0; k < 4; k++ {
					row := i + dx4[k]
					column := j + dy4[k]
					if isValidCell(row, column, rowCount, columnCount) {
						graph.AddEdge(index, row*columnCount+column, 1, int64(typ[i][j] == typ[row][column]), 1)
					}
				}
			} else {
				graph.AddEdge(index, sink, 1, 0, -1)
			}
		}
	}
	out.PrintLine(MinCostFlow(graph, source, sink, false).MinCostMaxFlow().first)
}

var dx4 = []int{1, 0, -1, 0}
var dy4 = []int{0, -1, 0, 1}

func isValidCell(row, column, rowCount, columnCount int) bool {
	return row >= 0 && row < rowCount && column >= 0 && column < columnCount
}

type MinCostFlow struct {
	graph        *Graph
	source       int
	destination  int
	phi          []int64
	dijkstraRes  []int64
	lastEdge     []int
	heap         *Heap
	vertexCount  int
	visited      []int
	visitIndex   int
}

func NewMinCostFlow(graph *Graph, source, destination int, hasNegativeEdges bool) *MinCostFlow {
	mcf := &MinCostFlow{
		graph:        graph,
		source:       source,
		destination:  destination,
		vertexCount:  graph.vertexCount,
		phi:          make([]int64, graph.vertexCount),
		dijkstraRes:  make([]int64, graph.vertexCount),
		lastEdge:     make([]int, graph.vertexCount),
		visited:      make([]int, graph.vertexCount),
		visitIndex:   0,
	}
	if hasNegativeEdges {
		mcf.fordBellman()
	}
	if graph.isSparse() {
		mcf.heap = NewHeap(graph.vertexCount, func(a, b int) int {
			if mcf.dijkstraRes[a] < mcf.dijkstraRes[b] {
				return -1
			} else if mcf.dijkstraRes[a] > mcf.dijkstraRes[b] {
				return 1
			} else {
				return 0
			}
		})
		mcf.visited = nil
	} else {
		mcf.heap = nil
	}
	return mcf
}

func (mcf *MinCostFlow) MinCostMaxFlow() Pair {
	return mcf.MinCostMaxFlowWithMaxFlow(math.MaxInt64)
}

func (mcf *MinCostFlow) MinCostMaxFlowWithMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		if mcf.graph.isSparse() {
			mcf.dijkstraAlgorithm()
		} else {
			mcf.dijkstraAlgorithmFull()
		}
		if mcf.lastEdge[mcf.destination] == -1 {
			return NewPair(cost, flow)
		}
		for i := 0; i < len(mcf.dijkstraRes); i++ {
			if mcf.dijkstraRes[i] != math.MaxInt64 {
				mcf.phi[i] += mcf.dijkstraRes[i]
			}
		}
		vertex := mcf.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			currentFlow = min(currentFlow, mcf.graph.capacity[edgeID])
			currentCost += mcf.graph.weight[edgeID]
			vertex = mcf.graph.from[edgeID]
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = mcf.destination
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			mcf.graph.pushFlow(edgeID, currentFlow)
			vertex = mcf.graph.from[edgeID]
		}
	}
	return NewPair(cost, flow)
}

func (mcf *MinCostFlow) fordBellman() {
	for i := 0; i < len(mcf.phi); i++ {
		mcf.phi[i] = math.MaxInt64
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
			edgeID = mcf.graph.flags[edgeID]
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (mcf *MinCostFlow) dijkstraAlgorithm() {
	for i := 0; i < len(mcf.dijkstraRes); i++ {
		mcf.dijkstraRes[i] = math.MaxInt64
	}
	for i := 0; i < len(mcf.lastEdge); i++ {
		mcf.lastEdge[i] = -1
	}
	mcf.dijkstraRes[mcf.source] = 0
	mcf.heap.Clear()
	mcf.heap.Add(mcf.source)
	for !mcf.heap.IsEmpty() {
		current := mcf.heap.Poll()
		edgeID := mcf.graph.firstOut[current]
		for edgeID != -1 {
			if mcf.graph.capacity[edgeID] != 0 {
				next := mcf.graph.to[edgeID]
				total := mcf.graph.weight[edgeID] - mcf.phi[next] + mcf.phi[current] + mcf.dijkstraRes[current]
				if mcf.dijkstraRes[next] > total {
					mcf.dijkstraRes[next] = total
					if mcf.heap.GetIndex(next) == -1 {
						mcf.heap.Add(next)
					} else {
						mcf.heap.ShiftUp(mcf.heap.GetIndex(next))
					}
					mcf.lastEdge[next] = edgeID
				}
			}
			edgeID = mcf.graph.flags[edgeID]
		}
	}
}

func (mcf *MinCostFlow) dijkstraAlgorithmFull() {
	mcf.visitIndex++
	for i := 0; i < len(mcf.dijkstraRes); i++ {
		mcf.dijkstraRes[i] = math.MaxInt64
	}
	mcf.lastEdge[mcf.destination] = -1
	mcf.dijkstraRes[mcf.source] = 0
	for i := 0; i < mcf.vertexCount; i++ {
		index := -1
		length := int64(math.MaxInt64)
		for j := 0; j < mcf.vertexCount; j++ {
			if mcf.visited[j] != mcf.visitIndex && mcf.dijkstraRes[j] < length {
				length = mcf.dijkstraRes[j]
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
					if mcf.dijkstraRes[next] > total {
						mcf.dijkstraRes[next] = total
						mcf.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = mcf.graph.flags[edgeID]
		}
	}
}

type Heap struct {
	list  []int
	shift int
	index []int
	less  func(a, b int) int
}

func NewHeap(size int, less func(a, b int) int) *Heap {
	return &Heap{
		list:  make([]int, 0, size),
		index: make([]int, size),
		less:  less,
	}
}

func (h *Heap) Add(value int) {
	h.index[value] = len(h.list)
	h.list = append(h.list, value)
	h.shiftUp(len(h.list) - 1)
}

func (h *Heap) IsEmpty() bool {
	return h.shift == len(h.list)
}

func (h *Heap) Poll() int {
	result := h.list[h.shift]
	h.index[result] = -1
	h.shift++
	return result
}

func (h *Heap) GetIndex(value int) int {
	return h.index[value]
}

func (h *Heap) ShiftUp(index int) {
	for index != 0 {
		nextIndex := (index - 1) >> 1
		if h.less(h.list[nextIndex], h.list[index]) <= 0 {
			break
		}
		h.swap(index, nextIndex)
		index = nextIndex
	}
}

func (h *Heap) Clear() {
	h.list = h.list[:0]
	h.shift = 0
	for i := 0; i < len(h.index); i++ {
		h.index[i] = -1
	}
}

func (h *Heap) swap(index1, index2 int) {
	h.list[index1], h.list[index2] = h.list[index2], h.list[index1]
	h.index[h.list[index1]] = index1
	h.index[h.list[index2]] = index2
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	defer output.Flush()

	var task TaskC1
	task.Solve(1, input, output)
}
