package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MOD      = 998244353
	YES      = "YES"
	NO       = "NO"
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner(r *os.File) *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(r)}
}

func (ms *MyScanner) nextInt() int {
	ms.scanner.Scan()
	var x int
	fmt.Sscan(ms.scanner.Text(), &x)
	return x
}

func (ms *MyScanner) close() {
	// No explicit close needed for bufio.Scanner
}

type id5 struct {
	writer *bufio.Writer
}

func NewId5(w *os.File) *id5 {
	return &id5{writer: bufio.NewWriter(w)}
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
		fileIn, _ := os.Open("input.txt")
		fileOut, _ := os.Create("output.txt")
		sol.in = NewMyScanner(fileIn)
		sol.out = NewId5(fileOut)
	} else {
		sol.in = NewMyScanner(os.Stdin)
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

	sol.in.close()
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
	var ans int64

	len := 1
	for len < f+2+f+2 {
		len <<= 1
	}
	ways := make([]int64, len)
	suffix := make([]int64, f+2)

	for i := 0; i <= k && i <= f; i++ {
		ways[i] = 1
	}
	ways[f+1] = max(0, k-f)

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
				val = (suffix[j+1] + ways[j]) % MOD
				suffix[j] = val
			}

			for j := 0; j <= k && j <= f; j++ {
				val = (suffix[j] + ways[j]*int64(k-j)) % MOD
				ways[j] = val
			}
			val = (suffix[f+1] * max(0, k-f)) % MOD
			ways[f+1] = val
			for j := k + 1; j < f+2; j++ {
				ways[j] = 0
			}
			for j := f + 2; j < len; j++ {
				ways[j] = 0
			}
		} else {
			for j := 0; j <= f; j++ {
				ans += ways[j] * ways[f-j] % MOD
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

func fft(a []int64, invert bool) {
	n := len(a)
	for i, j := 1, 0; i < n; i++ {
		bit := n >> 1
		for j&bit > 0 {
			bit >>= 1
			j ^= bit
		}
		j ^= bit
		if i < j {
			a[i], a[j] = a[j], a[i]
		}
	}

	for len := 2; len <= n; len <<= 1 {
		wlen := int64(1)
		if invert {
			wlen = pow(3, (MOD-2)/len, MOD)
		} else {
			wlen = 3
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

	if invert {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func pow(a, k, p int64) int64 {
	ans := int64(1)
	for k > 0 {
		if k&1 == 1 {
			ans = ans * a % p
		}
		k >>= 1
		a = a * a % p
	}
	return ans
}

func inverse(a, p int64) int64 {
	return pow(a, p-2, p)
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
