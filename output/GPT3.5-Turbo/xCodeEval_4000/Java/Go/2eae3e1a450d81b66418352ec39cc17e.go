package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	l := nextInt(scanner)
	r := nextInt(scanner)

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

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func main() {
	solve()
}
