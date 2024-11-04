package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func main() {
	defer out.Flush()
	solve()
}

func solve() {
	n := nl()
	ans := int64(0)
	ml := NewMeisselLehmer2(n / 2)
	for i := 0; i < len(ml.primes); i++ {
		plus := ml.pi(n/ml.primes[i]) - int64(i+1)
		if plus <= 0 {
			break
		}
		ans += plus
	}

	for _, p := range ml.primes {
		if int64(p)*int64(p)*int64(p) <= n {
			ans++
		} else {
			break
		}
	}
	fmt.Fprintln(out, ans)
}

type MeisselLehmer2 struct {
	primes    []int
	xcums     []int
	isp       []int
	cachelimit int
	picache   map[int64]int64
	phicache  map[int64]int64
	cachePhi  bool
	cumps     [][]int
	FP        []int
	M         int
	B         int
}

func NewMeisselLehmer2(n int64) *MeisselLehmer2 {
	ml := &MeisselLehmer2{}
	ml.primes = sieveEratosthenes(int(n))
	ml.xcums = make([]int, (n>>6)+1)
	ml.isp = make([]int, (n>>6)+1)
	for _, p := range ml.primes {
		ml.isp[p>>6] |= 1 << (p & 63)
	}
	for i := 0; i < len(ml.xcums)-1; i++ {
		ml.xcums[i+1] = ml.xcums[i] + bitsCount(ml.isp[i])
	}

	ml.cumps = make([][]int, ml.M)
	b := []bool{true}
	len := 1
	for i := 0; i < ml.M; i++ {
		len *= ml.FP[i]
		c := make([]bool, len)
		for j := 0; j < ml.FP[i]; j++ {
			copy(c[j*len/ml.FP[i]:], b)
		}
		for k := 0; k < len; k += ml.FP[i] {
			c[k] = false
		}
		ml.cumps[i] = make([]int, len+1)
		for j := 0; j < len; j++ {
			ml.cumps[i][j+1] = ml.cumps[i][j] + boolToInt(c[j])
		}
		ml.FP[i] = len
		b = c
	}
	return ml
}

func (ml *MeisselLehmer2) pi(x int64) int64 {
	if x <= int64(ml.cachelimit) {
		ix := int(x)
		return int64(ml.xcums[ix>>6]) + int64(bitsCount(ml.isp[ix>>6]<<^ix))
	}
	if ml.picache == nil {
		ml.picache = make(map[int64]int64)
	}
	if v, ok := ml.picache[x]; ok {
		return v
	}
	A := ml.pi(int64(sqrt(sqrt(float64(x)))))
	ret := A + ml.phi(x, A) - ml.P2(x, A) - ml.P3(x, A) - 1
	ml.picache[x] = ret
	return ret
}

