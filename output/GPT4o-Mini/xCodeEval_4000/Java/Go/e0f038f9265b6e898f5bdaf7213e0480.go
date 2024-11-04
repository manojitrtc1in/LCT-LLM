package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type Scnr struct {
	scanner *bufio.Scanner
}

func NewScnr() *Scnr {
	return &Scnr{scanner: bufio.NewScanner(os.Stdin)}
}

func (s *Scnr) NextInt() int {
	s.scanner.Scan()
	var n int
	fmt.Sscan(s.scanner.Text(), &n)
	return n
}

func (s *Scnr) NextInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = s.NextInt()
	}
	return arr
}

func repow(b, p int) int {
	res := 1
	a := b
	for p > 0 {
		if p%2 == 1 {
			res *= a
		}
		a *= a
		p /= 2
	}
	return res
}

func gcd(c, d int64) int64 {
	for {
		f := c % d
		if f == 0 {
			return d
		}
		c = d
		d = f
	}
}

func lcm(c, d int64) int64 {
	return c / gcd(c, d) * d
}

func divList(n int) []int {
	div := []int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			div = append(div, i)
			if i*i != n {
				div = append(div, n/i)
			}
		}
	}
	return div
}

func divSet(n int) map[int]struct{} {
	div := make(map[int]struct{})
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			div[i] = struct{}{}
			div[n/i] = struct{}{}
		}
	}
	return div
}

func pFacMap(x int64) map[int64]int {
	mp := make(map[int64]int)
	t := x
	for i := int64(2); i*i <= x && i <= t; i++ {
		if t%i == 0 {
			num := 0
			for t%i == 0 {
				t /= i
				num++
			}
			mp[i] = num
		}
	}
	if t != 1 {
		mp[t] = 1
	}
	return mp
}

func isPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n%2 == 0 || n == 1 {
		return false
	}
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func solve(sc *Scnr) {
	n := sc.NextInt()
	dq := make([]int, n)
	for i := 0; i < n; i++ {
		dq[i] = sc.NextInt()
	}
	a := dq[0]
	b := 0
	pre := a
	now := 0
	cnt := 1
	dq = dq[1:]

	for len(dq) > 0 {
		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[len(dq)-1]
			dq = dq[:len(dq)-1]
		}
		if now != 0 {
			b += now
			pre = now
			cnt++
		}

		if len(dq) == 0 {
			break
		}

		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[0]
			dq = dq[1:]
		}
		if now != 0 {
			a += now
			pre = now
			cnt++
		}
	}
	fmt.Printf("%d %d %d\n", cnt, a, b)
}

func main() {
	sc := NewScnr()
	t := sc.NextInt()
	for i := 0; i < t; i++ {
		solve(sc)
	}
}
