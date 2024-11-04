package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

var (
	reader *bufio.Reader
	writer *bufio.Writer
)

func solve() {
	l, _ := nextInt()
	r, _ := nextInt()

	ans := 0
	for l <= r && l < 3 {
		if l == 2 {
			ans++
		}
		l++
	}

	segSize := 250000
	certainty := 30
	for r >= l && r%segSize != 0 {
		if r%4 == 1 && big.NewInt(int64(r)).ProbablyPrime(certainty) {
			ans++
		}
		r--
	}

	for l <= r && l%segSize != 0 {
		if l%4 == 1 && big.NewInt(int64(l)).ProbablyPrime(certainty) {
			ans++
		}
		l++
	}

	if l < r {
		for l != r {
			ans += ans[r/segSize-1]
			r -= segSize
		}
	}

	if l == r && l%4 == 1 && big.NewInt(int64(l)).ProbablyPrime(certainty) {
		ans++
	}

	println(ans)
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func nextToken() string {
	for tokenizer == nil || !tokenizer.HasMoreTokens() {
		tokenizer = bufio.NewScanner(reader)
		tokenizer.Split(bufio.ScanWords)
	}
	return tokenizer.Text()
}

func nextInt() (int, error) {
	token := nextToken()
	return strconv.Atoi(token)
}

func nextLong() (int64, error) {
	token := nextToken()
	return strconv.ParseInt(token, 10, 64)
}

func nextDouble() (float64, error) {
	token := nextToken()
	return strconv.ParseFloat(token, 64)
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}
