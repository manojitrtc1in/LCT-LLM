package main

import (
	"fmt"
)

type mint struct {
	v int
}

func mod() int {
	return 998244353
}

func raw(v int) mint {
	return mint{v: v}
}

func (x mint) val() int {
	return x.v
}

func (x *mint) increment() {
	x.v++
	if x.v == mod() {
		x.v = 0
	}
}

func (x *mint) decrement() {
	if x.v == 0 {
		x.v = mod()
	}
	x.v--
}

func (x mint) add(rhs mint) mint {
	x.v += rhs.v
	if x.v >= mod() {
		x.v -= mod()
	}
	return x
}

func (x mint) subtract(rhs mint) mint {
	x.v += mod() - rhs.v
	if x.v >= mod() {
		x.v -= mod()
	}
	return x
}

func (x mint) multiply(rhs mint) mint {
	x.v = (x.v * rhs.v) % mod()
	return x
}

func (x mint) divide(rhs mint) mint {
	return x.multiply(rhs.inverse())
}

func (x mint) inverse() mint {
	eg := id2(x.v, mod())
	if eg.first == 1 {
		return eg.second
	}
	return mint{}
}

func (x mint) power(n int) mint {
	result := mint{v: 1}
	for n > 0 {
		if n&1 == 1 {
			result = result.multiply(x)
		}
		x = x.multiply(x)
		n >>= 1
	}
	return result
}

func operatorPlus(lhs mint, rhs mint) mint {
	return lhs.add(rhs)
}

func operatorMinus(lhs mint, rhs mint) mint {
	return lhs.subtract(rhs)
}

func operatorMultiply(lhs mint, rhs mint) mint {
	return lhs.multiply(rhs)
}

func operatorDivide(lhs mint, rhs mint) mint {
	return lhs.divide(rhs)
}

func operatorEqual(lhs mint, rhs mint) bool {
	return lhs.v == rhs.v
}

func operatorNotEqual(lhs mint, rhs mint) bool {
	return lhs.v != rhs.v
}

func id2(a int, b int) (int, mint) {
	a = safeMod(a, b)
	if a == 0 {
		return b, mint{}
	}

	s := b
	t := a
	m0 := 0
	m1 := 1

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
	return s, mint{v: m0}
}

func safeMod(x int, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}

func id4(x int, n int, m int) int {
	if m == 1 {
		return 0
	}
	_m := m
	r := 1
	y := safeMod(x, m)
	for n > 0 {
		if n&1 == 1 {
			r = (r * y) % _m
		}
		y = (y * y) % _m
		n >>= 1
	}
	return r
}

func id1(n int) bool {
	if n <= 1 {
		return false
	}
	if n == 2 || n == 7 || n == 61 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	d := n - 1
	for d%2 == 0 {
		d /= 2
	}
	bases := []int{2, 7, 61}
	for _, a := range bases {
		t := d
		y := id4(a, t, n)
		for t != n-1 && y != 1 && y != n-1 {
			y = y * y % n
			t <<= 1
		}
		if y != n-1 && t%2 == 0 {
			return false
		}
	}
	return true
}

func isPrime(n int) bool {
	return id1(n)
}

func id3(m int) int {
	if m == 2 {
		return 1
	}
	if m == 167772161 {
		return 3
	}
	if m == 469762049 {
		return 3
	}
	if m == 754974721 {
		return 11
	}
	if m == 998244353 {
		return 3
	}
	divs := make([]int, 20)
	divs[0] = 2
	cnt := 1
	x := (m - 1) / 2
	for x%2 == 0 {
		x /= 2
	}
	for i := 3; i*i <= x; i += 2 {
		if x%i == 0 {
			divs[cnt] = i
			for x%i == 0 {
				x /= i
			}
			cnt++
		}
	}
	if x > 1 {
		divs[cnt] = x
		cnt++
	}
	for g := 2; ; g++ {
		ok := true
		for i := 0; i < cnt; i++ {
			if id4(g, (m-1)/divs[i], m) == 1 {
				ok = false
				break
			}
		}
		if ok {
			return g
		}
	}
}

func primitiveRoot(m int) int {
	return id3(m)
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	dp := make([]mint, n+1)
	p := make([]mint, n+1)

	dp[n] = mint{v: 1}
	p[n] = mint{v: 1}
	for i := n - 1; i >= 1; i-- {
		dp[i] = dp[i].add(p[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
			dp[i] = dp[i].add(p[l])
			if r <= n {
				dp[i] = dp[i].subtract(p[r])
			}
		}

		p[i] = p[i+1].add(dp[i])
	}

	fmt.Println(dp[1].val())
}
