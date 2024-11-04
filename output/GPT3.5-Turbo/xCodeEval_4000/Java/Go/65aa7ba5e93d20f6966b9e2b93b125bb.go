package main

import (
	"bufio"
	"fmt"
	"os"
)

var MOD int64 = int64(1e9 + 7)
var MOD2 int64 = MOD * MOD

func main() {
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve(out)
}

func solve(out *bufio.Writer) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	s := sc.Text()
	t := sc.Text()
	n := len(s)
	m := len(t)
	pre := make([]int, m)
	suf := make([]int, m)

	for i, j := 0, 0; i < m; i++ {
		for s[j] != t[i] {
			j++
		}
		pre[i] = j
		j++
	}

	for i, j := m-1, n-1; i >= 0; i-- {
		for s[j] != t[i] {
			j--
		}
		suf[i] = j
		j--
	}

	ans := max(suf[0], n-1-pre[m-1])
	for i := 0; i < m-1; i++ {
		ans = max(ans, suf[i+1]-1-pre[i])
	}

	fmt.Fprintln(out, ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
