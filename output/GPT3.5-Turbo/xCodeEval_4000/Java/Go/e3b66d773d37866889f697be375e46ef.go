package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	adj     [][]int
	mod     int
	notmemo [][]int
	k       int
	a       []int
	b       []int
	m       int
	c       []byte
	s1      []Pair
	s       []int
	set1    map[int]bool
)

type Pair struct {
	x int
	y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	a = make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(scanner)
	}
	notmemo = make([][]int, n)
	for i := 0; i < n; i++ {
		notmemo[i] = make([]int, 2)
		for j := 0; j < 2; j++ {
			notmemo[i][j] = -1
		}
	}
	fmt.Println(dp(0, 0))
}

func dp(idx, state int) int {
	if idx == len(a) {
		return 0
	}
	if notmemo[idx][state] != -1 {
		return notmemo[idx][state]
	}
	take := 0
	leave := 0
	leaveall := 0
	if a[idx] == 1 && (state == 1 || state == 0) {
		take = 1 + dp(idx+1, 1)
	}
	if a[idx] == 0 && state == 0 {
		leave = 1 + dp(idx+1, state)
	}
	leaveall = dp(idx+1, state)
	return max(take, max(leaveall, leave))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
