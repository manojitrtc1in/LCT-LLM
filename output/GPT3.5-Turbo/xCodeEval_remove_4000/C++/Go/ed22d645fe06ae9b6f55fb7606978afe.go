package main

import (
	"fmt"
)

func LIS(n int, a []int) int {
	b := make([]int, 0)
	b = append(b, a[0])
	for i := 1; i < n; i++ {
		if b[len(b)-1] < a[i] {
			b = append(b, a[i])
		} else {
			l := 0
			r := len(b)
			for l < r {
				m := (l + r) / 2
				if b[m] < a[i] {
					l = m + 1
				} else {
					r = m
				}
			}
			b[r] = a[i]
		}
	}
	return len(b)
}

func main() {
	var b, d int
	var a, c string
	fmt.Scan(&b, &d)
	fmt.Scan(&a, &c)
	an := len(a)
	cn := len(c)
	t := make([]int, cn)
	tt := make([][2]int, cn)
	for i := 0; i < cn; i++ {
		k := 0
		for j := 0; j < an; j++ {
			if a[j] == c[(i+k)%cn] {
				k++
			}
		}
		t[i] = k
	}
	for i := 0; i < b; i++ {
		s := 0
		for j := 0; j < cn*d; j++ {
			s += t[s%cn]
			if tt[s%cn][0] == -1 {
				tt[s%cn][0] = i
				tt[s%cn][1] = s
			} else {
				r := i - tt[s%cn][0]
				s += (s - tt[s%cn][1]) * ((b - i) / r)
				i += ((b - i) / r) * r
				break
			}
		}
		s /= cn * d
		fmt.Println(s)
	}
}
