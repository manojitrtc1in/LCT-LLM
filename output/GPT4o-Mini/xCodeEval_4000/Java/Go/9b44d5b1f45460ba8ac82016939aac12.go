package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

const BIG = 1000000007

var (
	POWER2      = generatePOWER2()
	FACULTY_BIG = generateFacultyBig()
)

func generatePOWER2() []int64 {
	result := make([]int64, 63)
	for x := 0; x < len(result); x++ {
		result[x] = 1 << x
	}
	return result
}

func generateFacultyBig() []*big.Int {
	result := make([]*big.Int, 50)
	for x := 0; x < len(result); x++ {
		result[x] = facultyBig(x)
	}
	return result
}

func facultyBig(n int) *big.Int {
	result := big.NewInt(1)
	for index := 2; index <= n; index++ {
		result.Mul(result, big.NewInt(int64(index)))
	}
	return result
}

func add(p1, p2, c1, c2 int, count int64, result [][][][]int64) {
	if p1 >= 0 && p2 >= 0 && c1 >= 0 && c2 >= 0 && count > 0 {
		if p1 < len(result) && p2 < len(result[p1]) && c1 < len(result[p1][p2]) && c2 < len(result[p1][p2][c1]) {
			result[p1][p2][c1][c2] += count
		}
	}
}

func addPrevious(p1, p2, c1, c2 int, count int64, result [][][][]int64) {
	add(p1-1, p2, c1, c2, int64(p1)*count, result)
	add(p1+1, p2-1, c1, c2, int64(p2)*count, result)
}

func next(d int, count int64, p1, p2, c1, c2 int, result [][][][]int64) {
	if p1 == 0 && p2 == 0 {
		if d == 2 {
			addPrevious(c1, c2, 1, 0, count, result)
		} else {
			addPrevious(c1, c2, 0, 1, count, result)
		}
	}

	if d == 2 {
		addPrevious(p1, p2, c1+1, c2, count, result)
		addPrevious(p1, p2, c1-1, c2, int64(c1)*count, result)
		addPrevious(p1, p2, c1+1, c2-1, int64(c2)*count, result)
	} else {
		addPrevious(p1, p2, c1, c2+1, count, result)
		addPrevious(p1, p2, c1, c2, int64(c1)*count, result)
		addPrevious(p1, p2, c1+2, c2-1, int64(c2)*count, result)
		addPrevious(p1, p2, c1-2, c2, int64(c1*(c1-1)/2)*count, result)
		addPrevious(p1, p2, c1, c2-1, int64(c1*c2)*count, result)
		addPrevious(p1, p2, c1+2, c2-2, int64(c2*(c2-1)/2)*count, result)
	}
}

func solve(d []int) int64 {
	count := make([][][][]int64, len(d)/2+1)
	for i := range count {
		count[i] = make([][][]int64, len(d)/2+1)
		for j := range count[i] {
			count[i][j] = make([][]int64, len(d)/2+1)
			for k := range count[i][j] {
				count[i][j][k] = make([]int64, len(d)/2+1)
			}
		}
	}

	if d[0] == 2 {
		if d[1] == 2 {
			count[1][0][1][0] = 1
		} else {
			count[1][0][0][1] = 1
		}
	} else {
		if d[1] == 2 {
			count[0][1][1][0] = 1
		} else {
			count[0][1][0][1] = 1
		}
	}

	for u := 2; u < len(d); u++ {
		countNext := make([][][][]int64, len(d)/2+1)
		for i := range countNext {
			countNext[i] = make([][][]int64, len(d)/2+1)
			for j := range countNext[i] {
				countNext[i][j] = make([][]int64, len(d)/2+1)
				for k := range countNext[i][j] {
					countNext[i][j][k] = make([]int64, len(d)/2+1)
				}
			}
		}

		for p1 := 0; p1 <= len(d)/2; p1++ {
			for p2 := 0; p2 <= len(d)/2 && p1+p2 < len(d); p2++ {
				for c1 := 0; c1 <= len(d)/2 && p1+p2+c1 < len(d); c1++ {
					for c2 := 0; c2 <= len(d)/2 && p1+p2+c1+c2 < len(d); c2++ {
						next(d[u], count[p1][p2][c1][c2]%BIG, p1, p2, c1, c2, countNext)
					}
				}
			}
		}
		count = countNext
	}
	return count[0][0][0][0] % BIG
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	d := readInts(reader, n)
	fmt.Println(solve(d))
}

func readInt(reader *bufio.Reader) int {
	var n int
	fmt.Fscan(reader, &n)
	return n
}

func readInts(reader *bufio.Reader, n int) []int {
	result := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &result[i])
	}
	return result
}
