package main

import (
	"fmt"
	"strconv"
	"strings"
)

func RL(typeFn func(string) interface{}) []interface{} {
	var input string
	fmt.Scan(&input)
	strs := strings.Split(input, " ")
	result := make([]interface{}, len(strs))
	for i, str := range strs {
		result[i] = typeFn(str)
	}
	return result
}

var A = []string{"0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6"}

func fromBase(X string) int {
	base := "0123456789`~!@"
	l := len(base)
	r := 0
	e := 1
	for _, c := range X {
		r += strings.Index(base, string(c)) * e
		e *= l
	}
	return r
}

func solve() {
	N, mod := RL(strconv.Atoi)
	fmt.Println(fromBase(A[N]) % mod)
}

func main() {
	T := 1
	for t := 0; t < T; t++ {
		solve()
	}
}
