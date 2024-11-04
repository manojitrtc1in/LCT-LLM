package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	out        *bufio.Writer
	in         *bufio.Scanner
	IMPOSSIBLE = "IMPOSSIBLE"
	POSSIBLE   = "POSSIBLE"
	YES        = "YES"
	NO         = "NO"
)

func initIO(isFileIO bool) {
	if os.Getenv("ONLINE_JUDGE") == "" && isFileIO {
		inFile, _ := os.Open("input.txt")
		outFile, _ := os.Create("output.txt")
		in = bufio.NewScanner(inFile)
		out = bufio.NewWriter(outFile)
	} else {
		in = bufio.NewScanner(os.Stdin)
		out = bufio.NewWriter(os.Stdout)
	}
}

func main() {
	initIO(true)
	run()
	out.Flush()
}

func run() {
	isDebug := false
	isFileIO := true
	hasMultipleTests := false

	t := 1
	if hasMultipleTests {
		t = nextInt()
	}

	for i := 1; i <= t; i++ {
		if isDebug {
			fmt.Fprintf(out, "Test %d\n", i)
		}

		getInput()

		ans := solve()

		printOutput(ans)
	}
}

var n, k, f int

func getInput() {
	n = nextInt()
	k = nextInt()
	f = nextInt()
}

func printOutput(ans int) {
	fmt.Fprintln(out, ans)
}

const MOD = 998244353

func solve() int {
	ans := 0

	ways := make([]int64, f+2+f+2)
	suffix := make([]int64, f+2)

	for i := 0; i <= k && i <= f; i++ {
		ways[i] = 1
	}
	ways[f+1] = max(0, k-f)

	for i := 0; i < n; i++ {
		if i < n-1 {
			square(ways)

			var val int64
			for j := len(ways) - 1; j >= f+1; j-- {
				val += ways[j]
			}
			val %= MOD
			suffix[f+1] = val

			for j := f; j >= 0; j-- {
				val = suffix[j+1] + ways[j]
				val = val%MOD
				suffix[j] = val
			}

			for j := 0; j <= k && j <= f; j++ {
				val := suffix[j]

				val += ways[j] * (int64)(k-j)

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

const ROOT = int(pow(3, 7*17, MOD))
const ROOT_INV = int(pow(ROOT, int(MOD-2), MOD))
const ORDER = 1 << 23

func swap(a []int64, i, j int) {
	temp := a[i]
	a[i] = a[j]
	a[j] = temp
}

func fft(a []int64, isInvertedFFT bool) {
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
		wlen := int64(1)
		if isInvertedFFT {
			wlen = int64(ROOT_INV)
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

	if isInvertedFFT {
		inv := inverse(n, MOD)
		for i := 0; i < len(a); i++ {
			a[i] = a[i] * inv % MOD
		}
	}
}

func square(a []int64) {
	fft(a, false)
	for i := 0; i < len(a); i++ {
		a[i] = a[i] * a[i] % MOD
	}
	fft(a, true)
}

func multiplyPolynomial(a []int64, b []int64) []int64 {
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

func nextInt() int {
	in.Scan()
	num, _ := strconv.Atoi(in.Text())
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
