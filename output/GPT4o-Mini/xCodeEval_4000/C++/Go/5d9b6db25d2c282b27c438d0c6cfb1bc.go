package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"strings"
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
	res := make(Permutation, len(p))
	for i := range p {
		res[i] = p[rhs[i]]
	}
	return res
}

func (p Permutation) Next() bool {
	return nextPermutation(p)
}

func nextPermutation(p Permutation) bool {
	n := len(p)
	i := n - 1
	for i > 0 && p[i-1] >= p[i] {
		i--
	}
	if i <= 0 {
		return false
	}
	j := n - 1
	for p[j] <= p[i-1] {
		j--
	}
	p[i-1], p[j] = p[j], p[i-1]
	reverse(p[i:])
	return true
}

func reverse(p Permutation) {
	for i, j := 0, len(p)-1; i < j; i, j = i+1, j-1 {
		p[i], p[j] = p[j], p[i]
	}
}

func check(a []int) string {
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

func tryRecover(l, r int, s *string, p []int) bool {
	if r-l <= 1 {
		return true
	}
	mid := (l + r) / 2
	if !tryRecover(l, mid, s, p) || !tryRecover(mid, r, s, p) {
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

func solve(s string) {
	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
		}
	}

	for len(s) > 0 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		for len(s) > 0 && s[len(s)-1] == '1' {
			s = s[:len(s)-1]
