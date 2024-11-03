package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var (
	l, r int
)

func main() {
	Load()
	Solve()
}

func Load() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	l, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	r, _ = strconv.Atoi(scanner.Text())
}

func f(n int) int {
	if n <= 1 {
		return 0
	}
	res := 0
	l := 0
	for l*shift <= n {
		l++
	}
	l--
	for i := l*shift + 1; i <= n; i++ {
		if !isPrime(i) {
			continue
		}
		ok := false
		for a := 1; !ok && a*a <= i; a++ {
			b := i - a*a
			bb := int(math.Round(math.Sqrt(float64(b))))
			ok = bb > 0 && bb*bb == b
		}
		if ok {
			res++
		}
	}
	return res + prec[l]
}

func Solve() {
