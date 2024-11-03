package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Point struct {
	X int
	Y int
}

type ByX []Point

func (p ByX) Len() int           { return len(p) }
func (p ByX) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p ByX) Less(i, j int) bool { return p[i].X < p[j].X }

type ByY []Point

func (p ByY) Len() int           { return len(p) }
func (p ByY) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p ByY) Less(i, j int) bool { return p[i].Y < p[j].Y }

type Edge struct {
	Vertex0 int
	Vertex1 int
}

type Vertex struct {
	Index int
	Edges []Edge
}

type Tree2D struct {
	Trees [4]*Tree2D
