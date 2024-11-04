package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type Graph struct {
	vertexCount int
	edgeCount   int
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

type TaskF struct{}

type IntComparator func(int, int) int

type IntStream interface {
	IntIterator() IntIterator
	Iterator() Iterator
	CompareTo(IntStream) int
}

type GraphEdge struct {
	id int
}

type OutputWriter struct {
	writer *bufio.Writer
}

type IntQueue interface {
	IntCollection
}

type IntIterator interface {
	Value() int
	Advance() bool
	IsValid() bool
}

type InputReader struct {
	reader io.Reader
	buf    []byte
	cur    int
	num    int
}

type Pair struct {
	first  interface{}
	second interface{}
}

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewInputReader(inputStream)
	out := NewOutputWriter(outputStream)
	solver := &TaskF{}
	solver.Solve(1, in, out)
	out.Close()
}

func (solver *TaskF) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.NextInt()
	s := in.NextString()
	a := make([]int, n)
	cnt := make([]int, 26)
	for i := 0; i < n; i++ {
		a[i] = in.NextInt()
		cnt[int(s[i]-'a')]++
	}
	g := NewGraph(n + 100)
	source := n + 100 - 2
	target := source + 1
	for i := 0; i * 2 < n; i++ {
		g.AddEdge(i, target, 0, 2)
	}
	for i := 0; i < 26; i++ {
		g.AddEdge(source, i+n, 0, int64(cnt[i]))
		for j := 0; j * 2 < n; j++ {
			if s[j] == s[n-j-1] {
				w := int64(0)
				if s[j] == byte(i+'a') {
					w = -int64(Max(a[j], a[n-j-1]))
				}
				g.AddEdge(i+n, j, w, 1)
			} else {
				w := int64(0)
				if s[j] == byte(i+'a') {
					w -= int64(a[j])
				}
				if s[n-j-1] == byte(i+'a') {
					w -= int64(a[n-j-1])
				}
				g.AddEdge(i+n, j, w, 1)
			}
		}
	}
	id3 := NewID6(g, source, target, true)
	out.Println(-id3.ID1().first)
}

func NewGraph(vertexCount int) *Graph {
	return NewGraphWithCapacity(vertexCount, vertexCount)
}

func NewGraphWithCapacity(vertexCount, edgeCapacity int) *Graph {
	graph := &Graph{}
	graph.vertexCount = vertexCount
	graph.edgeCount = 0
	graph.firstOutbound = make([]int, vertexCount)
	for i := 0; i < vertexCount; i++ {
		graph.firstOutbound[i] = -1
	}
	graph.from = make([]int, edgeCapacity)
	graph.to = make([]int, edgeCapacity)
	graph.nextOutbound = make([]int, edgeCapacity)
	graph.flags = make([]int, edgeCapacity)
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
		graph.edges[graph.edgeCount] = graph.createEdge(graph.edgeCount)
	}
	graph.edgeCount++
	return graph.edgeCount - 1
}

func (graph *Graph) ensureEdgeCapacity(size int) {
	if len(graph.from) < size {
		newSize := Max(size, 2*len(graph.from))
		if graph.edges != nil {
			graph.edges = resizeEdgeSlice(graph.edges, newSize)
		}
		graph.from = resizeIntSlice(graph.from, newSize)
		graph.to = resizeIntSlice(graph.to, newSize)
		graph.nextOutbound = resizeIntSlice(graph.nextOutbound, newSize)
		if graph.nextInbound != nil {
			graph.nextInbound = resizeIntSlice(graph.nextInbound, newSize)
		}
		if graph.weight != nil {
			graph.weight = resizeInt64Slice(graph.weight, newSize)
		}
		if graph.capacity != nil {
			graph.capacity = resizeInt64Slice(graph.capacity, newSize)
		}
		if graph.reverseEdge != nil {
			graph.reverseEdge = resizeIntSlice(graph.reverseEdge, newSize)
		}
		graph.flags = resizeIntSlice(graph.flags, newSize)
	}
}

func resizeIntSlice(array []int, size int) []int {
	newArray := make([]int, size)
	copy(newArray, array)
	return newArray
}

func resizeInt64Slice(array []int64, size int) []int64 {
	newArray := make([]int64, size)
	copy(newArray, array)
	return newArray
}

