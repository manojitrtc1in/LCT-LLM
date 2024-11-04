package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Point struct {
	X int
	Y int
}

type Edge struct {
	Vertex0 *Vertex
	Vertex1 *Vertex
}

type Vertex struct {
	Index int
	Edges []*Edge
}

type Set map[int][]*Point

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	points := make([]*Point, n)
	set := make(Set)

	for i := 0; i < n; i++ {
		x := nextInt(scanner)
		y := nextInt(scanner)
		point := &Point{X: x, Y: y}
		points[i] = point

		if _, ok := set[y]; !ok {
			set[y] = []*Point{point}
		} else {
			set[y] = append(set[y], point)
		}
	}

	edges := make([]*Edge, 0)
	for _, points := range set {
		sort.Slice(points, func(i, j int) bool {
			return points[i].X < points[j].X
		})

		for i := 1; i < len(points); i++ {
			edge := &Edge{Vertex0: points[i], Vertex1: points[i-1]}
			edges = append(edges, edge)
		}
	}

	graph := make(map[*Point][]*Point)
	for _, edge := range edges {
		vertex0 := edge.Vertex0
		vertex1 := edge.Vertex1

		if _, ok := graph[vertex0]; !ok {
			graph[vertex0] = []*Point{vertex1}
		} else {
			graph[vertex0] = append(graph[vertex0], vertex1)
		}

		if _, ok := graph[vertex1]; !ok {
			graph[vertex1] = []*Point{vertex0}
		} else {
			graph[vertex1] = append(graph[vertex1], vertex0)
		}
	}

	processed := make(map[*Point]bool)
	cycles := make(map[*Point]bool)
	lines := make(map[*Point]bool)

	for _, point := range points {
		if _, ok := processed[point]; !ok {
			structure := make([]*Point, 0)
			if cycle(point, structure, graph, processed) {
				cycles[point] = true
			} else {
				lines[point] = true
			}
