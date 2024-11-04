package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

const MOD = 1000000007
const maxN = 100300

func toInt(s string) int {
	x := 0
	for _, ch := range s {
		x = x*10 + int(ch-'0')
	}
	return x
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
	for len(s) > 0 && (s[len(s)-1] < '0' || s[len(s)-1] > '9') {
		s = s[:len(s)-1]
	}
	s = reverse(s)

	VEC := []int{}
	for len(s) > 0 {
		VEC = append(VEC, toInt(s))
		s = reverse(s)
		s = s[:len(s)-1]
		s = reverse(s)
	}

	reverseSlice(VEC)

	SET := make(map[int]struct{})
	ans := 0
	for i, x := range VEC {
		for x < 1989 || existsInSet(SET, x) {
			x += st10[i+1]
		}
		SET[x] = struct{}{}
		ans = x
	}
	fmt.Println(ans)
}

func existsInSet(set map[int]struct{}, key int) bool {
	_, exists := set[key]
	return exists
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func reverseSlice(slice []int) {
	for i, j := 0, len(slice)-1; i < j; i, j = i+1, j-1 {
		slice[i], slice[j] = slice[j], slice[i]
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		solve()
		t--
	}
}
