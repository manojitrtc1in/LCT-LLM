package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

const MODULO = 1000000007

type Pair struct {
	power, coeff int64
}

var id34 int64

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	n, s := readInt(r), readInt64(r)

	f := id12(n)

	coeffs := make(map[int64]int64)
	coeffs[0] = 1

	for _, size := range f {
		coeffEntries := []Pair{}
		for power, coeff := range coeffs {
			nextPower := power + size + 1
			coeffEntries = append(coeffEntries, Pair{nextPower, -coeff})
		}

		for _, coeffEntry := range coeffEntries {
			coeffs[coeffEntry.power] = add(coeffs[coeffEntry.power], coeffEntry.coeff)
		}
	}

	id25 := multSequence(1, int64(n-1))
	id34 = inverse(id25)

	answer := int64(0)
	for power, coeff := range coeffs {
		if s >= power {
			need := s - power
			answer = add(answer, mult(binom(int64(n)+need-1, need), coeff))
		}
	}

	fmt.Fprintln(w, answer)
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
	}
	return mult(binpow(base, power-1), base)
}

func binom(n, k int64) int64 {
	return mult(multSequence(k+1, n), id34)
}

func add(a, b int64) int64 {
	return ((a%MODULO + b%MODULO) % MODULO + MODULO) % MODULO
}

func mult(a, b int64) int64 {
	return (a % MODULO) * (b % MODULO) % MODULO
}

func readInt(r *bufio.Reader) int {
	var x int
	fmt.Fscan(r, &x)
	return x
}

func readInt64(r *bufio.Reader) int64 {
	var x int64
	fmt.Fscan(r, &x)
	return x
}

func id12(size int) []int64 {
	array := make([]int64, size)
	for i := 0; i < size; i++ {
		array[i] = readInt64(bufio.NewReader(os.Stdin))
	}
	return array
}
