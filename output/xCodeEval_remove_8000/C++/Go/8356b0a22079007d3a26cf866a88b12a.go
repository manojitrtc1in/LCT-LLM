package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const (
	Maxn = 9
	INF  = 1e18
)

type mat struct {
	dist [77][77]int64
}

type iP struct {
	x, y int64
}

type dP struct {
	x, y float64
}

var (
	x, k, n, q int
	tl         int
	T1         mat
	cc         int
	c          [Maxn]int64
	id         [256]int
	dp, dp2    [77]int64
	p, wp      [30]int
)

func init() {
	for i := 0; i < (1 << k); i++ {
		cnt := 0
		for j := 0; j < k; j++ {
			if i>>j&1 == 1 {
				cnt++
			}
		}
		if cnt != x {
			continue
		}

		cc++
		id[i] = cc
	}

	for i := 0; i < (1 << k); i++ {
		cnt := 0
		for j := 0; j < k; j++ {
			if i>>j&1 == 1 {
				cnt++
			}
		}
		if cnt != x {
			continue
		}

		v := i >> 1
		u := i & 1
		if u == 0 {
			T1.dist[id[i]][id[v]] = 0
		} else {
			for j := 0; j < k; j++ {
				if v&(1<<j) != 0 {
					continue
				}
				T1.dist[id[i]][id[v^(1<<j)]] = c[j+1]
			}
		}
	}
}

func main() {
	x = readInt()
	k = readInt()
	n = readInt()
	q = readInt()
	n += k - x

	for i := 1; i <= k; i++ {
		c[i] = readInt64()
	}

	for i := 1; i <= q; i++ {
		p[i] = readInt()
		wp[i] = readInt()
	}

	dp[id[(1<<x)-1]] = 0
	now := k
	for now < n {
		if !normal(now + 1) {
			Tra := Build(now + 1)
			Mul(Tra)
			now++
			continue
		}

		Nxt := n + 1
		for i := 1; i <= q; i++ {
			if p[i] > now {
				Nxt = min(Nxt, p[i])
			}
		}

		di := Nxt - now - 1
		Tra := mqp(T1, int64(di))
		Mul(Tra)
		now = Nxt - 1
	}

	fmt.Println(dp[id[(1<<x)-1]])
}

func Build(pos int) mat {
	ret := T1
	for i := 0; i < (1 << k); i++ {
		if id[i] == 0 {
			continue
		}
		for j := 1; j <= q; j++ {
			if p[j] <= pos && pos-p[j] < k {
				pp := pos - p[j]
				pp = k - 1 - pp
				if i>>(pp+1)&1 == 1 {
					continue
				}

				for l := 0; l < (1 << k); l++ {
					if id[l] == 0 {
						continue
					}
					if l>>pp&1 == 1 {
						if ret.dist[id[i]][id[l]] != INF {
							ret.dist[id[i]][id[l]] += int64(wp[j])
						}
					}
				}
			}
		}
	}
	return ret
}

func Mul(X mat) {
	for i := 1; i <= cc; i++ {
		dp2[i] = INF
	}

	for i := 1; i <= cc; i++ {
		for j := 1; j <= cc; j++ {
			dp2[j] = min(dp2[j], dp[i]+X.dist[i][j])
		}
	}

	for i := 1; i <= cc; i++ {
		dp[i] = dp2[i]
	}
}

func mqp(x mat, p int64) mat {
	R := mat{}
	for i := 1; i <= cc; i++ {
		R.dist[i][i] = 0
	}

	for p > 0 {
		if p&1 == 1 {
			R = mul(R, x)
		}
		x = mul(x, x)
		p >>= 1
	}

	return R
}

func normal(pos int) bool {
	for i := 1; i <= q; i++ {
		if p[i] <= pos && pos-p[i] < k {
			return false
		}
	}
	return true
}

func mul(x, y mat) mat {
	ret := mat{}
	for i := 1; i <= cc; i++ {
		for j := 1; j <= cc; j++ {
			for k := 1; k <= cc; k++ {
				ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k]+y.dist[k][j])
			}
		}
	}
	return ret
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readInt64() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func main() {
	main()
}