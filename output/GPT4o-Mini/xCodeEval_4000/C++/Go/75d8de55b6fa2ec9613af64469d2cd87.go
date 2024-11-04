package main

import (
	"fmt"
	"math"
)

type Vector[T any] struct {
	data []T
}

func NewVector[T any](n int) *Vector[T] {
	return &Vector[T]{data: make([]T, n)}
}

func (v *Vector[T]) Get(index int) T {
	return v.data[index]
}

func (v *Vector[T]) Set(index int, value T) {
	v.data[index] = value
}

func (v *Vector[T]) Size() int {
	return len(v.data)
}

type Pair[T1, T2 any] struct {
	First  T1
	Second T2
}

type Arr[T any] struct {
	data []T
}

func NewArr[T any](n int) *Arr[T] {
	return &Arr[T]{data: make([]T, n)}
}

func (a *Arr[T]) Get(index int) T {
	return a.data[index]
}

func (a *Arr[T]) Set(index int, value T) {
	a.data[index] = value
}

func (a *Arr[T]) Size() int {
	return len(a.data)
}

type Arr2D[T any] struct {
	data [][]T
}

func NewArr2D[T any](rows, cols int) *Arr2D[T] {
	data := make([][]T, rows)
	for i := range data {
		data[i] = make([]T, cols)
	}
	return &Arr2D[T]{data: data}
}

func (a *Arr2D[T]) Get(row, col int) T {
	return a.data[row][col]
}

func (a *Arr2D[T]) Set(row, col int, value T) {
	a.data[row][col] = value
}

type Graph struct {
	edges [][]int
}

func NewGraph(vertexCount int) *Graph {
	edges := make([][]int, vertexCount)
	return &Graph{edges: edges}
}

func (g *Graph) AddEdge(from, to int) {
	g.edges[from] = append(g.edges[from], to)
}

func (g *Graph) GetEdges(vertex int) []int {
	return g.edges[vertex]
}

func DecreaseByOne(arr *Arr[int]) {
	for i := 0; i < arr.Size(); i++ {
		arr.Set(i, arr.Get(i)-1)
	}
}

func Solve(n, m int, b, w, x, y []int) int {
	graph := NewGraph(n)
	for i := 0; i < n-1; i++ {
		graph.AddEdge(x[i], y[i])
	}

	q := NewArr[int](n)
	var calcQ func(int, int) int
	calcQ = func(vert, last int) int {
		res := 1
		for _, next := range graph.GetEdges(vert) {
			if next == last {
				continue
			}
			res += calcQ(next, vert)
		}
		q.Set(vert, res)
		return res
	}
	calcQ(0, -1)

	answer := NewArr2D[Pair[int, int]](n, m+1)
	var goFunc func(int, int)
	goFunc = func(vert, last int) {
		id := -1
		for _, next := range graph.GetEdges(vert) {
			if next == last {
				continue
			}
			goFunc(next, vert)
			if id == -1 || q.Get(next) > q.Get(id) {
				id = next
			}
		}
		delta := w[vert] - b[vert]
		cur := answer.Get(vert)

		if id == -1 {
			cur.Set(0, Pair[int, int]{0, delta})
			cur.Set(1, Pair[int, int]{0, 0})
			return
		}

		aid := answer.Get(id)
		for i := 0; i <= q.Get(id); i++ {
			cur.Set(i, aid[i])
			cur.Get(i).Second += delta
		}

		sz := q.Get(id)
		for i := sz + 1; i <= q.Get(vert); i++ {
			cur.Set(i, Pair[int, int]{-1, 0})
		}
		for _, next := range graph.GetEdges(vert) {
			if next == last || next == id {
				continue
			}
			anext := answer.Get(next)
			temp := make([]Pair[int, int], sz+1)
			copy(temp, cur.data[:sz+1])

			nsz := sz + q.Get(next)
			for i := 0; i <= sz; i++ {
				for j := 0; j <= q.Get(next); j++ {
					cur.Set(i+j, Pair[int, int]{temp[i].First + anext[j].First, temp[i].Second + anext[j].Second})
				}
			}
			sz = nsz
		}
		if vert == 0 {
			for i := n - 1; i >= 0; i-- {
				cur.Set(i+1, Pair[int, int]{cur.Get(i).First + boolToInt(cur.Get(i).Second > 0), 0})
			}
			return
		}

		for i := sz; i >= 0; i-- {
			cur.Set(i+1, Pair[int, int]{cur.Get(i).First + boolToInt(cur.Get(i).Second > 0), 0})
		}
	}
	goFunc(0, -1)
	return answer.Get(0).Get(m).First
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)
		b := make([]int, m)
		w := make([]int, m)
		x := make([]int, m-1)
		y := make([]int, m-1)
		for j := 0; j < m; j++ {
			fmt.Scan(&b[j])
		}
		for j := 0; j < m; j++ {
			fmt.Scan(&w[j])
		}
		for j := 0; j < m-1; j++ {
			fmt.Scan(&x[j], &y[j])
		}
		DecreaseByOne(NewArr(len(x)))
		result := Solve(m, m, b, w, x, y)
		fmt.Println(result)
	}
}
