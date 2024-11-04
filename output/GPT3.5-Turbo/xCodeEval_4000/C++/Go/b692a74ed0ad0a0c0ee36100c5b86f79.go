package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i]--
	}

	ans := 0
	fre := -1

	{
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
	}

	const maxv = 100
	for i := 0; i < maxv; i++ {
		if i == fre {
			continue
		}
		b := make([]int, n+1)
		b[0] = 0
		for j, e := range a {
			pb := b[j]
			if e == fre {
				pb--
			} else if e == i {
				pb++
			}
			b[j+1] = pb
		}
		mi := make([]int, 2*n+1)
		ma := make([]int, 2*n+1)
		for i := 0; i <= n; i++ {
			va := n + b[i]
			if i < mi[va] {
				mi[va] = i
			}
			if i > ma[va] {
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

	fmt.Println(ans)
}
