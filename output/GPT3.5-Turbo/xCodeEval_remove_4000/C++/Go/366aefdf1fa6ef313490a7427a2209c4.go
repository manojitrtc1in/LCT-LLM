package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	INF = int(1e9)
	F   = 30001
)

var (
	vec   [][]int
	vid   []int
	pr    []int
	primes []int
	used   map[int64]int
	maxh   int64
	w      [][]int
	g      [][]int
	dc     []int
	dist   [][]int
	vis    []bool
	ans    [][]int
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
		vec[i] = make([]int, 0, len(vec[x])+1)
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
	for i := 0; i < min(len(w), 20000); i++ {
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

	dist = make([][]int, ws)
	for i := 0; i < ws; i++ {
		dist[i] = make([]int, F)
		for j := 0; j < F; j++ {
			dist[i][j] = INF
		}
	}

	for i := 0; i < ws; i++ {
		vis = make([]bool, F)
		q := []int{i}
		dp := make([]int, len(used))
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

	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		fmt.Println(ans[a][b])
	}
	return 0
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

func reunique(arr *[]int) {
	j := 0
	for i := 1; i < len(*arr); i++ {
		if (*arr)[i] != (*arr)[j] {
			j++
			(*arr)[j] = (*arr)[i]
		}
	}
	*arr = (*arr)[:j+1]
}

func main() {
	w = make([][]int, 0)
	used = make(map[int64]int)
	vec = make([][]int, 1010101)
	vid = make([]int, 1010101)
	pr = make([]int, 1010101)
	ans = make([][]int, 300)
	for i := 0; i < 300; i++ {
		ans[i] = make([]int, 300)
	}
	g = make([][]int, F)
	dc = make([]int, F)
	dist = make([][]int, 301)
	for i := 0; i < 301; i++ {
		dist[i] = make([]int, F)
	}
	solve()
}

func FREIN(name string) {
	file, err := os.Open(name)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanWords)
	buf := make([]byte, 0, 64*1024)
	scanner.Buffer(buf, 1024*1024)
	scanner.Scan()
}

func CURTIME() {
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
