package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type pair struct {
	first  int
	second int
}

type triple struct {
	first  int
	second int
	third  int
}

var (
	graf   [][]int
	siz    []int
	dep    []int
	ans    []triple
	ava    []int
	graf2  [][]pair
	seen   map[int]bool
	scanner *bufio.Scanner
	writer  *bufio.Writer
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
		panic("Invalid input")
	}
	ans = append(ans, triple{first: x, second: y, third: t - d})
	for _, v := range graf[x] {
		if v != y {
			dfs2(v, x, t)
		}
	}
}

func dfs3(x, y, d int) {
	seen[d] = true
	for _, e := range graf2[x] {
		if e.first != y {
			dfs3(e.first, x, d+e.second)
		}
	}
}

func testAns() {
	for _, x := range ans {
		graf2[x.first].push_back(pair{x.second, x.third})
		graf2[x.second].push_back(pair{x.first, x.third})
	}
	for i := 1; i <= n; i++ {
		dfs3(i)
	}
}

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscanf(scanner, "%d\n", &n)
	if n == 1 {
		return
	}

	graf = make([][]int, n+1)
	siz = make([]int, n+1)
	dep = make([]int, n+1)
	graf2 = make([][]pair, n+1)
	seen = make(map[int]bool)

	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscanf(scanner, "%d %d\n", &a, &b)
		graf[a] = append(graf[a], b)
		graf[b] = append(graf[b], a)
	}

	dfs1(1, -1, 0)
	M := n * 2 / 3

	for i := 1; i <= n; i++ {
		sizes := []pair{{1, i}}
		p := -1
		for _, v := range graf[i] {
			if dep[v] == dep[i]+1 {
				sizes = append(sizes, pair{siz[v], v})
			} else {
				p = v
			}
		}
		if i != 1 {
			sizes = append(sizes, pair{n - siz[i], p})
		}

		good := true
		for _, x := range sizes {
			if x.first > M {
				good = false
			}
		}

		if good {
			v1 := []pair{}
			v2 := []pair{}
			sort.Slice(sizes, func(i, j int) bool {
				return sizes[i].first > sizes[j].first
			})
			sum1 := 0
			sum2 := 0
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
				panic("Invalid input")
			}

			for j := 0; j < sum2; j++ {
				ava = append(ava, 1+j*sum1)
			}

			for _, x := range v2 {
				dfs2(x.second, i, 0)
			}

			if len(ava) != 0 {
				panic("Invalid input")
			}

			for _, x := range ans {
				fmt.Fprintf(writer, "%d %d %d\n", x.first, x.second, x.third)
			}

			testAns()
			return
		}
	}

	panic("Invalid input")
}
