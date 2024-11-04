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
	nextOutbound  []int
	from          []int
	to            []int
	weight        []int64
	capacity      []int64
	reverseEdge   []int
}

func NewGraph(vertexCount int) *Graph {
	return &Graph{
		vertexCount:  vertexCount,
		firstOutbound: make([]int, vertexCount),
		nextOutbound:  make([]int, vertexCount),
		from:         make([]int, vertexCount),
		to:           make([]int, vertexCount),
		weight:       make([]int64, vertexCount),
		capacity:     make([]int64, vertexCount),
		reverseEdge:  make([]int, vertexCount),
	}
}

func (g *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	if g.firstOutbound[fromID] != -1 {
		g.nextOutbound[g.edgeCount] = g.firstOutbound[fromID]
	} else {
		g.nextOutbound[g.edgeCount] = -1
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

func (g *Graph) Id3(from, to int, weight, capacity int64) int {
	if capacity == 0 {
		return g.AddEdge(from, to, weight, 0, -1)
	} else {
		id4 := g.edgeCount
		g.AddEdge(to, from, -weight, 0, id4+1)
		return g.AddEdge(from, to, weight, capacity, id4)
	}
}

type Id5 struct {
	graph      *Graph
	source     int
	destination int
	phi        []int64
	id13       []int64
	lastEdge   []int
}

func NewId5(graph *Graph, source, destination int) *Id5 {
	vertexCount := graph.vertexCount
	return &Id5{
		graph:      graph,
		source:     source,
		destination: destination,
		phi:        make([]int64, vertexCount),
		id13:       make([]int64, vertexCount),
		lastEdge:   make([]int, vertexCount),
	}
}

func (id *Id5) Id2(maxFlow int64) (int64, int64) {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		id12(id)
		if id.lastEdge[id.destination] == -1 {
			return cost, flow
		}
		for i := 0; i < len(id.id13); i++ {
			if id.id13[i] != math.MaxInt64 {
				id.phi[i] += id.id13[i]
			}
		}
		vertex := id.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != id.source {
			edgeID := id.lastEdge[vertex]
			currentFlow = min(currentFlow, id.graph.capacity[edgeID])
			currentCost += id.graph.weight[edgeID]
			vertex = id.graph.from[edgeID]
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = id.destination
		for vertex != id.source {
			edgeID := id.lastEdge[vertex]
			id.graph.capacity[edgeID] -= currentFlow
			vertex = id.graph.from[edgeID]
		}
	}
	return cost, flow
}

func id12(id *Id5) {
	// Implementation of id12 logic
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
					graph.Id3(id, id1, wt, 1)
				}
				graph.Id3(source, id, 0, 1)
			} else {
				graph.Id3(id, sink, 0, 1)
			}
		}
	}

	mcf := NewId5(graph, source, sink)
	ans1, ans2 := mcf.Id2(math.MaxInt64)
	fmt.Println(ans1)
}
