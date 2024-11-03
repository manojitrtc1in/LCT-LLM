package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readString())
	return num
}

func readInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = readInt()
	}
	return arr
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
						next(d[u], count[p1][p2][c1][c2], p1, p2, c1, c2, countNext)
					}
				}
			}
		}

		count = countNext
	}

	return count[0][0][0][0] % 1000000007
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

func next(d, count, p1, p2, c1, c2 int, result [][][][]int64) {
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

		addPrevious(p1, p2, c1-2, c2, int64(c1)*(int64(c1)-1)/2*count, result)
		addPrevious(p1, p2, c1, c2-1, int64(c1)*int64(c2)*count, result)
		addPrevious(p1, p2, c1+2, c2-2, int64(c2)*(int64(c2)-1)/2*count, result)
	}
}

func main() {
	initIO()
	defer flush()

	n := readInt()
	d := readInts(n)

	fmt.Println(solve(d))
}
