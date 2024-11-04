package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod = 998244353

func solve() {
	n := ni()
	K := ni()
	d := na(K)
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
		g = clean(id6(g, g, mod, 3))
		if n<<~D < 0 {
			g = clean(id5(g, f))
		}
	}
	fmt.Println(n*10 < len(g)*int64(len(g)) && n*10 < int64(len(g)) ? g[n*10] : 0)
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

func id5(a []int64, b []int64) []int64 {
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

var id8 = []int{1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681}
var id4 = []int{7, 6, 3, 5, 3, 3, 3, 3, 3, 17}

func id6(a []int64, b []int64, P int, g int) []int64 {
	m := max(2, 1<<(32-__builtin_clz(max(len(a), len(b))-1)<<2))
	fa := id9(a, m, false, P, g)
	fb := a
	if a != b {
		fb = id9(b, m, false, P, g)
	}
	for i := 0; i < m; i++ {
		fa[i] = fa[i] * fb[i] % int64(P)
	}
	return id9(fa, m, true, P, g)
}

func id3(a []int64, b []int64) []int64 {
	USE := 2
	m := max(2, 1<<(32-__builtin_clz(max(len(a), len(b))-1)<<2))
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := id8[k]
		g := id4[k]
		fa := id9(a, m, false, P, g)
		fb := a
		if a != b {
			fb = id9(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = fa[i] * fb[i] % int64(P)
		}
		fs[k] = id9(fa, m, true, P, g)
	}

	mods := id8[:USE]
	gammas := id1(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := id7(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = ret*int64(mods[j]) + res[j]
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func id3(a []int64, b []int64, USE int, mod int) []int64 {
	m := max(2, 1<<(32-__builtin_clz(max(len(a), len(b))-1)<<2))
	fs := make([][]int64, USE)
	for k := 0; k < USE; k++ {
		P := id8[k]
		g := id4[k]
		fa := id9(a, m, false, P, g)
		fb := a
		if a != b {
			fb = id9(b, m, false, P, g)
		}
		for i := 0; i < m; i++ {
			fa[i] = fa[i] * fb[i] % int64(P)
		}
		fs[k] = id9(fa, m, true, P, g)
	}

	mods := id8[:USE]
	gammas := id1(mods)
	buf := make([]int, USE)
	for i := 0; i < len(fs[0]); i++ {
		for j := 0; j < USE; j++ {
			buf[j] = int(fs[j][i])
		}
		res := id7(buf, mods, gammas)
		ret := int64(0)
		for j := len(res) - 1; j >= 0; j-- {
			ret = (ret*int64(mods[j]) + res[j]) % int64(mod)
		}
		fs[0][i] = ret
	}
	return fs[0]
}

func id9(src []int64, n int, inverse bool, P int, g int) []int64 {
	dst := make([]int64, n)

	h := __builtin_ctz(n)
	K := int64(1) << 32
	M := K * K / int64(P)

	wws := make([]int64, 1<<(h-1))
	dw := int64(0)
	if inverse {
		dw = pow(int64(g), int64(P-1-(P-1)/n), int64(P))
	} else {
		dw = pow(int64(g), int64((P-1)/n), int64(P))
	}
	w := (1 << 32) % P
	for k := 0; k < 1<<(h-1); k++ {
		wws[k] = int64(w)
		w = modh(w*dw, M, h, P)
	}

	J := invl(int64(P), int64(1)<<32)
	for i := 0; i < h; i++ {
		for j := 0; j < 1<<i; j++ {
			for k, s, t := 0, j<<h-i, j<<h-i|1<<(h-i-1); k < 1<<(h-i-1); k, s, t = k+1, s+1, t+1 {
				u := (dst[s] - dst[t] + 2*int64(P)) * wws[k]
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
		rev := __builtin_bswap32(uint32(i)) >> (32 - h)
		if i < int(rev) {
			d := dst[i]
			dst[i] = dst[rev]
			dst[rev] = d
		}
	}

	if inverse {
		in := invl(int64(n), int64(P))
		for i := 0; i < n; i++ {
			dst[i] = modh(dst[i]*in, M, h, P)
		}
	}

	return dst
}

func id1(m []int) []int64 {
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

func id7(u []int, m []int, gamma []int64) []int64 {
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
	x := 63 - __builtin_clz(int(n))
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func modh(a, M int64, h, mod int) int64 {
	r := a - ((M*(a&((1<<31)-1))>>31)+M*(a>>31)>>(h-31))*int64(mod)
	if r < int64(mod) {
		return r
	}
	return r - int64(mod)
}

func main() {
	solve()
}

var reader = bufio.NewReader(os.Stdin)
var scanner = bufio.NewScanner(os.Stdin)

func init() {
	scanner.Split(bufio.ScanWords)
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func scanInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func scanInt64() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func scanFloat() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func scanBytes() []byte {
	reader.Read(inbuf)
	return inbuf
}

func ni() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nl() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nf() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func ns() string {
	scanner.Scan()
	return scanner.Text()
}

func na(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = ni()
	}
	return a
}

func nlArr(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nl()
	}
	return a
}

func nfArr(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = nf()
	}
	return a
}

func nsArr(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = ns()
	}
	return a
}

func printString(s string) {
	fmt.Print(s)
}

func printInt(n int) {
	fmt.Print(n)
}

func printInt64(n int64) {
	fmt.Print(n)
}

func printFloat(f float64) {
	fmt.Print(f)
}

func printBytes(b []byte) {
	os.Stdout.Write(b)
}

func printlnString(s string) {
	fmt.Println(s)
}

func printlnInt(n int) {
	fmt.Println(n)
}

func printlnInt64(n int64) {
	fmt.Println(n)
}

func printlnFloat(f float64) {
	fmt.Println(f)
}

func printlnBytes(b []byte) {
	os.Stdout.Write(b)
}

func printfString(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func printfInt(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func printfInt64(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func printfFloat(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func printfBytes(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

func println() {
	fmt.Println()
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - __builtin_clz(int(n))
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func __builtin_clz(x int) int {
	return 31 - bits.Len32(uint32(x))
}

func __builtin_bswap32(x uint32) uint32 {
	return bits.Reverse32(x)
}

func __builtin_ctz(x int) int {
	return bits.TrailingZeros32(uint32(x))
}

func __builtin_popcount(x int) int {
	return bits.OnesCount32(uint32(x))
}
