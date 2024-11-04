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
var used = make(map[int64]int)
var maxh int64
var w [][]int
var g [6002][]int
var dc [6002]int
var ans [303][303]int

const F = 3001
const INF = int(1e9)

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

func addUsed(v []int, t []int) {
	x := calc(t)
	if _, ok := used[x]; !ok {
		sz := len(used)
		used[x] = sz
		w = append(w, t)
		dc[sz] = calcd(t)
	}
	v = append(v, used[x])
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
		vec[i] = append(vec[i], vec[x]...)
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
	for i := 0; i < min(len(w), F); i++ {
		cur := w[i]
		for j := 0; j < len(cur); j++ {
			t := cur
			t[j]--
			addUsed(g[i], t)
			t[j] += 2
			addUsed(g[i], t)
		}
		cur = append(cur, 1)
		addUsed(g[i], cur)
		sort.Ints(g[i])
		g[i] = unique(g[i])
		dc[i] = calcd(w[i])
	}
	for i := 0; i < ws; i++ {
		vis := make([]bool, F*2)
		q := []int{i}
		dp := make([]int, F*2)
		for j := 0; j < len(used); j++ {
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
	for i := 0; i < ws; i++ {
		dist[i][0] = INF
		for j := 0; j < i+1; j++ {
			res := INF
			for k := 0; k < F; k++ {
				res = min(res, dist[i][k]+dist[j][k])
			}
			ans[i][j] = res
		}
	}
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		fmt.Println(ans[a][b])
	}
	return 0
}

func main() {
	solve()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func unique(arr []int) []int {
	res := []int{}
	seen := make(map[int]bool)
	for _, val := range arr {
		if _, ok := seen[val]; !ok {
			res = append(res, val)
			seen[val] = true
		}
	}
	return res
}
