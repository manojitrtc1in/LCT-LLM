package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Edge struct {
	to   int
	weight int64
}

type Heap struct {
	data []Item
}

type Item struct {
	distance int64
	index    int
}

func (h *Heap) Push(x Item) {
	h.data = append(h.data, x)
	h.up(len(h.data) - 1)
}

func (h *Heap) Pop() Item {
	n := len(h.data) - 1
	h.swap(0, n)
	h.down(0, n)
	item := h.data[n]
	h.data = h.data[:n]
	return item
}

func (h *Heap) up(i int) {
	for i > 0 {
		p := (i - 1) / 2
		if h.data[i].distance >= h.data[p].distance {
			break
		}
		h.swap(i, p)
		i = p
	}
}

func (h *Heap) down(i, n int) {
	for {
		left := 2*i + 1
		if left >= n {
			break
		}
		right := left + 1
		smallest := left
		if right < n && h.data[right].distance < h.data[left].distance {
			smallest = right
		}
		if h.data[i].distance <= h.data[smallest].distance {
			break
		}
		h.swap(i, smallest)
		i = smallest
	}
}

func (h *Heap) swap(i, j int) {
	h.data[i], h.data[j] = h.data[j], h.data[i]
}

func dijkstra(n int, adj [][]Edge) []int64 {
	const INF = int64(1e18)
	dist := make([]int64, n)
	for i := range dist {
		dist[i] = INF
	}
	dist[0] = 0

	h := &Heap{}
	h.Push(Item{0, 0})

	for len(h.data) > 0 {
		item := h.Pop()
		u := item.index
		if item.distance > dist[u] {
			continue
		}
		for _, edge := range adj[u] {
			if dist[u]+edge.weight < dist[edge.to] {
				dist[edge.to] = dist[u] + edge.weight
				h.Push(Item{dist[edge.to], edge.to})
			}
		}
	}
	return dist
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, m := readTwoInts(reader)

	adj := make([][]Edge, n)
	for i := 0; i < m; i++ {
		u, v, w := readThreeInts(reader)
		adj[u-1] = append(adj[u-1], Edge{v - 1, int64(w)})
		adj[v-1] = append(adj[v-1], Edge{u - 1, int64(w)})
	}

	dist := dijkstra(n, adj)

	if dist[n-1] != int64(1e18) {
		path := []int{}
		u := n - 1
		for u != 0 {
			path = append(path, u)
			for _, edge := range adj[u] {
				if dist[edge.to]+edge.weight == dist[u] {
					u = edge.to
					break
				}
			}
		}
		path = append(path, 0)
		for i := len(path) - 1; i >= 0; i-- {
			fmt.Print(path[i] + 1)
			if i > 0 {
				fmt.Print(" ")
			}
		}
	} else {
		fmt.Println(-1)
	}
}

func readTwoInts(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	return a, b
}

func readThreeInts(reader *bufio.Reader) (int, int, int) {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	c, _ := strconv.Atoi(parts[2])
	return a, b, c
}
