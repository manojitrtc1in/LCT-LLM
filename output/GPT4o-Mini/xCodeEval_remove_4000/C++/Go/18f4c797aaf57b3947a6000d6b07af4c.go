package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

const N = 1000009
const M = 10009
const Z = 26

var A [N]rune
var buf [Z]rune
var Q [M]int
var have = make(map[int]struct{})
var ans = make(map[int]int)
var n, m int

var stk [Z]int
var nn int
var vis [Z]bool

func push(x int) {
	if !vis[x] {
		vis[stk[nn]] = true
		stk[nn] = x
		nn++
	} else {
		var j int
		for {
			if stk[j] == x {
				break
			}
			j++
		}
		for j < nn-1 {
			stk[j] = stk[j+1]
			j++
		}
		stk[nn-1] = x
	}
}

func main() {
	var input string
	fmt.Scan(&input)
	n = len(input)
	for i := 0; i < n; i++ {
		A[i] = rune(input[i]) - 'a'
	}
	A[n] = Z

	for i := 0; i < m; i++ {
		fmt.Scan(&buf)
		var cur int
		for _, c := range buf {
			Q[i] |= 1 << (c - 'a')
		}
		have[Q[i]] = struct{}{}
	}

	for i := 0; i < n; i++ {
		push(int(A[i]))
		s := 0
		for j := nn - 1; j >= 0; j-- {
			s |= 1 << stk[j]
			if (s & (1 << (A[i+1] - 'a'))) != 0 {
				break
			}
			if _, exists := have[s]; exists {
				ans[s]++
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
