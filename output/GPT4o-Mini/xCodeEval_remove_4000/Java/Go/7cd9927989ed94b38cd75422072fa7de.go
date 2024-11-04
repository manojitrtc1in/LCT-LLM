package main

import (
	"fmt"
)

type Pair struct {
	val  int
	dist int
}

func bfs(arr [][]int, visited []int, start int, m map[int]int) {
	q := []Pair{{start, 0}}
	m[start] = 0
	visited[start] = 1

	for len(q) > 0 {
		ob := q[0]
		q = q[1:]

		for _, curr := range arr[ob.val] {
			if visited[curr] == 0 {
				visited[curr] = 1
				q = append(q, Pair{curr, ob.dist + 1})
				m[curr] = ob.dist + 1
			}
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	rarr := make([][]int, n+1)
	arr := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		rarr[i] = []int{}
		arr[i] = []int{}
	}

	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		arr[a] = append(arr[a], b)
		rarr[b] = append(rarr[b], a)
	}

	var h int
	fmt.Scan(&h)
	path := make([]int, h)
	for i := 0; i < h; i++ {
		fmt.Scan(&path[i])
	}

	m := make(map[int]int)
	visited := make([]int, n+1)
	bfs(rarr, visited, path[h-1], m)

	min, max := 0, 0

	for i := 0; i < h-1; i++ {
		count := 0
		if m[path[i]] == m[path[i+1]]+1 {
			for _, curr := range arr[path[i]] {
				if m[curr] == m[path[i]]-1 {
					count++
				}
			}

			if count > 1 {
				max++
			}

		} else {
			min++
			max++
		}
	}
	fmt.Println(min, max)
}
