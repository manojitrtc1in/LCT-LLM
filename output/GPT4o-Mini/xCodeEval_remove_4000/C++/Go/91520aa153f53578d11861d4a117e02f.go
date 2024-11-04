package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

const (
	EPS    = 0.000000001
	id0    = 1000000000
	INF64  = 1000000000000000000
	INF32  = 1000000000
)

func toInt(s string) int {
	x := 0
	for _, ch := range s {
		x = x*10 + int(ch-'0')
	}
	return x
}

var st10 [20]int

func solve() {
	var s string
	fmt.Scan(&s)
	st10[0] = 1
	for i := 1; i < 20; i++ {
		st10[i] = st10[i-1] * 10
	}
	s = reverse(s)
	for len(s) > 0 && (s[len(s)-1] < '0' || s[len(s)-1] > '9') {
		s = s[:len(s)-1]
	}
	s = reverse(s)

	var VEC []int
	for i := len(s); i > 0; i-- {
		VEC = append(VEC, toInt(s))
		s = reverse(s)
		s = s[:len(s)-1]
		s = reverse(s)
	}
	VEC = reverseSlice(VEC)

	SET := make(map[int]struct{})
	ans := 0
	for i := 0; i < len(VEC); i++ {
		x := VEC[i]
		for x < 1989 || exists(SET, x) {
			x += st10[i+1]
		}
		SET[x] = struct{}{}
		ans = x
	}
	fmt.Println(ans)
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func reverseSlice(slice []int) []int {
	for i, j := 0, len(slice)-1; i < j; i, j = i+1, j-1 {
		slice[i], slice[j] = slice[j], slice[i]
	}
	return slice
}

func exists(set map[int]struct{}, key int) bool {
	_, found := set[key]
	return found
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
