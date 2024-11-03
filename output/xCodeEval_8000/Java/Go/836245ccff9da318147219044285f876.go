package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod int64 = 1000000007
var mod2 int64 = 998244353
var inp *FastReader
var out *bufio.Writer

type _InVoker_ struct {
	pref []int64
}

func main() {
	inp = NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	g := _InVoker_{}
	g.main()
}

func (g *_InVoker_) main() {
	n := inp.NextInt()
	a := make([]int64, n)
	input(a, n)
	if n > 66 {
		fmt.Println(1)
		return
	}
	g.pref = make([]int64, n+1)
	g.pref[1] = a[0]
	for i := 1; i < n; i++ {
		g.pref[i+1] = g.pref[i] ^ a[i]
	}
	gg := 34
	for c := 0; c < n-1; c++ {
		for left := c; left >= 0; left-- {
			for right := c + 1; right < n; right++ {
				if g.xor(left, c) > g.xor(c+1, right) {
					gg = min(gg, right-left-1)
				}
			}
		}
	}
	if gg == 34 {
		fmt.Println(-1)
	} else {
		fmt.Println(gg)
	}
}

func (g *_InVoker_) xor(i, j int) int64 {
	return g.pref[j+1] ^ g.pref[i]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type FastReader struct {
	br *bufio.Reader
	st []string
}

func NewFastReader() *FastReader {
	return &FastReader{
		br: bufio.NewReader(os.Stdin),
	}
}

func (r *FastReader) Next() string {
	for len(r.st) == 0 {
		s, _ := r.br.ReadString('\n')
		r.st = strings.Split(strings.TrimSpace(s), " ")
	}
	val := r.st[0]
	r.st = r.st[1:]
	return val
}

func (r *FastReader) NextInt() int {
	val, _ := strconv.Atoi(r.Next())
	return val
}

func (r *FastReader) NextLong() int64 {
	val, _ := strconv.ParseInt(r.Next(), 10, 64)
	return val
}

func (r *FastReader) NextDouble() float64 {
	val, _ := strconv.ParseFloat(r.Next(), 64)
	return val
}

func (r *FastReader) NextLine() string {
	s, _ := r.br.ReadString('\n')
	return strings.TrimSpace(s)
}

func input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = inp.NextLong()
	}
}
