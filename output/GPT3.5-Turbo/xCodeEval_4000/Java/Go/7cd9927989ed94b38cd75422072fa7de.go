package main

import (
	"container/list"
	"fmt"
)

type pair struct {
	val  int
	dist int
}

func bfs(arr []*list.List, visited []int, start int, m map[int]int) {
	q := list.New()
	q.PushBack(pair{val: start, dist: 0})
	m[start] = 0
	visited[start] = 1

	for q.Len() > 0 {
		ob := q.Front().Value.(pair)
		q.Remove(q.Front())

		for e := arr[ob.val].Front(); e != nil; e = e.Next() {
			curr := e.Value.(int)
			if visited[curr] == 0 {
				visited[curr] = 1
				q.PushBack(pair{val: curr, dist: ob.dist + 1})
				m[curr] = ob.dist + 1
			}
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	rarr := make([]*list.List, n+1)
	arr := make([]*list.List, n+1)
	for i := 0; i < n+1; i++ {
		rarr[i] = list.New()
		arr[i] = list.New()
	}

	var a, b int
	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		arr[a].PushBack(b)
		rarr[b].PushBack(a)
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

	min := 0
	max := 0

	for i := 0; i < h-1; i++ {
		count := 0
		if m[path[i]] == m[path[i+1]]+1 {
			for e := arr[path[i]].Front(); e != nil; e = e.Next() {
				curr := e.Value.(int)
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
