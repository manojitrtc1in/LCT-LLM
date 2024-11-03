package main

import (
	"fmt"
	"math"
	"sort"
)

type Vert struct {
	Hoge [5]int
}

func sign(a, b Vert) bool {
	hoge := 0
	for q := 0; q < 5; q++ {
		hoge += a.Hoge[q] * b.Hoge[q]
	}
	return hoge <= 0
}

func solve() {
	var n int
	fmt.Scan(&n)
	inputs := make([]Vert, n)
	for i := 0; i < n; i++ {
		for q := 0; q < 5; q++ {
			fmt.Scan(&inputs[i].Hoge[q])
		}
	}
	ans := make([]int, 0)
	for i := 0; i < n; i++ {
		ok := true
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
					A.Hoge[t] = inputs[q].Hoge[t] - inputs[i].Hoge[t]
					B.Hoge[t] = inputs[j].Hoge[t] - inputs[i].Hoge[t]
				}
				if !sign(A, B) {
					ok = false
					break
				}
			}
			if !ok {
				break
			}
		}
		if ok {
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
