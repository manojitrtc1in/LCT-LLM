package main

import (
	"bufio"
	"fmt"
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

type RoundEdu132F struct {
	out *MyPrintWriter
	in  *MyScanner
}

func (sol *RoundEdu132F) initIO(isFileIO bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && isFileIO {
		fileIn, _ := os.Open("input.txt")
		fileOut, _ := os.Create("output.txt")
		sol.in = NewMyScanner(bufio.NewReader(fileIn))
		sol.out = NewMyPrintWriter(fileOut)
	} else {
		sol.in = NewMyScanner(bufio.NewReader(os.Stdin))
		sol.out = NewMyPrintWriter(os.Stdout)
	}
}

func main() {
	sol := &RoundEdu132F{}
	sol.run()
}

func (sol *RoundEdu132F) run() {
	isDebug := false
	isFileIO := true
	hasMultipleTests := false

	sol.initIO(isFileIO)

	t := 1
	if hasMultipleTests {
		t = sol.in.nextInt()
	}

	for i := 1; i <= t; i++ {
		if isDebug {
			sol.out.printf("Test %d\n", i)
		}

		sol.getInput()

		ans := sol.solve()

		sol.printOutput(ans)
	}

	sol.in.close()
	sol.out.close()
}

func (sol *RoundEdu132F) getInput() {
	n := sol.in.nextInt()
	k := sol.in.nextInt()
	f := sol.in.nextInt()
}

func (sol *RoundEdu132F) printOutput(ans int) {
	sol.out.printlnAns(ans)
}

const MOD = 998244353

func (sol *RoundEdu132F) solve() int {
	ans := 0

	var ways []int
	var suffix []int

	for i := 0; i <= k && i <= f; i++ {
		ways[i] = 1
	}
	ways[f+1] = max(0, k-f)

	for i := 0; i < n; i++ {
		if i < n-1 {
			sol.square(ways)
			val := 0
			for j := len(ways) - 1; j >= f+1; j-- {
				val += ways[j]
			}
			val %= MOD
			suffix[f+1] = val

			for j := f; j >= 0; j-- {
				val := suffix[j+1] + ways[j]
				val = val % MOD
				suffix[j] = val
			}

			for j := 0; j <= k && j <= f; j++ {
				val := suffix[j]

				val += ways[j] * (k - j)

				val %= MOD
				ways[j] = val
			}

			val := suffix[f+1] * max(0, k-f)
			val %= MOD
			ways[f+1] = val

			for j := k + 1; j < f+2; j++ {
				ways[j] = 0
			}
			for j := f + 2; j < len(ways); j++ {
				ways[j] = 0
			}

		} else {
			for j := 0; j <= f; j++ {
				ans += ways[j] * ways[f-j] % MOD
			}
			ans %= MOD
		}
	}

	return ans
}

func pow(a, k int, p int) int {
	m := k
	ans := 1

	curr := a

	for m > 0 {
		if m&1 == 1 {
			ans *= curr
			ans %= p
		}
		m >>= 1
		curr *= curr
		curr %= p
	}
	return ans
}

func inverse(a, p int) int {
	return pow(a, p-2, p)
}

const ROOT = pow(3, 7*17, MOD)
const ROOT_INV = pow(ROOT, MOD-2, MOD)
const ORDER = 1 << 23
const W4 = pow(ROOT, (MOD-1)/4, MOD)
const W4_INV = pow(ROOT, (MOD-1)/4*3, MOD)

func swap(a []int, i, j int) {
	temp := a[i]
	a[i] = a[j]
	a[j] = temp
}

func fft(a []int, isInvertedFFT bool) {
	n := len(a)

	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for (j & bit) > 0 {
			j ^= bit
			bit >>= 1
		}
		j ^= bit

		if i < j {
			swap(a, i, j)
		}
	}

	for len := 2; len <= n; len <<= 1 {
		wlen := ROOT
		if isInvertedFFT {
			wlen = ROOT_INV
		}
		for i := len; i < ORDER; i <<= 1 {
			wlen = wlen * wlen % MOD
		}

		for i := 0; i < n; i += len {
			w := 1
			for j := 0; j < len/2; j++ {
				u := a[i+j]
				v := a[i+j+len/2] * w % MOD
				a[i+j] = (u + v) % MOD
				a[i+j+len/2] = (u - v + MOD) % MOD
				w = w * wlen % MOD
			}
		}
	}

	if isInvertedFFT {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func fft4(a []int, isInvertedFFT bool) {
	n := len(a)

	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for (j & bit) > 0 {
			j ^= bit
			bit >>= 1
		}
		j ^= bit

		if i < j {
			swap(a, i, j)
		}
	}

	parity := 0
	for len := 2; len <= n; len <<= 1 {
		parity++
	}

	var len int
	if parity%2 == 1 {
		len = 2
		if len <= n {
			wlen := ROOT
			if isInvertedFFT {
				wlen = ROOT_INV
			}
			for i := len; i < ORDER; i <<= 1 {
				wlen = wlen * wlen % MOD
			}

			for i := 0; i < n; i += len {
				w := 1
				for j := 0; j < len/2; j++ {
					x0 := a[i+j]
					x1 := a[i+j+len/2] * w % MOD
					x2 := a[i+j+len/4] * w % MOD
					x2 = x2 * w % MOD
					x3 := a[i+j+len*3/4] * w % MOD
					x3 = x3 * w % MOD
					x3 = x3 * w % MOD

					y0 := x0 + x1 + x2 + x3
					a[i+j] = y0 % MOD
					y1 := x0 + x1*w4 - x2 - x3*w4
					y1 %= MOD
					if y1 < 0 {
						y1 += MOD
					}
					a[i+j+len*3/4] = y1
					y2 := x0 - x1 + x2 - x3
					y2 %= MOD
					if y2 < 0 {
						y2 += MOD
					}
					a[i+j+len/2] = y2
					y3 := x0 - x1*w4 - x2 + x3*w4
					y3 %= MOD
					if y3 < 0 {
						y3 += MOD
					}
					a[i+j+len/4] = y3

					w = w * wlen % MOD
				}
			}
			len *= 4
		}
	} else {
		len = 4
	}

	for len <= n {
		wlen := ROOT
		if isInvertedFFT {
			wlen = ROOT_INV
		}
		w4 := W4
		if isInvertedFFT {
			w4 = W4_INV
		}
		for i := len; i < ORDER; i <<= 1 {
			wlen = wlen * wlen % MOD
		}

		for i := 0; i < n; i += len {
			w := 1
			for j := 0; j < len/4; j++ {
				x0 := a[i+j]
				x1 := a[i+j+len/2] * w % MOD
				x2 := a[i+j+len/4] * w % MOD
				x2 = x2 * w % MOD
				x3 := a[i+j+len*3/4] * w % MOD
				x3 = x3 * w % MOD
				x3 = x3 * w % MOD

				y0 := x0 + x1 + x2 + x3
				a[i+j] = y0 % MOD
				y1 := x0 + x1*w4 - x2 - x3*w4
				y1 %= MOD
				if y1 < 0 {
					y1 += MOD
				}
				a[i+j+len*3/4] = y1
				y2 := x0 - x1 + x2 - x3
				y2 %= MOD
				if y2 < 0 {
					y2 += MOD
				}
				a[i+j+len/2] = y2
				y3 := x0 - x1*w4 - x2 + x3*w4
				y3 %= MOD
				if y3 < 0 {
					y3 += MOD
				}
				a[i+j+len/4] = y3

				w = w * wlen % MOD
			}
		}

		len <<= 2
	}

	if isInvertedFFT {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func square(a []int) {
	fft4(a, false)
	for i := 0; i < len(a); i++ {
		a[i] = a[i] * a[i] % MOD
	}
	fft4(a, true)
}

func multiplyPolynomial(a []int, b []int) []int {
	n := 1
	for n < len(a)+len(b) {
		n <<= 1
	}
	fa := make([]int, n)
	fb := make([]int, n)

	copy(fa, a)
	copy(fb, b)

	fft(fa, false)
	fft(fb, false)
	for i := 0; i < n; i++ {
		fa[i] = fa[i] * fb[i] % MOD
	}
	fft(fa, true)

	return fa
}

type MyScanner struct {
	br *bufio.Reader
}

func NewMyScanner(br *bufio.Reader) *MyScanner {
	return &MyScanner{br: br}
}

func (ms *MyScanner) close() {
	ms.br = nil
}

func (ms *MyScanner) next() string {
	for ms.br == nil || !strings.ContainsRune(" \t\n\r\v\f", ms.peek()) {
		str, _ := ms.br.ReadString('\n')
		ms.br = bufio.NewReader(strings.NewReader(str))
	}
	str, _ := ms.br.ReadString(' ')
	return strings.TrimSpace(str)
}

func (ms *MyScanner) nextInt() int {
	num, _ := strconv.Atoi(ms.next())
	return num
}

func (ms *MyScanner) nextLong() int64 {
	num, _ := strconv.ParseInt(ms.next(), 10, 64)
	return num
}

func (ms *MyScanner) nextDouble() float64 {
	num, _ := strconv.ParseFloat(ms.next(), 64)
	return num
}

func (ms *MyScanner) nextLine() string {
	str, _ := ms.br.ReadString('\n')
	return strings.TrimSpace(str)
}

type MyPrintWriter struct {
	wr *bufio.Writer
}

func NewMyPrintWriter(wr *bufio.Writer) *MyPrintWriter {
	return &MyPrintWriter{wr: wr}
}

func (mpw *MyPrintWriter) close() {
	mpw.wr.Flush()
	mpw.wr = nil
}

func (mpw *MyPrintWriter) printlnAns(ans int) {
	mpw.println(ans)
}

func (mpw *MyPrintWriter) printlnAnsSplit(arr []int, split int) {
	if arr != nil {
		for i := 0; i < len(arr); i += split {
			mpw.print(arr[i])
			for j := i + 1; j < i+split; j++ {
				mpw.print(" ")
				mpw.print(arr[j])
			}
			mpw.println()
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int, add int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0] + add)
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i] + add)
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int, add int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0]+add)
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i]+add)
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

