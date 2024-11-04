package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	solve()
}

func solve() {
	n := readInt()
	s := readLong()

	f := id12(n)

	coeffs := make(map[int64]int64)
	coeffs[0] = 1

	type Pair struct {
		power int64
		coeff int64
	}

	for _, size := range f {
		coeffEntries := make([]Pair, 0)
		for power, coeff := range coeffs {
			nextPower := power + size + 1
			coeffEntries = append(coeffEntries, Pair{
				power: nextPower,
				coeff: -coeff,
			})
		}

		for _, coeffEntry := range coeffEntries {
			coeffs[coeffEntry.power] = add(coeffs[coeffEntry.power], coeffEntry.coeff)
		}
	}

	id25 := multSequence(1, n-1)
	id34 := inverse(id25)

	answer := int64(0)
	for power, coeff := range coeffs {
		if s >= power {
			need := s - power
			answer = add(answer, mult(binom(n+need-1, need), coeff))
		}
	}

	fmt.Fprintln(out, answer)
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

	if power&1 == 0 {
		half := binpow(base, power>>1)
		return mult(half, half)
	} else {
		prev := binpow(base, power-1)
		return mult(prev, base)
	}
}

func binom(n, k int64) int64 {
	return mult(multSequence(k+1, n), id34)
}

func add(a, b int64) int64 {
	return ((a%MODULO + b%MODULO) % MODULO + MODULO) % MODULO
}

func mult(a, b int64) int64 {
	return (a%MODULO)*(b%MODULO) % MODULO
}

func readString() string {
	str, _ := in.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func readInt() int {
	num, _ := strconv.Atoi(readString())
	return num
}

func readLong() int64 {
	num, _ := strconv.ParseInt(readString(), 10, 64)
	return num
}
