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
		weight:       make([]int64, vertexCount),
		capacity:     make([]int64, vertexCount),
		reverseEdge:  make([]int, vertexCount),
	}
}

func (g *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	if g.firstOutbound[fromID] != -1 {
		g.firstOutbound[g.edgeCount] = g.firstOutbound[fromID]
	} else {
		g.firstOutbound[g.edgeCount] = -1
	}
	g.firstOutbound[fromID] = g.edgeCount
	g.from[g.edgeCount] = fromID
	g.to[g.edgeCount] = toID
	g.weight[g.edgeCount] = weight
	g.capacity[g.edgeCount] = capacity
	g.reverseEdge[g.edgeCount] = reverseEdge
	g.edgeCount++
	return g.edgeCount - 1
}

type ID5 struct {
	graph       *Graph
	source      int
	destination int
	phi         []int64
	id13        []int64
	lastEdge    []int
}

func NewID5(graph *Graph, source, destination int) *ID5 {
	vertexCount := graph.vertexCount
	return &ID5{
		graph:       graph,
		source:      source,
		destination: destination,
		phi:         make([]int64, vertexCount),
		id13:        make([]int64, vertexCount),
		lastEdge:    make([]int, vertexCount),
	}
}

func (mcf *ID5) ID2(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		mcf.ID12()
		if mcf.lastEdge[mcf.destination] == -1 {
			return makePair(cost, flow)
		}
		for i := 0; i < len(mcf.id13); i++ {
			if mcf.id13[i] != math.MaxInt64 {
				mcf.phi[i] += mcf.id13[i]
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
	return makePair(cost, flow)
}

func (mcf *ID5) ID12() {
	for i := range mcf.id13 {
		mcf.id13[i] = math.MaxInt64
		mcf.lastEdge[i] = -1
	}
	mcf.id13[mcf.source] = 0
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
	source := 2*shoe
	sink := 2*shoe + 1

	graph := NewGraph(2*shoe + 2)

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
					graph.AddEdge(id, id1, wt, 1, -1)
				}
				graph.AddEdge(source, id, 0, 1, -1)
			} else {
				graph.AddEdge(id, sink, 0, 1, -1)
			}
		}
	}

	mcf := NewID5(graph, source, sink)
	ans := mcf.ID2(math.MaxInt64)
	fmt.Println(ans.first)
}
