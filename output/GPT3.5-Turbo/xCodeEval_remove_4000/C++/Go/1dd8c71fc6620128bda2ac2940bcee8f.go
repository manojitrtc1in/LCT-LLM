package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MOD   = 1_000_000_007
	EPS   = 1e-9
	PI    = 3.14159265358979323846
	LLINF = 18_000_000_000_000_000_000
	INF   = 900_000_000
	MAXN  = 600_006
	N     = 50_005
)

var cnt [MAXN]int

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
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	m := nextInt(scanner)

	for i := 1; i <= n; i++ {
		l := nextInt(scanner)
		r := nextInt(scanner)
		cnt[l]++
		cnt[r+1]--
	}

	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}

	fwL := newFenwick(100_001)
	for i := 1; i <= m; i++ {
		l[i] = fwL.get(cnt[i]) + 1
		fwL.update(cnt[i], l[i])
	}

	fwR := newFenwick(100_001)
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

	queries := 1

	for test_case := 1; test_case <= queries; test_case++ {
		solution(scanner, writer)
	}

	writer.Flush()
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
