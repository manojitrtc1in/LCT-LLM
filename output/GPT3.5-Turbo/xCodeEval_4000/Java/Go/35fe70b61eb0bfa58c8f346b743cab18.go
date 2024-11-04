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
	fact       []int64
	revFact    []int64
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

var scanner = bufio.NewScanner(os.Stdin)

func init() {
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

func scanIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt()
	}
	return arr
}

func scanInt64Array(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt64()
	}
	return arr
}

func scanFloat64Array(n int) []float64 {
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = scanFloat64()
	}
	return arr
}

func scanStringArray(n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = scanString()
	}
	return arr
}

func scan2DIntArray(n, m int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = scanIntArray(m)
	}
	return arr
}

func scan2DInt64Array(n, m int) [][]int64 {
	arr := make([][]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt64Array(m)
	}
	return arr
}

func scan2DFloat64Array(n, m int) [][]float64 {
	arr := make([][]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = scanFloat64Array(m)
	}
	return arr
}

func scan2DStringArray(n, m int) [][]string {
	arr := make([][]string, n)
	for i := 0; i < n; i++ {
		arr[i] = scanStringArray(m)
	}
	return arr
}

func scanLines(n int) []string {
	lines := make([]string, n)
	for i := 0; i < n; i++ {
		lines[i] = scanString()
	}
	return lines
}

func scanBytes() []byte {
	scanner.Scan()
	return scanner.Bytes()
}

func atoi(b []byte) int {
	i, _ := strconv.Atoi(string(b))
	return i
}

func itoa(i int) []byte {
	return []byte(strconv.Itoa(i))
}

func nl() {
	fmt.Println()
}

func printf(format string, args ...interface{}) {
	fmt.Printf(format, args...)
}

func print(args ...interface{}) {
	fmt.Print(args...)
}

func println(args ...interface{}) {
	fmt.Println(args...)
}

func debugf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debug(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

func debugPrintf(format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugPrintln(args ...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugScanf(format string, args ...interface{}) {
	fmt.Fscanf(os.Stderr, format, args...)
}

func debugScan(args ...interface{}) {
	fmt.Fscan(os.Stderr, args...)
}

func debugScanln(args ...interface{}) {
	fmt.Fscanln(os.Stderr, args...)
}

func debugPrint(args ...interface{}) {
	fmt.Fprint(os.Stderr, args...)
}

