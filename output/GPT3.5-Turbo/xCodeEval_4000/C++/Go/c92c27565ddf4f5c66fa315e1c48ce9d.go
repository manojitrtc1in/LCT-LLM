package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] = -a[i]
	}
	sort.Ints(a)
	ans := 0
	res := 0
	j := -1
	for i := 0; i < n; i++ {
		res -= a[i]
		if res < 0 {
			j = i
			break
		}
		if i != n-1 {
			ans += res
		}
	}
	if j == -1 {
		fmt.Println(ans)
		return
	}
	tmp := make([]int, 0)
	tmp = append(tmp, res)
	for i := j + 1; i < n; i++ {
		tmp = append(tmp, -a[i])
	}
	sort.Ints(tmp)
	w := 0
	for _, c := range tmp {
		ans += (w / (k + 1)) * c
		w++
	}
	fmt.Println(ans)
}
