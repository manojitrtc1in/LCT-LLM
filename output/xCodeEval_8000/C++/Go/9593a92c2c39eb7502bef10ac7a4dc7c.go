package main

import (
	"fmt"
	"strings"
)

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
	var S string
	fmt.Scan(&S)
	n := len(S)
	S = strings.ReplaceAll(S, "a", "")
	S = strings.ReplaceAll(S, "b", "")
	S = strings.ReplaceAll(S, "c", "")
	S = strings.ReplaceAll(S, "d", "")
	S = strings.ReplaceAll(S, "e", "")
	S = strings.ReplaceAll(S, "f", "")
	S = strings.ReplaceAll(S, "g", "")
	S = strings.ReplaceAll(S, "h", "")
	S = strings.ReplaceAll(S, "i", "")
	S = strings.ReplaceAll(S, "j", "")
	S = strings.ReplaceAll(S, "k", "")
	S = strings.ReplaceAll(S, "l", "")
	S = strings.ReplaceAll(S, "m", "")
	S = strings.ReplaceAll(S, "n", "")
	S = strings.ReplaceAll(S, "o", "")
	S = strings.ReplaceAll(S, "p", "")
	S = strings.ReplaceAll(S, "q", "")
	S = strings.ReplaceAll(S, "r", "")
	S = strings.ReplaceAll(S, "s", "")
	S = strings.ReplaceAll(S, "t", "")
	S = strings.ReplaceAll(S, "u", "")
	S = strings.ReplaceAll(S, "v", "")
	S = strings.ReplaceAll(S, "w", "")
	S = strings.ReplaceAll(S, "x", "")
	S = strings.ReplaceAll(S, "y", "")
	S = strings.ReplaceAll(S, "z", "")
	S = S + " "
	m := 0
	Qs := make(map[int]bool)
	ans := make(map[int]int)
	for i := 1; i <= m; i++ {
		Qs[getq()] = true
	}
	stk := make([]int, 27)
	nn := 0
	vis := make([]bool, 26)
	for i := 1; i <= n; i++ {
		x := int(S[i] - 'a')
		if !vis[x] {
			nn++
			stk[nn] = x
			vis[x] = true
		} else {
			j := 1
			for ; ; j++ {
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
		for j := nn; j > 0; j-- {
			t |= 1 << stk[j]
			if (t & (1 << int(S[i+1]))) != 0 {
				break
			}
			if Qs[t] {
				ans[t]++
			}
		}
	}
	for i := 1; i <= m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
