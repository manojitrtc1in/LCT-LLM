package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func solve() {
	n, k := readInt(), readInt()
	a := readIntArray(n)

	answer := getAnswer(n, a, k)

	fmt.Fprintln(writer, answer.X)
	fmt.Fprintln(writer, answer.Y)
}

func getAnswer(n int, a []int, limit int) Point {
	const MULTIPLIER = 50

	limit /= MULTIPLIER

	for i := 0; i < n; i++ {
		a[i] /= MULTIPLIER
	}

	onesCount := 0
	twosCount := 0
	for _, v := range a {
		if v == 1 {
			onesCount++
		} else {
			twosCount++
		}
	}

	c := make([][]int64, n+1)
	for i := 0; i <= n; i++ {
		c[i] = make([]int64, n+1)
		c[i][0] = 1
		c[i][i] = 1
		for j := 1; j < i; j++ {
			c[i][j] = add(c[i-1][j-1], c[i-1][j])
		}
	}

	const FROM_SIDE = 0
	const TO_SIDE = 1
	const INF = int(^uint(0) >> 1) / 3

	distances := make([][][]int, 2)
	for i := 0; i < 2; i++ {
		distances[i] = make([][]int, onesCount+1)
		for j := 0; j <= onesCount; j++ {
			distances[i][j] = make([]int, twosCount+1)
			for k := 0; k <= twosCount; k++ {
				distances[i][j][k] = INF
			}
		}
	}

	ways := make([][][]int64, 2)
	for i := 0; i < 2; i++ {
		ways[i] = make([][]int64, onesCount+1)
		for j := 0; j <= onesCount; j++ {
			ways[i][j] = make([]int64, twosCount+1)
		}
	}

	distances[FROM_SIDE][onesCount][twosCount] = 0
	ways[FROM_SIDE][onesCount][twosCount] = 1

	type Triple struct {
		side int
		ones int
		twos int
	}

	q := make([]Triple, 0)
	q = append(q, Triple{FROM_SIDE, onesCount, twosCount})

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

					fromNextWays := mult(fromWays,
						mult(c[from.ones][deltaOnes], c[from.twos][deltaTwos]),
					)

					if nextDistance > fromNextDistance {
						nextDistance = fromNextDistance
						distances[nextSide][nextOnes][nextTwos] = fromNextDistance
						q = append(q, Triple{nextSide, nextOnes, nextTwos})
					}

					if nextDistance == fromNextDistance {
						ways[nextSide][nextOnes][nextTwos] = add(
							ways[nextSide][nextOnes][nextTwos],
							fromNextWays,
						)
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

					fromNextWays := mult(fromWays,
						mult(c[toOnes][deltaOnes], c[toTwos][deltaTwos]),
					)

					if nextDistance > fromNextDistance {
						nextDistance = fromNextDistance
						distances[nextSide][nextOnes][nextTwos] = fromNextDistance
						q = append(q, Triple{nextSide, nextOnes, nextTwos})
					}

					if nextDistance == fromNextDistance {
						ways[nextSide][nextOnes][nextTwos] = add(
							ways[nextSide][nextOnes][nextTwos],
							fromNextWays,
						)
					}
				}
			}
		}
	}

	distance := distances[TO_SIDE][0][0]
	if INF == distance {
		return Point{-1, 0}
	} else {
		return Point{distance, ways[TO_SIDE][0][0]}
	}
}

func inverse(x int64) int64 {
	return binpow(x, MODULO-2)
}

func binpow(base, power int64) int64 {
	if power == 0 {
		return 1
	}
	if power&1 == 0 {
		half := binpow(base, power>>1)
		return mult(half, half)
	} else {
		prev := binpow(base, power-1)
		return mult(prev, base)
	}
}

func add(a, b int64) int64 {
	return (a + b) % MODULO
}

func mult(a, b int64) int64 {
	return (a * b) % MODULO
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readIntArray(size int) []int {
	scanner.Scan()
	arr := strings.Fields(scanner.Text())
	res := make([]int, size)
	for i := 0; i < size; i++ {
		res[i], _ = strconv.Atoi(arr[i])
	}
	return res
}

type Point struct {
	X int
	Y int
}

const (
	MAX_STACK_SIZE = 128
	MODULO         = 1000*1000*1000 + 7
)

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}
