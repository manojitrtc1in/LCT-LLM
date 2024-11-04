package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var vec [1010101][]int
var vid [1010101]int
var pr [1010101]int
var primes []int
var used map[int64]int
var maxh int64
var w [][]int
var g [][]int
var dc [10001]int
var dist [301][10001]int
var vis [10001]bool

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
	if _, ok := used[x]; !ok {
		sz := len(used)
		used[x] = sz
		w = append(w, t)
		dc[sz] = calcd(t)
	}
	*v = append(*v, used[x])
}

func solve() int {
	w = append(w, []int{})
	used = make(map[int64]int)
	used[0] = 0
	const N = 1000010
	for i := 2; i < N; i++ {
		if pr[i] == 0 {
			pr[i] = i
			primes = append(primes, i)
		}
		for _, p := range primes {
			if p*i >= N || p > pr[i] {
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
		vec[i] = append(vec[x][:0:0], vec[x]...)
		vec[i] = append(vec[i], cnt)
		h := calc(vec[i])
		maxh = max(maxh, h)
		id, ok := used[h]
		if !ok {
			id = len(w)
			w = append(w, vec[i])
			used[h] = id
		}
		vid[i] = id
	}

	ws := len(w)
	for i := 0; i < min(len(w), 7000); i++ {
		cur := w[i]
		for j := 0; j < len(cur); j++ {
			t := cur
			t[j]--
			addUsed(&g[i], t)
			t[j] += 2
			addUsed(&g[i], t)
		}
		cur = append(cur, 1)
		addUsed(&g[i], cur)
		sort.Ints(g[i])
		g[i] = g[i][:reunique(g[i])]
		dc[i] = calcd(w[i])
	}

	for i := 0; i < ws; i++ {
		for j := 0; j < F; j++ {
			dist[i][j] = INF
		}
	}

	for i := 0; i < ws; i++ {
		for j := 0; j < F; j++ {
			vis[j] = false
		}
		q := []int{i}
		dp := make([]int, len(used))
		for i := range dp {
			dp[i] = INF
		}
		dp[i] = 0
		for len(q) > 0 {
			cur := q[0]
			q = q[1:]
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

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < n; i++ {
		scanner.Scan()
		a, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		b, _ := strconv.Atoi(scanner.Text())
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

func main() {
	solve()
}
