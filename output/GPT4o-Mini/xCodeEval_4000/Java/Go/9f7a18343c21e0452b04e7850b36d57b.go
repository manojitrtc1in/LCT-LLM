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
	return Pair{first: first, second: second}
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
	// Implementation of adding edges
	return 0 // Placeholder
}

func (g *Graph) addFlowWeightedEdge(from, to int, weight, capacity int64) int {
	// Implementation of adding flow weighted edges
	return 0 // Placeholder
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

func (m *MinCostFlow) minCostMaxFlow(maxFlow int64) (int64, int64) {
	// Implementation of min cost max flow
	return 0, 0 // Placeholder
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
	dx := []int{-1, 0, 0, 1}
	dy := []int{0, -1, 1, 0}

	graph := NewGraph(2*shoe + 2)
	source := 2 * shoe
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
					graph.addFlowWeightedEdge(id, id1, wt, 1)
				}
				graph.addFlowWeightedEdge(source, id, 0, 1)
			} else {
				graph.addFlowWeightedEdge(id, sink, 0, 1)
			}
		}
	}

	mcf := NewMinCostFlow(graph, source, sink)
	ansFirst, ansSecond := mcf.minCostMaxFlow(math.MaxInt64)
	fmt.Println(ansFirst)
}
