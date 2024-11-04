package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	kMinLen = 2
	kMaxLen = 1111
)

type Permutation []int

func NewPermutation(size int) Permutation {
	p := make(Permutation, size)
	for i := range p {
		p[i] = i
	}
	return p
}

func (p Permutation) Multiply(rhs Permutation) Permutation {
	res := NewPermutation(len(p))
	for i := range p {
		res[i] = p[rhs[i]]
	}
	return res
}

func (p Permutation) Next() bool {
	// Implement next permutation logic if needed
	return false
}

func Merge(a []int, b []int, log *string, l int, r int) {
	if r-l <= 1 {
		return
	}
	m := (l + r) / 2
	Merge(a, b, log, l, m)
	Merge(a, b, log, m, r)
	i, j, k := l, m, l
	for i < m && j < r {
		if a[i] < a[j] {
			*log += "0"
			b[k] = a[i]
			i++
		} else {
			*log += "1"
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

func TryRecover(l, r int, s *string, p []int) bool {
	if r-l <= 1 {
		return true
	}
	mid := (l + r) / 2
	if !TryRecover(l, mid, s, p) || !TryRecover(mid, r, s, p) {
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

func Check(a []int) string {
	n := len(a)
	b := make([]int, n)
	log := ""
	Merge(a, b, &log, 0, n)
	return log
}

func Solve() {
	var s string
	fmt.Scan(&s)
	s = reverseString(s)

	for len := kMinLen; len <= kMaxLen; len++ {
		p := NewPermutation(len)
		tmp := s
		if TryRecover(0, len, &tmp, p) && len(tmp) == 0 {
			ans := make([]int, len)
			for i := range p {
				ans[p[i]] = i
			}
			fmt.Println(len)
			for _, x := range ans {
				fmt.Printf("%d ", x+1)
			}
			fmt.Println()
			return
		}
	}
}

func reverseString(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	Solve()
}