func (ml *MeisselLehmer2) phi(x int64, A int64) int64 {
	if A > 0 && A-1 < int64(ml.M) {
		return int64(ml.cumps[A-1][ml.FP[A-1]])*(x/int64(ml.FP[A-1])) + int64(ml.cumps[A-1][int(x%int64(ml.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(ml.primes[A-1])*int64(ml.primes[A-1]) {
		return ml.pi(x) - A + 1
	}
	code := x<<13 | A
	if ml.phicache == nil {
		ml.phicache = make(map[int64]int64)
	}
	if v, ok := ml.phicache[code]; ok {
		return v
	}
	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= ml.phi(x/int64(ml.primes[i]), i)
	}
	if ml.cachePhi {
		ml.phicache[code] = ret
	}
	return ret
}

func (ml *MeisselLehmer2) P2(x int64, A int64) int64 {
	B := int64(ml.pi(int64(sqrt(float64(x)))))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += ml.pi(x/int64(ml.primes[i]))
	}
	ret -= (B - A) * (B + A - 1) / 2
	return ret
}

func (ml *MeisselLehmer2) P3(x int64, A int64) int64 {
	C := int64(ml.pi(int64(cbrt(float64(x)))))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(ml.primes[i])
		B := int64(ml.pi(int64(sqrt(float64(xi)))))
		for j := i; j < B; j++ {
			ret += ml.pi(xi/int64(ml.primes[j])) - int64(j)
		}
	}
	return ret
}

func sieveEratosthenes(n int) []int {
	if n <= 32 {
		primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
		for i := 0; i < len(primes); i++ {
			if n < primes[i] {
				return primes[:i]
			}
		}
		return primes
	}

	u := n + 32
	lu := math.Log(float64(u))
	ret := make([]int, int(u/lu+u/lu/lu*1.5))
	ret[0] = 2
	pos := 1

	isnp := make([]int, (n+1)/32/2+1)
	sup := (n + 1) / 32 / 2 + 1

	tprimes := []int{3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
	for _, tp := range tprimes {
		ret[pos] = tp
		pos++
		ptn := make([]int, tp)
		for i := (tp - 3) / 2; i < tp<<5; i += tp {
			ptn[i>>5] |= 1 << (i & 31)
		}
		for j := 0; j < sup; j += tp {
			for i := 0; i < tp && i+j < sup; i++ {
				isnp[j+i] |= ptn[i]
			}
		}
	}

	magic := []int{0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14}
	h := n / 2
	for i := 0; i < sup; i++ {
		for j := ^isnp[i]; j != 0; j &= j - 1 {
			pp := i<<5 | magic[(j&-j)*0x076be629>>27]
			p := 2*pp + 3
			if p > n {
				break
			}
			ret[pos] = p
			pos++
			if int64(p)*int64(p) > int64(n) {
				continue
			}
			for q := (p*p - 3) / 2; q <= h; q += p {
				isnp[q>>5] |= 1 << q
			}
		}
	}

	return ret[:pos]
}

func sqrt(n float64) int64 {
	i := int64(math.Max(0, math.Sqrt(n)-2))
	for i*i <= int64(n) {
		i++
	}
	return i - 1
}

func cbrt(n float64) int64 {
	i := int64(math.Max(0, math.Cbrt(n)-2))
	for i*i*i <= int64(n) {
		i++
	}
	return i - 1
}

func bitsCount(x int) int {
	return bitsCount64(uint64(x))
}

func bitsCount64(x uint64) int {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555)
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333)
	x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f)
	x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff)
	x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff)
	x = (x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff)
	return int(x)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func nextInt() int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextInt64() int64 {
	sc.Scan()
	i, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return i
}

func nextFloat64() float64 {
	sc.Scan()
	f, _ := strconv.ParseFloat(sc.Text(), 64)
	return f
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextIntSlice(n int) []int {
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = nextInt()
	}
	return s
}

func nextInt64Slice(n int) []int64 {
	s := make([]int64, n)
	for i := 0; i < n; i++ {
		s[i] = nextInt64()
	}
	return s
}

func nextFloat64Slice(n int) []float64 {
	s := make([]float64, n)
	for i := 0; i < n; i++ {
		s[i] = nextFloat64()
	}
	return s
}

func nextStringSlice(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = nextString()
	}
	return s
}

func nextIntMatrix(r, c int) [][]int {
	m := make([][]int, r)
	for i := 0; i < r; i++ {
		m[i] = nextIntSlice(c)
	}
	return m
}

func nextInt64Matrix(r, c int) [][]int64 {
	m := make([][]int64, r)
	for i := 0; i < r; i++ {
		m[i] = nextInt64Slice(c)
	}
	return m
}

func nextFloat64Matrix(r, c int) [][]float64 {
	m := make([][]float64, r)
	for i := 0; i < r; i++ {
		m[i] = nextFloat64Slice(c)
	}
	return m
}

func nextStringMatrix(r, c int) [][]string {
	m := make([][]string, r)
	for i := 0; i < r; i++ {
		m[i] = nextStringSlice(c)
	}
	return m
}

func nextIntGrid(r, c int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1] - '0')
		}
	}
	return g
}

func nextStringGrid(r, c int) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1])
		}
	}
	return g
}

func nextIntGridWithoutBorder(r, c int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j] - '0')
		}
	}
	return g
}

func nextStringGridWithoutBorder(r, c int) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j])
		}
	}
	return g
}

