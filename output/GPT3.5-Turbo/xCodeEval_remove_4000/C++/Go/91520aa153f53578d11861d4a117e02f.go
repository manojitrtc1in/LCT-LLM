package main

import (
	"fmt"
	"strconv"
)

func toInt(s string) int {
	x, _ := strconv.Atoi(s)
	return x
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func solve() {
	var s string
	fmt.Scan(&s)
	st10 := make([]int, 20)
	st10[0] = 1
	for i := 1; i < 20; i++ {
		st10[i] = st10[i-1] * 10
	}
	s = reverse(s)
	for s[len(s)-1] < '0' || s[len(s)-1] > '9' {
		s = s[:len(s)-1]
	}
	s = reverse(s)
	vec := make([]int, 0)
	for i := len(s); i > 0; i-- {
		vec = append(vec, toInt(s))
		s = reverse(s)
		s = s[:len(s)-1]
		s = reverse(s)
	}
	reverse(vec)
	set := make(map[int]bool)
	ans := 0
	for i := 0; i < len(vec); i++ {
		x := vec[i]
		for x < 1989 || set[x] {
			x += st10[i+1]
		}
		set[x] = true
		ans = x
	}
	fmt.Println(ans)
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
