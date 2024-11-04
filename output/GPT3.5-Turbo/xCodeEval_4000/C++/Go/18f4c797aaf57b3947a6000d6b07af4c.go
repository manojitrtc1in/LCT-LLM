package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	N = 1000009
	M = 10009
	Z = 26
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	A, _ := reader.ReadString('\n')
	A = strings.TrimRight(A, "\n")
	n := len(A)
	A = A[:n-1]
	A = strings.ReplaceAll(A, " ", "")

	m, _ := strconv.Atoi(A)
	Q := make([]int, m)
	have := make(map[int]bool)
	ans := make(map[int]int)

	for i := 0; i < m; i++ {
		buf, _ := reader.ReadString('\n')
		buf = strings.TrimRight(buf, "\n")
		buf = strings.ReplaceAll(buf, " ", "")
		for _, ch := range buf {
			Q[i] |= 1 << (ch - 'a')
		}
		have[Q[i]] = true
	}

	stk := make([]int, Z)
	nn := 0
	vis := make([]bool, Z)

	push := func(x int) {
		if !vis[x] {
			vis[x] = true
			stk[nn] = x
			nn++
		} else {
			var j int
			for j = 0; ; j++ {
				if stk[j] == x {
					break
				}
			}
			for ; j < nn-1; j++ {
				stk[j] = stk[j+1]
			}
			stk[nn-1] = x
		}
	}

	for i := 0; i < n; i++ {
		push(int(A[i] - 'a'))
		s := 0
		for j := nn; j >= 0; j-- {
			s |= 1 << stk[j]
			if s&(1<<(A[i+1]-'a')) != 0 {
				break
			}
			if _, ok := have[s]; ok {
				ans[s]++
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Fprintln(writer, ans[Q[i]])
	}
}
