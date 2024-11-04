package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func readInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func readInt64() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func writeString(str string) {
	fmt.Fprint(writer, str)
}

func writeInt(val int) {
	fmt.Fprint(writer, val)
}

func writeInt64(val int64) {
	fmt.Fprint(writer, val)
}

func solve() {
	n := readInt()
	K := readInt()
	d := make([]int, K)
	for i := 0; i < K; i++ {
		d[i] = readInt()
	}

	f := make([]int64, 20)
	for i := 0; i < K; i++ {
		for j := 0; j < K; j++ {
			f[10+d[i]-d[j]]++
		}
	}

	n /= 2
	g := make([]int64, 1)
	g[0] = 1
	for D := 17; D >= 0; D-- {
		g = clean(convoluteSimply(g, g, mod, 3))
		if n<<~D < 0 {
			g = clean(mulnaive(g, f))
		}
	}
	if n*10 < len(g) {
		writeInt64(g[n*10])
	} else {
		writeInt64(0)
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

func mulnaive(a, b []int64) []int64 {
	c := make([]int64, len(a)+len(b)-1)
	big := 8 * mod * mod
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			c[i+j] += a[i] * b[j]
			if c[i+j] >= big {
				c[i+j] -= big
			}
		}
	}
	for i := 0; i < len(c); i++ {
		c[i] %= mod
	}
	return c
}

var mod = int64(998244353)

var NTTPrimes = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var NTTPrimitiveRoots = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func convoluteSimply(a, b []int64, P, g int) []int64 {
	m := max(2, 1<<(32-uint(bits.LeadingZeros(uint(len(a)+len(b)-1))<<2)))
	fa := nttmb(a, m, false, P, g)
	fb := a
	if a != b {
		fb = nttmb(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = fa[i] * fb[i] % int64(P)
	}
	return nttmb(fa, m, true, P, g)
}

func convolute(a, b []int64) []int64 {
	USE := 2
	m := max(2, 1<<(32-uint(bits.LeadingZeros(uint(len(a)+len(b)-1))<<2)))
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

func convolute(a, b []int64, USE, mod int) []int64 {
	m := max(2, 1<<(32-uint(bits.LeadingZeros(uint(len(a)+len(b)-1))<<2)))
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

func nttmb(src []int64, n int, inverse bool, P, g int) []int64 {
	dst := make([]int64, n)

	h := bits.TrailingZeros(uint(n))
	K := int64(1) << uint(bits.LeadingZeros(uint(P))<<1)
	H := bits.TrailingZeros(uint(K)) * 2
	M := K * K / int64(P)

	wws := make([]int, 1<<h-1)
	dw := int64(0)
	if inverse {
		dw = pow(g, int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(g, int64((P-1)/n), int64(P))
	}
	w := int64(1)
	for k := 0; k < 1<<h-1; k++ {
		wws[k] = int(w)
		w = modh(w*dw, M, H, P)
	}

	J := invl(int64(P), 1<<32)
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<h-i, s|1<<h-i-1; k < 1<<h-i-1; k, s, t = k+1, s+1, t+1 {
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
			for k := 0; k < 1<<h-i-2; k++ {
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

func nttmb(src []int64, n int, inverse bool, P, g int) []int64 {
	dst := make([]int64, n)

	h := bits.TrailingZeros(uint(n))
	K := int64(1) << uint(bits.LeadingZeros(uint(P))<<1)
	H := bits.TrailingZeros(uint(K)) * 2
	M := K * K / int64(P)

	dw := int64(0)
	if inverse {
		dw = pow(g, int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(g, int64((P-1)/n), int64(P))
	}
	wws := make([]int64, 1<<h-1)
	ws := make([]int64, 1<<h-1)
	w := int64(1)
	for k := 0; k < 1<<h-1; k++ {
		wws[k] = w << 32 / int64(P)
		ws[k] = w
		w = modh(w*dw, M, H, P)
	}

	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<h-i, s|1<<h-i-1; k < 1<<h-i-1; k, s, t = k+1, s+1, t+1 {
				ndsts := dst[s] + dst[t]
				if ndsts >= 2*int64(P) {
					ndsts -= 2 * int64(P)
				}
				T := dst[s] - dst[t] + 2*int64(P)
				Q := wws[k] * T >> 32
				dst[s] = ndsts
				dst[t] = ws[k]*T - Q*int64(P)&(1<<32)-1
			}
		}

		if i < h-1 {
			for k := 0; k < 1<<h-i-2; k++ {
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
		rev := bits.Reverse(uint(i)) >> uint(-h)
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - bits.LeadingZeros(uint64(n))
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

func garnerPrepare(m []int) []int64 {
	n := len(m)
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

func garnerBatch(u, m []int, gamma []int64) []int64 {
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

func main() {
	initIO()
	defer flush()
	solve()
}
