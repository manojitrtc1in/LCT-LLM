package main

import (
	"fmt"
	"sort"
)

const maxn = 500007

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] = -a[i]
	}
	sort.Ints(a)

	res, ans := 0, 0
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

	tmp := []int{res}
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
