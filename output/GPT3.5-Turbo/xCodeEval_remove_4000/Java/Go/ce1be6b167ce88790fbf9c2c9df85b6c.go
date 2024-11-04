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

func nextInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func nextLong() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solver() {
	n := nextLong()
	ar := make([]int64, 3)
	br := make([]int64, 3)
	for i := 0; i < 3; i++ {
		ar[i] = nextLong()
	}
	for i := 0; i < 3; i++ {
		br[i] = nextLong()
	}
	mxWins := int64(0)
	id19 := int64(0)
	draws := int64(0)
	for i := 0; i < 3; i++ {
		mxWins += min(ar[i], br[(i+1)%3])
		mxLose := min(br[i], ar[(i+1)%3])
		mxDraw := min(br[i], ar[i])
		id19 += min(br[i], mxLose+mxDraw)
	}
	println(n-id19, mxWins)
}

func main() {
	initIO()
	solver()
	flush()
}
