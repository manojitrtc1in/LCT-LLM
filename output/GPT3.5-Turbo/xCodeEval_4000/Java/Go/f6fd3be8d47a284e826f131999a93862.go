package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	IMPOSSIBLE = "IMPOSSIBLE"
	POSSIBLE   = "POSSIBLE"
	YES        = "YES"
	NO         = "NO"
)

type Round818E struct {
	out *MyPrintWriter
	in  *MyScanner
}

func (r *Round818E) initIO(isFileIO bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && isFileIO {
		file, err := os.Open("input.txt")
		if err != nil {
			panic(err)
		}
		r.in = NewMyScanner(file)
		file, err = os.Create("output.txt")
		if err != nil {
			panic(err)
		}
		r.out = NewMyPrintWriter(file)
	} else {
		r.in = NewMyScanner(os.Stdin)
		r.out = NewMyPrintWriter(os.Stdout)
	}
}

func main() {
	r := &Round818E{}
	r.run()
}

func (r *Round818E) run() {
	isDebug := false
	isFileIO := true
	hasMultipleTests := false

	r.initIO(isFileIO)

	t := 1
	if hasMultipleTests {
		t = r.in.nextInt()
	}

	for i := 1; i <= t; i++ {
		if isDebug {
			r.out.printf("Test %d\n", i)
		}

		r.getInput()

		r.solve()

		r.printOutput()
	}

	r.in.close()
	r.out.close()
}

var MOD int64 = 1_000_000_007

func (r *Round818E) test() {
	for i := 2; i <= 100; i++ {
		n := i
		compare := make([]int64, n+1)
		expected := int64(0)
		for a := 1; a <= n; a++ {
			for b := 1; b <= n; b++ {
				c := n - a - b
				if c < 0 {
					continue
				}
				g := gcd(int64(a), int64(b))
				gg := gcd(int64(c), g)
				expected += gg * (c/gg) * (g/gg)
				compare[g] += gg * (c/gg) * (g/gg)
			}
		}
		r.solve()
		if expected != r.ans {
			r.solve()
		}

	}
}

var n int

func (r *Round818E) getInput() {
	n = r.in.nextInt()
}

func (r *Round818E) printOutput() {
	r.out.printlnAns(r.ans)
}

var check []int64
var ans int64

func (r *Round818E) solve() {

	primeFactors := make([][]int, n+1)
	for i := 2; i <= n; i++ {
		primeFactors[i] = make([]int, 0)
	}

	for i := 2; i <= n; i++ {
		if len(primeFactors[i]) == 0 {
			primeFactors[i] = append(primeFactors[i], i)

			if n/i >= i {
				for j := i * i; j <= n; j += i {
					if len(primeFactors[j]) == 0 {
						primeFactors[j] = append(primeFactors[j], i)
					}
				}
			}
		} else {
			prime := primeFactors[i][0]
			rest := i / prime
			for rest%prime == 0 {
				rest /= prime
			}
			if rest > 1 {
				for _, factor := range primeFactors[rest] {
					primeFactors[i] = append(primeFactors[i], factor)
				}
			}
		}
	}

	ans = 0
	check = make([]int64, n+1)
	for g := int64(1); g <= int64(n); g++ {
		if g*2+1 > int64(n) {
			break
		}
		cnt := int64(0)
		sum := int64(0)

		for ap := 2; ap <= n; ap++ {
			if g*(int64(ap)+1)+1 > int64(n) {
				break
			}

			maxBp := min(ap-1, (n-1)/int(g)-ap)
			currCnt := maxBp
			sum += maxBp * (maxBp + 1) / 2 % MOD

			k := len(primeFactors[ap])
			for mask := 1; mask < (1 << k); mask++ {
				curr := int64(1)
				sign := int64(1)
				for pos := 0; pos < k; pos++ {
					if (mask & (1 << pos)) > 0 {
						curr *= int64(primeFactors[ap][pos])
						sign *= -1
					}
				}

				s := min((ap-1)/int(curr), (n-1-int(g)*ap)/int(curr)/int(g))

				currCnt += int64(s) * sign
				sum += curr * int64(s) * (int64(s) + 1) / 2 * sign
			}

			cnt += currCnt
			sum += currCnt * int64(ap)
			sum %= MOD

		}

		cnt *= 2
		sum *= int64(g) * 2

		cnt++
		sum += int64(g) * 2

		cnt %= MOD
		sum %= MOD
		if sum < 0 {
			sum += MOD
		}

		check[g] -= ans
		k := gcd(int64(g), int64(n))
		ans += int64(g) * int64(n) / k * cnt % MOD
		ans -= int64(g) / k * sum % MOD
		check[g] += ans
	}
	ans %= MOD
	if ans < 0 {
		ans += MOD
	}
}

