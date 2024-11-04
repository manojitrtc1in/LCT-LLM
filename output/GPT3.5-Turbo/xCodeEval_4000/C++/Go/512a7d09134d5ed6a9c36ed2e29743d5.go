package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	n := len(s)
	m := len(t)

	front := make([]int, m)
	back := make([]int, m)
	pos := 0
	for i := 0; i < m; i++ {
		front[i] = strings.Index(s[pos:], string(t[i])) + pos
		pos = front[i] + 1
	}
	pos = n - 1
	for i := m - 1; i >= 0; i-- {
		back[i] = strings.LastIndex(s[:pos+1], string(t[i]))
		pos = back[i] - 1
	}

	ans := max(back[0], n-1-front[m-1])
	for i := 0; i < m-1; i++ {
		if back[i+1]-front[i]-1 > ans {
			ans = back[i+1] - front[i] - 1
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
