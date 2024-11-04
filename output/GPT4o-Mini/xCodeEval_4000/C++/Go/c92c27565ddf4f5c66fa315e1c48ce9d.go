package main

import (
	"fmt"
	"sort"
)

const maxn = 500007

func main() {
	var n, k int
	var a [maxn]int64
	var ans, res int64

	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i] = -a[i]
	}
	sort.Slice(a[:n], func(i, j int) bool {
		return a[i] < a[j]
	})

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

	tmp := []int64{res}
	for i := j + 1; i < n; i++ {
		tmp = append(tmp, -a[i])
	}

	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i] < tmp[j]
	})

	w := 0
	for _, c := range tmp {
		ans += (int64(w) / (k + 1)) * c
		w++
	}
	fmt.Println(ans)
}
