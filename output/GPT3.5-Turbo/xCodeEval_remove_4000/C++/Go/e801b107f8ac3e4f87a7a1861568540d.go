package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var MOD int64 = 1e9 + 7
var MX int64 = 2e5 + 5
var INF int64 = 1e18
var PI float64 = 3.14159265358979323846
var xd = []int64{1, 0, -1, 0}
var yd = []int64{0, 1, 0, -1}

func nod(a, b int64) int64 {
	if b > a {
		a, b = b, a
	}
	for b > 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func nok(a, b int64) int64 {
	return a * b / nod(a, b)
}

func sp(a int64, b float64) {
	fmt.Printf("%.f", a)
	fmt.Printf("%.10f", b)
}

func binpow(a, n int64) int64 {
	if n == 0 {
		return 1
	}
	if n%2 == 1 {
		return binpow(a, n-1) * a
	} else {
		b := binpow(a, n/2)
		return b * b
	}
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int64 {
	s := readString()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

func readFloat() float64 {
	s := readString()
	n, _ := strconv.ParseFloat(s, 64)
	return n
}

func readInts() []int64 {
	s := readString()
	fields := strings.Fields(s)
	ints := make([]int64, len(fields))
	for i, f := range fields {
		ints[i], _ = strconv.ParseInt(f, 10, 64)
	}
	return ints
}

func readFloats() []float64 {
	s := readString()
	fields := strings.Fields(s)
	floats := make([]float64, len(fields))
	for i, f := range fields {
		floats[i], _ = strconv.ParseFloat(f, 64)
	}
	return floats
}

func writeString(s string) {
	fmt.Println(s)
}

func writeInt(n int64) {
	fmt.Println(n)
}

func writeFloat(n float64) {
	fmt.Println(n)
}

func writeInts(ints []int64) {
	for _, n := range ints {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}

func writeFloats(floats []float64) {
	for _, n := range floats {
		fmt.Printf("%.10f ", n)
	}
	fmt.Println()
}

func solve() {
	m := make(map[int64]int64)
	n, s, k := readInts()
	ans := MOD
	cnt := int64(0)
	for i := int64(1); i <= n; i++ {
		a := readInt()
		if i >= k {
			m[a-i*k]--
			if m[a-i*k] == 0 {
				cnt--
			}
			m[a]++
			if m[a] == 1 {
				cnt++
			}
			ans = min(ans, cnt)
		} else {
			m[a]++
			if m[a] == 1 {
				cnt++
			}
		}
	}
	ans = min(ans, cnt)
	writeInt(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	t := readInt()
	for i := int64(1); i <= t; i++ {
		solve()
	}
}
