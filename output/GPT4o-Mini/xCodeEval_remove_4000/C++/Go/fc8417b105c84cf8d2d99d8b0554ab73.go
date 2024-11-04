package main

import (
	"fmt"
	"sort"
)

const MAXN = 200000
const INF = 0x3f3f3f3f

func main() {
	var n, k int
	ans := INF
	t := make(map[int]bool)
	a := make([][]int, MAXN)

	fmt.Scanf("%d%d", &n, &k)
	for i := 0; i < n; i++ {
		var temp, cnt int
		fmt.Scanf("%d", &temp)
		cnt = 0
		for temp > 0 {
			a[temp] = append(a[temp], cnt)
			t[temp] = true
			cnt++
			temp /= 2
		}
	}
	for i := range t {
		if len(a[i]) < k {
			continue
		}
		sort.Ints(a[i])
		sum := 0
		for j := 0; j < k; j++ {
			sum += a[i][j]
		}
		if sum < ans {
			ans = sum
		}
	}
	fmt.Println(ans)
}
