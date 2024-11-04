package main

import (
	"fmt"
	"math"
)

func main() {
	n := readInt()
	a := readInts(n)
	for i := range a {
		a[i]--
	}

	ans := 0
	fre := -1

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
			chle(&mi[va], i)
			chge(&ma[va], i)
		}
		j := n + 1
		for i := 0; i < len(mi); i++ {
			chle(&j, mi[i])
			chge(&ans, ma[i]-j)
		}
	}

	fmt.Println(ans)
}

func chle(x *int, y int) {
	if y < *x {
		*x = y
	}
}

func chge(x *int, y int) {
	if y > *x {
		*x = y
	}
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func readInts(n int) []int {
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}
	return x
}
