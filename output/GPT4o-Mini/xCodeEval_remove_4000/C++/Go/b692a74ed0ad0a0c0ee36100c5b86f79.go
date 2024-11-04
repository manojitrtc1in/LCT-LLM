package main

import (
	"fmt"
	"math"
)

const eol = '\n'

func main() {
	cases := 1
	for caseid := 1; caseid <= cases; caseid++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i]-- // Decrement each element
	}

	ans := 0
	fre := -1

	// Count occurrences
	cnt := make(map[int]int)
	for _, e := range a {
		cnt[e]++
	}
	ma := 0
	for _, y := range cnt {
		if y > ma {
			ma = y
		}
	}
	mac := 0
	for x, y := range cnt {
		if y == ma {
			mac++
			fre = x
		}
	}
	if mac > 1 {
		ans = n
	}

	const maxv = 100
	for i := 0; i < maxv; i++ {
		if i == fre {
			continue
		}
		b := []int{0}
		for _, e := range a {
			pb := b[len(b)-1]
			if e == fre {
				pb--
			} else if e == i {
				pb++
			}
			b = append(b, pb)
		}
		mi := make([]int, 2*n+1)
		ma := make([]int, 2*n+1)
		for j := range mi {
			mi[j] = n + 1
			ma[j] = -1
		}
		for i := 0; i <= n; i++ {
			va := n + b[i]
			if mi[va] > i {
				mi[va] = i
			}
			if ma[va] < i {
				ma[va] = i
			}
		}
		j := n + 1
		for i := 0; i < len(mi); i++ {
			if mi[i] < j {
				j = mi[i]
			}
			if ma[i]-j > ans {
				ans = ma[i] - j
			}
		}
	}

	fmt.Printf("%d%c", ans, eol)
}
