package main

import (
	"fmt"
	"math/rand"
	"sort"
	"strconv"
	"strings"
	"time"
)

const (
	kMinLen = 1
	kMaxLen = 1111
)

type E1SortirovkaSliyaniem struct{}

func (solver *E1SortirovkaSliyaniem) check(a []int) string {
	n := len(a)
	b := make([]int, n)
	var log strings.Builder

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
				log.WriteByte('0')
				b[k] = a[i]
				i++
			} else {
				log.WriteByte('1')
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
		copy(a[l:r], b[l:r])
	}

	merge(0, n)
	return log.String()
}

func (solver *E1SortirovkaSliyaniem) tryRecover(l, r int, s *string, p []int) bool {
	if r-l <= 1 {
		return true
	}
	mid := (l + r) / 2
	if !solver.tryRecover(l, mid, s, p) || !solver.tryRecover(mid, r, s, p) {
		return false
	}
	left := make([]int, 0)
	for i := mid - 1; i >= l; i-- {
		left = append(left, p[i])
	}
	right := make([]int, 0)
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

func (solver *E1SortirovkaSliyaniem) solve(in *strings.Reader, out *strings.Builder) {
	var s string
	fmt.Fscan(in, &s)
	s = reverse(s)

	L, R := kMinLen, kMaxLen
	for R-L > 1 {
		len := (L + R) / 2
		p := make([]int, len)
		tmp := s
		recovered := solver.tryRecover(0, len, &tmp, p)
		if recovered {
			if len(*s) == 0 {
				ans := make([]int, len)
				for i := 0; i < len; i++ {
					ans[p[i]] = i
				}
				out.WriteString(fmt.Sprintf("%d\n", len))
				for _, x := range ans {
					out.WriteString(fmt.Sprintf("%d ", x+1))
				}
				out.WriteString("\n")
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
	solver := E1SortirovkaSliyaniem{}
	in := strings.NewReader("input string here") // replace with actual input
	out := &strings.Builder{}

	rand.Seed(time.Now().UnixNano())
	out.WriteString(fmt.Sprintf("%.16f\n", 0.0)) // Placeholder for precision output
	solver.solve(in, out)

	fmt.Print(out.String())
}
