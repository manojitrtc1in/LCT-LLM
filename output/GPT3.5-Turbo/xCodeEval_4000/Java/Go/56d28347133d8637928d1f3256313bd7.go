package main

import (
	"container/heap"
	"fmt"
)

type Graph struct {
	vertexCount    int
	edgeCount      int
	firstOutbound  []int
	firstInbound   []int
	edges          []Edge
	nextInbound    []int
	nextOutbound   []int
	from           []int
	to             []int
	weight         []int64
	capacity       []int64
	reverseEdge    []int
	flags          []int
}

type Edge struct {
	id int
}

type MinCostFlow struct {
	graph          *Graph
	source         int
	destination    int
	phi            []int64
	dijkstraResult []int64
	lastEdge       []int
	heap           *Heap
	vertexCount    int
	visited        []int
	visitIndex     int
}

type Heap struct {
	list  IntList
	shift int
	index []int
}

type Pair struct {
	first  int64
	second int64
}

type IntList []int

func (list IntList) Get(index int) int {
	return list[index]
}

func (list IntList) Size() int {
	return len(list)
}

func (list *IntList) Add(value int) {
	*list = append(*list, value)
}

func (list *IntList) AddAll(values IntList) {
	*list = append(*list, values...)
}

type IntIterator struct {
	list  IntList
	index int
}

func (iterator *IntIterator) Value() int {
	return iterator.list.Get(iterator.index)
}

func (iterator *IntIterator) Advance() {
	iterator.index++
}

func (iterator *IntIterator) IsValid() bool {
	return iterator.index < iterator.list.Size()
}

func NewGraph(vertexCount int) *Graph {
	graph := &Graph{
		vertexCount:   vertexCount,
		firstOutbound: make([]int, vertexCount),
		firstInbound:  make([]int, vertexCount),
	}
	for i := 0; i < vertexCount; i++ {
		graph.firstOutbound[i] = -1
		graph.firstInbound[i] = -1
	}
	return graph
}

func (graph *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	graph.ensureEdgeCapacity(graph.edgeCount + 1)
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

func (graph *Graph) AddFlowWeightedEdge(from, to int, weight, capacity int64) int {
	if capacity == 0 {
		return graph.AddEdge(from, to, weight, 0, -1)
	} else {
		lastEdgeCount := graph.edgeCount
		graph.AddEdge(to, from, -weight, 0, lastEdgeCount+graph.entriesPerEdge())
		return graph.AddEdge(from, to, weight, capacity, lastEdgeCount)
	}
}

func (graph *Graph) entriesPerEdge() int {
	return 1
}

func (graph *Graph) VertexCount() int {
	return graph.vertexCount
}

func (graph *Graph) FirstOutbound(vertex int) int {
	id := graph.firstOutbound[vertex]
	for id != -1 && graph.isRemoved(id) {
		id = graph.nextOutbound[id]
	}
	return id
}

func (graph *Graph) NextOutbound(id int) int {
	id = graph.nextOutbound[id]
	for id != -1 && graph.isRemoved(id) {
		id = graph.nextOutbound[id]
	}
	return id
}

func (graph *Graph) Source(id int) int {
	return graph.from[id]
}

func (graph *Graph) Destination(id int) int {
	return graph.to[id]
}

func (graph *Graph) Weight(id int) int64 {
	if graph.weight == nil {
		return 0
	}
	return graph.weight[id]
}

func (graph *Graph) Capacity(id int) int64 {
	if graph.capacity == nil {
		return 0
	}
	return graph.capacity[id]
}

func (graph *Graph) Flow(id int) int64 {
	if graph.reverseEdge == nil {
		return 0
	}
	return graph.capacity[graph.reverseEdge[id]]
}

func (graph *Graph) PushFlow(id int, flow int64) {
	if flow == 0 {
		return
	}
	if flow > 0 {
		if graph.Capacity(id) < flow {
			panic("Not enough capacity")
		}
	} else {
		if graph.Flow(id) < -flow {
			panic("Not enough capacity")
		}
	}
	graph.capacity[id] -= flow
	graph.capacity[graph.reverseEdge[id]] += flow
}

func (graph *Graph) Flag(id, bit int) bool {
	return (graph.flags[id]>>bit)&1 != 0
}

func (graph *Graph) IsRemoved(id int) bool {
	return graph.Flag(id, 0)
}

func (graph *Graph) EnsureEdgeCapacity(size int) {
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

func (mcf *MinCostFlow) MinCostMaxFlow() Pair {
	return mcf.MinCostMaxFlow(1<<63 - 1)
}

func (mcf *MinCostFlow) MinCostMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		if mcf.graph.IsSparse() {
			mcf.dijkstraAlgorithm()
		} else {
			mcf.dijkstraAlgorithmFull()
		}
		if mcf.lastEdge[mcf.destination] == -1 {
			return Pair{cost, flow}
		}
		for i := 0; i < len(mcf.dijkstraResult); i++ {
			if mcf.dijkstraResult[i] != 1<<63-1 {
				mcf.phi[i] += mcf.dijkstraResult[i]
			}
		}
		vertex := mcf.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			currentFlow = min(currentFlow, mcf.graph.Capacity(edgeID))
			currentCost += mcf.graph.Weight(edgeID)
			vertex = mcf.graph.Source(edgeID)
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = mcf.destination
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			mcf.graph.PushFlow(edgeID, currentFlow)
			vertex = mcf.graph.Source(edgeID)
		}
	}
	return Pair{cost, flow}
}

