package main

import (
	"fmt"
)

const mod uint = 998244353

type modint struct {
	v uint
}

func makeModint(x uint) modint {
	m := modint{v: x}
	return m
}

func (m modint) add(x modint) modint {
	return makeModint((m.v + x.v) % mod)
}

func (m modint) sub(x modint) modint {
	return makeModint((m.v + mod - x.v) % mod)
}

func (m modint) mul(x modint) modint {
	return makeModint((uint(m.v) * uint(x.v)) % mod)
}

func (m modint) inv() modint {
	return m.pow(mod - 2)
}

func (m modint) pow(n uint) modint {
	ans := makeModint(uint(1))
	for n > 0 {
		if n&1 == 1 {
			ans = ans.mul(m)
		}
		m = m.mul(m)
		n >>= 1
	}
	return ans
}

func (m modint) div(x modint) modint {
	return m.mul(x.inv())
}

func (m modint) equal(x modint) bool {
	return m.v == x.v
}

func (m modint) notEqual(x modint) bool {
	return !m.equal(x)
}

func (m modint) less(x modint) bool {
	return m.v < x.v
}

func (m modint) lessEqual(x modint) bool {
	return m.less(x) || m.equal(x)
}

func (m modint) greater(x modint) bool {
	return !m.lessEqual(x)
}

func (m modint) greaterEqual(x modint) bool {
	return !m.less(x)
}

func (m modint) String() string {
	return fmt.Sprintf("%d", m.v)
}

func in() int {
	var v int
	fmt.Scan(&v)
	return v
}

func inSlice(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a[i] = x == 1
	}
	return a
}

func inSliceInt(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	return a
}

func out(v interface{}) {
	fmt.Print(v)
}

func outln(v interface{}) {
	fmt.Println(v)
}

func main() {
	n := in()
	m := in()
	a := inSlice(n)
	w := inSliceInt(n)

	zw := 0
	ow := 0
	for i := 0; i < n; i++ {
		if a[i] {
			ow += w[i]
		} else {
			zw += w[i]
		}
	}

	s := zw + ow
	inv := make([]modint, 2*m+1)
	for d := -m; d <= m; d++ {
		if s+d > 0 {
			inv[d+m] = makeModint(1).div(makeModint(uint(s + d)))
		}
	}

	dp := make([][]modint, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]modint, 2)
	}
	dp[0][0] = makeModint(1)
	dp[0][1] = makeModint(1)

	for i := 0; i < m; i++ {
		ndp := make([][]modint, m+1)
		for j := 0; j <= m; j++ {
			ndp[j] = make([]modint, 2)
		}

		for z := 0; z <= i; z++ {
			o := i - z
			wz := zw - z
			wo := ow + o

			if wz < 0 {
				continue
			}

			for dz := -1; dz <= 0; dz++ {
				nwz := wz + dz
				nz := z + (-dz)

				if nwz < 0 {
					continue
				}

				eps := inv[wz+wo-s+m]
				p := makeModint(0)
				if dz == -1 {
					p = makeModint(uint(wz)).mul(eps)
				} else {
					p = makeModint(uint(wo)).mul(eps)
				}

				ndp[nz][-dz] = ndp[nz][-dz].add(dp[z][-dz].mul(p))
				ndp[nz][1+dz] = ndp[nz][1+dz].add(dp[z][1+dz].mul(p.add(makeModint(2*dz+1).mul(eps))))
			}
		}

		dp = ndp
	}

	cz := makeModint(0)
	co := makeModint(0)
	for i := 0; i <= m; i++ {
		cz = cz.add(dp[i][0])
		co = co.add(dp[i][1])
	}

	for i := 0; i < n; i++ {
		if a[i] {
			outln(makeModint(uint(w[i])).mul(co))
		} else {
			outln(makeModint(uint(w[i])).mul(cz))
		}
	}
}
