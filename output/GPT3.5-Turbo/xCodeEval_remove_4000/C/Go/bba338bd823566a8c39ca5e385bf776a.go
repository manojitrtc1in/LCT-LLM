package main

import (
	"fmt"
	"math"
)

const (
	A     = 100000
	B     = 100000
	P     = 10000
	PMAX  = 100000000
	L1    = 100000
	P3    = 1000000000000000000
)

var (
	a [PMAX + 1]int
	b [B + 1]uint32
	p [P]int
	y [P]int64
)

func main() {
	var n, n2, n3, bl, bh, ans, k, kl, kh int64
	var i, j, b1, b2, q2, c int

	fmt.Scan(&n)

	p[0] = 2
	k = 1
	for i = 3; i <= PMAX; i += 2 {
		if a[i] == 0 {
			p[k] = i
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
		b2 = int(n2 / A)
		q2 = int(n2 % A)
		if b1 != b2 {
			for j := 0; j < A+1; j++ {
				a[j] = 0
			}
			b1 = b2
			bl = int64(b1 * A)
			bh = bl + int64(q2) + 1
			c = 0
			y[0] = -1
			for j := 1; j < P; j++ {
				y[j] = int64(math.Max(float64(bl/p[j]*int64(p[j])+int64(p[j])), float64(int64(p[j])*int64(p[j])))) - bl
				if y[j]&1 == 0 {
					y[j] += int64(p[j])
				}
			}
			for kl = bl; kl < bh; kl += L1 {
				kh = int64(math.Min(float64(kl+L1), float64(bh))) - bl
				for j := 1; j < P; j++ {
					for k = y[j]; k < kh; k += 2 * int64(p[j]) {
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

	fmt.Println(ans)
}
