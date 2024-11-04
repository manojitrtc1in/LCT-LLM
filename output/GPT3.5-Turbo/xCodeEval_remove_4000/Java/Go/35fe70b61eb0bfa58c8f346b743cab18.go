package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	mod   int64 = 998244353
	fact        []int64
	revFact     []int64
)

func solve() {
	n := ni()
	tmp := nl()
	if n <= tmp {
		fmt.Println(0)
		return
	}
	k := int(tmp)
	preFact(400000)
	var ans int64 = 0
	si := int64(1)
	t := cmb(n, n-k)
	for i := n - k; i >= 1; i-- {
		ans += si * cmb(n-k, i) * pow(i, n)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		si *= -1
	}
	ans *= t
	ans %= mod
	if k != 0 {
		ans *= 2
	}
	ans %= mod
	if ans < 0 {
		ans += mod
	}
	fmt.Println(ans)
}

func preFact(n int) {
	fact = make([]int64, n+1)
	revFact = make([]int64, n+1)
	fact[0] = 1
	for i := 0; i < n; i++ {
		fact[i+1] = mul(int64(i+1), fact[i])
	}
	revFact[n] = div(1, fact[n])
	for i := n - 1; i >= 0; i-- {
		revFact[i] = mul(revFact[i+1], int64(i+1))
	}
}

func cmb(a, b int) int64 {
	if a < b {
		return 0
	}
	if len(fact) == 0 {
		fmt.Println("error : factorials has not been culculated!! do [pre_factorial] method")
	}
	af := fact[a]
	bf := revFact[b]
	abf := revFact[a-b]
	res := mul(mul(af, bf), abf)
	return res
}

func inf() int {
	return int(^uint(0) >> 1) / 2
}

func linf() int64 {
	return int64(^uint64(0) >> 1) / 2
}

func dinf() float64 {
	return float64(^uint64(0) >> 1) / 2
}

func pow(x, y int64) int64 {
	if y < 0 {
		return 0
	}
	if y == 0 {
		return 1
	}
	if y%2 == 1 {
		return (x * pow(x, y-1)) % mod
	}
	root := pow(x, y/2)
	return (root * root) % mod
}

func plus(x, y int64) int64 {
	res := (x + y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func sub(x, y int64) int64 {
	res := (x - y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func mul(x, y int64) int64 {
	res := (x * y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func div(x, y int64) int64 {
	res := x * pow(y, mod-2) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func main() {
	solve()
}

var (
	scanner *bufio.Scanner
)

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func scanString() string {
	if scanner.Scan() {
		return scanner.Text()
	}
	return ""
}

func scanInt() int {
	i, _ := strconv.Atoi(scanString())
	return i
}

func scanInt64() int64 {
	i, _ := strconv.ParseInt(scanString(), 10, 64)
	return i
}

func scanFloat64() float64 {
	f, _ := strconv.ParseFloat(scanString(), 64)
	return f
}

func scanStrings(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = scanString()
	}
	return s
}

func scanInts(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}
	return a
}

func scanInt64s(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt64()
	}
	return a
}

func scanFloat64s(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = scanFloat64()
	}
	return a
}

func scan2DStrings(n, m int) [][]string {
	a := make([][]string, n)
	for i := 0; i < n; i++ {
		a[i] = scanStrings(m)
	}
	return a
}

func scan2DInts(n, m int) [][]int {
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInts(m)
	}
	return a
}

func scan2DInt64s(n, m int) [][]int64 {
	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt64s(m)
	}
	return a
}

func scan2DFloat64s(n, m int) [][]float64 {
	a := make([][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = scanFloat64s(m)
	}
	return a
}

func scanLines(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = scanLine()
	}
	return s
}

func scanLine() string {
	scanner.Scan()
	return scanner.Text()
}

func splitLine(line string) []string {
	return strings.Fields(line)
}

func splitLines(lines []string) [][]string {
	a := make([][]string, len(lines))
	for i, line := range lines {
		a[i] = splitLine(line)
	}
	return a
}

func splitInts(s string) []int {
	fields := strings.Fields(s)
	a := make([]int, len(fields))
	for i, f := range fields {
		a[i], _ = strconv.Atoi(f)
	}
	return a
}

func splitInt64s(s string) []int64 {
	fields := strings.Fields(s)
	a := make([]int64, len(fields))
	for i, f := range fields {
		a[i], _ = strconv.ParseInt(f, 10, 64)
	}
	return a
}

func splitFloat64s(s string) []float64 {
	fields := strings.Fields(s)
	a := make([]float64, len(fields))
	for i, f := range fields {
		a[i], _ = strconv.ParseFloat(f, 64)
	}
	return a
}

func joinStrings(a []string) string {
	return strings.Join(a, " ")
}

func joinInts(a []int) string {
	s := make([]string, len(a))
	for i, v := range a {
		s[i] = strconv.Itoa(v)
	}
	return strings.Join(s, " ")
}

func joinInt64s(a []int64) string {
	s := make([]string, len(a))
	for i, v := range a {
		s[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(s, " ")
}

func joinFloat64s(a []float64) string {
	s := make([]string, len(a))
	for i, v := range a {
		s[i] = strconv.FormatFloat(v, 'f', -1, 64)
	}
	return strings.Join(s, " ")
}
