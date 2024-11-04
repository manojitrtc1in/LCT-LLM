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

func (a ByX) Len() int           { return len(a) }
func (a ByX) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByX) Less(i, j int) bool { return a[i].X < a[j].X }

func countLines(points []Point) int {
	xs := make(map[int]bool)
	ys := make(map[int]bool)
	for _, point := range points {
		xs[point.X] = true
		ys[point.Y] = true
	}
	return len(xs) + len(ys)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	points := make([]Point, n)
	for i := 0; i < n; i++ {
		x := nextInt(scanner)
