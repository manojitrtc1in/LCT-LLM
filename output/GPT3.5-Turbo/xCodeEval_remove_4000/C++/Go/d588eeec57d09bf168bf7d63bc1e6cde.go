package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MOD   = 1000000007
	maxn  = 100005
	x_max = maxn * 2
)

var (
	n        int
	pts      [maxn][2]int
	visit    [x_max]bool
	ve       [x_max]bool
	g        [x_max][]pair
	x_start  int
	y_start  int
	now      int
	trans    [2]map[int]int
)

type pair struct {
	first  int
	second int
}

func dfs(u int) pair {
	ret := pair{1, 0}
	visit[u] = true
	for _, vv := range g[u] {
		if ve[vv.second] {
			continue
		}
		ret.second++
		ve[vv.second] = true
		if visit[vv.first] {
			continue
		}
		p := dfs(vv.first)
		ret.first += p.first
		ret.second += p.second
	}
	return ret
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)

	trans[0] = make(map[int]int)
	trans[1] = make(map[int]int)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &pts[i][0], &pts[i][1])
		for j := 0; j < 2; j++ {
			if _, ok := trans[j][pts[i][j]]; !ok {
				s := len(trans[j])
				trans[j][pts[i][j]] = s
			}
			pts[i][j] = trans[j][pts[i][j]]
		}
	}

	x_start = now
	now += len(trans[0])
	y_start = now
	now += len(trans[1])

	for i := 0; i < n; i++ {
		x := x_start + pts[i][0]
		y := y_start + pts[i][1]
		g[x] = append(g[x], pair{y, i})
		g[y] = append(g[y], pair{x, i})
	}

	ans := 1
	for i := 0; i < now; i++ {
		if !visit[i] {
			p := dfs(i)
			k := p.first
			if p.second < p.first {
				ans = mulMod(ans, subMod(powMod(2, k), 1))
			} else {
				ans = mulMod(ans, powMod(2, k))
			}
		}
	}

	fmt.Fprintln(writer, ans)
}

func mulMod(a, b int) int {
	p := int64(a)
	p = (p * int64(b)) % MOD
	return int(p)
}

func powMod(a, p int) int {
	r := 1
	a %= MOD
	for p > 0 {
		if p&1 == 1 {
			r = mulMod(r, a)
		}
		a = mulMod(a, a)
		p >>= 1
	}
	return r
}

func subMod(a, b int) int {
	r := a - b
	if r < 0 {
		r += MOD
	}
	return r
}
