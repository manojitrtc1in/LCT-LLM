package main

import (
	"fmt"
	"math"
)

const MS = 3001

var t [MS + 1]int
var pw [MS + 1]int64
var pr = []int{2, 7, 61}

func count() {
	pw[0] = 1
	for c := 1; c <= MS; c++ {
		pw[c] = pw[c-1] * 2
	}
}

func square(x int64) int64 {
	return x * x
}

func bigmod(b, p, m int64) int64 {
	if p == 0 {
		return 1
	} else if p%2 == 0 {
		return square(bigmod(b, p/2, m)) % m
	} else {
		return ((b % m) * bigmod(b, p-1, m)) % m
	}
}

func mr(n int) bool {
	if (n%2 == 0 && n != 2) || n == 1 {
		return true
	}
	s := 0
	d := n - 1
	for d > 1 && d%2 == 0 {
		s++
		d /= 2
	}
	for _, p := range pr {
		if p >= n {
			break
		}
		if bigmod(int64(p), int64(d), int64(n)) != 1 {
			l := 0
			for r := 0; r < s; r++ {
				if (bigmod(int64(p), pw[r]*int64(d), int64(n))+1)%int64(n) != 0 {
					l++
				} else {
					break
				}
			}
			if l == s {
				return true
			}
		}
	}
	return false
}

func sqr(x int) int {
	return x * x
}

func ok(x int) bool {
	if x == 1 {
		return false
	}
	if mr(x) {
		return false
	}
	v := int(math.Sqrt(float64(x)))
	for i := 1; i <= v; i++ {
		j := sqr(i)
		if x > j && sqr(int(math.Sqrt(float64(x-j))))+j == x {
			return true
		}
	}
	return false
}

func main() {
	count()

	for i := 1; i <= 3001; i++ {
		t[i] += t[i-1]
	}

	var l, r int
	fmt.Scan(&l, &r)

	res := 0
	for l%100000 != 0 && l <= r {
		if ok(l) {
			res++
		}
		l++
	}
	for r%100000 != 0 && l <= r {
		if ok(r) {
			res++
		}
		r--
	}
	if l <= r {
		res += t[r/100000] - t[l/100000]
	}
	fmt.Println(res)
}
