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

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func main() {
	defer writer.Flush()
	solve()
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextStrings(n int) []string {
	result := make([]string, n)
	for i := 0; i < n; i++ {
		result[i] = nextString()
	}
	return result
}

func nextInt() int {
	s := nextString()
	n, _ := strconv.Atoi(s)
	return n
}

func nextInts(n int) []int {
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = nextInt()
	}
	return result
}

func nextLong() int64 {
	s := nextString()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

func nextLongs(n int) []int64 {
	result := make([]int64, n)
	for i := 0; i < n; i++ {
		result[i] = nextLong()
	}
	return result
}

func solve() {
	n := nextInt()
	d := nextInts(n)
	fmt.Fprintln(writer, solveE418(d))
}

func solveE418(d []int) int64 {
	BIG := int64(1000000007)
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

func next(d, count int, p1, p2, c1, c2 int, result [][][][]int64) {
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
