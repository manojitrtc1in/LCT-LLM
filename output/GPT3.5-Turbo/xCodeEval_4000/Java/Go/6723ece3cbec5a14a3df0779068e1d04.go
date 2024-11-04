package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var adj [][]int
var dist []int
var mulpath []bool

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	m := nextInt(scanner)
	adj = make([][]int, n)
	for i := 0; i < n; i++ {
		adj[i] = make([]int, 0)
	}
	for m > 0 {
		u := nextInt(scanner) - 1
		v := nextInt(scanner) - 1
		adj[v] = append(adj[v], u)
		m--
	}

	dist = make([]int, n)
	mulpath = make([]bool, n)
	k := nextInt(scanner)
	p := make([]int, k)
	for i := 0; i < k; i++ {
		p[i] = nextInt(scanner) - 1
	}

	bfs(p[k-1])
	min := 0
	max := 0
	for i := 0; i < k-1; i++ {
		if dist[p[i+1]]+1 == dist[p[i]] {
			if mulpath[p[i]] {
				max++
			}
		} else {
			min++
			max++
		}
	}

	fmt.Println(min, max)
}

func bfs(s int) {
	n := len(adj)
	dist = make([]int, n)
	for i := 0; i < n; i++ {
		dist[i] = 1e9
	}
	dist[s] = 0
	queue := make([]int, 0)
	queue = append(queue, s)

	for len(queue) > 0 {
		u := queue[0]
		queue = queue[1:]

		for _, v := range adj[u] {
			if dist[v] == 1e9 {
				dist[v] = dist[u] + 1
				queue = append(queue, v)
			} else if dist[v] == dist[u]+1 {
				mulpath[v] = true
			}
		}
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
