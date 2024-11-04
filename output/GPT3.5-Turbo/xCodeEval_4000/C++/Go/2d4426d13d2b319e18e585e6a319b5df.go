package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const (
	jt   = 998244353
	maxM = 20
	maxN = 55
)

var (
	n   int
	m   int
	s   [maxN]string
	val [maxN]int
	dy  [1 << maxM]uint64
	dp  [1 << maxM]float64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &s[i])
	}

	m = len(s[0])

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			num := 0
			for k := 0; k < m; k++ {
				if s[i][k] == s[j][k] {
					num |= (1 << k)
				}
			}
			dy[num] |= (1 << i) | (1 << j)
		}
	}

	for i := (1 << m) - 1; i >= 0; i-- {
		for j := i; j > 0; j -= j & -j {
			lst := j & -j
			dy[i^lst] |= dy[i]
		}
	}

	dp[0] = 1
	ans := 0.0

	for i := 0; i < (1 << m); i++ {
		v := dp[i] / float64(m-strings.Count(fmt.Sprintf("%b", i), "1"))
		for j := (1 << m) - 1 ^ i; j > 0; j -= j & -j {
			dp[i|(j&-j)] += v
		}
		ans += dp[i] * float64(strings.Count(fmt.Sprintf("%b", dy[i]), "1"))
	}

	fmt.Println(ans / float64(n))
}
