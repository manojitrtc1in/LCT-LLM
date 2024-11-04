package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var mod = int(math.Pow(10, 9)) + 7
var n int
var m int
var a [][][]int
var st []string

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextLong(scanner)
	m := nextInt(scanner)
	a := make([][]int, m)

	for i := 0; i < m; i++ {
		a[i] = make([]int, 2)
		a[i][0] = n / m
	}

	for i := 1; i <= n%m; i++ {
		a[i][0]++
	}

	b := make([]int, m)
	for i := 0; i < m; i++ {
		t := ((i) % m * (i) % m) % m
		b[t] += a[i][0]
	}

	ans := 0
	for i := 0; i < m; i++ {
		if i == 0 {
			ans += (b[i] * (b[i]))
		} else {
			ans += b[i] * b[m-i]
		}
	}

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}
