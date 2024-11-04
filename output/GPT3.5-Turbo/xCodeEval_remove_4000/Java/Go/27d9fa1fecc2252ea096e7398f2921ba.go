package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var id10 = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var id4 = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func id7(a []int64, b []int64, P int, g int) []int64 {
	m := max(2, pow2(max(len(a), len(b)))-1)<<2
	fa := id13(a, m, false, P, g)
	fb := fa
	if !equal(a, b) {
		fb = id13(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = (fa[i] * fb[i]) % int64(P)
	}
	return id13(fa, m, true, P, g)
}

func id3(a []int64, b []int64) []int64 {
	USE := 2
	m := max(2, pow2(max(len(a), len(b)))-1)<<2
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := id10[k]
		g := id4[k]
		fa := id13(a, m, false, P, g)
		fb := fa
		if !equal(a, b) {
			fb = id13(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = (fa[i] * fb[i]) % int64(P)
		}
		fs[k] = id13(fa, m, true, P, g)
	}

	mods := make([]int, USE)
	copy(mods, id10[:USE])
	gammas := id2(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := id8(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = (ret * int64(mods[j])) + int64(res[j])
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func id11(a []int64, b []int64) []int64 {
	m := max(2, pow2(max(len(a), len(b)))-1)<<2
	P := id10[0]
	g := id4[0]
	fa := id13(a, m, false, P, g)
	fb := fa
	if !equal(a, b) {
		fb = id13(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = (fa[i] * fb[i]) % int64(P)
	}
	f := id13(fa, m, true, P, g)
	return f
}

func multiply(a []int64, b []int64, mod int) []int64 {
	v := int64(mod)
	v *= int64(mod)
	ans := make([]int64, len(a)+len(b)-1)
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			ans[i+j] += a[i] * b[j]
			if ans[i+j] >= v {
				ans[i+j] -= v
			}
		}
	}
	for i := 0; i < len(ans); i++ {
		ans[i] %= int64(mod)
	}
	return ans
}

func id3Mod(a []int64, b []int64, USE int, mod int) []int64 {
	if len(a)+len(b) <= 200 {
		return multiply(a, b, mod)
	}
	m := max(2, pow2(max(len(a), len(b)))-1)<<2
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := id10[k]
		g := id4[k]
		fa := id13(a, m, false, P, g)
		fb := fa
		if !equal(a, b) {
			fb = id13(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = (fa[i] * fb[i]) % int64(P)
		}
		fs[k] = id13(fa, m, true, P, g)
	}

	mods := make([]int, USE)
	copy(mods, id10[:USE])
	gammas := id2(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := id8(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = (ret*int64(mods[j]) + int64(res[j])) % int64(mod)
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func id13(src []int64, n int, inverse bool, P int, g int) []int64 {
	dst := make([]int64, n)
	copy(dst, src)

	h := bits.TrailingZeros(uint(n))
	K := int64(bits.HighestOneBit(uint64(P)) << 1)
	H := bits.TrailingZeros(uint(K)) * 2
	M := K * K / int64(P)

	wws := make([]int, 1<<(h-1))
	dw := int64(0)
	if inverse {
		dw = pow(int64(g), int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(int64(g), int64((P-1)/n), int64(P))
	}
	w := int64(1 << 32) % int64(P)
	for k := 0; k < 1<<(h-1); k++ {
		wws[k] = int(w)
		w = modh(w*dw, M, H, P)
	}

	J := invl(int64(P), 1<<32)
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<(h-i), (j<<(h-i))|(1<<(h-i-1)); k < 1<<(h-i-1); k, s, t = k+1, s+1, t+1 {
				u := (dst[s] - dst[t] + 2*int64(P)) * int64(wws[k])
				dst[s] += dst[t]
				if dst[s] >= 2*int64(P) {
					dst[s] -= 2 * int64(P)
				}

				Q := (u << 32) * J >> 32
				dst[t] = (u >> 32) - (Q*int64(P) >> 32) + int64(P)
			}
		}
		if i < h-1 {
			for k := 0; k < 1<<(h-i-2); k++ {
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
		rev := bits.Reverse(uint(i)) >> -h
		if i < int(rev) {
			d := dst[i]
			dst[i] = dst[rev]
			dst[rev] = d
		}
	}

	if inverse {
		in := invl(int64(n), int64(P))
		for i := 0; i < n; i++ {
			dst[i] = modh(dst[i]*in, M, H, P)
		}
	}

	return dst
}

func id2(m []int) []int64 {
	n := len(m)
	gamma := make([]int64, n)
	for k := 1; k < n; k++ {
		prod := int64(1)
		for i := 0; i < k; i++ {
			prod = (prod * int64(m[i])) % int64(m[k])
		}
		gamma[k] = invl(prod, int64(m[k]))
	}
	return gamma
}

func id8(u []int, m []int, gamma []int64) []int64 {
	n := len(u)
	v := make([]int64, n)
	v[0] = int64(u[0])
	for k := 1; k < n; k++ {
		temp := v[k-1]
		for j := k - 2; j >= 0; j-- {
			temp = (temp*int64(m[j]) + v[j]) % int64(m[k])
		}
		v[k] = ((int64(u[k]) - temp) * gamma[k]) % int64(m[k])
		if v[k] < 0 {
			v[k] += int64(m[k])
		}
	}
	return v
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - bits.LeadingZeros(uint64(n))
	for ; x >= 0; x-- {
		ret = (ret * ret) % mod
		if (n<<63-x)>>63 == 1 {
			ret = (ret * a) % mod
		}
	}
	return ret
}

func invl(a, mod int64) int64 {
	b := mod
	p := int64(1)
	q := int64(0)
	for b > 0 {
		c := a / b
		d := a
		a = b
		b = d % b
		d = p
		p = q
		q = d - c*q
	}
	if p < 0 {
		p += mod
	}
	return p
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pow2(n int) int {
	return 1 << uint(bits.Len(uint(n-1)))
}

func equal(a, b []int64) bool {
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func modh(a, M int64, h, mod int) int64 {
	r := a - ((M*(a&int64(1<<31)-1))>>31+M*(a>>31)>>h-31)*int64(mod)
	if r < int64(mod) {
		return r
	}
	return r - int64(mod)
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	n /= 2
	b := make([]int64, 10)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		b[x] = 1
	}
	mod := 998244353
	ans := make([]int64, 1)
	ans[0] = 1
	for n > 0 {
		if n&1 == 1 {
			ans = id7(ans, b, mod, 3)
			sz := len(ans) - 1
			for sz > 0 && ans[sz] == 0 {
				sz--
			}
			if len(ans)-sz > 100 {
				ans = ans[:sz+1]
			}
		}
		n >>= 1
		b = id7(b, b, mod, 3)
		sz := len(b) - 1
		for sz > 0 && b[sz] == 0 {
			sz--
		}
		if len(b)-sz > 100 {
			b = b[:sz+1]
		}
	}
	res := int64(0)
	for i := 0; i < len(ans); i++ {
		res += ans[i] * ans[i]
		res %= int64(mod)
	}
	fmt.Println(res)
}

func main() {
	solve()
}
