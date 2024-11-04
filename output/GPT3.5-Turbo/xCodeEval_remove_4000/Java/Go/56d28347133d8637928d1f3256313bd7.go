package main

import (
	"bufio"
	"fmt"
	"os"
)

type Graph struct {
	vertexCount   int
	edgeCount     int
	firstOutbound []int
	firstInbound  []int
	edges         []Edge
	nextInbound   []int
	nextOutbound  []int
	from          []int
	to            []int
	weight        []int64
	capacity      []int64
	reverseEdge   []int
	flags         []int
}

type Edge struct {
	id int
}

func NewGraph(vertexCount int) *Graph {
	graph := &Graph{
		vertexCount:   vertexCount,
		firstOutbound: make([]int, vertexCount),
		edges:         make([]Edge, 0),
		nextOutbound:  make([]int, 0),
		from:          make([]int, 0),
		to:            make([]int, 0),
		weight:        make([]int64, 0),
		capacity:      make([]int64, 0),
		reverseEdge:   make([]int, 0),
		flags:         make([]int, 0),
	}
	for i := 0; i < vertexCount; i++ {
		graph.firstOutbound[i] = -1
	}
	return graph
}

func (graph *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	graph.ensureCapacity(graph.edgeCount + 1)
	if graph.firstOutbound[fromID] != -1 {
		graph.nextOutbound[graph.edgeCount] = graph.firstOutbound[fromID]
	} else {
		graph.nextOutbound[graph.edgeCount] = -1
	}
	graph.firstOutbound[fromID] = graph.edgeCount
	if graph.firstInbound != nil {
		if graph.firstInbound[toID] != -1 {
			graph.nextInbound[graph.edgeCount] = graph.firstInbound[toID]
		} else {
			graph.nextInbound[graph.edgeCount] = -1
		}
		graph.firstInbound[toID] = graph.edgeCount
	}
	graph.from[graph.edgeCount] = fromID
	graph.to[graph.edgeCount] = toID
	if capacity != 0 {
		if graph.capacity == nil {
			graph.capacity = make([]int64, len(graph.from))
		}
		graph.capacity[graph.edgeCount] = capacity
	}
	if weight != 0 {
		if graph.weight == nil {
			graph.weight = make([]int64, len(graph.from))
		}
		graph.weight[graph.edgeCount] = weight
	}
	if reverseEdge != -1 {
		if graph.reverseEdge == nil {
			graph.reverseEdge = make([]int, len(graph.from))
			for i := 0; i < graph.edgeCount; i++ {
				graph.reverseEdge[i] = -1
			}
		}
		graph.reverseEdge[graph.edgeCount] = reverseEdge
	}
	if graph.edges != nil {
		graph.edges[graph.edgeCount] = Edge{id: graph.edgeCount}
	}
	return graph.edgeCount
}

func (graph *Graph) ensureCapacity(size int) {
	if len(graph.from) < size {
		newSize := max(size, 2*len(graph.from))
		if graph.edges != nil {
			newEdges := make([]Edge, newSize)
			copy(newEdges, graph.edges)
			graph.edges = newEdges
		}
		newFrom := make([]int, newSize)
		copy(newFrom, graph.from)
		graph.from = newFrom
		newTo := make([]int, newSize)
		copy(newTo, graph.to)
		graph.to = newTo
		newNextOutbound := make([]int, newSize)
		copy(newNextOutbound, graph.nextOutbound)
		graph.nextOutbound = newNextOutbound
		if graph.nextInbound != nil {
			newNextInbound := make([]int, newSize)
			copy(newNextInbound, graph.nextInbound)
			graph.nextInbound = newNextInbound
		}
		if graph.weight != nil {
			newWeight := make([]int64, newSize)
			copy(newWeight, graph.weight)
			graph.weight = newWeight
		}
		if graph.capacity != nil {
			newCapacity := make([]int64, newSize)
			copy(newCapacity, graph.capacity)
			graph.capacity = newCapacity
		}
		if graph.reverseEdge != nil {
			newReverseEdge := make([]int, newSize)
			copy(newReverseEdge, graph.reverseEdge)
			graph.reverseEdge = newReverseEdge
		}
		newFlags := make([]int, newSize)
		copy(newFlags, graph.flags)
		graph.flags = newFlags
	}
}

type Pair struct {
	first  int64
	second int64
}

func MakePair(first, second int64) Pair {
	return Pair{first: first, second: second}
}

type Heap struct {
	list  *IntList
	shift int
	index []int
}

func NewHeap(vertexCount int) *Heap {
	return &Heap{
		list:  NewIntList(vertexCount),
		index: make([]int, vertexCount),
	}
}

func (heap *Heap) Add(source int) {
	heap.index[source] = 0
	heap.list.Add(source)
}

func (heap *Heap) IsEmpty() bool {
	return heap.shift == heap.list.Size()
}

func (heap *Heap) Poll() int {
	result := heap.list.Get(heap.shift)
	heap.index[result] = -1
	heap.shift++
	return result
}

func (heap *Heap) GetIndex(next int) int {
	return heap.index[next]
}

func (heap *Heap) ShiftUp(index int) {

}

