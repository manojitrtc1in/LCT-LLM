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

var (
	k     int
	in    *FastScanner
	out   *FastWriter
	adj   [][]int
	e97   int64 = 1e9 + 7
)

func main() {
	in = NewFastScanner()
	out = NewFastWriter()
	solver()
	out.Flush()
}

func solver() {
	n := in.IntNext()
	k = in.IntNext()
	arr := in.NextIntArray(n)
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
		if count.count >= k {
			ans = min(ans, count.cost)
		}
	}
	out.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

type FastWriter struct {
	out *bufio.Writer
}

func NewFastWriter() *FastWriter {
	return &FastWriter{bufio.NewWriter(os.Stdout)}
}

func (w *FastWriter) Println(a ...interface{}) {
	fmt.Fprintln(w.out, a...)
}

func (w *FastWriter) Flush() {
	w.out.Flush()
}

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &FastScanner{scanner}
}

func (s *FastScanner) IntNext() int {
	s.scanner.Scan()
	num, _ := strconv.Atoi(s.scanner.Text())
	return num
}

func (s *FastScanner) NextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = s.IntNext()
	}
	return arr
}

func (s *FastScanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *FastScanner) LongNext() int64 {
	s.scanner.Scan()
	num, _ := strconv.ParseInt(s.scanner.Text(), 10, 64)
	return num
}
