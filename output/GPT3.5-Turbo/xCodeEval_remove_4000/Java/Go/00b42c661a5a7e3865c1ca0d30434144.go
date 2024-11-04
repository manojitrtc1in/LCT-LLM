package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	run()
}

func run() {
	s := ns()
	t := ns()
	len := len(s)
	pref := make([]int, len)
	suf := make([]int, len+1)
	p := 0
	tlen := len(t)
	for i := 0; i < len; i++ {
		if p < tlen && s[i] == t[p] {
			p++
		}
		pref[i] = p
	}
	p = 0
	for i := len - 1; i >= 0; i-- {
		if p < tlen && s[i] == t[tlen-1-p] {
			p++
		}
		suf[i] = p
	}
	e := -1
	all := 0
	for i := -1; i < len; i++ {
		r := tlen - pref[i]
		for e+1 <= len && suf[e+1] >= r {
			e++
		}
		all = max(all, e-i-1)
	}
	println(all)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func ns() string {
	scanner.Scan()
	return scanner.Text()
}

func ni() int {
	n, _ := strconv.Atoi(ns())
	return n
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}
