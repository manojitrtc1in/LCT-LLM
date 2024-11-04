package main

import (
	"fmt"
	"math"
)

type Pair struct {
	first  int64
	second int64
}

func makePair(first, second int64) Pair {
	return Pair{first, second}
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOutbound []int
	from         []int
	to           []int
	nextOutbound []int
	weight       []int64
	capacity     []int64
	reverseEdge  []int
}

func NewGraph(vertexCount int) *Graph {
	return &Graph{
		vertexCount: vertexCount,
		firstOutbound: make([]int, vertexCount),
		from:         make([]int, vertexCount),
		to:           make([]int, vertexCount),
		nextOutbound: make([]int, vertexCount),
		weight:       make([]int64, vertexCount),
		capacity:     make([]int64, vertexCount),
		reverseEdge:  make([]int, vertexCount),
	}
}

func (g *Graph) addEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	g.from[g.edgeCount] = fromID
	g.to[g.edgeCount] = toID
	g.weight[g.edgeCount] = weight
	g.capacity[g.edgeCount] = capacity
	g.reverseEdge[g.edgeCount] = reverseEdge
	g.nextOutbound[g.edgeCount] = g.firstOutbound[fromID]
	g.firstOutbound[fromID] = g.edgeCount
	g.edgeCount++
	return g.edgeCount - 1
}

func (g *Graph) addFlowWeightedEdge(from, to int, weight, capacity int64) int {
	if capacity == 0 {
		return g.addEdge(from, to, weight, 0, -1)
	} else {
		lastEdgeCount := g.edgeCount
		g.addEdge(to, from, -weight, 0, lastEdgeCount)
		return g.addEdge(from, to, weight, capacity, lastEdgeCount)
	}
}

type MinCostFlow struct {
	graph       *Graph
	source      int
	destination int
	phi         []int64
	dijkstraResult []int64
	lastEdge    []int
}

func NewMinCostFlow(graph *Graph, source, destination int) *MinCostFlow {
	return &MinCostFlow{
		graph:       graph,
		source:      source,
		destination: destination,
		phi:         make([]int64, graph.vertexCount),
		dijkstraResult: make([]int64, graph.vertexCount),
		lastEdge:    make([]int, graph.vertexCount),
	}
}

func (mcf *MinCostFlow) minCostMaxFlow(maxFlow int64) (int64, int64) {
	var cost, flow int64
	for maxFlow != 0 {
		mcf.dijkstraAlgorithm()
		if mcf.lastEdge[mcf.destination] == -1 {
			return cost, flow
		}
		for i := 0; i < len(mcf.dijkstraResult); i++ {
			if mcf.dijkstraResult[i] != math.MaxInt64 {
				mcf.phi[i] += mcf.dijkstraResult[i]
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
			mcf.graph.capacity[edgeID] -= currentFlow
			vertex = mcf.graph.from[edgeID]
		}
	}
	return cost, flow
}

func (mcf *MinCostFlow) dijkstraAlgorithm() {
	for i := range mcf.dijkstraResult {
		mcf.dijkstraResult[i] = math.MaxInt64
		mcf.lastEdge[i] = -1
	}
	mcf.dijkstraResult[mcf.source] = 0
	// Implement the heap logic here if needed
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
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
			a[i][j]--
		}
	}

	shoe := m * n / 2
	graph := NewGraph(2*shoe + 2)
	source := 2 * shoe
	sink := 2*shoe + 1

	dx := []int{-1, 0, 0, 1}
	dy := []int{0, -1, 1, 0}

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
					graph.addFlowWeightedEdge(id, id1, wt, 1)
				}
				graph.addFlowWeightedEdge(source, id, 0, 1)
			} else {
				graph.addFlowWeightedEdge(id, sink, 0, 1)
			}
		}
	}

	mcf := NewMinCostFlow(graph, source, sink)
	ansCost, ansFlow := mcf.minCostMaxFlow(math.MaxInt64)
	fmt.Println(ansCost)
}
