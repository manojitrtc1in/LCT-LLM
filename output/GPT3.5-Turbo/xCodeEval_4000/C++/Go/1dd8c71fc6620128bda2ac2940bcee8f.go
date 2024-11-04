package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var cnt [100001]int
var l [100001]int
var r [100001]int

type fenwick struct {
	fw []int
}

func newFenwick(n int) *fenwick {
	fw := make([]int, n+1)
	return &fenwick{fw}
}

func (fw *fenwick) update(i, d int) {
	for i < len(fw.fw) {
		if d > fw.fw[i] {
			fw.fw[i] = d
		}
		i |= i + 1
	}
}

func (fw *fenwick) get(n int) int {
	result := 0
	for n >= 0 {
		if fw.fw[n] > result {
			result = fw.fw[n]
		}
		n = (n & (n + 1)) - 1
	}
	return result
}

func (fw *fenwick) getRange(l, r int) int {
	return fw.get(r) - fw.get(l-1)
}

func solution(scanner *bufio.Scanner, writer *bufio.Writer) {
	n, m := nextInt(scanner), nextInt(scanner)
	for i := 1; i <= n; i++ {
		l := nextInt(scanner)
		r := nextInt(scanner)
		cnt[l]++
		cnt[r+1]--
	}

	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}

	fwL := newFenwick(100001)
	for i := 1; i <= m; i++ {
		l[i] = fwL.get(cnt[i]) + 1
		fwL.update(cnt[i], l[i])
	}

	fwR := newFenwick(100001)
	for i := m; i >= 1; i-- {
		r[i] = fwR.get(cnt[i]) + 1
		fwR.update(cnt[i], r[i])
	}

	ans := 0
	for i := 1; i <= m; i++ {
		if l[i]+r[i]-1 > ans {
			ans = l[i] + r[i] - 1
		}
	}

	fmt.Fprintln(writer, ans)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	queries := 1

	for test_case := 1; test_case <= queries; test_case++ {
		solution(scanner, writer)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func nextInts(scanner *bufio.Scanner) []int {
	scanner.Scan()
	strs := strings.Split(scanner.Text(), " ")
	vals := make([]int, len(strs))
	for i, str := range strs {
		vals[i], _ = strconv.Atoi(str)
	}
	return vals
}
