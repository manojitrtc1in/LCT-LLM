package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (in *InputReader) ReadInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) PrintLine(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

type Graph struct {
	vertexCount int
	edges       [][]Edge
}

type Edge struct {
	to       int
	weight   int
	capacity int
}

func NewGraph(vertexCount int) *Graph {
	edges := make([][]Edge, vertexCount)
	return &Graph{vertexCount: vertexCount, edges: edges}
}

func (g *Graph) AddEdge(from, to, weight, capacity int) {
	g.edges[from] = append(g.edges[from], Edge{to: to, weight: weight, capacity: capacity})
}

type Solver struct{}

func (s *Solver) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	rowCount := in.ReadInt()
	columnCount := in.ReadInt()
	typeGrid := make([][]int, rowCount)
	for i := 0; i < rowCount; i++ {
		typeGrid[i] = make([]int, columnCount)
		for j := 0; j < columnCount {
			typeGrid[i][j] = in.ReadInt()
		}
	}

	graph := NewGraph(rowCount*columnCount + 2)
	source := graph.vertexCount - 2
	sink := graph.vertexCount - 1

	for i := 0; i < rowCount; i++ {
		for j := 0; j < columnCount; j++ {
			index := i*columnCount + j
			if (i+j)%2 == 0 {
				graph.AddEdge(source, index, 1, 1)
				for k := 0; k < 4; k++ {
					row := i + DX4[k]
					column := j + DY4[k]
					if isValid(row, column, rowCount, columnCount) {
						graph.AddEdge(index, row*columnCount+column, 0, 1)
					}
				}
			} else {
				graph.AddEdge(index, sink, 1, 1)
			}
		}
	}

	// Placeholder for the flow calculation
	out.PrintLine("Flow calculation not implemented")
}

var DX4 = [4]int{1, 0, -1, 0}
var DY4 = [4]int{0, -1, 0, 1}

func isValid(row, column, rowCount, columnCount int) bool {
	return row >= 0 && row < rowCount && column >= 0 && column < columnCount
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := &Solver{}
	solver.Solve(1, in, out)
	out.Close()
}
