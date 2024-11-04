package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var rowCount, columnCount int
	fmt.Fscan(in, &rowCount, &columnCount)
	typeGrid := readIntTable(in, rowCount, columnCount)

	graph := NewGraph(rowCount*columnCount + 2)
	source := graph.VertexCount() - 2
	sink := graph.VertexCount() - 1

	for i := 0; i < rowCount; i++ {
		for j := 0; j < columnCount; j++ {
			index := i*columnCount + j
			if (i+j)%2 == 0 {
				graph.AddFlowEdge(source, index, 1)
				for k := 0; k < 4; k++ {
					row := i + DX4[k]
					column := j + DY4[k]
					if isValidCell(row, column, rowCount, columnCount) {
						graph.AddFlowWeightedEdge(index, row*columnCount+column, 
							if typeGrid[i][j] == typeGrid[row][column] { 0 } else { 1 }, 1)
					}
				}
			} else {
				graph.AddFlowEdge(index, sink, 1)
			}
		}
	}
	fmt.Fprintln(out, NewMinCostFlow(graph, source, sink, false).MinCostMaxFlow().First)
}

func readIntTable(in io.Reader, rowCount, columnCount int) [][]int {
	table := make([][]int, rowCount)
	for i := 0; i < rowCount; i++ {
		table[i] = readIntArray(in, columnCount)
	}
	return table
}

func readIntArray(in io.Reader, size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Fscan(in, &array[i])
	}
	return array
}

const (
	REMOVED_BIT = 0
)

var DX4 = [4]int{1, 0, -1, 0}
var DY4 = [4]int{0, -1, 0, 1}

func isValidCell(row, column, rowCount, columnCount int) bool {
	return row >= 0 && row < rowCount && column >= 0 && column < columnCount
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOutbound []int
	from, to, nextOutbound, flags []int
	weight, capacity []int64
	reverseEdge []int
}

func NewGraph(vertexCount int) *Graph {
	graph := &Graph{
		vertexCount: vertexCount,
		firstOutbound: make([]int, vertexCount),
		from: make([]int, vertexCount),
		to: make([]int, vertexCount),
		nextOutbound: make([]int, vertexCount),
		flags: make([]int, vertexCount),
	}
	for i := range graph.firstOutbound {
		graph.firstOutbound[i] = -1
	}
	return graph
}

func (g *Graph) AddEdge(fromID, toID int, weight, capacity int64, reverseEdge int) int {
	g.ensureEdgeCapacity(g.edgeCount + 1)
	if g.firstOutbound[fromID] != -1 {
		g.nextOutbound[g.edgeCount] = g.firstOutbound[fromID]
	} else {
		g.nextOutbound[g.edgeCount] = -1
	}
	g.firstOutbound[fromID] = g.edgeCount
	g.from[g.edgeCount] = fromID
	g.to[g.edgeCount] = toID
	if capacity != 0 {
		if g.capacity == nil {
			g.capacity = make([]int64, len(g.from))
		}
		g.capacity[g.edgeCount] = capacity
	}
	if weight != 0 {
		if g.weight == nil {
			g.weight = make([]int64, len(g.from))
		}
		g.weight[g.edgeCount] = weight
	}
	if reverseEdge != -1 {
		if g.reverseEdge == nil {
			g.reverseEdge = make([]int, len(g.from))
			for i := 0; i < g.edgeCount; i++ {
				g.reverseEdge[i] = -1
			}
		}
		g.reverseEdge[g.edgeCount] = reverseEdge
	}
	return g.edgeCount++
}

func (g *Graph) AddFlowWeightedEdge(from, to int, weight, capacity int64) int {
	if capacity == 0 {
		return g.AddEdge(from, to, weight, 0, -1)
	} else {
		lastEdgeCount := g.edgeCount
		g.AddEdge(to, from, -weight, 0, lastEdgeCount+1)
		return g.AddEdge(from, to, weight, capacity, lastEdgeCount)
	}
}

func (g *Graph) AddFlowEdge(from, to int, capacity int64) int {
	return g.AddFlowWeightedEdge(from, to, 0, capacity)
}

func (g *Graph) VertexCount() int {
	return g.vertexCount
}

type MinCostFlow struct {
	graph       *Graph
	source      int
	destination int
	phi         []int64
	dijkstraResult []int64
	lastEdge    []int
}

func NewMinCostFlow(graph *Graph, source, destination int, hasNegativeEdges bool) *MinCostFlow {
	mcf := &MinCostFlow{
		graph: graph,
		source: source,
		destination: destination,
		phi: make([]int64, graph.VertexCount()),
		dijkstraResult: make([]int64, graph.VertexCount()),
		lastEdge: make([]int, graph.VertexCount()),
	}
	if hasNegativeEdges {
		mcf.fordBellman()
	}
	return mcf
}

func (m *MinCostFlow) fordBellman() {
	for i := range m.phi {
		m.phi[i] = 1<<63 - 1
	}
	m.phi[m.source] = 0
	inQueue := make([]bool, m.graph.VertexCount())
	queue := make([]int, m.graph.VertexCount()+1)
	queue[0] = m.source
	inQueue[m.source] = true
	head, end := 0, 1
	maxSteps := 2 * m.graph.VertexCount() * m.graph.VertexCount()

	for head != end {
		vertex := queue[head]
		head++
		if head == len(queue) {
			head = 0
		}
		inQueue[vertex] = false
		edgeID := m.graph.firstOutbound[vertex]
		for edgeID != -1 {
			total := m.phi[vertex] + m.graph.weight[edgeID]
			dest := m.graph.to[edgeID]
			if m.graph.capacity[edgeID] != 0 && m.phi[dest] > total {
				m.phi[dest] = total
				if !inQueue[dest] {
					queue[end] = dest
					end++
					if end == len(queue) {
						end = 0
					}
					inQueue[dest] = true
				}
			}
			edgeID = m.graph.nextOutbound[edgeID]
		}
		if head > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (m *MinCostFlow) MinCostMaxFlow() (cost, flow int64) {
	// Implementation of minCostMaxFlow logic
	return
}