func (heap *Heap) Clear() {
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

func NewIntList() *IntList {
	return &IntList{
		array: make([]int, 0),
	}
}

func NewIntListWithCapacity(capacity int) *IntList {
	return &IntList{
		array: make([]int, 0, capacity),
	}
}

func NewIntListFromList(list []int) *IntList {
	return &IntList{
		array: list,
		size:  len(list),
	}
}

func (list *IntList) Get(index int) int {
	if index >= list.size {
		panic("Index out of range")
	}
	return list.array[index]
}

func (list *IntList) Size() int {
	return list.size
}

func (list *IntList) Add(value int) {
	list.ensureCapacity(list.size + 1)
	list.array[list.size] = value
	list.size++
}

func (list *IntList) ensureCapacity(newCapacity int) {
	if newCapacity > len(list.array) {
		newArray := make([]int, max(newCapacity, len(list.array)<<1))
		copy(newArray, list.array)
		list.array = newArray
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscanf(reader, "%d", &a[i][j])
			a[i][j]--
		}
		fmt.Fscanf(reader, "\n")
	}

	shoe := m * n / 2

	dx := []int{-1, 0, 0, 1}
	dy := []int{0, -1, 1, 0}

	graph := NewGraph(2*shoe + 2)
	source := 2*shoe
	sink := 2*shoe + 1

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			id := i*m + j
			if (i+j)%2 == 0 {
				for z := 0; z < 4; z++ {
					i1 := i + dx[z]
					j1 := j + dy[z]
					if i1 < 0 || i1 >= n || j1 < 0 || j1 >= m {
						continue
					}
					id1 := i1*m + j1
					wt := int64(0)
					if a[i][j] != a[i1][j1] {
						wt = 1
					}
					graph.AddEdge(id, id1, wt, 1, -1)
				}
				graph.AddEdge(source, id, 0, 1, -1)
			} else {
				graph.AddEdge(id, sink, 0, 1, -1)
			}
		}
	}

	mcf := NewMCF(graph, source, sink, false)
	ans := mcf.GetResult()
	fmt.Println(ans.first)
}

type MCF struct {
	graph        *Graph
	source       int
	destination  int
	phi          []int64
	potential    []int64
	lastEdge     []int
	heap         *Heap
	vertexCount  int
	visited      []int
	visitIndex   int
}

func NewMCF(graph *Graph, source, destination int, id11 bool) *MCF {
	mcf := &MCF{
		graph:        graph,
		source:       source,
		destination:  destination,
		vertexCount:  graph.vertexCount,
		phi:          make([]int64, graph.vertexCount),
		lastEdge:     make([]int, graph.vertexCount),
		heap:         NewHeap(graph.vertexCount),
		visited:      make([]int, graph.vertexCount),
	}
	if id11 {
		mcf.init()
	}
	return mcf
}

func (mcf *MCF) init() {
	for i := 0; i < mcf.vertexCount; i++ {
		mcf.phi[i] = 1<<63 - 1
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
		edgeID := mcf.graph.firstOutbound[vertex]
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
			edgeID = mcf.graph.nextOutbound[edgeID]
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (mcf *MCF) GetResult() Pair {
	return mcf.GetResultWithMaxFlow(1<<63 - 1)
}

func (mcf *MCF) GetResultWithMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		mcf.potential = make([]int64, mcf.vertexCount)
		mcf.lastEdge = make([]int, mcf.vertexCount)
		mcf.init()
		if mcf.lastEdge[mcf.destination] == -1 {
			return Pair{first: cost, second: flow}
		}
		for i := 0; i < len(mcf.phi); i++ {
			if mcf.phi[i] != 1<<63-1 {
				mcf.phi[i] += mcf.potential[i]
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
			mcf.graph.PushFlow(edgeID, currentFlow)
			vertex = mcf.graph.from[edgeID]
		}
	}
	return Pair{first: cost, second: flow}
}

func (mcf *MCF) id12() {
	for i := 0; i < len(mcf.phi); i++ {
		mcf.phi[i] = 1<<63 - 1
	}
	mcf.phi[mcf.source] = 0
	mcf.heap.Clear()
	mcf.heap.Add(mcf.source)
	for !mcf.heap.IsEmpty() {
		current := mcf.heap.Poll()
		edgeID := mcf.graph.firstOutbound[current]
		for edgeID != -1 {
			if mcf.graph.capacity[edgeID] != 0 {
				next := mcf.graph.to[edgeID]
				total := mcf.graph.weight[edgeID] - mcf.phi[next] + mcf.phi[current] + mcf.potential[current]
				if mcf.phi[next] > total {
					mcf.phi[next] = total
					if mcf.heap.GetIndex(next) == -1 {
						mcf.heap.Add(next)
					} else {
						mcf.heap.ShiftUp(mcf.heap.GetIndex(next))
					}
					mcf.lastEdge[next] = edgeID
				}
			}
			edgeID = mcf.graph.nextOutbound[edgeID]
		}
	}
}

func (mcf *MCF) id9() {
	mcf.visitIndex++
	for i := 0; i < len(mcf.phi); i++ {
		mcf.potential[i] = 1<<63 - 1
	}
	mcf.lastEdge[mcf.destination] = -1
	mcf.potential[mcf.source] = 0
	for i := 0; i < mcf.vertexCount; i++ {
		index := -1
		length := int64(1<<63 - 1)
		for j := 0; j < mcf.vertexCount; j++ {
			if mcf.visited[j] != mcf.visitIndex && mcf.potential[j] < length {
				length = mcf.potential[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		mcf.visited[index] = mcf.visitIndex
		edgeID := mcf.graph.firstOutbound[index]
		for edgeID != -1 {
			if mcf.graph.capacity[edgeID] != 0 {
				next := mcf.graph.to[edgeID]
				if mcf.visited[next] != mcf.visitIndex {
					total := mcf.graph.weight[edgeID] - mcf.phi[next] + mcf.phi[index] + length
					if mcf.potential[next] > total {
						mcf.potential[next] = total
						mcf.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = mcf.graph.nextOutbound[edgeID]
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