func (mpw *MyPrintWriter) printlnAns(arr []int, add int) {
	mpw.printAns(arr, add)
	mpw.println()
}

type MyScanner struct {
	br *bufio.Reader
}

func NewMyScanner(br *bufio.Reader) *MyScanner {
	return &MyScanner{br: br}
}

func (ms *MyScanner) close() {
	ms.br = nil
}

func (ms *MyScanner) next() string {
	for ms.br == nil || !strings.ContainsRune(" \t\n\r\v\f", ms.peek()) {
		str, _ := ms.br.ReadString('\n')
		ms.br = bufio.NewReader(strings.NewReader(str))
	}
	str, _ := ms.br.ReadString(' ')
	return strings.TrimSpace(str)
}

func (ms *MyScanner) nextInt() int {
	num, _ := strconv.Atoi(ms.next())
	return num
}

func (ms *MyScanner) nextLong() int64 {
	num, _ := strconv.ParseInt(ms.next(), 10, 64)
	return num
}

func (ms *MyScanner) nextDouble() float64 {
	num, _ := strconv.ParseFloat(ms.next(), 64)
	return num
}

func (ms *MyScanner) nextLine() string {
	str, _ := ms.br.ReadString('\n')
	return strings.TrimSpace(str)
}

type MyPrintWriter struct {
	wr *bufio.Writer
}

func NewMyPrintWriter(wr *bufio.Writer) *MyPrintWriter {
	return &MyPrintWriter{wr: wr}
}

func (mpw *MyPrintWriter) close() {
	mpw.wr.Flush()
	mpw.wr = nil
}

func (mpw *MyPrintWriter) printlnAns(ans int) {
	mpw.println(ans)
}

func (mpw *MyPrintWriter) printlnAnsSplit(arr []int, split int) {
	if arr != nil {
		for i := 0; i < len(arr); i += split {
			mpw.print(arr[i])
			for j := i + 1; j < i+split; j++ {
				mpw.print(" ")
				mpw.print(arr[j])
			}
			mpw.println()
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func (mpw *MyPrintWriter) printlnAns(arr []int) {
	mpw.printAns(arr)
	mpw.println()
}

func (mpw *MyPrintWriter) printAns(arr []int) {
	if arr != nil && len(arr) > 0 {
		mpw.print(arr[0])
		for i := 1; i < len(arr); i++ {
			mpw.print(" ")
			mpw.print(arr[i])
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
