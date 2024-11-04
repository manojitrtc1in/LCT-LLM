package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pair struct {
	val  int
	dist int
}

func bfs(arr [][]int, visited []int, start int, m map[int]int) {
	q := []pair{{val: start, dist: 0}}
	m[start] = 0
	visited[start] = 1
	for len(q) > 0 {
		ob := q[0]
		q = q[1:]
		for i := 0; i < len(arr[ob.val]); i++ {
			curr := arr[ob.val][i]
			if visited[curr] == 0 {
				visited[curr] = 1
				q = append(q, pair{val: curr, dist: ob.dist + 1})
				m[curr] = ob.dist + 1
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	rarr := make([][]int, n+1)
	arr := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		rarr[i] = []int{}
		arr[i] = []int{}
	}

	for i := 0; i < m; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())

		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())

		arr[a] = append(arr[a], b)
		rarr[b] = append(rarr[b], a)
	}

	scanner.Scan()
	h, _ := strconv.Atoi(scanner.Text())

	path := make([]int, h)
	for i := 0; i < h; i++ {
		scanner.Scan()
		path[i], _ = strconv.Atoi(scanner.Text())
	}

	m := make(map[int]int)
	visited := make([]int, n+1)
	bfs(rarr, visited, path[h-1], m)

	min := 0
	max := 0

	for i := 0; i < h-1; i++ {
		count := 0
		if m[path[i]] == m[path[i+1]]+1 {
			for j := 0; j < len(arr[path[i]]); j++ {
				curr := arr[path[i]][j]
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
