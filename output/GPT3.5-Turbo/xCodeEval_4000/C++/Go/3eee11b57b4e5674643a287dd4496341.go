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

	b := make([][]int, 100)
	sum := make([][]int, 100)
	for i := 0; i < 100; i++ {
		b[i] = make([]int, 0)
		sum[i] = make([]int, n+1)
	}

	for i := 0; i < n; i++ {
		sum[a[i]][i+1]++
		b[a[i]] = append(b[a[i]], i)
	}

	for i := 0; i < 100; i++ {
		for j := 0; j < n; j++ {
			sum[i][j+1] += sum[i][j]
		}
	}

	find := func() int {
		mx := 0
		ret := -1
		for i := 0; i < 100; i++ {
			if mx < sum[i][n] {
				mx = sum[i][n]
				ret = i
			}
		}
		return ret
	}

	i := find()
	ans := 0
	mp := make([]int, 404040)
	for i := 0; i < 404040; i++ {
		mp[i] = -1
	}

	for j := 0; j < 100; j++ {
		if i == j {
			continue
		}
		if len(b[i]) == 0 || len(b[j]) == 0 {
			continue
		}
		x := 0
		y := 0
		now := 202020
		mp[202020] = 0
		for {
			nex := func(x, y int) (int, int) {
				if x != len(b[i]) && y != len(b[j]) {
					if b[i][x] < b[j][y] {
						return 1, b[i][x]
					} else {
						return -1, b[j][y]
					}
				} else if x != len(b[i]) {
					return 1, b[i][x]
				} else if y != len(b[j]) {
					return -1, b[j][y]
				} else {
					return -2, 0
				}
			}
			tmpX, tmpY := nex(x, y)
			if tmpX == -2 {
				break
			}
			if tmpX == 1 {
				x++
			} else {
				y++
			}
			now += tmpX
			if mp[now] != -1 {
				tmpX, tmpY := nex(x, y)
				if tmpX == -2 {
					if n-mp[now] > ans {
						ans = n - mp[now]
					}
				} else {
					if tmpY-mp[now] > ans {
						ans = tmpY - mp[now]
					}
				}
			} else {
				mp[now] = tmpY + 1
			}
		}
		for i := 0; i < len(mp); i++ {
			mp[i] = -1
		}
	}

	fmt.Println(ans)
}
