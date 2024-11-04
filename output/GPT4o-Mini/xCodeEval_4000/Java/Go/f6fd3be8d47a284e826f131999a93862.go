package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	IMPOSSIBLE = "IMPOSSIBLE"
	POSSIBLE   = "POSSIBLE"
	YES        = "YES"
	NO         = "NO"
	MOD        = 1_000_000_007
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (ms *MyScanner) NextInt() int {
	ms.scanner.Scan()
	val, _ := strconv.Atoi(ms.scanner.Text())
	return val
}

type MyPrintWriter struct {
	writer *bufio.Writer
}

func NewMyPrintWriter() *MyPrintWriter {
	return &MyPrintWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (mpw *MyPrintWriter) Println(ans int) {
	fmt.Fprintln(mpw.writer, ans)
}

func (mpw *MyPrintWriter) Close() {
	mpw.writer.Flush()
}

type Pair struct {
	first  int
	second int
}

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	for b > 0 {
		r := a % b
		a = b
		b = r
	}
	return a
}

type Round818E struct {
	n     int
	ans   int64
	check []int64
}

func (r *Round818E) getInput(scanner *MyScanner) {
	r.n = scanner.NextInt()
}

func (r *Round818E) printOutput(writer *MyPrintWriter) {
	writer.Println(r.ans)
}

func (r *Round818E) solve() {
	primeFactors := make([][]int, r.n+1)
	for i := 2; i <= r.n; i++ {
		primeFactors[i] = []int{}
	}

	for i := 2; i <= r.n; i++ {
		if len(primeFactors[i]) == 0 {
			primeFactors[i] = append(primeFactors[i], i)
			if r.n/i >= i {
				for j := i * i; j <= r.n; j += i {
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

	r.ans = 0
	r.check = make([]int64, r.n+1)
	for g := int64(1); g <= int64(r.n); g++ {
		if g*2+1 > int64(r.n) {
			break
		}
		cnt := int64(0)
		sum := int64(0)

		for ap := 2; ap <= r.n; ap++ {
			if g*(int64(ap)+1) > int64(r.n) {
				break
			}

			maxBp := min(int64(ap-1), (int64(r.n)-1)/g-int64(ap))
			currCnt := maxBp
			sum += maxBp*(maxBp+1)/2 % MOD

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

				s := min((int64(ap)-1)/curr, (int64(r.n)-1-g*int64(ap))/curr/g)

				currCnt += s * sign
				sum += curr * s * (s + 1) / 2 * sign
			}

			cnt += currCnt
			sum += currCnt * int64(ap)
			sum %= MOD
		}

		cnt *= 2
		sum *= g * 2

		cnt++
		sum += g * 2

		cnt %= MOD
		sum %= MOD
		if sum < 0 {
			sum += MOD
		}

		r.check[int(g)] -= r.ans
		k := gcd(int(g), r.n)
		r.ans += g*int64(r.n)/int64(k)*cnt%MOD
		r.ans -= g/int64(k)*sum%MOD
		r.check[int(g)] += r.ans
	}
	r.ans %= MOD
	if r.ans < 0 {
		r.ans += MOD
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := NewMyScanner()
	writer := NewMyPrintWriter()
	defer writer.Close()

	solution := Round818E{}
	t := 1
	for i := 1; i <= t; i++ {
		solution.getInput(scanner)
		solution.solve()
		solution.printOutput(writer)
	}
}
