package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(a []int) string {
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

func tryRecover(l, r int, s string, p []int) bool {
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

func solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	scanner.Split(bufio.ScanWords)
	s := scanString(scanner)
	s = reverse(s)

	for len(s) >= 2 {
		lenStr := len(s)
		for l := 2; l <= lenStr; l++ {
			p := make([]int, l)
			for i := 0; i < l; i++ {
				p[i] = i
			}
			tmp := s
			if tryRecover(0, l, tmp, p) && len(tmp) == 0 {
				ans := make([]int, l)
				for i := 0; i < l; i++ {
					ans[p[i]] = i
				}
				writer.WriteString(strconv.Itoa(l) + "\n")
				for _, x := range ans {
					writer.WriteString(strconv.Itoa(x+1) + " ")
				}
				writer.WriteString("\n")
				return
			}
		}
		s = s[:len(s)-1]
	}

	writer.Flush()
}

func scanString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	solve(scanner, writer)
}
