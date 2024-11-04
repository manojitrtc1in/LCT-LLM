package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	x int
	y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	k := nextInt(scanner)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(scanner)
	}

	answer := getAnswer(n, a, k)

	fmt.Println(answer.x)
	fmt.Println(answer.y)
}

func getAnswer(n int, a []int, limit int) Point {
	id22 := 50
	limit /= id22

	for i := 0; i < n; i++ {
		a[i] /= id22
	}

	onesCount := 0
	id33 := 0
	for _, v := range a {
		if v == 1 {
			onesCount++
		} else {
			id33++
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

	FROM_SIDE := 0
	TO_SIDE := 1
	INF := int(^uint(0) >> 1) / 3

	distances := make([][][]int, 2)
	for i := 0; i < 2; i++ {
		distances[i] = make([][]int, onesCount+1)
		for j := 0; j <= onesCount; j++ {
			distances[i][j] = make([]int, id33+1)
			for k := 0; k <= id33; k++ {
				distances[i][j][k] = INF
			}
		}
	}

	ways := make([][][]int64, 2)
	for i := 0; i < 2; i++ {
		ways[i] = make([][]int64, onesCount+1)
		for j := 0; j <= onesCount; j++ {
			ways[i][j] = make([]int64, id33+1)
		}
	}

	distances[FROM_SIDE][onesCount][id33] = 0
	ways[FROM_SIDE][onesCount][id33] = 1

	type Triple struct {
		side int
		ones int
		twos int
	}

	q := make([]Triple, 0)
	q = append(q, Triple{FROM_SIDE, onesCount, id33})

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
					if id44+id45 == 0 {
						continue
					}
					if id44+2*id45 > limit {
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
						nextDistance = id39
						distances[nextSide][id24][id32] = id39
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
					if id44+id45 == 0 {
						continue
					}
					if id44+2*id45 > limit {
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
						nextDistance = id39
						distances[nextSide][id24][id32] = id39
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

func inverse(x int64) int64 {
	return binpow(x, MODULO-2)
}

func binpow(base int64, power int64) int64 {
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

func add(a int64, b int64) int64 {
	return (a + b) % MODULO
}

func mult(a int64, b int64) int64 {
	return (a * b) % MODULO
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

const MODULO = 1000*1000*1000 + 7

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func nextStringArray(scanner *bufio.Scanner, n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextString(scanner)
	}
	return arr
}

func nextIntArray(scanner *bufio.Scanner, n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt(scanner)
	}
	return arr
}

func nextInt64Array(scanner *bufio.Scanner, n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64(scanner)
	}
	return arr
}

func nextFloat64(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func nextFloat64Array(scanner *bufio.Scanner, n int) []float64 {
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextFloat64(scanner)
	}
	return arr
}

func nextChar(scanner *bufio.Scanner) byte {
	scanner.Scan()
	return scanner.Bytes()[0]
}

func nextCharArray(scanner *bufio.Scanner, n int) []byte {
	arr := make([]byte, n)
	for i := 0; i < n; i++ {
		arr[i] = nextChar(scanner)
	}
	return arr
}

func nextBool(scanner *bufio.Scanner) bool {
	scanner.Scan()
	num, _ := strconv.ParseBool(scanner.Text())
	return num
}

func nextBoolArray(scanner *bufio.Scanner, n int) []bool {
	arr := make([]bool, n)
	for i := 0; i < n; i++ {
		arr[i] = nextBool(scanner)
	}
	return arr
}

func nextPoint(scanner *bufio.Scanner) Point {
	x := nextInt(scanner)
	y := nextInt(scanner)
	return Point{x, y}
}

func nextPointArray(scanner *bufio.Scanner, n int) []Point {
	arr := make([]Point, n)
	for i := 0; i < n; i++ {
		arr[i] = nextPoint(scanner)
	}
	return arr
}

func nextIntArray2D(scanner *bufio.Scanner, n, m int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextIntArray(scanner, m)
	}
	return arr
}

func nextInt64Array2D(scanner *bufio.Scanner, n, m int) [][]int64 {
	arr := make([][]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt64Array(scanner, m)
	}
	return arr
}

func nextFloat64Array2D(scanner *bufio.Scanner, n, m int) [][]float64 {
	arr := make([][]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextFloat64Array(scanner, m)
	}
	return arr
}

func nextCharArray2D(scanner *bufio.Scanner, n, m int) [][]byte {
	arr := make([][]byte, n)
	for i := 0; i < n; i++ {
		arr[i] = nextCharArray(scanner, m)
	}
	return arr
}

func nextBoolArray2D(scanner *bufio.Scanner, n, m int) [][]bool {
	arr := make([][]bool, n)
	for i := 0; i < n; i++ {
		arr[i] = nextBoolArray(scanner, m)
	}
	return arr
}

func nextStringArray2D(scanner *bufio.Scanner, n, m int) [][]string {
	arr := make([][]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextStringArray(scanner, m)
	}
	return arr
}

func nextPointArray2D(scanner *bufio.Scanner, n, m int) [][]Point {
	arr := make([][]Point, n)
	for i := 0; i < n; i++ {
		arr[i] = nextPointArray(scanner, m)
	}
	return arr
}

func add(a int64, b int64) int64 {
	return (a + b) % MODULO
}

func mult(a int64, b int64) int64 {
	return (a * b) % MODULO
}

func gcd(a int64, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func lcm(a int64, b int64) int64 {
	return a / gcd(a, b) * b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Your code here
}
