package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	Maxn = 9
	big  = 20160116
	INF  = 2147483647
)

type LL int64

type edge struct {
	to, rev, cap int
}

type mat struct {
	dist [77][77]LL
}

var (
	x, k, n, q int
	tl          int
	id          [256]int
	T1          mat
	cc          int
	c           [Maxn]LL
	dp          [77]LL
	dp2         [77]LL
	p, wp       [30]int
)

func init() {
	for i := 0; i < 77; i++ {
		for j := 0; j < 77; j++ {
			T1.dist[i][j] = 1e18
		}
	}
}

func read() int {
	var x int
	fmt.Scan(&x)
	return x
}

func _init() {
	for i := 0; i < (1 << k); i++ {
		cnt := 0
		for j := 0; j < k; j++ {
			if i>>j&1 != 0 {
				cnt++
			}
		}
		if cnt != x {
			continue
		}
		id[i] = cc + 1
		cc++
	}
	for i := 0; i < (1 << k); i++ {
		cnt := 0
		for j := 0; j < k; j++ {
			if i>>j&1 != 0 {
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
				if i>>(pp+1)&1 != 0 {
					continue
				}
				for l := 0; l < (1 << k); l++ {
					if id[l] == 0 {
						continue
					}
					if l>>pp&1 != 0 {
						if ret.dist[id[i]][id[l]] != 1e18 {
							ret.dist[id[i]][id[l]] += LL(wp[j])
						}
					}
				}
			}
		}
	}
	return ret
}

func mul(x, y mat) mat {
	var ret mat
	for i := 1; i <= cc; i++ {
		for j := 1; j <= cc; j++ {
			for k := 1; k <= cc; k++ {
				ret.dist[i][j] = min(ret.dist[i][j], x.dist[i][k]+y.dist[k][j])
			}
		}
	}
	return ret
}

func Mul(X mat) {
	for i := 1; i <= cc; i++ {
		dp2[i] = 1e18
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

func mqp(x mat, p LL) mat {
	var R mat
	for i := 1; i <= cc; i++ {
		R.dist[i][i] = 0
	}
	for p > 0 {
		if p&1 != 0 {
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

func min(a, b LL) LL {
	if a < b {
		return a
	}
	return b
}

func main() {
	x = read()
	k = read()
	n = read()
	q = read()
	n += k - x
	for i := 1; i <= k; i++ {
		c[i] = LL(read())
	}
	_init()

	for i := 1; i <= q; i++ {
		p[i] = read()
		wp[i] = read()
	}
	for i := 1; i <= cc; i++ {
		dp[i] = 1e18
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
		Tra := mqp(T1, LL(di))
		Mul(Tra)
		now = Nxt - 1
	}
	fmt.Println(dp[id[(1<<x)-1]])
}
