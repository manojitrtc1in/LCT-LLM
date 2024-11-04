package main

import (
	"fmt"
	"strings"
)

const eps = 1e-8

func getq() int {
	var buf string
	fmt.Scan(&buf)
	ret := 0
	for i := len(buf) - 1; i >= 0; i-- {
		ret |= 1 << (buf[i] - 'a')
	}
	return ret
}

func main() {
	var S [1000100]rune
	var n, m int
	fmt.Scan(&S[1])
	n = len(S[1:]) - 1 // Adjust for 1-based index

	for i := 1; i <= n; i++ {
		S[i] -= 'a'
	}

	fmt.Scan(&m)
	Q := make([]int, 10010)
	Qs := make(map[int]struct{})
	ans := make(map[int]int)

	for i := 1; i <= m; i++ {
		Q[i] = getq()
		Qs[Q[i]] = struct{}{}
	}

	stk := make([]int, 27)
	nn := 0
	vis := make([]bool, 26)

	for i := 1; i <= n; i++ {
		x := S[i]
		if !vis[x] {
			nn++
			stk[nn] = x
			vis[x] = true
		} else {
			var j int
			for j = 1; ; j++ {
				if stk[j] == x {
					break
				}
			}
			for j < nn {
				stk[j] = stk[j+1]
				j++
			}
			stk[nn] = x
		}
		t := 0
		for j := nn; j > 0; j-- {
			t |= 1 << stk[j]
			if i < n && (t&(1<<S[i+1])) != 0 {
				break
			}
			if _, exists := Qs[t]; exists {
				ans[t]++
			}
		}
	}

	for i := 1; i <= m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
