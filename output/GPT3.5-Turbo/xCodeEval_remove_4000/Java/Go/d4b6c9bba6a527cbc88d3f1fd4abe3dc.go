package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &MyScanner{scanner}
}

func (s *MyScanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *MyScanner) NextInt() int {
	num, _ := strconv.Atoi(s.Next())
	return num
}

func (s *MyScanner) NextLong() int64 {
	num, _ := strconv.ParseInt(s.Next(), 10, 64)
	return num
}

func (s *MyScanner) NextDouble() float64 {
	num, _ := strconv.ParseFloat(s.Next(), 64)
	return num
}

func (s *MyScanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

type id5 struct {
	writer *bufio.Writer
}

func Newid5() *id5 {
	return &id5{bufio.NewWriter(os.Stdout)}
}

func (w *id5) Println(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
}

func (w *id5) Printf(format string, a ...interface{}) {
	fmt.Fprintf(w.writer, format, a...)
}

func (w *id5) Close() {
	w.writer.Flush()
}

type id4 struct {
	out *id5
	in  *MyScanner
}

const (
	id9  = "id9"
	id11 = "id11"
	YES  = "YES"
	NO   = "NO"
)

func main() {
	sol := &id4{}
	sol.run()
}

func (sol *id4) run() {
	isDebug := false
	id8 := true
	id2 := false

	sol.initIO(id8)

	t := 1
	if id2 {
		t = sol.in.NextInt()
	}

	for i := 1; i <= t; i++ {
		if isDebug {
			sol.out.Printf("Test %d\n", i)
		}

		sol.getInput()

		ans := sol.solve()

		sol.printOutput(ans)
	}

	sol.in.Close()
	sol.out.Close()
}

func (sol *id4) initIO(id8 bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && id8 {
		file, _ := os.Open("input.txt")
		defer file.Close()
		sol.in = &MyScanner{bufio.NewScanner(file)}
		file, _ = os.Create("output.txt")
		defer file.Close()
		sol.out = Newid5()
	} else {
		sol.in = NewMyScanner()
		sol.out = Newid5()
	}
}

func (sol *id4) getInput() {
	sol.n = sol.in.NextInt()
	sol.k = sol.in.NextInt()
	sol.f = sol.in.NextInt()
}

func (sol *id4) printOutput(ans int) {
	sol.out.Println(ans)
}

const MOD = 998244353

var n, k, f int

func (sol *id4) solve() int {
	ans := 0

	ways := make([]int64, f+2)
	suffix := make([]int64, f+2)

	for i := 0; i <= k && i <= f; i++ {
		ways[i] = 1
	}
	ways[f+1] = max(0, k-f)

	for i := 0; i < sol.n; i++ {
		if i < sol.n-1 {
			sol.square(ways)

			val := int64(0)
			for j := len(ways) - 1; j >= f+1; j-- {
				val += ways[j]
			}
			val %= MOD
			suffix[f+1] = val

			for j := f; j >= 0; j-- {
				val := suffix[j+1] + ways[j]
				val = val%MOD
				suffix[j] = val
			}

			for j := 0; j <= k && j <= f; j++ {
				val := suffix[j]

				val += ways[j] * (int64(k - j))

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
				ans += int(ways[j] * ways[f-j] % MOD)
				ans %= MOD
			}
		}
	}

	return ans
}

func (sol *id4) square(a []int64) {
	sol.fft4(a, false)
	for i := 0; i < len(a); i++ {
		a[i] = a[i] * a[i] % MOD
	}
	sol.fft4(a, true)
}

func pow(a, k int, p int64) int64 {
	m := int64(k)
	ans := int64(1)
	curr := int64(a)

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

func inverse(a int, p int64) int64 {
	return pow(a, int(p-2), p)
}

const (
	ROOT      = int(pow(3, 7*17, MOD))
	ROOT_INV  = int(pow(ROOT, int(MOD-2), MOD))
	ORDER     = 1 << 23
	W4        = pow(ROOT, int((MOD-1)/4), MOD)
	id15      = pow(ROOT, int((MOD-1)/4*3), MOD)
)

func swap(a []int64, i, j int) {
	temp := a[i]
	a[i] = a[j]
	a[j] = temp
}

func fft(a []int64, id0 bool) {
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
		if id0 {
			wlen = ROOT_INV
		}
		for i := len; i < ORDER; i <<= 1 {
			wlen = wlen * wlen % MOD
		}

		for i := 0; i < n; i += len {
			w := int64(1)
			for j := 0; j < len/2; j++ {
				u := a[i+j]
				v := a[i+j+len/2] * w % MOD
				a[i+j] = (u + v) % MOD
				a[i+j+len/2] = (u - v + MOD) % MOD
				w = w * wlen % MOD
			}
		}
	}

	if id0 {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func fft4(a []int64, id0 bool) {
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

	len := 0
	if parity%2 == 1 {
		len = 2
		if len <= n {
			wlen := ROOT_INV
			for i := len; i < ORDER; i <<= 1 {
				wlen = wlen * wlen % MOD
			}

			for i := 0; i < n; i += len {
				w := int64(1)
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
		wlen := ROOT_INV
		w4 := W4
		for i := len; i < ORDER; i <<= 1 {
			wlen = wlen * wlen % MOD
		}

		for i := 0; i < n; i += len {
			w := int64(1)
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

	if id0 {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func multiplyPolynomial(a, b []int64) []int64 {
	n := 1
	for n < len(a)+len(b) {
		n <<= 1
	}
	fa := make([]int64, n)
	fb := make([]int64, n)

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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
