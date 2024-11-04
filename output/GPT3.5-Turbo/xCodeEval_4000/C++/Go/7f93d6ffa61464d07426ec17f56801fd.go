package main

import (
	"fmt"
	"sort"
)

const (
	MAX = 1000000
)

var (
	pr  = []int{2, 3, 5, 7, 11, 13, 17, 19}
	num = [][]int{
		{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 3},
		{1, 4}, {1, 5}, {1, 6}, {1, 7}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
		{2, 6}, {2, 7}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
		{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {5, 0}, {5, 1},
		{5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {6, 0}, {6, 1}, {6, 2}, {6, 3},
		{6, 4}, {6, 5}, {6, 6}, {6, 7}, {7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6},
		{7, 7}, {7, 8}, {8, 1}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9},
		{9, 3}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}, {10, 7}, {10, 8},
	}

	L   [][]int
	ans [][]int
	cnt int
	mp  []int
)

func initL(i, x, la int, v []int) {
	L[cnt] = make([]int, len(v))
	copy(L[cnt], v)
	cnt++

	sz := len(v)
	v = append(v, 0)
	for d := 1; d <= la && (x /= pr[i]); d++ {
		v[sz]++
		initL(i+1, x, d, v)
	}
	v = v[:sz]
}

func get(x int) int {
	v := make([]int, 0)
	for x > 1 {
		p := mp[x]
		c := 0
		for x%p == 0 {
			x /= p
			c++
		}
		v = append(v, -c)
	}
	sort.Ints(v)
	for i := range v {
		v[i] *= -1
	}
	return sort.Search(len(L), func(i int) bool {
		return !less(L[i], v)
	})
}

func less(a, b []int) bool {
	for i := range a {
		if a[i] != b[i] {
			return a[i] < b[i]
		}
	}
	return false
}

func main() {
	L = make([][]int, 300)
	ans = make([][]int, 300)
	for i := range ans {
		ans[i] = make([]int, 300)
	}

	initL(0, MAX, 1<<30, []int{})
	mp = make([]int, MAX+1)
	for i := 2; i <= MAX; i++ {
		if mp[i] == 0 {
			for j := i; j <= MAX; j += i {
				if mp[j] == 0 {
					mp[j] = i
				}
			}
		}
	}

	for i := 0; i < 300; i++ {
		for j := i + 1; j < 300; j++ {
			for k := 0; k < 2; k++ {
				ans[i][j] = num[int(s[i*2+k])-32][k]
				ans[j][i] = ans[i][j]
			}
		}
	}

	var t int
	fmt.Scan(&t)
	for t > 0 {
		var a, b int
		fmt.Scan(&a, &b)
		fmt.Println(ans[get(a)][get(b)])
		t--
	}
}
