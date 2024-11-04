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
	F   = 1001
)

var (
	vec   [][]int
	vid   []int
	pr    []int
	primes []int
	used   map[int]int
	w      [][]int
	g      [][]int
	dc     []int
	dist   [][]int
	vis    []bool
	ans    [][]int
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
		vec[i] = make([]int, 0, len(vec[x])+1)
		vec[i] = append(vec[i], vec[x]...)
		vec[i] = append(vec[i], cnt)
		h := calc(vec[i])
		if _, ok := used[h]; !ok {
			used[h] = len(w)
			w = append(w, vec[i])
		}
		vid[i] = used[h]
	}
	ws := len(w)
	for i := 0; i < min(len(w), F); i++ {
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
		vis = make([]bool, F*2)
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
	n := readInt()
	for ; n > 0; n-- {
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	vec = make([][]int, 1010101)
	vid = make([]int, 1010101)
	pr = make([]int, 1010101)
	used = make(map[int]int)
	g = make([][]int, F*2)
	dc = make([]int, F*2)
	dist = make([][]int, 301)
	for i := range dist {
		dist[i] = make([]int, F*2)
	}
	ans = make([][]int, 303)
	for i := range ans {
		ans[i] = make([]int, 303)
	}

	solve()
}

func unique(a []int) []int {
	if len(a) == 0 {
		return a
	}
	res := []int{a[0]}
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] {
			res = append(res, a[i])
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt() int {
	str := readString()
	num, _ := strconv.Atoi(str)
	return num
}

func readString() string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func writeInt(num int) {
	str := strconv.Itoa(num)
	writer.WriteString(str)
	writer.WriteByte('\n')
}

func writeString(str string) {
	writer.WriteString(str)
	writer.WriteByte('\n')
}
