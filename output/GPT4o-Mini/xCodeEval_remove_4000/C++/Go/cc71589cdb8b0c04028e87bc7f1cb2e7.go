package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

const (
	INF      = int(1e9)
	INF64    = int64(1e18)
	MOD      = int(1e9) + 7
	EPS      = 1e-9
	PI       = 3.141592653589793
	N        = 1000 + 7
)

var (
	lim  = []int64{0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099}
	pr1  = []string{"", "198", "19", "2", "", "", "", "", "", ""}
	pr2  = []string{"", "199", "20", "3", "1", "1", "1", "1", "1", "1"}
	n    int
	s    string
)

func read() bool {
	var buf [N]byte
	if _, err := fmt.Scanf("%s", &buf); err != nil {
		return false
	}
	s = string(buf[:])
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
	file, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	tc := 0
	fmt.Fscanf(file, "%d", &tc)

	start := time.Now()

	for tc > 0 {
		tc--
		if !read() {
			break
		}
		fmt.Println(solve())
		fmt.Printf("TIME = %v\n", time.Since(start))
		start = time.Now()
	}
}
