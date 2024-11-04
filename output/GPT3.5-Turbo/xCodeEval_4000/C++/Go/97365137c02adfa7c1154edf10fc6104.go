package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF = 1e9
	LINF = 1e18
	M = 1e9 + 7
	C = 20
)

var (
	G [C][]int
	cur []int
	masks [C]int
	dp [1 << C]bool
	vis [C]bool
	mask int
)

func dfs(v int) {
	vis[v] = true
	mask |= 1 << v
	cur = append(cur, v)

	for _, s := range G[v] {
		if !vis[s] {
			dfs(s)
		}
	}
}

func count() int {
	var sub []int
	m := mask
	for m > 0 {
		sub = append(sub, m)
		m = (m - 1) & mask
	}
	for i := len(sub) - 1; i >= 0; i-- {
		m := sub[i]
		for _, v := range cur {
			if m&(1<<v) != 0 {
				dp[m] = dp[m^(1<<v)] && ((m&masks[v]&mask) == 0)
			}
		}
		if dp[m] {
			return strings.Count(strconv.FormatInt(int64(m), 2), "1")
		}
	}
	return 0
}

func solve() int {
	n := scanInt()
	s := scanString()
	t := scanString()

	get := func(c byte) int {
		return int(c - 'a')
	}

	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(s[i])
			b := get(t[i])
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			masks[a] |= 1 << b
		}
	}

	res := 0
	dp[0] = true
	for i := 0; i < C; i++ {
		if !vis[i] {
			mask = 0
			cur = []int{}
			dfs(i)
			tmp := count()
			res += 2*len(cur) - 1 - tmp
		}
	}

	for i := 0; i < C; i++ {
		vis[i] = false
		masks[i] = 0
		G[i] = []int{}
		dp[i] = false
	}

	return res
}

func main() {
	t := scanInt()
	for t > 0 {
		fmt.Println(solve())
		t--
	}
}

// Helper functions
var scanner = bufio.NewScanner(os.Stdin)

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func scanInt() int {
	i, _ := strconv.Atoi(scanString())
	return i
}
