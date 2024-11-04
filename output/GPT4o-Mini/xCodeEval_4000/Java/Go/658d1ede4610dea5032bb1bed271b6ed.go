package main

import (
	"bytes"
	"fmt"
	"io"
	"math"
)

type Pair struct {
	first  int64
	second int64
}

type Graph struct {
	vertexCount int
	edges       [][]Edge
}

type Edge struct {
	to      int
	weight  int64
	capacity int64
}

func NewGraph(vertexCount int) *Graph {
	return &Graph{
		vertexCount: vertexCount,
		edges:       make([][]Edge, vertexCount),
	}
}

func (g *Graph) AddEdge(from, to int, weight, capacity int64) {
	g.edges[from] = append(g.edges[from], Edge{to, weight, capacity})
}

type MinCostFlow struct {
	graph      *Graph
	source     int
	destination int
	phi        []int64
	dijkstraResult []int64
	lastEdge   []int
}

func NewMinCostFlow(graph *Graph, source, destination int) *MinCostFlow {
	return &MinCostFlow{
		graph:        graph,
		source:       source,
		destination:  destination,
		phi:          make([]int64, graph.vertexCount),
		dijkstraResult: make([]int64, graph.vertexCount),
		lastEdge:     make([]int, graph.vertexCount),
	}
}

func (m *MinCostFlow) FordBellman() {
	for i := range m.phi {
		m.phi[i] = math.MaxInt64
	}
	m.phi[m.source] = 0
}

func (m *MinCostFlow) MinCostMaxFlow(maxFlow int64) (int64, int64) {
	cost := int64(0)
	flow := int64(0)

	for maxFlow > 0 {
		m.DijkstraAlgorithm()
		if m.lastEdge[m.destination] == -1 {
			return cost, flow
		}
		currentFlow := maxFlow
		currentCost := int64(0)
		vertex := m.destination

		for vertex != m.source {
			edgeID := m.lastEdge[vertex]
			currentFlow = min(currentFlow, m.graph.edges[edgeID][0].capacity)
			currentCost += m.graph.edges[edgeID][0].weight
			vertex = m.graph.edges[edgeID][0].to
		}

		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = m.destination

		for vertex != m.source {
			edgeID := m.lastEdge[vertex]
			m.graph.edges[edgeID][0].capacity -= currentFlow
			vertex = m.graph.edges[edgeID][0].to
		}
	}
	return cost, flow
}

func (m *MinCostFlow) DijkstraAlgorithm() {
	for i := range m.dijkstraResult {
		m.dijkstraResult[i] = math.MaxInt64
		m.lastEdge[i] = -1
	}
	m.dijkstraResult[m.source] = 0
	// Implement priority queue logic here
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	s := make([]byte, n)
	fmt.Scanf("%s", &s)

	ugliness := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ugliness[i])
		ugliness[i] = -ugliness[i]
	}

	graph := NewGraph(1 + 26 + n/2 + 1)
	for c := 'a'; c <= 'z'; c++ {
		for i := 0; i < n/2; i++ {
			cost := int64(math.MaxInt64)
			if c == s[i] {
				cost = min(cost, ugliness[i])
			}
			if c == s[n-1-i] {
				cost = min(cost, ugliness[n-1-i])
			}
			graph.AddEdge(1+(c-'a'), 1+26+i, cost, 1)
		}
	}

	occurs := make([]int, 128)
	for i := 0; i < n; i++ {
		occurs[s[i]]++
	}
	for c := 'a'; c <= 'z'; c++ {
		graph.AddEdge(0, 1+(c-'a'), 0, int64(occurs[c]))
	}

	for i := 0; i < n/2; i++ {
		graph.AddEdge(1+26+i, 1+26+n/2, 0, 2)
	}

	mcf := NewMinCostFlow(graph, 0, 1+26+n/2)
	cost, _ := mcf.MinCostMaxFlow(int64(n))
	fmt.Println(-cost)
}
