package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"time"
)

var (
	n, m int64
)

func modPow(a, b, M int64) int64 {
	if b == 0 {
		return 1
	}
	tmp := modPow(a, b/2, M)
	if b%2 == 0 {
		return (tmp * tmp) % M
	}
	return (((tmp * tmp) % M) * a) % M
}

func Input() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Split(input, " ")
	n, _ = strconv.ParseInt(parts[0], 10, 64)
	m, _ = strconv.ParseInt(parts[1], 10, 64)
}

func Solve() {
	A := (modPow(3, n, m) + m - 1) % m
	fmt.Println(A)
}

func main() {
	Input()
	start := time.Now()
	Solve()
	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %s seconds.\n", elapsed)
}
