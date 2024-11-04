package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var NTTPrimes = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var NTTPrimitiveRoots = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func convoluteSimply(a []int64, b []int64, P int, g int) []int64 {
	m := max(2, highestOneBit(max(len(a), len(b))-1)<<2)
	fa := nttmb(a, m, false, P, g)
	fb := a
	if a == b {
		fb = fa
	} else {
		fb = nttmb(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = fa[i] * fb[i] % int64(P)
	}
	return nttmb(fa, m, true, P, g)
}

func convolute(a []int64, b []int64) []int64 {
	USE := 2
	m := max(2, highestOneBit(max(len(a), len(b))-1)<<2)
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := NTTPrimes[k]
		g := NTTPrimitiveRoots[k]
		fa := nttmb(a, m, false, P, g)
		fb := a
		if a == b {
			fb = fa
		} else {
			fb = nttmb(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = fa[i] * fb[i] % int64(P)
		}
		fs[k] = nttmb(fa, m, true, P, g)
	}

	mods := make([]int, USE)
	copy(mods, NTTPrimes)
	gammas := garnerPrepare(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := garnerBatch(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = ret*int64(mods[j]) + int64(res[j])
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func convolute1(a []int64, b []int64) []int64 {
	m := max(2, highestOneBit(max(len(a), len(b))-1)<<2)
	P := NTTPrimes[0]
	g := NTTPrimitiveRoots[0]
	fa := nttmb(a, m, false, P, g)
	fb := a
	if a == b {
		fb = fa
	} else {
		fb = nttmb(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = fa[i] * fb[i] % int64(P)
	}
	f := nttmb(fa, m, true, P, g)
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

func convolute2(a []int64, b []int64, USE int, mod int) []int64 {
	if len(a)+len(b) <= 200 {
		return multiply(a, b, mod)
	}
	m := max(2, highestOneBit(max(len(a), len(b))-1)<<2)
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := NTTPrimes[k]
		g := NTTPrimitiveRoots[k]
		fa := nttmb(a, m, false, P, g)
		fb := a
		if a == b {
			fb = fa
		} else {
			fb = nttmb(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = fa[i] * fb[i] % int64(P)
		}
		fs[k] = nttmb(fa, m, true, P, g)
	}

	mods := make([]int, USE)
	copy(mods, NTTPrimes)
	gammas := garnerPrepare(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := garnerBatch(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = (ret*int64(mods[j]) + int64(res[j])) % int64(mod)
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func nttmb(src []int64, n int, inverse bool, P int, g int) []int64 {
	dst := make([]int64, n)
	copy(dst, src)

	h := numberOfTrailingZeros(n)
	K := highestOneBit(P) << 1
	H := numberOfTrailingZeros(K) * 2
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
		w = modh(w*dw, M, H, int64(P))
	}

	J := invl(int64(P), 1<<32)
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<(h-i), s|(1<<(h-i-1)); k < 1<<(h-i-1); k, s, t = k+1, s+1, t+1 {
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
		rev := reverse(i) >> -h
		if i < rev {
			d := dst[i]
			dst[i] = dst[rev]
			dst[rev] = d
		}
	}

	if inverse {
		in := invl(int64(n), int64(P))
		for i := 0; i < n; i++ {
			dst[i] = modh(dst[i]*in, M, H, int64(P))
		}
	}

	return dst
}

func nttsb(src []int64, n int, inverse bool, P int, g int) []int64 {
	dst := make([]int64, n)
	copy(dst, src)

	h := numberOfTrailingZeros(n)
	K := highestOneBit(P) << 1
	H := numberOfTrailingZeros(K) * 2
	M := K * K / int64(P)

	dw := int64(0)
	if inverse {
		dw = pow(int64(g), int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(int64(g), int64((P-1)/n), int64(P))
	}
	wws := make([]int64, 1<<(h-1))
	ws := make([]int64, 1<<(h-1))
	w := int64(1)
	for k := 0; k < 1<<(h-1); k++ {
		wws[k] = w << 32 / int64(P)
		ws[k] = w
		w = modh(w*dw, M, H, int64(P))
	}

	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<(h-i), s|(1<<(h-i-1)); k < 1<<(h-i-1); k, s, t = k+1, s+1, t+1 {
				ndsts := dst[s] + dst[t]
				if ndsts >= 2*int64(P) {
					ndsts -= 2 * int64(P)
				}
				T := dst[s] - dst[t] + 2*int64(P)
				Q := wws[k] * T >> 32
				dst[s] = ndsts
				dst[t] = ws[k]*T - Q*int64(P) & (1<<32) - 1
			}
		}

		if i < h-1 {
			for k := 0; k < 1<<(h-i-2); k++ {
				wws[k] = wws[k*2]
				ws[k] = ws[k*2]
			}
		}
	}

	for i := 0; i < n; i++ {
		if dst[i] >= int64(P) {
			dst[i] -= int64(P)
		}
	}
	for i := 0; i < n; i++ {
		rev := reverse(i) >> -h
		if i < rev {
			d := dst[i]
			dst[i] = dst[rev]
			dst[rev] = d
		}
	}

	if inverse {
		in := invl(int64(n), int64(P))
		for i := 0; i < n; i++ {
			dst[i] = modh(dst[i]*in, M, H, int64(P))
		}
	}

	return dst
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func highestOneBit(n int) int {
	return 1 << (31 - numberOfLeadingZeros(n))
}

func numberOfLeadingZeros(n int) int {
	if n == 0 {
		return 32
	}
	val := uint32(n)
	var leadingZeros int
	if val >= 1<<16 {
		if val >= 1<<24 {
			if val >= 1<<28 {
				leadingZeros = 28
			} else {
				leadingZeros = 24
			}
		} else {
			if val >= 1<<26 {
				leadingZeros = 26
			} else {
				leadingZeros = 22
			}
		}
	} else {
		if val >= 1<<8 {
			if val >= 1<<12 {
				leadingZeros = 12
			} else {
				leadingZeros = 8
			}
		} else {
			if val >= 1<<4 {
				leadingZeros = 4
			} else {
				leadingZeros = 0
			}
		}
	}
	return leadingZeros - int(log2(uint32(n)))
}

func log2(n uint32) uint32 {
	n |= n >> 1
	n |= n >> 2
	n |= n >> 4
	n |= n >> 8
	n |= n >> 16
	return bitCount(n) - 1
}

func bitCount(n uint32) uint32 {
	n = n - ((n >> 1) & 0x55555555)
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
	n = (n + (n >> 4)) & 0x0f0f0f0f
	n = n + (n >> 8)
	n = n + (n >> 16)
	return n & 0x0000003f
}

func reverse(n int) int {
	return reverseBytes(int32(n))
}

func reverseBytes(n int32) int {
	return int(reverseBytes32(uint32(n)))
}

func reverseBytes32(n uint32) uint32 {
	n = (n&0x55555555)<<1 | (n>>1)&0x55555555
	n = (n&0x33333333)<<2 | (n>>2)&0x33333333
	n = (n&0x0f0f0f0f)<<4 | (n>>4)&0x0f0f0f0f
	n = (n&0x00ff00ff)<<8 | (n>>8)&0x00ff00ff
	return n<<16 | n>>16
}

func modh(a, M, h, mod int64) int64 {
	r := a - ((M*(a&(1<<31)-1)>>31)+M*(a>>31)>>(h-31))*mod
	if r < mod {
		return r
	}
	return r - mod
}

func garnerPrepare(m []int) []int64 {
	n := len(m)
	if n == 0 {
		return []int64{}
	}
	gamma := make([]int64, n)
	for k := 1; k < n; k++ {
		prod := int64(1)
		for i := 0; i < k; i++ {
			prod = prod * int64(m[i]) % int64(m[k])
		}
		gamma[k] = invl(prod, int64(m[k]))
	}
	return gamma
}

func garnerBatch(u []int, m []int, gamma []int64) []int64 {
	n := len(u)
	v := make([]int64, n)
	v[0] = int64(u[0])
	for k := 1; k < n; k++ {
		temp := v[k-1]
		for j := k - 2; j >= 0; j-- {
			temp = (temp*int64(m[j]) + v[j]) % int64(m[k])
		}
		v[k] = (int64(u[k]) - temp) * gamma[k] % int64(m[k])
		if v[k] < 0 {
			v[k] += int64(m[k])
		}
	}
	return v
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - numberOfLeadingZeros(int(n))
	for ; x >= 0; x-- {
		ret = ret * ret % mod
		if n<<63-x < 0 {
			ret = ret * a % mod
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

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
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
			ans = convoluteSimply(ans, b, mod, 3)
			sz := len(ans) - 1
			for sz > 0 && ans[sz] == 0 {
				sz--
			}
			if len(ans)-sz > 100 {
				ans = ans[:sz+1]
			}
		}
		n >>= 1
		b = convoluteSimply(b, b, mod, 3)
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