func resizeEdgeSlice(array []Edge, size int) []Edge {
	newArray := make([]Edge, size)
	copy(newArray, array)
	return newArray
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (graph *Graph) createEdge(id int) Edge {
	return Edge{id: id}
}

type ID6 struct {
	graph        *Graph
	source       int
	destination  int
	phi          []int64
	id4          []int64
	lastEdge     []int
	heap         *Heap
	vertexCount  int
	visited      []int
	visitIndex   int
}

func NewID6(graph *Graph, source, destination int, id11 bool) *ID6 {
	id6 := &ID6{}
	id6.graph = graph
	id6.source = source
	id6.destination = destination
	id6.vertexCount = graph.vertexCount
	id6.phi = make([]int64, id6.vertexCount)
	if id11 {
		id6.id7()
	}
	id6.id4 = make([]int64, id6.vertexCount)
	id6.lastEdge = make([]int, id6.vertexCount)
	if graph.IsSparse() {
		id6.heap = NewHeap(id6.vertexCount, func(first, second int) int {
			return LongCompare(id6.id4[first], id6.id4[second])
		}, id6.vertexCount)
		id6.visited = nil
	} else {
		id6.heap = nil
		id6.visited = make([]int, id6.vertexCount)
	}
	return id6
}

func (id6 *ID6) id7() {
	for i := 0; i < id6.vertexCount; i++ {
		id6.phi[i] = 1<<63 - 1
	}
	id6.phi[id6.source] = 0
	inQueue := make([]bool, id6.vertexCount)
	queue := make([]int, id6.vertexCount+1)
	queue[0] = id6.source
	inQueue[id6.source] = true
	stepCount := 0
	head := 0
	end := 1
	maxSteps := 2 * id6.vertexCount * id6.vertexCount
	for head != end {
		vertex := queue[head]
		head++
		if head == len(queue) {
			head = 0
		}
		inQueue[vertex] = false
		edgeID := id6.graph.firstOutbound[vertex]
		for edgeID != -1 {
			total := id6.phi[vertex] + id6.graph.weight[edgeID]
			destination := id6.graph.to[edgeID]
			if id6.graph.capacity[edgeID] != 0 && id6.phi[destination] > total {
				id6.phi[destination] = total
				if !inQueue[destination] {
					queue[end] = destination
					end++
					if end == len(queue) {
						end = 0
					}
					inQueue[destination] = true
				}
			}
			edgeID = id6.graph.nextOutbound[edgeID]
		}
		stepCount++
		if stepCount > maxSteps {
			panic("Graph contains negative cycle")
		}
	}
}

func (id6 *ID6) ID1() Pair {
	return id6.ID1WithMaxFlow(1<<63 - 1)
}

func (id6 *ID6) ID1WithMaxFlow(maxFlow int64) Pair {
	cost := int64(0)
	flow := int64(0)
	for maxFlow != 0 {
		if id6.graph.IsSparse() {
			id6.id13()
		} else {
			id6.id10()
		}
		if id6.lastEdge[id6.destination] == -1 {
			return Pair{first: cost, second: flow}
		}
		for i := 0; i < len(id6.id4); i++ {
			if id6.id4[i] != 1<<63-1 {
				id6.phi[i] += id6.id4[i]
			}
		}
		vertex := id6.destination
		currentFlow := maxFlow
		currentCost := int64(0)
		for vertex != id6.source {
			edgeID := id6.lastEdge[vertex]
			currentFlow = Min(currentFlow, id6.graph.capacity[edgeID])
			currentCost += id6.graph.weight[edgeID]
			vertex = id6.graph.from[edgeID]
		}
		maxFlow -= currentFlow
		cost += currentCost * currentFlow
		flow += currentFlow
		vertex = id6.destination
		for vertex != id6.source {
			edgeID := id6.lastEdge[vertex]
			id6.graph.PushFlow(edgeID, currentFlow)
			vertex = id6.graph.from[edgeID]
		}
	}
	return Pair{first: cost, second: flow}
}

func (id6 *ID6) id13() {
	for i := 0; i < len(id6.id4); i++ {
		id6.id4[i] = 1<<63 - 1
	}
	for i := 0; i < len(id6.lastEdge); i++ {
		id6.lastEdge[i] = -1
	}
	id6.id4[id6.source] = 0
	id6.heap.Add(id6.source)
	for !id6.heap.IsEmpty() {
		current := id6.heap.Poll()
		edgeID := id6.graph.firstOutbound[current]
		for edgeID != -1 {
			if id6.graph.capacity[edgeID] != 0 {
				next := id6.graph.to[edgeID]
				total := id6.graph.weight[edgeID] - id6.phi[next] + id6.phi[current] + id6.id4[current]
				if id6.id4[next] > total {
					id6.id4[next] = total
					if id6.heap.GetIndex(next) == -1 {
						id6.heap.Add(next)
					} else {
						id6.heap.ShiftUp(id6.heap.GetIndex(next))
					}
					id6.lastEdge[next] = edgeID
				}
			}
			edgeID = id6.graph.nextOutbound[edgeID]
		}
	}
}

func (id6 *ID6) id10() {
	id6.visitIndex++
	for i := 0; i < len(id6.id4); i++ {
		id6.id4[i] = 1<<63 - 1
	}
	id6.lastEdge[id6.destination] = -1
	id6.id4[id6.source] = 0
	for i := 0; i < id6.vertexCount; i++ {
		index := -1
		length := int64(1<<63 - 1)
		for j := 0; j < id6.vertexCount; j++ {
			if id6.visited[j] != id6.visitIndex && id6.id4[j] < length {
				length = id6.id4[j]
				index = j
			}
		}
		if index == -1 {
			return
		}
		id6.visited[index] = id6.visitIndex
		edgeID := id6.graph.firstOutbound[index]
		for edgeID != -1 {
			if id6.graph.capacity[edgeID] != 0 {
				next := id6.graph.to[edgeID]
				if id6.visited[next] != id6.visitIndex {
					total := id6.graph.weight[edgeID] - id6.phi[next] + id6.phi[index] + length
					if id6.id4[next] > total {
						id6.id4[next] = total
						id6.lastEdge[next] = edgeID
					}
				}
			}
			edgeID = id6.graph.nextOutbound[edgeID]
		}
	}
}

func NewOutputWriter(writer io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(writer)}
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

func (out *OutputWriter) Println(i int64) {
	fmt.Fprintln(out.writer, i)
}

func NewInputReader(reader io.Reader) *InputReader {
	return &InputReader{reader: reader}
}

func (in *InputReader) Read() int {
	if in.num == -1 {
		panic("InputMismatchException")
	}
	if in.cur >= in.num {
		in.cur = 0
		in.num = 0
		var err error
		for in.num == 0 && err == nil {
			in.num, err = in.reader.Read(in.buf)
		}
		if err != nil {
			in.num = -1
		}
	}
	if in.num == -1 {
		return -1
	}
	result := int(in.buf[in.cur])
	in.cur++
	return result
}

func (in *InputReader) NextInt() int {
	c := in.Read()
	for isWhitespace(c) {
		c = in.Read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.Read()
	}
	res := 0
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("InputMismatchException")
		}
		res *= 10
		res += int(c - '0')
		c = in.Read()
	}
	return res * sgn
}

