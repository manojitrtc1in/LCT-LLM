package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	in := NewFastScanner()

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
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type FastScanner struct {
	data []string
	index int
}

func NewFastScanner() *FastScanner {
	data, _ := ioutil.ReadAll(os.Stdin)
	return &FastScanner{data: strings.Fields(string(data)), index: 0}
}

func (fs *FastScanner) Next() string {
	if fs.index >= len(fs.data) {
		return ""
	}
	result := fs.data[fs.index]
	fs.index++
	return result
}
