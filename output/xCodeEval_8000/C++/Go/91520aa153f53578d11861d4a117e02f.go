package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var st10 [20]int

func toInt(s string) int {
	x, _ := strconv.Atoi(s)
	return x
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func solve() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	st10[0] = 1
	for i := 1; i < 20; i++ {
		st10[i] = st10[i-1] * 10
	}
	s = reverse(s)
	for s[len(s)-1] < '0' || s[len(s)-1] > '9' {
		s = s[:len(s)-1]
	}
	s = reverse(s)
	split := strings.Split(s, "")
	VEC := make([]int, 0)
	for i := len(split); i > 0; i-- {
		x := toInt(s)
		VEC = append(VEC, x)
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

func reverseSlice(slice []int) {
	for i, j := 0, len(slice)-1; i < j; i, j = i+1, j-1 {
		slice[i], slice[j] = slice[j], slice[i]
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	tStr, _ := reader.ReadString('\n')
	tStr = strings.TrimSpace(tStr)
	t, _ := strconv.Atoi(tStr)
	for t > 0 {
		solve()
		t--
	}
}
