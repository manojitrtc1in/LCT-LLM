package main

import (
	"fmt"
)

const (
	MOD = 998244353
	INF = 1 << 61
)

func extgcd(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return a, 1, 0
	}
	d, x, y := extgcd(b, a%b)
	return d, y, x - a/b*y
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var m int64
	fmt.Scan(&m)
	var h1, a1, x1, y1 int64
	fmt.Scan(&h1, &a1, &x1, &y1)
	t := []int64{h1}
	used := make([]bool, m)
	used[h1] = true
	for {
		tmp := (t[len(t)-1]*x1 + y1) % m
		t = append(t, tmp)
		if used[tmp] {
			break
		}
		used[tmp] = true
	}
	used = make([]bool, m)
	var h2, a2, x2, y2 int64
	fmt.Scan(&h2, &a2, &x2, &y2)
	used[h2] = true
	s := []int64{h2}
	for {
		tmp := (s[len(s)-1]*x2 + y2) % m
		s = append(s, tmp)
		if used[tmp] {
			break
		}
		used[tmp] = true
	}

	l1, l2 := int64(-1), int64(-1)
	mn1, mn2 := INF, INF
	now := int64(0)
	for {
		if t[len(t)-1] == t[now] {
			l1 = int64(len(t)) - now - 1
		}
		if t[now] == a1 {
			mn1 = now
			break
		}
		now++
		if now == int64(len(t)) {
			break
		}
	}
	now = int64(0)
	for {
		if s[len(s)-1] == s[now] {
			l2 = int64(len(s)) - now - 1
		}
		if s[now] == a2 {
			mn2 = now
			break
		}
		now++
		if now == int64(len(s)) {
			break
		}
	}

	calc := func() int64 {
		if mn1 != INF && mn2 != INF {
			if mn1 == mn2 {
				return mn1
			}
			if mn1 > mn2 && l2 == -1 {
				return -1
			}
			if mn1 < mn2 && l1 == -1 {
				return -1
			}
			if l1 == -1 {
				if (mn1-mn2)%l2 == 0 {
					return mn1
				} else {
					return -1
				}
			}
			if l2 == -1 {
				if (mn2-mn1)%l1 == 0 {
					return mn2
				} else {
					return -1
				}
			}
			if l1 == l2 {
				if abs(mn1-mn2)%l1 == 0 {
					return max(mn1, mn2)
				} else {
					return -1
				}
			}
			if mn2 > mn1 && (mn2-mn1)%l1 == 0 {
				return mn2
			}
			if mn1 > mn2 && (mn1-mn2)%l2 == 0 {
				return mn1
			}
			if abs(mn2-mn1)%abs(gcd(l1, l2)) != 0 {
				return -1
			}
			x, y := extgcd(l1, l2)
			x *= (mn2 - mn1) / gcd(l1, l2)
			y *= (mn2 - mn1) / gcd(l1, l2)
			mn := INF
			for x*l1+mn1 < max(mn1, mn2) {
				x += l2 / gcd(l1, l2)
			}
			mn = x*l1 + mn1
			for {
				x -= l2 / gcd(l1, l2)
				if x*l1+mn1 >= max(mn1, mn2) {
					if mn > x*l1+mn1 {
						mn = x*l1 + mn1
					}
				} else {
					break
				}
			}
			return mn
		} else {
			return -1
		}
	}

	fmt.Println(calc())
}
