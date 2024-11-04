package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const MODULO = 1000 * 1000 * 1000 + 7

type Point struct {
	x, y int
}

type Triple struct {
	side, ones, twos int
}

var (
	id3   = false
	id6   = true
	id10  = !fileExists("input.txt")
	id17  = 128
	id30  = false
	rnd   = rand.New(rand.NewSource(time.Now().UnixNano()))
	fileName = ""
)

func main() {
	if id10 {
		solve()
	} else {
		for {
			if err := solve(); err != nil {
				break
			}
		}
	}
}

func solve() error {
	n := readInt()
	k := readInt()
	a := readIntArray(n)

	answer := getAnswer(n, a, k)

	fmt.Println(answer.x)
	fmt.Println(answer.y)
	return nil
}

func getAnswer(n int, a []int, limit int) Point {
	const id22 = 50
	limit /= id22

	for i := 0; i < n; i++ {
		a[i] /= id22
	}

	onesCount, id33 := 0, 0
	for _, v := range a {
		if v == 1 {
			onesCount++
		} else {
			id33++
		}
	}

	c := make([][]int64, n+1)
	for i := range c {
		c[i] = make([]int64, n+1)
	}
	for i := 0; i <= n; i++ {
		c[i][0] = 1
		c[i][i] = 1
		for j := 1; j < i; j++ {
			c[i][j] = add(c[i-1][j-1], c[i-1][j])
		}
	}

	const (
		FROM_SIDE = 0
		TO_SIDE   = 1
		INF       = math.MaxInt32 / 3
	)

	distances := make([][][]int, 2)
	ways := make([][][]int64, 2)
	for i := range distances {
		distances[i] = make([][]int, onesCount+1)
		ways[i] = make([][]int64, onesCount+1)
		for j := range distances[i] {
			distances[i][j] = make([]int, id33+1)
			ways[i][j] = make([]int64, id33+1)
			for k := range distances[i][j] {
				distances[i][j][k] = INF
			}
		}
	}

	distances[FROM_SIDE][onesCount][id33] = 0
	ways[FROM_SIDE][onesCount][id33] = 1

	q := []Triple{{FROM_SIDE, onesCount, id33}}

	for len(q) > 0 {
		from := q[0]
		q = q[1:]

		fromDistance := distances[from.side][from.ones][from.twos]
		fromWays := ways[from.side][from.ones][from.twos]
		id39 := fromDistance + 1

		nextSide := FROM_SIDE + TO_SIDE - from.side

		if from.side == FROM_SIDE {
			for id44 := 0; id44 <= from.ones; id44++ {
				for id45 := 0; id45 <= from.twos; id45++ {
					if id44+id45 == 0 || id44+2*id45 > limit {
						continue
					}

					id24 := from.ones - id44
					id32 := from.twos - id45

					nextDistance := distances[nextSide][id24][id32]

					if nextDistance < id39 {
						continue
					}

					id23 := mult(fromWays, mult(c[from.ones][id44], c[from.twos][id45]))

					if nextDistance > id39 {
						nextDistance = distances[nextSide][id24][id32] = id39
						q = append(q, Triple{nextSide, id24, id32})
					}

					if nextDistance == id39 {
						ways[nextSide][id24][id32] = add(ways[nextSide][id24][id32], id23)
					}
				}
			}
		} else {
			id34 := onesCount - from.ones
			id12 := id33 - from.twos

			for id44 := 0; id44 <= id34; id44++ {
				for id45 := 0; id45 <= id12; id45++ {
					if id44+id45 == 0 || id44+2*id45 > limit {
						continue
					}

					id24 := from.ones + id44
					id32 := from.twos + id45

					nextDistance := distances[nextSide][id24][id32]

					if nextDistance < id39 {
						continue
					}

					id23 := mult(fromWays, mult(c[id34][id44], c[id12][id45]))

					if nextDistance > id39 {
						nextDistance = distances[nextSide][id24][id32] = id39
						q = append(q, Triple{nextSide, id24, id32})
					}

					if nextDistance == id39 {
						ways[nextSide][id24][id32] = add(ways[nextSide][id24][id32], id23)
					}
				}
			}
		}
	}

	distance := distances[TO_SIDE][0][0]
	if INF == distance {
		return Point{-1, 0}
	} else {
		return Point{distance, int(ways[TO_SIDE][0][0])}
	}
}

func add(a, b int64) int64 {
	return (a + b) % MODULO
}

func mult(a, b int64) int64 {
	return (a * b) % MODULO
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func readIntArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = readInt()
	}
	return arr
}

func fileExists(filename string) bool {
	_, err := os.Stat(filename)
	return !os.IsNotExist(err)
}
