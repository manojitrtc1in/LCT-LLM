package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = acos(-1.0)

	N = 20*1000*1000 + 13
)

var (
	s string
	n int
)

func read() bool {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		s = scanner.Text()
		n = len(s)
		return true
	}
	return false
}

func gen(n int) []int {
	if n == 1 {
		return []int{1}
	}
	left := gen(n / 2)
	right := gen((n + 1) / 2)
	ord := append(left, right...)
	ord = append(ord, n)
	return ord
}

func get(t int, ans bool) int {
	ord := gen(t)
	l := 0
	pr := 0
	for _, x := range ord {
		if x == 1 {
			pr++
			continue
		}
		cnt0 := 0
		cnt1 := 0
		r := l
		fl := false
		for r < n {
			if s[r] == '0' {
				cnt0++
				if cnt0 == x/2 && cnt1 < (x+1)/2 {
					fl = true
					break
				}
			} else {
				cnt1++
				if cnt1 == (x+1)/2 && cnt0 < x/2 {
					fl = true
					break
				}
			}
			r++
		}
		if !fl {
			break
		}
		l = r
		pr++
	}
	if !ans {
		return len(ord) - pr
	}
	if l != n || pr != len(ord) {
		panic("Invalid state")
	}
	res := make([][]int, 0)
	l = 0
	for _, x := range ord {
		if x == 1 {
			res = append(res, []int{0})
			continue
		}
		cnt0 := 0
		cnt1 := 0
		r := l
		fl := false
		L := make([]int, x/2)
		R := make([]int, (x+1)/2)
		for r < n {
			if s[r] == '0' {
				L[cnt0] = cnt0 + cnt1
				cnt0++
				if cnt0 == x/2 && cnt1 < (x+1)/2 {
					fl = true
					break
				}
			} else {
				R[cnt1] = cnt0 + cnt1
				cnt1++
				if cnt1 == (x+1)/2 && cnt0 < x/2 {
					fl = true
					break
				}
			}
			r++
		}
		for cnt0 < x/2 {
			L[cnt0] = cnt0 + cnt1
			cnt0++
		}
		for cnt1 < (x+1)/2 {
			R[cnt1] = cnt0 + cnt1
			cnt1++
		}
		nw := make([]int, 0)
		for _, x := range res[len(res)-2] {
			nw = append(nw, L[x])
		}
		for _, x := range res[len(res)-1] {
			nw = append(nw, R[x])
		}
		res = res[:len(res)-2]
		res = append(res, nw)
		if !fl {
			break
		}
		l = r
	}
	fmt.Println(t)
	for _, x := range res[0] {
		fmt.Printf("%d ", x+1)
	}
	fmt.Println()
	return 1
}

func solve() {
	l := 1
	r := n + 1
	res := -1
	for l <= r {
		m := (l + r) / 2
		if get(m, false) == 0 {
			res = m
			l = m + 1
		} else {
			r = m - 1
		}
	}
	get(res, true)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s = scanner.Text()
		n = len(s)
		solve()
	}
}
