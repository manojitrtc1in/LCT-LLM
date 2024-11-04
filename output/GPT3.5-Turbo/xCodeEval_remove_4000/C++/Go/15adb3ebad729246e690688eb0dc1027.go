package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = int(1e9) + 7

var dp [61][8]int

func solve(n int64) {
	for i := 0; i < 61; i++ {
		for j := 0; j < 8; j++ {
			dp[i][j] = 0
		}
	}

	dp[0][0] = 1
	for i := int64(0); i < 60; i++ {
		bit := (1 << i) & n

		for j := 0; j < (1 << 3); j++ {
			if dp[i][j] == 0 {
				continue
			}

			for k := (j%2)^bit; k < 8; k += 2 {
				lol := j + k

				dp[i+1][lol/2] += dp[i][j]
				if dp[i+1][lol/2] >= MOD {
					dp[i+1][lol/2] -= MOD
				}
			}
		}
	}

	fmt.Println(dp[60][0])
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	tests := 0
	if scanner.Scan() {
		tests, _ = strconv.Atoi(scanner.Text())
	}

	for tests > 0 {
		tests--

		n := int64(0)
		if scanner.Scan() {
			n, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		}

		solve(n)
	}
}
