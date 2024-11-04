package main

import (
	"fmt"
	"math"
	"sort"
)

func touchPos(r, c, d int, len []int, dist [][]int, q *[]int) (int, int) {
	pos := []int{r, int(math.Min(float64(c), float64(len[r])))}
	if d < dist[r][pos[1]] {
		dist[r][pos[1]] = d
		*q = append(*q, pos...)
	}
	return pos[0], pos[1]
}

func c253() {
	var n int
	fmt.Scan(&n)

	len := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&len[i])
	}

	var first, last []int
	fmt.Scan(&first)
	fmt.Scan(&last)

	first[0]--
	first[1]--
	last[0]--
	last[1]--

	if first[0] == last[0] && first[1] == last[1] {
		fmt.Println(0)
		return
	}

	INF := math.MaxInt32
	dist := make([][]int, n)
	for i := 0; i < n; i++ {
		dist[i] = make([]int, len[i]+1)
		for j := 0; j <= len[i]; j++ {
			dist[i][j] = INF
		}
	}

	q := make([]int, 0)
	firstPos := []int{first[0], int(math.Min(float64(first[1]), float64(len[first[0]])))}
	q = append(q, firstPos...)
	dist[first[0]][firstPos[1]] = 0

	for len(q) > 0 {
		r := q[0]
		c := q[1]
		d := dist[r][c] + 1
		q = q[2:]

		if r > 0 && last[0] == touchPos(r-1, c, d, len, dist, &q) {
			break
		}

		if r+1 < n && last[0] == touchPos(r+1, c, d, len, dist, &q) {
			break
		}

		if c > 0 && last[0] == touchPos(r, c-1, d, len, dist, &q) {
			break
		}

		if c < len[r] && last[0] == touchPos(r, c+1, d, len, dist, &q) {
			break
		}
	}

	fmt.Println(dist[last[0]][last[1]])
}

func main() {
	c253()
}
