package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MOD      = 998244353
	YES      = "YES"
	NO       = "NO"
	ROOT     = 1 // Placeholder for actual value
	ROOT_INV = 1 // Placeholder for actual value
	ORDER    = 1 << 23
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (ms *MyScanner) nextInt() int {
	ms.scanner.Scan()
	val, _ := strconv.Atoi(ms.scanner.Text())
	return val
}

type id5 struct {
	writer *bufio.Writer
}

func NewId5(output *os.File) *id5 {
	return &id5{writer: bufio.NewWriter(output)}
}

func (out *id5) printlnAns(ans int) {
	fmt.Fprintln(out.writer, ans)
}

func (out *id5) close() {
	out.writer.Flush()
}

type id4 struct {
	out *id5
	in  *MyScanner
}

func (sol *id4) initIO(id8 bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && id8 {
		inputFile, _ := os.Open("input.txt")
		outputFile, _ := os.Create("output.txt")
		sol.in = NewMyScanner()
		sol.out = NewId5(outputFile)
		sol.in.scanner = bufio.NewScanner(inputFile)
	} else {
		sol.in = NewMyScanner()
		sol.out = NewId5(os.Stdout)
	}
}

func (sol *id4) run() {
	isDebug := false
	id8 := true
	id2 := false

	sol.initIO(id8)

	t := 1
	if id2 {
		t = sol.in.nextInt()
	}

	for i := 1; i <= t; i++ {
		if isDebug {
			sol.out.printlnAns(i)
		}

		sol.getInput()
		ans := sol.solve()
		sol.printOutput(ans)
	}

	sol.out.close()
}

var n, k, f int

func (sol *id4) getInput() {
	n = sol.in.nextInt()
	k = sol.in.nextInt()
	f = sol.in.nextInt()
}

func (sol *id4) printOutput(ans int) {
	sol.out.printlnAns(ans)
}

func (sol *id4) solve() int {
	ans := 0

	len := 1
	for len < f+2+f+2 {
		len <<= 1
	}
	ways := make([]int64, len)
	suffix := make([]int64, f+2)

	for i := 0; i <= k && i <= f; i++ {
		ways[i] = 1
	}
	ways[f+1] = int64(max(0, k-f))

	for i := 0; i < n; i++ {
		if i < n-1 {
			square(ways)
			val := int64(0)
			for j := len - 1; j >= f+1; j-- {
				val += ways[j]
			}
			val %= MOD
			suffix[f+1] = val

			for j := f; j >= 0; j-- {
				val = suffix[j+1] + ways[j]
				if val >= MOD {
					val -= MOD
				}
				suffix[j] = val
			}

			for j := 0; j <= k && j <= f; j++ {
				val = suffix[j]
				val += ways[j] * int64(k-j)
				val %= MOD
				ways[j] = val
			}
			val = suffix[f+1] * int64(max(0, k-f))
			val %= MOD
			ways[f+1] = val
			for j := k + 1; j < f+2; j++ {
				ways[j] = 0
			}
			for j := f + 2; j < len; j++ {
				ways[j] = 0
			}
		} else {
			for j := 0; j <= f; j++ {
				ans += int(ways[j] * ways[f-j] % MOD)
			}
			ans %= MOD
		}
	}

	return ans
}

func square(a []int64) {
	fft4(a, false)
	for i := 0; i < len(a); i++ {
		a[i] = a[i] * a[i] % MOD
	}
	fft4(a, true)
}

func fft4(a []int64, id0 bool) {
	n := len(a)

	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for (j & bit) > 0 {
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
			wlen := 1 // Placeholder for actual value
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
			len *= 4
		}
	} else {
		len = 4
	}

	for len <= n {
		wlen := 1 // Placeholder for actual value
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

				y0 := (x0 + x1 + x2 + x3) % MOD
				a[i+j] = y0
				y1 := (x0 + x1 - x2 - x3 + MOD) % MOD
				a[i+j+len*3/4] = y1
				y2 := (x0 - x1 + x2 - x3 + MOD) % MOD
				a[i+j+len/2] = y2
				y3 := (x0 - x1 - x2 + x3 + MOD) % MOD
				a[i+j+len/4] = y3

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

func swap(a []int64, i, j int) {
	temp := a[i]
	a[i] = a[j]
	a[j] = temp
}

func inverse(a, p int) int64 {
	return pow(a, p-2, p)
}

func pow(a, k, p int) int64 {
	m := int64(k)
	ans := int64(1)
	curr := int64(a)

	for m > 0 {
		if (m & 1) == 1 {
			ans = ans * curr % int64(p)
		}
		m >>= 1
		curr = curr * curr % int64(p)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	sol := &id4{}
	sol.run()
}
