package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	USUAL_MOD = 1000000007
	F         = 10001
	INF      = 1011111111
)

var (
	vec     [1010101][]int
	vid     [1010101]int
	pr      [1010101]int
	primes  []int
	used    = make(map[int64]int)
	maxh    int64
	dist    [301][F]int
	vis     [F]bool
	dc      [F]int
	g       [F][]int
	w       [][]int
)

func calc(v []int) int64 {
	sort.Ints(v)
	res := int64(0)
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
	for i := 0; i < int(math.Min(float64(ws), 7000)); i++ {
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
		copy(vis[:], make([]bool, F))
		q := []int{i}
		dp := make([]int, len(used))
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
		for j := 0; j < len(used); j++ {
			if dc[j] < F {
				dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
			}
		}
	}

	var n int
	fmt.Scan(&n)
	for n > 0 {
		n--
		var a, b int
		fmt.Scan(&a, &b)
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		ans := INF
		for i := 1; i < 3000; i++ {
			ans = min(ans, dist[a][i]+dist[b][i])
		}
		fmt.Println(ans)
	}
	return 0
}

func reunique(v *[]int) {
	unique := make([]int, 0, len(*v))
	seen := make(map[int]bool)
	for _, val := range *v {
		if !seen[val] {
			seen[val] = true
			unique = append(unique, val)
		}
	}
	*v = unique
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	solve()
}
