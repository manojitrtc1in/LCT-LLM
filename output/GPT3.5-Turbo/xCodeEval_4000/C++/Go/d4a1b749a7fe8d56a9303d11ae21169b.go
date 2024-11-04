package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = INF + 7
	EPS   = 1e-9
	PI    = acos(-1.0)

	N  = 1000*1000 + 13
	AL = 26
)

var (
	n     int
	s     string
	m     int
	t     []int
	nxt   [][]int
	cnt   []int
	mx    []int
	masks map[int]int
)

func read() bool {
	scanner := bufio.NewScanner(os.Stdin)

	if !scanner.Scan() {
		return false
	}
	s = scanner.Text()
	n = len(s)

	scanner.Scan()
	m, _ = strconv.Atoi(scanner.Text())

	t = make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		tmp := scanner.Text()
		x := 0
		for j := 0; j < len(tmp); j++ {
			x |= (1 << (tmp[j] - 'a'))
		}
		t[i] = x
	}

	return true
}

func solve() {
	nxt = make([][]int, n+1)
	for i := 0; i <= n; i++ {
		nxt[i] = make([]int, AL)
		for j := 0; j < AL; j++ {
			nxt[i][j] = n
		}
	}

	for i := n - 1; i >= 0; i-- {
		for j := 0; j < AL; j++ {
			nxt[i][j] = nxt[i+1][j]
		}
		nxt[i][s[i]-'a'] = i
	}

	masks = make(map[int]int)
	cnt = make([]int, m)
	mx = make([]int, m)
	for i := 0; i < m; i++ {
		if _, ok := masks[t[i]]; !ok {
			k := len(masks)
			masks[t[i]] = k
		}
	}

	for i := 0; i < n; i++ {
		lst := i
		cur := (1 << (s[lst] - 'a'))
		for {
			mn := n
			for j := 0; j < AL; j++ {
				if (cur>>j)&1 == 0 {
					mn = min(mn, nxt[lst][j])
				}
			}
			if _, ok := masks[cur]; ok {
				x := masks[cur]
				if mx[x] != mn-1 {
					mx[x] = mn - 1
					cnt[x]++
				}
			}
			if mn == n {
				break
			}
			lst = mn
			cur |= (1 << (s[lst] - 'a'))
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(cnt[masks[t[i]]])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for read() {
		solve()
	}
}
