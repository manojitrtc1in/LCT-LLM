package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const (
	id11 = 1000000007
	F    = 3001
	INF  = 1 << 30
)

var (
	vec    [1010101][]int
	vid    [1010101]int
	pr     [1010101]int
	primes []int
	used   = make(map[int64]int)
	maxh   int64
	dist   [301][F * 2]int
	vis    [F * 2]bool
	dc     [F * 2]int
	g      [F * 2][]int
	w      [][]int
	ans    [303][303]int
)

func calc(v []int) int64 {
	sort.Ints(v)
	var res int64 = 0
	for _, x := range v {
		res = res*30 + int64(x)
	}
	return res
}

func calcd(v []int) int {
	res := 1
	for _, x := range v {
		res *= x + 1
	}
	return res
}

func addUsed(v *[]int, t []int) {
	x := calc(t)
	if _, exists := used[x]; !exists {
		sz := len(used)
		used[x] = sz
		w = append(w, t)
		dc[sz] = calcd(t)
	}
	*v = append(*v, used[x])
}

func solve() int {
	w = append(w, []int{})
	used[0] = 0
	const N = 1000010
	for i := 2; i < N; i++ {
		if pr[i] == 0 {
			pr[i] = i
			primes = append(primes, i)
		}
		for _, p := range primes {
			if p*i > N || p > pr[i] {
				break
			}
			pr[p*i] = p
		}
		cnt := 1
		x := i
		for pr[x] == pr[x/pr[x]] {
			cnt++
			x /= pr[x]
		}
		x /= pr[x]
		vec[i] = append(vec[x], cnt)
		h := calc(vec[i])

		if h > maxh {
			maxh = h
		}
		id := used[h]
		if id == 0 {
			id = len(w)
			w = append(w, vec[i])
		}
		vid[i] = id
	}
	ws := len(w)
	for i := 0; i < min(ws, F); i++ {
		cur := w[i]
		for j := 0; j < len(cur); j++ {
			t := make([]int, len(cur))
			copy(t, cur)
			t[j]--
			addUsed(&g[i], t)
			t[j] += 2
			addUsed(&g[i], t)
		}
		cur = append(cur, 1)
		addUsed(&g[i], cur)
		sort.Ints(g[i])
		reunique(&g[i])
		dc[i] = calcd(w[i])
	}
	for i := 0; i < ws; i++ {
		dist[i][0] = INF
		for j := 0; j < ws; j++ {
			if dc[j] < F {
				dist[i][dc[j]] = min(dist[i][dc[j]], INF)
			}
		}
	}
	for i := 0; i < ws; i++ {
		vis = [F * 2]bool{}
		q := []int{i}
		dp := make([]int, F*2)
		for j := range dp {
			dp[j] = INF
		}
		dp[i] = 0
		for j := 0; j < len(q); j++ {
			cur := q[j]
			dcur := dp[cur]
			for _, to := range g[cur] {
				if dp[to] == INF {
					dp[to] = dcur + 1
					q = append(q, to)
				}
			}
		}
		for j := 0; j < ws; j++ {
			if dc[j] < F {
				dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
			}
		}
	}
	for i := 0; i < ws; i++ {
		for j := 0; j <= i; j++ {
			res := INF
			for k := 0; k < F; k++ {
				res = min(res, dist[i][k]+dist[j][k])
			}
			ans[i][j] = res
		}
	}
	return 0
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func reunique(v *[]int) {
	unique := make(map[int]struct{})
	var result []int
	for _, val := range *v {
		if _, exists := unique[val]; !exists {
			unique[val] = struct{}{}
			result = append(result, val)
		}
	}
	*v = result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	defer reader.Flush()
	solve()
	n := readInt()
	for i := 0; i < n; i++ {
		a := readInt()
		b := readInt()
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		fmt.Println(ans[a][b])
	}
}
