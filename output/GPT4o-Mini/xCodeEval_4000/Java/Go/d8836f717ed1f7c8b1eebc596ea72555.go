package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	FIRST_INPUT_STRING      = false
	MULTIPLE_TESTS          = true
	MAX_STACK_SIZE          = 128
	OPTIMIZE_READ_NUMBERS   = false
	MODULO                  = 1000 * 1000 * 1000 + 7
)

type Point struct {
	x, y int
}

type Triple struct {
	side, ones, twos int
}

var (
	in  *bufio.Reader
	out *bufio.Writer
)

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)

	defer out.Flush()

	n, k := readInt(), readInt()
	a := readIntArray(n)

	answer := getAnswer(n, a, k)

	fmt.Fprintln(out, answer.x)
	fmt.Fprintln(out, answer.y)
}

func getAnswer(n int, a []int, limit int) Point {
	const MULTIPLIER = 50

	limit /= MULTIPLIER

	for i := 0; i < n; i++ {
		a[i] /= MULTIPLIER
	}

	onesCount, twosCount := 0, 0
	for _, v := range a {
		if v == 1 {
			onesCount++
		} else {
			twosCount++
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
			distances[i][j] = make([]int, twosCount+1)
			ways[i][j] = make([]int64, twosCount+1)
			for k := range distances[i][j] {
				distances[i][j][k] = INF
			}
		}
	}

	distances[FROM_SIDE][onesCount][twosCount] = 0
	ways[FROM_SIDE][onesCount][twosCount] = 1

	q := []Triple{{FROM_SIDE, onesCount, twosCount}}

	for len(q) > 0 {
		from := q[0]
		q = q[1:]

		fromDistance := distances[from.side][from.ones][from.twos]
		fromWays := ways[from.side][from.ones][from.twos]
		fromNextDistance := fromDistance + 1

		nextSide := FROM_SIDE + TO_SIDE - from.side

		if from.side == FROM_SIDE {
			for deltaOnes := 0; deltaOnes <= from.ones; deltaOnes++ {
				for deltaTwos := 0; deltaTwos <= from.twos; deltaTwos++ {
					if deltaOnes+deltaTwos == 0 {
						continue
					}
					if deltaOnes+2*deltaTwos > limit {
						continue
					}

					nextOnes := from.ones - deltaOnes
					nextTwos := from.twos - deltaTwos

					nextDistance := distances[nextSide][nextOnes][nextTwos]

					if nextDistance < fromNextDistance {
						continue
					}

					fromNextWays := mult(fromWays, mult(c[from.ones][deltaOnes], c[from.twos][deltaTwos]))

					if nextDistance > fromNextDistance {
						nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance
						q = append(q, Triple{nextSide, nextOnes, nextTwos})
					}

					if nextDistance == fromNextDistance {
						ways[nextSide][nextOnes][nextTwos] = add(ways[nextSide][nextOnes][nextTwos], fromNextWays)
					}
				}
			}
		} else {
			toOnes := onesCount - from.ones
			toTwos := twosCount - from.twos

			for deltaOnes := 0; deltaOnes <= toOnes; deltaOnes++ {
				for deltaTwos := 0; deltaTwos <= toTwos; deltaTwos++ {
					if deltaOnes+deltaTwos == 0 {
						continue
					}
					if deltaOnes+2*deltaTwos > limit {
						continue
					}

					nextOnes := from.ones + deltaOnes
					nextTwos := from.twos + deltaTwos

					nextDistance := distances[nextSide][nextOnes][nextTwos]

					if nextDistance < fromNextDistance {
						continue
					}

					fromNextWays := mult(fromWays, mult(c[toOnes][deltaOnes], c[toTwos][deltaTwos]))

					if nextDistance > fromNextDistance {
						nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance
						q = append(q, Triple{nextSide, nextOnes, nextTwos})
					}

					if nextDistance == fromNextDistance {
						ways[nextSide][nextOnes][nextTwos] = add(ways[nextSide][nextOnes][nextTwos], fromNextWays)
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
	val, _ := strconv.Atoi(readString())
	return val
}

func readIntArray(size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = readInt()
	}
	return array
}

func readString() string {
	s, _ := in.ReadString('\n')
	return s[:len(s)-1]
}
