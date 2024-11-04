package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

const mod = 998244353
const m2 = mod * mod
const BIG = 8 * m2

type FastWriter struct {
	buf  bytes.Buffer
	out  io.Writer
}

func NewFastWriter(out io.Writer) *FastWriter {
	return &FastWriter{out: out}
}

func (fw *FastWriter) Write(b byte) {
	fw.buf.WriteByte(b)
	if fw.buf.Len() >= 8192 {
		fw.Flush()
	}
}

func (fw *FastWriter) WriteString(s string) {
	fw.buf.WriteString(s)
	if fw.buf.Len() >= 8192 {
		fw.Flush()
	}
}

func (fw *FastWriter) Flush() {
	fw.out.Write(fw.buf.Bytes())
	fw.buf.Reset()
}

func pow(A [][]int, v []int, e int64) []int {
	for i := range v {
		if v[i] >= mod {
			v[i] %= mod
		}
	}
	MUL := A
	for e > 0 {
		if e&1 == 1 {
			v = mul(MUL, v)
		}
		MUL = p2(MUL)
		e >>= 1
	}
	return v
}

func mul(A [][]int, v []int) []int {
	m := len(A)
	n := len(v)
	w := make([]int, m)
	for i := 0; i < m; i++ {
		var sum int64
		for k := 0; k < n; k++ {
			sum += int64(A[i][k]) * int64(v[k])
			if sum >= BIG {
				sum -= BIG
			}
		}
		w[i] = int(sum % int64(mod))
	}
	return w
}

func p2(A [][]int) [][]int {
	n := len(A)
	C := make([][]int, n)
	for i := range C {
		C[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		sum := make([]int64, n)
		for k := 0; k < n; k++ {
			for j := 0; j < n; j++ {
				sum[j] += int64(A[i][k]) * int64(A[k][j])
				if sum[j] >= BIG {
					sum[j] -= BIG
				}
			}
		}
		for j := 0; j < n; j++ {
			C[i][j] = int(sum[j] % int64(mod))
		}
	}
	return C
}

func lowerBound(a []int, v int) int {
	l, r := 0, len(a)
	for r-l > 1 {
		h := (r + l) >> 1
		if a[h] >= v {
			r = h
		} else {
			l = h
		}
	}
	return r
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)
	ss := make([]string, n)
	oss := make([]string, n)
	offset := make([]int, n+1)
	offset[0] = 1
	for i := 0; i < n; i++ {
		fmt.Scan(&ss[i])
		oss[i] = ss[i]
		offset[i+1] = offset[i] + len(ss[i]) - 1
	}
	U := offset[n] - 1
	D := 5
	M := make([][]int, (U+1)*D)
	for i := range M {
		M[i] = make([]int, (U+1)*D)
	}

	for i := 0; i <= U; i++ {
		lb, of := 0, 0
		if i != 0 {
			lb = lowerBound(offset, i+1) - 1
			of = i - offset[lb] + 1
		}

		if i == 0 {
			for j := 0; j < n; j++ {
				for k := 0; k < n; k++ {
					if k != j && oss[k][:len(oss[j])] == oss[j] {
						M[offset[k]+len(ss[j])-1][0+(U+1)*(len(ss[j])-1)] = 1
					}
				}
				M[0][0+(U+1)*(len(ss[j])-1)] += 1
			}
		} else {
			for j := 0; j < n; j++ {
				if oss[lb][of:] == oss[j] {
					M[0][i+(U+1)*(len(oss[j])-1)] += 2
				} else if oss[lb][of:len(oss[j])] == oss[j] {
					M[i+len(oss[j])][i+(U+1)*(len(oss[j])-1)] += 1
				}
			}

			suf := oss[lb][of:]
			for j := 0; j < n; j++ {
				if len(oss[j]) >= len(suf) && oss[j][:len(suf)] == suf && oss[j] != suf {
					M[offset[j]+len(suf)-1][i+(U+1)*(len(suf)-1)] += 1
				}
			}
		}
	}

	for i := 0; i <= U; i++ {
		for j := 0; j < D-1; j++ {
			M[i+(U+1)*(j+1)][i+(U+1)*j] = 1
		}
	}

	v := make([]int, (U+1)*D)
	v[0] = 1
	v = pow(M, v, int64(m))

	fmt.Println(v[0])
}

func main() {
	fw := NewFastWriter(os.Stdout)
	defer fw.Flush()
	solve()
}
