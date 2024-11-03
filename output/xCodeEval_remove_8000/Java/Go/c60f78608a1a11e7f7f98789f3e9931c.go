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
	Vertex0       *Vertex
	Vertex1       *Vertex
	Bidirectional bool
}

type Vertex struct {
	Index int
	Edges []*Edge
}

type Set []*Point

func (s Set) Len() int {
	return len(s)
}

func (s Set) Less(i, j int) bool {
	if s[i].X == s[j].X {
		return s[i].Y < s[j].Y
	}
	return s[i].X < s[j].X
}

func (s Set) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func NewPoint(x, y int) *Point {
	return &Point{
		X: x,
		Y: y,
	}
}

func NewEdge(vertex0, vertex1 *Vertex, bidirectional bool) *Edge {
	return &Edge{
		Vertex0:       vertex0,
		Vertex1:       vertex1,
		Bidirectional: bidirectional,
	}
}

func NewVertex(index int) *Vertex {
	return &Vertex{
		Index: index,
		Edges: make([]*Edge, 0),
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	points := make([]*Point, n)
	id3 := make(map[int]Set)
	for i := 0; i < n; i++ {
		x := nextInt(scanner)
		y := nextInt(scanner)
		point := NewPoint(x, y)
		points[i] = point
		if _, ok := id3[y]; !ok {
			id3[y] = make(Set, 0)
		}
		id3[y] = append(id3[y], point)
	}

	id49 := make(map[int]*Point)
	for _, set := range id3 {
		sort.Sort(set)
		lastX := set[0]
		for i := 1; i < len(set); i++ {
			point := set[i]
			NewEdge(point, lastX, true)
			if lastY, ok := id49[point.X]; ok {
				NewEdge(point, lastY, true)
			}
			id49[point.X] = point
			lastX = point
		}