func (mcf *MinCostFlow) dijkstraAlgorithm() {
	for i := 0; i < len(mcf.dijkstraResult); i++ {
		mcf.dijkstraResult[i] = 1 << 63 - 1
	}
	for i := 0; i < len(mcf.lastEdge); i++ {
		mcf.lastEdge[i] = -1
	}
	mcf.dijkstraResult[mcf.source] = 0
	mcf.heap.Clear()
	mcf.heap.Add(mcf.source)
	for !mcf.heap.IsEmpty() {
		current := mcf.heap.Poll()
		edgeID := mcf.graph.FirstOutbound(current)
		for edgeID != -1 {
			if mcf.graph.Capacity(edgeID) != 0 {
				next := mcf.graph.Destination(edgeID)
				total := mcf.graph.Weight(edgeID) - mcf.phi[next] + mcf.phi[current] + mcf.dijkstraResult[current]
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
			edgeID = mcf.graph.NextOutbound(edgeID)
		}
	}
}

func (mcf *MinCostFlow) dijkstraAlgorithmFull() {
	mcf.visitIndex++
	for i := 0; i < len(mcf.dijkstraResult); i++ {
		mcf.dijkstraResult[i] = 1 << 63 - 1
	}
	mcf.lastEdge[mcf.destination] = -1
	mcf.dijkstraResult[mcf.source] = 0
	for i := 0; i < mcf.vertexCount; i++ {
		index := -1
		length := int64(1 << 63 - 1)
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
		edgeID := mcf.graph.FirstOutbound(index)
		for edgeID != -1 {
			if mcf.graph.Capacity(edgeID) != 0 {
				next := mcf.graph.Destination(edgeID)
				if mcf.visited[next] != mcf.visitIndex {
					total := mcf.graph.Weight(edgeID) - mcf.phi[next] + mcf.phi[index] + length
					if mcf.dijkstraResult[next] > total {
						mcf.dijkstraResult[next] = total
						mcf.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = mcf.graph.NextOutbound(edgeID)
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&a[i][j])
		}
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
					graph.AddFlowWeightedEdge(id, id1, wt, 1)
				}
				graph.AddFlowWeightedEdge(source, id, 0, 1)
			} else {
				graph.AddFlowWeightedEdge(id, sink, 0, 1)
			}
		}
	}

	mcf := &MinCostFlow{
		graph:       graph,
		source:      source,
		destination: sink,
		phi:         make([]int64, graph.VertexCount()),
	}

	ans := mcf.MinCostMaxFlow()
	fmt.Println(ans.first)
}