func nextIntGridWithBorder(r, c int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1] - '0')
		}
	}
	return g
}

func nextStringGridWithBorder(r, c int) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1])
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValue(r, c, defaultValue int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j] - '0')
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValue(r, c int, defaultValue string) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j])
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValue(r, c, defaultValue int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1] - '0')
		}
	}
	return g
}

func nextStringGridWithBorderWithDefaultValue(r, c int, defaultValue string) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1])
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValueAndOffset(r, c, defaultValue, offset int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue + offset
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j]) - '0' + offset
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValueAndOffset(r, c, offset int, defaultValue string) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j] + byte(offset))
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValueAndOffset(r, c, defaultValue, offset int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue + offset
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1]) - '0' + offset
		}
	}
	return g
}

func nextStringGridWithBorderWithDefaultValueAndOffset(r, c, offset int, defaultValue string) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1] + byte(offset))
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValueAndOffsetAndOffset(r, c, defaultValue, offset, offset2 int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue + offset + offset2
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j]) - '0' + offset + offset2
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValueAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2 int) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j] + byte(offset) + byte(offset2))
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValueAndOffsetAndOffset(r, c, defaultValue, offset, offset2 int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue + offset + offset2
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1]) - '0' + offset + offset2
		}
	}
	return g
}

func nextStringGridWithBorderWithDefaultValueAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2 int) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1] + byte(offset) + byte(offset2))
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3 int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j]) - '0' + offset + offset2 + offset3
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2, offset3 int) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j] + byte(offset) + byte(offset2) + byte(offset3))
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValueAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3 int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1]) - '0' + offset + offset2 + offset3
		}
	}
	return g
}

func nextStringGridWithBorderWithDefaultValueAndOffsetAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2, offset3 int) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1] + byte(offset) + byte(offset2) + byte(offset3))
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3, offset4 int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3 + offset4
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j]) - '0' + offset + offset2 + offset3 + offset4
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2, offset3, offset4 int) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j] + byte(offset) + byte(offset2) + byte(offset3) + byte(offset4))
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3, offset4 int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3 + offset4
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1]) - '0' + offset + offset2 + offset3 + offset4
		}
	}
	return g
}

func nextStringGridWithBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2, offset3, offset4 int) [][]string {
	g := make([][]string, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]string, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = string(s[j-1] + byte(offset) + byte(offset2) + byte(offset3) + byte(offset4))
		}
	}
	return g
}

func nextIntGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3, offset4, offset5 int) [][]int {
	g := make([][]int, r)
	for i := 0; i < r; i++ {
		g[i] = make([]int, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3 + offset4 + offset5
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = int(s[j]) - '0' + offset + offset2 + offset3 + offset4 + offset5
		}
	}
	return g
}

func nextStringGridWithoutBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffsetAndOffset(r, c, offset int, defaultValue string, offset2, offset3, offset4, offset5 int) [][]string {
	g := make([][]string, r)
	for i := 0; i < r; i++ {
		g[i] = make([]string, c)
		for j := 0; j < c; j++ {
			g[i][j] = defaultValue
		}
	}
	for i := 0; i < r; i++ {
		s := nextString()
		for j := 0; j < c; j++ {
			g[i][j] = string(s[j] + byte(offset) + byte(offset2) + byte(offset3) + byte(offset4) + byte(offset5))
		}
	}
	return g
}

func nextIntGridWithBorderWithDefaultValueAndOffsetAndOffsetAndOffsetAndOffsetAndOffset(r, c, defaultValue, offset, offset2, offset3, offset4, offset5 int) [][]int {
	g := make([][]int, r+2)
	for i := 0; i < r+2; i++ {
		g[i] = make([]int, c+2)
		for j := 0; j < c+2; j++ {
			g[i][j] = defaultValue + offset + offset2 + offset3 + offset4 + offset5
		}
	}
	for i := 1; i <= r; i++ {
		s := nextString()
		for j := 1; j <= c; j++ {
			g[i][j] = int(s[j-1]) - '0' + offset + offset2 + offset3 + offset4 + offset5
		}
	}
	return g
}

