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
	VEC := make([]int, 0)
	for i := len(s); i > 0; i-- {
		VEC = append(VEC, toInt(s))
		s = reverse(s)
		s = s[:len(s)-1]
		s = reverse(s)
	}
	reverseSlice(VEC)
	SET := make(map[int]bool)
	ans := 0
	for i := 0; i < len(VEC); i++ {
		x := VEC[i]
		for x < 1989 || SET[x] {
			x += st10[i+1]
		}
		SET[x] = true
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

func reverseSlice(slice []int) {
	for i, j := 0, len(slice)-1; i < j; i, j = i+1, j-1 {
		slice[i], slice[j] = slice[j], slice[i]
	}
}
