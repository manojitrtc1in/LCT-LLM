package main

import (
	"container/heap"
	"fmt"
	"math"
)

const (
	INF = math.MaxInt64
	MOD = 1000000007
)

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, len((*G)[to]) + boolToInt(from == to), cap})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, len((*G)[from]) - 1, revCap})
	}
}

func maxFlowDFS(G *Graph, v, t int64, f int64, used []bool) int64 {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := (*G)[v][i]
		if !used[e.to] && e.cap > 0 {
			d := maxFlowDFS(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int64) int64 {
	flow := int64(0)
	for {
		used := make([]bool, len(*G))
		f := maxFlowDFS(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func main() {
	var m, h1, a1, x1, y1 int64
	fmt.Scan(&m)
	fmt.Scan(&h1, &a1, &x1, &y1)

	t := []int64{h1}
	used := make([]int64, m)
	used[h1] = 1
	for {
		tmp := (t[len(t)-1]*x1 + y1) % m
		t = append(t, tmp)
		if used[tmp] != 0 {
			break
		}
		used[tmp] = 1
	}

	used = make([]int64, m)
	var h2, a2, x2, y2 int64
	fmt.Scan(&h2, &a2, &x2, &y2)
	used[h2] = 1
	s := []int64{h2}
	for {
		tmp := (s[len(s)-1]*x2 + y2) % m
		s = append(s, tmp)
		if used[tmp] != 0 {
			break
		}
		used[tmp] = 1
	}

	l1, l2 := int64(-1), int64(-1)
	mn1, mn2 := INF, INF
	now := int64(0)

	for {
		if t[len(t)-1] == t[now] {
			l1 = int64(len(t) - now - 1)
		}
		if t[now] == a1 {
			mn1 = now
			break
		}
		now++
		if now == int64(len(t)) {
			break
		}
	}

	now = 0
	for {
		if s[len(s)-1] == s[now] {
			l2 = int64(len(s) - now - 1)
		}
		if s[now] == a2 {
			mn2 = now
			break
		}
		now++
		if now == int64(len(s)) {
			break
		}
	}

	calc := func() int64 {
		if mn1 != INF && mn2 != INF {
			if mn1 == mn2 {
				return mn1
			}
			if mn1 > mn2 && l2 == -1 {
				return -1
			}
			if mn1 < mn2 && l1 == -1 {
				return -1
			}
			if l1 == -1 {
				if (mn1-mn2)%l2 == 0 {
					return mn1
				}
				return -1
			}
			if l2 == -1 {
				if (mn2-mn1)%l1 == 0 {
					return mn2
				}
				return -1
			}
			if l1 == l2 {
				if abs(mn1-mn2)%l1 == 0 {
					return max(mn1, mn2)
				}
				return -1
			}
			if mn2 > mn1 && (mn2-mn1)%l1 == 0 {
				return mn2
			}
			if mn1 > mn2 && (mn1-mn2)%l2 == 0 {
				return mn1
			}
			if abs(mn2-mn1)%abs(gcd(l1, l2)) != 0 {
				return -1
			}
			x, y := int64(0), int64(0)
			g := extgcd(l1, l2, &x, &y)
			x *= (mn2 - mn1) / g
			y *= (mn2 - mn1) / g
			if x*l1+mn1 < max(mn1, mn2) {
				x += ((max(mn1, mn2) - x*l1 + mn1 + l1 - 1) / l1 + l2/g - 1) / (l2 / g) * (l2 / g))
			}
			if x*l1+mn1 >= max(mn1, mn2) {
				x -= (x*l1 + mn1 - max(mn1, mn2)) / l1 / (l2 / g) * (l2 / g)
			}
			return x*l1 + mn1
		}
		return -1
	}

	fmt.Println(calc())
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func extgcd(a, b int64, x, y *int64) int64 {
	if a < b {
		return extgcd(b, a, y, x)
	}
	if b > 0 {
		g := extgcd(b, a%b, y, x)
		*y -= (a / b) * (*x)
		return g
	}
	*x = 1
	*y = 0
	return a
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
