package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	n        int
	a        []int
	notmemo  [][]int
	mod      int64
	primes   []int
	isComposite []int
)

type Pair struct {
	x, y int
}

func (p Pair) Less(o Pair) bool {
	if p.x != o.x {
		return p.x < o.x
	}
	return p.y < o.y
}

func main() {
	sc := NewScanner(os.Stdin)
	n = sc.NextInt()
	a = make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = sc.NextInt()
	}
	notmemo = make([][]int, n)
	for i := range notmemo {
		notmemo[i] = []int{-1, -1}
	}
	fmt.Println(dp(0, 0))
}

func dp(idx, state int) int {
	if idx == n {
		return 0
	}
	if notmemo[idx][state] != -1 {
		return notmemo[idx][state]
	}
	take, leave, leaveall := 0, 0, 0
	if a[idx] == 1 && (state == 1 || state == 0) {
		take = 1 + dp(idx+1, 1)
	}
	if a[idx] == 0 && state == 0 {
		leave = 1 + dp(idx+1, state)
	}
	leaveall = dp(idx+1, state)

	notmemo[idx][state] = max(take, max(leaveall, leave))
	return notmemo[idx][state]
}

func sieve(N int) {
	isComposite = make([]int, N+1)
	isComposite[0], isComposite[1] = 1, 1
	for i := 2; i <= N; i++ {
		if isComposite[i] == 0 {
			primes = append(primes, i)
			for j := i * i; j <= N; j += i {
				isComposite[j] = 1
			}
		}
	}
}

func primeFactors(N int) []int {
	factors := []int{}
	idx, p := 0, primes[idx]
	for p*p <= N {
		for N%p == 0 {
			factors = append(factors, p)
			N /= p
		}
		idx++
		if idx < len(primes) {
			p = primes[idx]
		} else {
			break
		}
	}
	if N != 1 {
		factors = append(factors, N)
	}
	return factors
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner(r *os.File) *Scanner {
	return &Scanner{scanner: bufio.NewScanner(r)}
}

func (s *Scanner) NextInt() int {
	s.scanner.Scan()
	var x int
	fmt.Sscanf(s.scanner.Text(), "%d", &x)
	return x
}

func (s *Scanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}