func (in *InputReader) NextString() string {
	c := in.Read()
	for isWhitespace(c) {
		c = in.Read()
	}
	var res strings.Builder
	for !isWhitespace(c) {
		if !CharacterIsValidCodePoint(c) {
			panic("InputMismatchException")
		}
		res.WriteRune(rune(c))
		c = in.Read()
	}
	return res.String()
}

func isWhitespace(c int) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1
}

func CharacterIsValidCodePoint(c int) bool {
	return c >= 0 && c <= 0x10FFFF
}

func LongCompare(a, b int64) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

func NewHeap(maxElement int, comparator IntComparator, size int) *Heap {
	return &Heap{comparator: comparator, size: 0, elements: make([]int, size), at: make([]int, maxElement)}
}

func (heap *Heap) IsEmpty() bool {
	return heap.size == 0
}

func (heap *Heap) Add(element int) {
	heap.ensureCapacity(heap.size + 1)
	heap.elements[heap.size] = element
	heap.at[element] = heap.size
	heap.shiftUp(heap.size)
	heap.size++
}

func (heap *Heap) ensureCapacity(size int) {
	if len(heap.elements) < size {
		newSize := Max(size, 2*len(heap.elements))
		newElements := make([]int, newSize)
		copy(newElements, heap.elements)
		heap.elements = newElements
	}
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
		}
		heap.elements[index] = parentValue
		heap.at[parentValue] = index
		index = parent
	}
	heap.elements[0] = value
	heap.at[value] = 0
}

func (heap *Heap) Poll() int {
	if heap.IsEmpty() {
		panic("IndexOutOfBoundsException")
	}
	result := heap.elements[0]
	heap.at[result] = -1
	if heap.size == 1 {
		heap.size = 0
		return result
	}
	heap.size--
	heap.elements[0] = heap.elements[heap.size]
	heap.at[heap.elements[0]] = 0
	heap.shiftDown(0)
	return result
}

func (heap *Heap) shiftDown(index int) {
	for {
		child := (index << 1) + 1
		if child >= heap.size {
			return
		}
		if child+1 < heap.size && heap.comparator(heap.elements[child], heap.elements[child+1]) > 0 {
			child++
		}
		if heap.comparator(heap.elements[index], heap.elements[child]) <= 0 {
			return
		}
		heap.swap(index, child)
		index = child
	}
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) swap(first, second int) {
	temp := heap.elements[first]
	heap.elements[first] = heap.elements[second]
	heap.elements[second] = temp
	heap.at[heap.elements[first]] = first
	heap.at[heap.elements[second]] = second
}

func (heap *Heap) ShiftUp(index int) {
	heap.shiftUp(index)
}

func (heap *Heap) GetIndex(element int) int {
	return heap.at[element]
}

func (heap *Heap) shiftUp(index int) {
	value := heap.elements[index]
	for index != 0 {
		parent := (index - 1) >> 1
		parentValue := heap.elements[parent]
		if heap.comparator(parentValue, value) <= 0 {
			heap.elements[index] = value
			heap.at[value] = index
			return
