package main

import (
	"bytes"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func main() {
	var n int
	fmt.Scan(&n)
	l := make([][]int, n)
	for i := 0; i < n; i++ {
		l[i] = make([]int, 5)
		for j := 0; j < 5; j++ {
			fmt.Scan(&l[i][j])
		}
	}
	if n >= 50 {
		fmt.Println(0)
		return
	}
	if n <= 2 {
		fmt.Println(n)
		for i := 1; i <= n; i++ {
			fmt.Println(i)
		}
		return
	}
	er := make(map[int]struct{})
	for i := 0; i < n; i++ {
		f := 0
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if i == j || i == k || j == k {
					continue
				}
				w := 0
				for d := 0; d < 5; d++ {
					w += (l[i][d] - l[j][d]) * (l[i][d] - l[k][d])
				}
				if w > 0 {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 0 {
			er[i+1] = struct{}{}
		}
	}
	fmt.Println(len(er))
	for key := range er {
		fmt.Println(key)
	}
}
