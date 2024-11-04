package main

import (
	"fmt"
)

func powMod(x, n, m int64) int64 {
	if m == 1 {
		return 0
	}
	r := int64(1)
	y := x % m
	for n > 0 {
		if n&1 == 1 {
			r = (r * y) % m
		}
		y = (y * y) % m
		n >>= 1
	}
	return r
}

func invMod(x, m int64) int64 {
	z := invGCD(x, m)
	return z[1]
}

func invGCD(a, b int64) [2]int64 {
	a = safeMod(a, b)
	if a == 0 {
		return [2]int64{b, 0}
	}

	s := b
	t := a
	m0 := int64(0)
	m1 := int64(1)

	for t != 0 {
		u := s / t
		s -= t * u
		m0 -= m1 * u

		tmp := s
		s = t
		t = tmp
		tmp = m0
		m0 = m1
		m1 = tmp
	}

	if m0 < 0 {
		m0 += b / s
	}
	return [2]int64{s, m0}
}

func safeMod(x, m int64) int64 {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}

func crt(r, m []int64) (int64, int64) {
	n := len(r)

	r0 := int64(0)
	m0 := int64(1)
	for i := 0; i < n; i++ {
		r1 := safeMod(r[i], m[i])
		m1 := m[i]
		if m0 < m1 {
			r0, r1 = r1, r0
			m0, m1 = m1, m0
		}
		if m0%m1 == 0 {
			if r0%m1 != r1 {
				return 0, 0
			}
			continue
		}

		g, im := invGCD(m0, m1)
		u1 := m1 / g

		if (r1-r0)%g != 0 {
			return 0, 0
		}

		x := (r1 - r0) / g % u1 * im % u1

		r0 += x * m0
		m0 *= u1

		if r0 < 0 {
			r0 += m0
		}
	}
	return r0, m0
}

func floorSum(n, m, a, b int64) int64 {
	ans := int64(0)
	if a >= m {
		ans += (n - 1) * n * (a / m) / 2
		a %= m
	}
	if b >= m {
		ans += n * (b / m)
		b %= m
	}

	yMax := (a*n + b) / m
	xMax := yMax*m - b
	if yMax == 0 {
		return ans
	}
	ans += (n - (xMax+a-1)/a) * yMax
	ans += floorSum(yMax, a, m, (a-xMax%a)%a)
	return ans
}

func main() {
	var m int64
	fmt.Scan(&m)
	hh := make([]int64, 2)
	aa := make([]int64, 2)
	xx := make([]int64, 2)
	yy := make([]int64, 2)
	for i := 0; i < 2; i++ {
		fmt.Scan(&hh[i], &aa[i], &xx[i], &yy[i])
	}
	F := func(i int) (int64, int64) {
		h := hh[i]
		a := aa[i]
		x := xx[i]
		y := yy[i]
		id := make([]int, m)
		out := make([]int, m)
		f := false
		id[h] = 0
		for i := 0; i < m+2; i++ {
			h = (h*x + y) % m
			if id[h] != 0 {
				if !f || out[h] != 0 {
					return -1, -1
				}
				return int64(i + 1 - id[h]), int64(id[a])
			} else {
				id[h] = i + 1
				out[h] = boolToInt(f)
				if h == a {
					f = true
				}
			}
		}
		return -1, -1
	}
	d1, c1 := F(0)
	d2, c2 := F(1)
	for i := 0; i < m*3+1; i++ {
		for j := 0; j < 2; j++ {
			hh[j] = (hh[j]*xx[j] + yy[j]) % m
			if hh[0] == aa[0] && hh[1] == aa[1] {
				fmt.Println(i + 1)
				return
			}
		}
	}
	if d1 == -1 || d2 == -1 {
		fmt.Println(-1)
	} else {
		x, y := crt([]int64{c1, c2}, []int64{d1, d2})
		if x == 0 && y == 0 {
			fmt.Println(-1)
		} else {
			M := max(c1, c2)
			if x < M {
				x += ((M - x - 1) / y + 1) * y
			}
			fmt.Println(x)
		}
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
