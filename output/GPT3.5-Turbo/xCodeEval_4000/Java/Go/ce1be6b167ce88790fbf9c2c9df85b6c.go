package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanInt64() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt()
	}
	return arr
}

func scanInt64Array(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt64()
	}
	return arr
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solver() {
	n := scanInt64()
	ar := scanInt64Array(3)
	br := scanInt64Array(3)
	mxWins := int64(0)
	mxLosesOrDraw := int64(0)
	draws := int64(0)
	for i := 0; i < 3; i++ {
		mxWins += min(ar[i], br[(i+1)%3])
		mxLose := min(br[i], ar[(i+1)%3])
		mxDraw := min(br[i], ar[i])
		mxLosesOrDraw += min(br[i], mxLose+mxDraw)
	}
	fmt.Fprintf(writer, "%d %d\n", n-mxLosesOrDraw, mxWins)
}

func main() {
	initIO()
	defer flush()

	solver()
}
