package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scan(&S)
	n := len(S)
	S = S[:n]
	S = S[:n]
	m := 0
	Qs := make(map[int]bool)
	ans := make(map[int]int)

	for i := 0; i < n; i++ {
		x := int(S[i] - 'a')
		if !Qs[x] {
			m++
			Qs[x] = true
		}
	}

	for i := 0; i < n; i++ {
		x := int(S[i] - 'a')
		if Qs[x] {
			Qs[x] = false
			m--
		}
		Qs[31] = true
		t := 0
		for j := 0; j < 26; j++ {
			if Qs[j] {
				t |= 1 << j
				if Qs[t] {
					ans[t]++
				}
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
