package main

import (
	"fmt"
	"math"
)

const (
	A     = 100000
	B     = 1000
	P     = 10000
	PMAX  = 1000000
	L1    = 10000
	P3    = 1000000000
)

var (
	a [A + 1]int
	b [B]uint
	p [P]int
	y [P]int64
)

func main() {
	var n, n2, n3, bl, bh, ans, k, kl, kh int64
	var i, j, b1, b2, q2, c int

	fmt.Scanf("%d", &n)

	p[0] = 2
	k = 1
	for i = 3; i <= PMAX; i += 2 {
		if a[i] == 0 {
			p[k] = int(i)
			k++
			if i <= PMAX/i {
				for j = i * i; j <= PMAX; j += i {
					a[j] = 1
				}
			}
		}
	}

	for i = 0; i < P; i++ {
		n2 = n / int64(p[i])
		if n2 == 0 || n2 < int64(p[i]) {
			break
		}
		b2 = int(n2 / int64(A))
		q2 = int(n2 % int64(A))
		if b1 != b2 {
			for j := range a {
				a[j] = 0
			}
			b1 = b2
			bl = b1 * int64(A)
			bh = bl + int64(q2) + 1
			c = 0
			if b1 == 0 {
				c = 1
			}
			y[0] = -1
			for j := 1; j < P; j++ {
				y[j] = max(bl/int64(p[j])*int64(p[j])+int64(p[j]), int64(p[j])*int64(p[j])) - bl
				if y[j]&1 == 0 {
					y[j] += int64(p[j])
				}
			}
			for kl = bl; kl < bh; kl += L1 {
				kh = min(kl+L1, bh) - bl
				for j := 1; j < P; j++ {
					for k := y[j]; k < kh; k += 2 * int64(p[j]) {
						a[k] = 1
					}
					y[j] = k
				}
				if kl == 0 {
					k = 3
					a[2] = 1
				} else {
					k = kl - bl + 1
				}
				for ; k < kh; k += 2 {
					a[k] = a[k+1]
					if a[k] == 0 {
						c++
					}
				}
			}
		}

		ans += int64(b[b1]) + int64(a[q2]) - int64(i+1)
	}

	i = 0
	j = P
	for {
		k = i + (j-i)/2
		if k == i {
			break
		}
		if p[k] > P3 {
			n3 = n + 1
		} else {
			n3 = int64(p[k]) * int64(p[k]) * int64(p[k])
		}
		if n3 > n {
			j = k
		} else if n3 < n {
			i = k
		} else {
			break
		}
	}
	if int64(p[k])*int64(p[k])*int64(p[k]) <= n {
		ans += int64(k + 1)
	}

	fmt.Printf("%d\n", ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
