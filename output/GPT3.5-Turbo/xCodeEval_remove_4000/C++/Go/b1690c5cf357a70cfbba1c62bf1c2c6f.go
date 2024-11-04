package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)
	n := len(S)
	S = strings.ToLower(S)
	var m int
	fmt.Scan(&m)
	Q := make([]int, m)
	Qs := make(map[int]bool)
	ans := make(map[int]int)
	for i := 0; i < m; i++ {
		Q[i] = getq()
		Qs[Q[i]] = true
	}
	stk := make([]int, 27)
	nn := 0
	vis := make([]bool, 26)
	for i := 0; i < 26; i++ {
		vis[i] = false
	}
	for i := 0; i < n; i++ {
		x := int(S[i] - 'a')
		if !vis[x] {
			nn++
			stk[nn] = x
			vis[x] = true
		} else {
			j := 0
			for j = 1; j <= nn; j++ {
				if stk[j] == x {
					break
				}
			}
			for ; j < nn; j++ {
				stk[j] = stk[j+1]
			}
			stk[nn] = x
		}
		t := 0
		for j := nn; j >= 1; j-- {
			t |= 1 << stk[j]
			if i < n-1 && (t&(1<<int(S[i+1]-'a'))) != 0 {
				break
			}
			if Qs[t] {
				ans[t]++
			}
		}
	}
	for i := 0; i < m; i++ {
		fmt.Println(ans[Q[i]])
	}
}

func getq() int {
	var buf string
	fmt.Scan(&buf)
	ret := 0
	for i := len(buf) - 1; i >= 0; i-- {
		ret |= 1 << (buf[i] - 'a')
	}
	return ret
}
