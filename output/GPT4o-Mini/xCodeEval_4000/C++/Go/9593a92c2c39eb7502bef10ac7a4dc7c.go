package main

import (
	"fmt"
	"strings"
)

const MAXN = 1000100

var S [MAXN]rune
var n, m int
var Q [10010]int
var Qs = make(map[int]struct{})
var ans = make(map[int]int)

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
	fmt.Scan(&S[1])
	n = len(S[1:]) // Adjust for 1-based index
	for i := 1; i <= n; i++ {
		S[i] -= 'a'
	}
	S[n+1] = 31 // Set the end character

	fmt.Scan(&m)
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
			if (t & (1 << S[i+1])) != 0 {
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
