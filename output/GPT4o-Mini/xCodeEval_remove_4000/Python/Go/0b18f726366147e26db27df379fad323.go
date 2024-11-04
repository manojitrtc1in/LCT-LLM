package main

import (
	"fmt"
	"strings"
)

var A = []string{"0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6"}

func fromBase(X string) int {
	base := "0123456789`~!@"
	l := len(base)
	r := 0
	e := 1
	for _, c := range X {
		index := strings.IndexByte(base, byte(c))
		r += index * e
		e *= l
	}
	return r
}

func solve() {
	var N, mod int
	fmt.Scan(&N, &mod)
	fmt.Println(fromBase(A[N]) % mod)
}

func main() {
	T := 1
	for t := 0; t < T; t++ {
		solve()
	}
}
