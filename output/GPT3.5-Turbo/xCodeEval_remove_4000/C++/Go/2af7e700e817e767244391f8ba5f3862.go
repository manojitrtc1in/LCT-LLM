package main

import (
	"fmt"
	"math"
	"sort"
)

type Vert struct {
	hoge [5]int
}

func sign(a, b Vert) bool {
	hoge := 0
	for q := 0; q < 5; q++ {
		hoge += a.hoge[q] * b.hoge[q]
	}
	return hoge <= 0
}

func solve() {
	var n int
	fmt.Scan(&n)
	inputs := make([]Vert, n)
	for i := 0; i < n; i++ {
		var a Vert
		for q := 0; q < 5; q++ {
			fmt.Scan(&a.hoge[q])
		}
		inputs[i] = a
	}
	ans := make([]int, 0)
	for i := 0; i < n; i++ {
		ok := 1
		for q := 0; q < n; q++ {
			if i == q {
				continue
			}
			for j := q + 1; j < n; j++ {
				if i == j {
					continue
				}
				var A, B Vert
				for t := 0; t < 5; t++ {
					A.hoge[t] = inputs[q].hoge[t] - inputs[i].hoge[t]
					B.hoge[t] = inputs[j].hoge[t] - inputs[i].hoge[t]
				}
				if sign(A, B) == false {
					ok = 0
					break
				}
			}
			if ok == 0 {
				break
			}
		}
		if ok == 1 {
			ans = append(ans, i)
		}
	}
	fmt.Println(len(ans))
	for i := 0; i < len(ans); i++ {
		fmt.Printf("%d ", ans[i]+1)
	}
	fmt.Println()
}

func main() {
	solve()
}
