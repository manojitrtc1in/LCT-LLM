package main

import (
	"fmt"
	"sort"
	"strconv"
)

const inf = 1234000000
const llinf = 1234567890000000000

type Pair struct {
	first, second int
}

var (
	n       int
	graf    [1000 + 44][]int
	siz     [1000 + 44]int
	dep     [1000 + 44]int
	ans     []Pair
	ava     []int
	graf2   [1000 + 44][]Pair
	seen    map[int]struct{}
)

func dfs1(x, y, d int) {
	siz[x] = 1
	dep[x] = d
	for _, v := range graf[x] {
		if v != y {
			dfs1(v, x, d+1)
			siz[x] += siz[v]
		}
	}
}

func dfs2(x, y, d int) {
	t := ava[0]
	ava = ava[1:]
	if t <= d {
		panic("assertion failed")
	}
	ans = append(ans, Pair{first: x, second: y})
	for _, v := range graf[x] {
		if v != y {
			dfs2(v, x, t-d)
		}
	}
}

func dfs3(x, y, d int) {
	seen[d] = struct{}{}
	for _, e := range graf2[x] {
		if e.first != y {
			dfs3(e.first, x, d+e.second)
		}
	}
}

func testAns() {
	for _, x := range ans {
		graf2[x.first]. = append(graf2[x.first], Pair{first: x.second, second: x.second})
		graf2[x.second]. = append(graf2[x.second], Pair{first: x.first, second: x.second})
	}
	for i := 1; i <= n; i++ {
		dfs3(i, -1, 0)
	}
	for i := 1; i <= n*n*2/9; i++ {
		if _, ok := seen[i]; !ok {
			panic("assertion failed")
		}
	}
}

func main() {
	fmt.Scan(&n)
	if n == 1 {
		return
	}
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graf[a] = append(graf[a], b)
		graf[b] = append(graf[b], a)
	}
	dfs1(1)
	M := n * 2 / 3
	for i := 1; i <= n; i++ {
		sizes := []Pair{{1, i}}
		p := -1
		for _, v := range graf[i] {
			if dep[v] == dep[i]+1 {
				sizes = append(sizes, Pair{first: siz[v], second: v})
			} else {
				p = v
			}
		}
		if i != 1 {
			sizes = append(sizes, Pair{first: n - siz[i], second: p})
		}
		good := true
		for _, x := range sizes {
			if x.first > M {
				good = false
			}
		}
		if good {
			v1, v2 := []Pair{}, []Pair{}
			sort.Slice(sizes, func(a, b int) bool {
				return sizes[a].first > sizes[b].first
			})
			sum1, sum2 := 0, 0
			whme := 0
			for _, c := range sizes {
				if sum1+c.first > M {
					v2 = append(v2, c)
					sum2 += c.first
					if c.second == i {
						whme = 2
					}
				} else {
					v1 = append(v1, c)
					sum1 += c.first
					if c.second == i {
						whme = 1
					}
				}
			}
			if sum1*sum2 < n*n*2/9 {
				panic("assertion failed")
			}
			if whme == 2 {
				v1, v2 = v2, v1
				sum1, sum2 = sum2, sum1
			}
			for j := 1; j < sum1; j++ {
				ava = append(ava, j)
			}
			for _, x := range v1 {
				if x.second != i {
					dfs2(x.second, i, 0)
				}
			}
			if len(ava) != 0 {
				panic("assertion failed")
			}
			for j := 0; j < sum2; j++ {
				ava = append(ava, 1+j*sum1)
			}
			for _, x := range v2 {
				dfs2(x.second, i, 0)
			}
			if len(ava) != 0 {
				panic("assertion failed")
			}
			for _, x := range ans {
				fmt.Printf("%d %d %d\n", x.first, x.second)
			}
			testAns()
			return
		}
	}
	panic("assertion failed")
}
