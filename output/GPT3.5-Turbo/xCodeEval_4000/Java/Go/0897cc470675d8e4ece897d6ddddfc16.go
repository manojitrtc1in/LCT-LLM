package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	num, _ := strconv.Atoi(in.readString())
	return num
}

func (in *InputReader) ReadString() string {
	str, _ := in.reader.ReadString('\n')
	return str[:len(str)-1]
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

type Pair struct {
	first  interface{}
	second interface{}
}

func NewPair(first, second interface{}) Pair {
	return Pair{first: first, second: second}
}

type Graph struct {
	vertexCount int
	edgeCount   int
	firstOut    []int
	from        []int
	to          []int
	weight      []int64
	capacity    []int64
	nextOut     []int
	flags       []int
}

func NewGraph(vertexCount, edgeCapacity int) *Graph {
	g := &Graph{
		vertexCount: vertexCount,
		firstOut:    make([]int, vertexCount),
		from:        make([]int, edgeCapacity),
		to:          make([]int, edgeCapacity),
		weight:      make([]int64, edgeCapacity),
		capacity:    make([]int64, edgeCapacity),
		nextOut:     make([]int, edgeCapacity),
		flags:       make([]int, edgeCapacity),
	}
	for i := 0; i < vertexCount; i++ {
		g.firstOut[i] = -1
	}
	return g
}

func (g *Graph) AddEdge(from, to int, weight, capacity int64, reverseEdge int) int {
	edgeID := g.edgeCount
	g.from[edgeID] = from
	g.to[edgeID] = to
	g.weight[edgeID] = weight
	g.capacity[edgeID] = capacity
	g.nextOut[edgeID] = g.firstOut[from]
	g.firstOut[from] = edgeID
	if reverseEdge != -1 {
		g.nextOut[edgeID^1] = g.firstOut[to]
		g.firstOut[to] = edgeID ^ 1
	}
	g.edgeCount++
	return edgeID
}

type MinCostFlow struct {
	graph        *Graph
	source       int
	destination  int
	phi          []int64
	dijkstraRes  []int64
	lastEdge     []int
	heap         *Heap
	vertexCount  int
	visited      []int
	visitIndex   int
}

func NewMinCostFlow(graph *Graph, source, destination int, hasNegativeEdges bool) *MinCostFlow {
	m := &MinCostFlow{
		graph:        graph,
		source:       source,
		destination:  destination,
		vertexCount:  graph.vertexCount,
		phi:          make([]int64, graph.vertexCount),
		dijkstraRes:  make([]int64, graph.vertexCount),
		lastEdge:     make([]int, graph.vertexCount),
		visited:      make([]int, graph.vertexCount),
	}
	if hasNegativeEdges {
		m.fordBellman()
	}
	if graph.IsSparse() {
		m.heap = NewHeap(graph.vertexCount, func(a, b int) int {
			if m.dijkstraRes[a] < m.dijkstraRes[b] {
				return -1
			} else if m.dijkstraRes[a] > m.dijkstraRes[b] {
				return 1
			}
			return 0
		})
		m.visited = nil
	} else {
		m.heap = nil
	}
	return m
}

func (m *MinCostFlow) MinCostMaxFlow() Pair {
	return m.MinCostMaxFlowWithMaxFlow(1<<63 - 1)
}

func (m *MinCostFlow) MinCostMaxFlowWithMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		if m.graph.IsSparse() {
			m.dijkstraAlgorithm()
		} else {
			m.dijkstraAlgorithmFull()
		}
		if m.lastEdge[m.destination] == -1 {
			return NewPair(cost, flow)
		}
		for i := 0; i < len(m.dijkstraRes); i++ {
			if m.dijkstraRes[i] != 1<<63-1 {
				m.phi[i] += m.dijkstraRes[i]
			}
		}
		vertex := m.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != m.source {
			edgeID := m.lastEdge[vertex]
			currentFlow = min(currentFlow, m.graph.capacity[edgeID])
			currentCost += m.graph.weight[edgeID]
			vertex = m.graph.from[edgeID]
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = m.destination
		for vertex != m.source {
			edgeID := m.lastEdge[vertex]
			m.graph.PushFlow(edgeID, currentFlow)
			vertex = m.graph.from[edgeID]
		}
	}
	return NewPair(cost, flow)
}

