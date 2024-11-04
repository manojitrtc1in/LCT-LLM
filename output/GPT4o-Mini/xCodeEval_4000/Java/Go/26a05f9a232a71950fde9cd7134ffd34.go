package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

const MODULO = 1000000007

var inverseNMinus1Factorial int64

func main() {
	var n int
	var s int64
	fmt.Scan(&n, &s)

	f := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&f[i])
	}

	coeffs := make(map[int64]int64)
	coeffs[0] = 1

	type Pair struct {
		power int64
		coeff int64
	}

	for _, size := range f {
		coeffEntries := []Pair{}
		for power, coeff := range coeffs {
			nextPower := power + size + 1
			coeffEntries = append(coeffEntries, Pair{nextPower, -coeff})
		}

		for _, coeffEntry := range coeffEntries {
			coeffs[coeffEntry.power] += coeffEntry.coeff
		}
	}

	nMinus1Factorial := multSequence(1, int64(n-1))
	inverseNMinus1Factorial = inverse(nMinus1Factorial)

	answer := int64(0)
	for power, coeff := range coeffs {
		if s >= power {
			need := s - power
			answer = (answer + mult(binom(int64(n)+need-1, need), coeff)) % MODULO
		}
	}

	fmt.Println(answer)
}

func multSequence(start, end int64) int64 {
	res := int64(1)
	for i := start; i <= end; i++ {
		res = mult(res, i)
	}
	return res
}

func inverse(x int64) int64 {
	return binpow(x, MODULO-2)
}

func binpow(base, power int64) int64 {
	if power == 0 {
		return 1
	}
	if power%2 == 0 {
		half := binpow(base, power/2)
		return mult(half, half)
	} else {
		prev := binpow(base, power-1)
		return mult(prev, base)
	}
}

func binom(n, k int64) int64 {
	return mult(multSequence(k+1, n), inverseNMinus1Factorial)
}

func mult(a, b int64) int64 {
	return (a%MODULO)*(b%MODULO) % MODULO
}
