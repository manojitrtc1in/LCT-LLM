package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	kWriteCaseNumber = false
	kMultiTest       = false
	id7              = 1
	id19             = 1111
	kMaxn            = 100001
)

func check(a []int) string {
	n := len(a)
	b := make([]int, n)
	log := ""

	var merge func(l, r int)
	merge = func(l, r int) {
		if r-l <= 1 {
			return
		}
		m := (l + r) / 2
		merge(l, m)
		merge(m, r)
		i, j, k := l, m, l
		for i < m && j < r {
			if a[i] < a[j] {
				log += "0"
				b[k] = a[i]
				i++
			} else {
				log += "1"
				b[k] = a[j]
				j++
			}
			k++
		}
		for i < m {
			b[k] = a[i]
			i++
			k++
		}
		for j < r {
			b[k] = a[j]
			j++
			k++
		}
		for p := l; p < r; p++ {
			a[p] = b[p]
		}
	}

	merge(0, n)
	return log
}

func tryRecover(l, r int, s *string, p []int) bool {
	if r-l <= 1 {
		return true
	}
	mid := (l + r) / 2
	if !tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p) {
		return false
	}
	left := []int{}
	for i := mid - 1; i >= l; i-- {
		left = append(left, p[i])
	}
	right := []int{}
	for i := r - 1; i >= mid; i-- {
		right = append(right, p[i])
	}
	pos := l
	for len(left) > 0 && len(right) > 0 {
		if len(*s) == 0 {
			return false
		}
		ch := (*s)[len(*s)-1]
		*s = (*s)[:len(*s)-1]

		if ch == '1' {
			p[pos] = right[len(right)-1]
			right = right[:len(right)-1]
		} else {
			p[pos] = left[len(left)-1]
			left = left[:len(left)-1]
		}
		pos++
	}
	for len(left) > 0 {
		p[pos] = left[len(left)-1]
		left = left[:len(left)-1]
		pos++
	}
	for len(right) > 0 {
		p[pos] = right[len(right)-1]
		right = right[:len(right)-1]
		pos++
	}
	return true
}

func solve(in *fmt.Scanner, out *fmt.Writer) {
	var s string
	in.Scan(&s)
	s = reverse(s)

	L := id7
	R := id19
	for R-L > 1 {
		len := (L + R) / 2
		p := make([]int, len)
		tmp := s
		recovered := tryRecover(0, len, &tmp, p)
		if recovered {
			if len(tmp) == 0 {
				ans := make([]int, len)
				for i := 0; i < len; i++ {
					ans[p[i]] = i
				}
				fmt.Fprintln(out, len)
				for _, x := range ans {
					fmt.Fprint(out, x+1, " ")
				}
				fmt.Fprintln(out)
				return
			}
			L = len
		} else {
			R = len
		}
	}
	panic("should not reach here")
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	if kMultiTest {
		var testsCount int
		fmt.Scan(&testsCount)
		for i := 1; i <= testsCount; i++ {
			if kWriteCaseNumber {
				fmt.Printf("Case %d: ", i)
			}
			solve(fmt.Scan, fmt.Print)
		}
	} else {
		solve(fmt.Scan, fmt.Print)
	}
}
