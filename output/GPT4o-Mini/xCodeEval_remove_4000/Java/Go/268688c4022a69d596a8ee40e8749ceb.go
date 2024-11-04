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
	fmt.Sscanf(s.scanner.Text(), "%d", &n)
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

func repowMod(b, p, modder int) int {
	res := 1
	a := b % modder
	for p > 0 {
		if p%2 == 1 {
			res = (res * a) % modder
		}
		a = (a * a) % modder
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

func divListLong(n int64) []int64 {
	div := []int64{}
	for i := int64(1); i*i <= n; i++ {
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

func id9(x int64) map[int64]int {
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
	if n&1 == 0 || n == 1 {
		return false
	}
	if n > math.MaxInt32 {
		return id5(n)
	}
	d := n - 1
	s := 0
	for d&1 == 0 {
		d /= 2
		s++
	}
	aa := []int{2, 3, 5, 7, 11, 13, 17}
	for _, a := range aa {
		if a >= int(n) {
			break
		}
		t := d
		y := repowMod(a, int(t), int(n))
		for t != n-1 && y != 1 && y != n-1 {
			y = (y * y) % n
			t *= 2
		}
		if y != n-1 && t%2 == 0 {
			return false
		}
	}
	return true
}

func id5(n int64) bool {
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
	left := 1
	right := n - 1

	for left <= right {
		now = 0
		for now <= pre && right >= left {
			now += dq[right]
			right--
		}
		if now != 0 {
			b += now
			pre = now
			cnt++
		}

		if left > right {
			break
		}

		now = 0
		for now <= pre && left <= right {
			now += dq[left]
			left++
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
