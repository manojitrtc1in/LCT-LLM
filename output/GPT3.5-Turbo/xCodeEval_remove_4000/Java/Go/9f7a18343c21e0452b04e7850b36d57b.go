package main

import (
	"fmt"
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
	weight        []int
	capacity      []int
	reverseEdge   []int
	flags         []int
}

type Edge struct {
	id int
}

type MCF struct {
	graph       *Graph
	source      int
	destination int
	phi         []int
	potential   []int
	lastEdge    []int
	heap        *Heap
	vertexCount int
	visited     []int
	visitIndex  int
}

type Heap struct {
	list  *IntList
	shift int
	index []int
}

type IntList struct {
	array []int
	size  int
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

func (graph *Graph) addEdge(fromID, toID, weight, capacity, reverseEdge int) int {
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
			graph.capacity = make([]int, len(graph.from))
		}
		graph.capacity[graph.edgeCount] = capacity
	}
	if weight != 0 {
		if graph.weight == nil {
			graph.weight = make([]int, len(graph.from))
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

func (graph *Graph) id3(from, to, weight, capacity int) int {
	if capacity == 0 {
		return graph.addEdge(from, to, weight, 0, -1)
	} else {
		id4 := graph.edgeCount
		graph.addEdge(to, from, -weight, 0, id4+id7())
		return graph.addEdge(from, to, weight, capacity, id4)
	}
}

func (graph *Graph) id7() int {
	return 1
}

func (graph *Graph) id1(from, to, capacity int) int {
	return graph.id3(from, to, 0, capacity)
}

func (graph *Graph) vertexCount() int {
	return graph.vertexCount
}

func (graph *Graph) firstOutbound(vertex int) int {
	id := graph.firstOutbound[vertex]
	for id != -1 && graph.isRemoved(id) {
		id = graph.nextOutbound[id]
	}
	return id
}

func (graph *Graph) nextOutbound(id int) int {
	id = graph.nextOutbound[id]
	for id != -1 && graph.isRemoved(id) {
		id = graph.nextOutbound[id]
	}
	return id
}

func (graph *Graph) source(id int) int {
	return graph.from[id]
}

func (graph *Graph) destination(id int) int {
	return graph.to[id]
}

func (graph *Graph) weight(id int) int {
	if graph.weight == nil {
		return 0
	}
	return graph.weight[id]
}

func (graph *Graph) capacity(id int) int {
	if graph.capacity == nil {
		return 0
	}
	return graph.capacity[id]
}

func (graph *Graph) flow(id int) int {
	if graph.reverseEdge == nil {
		return 0
	}
	return graph.capacity[graph.reverseEdge[id]]
}

func (graph *Graph) pushFlow(id, flow int) {
	if flow == 0 {
		return
	}
	if flow > 0 {
		if graph.capacity(id) < flow {
			panic("Not enough capacity")
		}
	} else {
		if graph.flow(id) < -flow {
			panic("Not enough capacity")
		}
	}
	graph.capacity[id] -= flow
	graph.capacity[graph.reverseEdge[id]] += flow
}

func (graph *Graph) flag(id, bit int) bool {
	return (graph.flags[id]>>bit)&1 != 0
}

func (graph *Graph) isRemoved(id int) bool {
	return graph.flag(id, id14)
}

func (graph *Graph) id8(size int) {
	if len(graph.from) < size {
		newSize := max(size, 2*len(graph.from))
		if graph.edges != nil {
			graph.edges = resize(graph.edges, newSize)
		}
		graph.from = resize(graph.from, newSize)
		graph.to = resize(graph.to, newSize)
		graph.nextOutbound = resize(graph.nextOutbound, newSize)
		if graph.nextInbound != nil {
			graph.nextInbound = resize(graph.nextInbound, newSize)
		}
		if graph.weight != nil {
			graph.weight = resize(graph.weight, newSize)
		}
		if graph.capacity != nil {
			graph.capacity = resize(graph.capacity, newSize)
		}
		if graph.reverseEdge != nil {
			graph.reverseEdge = resize(graph.reverseEdge, newSize)
		}
		graph.flags = resize(graph.flags, newSize)
	}
}

func resize(array []int, size int) []int {
	newArray := make([]int, size)
	copy(newArray, array)
	return newArray
}

type Pair struct {
	first  int
	second int
}

func makePair(first, second int) Pair {
	return Pair{first: first, second: second}
}

type id5 struct {
	graph       *Graph
	source      int
	destination int
	phi         []int
	id13        []int
	lastEdge    []int
	heap        *Heap
	vertexCount int
	visited     []int
	visitIndex  int
}

func NewMCF(graph *Graph, source, destination int, id11 bool) *id5 {
	mcf := &id5{
		graph:       graph,
		source:      source,
		destination: destination,
		vertexCount: graph.vertexCount(),
	}
	if id11 {
		mcf.id6()
	}
	mcf.id13 = make([]int, mcf.vertexCount)
	mcf.lastEdge = make([]int, mcf.vertexCount)
	if graph.isSparse() {
		mcf.heap = &Heap{
			list:  &IntList{},
			index: make([]int, mcf.vertexCount),
		}
		mcf.visited = nil
	} else {
		mcf.heap = nil
		mcf.visited = make([]int, mcf.vertexCount)
	}
	return mcf
}

func (mcf *id5) id6() {
	mcf.phi = make([]int, mcf.vertexCount)
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
		edgeID := mcf.graph.firstOutbound(vertex)
		for edgeID != -1 {
			total := mcf.phi[vertex] + mcf.graph.weight(edgeID)
			destination := mcf.graph.destination(edgeID)
			if mcf.graph.capacity(edgeID) != 0 && mcf.phi[destination] > total {
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
			edgeID = mcf.graph.nextOutbound(edgeID)
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (mcf *id5) id12() {
	for i := 0; i < len(mcf.id13); i++ {
		mcf.id13[i] = 1<<63 - 1
	}
	for i := 0; i < len(mcf.lastEdge); i++ {
		mcf.lastEdge[i] = -1
	}
	mcf.id13[mcf.source] = 0
	mcf.heap.clear()
	mcf.heap.add(mcf.source)
	for !mcf.heap.isEmpty() {
		current := mcf.heap.poll()
		edgeID := mcf.graph.firstOutbound(current)
		for edgeID != -1 {
			if mcf.graph.capacity(edgeID) != 0 {
				next := mcf.graph.destination(edgeID)
				total := mcf.graph.weight(edgeID) - mcf.phi[next] + mcf.phi[current] + mcf.id13[current]
				if mcf.id13[next] > total {
					mcf.id13[next] = total
					if mcf.heap.getIndex(next) == -1 {
						mcf.heap.add(next)
					} else {
						mcf.heap.shiftUp(mcf.heap.getIndex(next))
					}
					mcf.lastEdge[next] = edgeID
				}
			}
			edgeID = mcf.graph.nextOutbound(edgeID)
		}
	}
}

func (mcf *id5) id9() {
	mcf.visitIndex++
	for i := 0; i < len(mcf.id13); i++ {
		mcf.id13[i] = 1<<63 - 1
	}
	mcf.lastEdge[mcf.destination] = -1
	mcf.id13[mcf.source] = 0
	for i := 0; i < mcf.vertexCount; i++ {
		index := -1
		length := 1<<63 - 1
		for j := 0; j < mcf.vertexCount; j++ {
			if mcf.visited[j] != mcf.visitIndex && mcf.id13[j] < length {
				length = mcf.id13[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		mcf.visited[index] = mcf.visitIndex
		edgeID := mcf.graph.firstOutbound(index)
		for edgeID != -1 {
			if mcf.graph.capacity(edgeID) != 0 {
				next := mcf.graph.destination(edgeID)
				if mcf.visited[next] != mcf.visitIndex {
					total := mcf.graph.weight(edgeID) - mcf.phi[next] + mcf.phi[index] + length
					if mcf.id13[next] > total {
						mcf.id13[next] = total
						mcf.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = mcf.graph.nextOutbound(edgeID)
		}
	}
}

func (mcf *id5) id2() Pair {
	return mcf.id2(1<<63 - 1)
}

func (mcf *id5) id2(maxFlow int) Pair {
	cost := 0
	flow := 0
	for maxFlow != 0 {
		if mcf.graph.isSparse() {
			mcf.id12()
		} else {
			mcf.id9()
		}
		if mcf.lastEdge[mcf.destination] == -1 {
			return Pair{first: cost, second: flow}
		}
		for i := 0; i < len(mcf.id13); i++ {
			if mcf.id13[i] != 1<<63-1 {
				mcf.phi[i] += mcf.id13[i]
			}
		}
		vertex := mcf.destination
		currentFlow := maxFlow
		currentCost := 0
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			currentFlow = min(currentFlow, mcf.graph.capacity(edgeID))
			currentCost += mcf.graph.weight(edgeID)
			vertex = mcf.graph.source(edgeID)
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = mcf.destination
		for vertex != mcf.source {
			edgeID := mcf.lastEdge[vertex]
			mcf.graph.pushFlow(edgeID, currentFlow)
			vertex = mcf.graph.source(edgeID)
		}
	}
	return Pair{first: cost, second: flow}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

const id14 = 0

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&a[i][j])
			a[i][j]--
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
					wt := 0
					if a[i][j] != a[i1][j1] {
						wt = 1
					}
					graph.id3(id, id1, wt, 1)
				}
				graph.id3(source, id, 0, 1)
			} else {
				graph.id3(id, sink, 0, 1)
			}
		}
	}

	mcf := NewMCF(graph, source, sink, false)
	ans := mcf.id2()
	fmt.Println(ans.first)
}
