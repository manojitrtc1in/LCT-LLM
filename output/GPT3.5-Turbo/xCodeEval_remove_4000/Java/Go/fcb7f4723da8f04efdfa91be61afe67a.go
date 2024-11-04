package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Count struct {
	count int
	cost  int64
}

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (fs *FastScanner) Next() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	num, _ := strconv.Atoi(fs.Next())
	return num
}

func (fs *FastScanner) NextInt64() int64 {
	num, _ := strconv.ParseInt(fs.Next(), 10, 64)
	return num
}

func (fs *FastScanner) NextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.NextInt()
	}
	return arr
}

func (fs *FastScanner) NextInt64Array(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.NextInt64()
	}
	return arr
}

type FastWriter struct {
	writer *bufio.Writer
}

func NewFastWriter() *FastWriter {
	return &FastWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (fw *FastWriter) Println(a ...interface{}) {
	fmt.Fprintln(fw.writer, a...)
}

func (fw *FastWriter) Close() {
	fw.writer.Flush()
}

func main() {
	scanner := NewFastScanner()
	writer := NewFastWriter()

	var d D
	d.solver(scanner, writer)

	writer.Close()
}

type D struct {
	k int
}

func (d *D) solver(scanner *FastScanner, writer *FastWriter) {
	n := scanner.NextInt()
	d.k = scanner.NextInt()
	arr := scanner.NextIntArray(n)
	sort.Ints(arr)

	counts := make(map[int]Count)
	counts[0] = Count{}
	for _, number := range arr {
		num := number
		cost := int64(0)
		for num > 0 {
			if _, ok := counts[num]; !ok {
				counts[num] = Count{}
			}
			counts[num].increment(cost)
			num = num / 2
			cost++
		}
		counts[0].increment(cost)
	}

	ans := int64(1<<63 - 1)
	for _, count := range counts {
		if count.count >= d.k {
			ans = min(ans, count.cost)
		}
	}

	writer.Println(ans)
}

func (c *Count) increment(cost int64) {
	if c.count >= 0 {
		return
	}
	c.cost += cost
	c.count++
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