func gcd(a, b int64) int64 {
	if a < b {
		temp := b
		b = a
		a = temp
	}

	for b > 0 {
		r := a % b
		a = b
		b = r
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Pair struct {
	first  int
	second int
}

func (p *Pair) hashCode() int {
	var x int64 = int64(p.first)
	x <<= 32
	x += int64(p.second)
	x += 0x9e3779b97f4a7c15
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb
	return int(x ^ (x >> 31))
}

func (p *Pair) equals(obj *Pair) bool {
	other := obj
	return p.first == other.first && p.second == other.second
}

func (p *Pair) String() string {
	return "[" + strconv.Itoa(p.first) + "," + strconv.Itoa(p.second) + "]"
}

func (p *Pair) compareTo(o *Pair) int {
	cmp := strconv.Itoa(p.first) < strconv.Itoa(o.first)
	if cmp != 0 {
		return cmp
	}
	return strconv.Itoa(p.second) < strconv.Itoa(o.second)
}

type MyScanner struct {
	br *bufio.Reader
	st *strings.Reader
}

func NewMyScanner(r io.Reader) *MyScanner {
	return &MyScanner{br: bufio.NewReader(r)}
}

func (s *MyScanner) Close() {
	err := s.br.Reset(nil)
	if err != nil {
		panic(err)
	}
}

func (s *MyScanner) next() string {
	for s.st == nil || !s.st.Len() {
		str, err := s.br.ReadString('\n')
		if err != nil {
			panic(err)
		}
		s.st = strings.NewReader(str)
	}
	str, err := s.st.ReadString(' ')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(str)
}

func (s *MyScanner) nextInt() int {
	num, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return num
}

func (s *MyScanner) nextLong() int64 {
	num, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (s *MyScanner) nextDouble() float64 {
	num, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return num
}

func (s *MyScanner) nextLine() string {
	str, err := s.br.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(str)
}

func (s *MyScanner) nextMatrix(n, m int) [][]int {
	return s.nextMatrixWithOffset(n, m, 0)
}

func (s *MyScanner) nextMatrixWithOffset(n, m, offset int) [][]int {
	mat := make([][]int, n)
	for i := 0; i < n; i++ {
		mat[i] = make([]int, m)
		for j := 0; j < m; j++ {
			mat[i][j] = s.nextInt() + offset
		}
	}
	return mat
}

func (s *MyScanner) nextTransposedMatrix(n, m int) [][]int {
	return s.nextTransposedMatrixWithOffset(n, m, 0)
}

func (s *MyScanner) nextTransposedMatrixWithOffset(n, m, offset int) [][]int {
	mat := make([][]int, m)
	for i := 0; i < m; i++ {
		mat[i] = make([]int, n)
		for j := 0; j < n; j++ {
			mat[i][j] = s.nextInt() + offset
		}
	}
	return mat
}

func (s *MyScanner) nextIntArray(len int) []int {
	return s.nextIntArrayWithOffset(len, 0)
}

func (s *MyScanner) nextIntArrayWithOffset(len, offset int) []int {
	arr := make([]int, len)
	for j := 0; j < len; j++ {
		arr[j] = s.nextInt() + offset
	}
	return arr
}

func (s *MyScanner) nextLongArray(len int) []int64 {
	return s.nextLongArrayWithOffset(len, 0)
}

func (s *MyScanner) nextLongArrayWithOffset(len, offset int) []int64 {
	arr := make([]int64, len)
	for j := 0; j < len; j++ {
		arr[j] = s.nextLong() + int64(offset)
	}
	return arr
}

func (s *MyScanner) nextStringArray(len int) []string {
	arr := make([]string, len)
	for i := 0; i < len; i++ {
		arr[i] = s.next()
	}
	return arr
}

type MyPrintWriter struct {
	writer *bufio.Writer
}

func NewMyPrintWriter(w io.Writer) *MyPrintWriter {
	return &MyPrintWriter{writer: bufio.NewWriter(w)}
}

func (p *MyPrintWriter) Close() {
	err := p.writer.Flush()
	if err != nil {
		panic(err)
	}
}

func (p *MyPrintWriter) printlnAns(ans int) {
	p.println(ans)
}

func (p *MyPrintWriter) printlnAnsSplit(arr []int, split int) {
	if arr != nil {
		for i := 0; i < len(arr); i += split {
			p.print(arr[i])
			for j := i + 1; j < i+split; j++ {
				p.print(" ")
				p.print(arr[j])
			}
			p.println()
		}
	}
}

func (p *MyPrintWriter) printlnAnsSplitLong(arr []int64, split int) {
	if arr != nil {
		for i := 0; i < len(arr); i += split {
			p.print(arr[i])
			for j := i + 1; j < i+split; j++ {
				p.print(" ")
				p.print(arr[j])
			}
			p.println()
		}
	}
}

func (p *MyPrintWriter) printlnAnsLong(ans int64) {
	p.println(ans)
}

func (p *MyPrintWriter) printlnAns(arr []int) {
	p.printAns(arr)
	p.println()
}

func (p *MyPrintWriter) printlnAnsLong(arr []int64) {
	p.printAnsLong(arr)
	p.println()
}

func (p *MyPrintWriter) printlnAns(arr []string) {
	p.printAns(arr)
	p.println()
}

func (p *MyPrintWriter) printlnAnsSplit(arr []string, split int) {
	if arr != nil && len(arr) > 0 {
		for i := 0; i < len(arr); i += split {
			p.print(arr[i])
			for j := i + 1; j < i+split; j++ {
				p.print(" ")
				p.print(arr[j])
			}
			p.println()
		}
	}
}

func (p *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		p.print(arr[0])
		for i := 1; i < len(arr); i++ {
			p.print(" ")
			p.print(arr[i])
		}
	}
}

func (p *MyPrintWriter) printAnsLong(arr []int64) {
	if arr != nil && len(arr) > 0 {
		p.print(arr[0])
		for i := 1; i < len(arr); i++ {
			p.print(" ")
			p.print(arr[i])
		}
	}
}

func (p *MyPrintWriter) printAns(arr []string) {
	if arr != nil && len(arr) > 0 {
		p.print(arr[0])
		for i := 1; i < len(arr); i++ {
			p.print(" ")
			p.print(arr[i])
		}
	}
}

func (p *MyPrintWriter) println() {
	p.print("\n")
}

func (p *MyPrintWriter) print(a ...interface{}) {
	_, err := fmt.Fprint(p.writer, a...)
	if err != nil {
		panic(err)
	}
}

func (p *MyPrintWriter) println(a ...interface{}) {
	_, err := fmt.Fprintln(p.writer, a...)
	if err != nil {
		panic(err)
	}
}

func gcd(a, b int64) int64 {
	if a < b {
		temp := b
		b = a
		a = temp
	}

	for b > 0 {
		r := a % b
		a = b
		b = r
	}
	return a
}

func main() {
	sol := &Round818E{}
	sol.run()
}
