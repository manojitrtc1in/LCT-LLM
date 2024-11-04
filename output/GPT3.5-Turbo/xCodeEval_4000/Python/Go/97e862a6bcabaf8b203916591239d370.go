package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	fmt.Fscan(reader, &n, &m)

	DP := make([]int, n+5)
	CUM := make([]int, n+5)
	CUM[1] = 0
	DP[1] = 1

	S := 1

	for i := 2; i <= n; i++ {
		CUM[i] = (CUM[i-1] + CUM[i]) % m
		DP[i] = (S + CUM[i]) % m
		S += DP[i]
		S %= m

		for j := i + i; j <= n; j += i {
			CUM[j] = (CUM[j] + DP[i] - DP[i-1]) % m
		}
	}

	fmt.Fprintln(writer, DP[n])
}

func scanInts(s string) []int {
	fields := strings.Fields(s)
	ints := make([]int, len(fields))
	for i, f := range fields {
		ints[i], _ = strconv.Atoi(f)
	}
	return ints
}
