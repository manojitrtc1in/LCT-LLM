package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var vec [1010101][]int
var vid [1010101]int
var pr [1010101]int
var primes []int
var calcMemo map[string]int
var used map[int]int
var w [][]int
var g [][]int
var dc []int
var dist [301][2002]int
var vis [2002]bool
var ans [303][303]int

func calc(v []int) int {
	sort.Ints(v)
	res := 0
	for _, x := range v {
		res = res*24 + x
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
		id, ok := used[h]
		if !ok {
			id = len(w)
			used[h] = id
			w = append(w, vec[i])
		}
		vid[i] = id
	}

	ws := len(w)
	for i := 0; i < min(len(w), 1001); i++ {
		cur := w[i]
		for j := 0; j < len(cur); j++ {
			t := make([]int, len(cur))
			copy(t, cur)
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
		for j := 0; j < 2002; j++ {
			dist[i][j] = 1011111111
		}
	}
	for i := 0; i < ws; i++ {
		vis = make([]bool, 2002)
		q := []int{i}
		dp := make([]int, len(used))
		for j := 0; j < len(used); j++ {
			dp[j] = 1011111111
		}
		dp[i] = 0
		for j := 0; j < len(q); j++ {
			cur := q[j]
			dcur := dp[cur]
			for _, to := range g[cur] {
				if dp[to] == 1011111111 {
					dp[to] = dcur + 1
					q = append(q, to)
				}
			}
		}
		for j := 0; j < len(used); j++ {
			if dc[j] < 1001 {
				dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
			}
		}
	}

	for i := 0; i < ws; i++ {
		dist[i][0] = 1011111111
		for j := 0; j < i+1; j++ {
			res := 1011111111
			for k := 0; k < 1001; k++ {
				res = min(res, dist[i][k]+dist[j][k])
			}
			ans[i][j] = res
		}
	}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	n := nextInt(scanner)
	for i := 0; i < n; i++ {
		a := nextInt(scanner)
		b := nextInt(scanner)
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		fmt.Println(ans[a][b])
	}

	return 0
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func unique(arr []int) []int {
	m := make(map[int]bool)
	for _, v := range arr {
		m[v] = true
	}
	var res []int
	for k := range m {
		res = append(res, k)
	}
	return res
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
