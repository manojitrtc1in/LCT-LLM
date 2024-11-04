package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

type Pair struct {
	x, y int
}

var (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = int(1e9) + 7
	EPS     = 1e-9
	PI      = 3.141592653589793
	N       = 20*1000*1000 + 13
	s       string
	n       int
	ord     []int
)

func read() bool {
	_, err := fmt.Scan(&s)
	if err != nil {
		return false
	}
	n = len(s)
	return true
}

func gen(n int) {
	if n == 1 {
		ord = append(ord, 1)
		return
	}
	gen(n / 2)
	gen((n + 1) / 2)
	ord = append(ord, n)
}

func get(t int, ans bool) int {
	ord = []int{}
	gen(t)
	l := 0
	pr := 0
	for _, x := range ord {
		if x == 1 {
			pr++
			continue
		}
		cnt0, cnt1 := 0, 0
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
		panic("assertion failed")
	}
	res := [][]int{}
	l = 0
	for _, x := range ord {
		if x == 1 {
			res = append(res, []int{0})
			continue
		}
		cnt0, cnt1 := 0, 0
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
		nw := []int{}
		for _, v := range res[len(res)-2] {
			nw = append(nw, L[v])
		}
		for _, v := range res[len(res)-1] {
			nw = append(nw, R[v])
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
	return true
}

func solve() {
	l, r := 1, n+1
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
	file, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	rand.Seed(time.Now().UnixNano())

	tc := 0
	fmt.Scan(&tc)
	for tc > 0 {
		tc--
		if read() {
			solve()
		}
	}
}
