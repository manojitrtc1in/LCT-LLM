package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	groups int
	fa     []int
	sz     []int
	h      []int
	to     []int
	ne     []int
	m      int
	w      []int
	cc     int
	a      []S
	o      []int
	rr     int
	cao    []int
	dp     []int
)

type S struct {
	l    int
	r    int
	miss int
	cnt  int
	c    int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	t := nextInt(scanner)
	dp = make([]int, 1000001)
	for i := 0; i < t; i++ {
		n := nextInt(scanner)
		k := nextInt(scanner)
		d := nextInt(scanner)
		a := make([]int, n)
		for j := 0; j < n; j++ {
			a[j] = nextInt(scanner)
		}

		g := 0
		for j := 0; j < d; j++ {
			if dp[a[j]] == 0 {
				g++
			}
			dp[a[j]]++
		}
		all := g
		for j := d; j < n; j++ {
			dp[a[j-d]]--
			if dp[a[j-d]] == 0 {
				g--
			}
			if dp[a[j]] == 0 {
				g++
			}
			dp[a[j]]++
			all = min(all, g)
		}
		fmt.Println(all)
		for j := 0; j < d; j++ {
			dp[a[n-j-1]]--
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
