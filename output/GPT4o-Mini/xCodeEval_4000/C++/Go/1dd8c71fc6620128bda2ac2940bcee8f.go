package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const MOD = 1_000_000_007
const EPS = 1e-9
const LLINF = 18_000_000_000_000_000_000
const INF = 9_000_000_000

const MAXN = 6_000_000
const N = 5_000_000

var cnt [MAXN]int

type Fenwick struct {
	fw []int
}

func NewFenwick(n int) *Fenwick {
	fw := make([]int, n+1)
	return &Fenwick{fw: fw}
}

func (f *Fenwick) Update(i, d int) {
	for i < len(f.fw) {
		if f.fw[i] < d {
			f.fw[i] = d
		}
		i = (i | (i + 1))
	}
}

func (f *Fenwick) Get(n int) int {
	result := 0
	for n >= 0 {
		if result < f.fw[n] {
			result = f.fw[n]
		}
		n = (n & (n + 1)) - 1
	}
	return result
}

func (f *Fenwick) GetRange(l, r int) int {
	return f.Get(r) - f.Get(l - 1)
}

func solution(cin *fmt.Scanner, cout *fmt.Writer, testCase int) {
	var n, m int
	cin.Scan(&n, &m)

	for i := 1; i <= n; i++ {
		var l, r int
		cin.Scan(&l, &r)
		cnt[l]++
		cnt[r+1]--
	}

	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}

	fwL := NewFenwick(100001)
	l := make([]int, m+1)
	for i := 1; i <= m; i++ {
		l[i] = fwL.Get(cnt[i]) + 1
		fwL.Update(cnt[i], l[i])
	}

	fwR := NewFenwick(100001)
	r := make([]int, m+1)
	for i := m; i >= 1; i-- {
		r[i] = fwR.Get(cnt[i]) + 1
		fwR.Update(cnt[i], r[i])
	}

	ans := 0
	for i := 1; i <= m; i++ {
		if ans < l[i]+r[i]-1 {
			ans = l[i] + r[i] - 1
		}
	}

	fmt.Fprintln(cout, ans)
}

func main() {
	rand.Seed(time.Now().UnixNano())

	cin := fmt.NewScanner(os.Stdin)
	cout := os.Stdout

	queries := 1

	for testCase := 1; testCase <= queries; testCase++ {
		solution(cin, cout, testCase)
	}
}
