package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
)

var NTTPrimes = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var NTTPrimitiveRoots = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func convoluteSimply(a, b []int64, P, g int) []int64 {
	m := max(2, bits.Len64(uint64(max(len(a), len(b))))<<2)
	fa := nttmb(a, m, false, P, g)
	fb := a
	if a != b {
		fb = nttmb(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = (fa[i] * fb[i]) % int64(P)
	}
	return nttmb(fa, m, true, P, g)
}

func convolute(a, b []int64) []int64 {
	USE := 2
	m := max(2, bits.Len64(uint64(max(len(a), len(b))))<<2)
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := NTTPrimes[k]
		g := NTTPrimitiveRoots[k]
		fa := nttmb(a, m, false, P, g)
		fb := a
		if a != b {
			fb = nttmb(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = (fa[i] * fb[i]) % int64(P)
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
			ret = (ret * int64(mods[j]) + res[j]) % int64(mods[0])
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func convolute1(a, b []int64) []int64 {
	m := max(2, bits.Len64(uint64(max(len(a), len(b))))<<2)
	P := NTTPrimes[0]
	g := NTTPrimitiveRoots[0]
	fa := nttmb(a, m, false, P, g)
	fb := a
	if a != b {
		fb = nttmb(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = (fa[i] * fb[i]) % int64(P)
	}
	return nttmb(fa, m, true, P, g)
}

func multiply(a, b []int64, mod int) []int64 {
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

func convoluteWithMod(a, b []int64, USE, mod int) []int64 {
	if len(a)+len(b) <= 200 {
		return multiply(a, b, mod)
	}
	m := max(2, bits.Len64(uint64(max(len(a), len(b))))<<2)
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := NTTPrimes[k]
		g := NTTPrimitiveRoots[k]
		fa := nttmb(a, m, false, P, g)
		fb := a
		if a != b {
			fb = nttmb(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = (fa[i] * fb[i]) % int64(P)
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
			ret = (ret*int64(mods[j]) + res[j]) % int64(mod)
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func nttmb(src []int64, n int, inverse bool, P, g int) []int64 {
	dst := make([]int64, n)
	copy(dst, src)

	h := bits.TrailingZeros(uint(n))
	K := int64(1 << bits.Len(uint(P)))
	H := bits.TrailingZeros(uint(K)) * 2
	M := K * K / int64(P)

	wws := make([]int, 1<<h-1)
	dw := int64(1)
	if inverse {
		dw = pow(int64(g), int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(int64(g), int64((P-1)/n), int64(P))
	}
	w := int64(1 << 32) % int64(P)
	for k := 0; k < 1<<h-1; k++ {
		wws[k] = int(w)
		w = modh(w*dw, M, H, P)
	}
	J := invl(int64(P), int64(1<<32))
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<h-i, (j<<h-i)|1<<(h-i-1); k < 1<<(h-i-1); k, s, t = k+1, s+1, t+1 {
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
		rev := bits.Reverse(uint(i)) >> uint(-h)
		if i < rev {
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

func modh(a, M int64, h, mod int) int64 {
	r := a - ((M * (a & ((1 << 31) - 1)) >> 31) + M*(a>>31)>>uint(h-31)) * int64(mod))
	if r < int64(mod) {
		return r
	}
	return r - int64(mod)
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

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{scanner: bufio.NewScanner(r)}
}

func (s *Scanner) NextInt() int {
	s.scanner.Scan()
	var x int
	fmt.Sscan(s.scanner.Text(), &x)
	return x
}

func (s *Scanner) NextLong() int64 {
	s.scanner.Scan()
	var x int64
	fmt.Sscan(s.scanner.Text(), &x)
	return x
}

func (s *Scanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *Scanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *Scanner) NextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = s.NextInt()
	}
	return a
}

func (s *Scanner) NextLongArray(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = s.NextLong()
	}
	return a
}

func main() {
	solve()
}

func solve() {
	in := NewScanner(bufio.NewReader(os.Stdin))
	n := in.NextInt() / 2
	b := make([]int64, 10)
	for i := in.NextInt(); i > 0; i-- {
		b[in.NextInt()] = 1
	}
	mod := int64(998244353)
	ans := []int64{1}
	for n > 0 {
		if n&1 == 1 {
			ans = convoluteSimply(ans, b, int(mod), 3)
			sz := len(ans) - 1
			for sz > 0 && ans[sz] == 0 {
				sz--
			}
			if len(ans)-sz > 100 {
				ans = ans[:sz+1]
			}
		}
		n >>= 1
		b = convoluteSimply(b, b, int(mod), 3)
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
		res += (ans[i] * ans[i]) % mod
		res %= mod
	}
	fmt.Println(res)
}
