package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanInt64() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanFloat() float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}

func printString(s string) {
	fmt.Fprint(writer, s)
}

func printInt(i int) {
	fmt.Fprint(writer, i)
}

func printInt64(i int64) {
	fmt.Fprint(writer, i)
}

func printFloat(f float64) {
	fmt.Fprint(writer, f)
}

func lowerBound(a []int, v int) int {
	l := 0
	r := len(a)
	for l < r {
		m := (l + r) / 2
		if a[m] >= v {
			r = m
		} else {
			l = m + 1
		}
	}
	return r
}

func pow(A [][]int, v []int, e int64) []int {
	mod := 998244353
	m2 := int64(mod) * int64(mod)
	big := 8 * m2

	for i := 0; i < len(v); i++ {
		if v[i] >= mod {
			v[i] %= mod
		}
	}

	MUL := A
	for e > 0 {
		if e&1 == 1 {
			v = mul(MUL, v, big, mod)
		}
		MUL = p2(MUL, big, mod)
		e >>= 1
	}

	return v
}

func mul(A [][]int, v []int, big, mod int) []int {
	m := len(A)
	n := len(v)
	w := make([]int, m)
	for i := 0; i < m; i++ {
		sum := int64(0)
		for k := 0; k < n; k++ {
			sum += int64(A[i][k]) * int64(v[k])
			if sum >= big {
				sum -= big
			}
		}
		w[i] = int(sum % int64(mod))
	}
	return w
}

func p2(A [][]int, big, mod int) [][]int {
	n := len(A)
	C := make([][]int, n)
	for i := 0; i < n; i++ {
		sum := make([]int64, n)
		for k := 0; k < n; k++ {
			for j := 0; j < n; j++ {
				sum[j] += int64(A[i][k]) * int64(A[k][j])
				if sum[j] >= big {
					sum[j] -= big
				}
			}
		}
		C[i] = make([]int, n)
		for j := 0; j < n; j++ {
			C[i][j] = int(sum[j] % int64(mod))
		}
	}
	return C
}

func solve() {
	n := scanInt()
	m := scanInt()
	ss := make([][]byte, n)
	oss := make([]string, n)
	for i := 0; i < n; i++ {
		ss[i] = []byte(scanString())
		oss[i] = string(ss[i])
	}
	offset := make([]int, n+1)
	offset[0] = 1
	for i := 0; i < n; i++ {
		offset[i+1] = offset[i] + len(ss[i]) - 1
	}
	U := offset[n] - 1

	D := 5
	M := make([][]int, (U+1)*D)
	for i := 0; i < (U+1)*D; i++ {
		M[i] = make([]int, (U+1)*D)
	}

	for i := 0; i < U+1; i++ {
		var lb, of int
		if i == 0 {
			lb = 0
			of = 0
		} else {
			lb = lowerBound(offset, i+1) - 1
			of = i - offset[lb] + 1
		}

		if i == 0 {
			for j := 0; j < n; j++ {
				for k := 0; k < n; k++ {
					if k != j && strings.HasPrefix(oss[k], oss[j]) {
						M[offset[k]+len(ss[j])-1][0+(U+1)*(len(ss[j])-1)] = 1
					}
				}
				M[0][0+(U+1)*(len(ss[j])-1)] += 1
			}
		} else {
			for j := 0; j < n; j++ {
				if oss[lb][of:] == oss[j] {
					M[0][i+(U+1)*(len(oss[j])-1)] += 2
				} else if strings.HasPrefix(oss[lb][of:], oss[j]) {
					M[i+len(ss[j])][i+(U+1)*(len(oss[j])-1)] += 1
				}
			}

			suf := oss[lb][of:]
			for j := 0; j < n; j++ {
				if strings.HasPrefix(oss[j], suf) && oss[j] != suf {
					M[offset[j]+len(suf)-1][i+(U+1)*(len(suf)-1)] += 1
				}
			}
		}
	}

	for i := 0; i < U+1; i++ {
		for j := 0; j < D-1; j++ {
			M[i+(U+1)*(j+1)][i+(U+1)*j] = 1
		}
	}

	v := make([]int, (U+1)*D)
	v[0] = 1
	v = pow(M, v, int64(m))

	printInt(v[0])
}

func main() {
	initIO()
	solve()
	flush()
}
