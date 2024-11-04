package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *FastScanner
var out *FastWriter

type FastWriter struct {
	out *bufio.Writer
}

func NewFastWriter() *FastWriter {
	return &FastWriter{out: bufio.NewWriter(os.Stdout)}
}

func (w *FastWriter) p(a ...interface{}) {
	fmt.Fprint(w.out, a...)
}

func (w *FastWriter) pp(a ...interface{}) {
	for _, v := range a {
		fmt.Fprint(w.out, v, " ")
	}
	fmt.Fprintln(w.out)
}

func (w *FastWriter) println(a ...interface{}) {
	fmt.Fprintln(w.out, a...)
}

func (w *FastWriter) toFile(fileName string) error {
	file, err := os.Create(fileName)
	if err != nil {
		return err
	}
	defer file.Close()

	w.out.Flush()
	_, err = file.WriteString(w.out.String())
	return err
}

func (w *FastWriter) close() {
	w.out.Flush()
}

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (s *FastScanner) scan() bool {
	return s.scanner.Scan()
}

func (s *FastScanner) text() string {
	return s.scanner.Text()
}

func (s *FastScanner) next() string {
	s.scan()
	return s.text()
}

func (s *FastScanner) intNext() int {
	return parseInt(s.next())
}

func (s *FastScanner) longNext() int64 {
	return parseLong(s.next())
}

func (s *FastScanner) doubleNext() float64 {
	return parseDouble(s.next())
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func parseLong(s string) int64 {
	var res int64
	for _, c := range s {
		res = res*10 + int64(c-'0')
	}
	return res
}

func parseDouble(s string) float64 {
	var res float64
	var decimal bool
	var decimalCount int
	for _, c := range s {
		if c == '.' {
			decimal = true
			continue
		}
		if decimal {
			res += float64(c-'0') / pow10(decimalCount)
			decimalCount++
		} else {
			res = res*10 + float64(c-'0')
		}
	}
	return res
}

func pow10(n int) float64 {
	res := 1.0
	for i := 0; i < n; i++ {
		res *= 10
	}
	return res
}

func main() {
	in = NewFastScanner()
	out = NewFastWriter()

	lng := in.next()
	sht := in.next()
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
	out.println(ans)

	out.close()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	// Your code here
}
