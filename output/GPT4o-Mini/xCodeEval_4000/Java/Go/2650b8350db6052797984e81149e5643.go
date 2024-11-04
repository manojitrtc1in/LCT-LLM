package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)

	lng, _ := in.ReadString('\n')
	sht, _ := in.ReadString('\n')

	n := len(lng) - 1 // Exclude newline character
	m := len(sht) - 1 // Exclude newline character
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
