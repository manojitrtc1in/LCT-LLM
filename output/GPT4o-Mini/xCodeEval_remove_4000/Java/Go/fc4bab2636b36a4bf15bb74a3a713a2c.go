package main

import (
	"bytes"
	"fmt"
	"io"
	"math"
)

const mod = 998244353

var id8 = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var id4 = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func main() {
	var n, K int
	fmt.Scan(&n, &K)
	d := make([]int, K)
	for i := 0; i < K; i++ {
		fmt.Scan(&d[i])
	}

	f := make([]int64, 20)
	for i := 0; i < K; i++ {
		for j := 0; j < K; j++ {
			f[10+d[i]-d[j]]++
		}
	}

	n /= 2
	g := []int64{1}
	for D := 17; D >= 0; D-- {
		g = clean(id6(g, g, mod, 3))
		if n<<uint(63-D) < 0 {
			g = clean(id5(g, f))
		}
	}
	if n*10 < len(g) {
		fmt.Println(g[n*10])
	} else {
		fmt.Println(0)
	}
}

func clean(a []int64) []int64 {
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] != 0 {
			if i == len(a)-1 {
				return a
			}
			return a[:i+1]
		}
	}
	return []int64{}
}

func id5(a, b []int64) []int64 {
	c := make([]int64, len(a)+len(b)-1)
	big := 8 * int64(mod) * int64(mod)
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			c[i+j] += a[i] * b[j]
			if c[i+j] >= big {
				c[i+j] -= big
			}
		}
	}
	for i := 0; i < len(c); i++ {
		c[i] %= int64(mod)
	}
	return c
}

func id6(a, b []int64, P, g int) []int64 {
	m := int(math.Max(2, float64(1<<uint(2*int(math.Ceil(math.Log2(float64(len(a)))))))))
	fa := id9(a, m, false, P, g)
	fb := fa
	if a != b {
		fb = id9(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = fa[i] * fb[i] % int64(P)
	}
	return id9(fa, m, true, P, g)
}

func id9(src []int64, n int, inverse bool, P, g int) []int64 {
	dst := make([]int64, n)
	copy(dst, src)

	h := bits.Len(uint(n)) - 1
	K := int64(1 << uint(32))
	H := bits.Len(uint(P)) * 2
	M := K * K / int64(P)

	wws := make([]int, 1<<uint(h-1))
	dw := int64(1)
	if inverse {
		dw = pow(g, int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(g, int64((P-1)/n), int64(P))
	}
	w := (1 << 32) % P
	for k := 0; k < 1<<uint(h-1); k++ {
		wws[k] = int(w)
		w = modh(w*dw, M, H, P)
	}
	J := invl(P, 1<<32)
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<uint(i); j++ {
			for k, s, t := 0, j<<uint(h-i), (j<<uint(h-i))|1<<uint(h-i-1); k < 1<<uint(h-i-1); k, s, t = k+1, s+1, t+1 {
				u := (dst[s] - dst[t] + 2*int64(P)) * int64(wws[k])
				dst[s] += dst[t]
				if dst[s] >= 2*int64(P) {
					dst[s] -= 2 * int64(P)
				}

				Q := (u << 32) * J >> 32
				dst[t] = (u >> 32) - (Q * int64(P) >> 32) + int64(P)
			}
		}
		if i < h-1 {
			for k := 0; k < 1<<uint(h-i-2); k++ {
				wws[k] = wws[k*2]
			}
		}
	}
	for i := 0; i < n; i++ {
		if dst[i] >= int64(P) {
			dst[i] -= int64(P)
		}
	}
	for i := 0; i < n; i++ {
		rev := bits.Reverse(uint(i)) >> uint(-h)
		if i < rev {
			dst[i], dst[rev] = dst[rev], dst[i]
		}
	}

	if inverse {
		inv := invl(int64(n), int64(P))
		for i := 0; i < n; i++ {
			dst[i] = modh(dst[i]*inv, M, H, P)
		}
	}

	return dst
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - bits.LeadingZeros64(uint64(n))
	for x >= 0 {
		ret = ret * ret % mod
		if n<<uint(63-x) < 0 {
			ret = ret * a % mod
		}
		x--
	}
	return ret
}

func invl(a, mod int64) int64 {
	b := mod
	p, q := int64(1), int64(0)
	for b > 0 {
		c := a / b
		a, b = b, a%b
		p, q = q, p-c*q
	}
	if p < 0 {
		p += mod
	}
	return p
}

func modh(a, M, h, mod int64) int64 {
	r := a - ((M*(a&((1<<31)-1))>>31)+M*(a>>31)>>h-31)*mod)
	if r < mod {
		return r
	}
	return r - mod
}
