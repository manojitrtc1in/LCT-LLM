package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func touchPos(r, c, d int, len []int, dist [][]int, q *[]int) (int, int) {
	pos := []int{r, min(c, len[r])}
	if d < dist[r][pos[1]] {
		dist[r][pos[1]] = d
		*q = append(*q, pos...)
	}
	return pos[0], pos[1]
}

func c253() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	readInt := func() int {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		return val
	}

	readInts := func(n int) []int {
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			arr[i] = readInt()
		}
		return arr
	}

	len := readInts(5)
	first := []int{readInt(), readInt()}
	last := []int{readInt(), readInt()}

	makePos := func(a, b int) []int {
		return []int{a - 1, min(b-1, len[a-1])}
	}

	first = makePos(first[0], first[1])
	last = makePos(last[0], last[1])

	if first[0] == last[0] && first[1] == last[1] {
		fmt.Println(0)
		return
	}

	INF := int(1e9)
	dist := make([][]int, 5)
	for i := 0; i < 5; i++ {
		dist[i] = make([]int, len[i]+1)
		for j := 0; j <= len[i]; j++ {
			dist[i][j] = INF
		}
	}

	q := make([]int, 0)
	q = append(q, first...)
	dist[first[0]][first[1]] = 0

	for len(q) > 0 {
		r, c := q[0], q[1]
		q = q[2:]

		d := dist[r][c] + 1

		if r > 0 && last[0] == touchPos(r-1, c, d, len, dist, &q) {
			break
		}

		if r < 4 && last[0] == touchPos(r+1, c, d, len, dist, &q) {
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	c253()
}
