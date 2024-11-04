package main

import (
	"container/heap"
	"fmt"
	"math"
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

type MinCostFlow struct {
	graph        *Graph
	source       int
	destination  int
	phi          []int64
	dijkstraResult []int64
	lastEdge     []int
	heap         *Heap
	vertexCount  int
	visited      []int
	visitIndex   int
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
	list  *IntList
	index int
}

func (iterator *IntIterator) Value() int {
	return (*iterator.list)[iterator.index]
}

func (iterator *IntIterator) Advance() {
	iterator.index++
}

func (iterator *IntIterator) IsValid() bool {
	return iterator.index < len(*iterator.list)
}

func (list IntList) Iterator() *IntIterator {
	iterator := &IntIterator{list: &list}
	return iterator
}

func (list IntList) HashCode() int {
	hashCode := 1
	for _, value := range list {
		hashCode = 31*hashCode + value
	}
	return hashCode
}

func (list IntList) Equals(obj interface{}) bool {
	if otherList, ok := obj.(IntList); ok {
		if len(list) != len(otherList) {
			return false
		}
		for i, value := range list {
			if value != otherList[i] {
				return false
			}
		}
		return true
	}
	return false
}

func (list IntList) CompareTo(otherList IntList) int {
	iterator1 := list.Iterator()
	iterator2 := otherList.Iterator()
	for {
		if iterator1.IsValid() {
			if iterator2.IsValid() {
				if iterator1.Value() != iterator2.Value() {
					if iterator1.Value() < iterator2.Value() {
						return -1
					} else {
						return 1
					}
				}
			} else {
				return 1
			}
		} else {
			if iterator2.IsValid() {
				return -1
			} else {
				return 0
			}
		}
		iterator1.Advance()
		iterator2.Advance()
	}
}

func NewGraph(vertexCount int) *Graph {
	return NewGraphWithCapacity(vertexCount, vertexCount)
}

func NewGraphWithCapacity(vertexCount, edgeCapacity int) *Graph {
	graph := &Graph{
		vertexCount:   vertexCount,
		firstOutbound: make([]int, vertexCount),
		from:          make([]int, edgeCapacity),
		to:            make([]int, edgeCapacity),
		nextOutbound:  make([]int, edgeCapacity),
		flags:         make([]int, edgeCapacity),
	}
	for i := 0; i < vertexCount; i++ {
		graph.firstOutbound[i] = -1
	}
	return graph
}

func (graph *Graph) AddEdge(from, to int, weight, capacity int64, reverseEdge int) int {
	graph.ensureEdgeCapacity(graph.edgeCount + 1)
	if graph.firstOutbound[from] != -1 {
		graph.nextOutbound[graph.edgeCount] = graph.firstOutbound[from]
	} else {
		graph.nextOutbound[graph.edgeCount] = -1
	}
	graph.firstOutbound[from] = graph.edgeCount
	if graph.firstInbound != nil {
		if graph.firstInbound[to] != -1 {
			graph.nextInbound[graph.edgeCount] = graph.firstInbound[to]
		} else {
			graph.nextInbound[graph.edgeCount] = -1
		}
		graph.firstInbound[to] = graph.edgeCount
	}
	graph.from[graph.edgeCount] = from
	graph.to[graph.edgeCount] = to
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
	graph.edgeCount++
	return graph.edgeCount - 1
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

func (graph *Graph) AddFlowEdge(from, to int, capacity int64) int {
	return graph.AddFlowWeightedEdge(from, to, 0, capacity)
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
		newSize := int(math.Max(float64(size), float64(len(graph.from)<<1)))
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

type IntComparator interface {
}

func NewMinCostFlow(graph *Graph, source, destination int, hasNegativeEdges bool) *MinCostFlow {
	flow := &MinCostFlow{
		graph:        graph,
		source:       source,
		destination:  destination,
		vertexCount:  graph.VertexCount(),
		phi:          make([]int64, graph.VertexCount()),
		dijkstraResult: make([]int64, graph.VertexCount()),
		lastEdge:     make([]int, graph.VertexCount()),
	}
	if hasNegativeEdges {
		flow.fordBellman()
	}
	if graph.IsSparse() {
		flow.heap = NewHeap(flow.vertexCount, func(first, second int) int {
			return IntegerUtilsLongCompare(flow.dijkstraResult[first], flow.dijkstraResult[second])
		}, flow.vertexCount)
		flow.visited = nil
	} else {
		flow.heap = nil
		flow.visited = make([]int, flow.vertexCount)
	}
	return flow
}

func (flow *MinCostFlow) minCostMaxFlow() Pair {
	return flow.minCostMaxFlow(math.MaxInt64)
}

func (flow *MinCostFlow) minCostMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flowValue := int64(0)
	for maxFlow != 0 {
		if flow.graph.IsSparse() {
			flow.dijkstraAlgorithm()
		} else {
			flow.dijkstraAlgorithmFull()
		}
		if flow.lastEdge[flow.destination] == -1 {
			return Pair{cost, flowValue}
		}
		for i := 0; i < len(flow.dijkstraResult); i++ {
			if flow.dijkstraResult[i] != math.MaxInt64 {
				flow.phi[i] += flow.dijkstraResult[i]
			}
		}
		vertex := flow.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != flow.source {
			edgeID := flow.lastEdge[vertex]
			currentFlow = int64(math.Min(float64(currentFlow), float64(flow.graph.Capacity(edgeID))))
			currentCost += flow.graph.Weight(edgeID)
			vertex = flow.graph.Source(edgeID)
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flowValue += currentFlow
		vertex = flow.destination
		for vertex != flow.source {
			edgeID := flow.lastEdge[vertex]
			flow.graph.PushFlow(edgeID, currentFlow)
			vertex = flow.graph.Source(edgeID)
		}
	}
	return Pair{cost, flowValue}
}

func (flow *MinCostFlow) dijkstraAlgorithm() {
	for i := 0; i < len(flow.dijkstraResult); i++ {
		flow.dijkstraResult[i] = math.MaxInt64
	}
	for i := 0; i < len(flow.lastEdge); i++ {
		flow.lastEdge[i] = -1
	}
	flow.dijkstraResult[flow.source] = 0
	flow.heap.Clear()
	flow.heap.Add(flow.source)
	for !flow.heap.IsEmpty() {
		current := flow.heap.Poll()
		edgeID := flow.graph.FirstOutbound(current)
		for edgeID != -1 {
			if flow.graph.Capacity(edgeID) != 0 {
				next := flow.graph.Destination(edgeID)
				total := flow.graph.Weight(edgeID) - flow.phi[next] + flow.phi[current] + flow.dijkstraResult[current]
				if flow.dijkstraResult[next] > total {
					flow.dijkstraResult[next] = total
					if flow.heap.GetIndex(next) == -1 {
						flow.heap.Add(next)
					} else {
						flow.heap.ShiftUp(flow.heap.GetIndex(next))
					}
					flow.lastEdge[next] = edgeID
				}
			}
			edgeID = flow.graph.NextOutbound(edgeID)
		}
	}
}

func (flow *MinCostFlow) dijkstraAlgorithmFull() {
	flow.visitIndex++
	for i := 0; i < len(flow.dijkstraResult); i++ {
		flow.dijkstraResult[i] = math.MaxInt64
	}
	flow.lastEdge[flow.destination] = -1
	flow.dijkstraResult[flow.source] = 0
	for i := 0; i < flow.vertexCount; i++ {
		index := -1
		length := int64(math.MaxInt64)
		for j := 0; j < flow.vertexCount; j++ {
			if flow.visited[j] != flow.visitIndex && flow.dijkstraResult[j] < length {
				length = flow.dijkstraResult[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		flow.visited[index] = flow.visitIndex
		edgeID := flow.graph.FirstOutbound(index)
		for edgeID != -1 {
			if flow.graph.Capacity(edgeID) != 0 {
				next := flow.graph.Destination(edgeID)
				if flow.visited[next] != flow.visitIndex {
					total := flow.graph.Weight(edgeID) - flow.phi[next] + flow.phi[index] + length
					if flow.dijkstraResult[next] > total {
						flow.dijkstraResult[next] = total
						flow.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = flow.graph.NextOutbound(edgeID)
		}
	}
}

func (flow *MinCostFlow) fordBellman() {
	for i := 0; i < len(flow.phi); i++ {
		flow.phi[i] = math.MaxInt64
	}
	flow.phi[flow.source] = 0
	inQueue := make([]bool, flow.vertexCount)
	queue := make([]int, flow.vertexCount+1)
	queue[0] = flow.source
	inQueue[flow.source] = true
	stepCount := 0
	head := 0
	end := 1
	maxSteps := 2 * flow.vertexCount * flow.vertexCount
	for head != end {
		vertex := queue[head]
		head++
		if head == len(queue) {
			head = 0
		}
		inQueue[vertex] = false
		edgeID := flow.graph.FirstOutbound(vertex)
		for edgeID != -1 {
			total := flow.phi[vertex] + flow.graph.Weight(edgeID)
			destination := flow.graph.Destination(edgeID)
			if flow.graph.Capacity(edgeID) != 0 && flow.phi[destination] > total {
				flow.phi[destination] = total
				if !inQueue[destination] {
					queue[end] = destination
					end++
					if end == len(queue) {
						end = 0
					}
					inQueue[destination] = true
				}
			}
			edgeID = flow.graph.NextOutbound(edgeID)
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func NewHeap(vertexCount int, intComparator func(first, second int) int, vertexCount1 int) *Heap {
	heap := &Heap{
		list:  make(IntList, 0, vertexCount),
		index: make([]int, vertexCount1),
	}
	for i := 0; i < vertexCount1; i++ {
		heap.index[i] = -1
	}
	return heap
}

func (heap *Heap) Add(source int) {
	heap.index[source] = 0
	heap.list.Add(source)
}

func (heap *Heap) IsEmpty() bool {
	return heap.shift == len(heap.list)
}

func (heap *Heap) Poll() int {
	result := heap.list[heap.shift]
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
	heap.list = make(IntList, 0)
	heap.shift = 0
	for i := 0; i < len(heap.index); i++ {
		heap.index[i] = -1
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

	mcf := NewMinCostFlow(graph, source, sink, false)
	ans := mcf.minCostMaxFlow()
	fmt.Println(ans.first)
}
