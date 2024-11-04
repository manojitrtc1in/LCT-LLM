package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pr struct {
	first  int
	second int64
}

func calcQ(vert int, last int, graph [][]int, q []int) int {
	res := 1
	for _, next := range graph[vert] {
		if next == last {
			continue
		}
		res += calcQ(next, vert, graph, q)
	}
	q[vert] = res
	return res
}

func go(vert int, last int, graph [][]int, answer [][]pr, b []int, w []int, q []int) {
	id := -1
	for _, next := range graph[vert] {
		if next == last {
			continue
		}
		go(next, vert, graph, answer, b, w, q)
		if id == -1 || q[next] > q[id] {
			id = next
		}
	}
	cur := answer[vert]
	delta := int64(w[vert] - b[vert])
	if id == -1 {
		cur[0] = pr{0, delta}
		cur[1] = pr{0, 0}
		return
	}
	aid := answer[id]
	for i := 0; i <= q[id]; i++ {
		cur[i] = aid[i]
		cur[i].second += delta
	}
	sz := q[id]
	for i := sz + 1; i <= q[vert]; i++ {
		cur[i] = pr{-1, 0}
	}
	for _, next := range graph[vert] {
		if next == last || next == id {
			continue
		}
		anext := answer[next]
		for i := 0; i <= sz; i++ {
			temp := cur[i]
			cur[i] = pr{-1, 0}
			for j := 0; j <= q[next]; j++ {
				if temp.first+anext[j].first > cur[i+j].first {
					cur[i+j] = pr{temp.first + anext[j].first, temp.second + anext[j].second}
				}
			}
		}
		sz += q[next]
	}
	if vert == 0 {
		for i := n - 1; i >= 0; i-- {
			cur[i+1] = pr{cur[i].first + boolToInt(cur[i].second > 0), 0}
		}
		return
	}
	for i := sz; i >= 0; i-- {
		if cur[i].first+boolToInt(cur[i].second > 0) > cur[i+1].first {
			cur[i+1] = pr{cur[i].first + boolToInt(cur[i].second > 0), 0}
		}
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	for i := 0; i < n; i++ {
		solver(scanner)
	}
}

func solver(scanner *bufio.Scanner) {
	n := nextInt(scanner)
	m := nextInt(scanner)
	b := make([]int, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = nextInt(scanner)
	}
	for i := 0; i < n; i++ {
		w[i] = nextInt(scanner)
	}
	graph := make([][]int, n)
	for i := 0; i < n-1; i++ {
		x := nextInt(scanner)
		y := nextInt(scanner)
		graph[x-1] = append(graph[x-1], y-1)
		graph[y-1] = append(graph[y-1], x-1)
	}
	q := make([]int, n)
	calcQ(0, -1, graph, q)
	answer := make([][]pr, n)
	for i := 0; i < n; i++ {
		answer[i] = make([]pr, n+2)
	}
	go(0, -1, graph, answer, b, w, q)
	fmt.Println(answer[0][m].first)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
