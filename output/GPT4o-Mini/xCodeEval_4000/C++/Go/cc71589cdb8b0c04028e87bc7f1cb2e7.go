package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	N      = 1000 + 7
	INF    = int(1e9)
	INF64  = int64(1e18)
	MOD    = int(1e9) + 7
	EPS    = 1e-9
	PI     = 3.141592653589793
)

var lim = []int64{0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099}
var pr1 = []string{"", "198", "19", "2", "", "", "", "", "", ""}
var pr2 = []string{"", "199", "20", "3", "1", "1", "1", "1", "1", "1"}

var n int
var s string

func read() bool {
	_, err := fmt.Scan(&s)
	if err != nil {
		return false
	}
	s = s[4:]
	n = len(s)
	return true
}

func solve() string {
	x := int64(0)
	fmt.Sscan(s, &x)
	if x >= lim[n] {
		return pr1[n] + s
	}
	return pr2[n] + s
}

func main() {
	rand.Seed(time.Now().UnixNano())

	var tc int
	fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		if read() {
			fmt.Println(solve())
		}
	}
}
