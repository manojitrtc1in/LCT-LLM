package main

import (
	"fmt"
	"strings"
)

const (
	N = 1000009
	M = 10009
	Z = 26
)

var (
	A    [N]int
	buf  [Z]byte
	Q    [M]int
	have = make(map[int]bool)
	ans  = make(map[int]int)
	n, m int
)

func push(x int) {
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

func main() {
	var s string
	fmt.Scanln(&s)
	n = len(s)
	for i := 0; i < n; i++ {
		A[i] = int(s[i] - 'a')
	}
	A[n] = Z

	fmt.Scanln(&m)
	for i := 0; i < m; i++ {
		fmt.Scanln(&buf)
		for _, c := range buf {
			Q[i] |= 1 << (c - 'a')
		}
		have[Q[i]] = true
	}

	for i := 0; i < n; i++ {
		push(A[i])
		s := 0
		for j := nn; j >= 0; j-- {
			s |= 1 << stk[j]
			if s&(1<<A[i+1]) != 0 {
				break
			}
			if have[s] {
				ans[s]++
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
