package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	IMPOSSIBLE = "IMPOSSIBLE"
	POSSIBLE   = "POSSIBLE"
	YES        = "YES"
	NO         = "NO"
	MOD        = 998244353
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (ms *MyScanner) nextInt() int {
	ms.scanner.Scan()
	var x int
	fmt.Sscanf(ms.scanner.Text(), "%d", &x)
	return x
}

type MyPrintWriter struct {
	writer *bufio.Writer
}

func NewMyPrintWriter() *MyPrintWriter {
	return &MyPrintWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (mpw *MyPrintWriter) println(ans int) {
	fmt.Fprintln(mpw.writer, ans)
}

func (mpw *MyPrintWriter) close() {
	mpw.writer.Flush()
}

type RoundEdu132F struct {
	in  *MyScanner
	out *MyPrintWriter
	ans int
	n   int
	k   int
	f   int
}

func (r *RoundEdu132F) initIO(isFileIO bool) {
	if !isFileIO {
		r.in = NewMyScanner()
		r.out = NewMyPrintWriter()
	} else {
		// File I/O not implemented
	}
}

func (r *RoundEdu132F) run() {
	isFileIO := false
	r.initIO(isFileIO)

	t := 1
	for i := 1; i <= t; i++ {
		r.getInput()
		r.ans = r.solve()
		r.printOutput()
	}
	r.out.close()
}

func (r *RoundEdu132F) getInput() {
	r.n = r.in.nextInt()
	r.k = r.in.nextInt()
	r.f = r.in.nextInt()
}

func (r *RoundEdu132F) printOutput() {
	r.out.println(r.ans)
}

func (r *RoundEdu132F) solve() int {
	var ans int64 = 0
	len := 1
	for len < r.f+2+r.f+2 {
		len <<= 1
	}
	ways := make([]int64, len)
	suffix := make([]int64, r.f+2)

	for i := 0; i <= r.k && i <= r.f; i++ {
		ways[i] = 1
	}
	ways[r.f+1] = max(0, r.k-r.f)

	for i := 0; i < r.n; i++ {
		if i < r.n-1 {
			square(ways)
			val := int64(0)
			for j := len - 1; j >= r.f+1; j-- {
				val += ways[j]
			}
			val %= MOD
			suffix[r.f+1] = val
			for j := r.f; j >= 0; j-- {
				val = (suffix[j+1] + ways[j]) % MOD
				suffix[j] = val
			}
			for j := 0; j <= r.k && j <= r.f; j++ {
				val = (suffix[j] + ways[j]*int64(r.k-j)) % MOD
				ways[j] = val
			}
			val = (suffix[r.f+1] * max(0, r.k-r.f)) % MOD
			ways[r.f+1] = val
			for j := r.k + 1; j < r.f+2; j++ {
				ways[j] = 0
			}
			for j := r.f+2; j < len; j++ {
				ways[j] = 0
			}
		} else {
			for j := 0; j <= r.f; j++ {
				ans += ways[j] * ways[r.f-j] % MOD
			}
			ans %= MOD
		}
	}

	return int(ans)
}

func square(a []int64) {
	fft(a, false)
	for i := 0; i < len(a); i++ {
		a[i] = a[i] * a[i] % MOD
	}
	fft(a, true)
}

func fft(a []int64, isInvertedFFT bool) {
	n := len(a)
	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for (j & bit) > 0 {
			bit >>= 1
		}
		j ^= bit
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}
	for len := 2; len <= n; len <<= 1 {
		wlen := int64(1) // Placeholder for ROOT or ROOT_INV
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
	if isInvertedFFT {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func inverse(a int, p int64) int64 {
	return pow(a, p-2, p)
}

func pow(a int, k int64, p int64) int64 {
	m := k
	ans := int64(1)
	curr := int64(a)

	for m > 0 {
		if (m & 1) == 1 {
			ans = ans * curr % p
		}
		m >>= 1
		curr = curr * curr % p
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
	sol := &RoundEdu132F{}
	sol.run()
}
