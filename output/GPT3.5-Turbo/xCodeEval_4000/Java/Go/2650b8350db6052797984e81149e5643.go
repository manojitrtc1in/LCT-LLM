package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *FastScanner
var out *FastWriter

func main() {
	in = NewFastScanner()
	out = NewFastWriter()

	lng := in.Next()
	sht := in.Next()
	n := len(lng)
	m := len(sht)
	leftmost := make([]int, m+1)
	rightmost := make([]int, m+1)
	rightmost[m] = n

	idx := 0
	for i := 0; i < m; i++ {
		for sht[i] != lng[idx] {
			idx++
		}
		leftmost[i] = idx
		idx++
	}
	idx = n - 1
	for i := m - 1; i >= 0; i-- {
		for sht[i] != lng[idx] {
			idx--
		}
		rightmost[i] = idx
		idx--
	}

	ans := rightmost[0]
	for i := 0; i < m; i++ {
		ans = max(ans, rightmost[i+1]-leftmost[i]-1)
	}
	out.Println(ans)

	out.Flush()
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

func (s *FastScanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
