package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Permutation []int

func NewPermutation(size int) Permutation {
	p := make(Permutation, size)
	for i := 0; i < size; i++ {
		p[i] = i
	}
	return p
}

func (p Permutation) Multiply(rhs Permutation) Permutation {
	res := make(Permutation, len(p))
	for i := 0; i < len(p); i++ {
		res[i] = p[rhs[i]]
	}
	return res
}

func (p Permutation) Pow(deg int64) Permutation {
	result := NewPermutation(len(p))
	a := p
	b := deg
	for b > 0 {
		if b&1 > 0 {
			result = result.Multiply(a)
		}
		a = a.Multiply(a)
		b >>= 1
	}
	return result
}

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func Check(a []int) string {
	n := len(a)
	b := make([]int, n)
	log := ""

	var merge func(int, int)
	merge = func(l, r int) {
		if r-l <= 1 {
			return
		}
		m := (l + r) / 2
		merge(l, m)
		merge(m, r)
		i := l
		j := m
		k := l
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

func TryRecover(l, r int, s string, p []int) bool {
	if r-l <= 1 {
		return true
	}
	mid := (l + r) / 2
	if !TryRecover(l, mid, s, p) || !TryRecover(mid, r, s, p) {
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
		if len(s) == 0 {
			return false
		}
		ch := s[len(s)-1]
		s = s[:len(s)-1]
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

func Solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	scanner.Scan()
	s := Reverse(scanner.Text())

	for len(s) >= 2 {
		for len(s) > 0 && s[len(s)-1] == '0' {
			s = s[:len(s)-1]
		}
		if len(s) == 0 {
			break
		}
		n := len(s)
		p := NewPermutation(n)
		tmp := s
		if TryRecover(0, n, tmp, p) && len(tmp) == 0 {
			ans := make([]int, n)
			for i := 0; i < n; i++ {
				ans[p[i]] = i
			}
			writer.WriteString(fmt.Sprintf("%d\n", n))
			for _, x := range ans {
				writer.WriteString(fmt.Sprintf("%d ", x+1))
			}
			writer.WriteString("\n")
			return
		}
		s = s[:len(s)-1]
	}

	writer.Flush()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	Solve(scanner, writer)
}
