package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type Graph struct {
	vertexCount int
	edges       [][]Edge
}

type Edge struct {
	to     int
	weight int64
}

type TaskD struct {
	graph  *Graph
	weight []int
	path   []int
}

func (t *TaskD) solve(n, k int, a []int, u, v []int) {
	t.graph = createGraph(n, u, v)
	order := createOrder(a)
	sort.Sort(sort.Reverse(sort.IntSlice(order)))

	left, right := k, n
	t.weight = make([]int, n)
	degree := make([]int, n)

	for i := 0; i < n-1; i++ {
		degree[u[i]]++
		degree[v[i]]++
	}

	remaining := make([]int, n)
	queue := make([]int, n)
	t.path = make([]int, n)

	for left < right {
		middle := (left + right) >> 1
		threshold := a[order[middle-1]]
		for i := range t.weight {
			if a[i] >= threshold {
				t.weight[i] = 1
			} else {
				t.weight[i] = 0
			}
		}

		copy(remaining, degree)
		size := 0
		for i := 0; i < n; i++ {
			if degree[i] == 1 && t.weight[i] > 0 {
				queue[size] = i
				size++
			}
		}

		for i := 0; i < size; i++ {
			current := queue[i]
			for _, edge := range t.graph.edges[current] {
				next := edge.to
				if t.weight[next] != 0 {
					t.weight[next] += t.weight[current]
					t.weight[current] = 0
					remaining[next]--
					if remaining[next] == 1 {
						queue[size] = next
						size++
					}
				}
			}
		}

		result := t.dfs(0, -1)
		if result >= k {
			right = middle
		} else {
			left = middle + 1
		}
	}
	fmt.Println(a[order[left-1]])
}

func (t *TaskD) dfs(current, last int) int {
	result := 0
	max, second := 0, 0
	for _, edge := range t.graph.edges[current] {
		next := edge.to
		if next == last {
			continue
		}
		result = maxInt(result, t.dfs(next, current))
		if t.path[next] > max {
			second = max
			max = t.path[next]
		} else {
			second = maxInt(second, t.path[next])
		}
	}
	if t.weight[current] != 0 {
		t.path[current] = t.weight[current] + max
		result = maxInt(result, max+second+t.weight[current])
	} else {
		t.path[current] = 0
	}
	return result
}

func createGraph(vertexCount int, u, v []int) *Graph {
	graph := &Graph{vertexCount: vertexCount, edges: make([][]Edge, vertexCount)}
	for i := 0; i < len(u); i++ {
		graph.edges[u[i]] = append(graph.edges[u[i]], Edge{to: v[i]})
		graph.edges[v[i]] = append(graph.edges[v[i]], Edge{to: u[i]})
	}
	return graph
}

func createOrder(array []int) []int {
	order := make([]int, len(array))
	for i := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return array[order[i]] < array[order[j]]
	})
	return order
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	u := make([]int, n-1)
	v := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(reader, &u[i], &v[i])
	}

	solver := &TaskD{}
	solver.solve(n, k, a, u, v)
}
