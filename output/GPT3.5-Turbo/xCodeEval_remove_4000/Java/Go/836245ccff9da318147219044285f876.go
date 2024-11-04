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

type id1 struct {
	pref []int64
}

func main() {
	inp = NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	g := id1{}
	g.main()
}

func (g *id1) main() {
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

func (g *id1) xor(i, j int) int64 {
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
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (r *FastReader) Next() string {
	for {
		str, err := r.br.ReadString('\n')
		if err != nil || len(str) > 0 {
			return strings.TrimSpace(str)
		}
	}
}

func (r *FastReader) NextInt() int {
	num, _ := strconv.Atoi(r.Next())
	return num
}

func (r *FastReader) NextInt64() int64 {
	num, _ := strconv.ParseInt(r.Next(), 10, 64)
	return num
}

func (r *FastReader) NextFloat64() float64 {
	num, _ := strconv.ParseFloat(r.Next(), 64)
	return num
}

func (r *FastReader) NextLine() string {
	str, _ := r.br.ReadString('\n')
	return strings.TrimSpace(str)
}

func input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = inp.NextInt64()
	}
}
