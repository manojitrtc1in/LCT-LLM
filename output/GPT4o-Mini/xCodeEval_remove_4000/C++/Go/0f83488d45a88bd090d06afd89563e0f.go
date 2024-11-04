package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	id11 = 1000000007
	F    = 1001
	INF  = math.MaxInt32
)

var (
	vec    [1010101][]int
	vid    [1010101]int
	pr     [1010101]int
	primes []int
	used   = make(map[int]int)
	w      [][]int
	dist   [301][F * 2]int
	vis    [F * 2]bool
	dc     [F * 2]int
	g      [F * 2][]int
	ans    [303][303]int
)

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
		vec[i] = append(vec[i][:0], vec[x]...)
		vec[i] = append(vec[i], cnt)
		h := calc(vec[i])
		id := &used[h]
		if *id == 0 {
			*id = len(w)
			w = append(w, vec[i])
		}
		vid[i] = *id
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
				dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
			}
		}
	}
	n := readInt()
	for n > 0 {
		n--
		a := readInt()
		b := readInt()
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		writeInt(ans[a][b])
	}
	return 0
}

func main() {
	solve()
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func writeInt(x int) {
	fmt.Println(x)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func reunique(v *[]int) {
	// Implement reunique logic here
}
