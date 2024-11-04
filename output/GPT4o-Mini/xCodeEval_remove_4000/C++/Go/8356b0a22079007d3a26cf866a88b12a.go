package main

import (
	"fmt"
	"math"
	"sort"
)

const Maxn = 1005
const INF = math.MaxInt64

type LL int64

func read() int {
	var x int
	fmt.Scan(&x)
	return x
}

type edge struct {
	to, rev, cap int
}

var (
	src = 1002
	snk = 1003
	G   [Maxn][]edge
)

var (
	dist [Maxn]int
	seen [Maxn]int
	n    int
)

func Clear() {
	for i := 0; i < Maxn; i++ {
		G[i] = nil
	}
}

func bfs(s int) {
	for i := 0; i < Maxn; i++ {
		dist[i] = -1
	}
	dist[s] = 0
	Q := []int{s}
	for len(Q) > 0 {
		x := Q[0]
		Q = Q[1:]
		for i := 0; i < len(G[x]); i++ {
			e := G[x][i]
			if e.cap > 0 && dist[e.to] == -1 {
				dist[e.to] = dist[x] + 1
				Q = append(Q, e.to)
			}
		}
	}
}

func dfs(now, dest, fl int) int {
	if now == dest {
		return fl
	}
	for i := seen[now]; i < len(G[now]); i++ {
		seen[now] = i
		ed := G[now][i]
		if ed.cap > 0 && dist[ed.to] == dist[now]+1 {
			f := dfs(ed.to, dest, min(fl, ed.cap))
			if f > 0 {
				ed.cap -= f
				G[ed.to][ed.rev].cap += f
				return f
			}
		}
	}
	return 0
}

func dinic(s, t int) int {
	ret := 0
	for {
		for i := 0; i < Maxn; i++ {
			seen[i] = 0
		}
		bfs(s)
		if dist[t] == -1 {
			return ret
		}
		f := dfs(s, t, INF)
		for f > 0 {
			ret += f
			f = dfs(s, t, INF)
		}
	}
}

type iP struct {
	x, y LL
}

func (p iP) add(q iP) iP {
	return iP{p.x + q.x, p.y + q.y}
}

func (p iP) sub(q iP) iP {
	return iP{p.x - q.x, p.y - q.y}
}

func (p iP) mul(k LL) iP {
	return iP{p.x * k, p.y * k}
}

func (p iP) det(q iP) LL {
	return p.x*q.y - p.y*q.x
}

func (p iP) dot(q iP) LL {
	return p.x*q.x + p.y*q.y
}

func (p iP) dist() LL {
	return p.x*p.x + p.y*p.y
}

type mat struct {
	dist [77][77]LL
}

func newMat() mat {
	var m mat
	for i := 0; i < 77; i++ {
		for j := 0; j < 77; j++ {
			m.dist[i][j] = 1e18
		}
	}
	return m
}

var id [256]int
var T1 mat
var cc int
var c [Maxn]LL

func _init(k, x int) {
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

var p, wp [30]int
var dp, dp2 [77]LL

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

func main() {
	x = read()
	k = read()
	n = read()
	q = read()
	n += k - x
	for i := 1; i <= k; i++ {
		c[i] = LL(read())
	}
	_init(k, x)

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
