package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

const mod = 1000000007
const mod2 = 998244353

var inp = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

type InVoker struct {
	pref     []int64
	fact     []int64
	invFact  []int64
}

func main() {
	defer out.Flush()
	g := InVoker{}
	g.main()
}

func (g *InVoker) main() {
	n := g.nextInt()
	a := make([]int64, n)
	g.input(a, n)
	if n > 66 {
		fmt.Fprintln(out, 1)
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
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, gg)
	}
}

func (g *InVoker) xor(i, j int) int64 {
	return g.pref[j+1] ^ g.pref[i]
}

func (g *InVoker) input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = g.nextLong()
	}
}

func (g *InVoker) nextInt() int {
	s, _ := inp.ReadString('\n')
	val, _ := strconv.Atoi(s[:len(s)-1])
	return val
}

func (g *InVoker) nextLong() int64 {
	s, _ := inp.ReadString('\n')
	val, _ := strconv.ParseInt(s[:len(s)-1], 10, 64)
	return val
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