func (m *MinCostFlow) fordBellman() {
	for i := 0; i < len(m.phi); i++ {
		m.phi[i] = 1 << 63 - 1
	}
	m.phi[m.source] = 0
	inQueue := make([]bool, m.vertexCount)
	queue := make([]int, m.vertexCount+1)
	queue[0] = m.source
	inQueue[m.source] = true
	stepCount := 0
	head := 0
	end := 1
	maxSteps := 2 * m.vertexCount * m.vertexCount
	for head != end {
		vertex := queue[head]
		head++
		if head == len(queue) {
			head = 0
		}
		inQueue[vertex] = false
		edgeID := m.graph.firstOut[vertex]
		for edgeID != -1 {
			total := m.phi[vertex] + m.graph.weight[edgeID]
			destination := m.graph.to[edgeID]
			if m.graph.capacity[edgeID] != 0 && m.phi[destination] > total {
				m.phi[destination] = total
				if !inQueue[destination] {
					queue[end] = destination
					end++
					if end == len(queue) {
						end = 0
					}
					inQueue[destination] = true
				}
			}
			edgeID = m.graph.nextOut[edgeID]
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (m *MinCostFlow) dijkstraAlgorithm() {
	for i := 0; i < len(m.dijkstraRes); i++ {
		m.dijkstraRes[i] = 1 << 63 - 1
	}
	for i := 0; i < len(m.lastEdge); i++ {
		m.lastEdge[i] = -1
	}
	m.dijkstraRes[m.source] = 0
	m.heap.Add(m.source)
	for !m.heap.IsEmpty() {
		current := m.heap.Poll()
		edgeID := m.graph.firstOut[current]
		for edgeID != -1 {
			if m.graph.capacity[edgeID] != 0 {
				next := m.graph.to[edgeID]
				total := m.graph.weight[edgeID] - m.phi[next] + m.phi[current] + m.dijkstraRes[current]
				if m.dijkstraRes[next] > total {
					m.dijkstraRes[next] = total
					if m.heap.GetIndex(next) == -1 {
						m.heap.Add(next)
					} else {
						m.heap.ShiftUp(m.heap.GetIndex(next))
					}
					m.lastEdge[next] = edgeID
				}
			}
			edgeID = m.graph.nextOut[edgeID]
		}
	}
}

func (m *MinCostFlow) dijkstraAlgorithmFull() {
	m.visitIndex++
	for i := 0; i < len(m.dijkstraRes); i++ {
		m.dijkstraRes[i] = 1 << 63 - 1
	}
	m.lastEdge[m.destination] = -1
	m.dijkstraRes[m.source] = 0
	for i := 0; i < m.vertexCount; i++ {
		index := -1
		length := int64(1 << 63 - 1)
		for j := 0; j < m.vertexCount; j++ {
			if m.visited[j] != m.visitIndex && m.dijkstraRes[j] < length {
				length = m.dijkstraRes[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		m.visited[index] = m.visitIndex
		edgeID := m.graph.firstOut[index]
		for edgeID != -1 {
			if m.graph.capacity[edgeID] != 0 {
				next := m.graph.to[edgeID]
				if m.visited[next] != m.visitIndex {
					total := m.graph.weight[edgeID] - m.phi[next] + m.phi[index] + length
					if m.dijkstraRes[next] > total {
						m.dijkstraRes[next] = total
						m.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = m.graph.nextOut[edgeID]
		}
	}
}

type Heap struct {
	comparator func(a, b int) int
	size       int
	elements   []int
	at         []int
}

func NewHeap(maxElement int, comparator func(a, b int) int) *Heap {
	h := &Heap{
		comparator: comparator,
		elements:   make([]int, 0, maxElement),
		at:         make([]int, maxElement),
	}
	for i := 0; i < maxElement; i++ {
		h.at[i] = -1
	}
	return h
}

func (h *Heap) IsEmpty() bool {
	return h.size == 0
}

func (h *Heap) Add(element int) {
	h.ensureCapacity(h.size + 1)
	h.elements[h.size] = element
	h.at[element] = h.size
	h.shiftUp(h.size)
	h.size++
}

func (h *Heap) Poll() int {
	if h.IsEmpty() {
		panic("Heap is empty")
	}
	result := h.elements[0]
	h.at[result] = -1
	if h.size == 1 {
		h.size = 0
		return result
	}
	h.elements[0] = h.elements[h.size-1]
	h.at[h.elements[0]] = 0
	h.size--
	h.shiftDown(0)
	return result
}

func (h *Heap) GetIndex(element int) int {
	return h.at[element]
}

func (h *Heap) shiftUp(index int) {
	value := h.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := h.elements[parent]
		if h.comparator(parentValue, value) <= 0 {
			h.elements[index] = value
			h.at[value] = index
			return
		}
		h.elements[index] = parentValue
		h.at[parentValue] = index
		index = parent
	}
	h.elements[0] = value
	h.at[value] = 0
}

func (h *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= h.size {
			return
		}
		if child+1 < h.size && h.comparator(h.elements[child], h.elements[child+1]) > 0 {
			child++
		}
		if h.comparator(h.elements[index], h.elements[child]) <= 0 {
			return
		}
		h.swap(index, child)
		index = child
	}
}

func (h *Heap) swap(first, second int) {
	temp := h.elements[first]
	h.elements[first] = h.elements[second]
	h.elements[second] = temp
	h.at[h.elements[first]] = first
	h.at[h.elements[second]] = second
}

func (h *Heap) ensureCapacity(size int) {
	if len(h.elements) < size {
		newElements := make([]int, max(2*len(h.elements), size))
		copy(newElements, h.elements)
		h.elements = newElements
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)

	n := input.ReadInt()
	s := input.ReadString()
	a := make([]int, n)
	cnt := make([]int, 26)
	for i := 0; i < n; i++ {
		a[i] = input.ReadInt()
		cnt[s[i]-'a']++
	}

	g := NewGraph(n+100, n+100)
	source := n + 100 - 2
	target := source + 1
	for i := 0; i*2 < n; i++ {
		g.AddEdge(i, target, 0, 2, -1)
	}
	for i := 0; i < 26; i++ {
		g.AddEdge(source, i+n, 0, int64(cnt[i]), -1)
		for j := 0; j*2 < n; j++ {
			if s[j] == s[n-j-1] {
				w := int64(0)
				if s[j] == byte(i+'a') {
					w = -max(int64(a[j]), int64(a[n-j-1]))
				}
				g.AddEdge(i+n, j, w, 1, -1)
			} else {
				w := int64(0)
				if s[j] == byte(i+'a') {
					w -= int64(a[j])
				}
				if s[n-j-1] == byte(i+'a') {
					w -= int64(a[n-j-1])
				}
				g.AddEdge(i+n, j, w, 1, -1)
			}
		}
	}

	mcmf := NewMinCostFlow(g, source, target, true)
	res := -mcmf.MinCostMaxFlow().first
	output.Println(res)

	output.Flush()
}
