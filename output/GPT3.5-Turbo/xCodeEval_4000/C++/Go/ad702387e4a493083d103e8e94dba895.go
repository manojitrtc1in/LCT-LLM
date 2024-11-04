package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pair struct {
	first  int
	second int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	v := nextInt(scanner)
	m := nextInt(scanner)

	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(scanner)
	}
	for i := 0; i < n; i++ {
		b[i] = nextInt(scanner)
	}

	edges := make([][]int, n)
	for i := 0; i < m; i++ {
		x := nextInt(scanner) - 1
		y := nextInt(scanner) - 1
		edges[x] = append(edges[x], y)
		edges[y] = append(edges[y], x)
	}

	c := make([]int, n)
	visit := make([]int, n)
	cnt := 0
	s := make([]int, n)
	res := make([]pair, 0)

	var dfs func(int)
	dfs = func(x int) {
		visit[x] = 1
		c[x] = cnt
		for _, u := range edges[x] {
			if visit[u] == 0 {
				dfs(u)
			}
		}
	}

	for i := 0; i < n; i++ {
		if visit[i] == 0 {
			dfs(i)
			cnt++
		}
	}

	for i := 0; i < n; i++ {
		s[c[i]] += a[i]
		s[c[i]] -= b[i]
	}

	for i := 0; i < n; i++ {
		if a[i] == b[i] {
			continue
		}
		for j := i + 1; j < n; j++ {
			if c[i] != c[j] {
				continue
			}
			if a[j] == b[j] {
				continue
			}
			if a[i] < b[i] && a[j] < b[j] {
				continue
			}
			if a[i] > b[i] && a[j] > b[j] {
				continue
			}

			adjust(i, j, a, b, edges, res)
			break
		}
		if a[i] != b[i] {
			i--
		}
	}

	fmt.Println(len(res))
	for _, e := range res {
		fmt.Printf("%d %d %d\n", e.first+1, e.second+1, e.second)
	}
}

func adjust(x, y int, a, b []int, edges [][]int, res []pair) {
	if a[x] != b[x] {
		if a[y] != b[y] {
			if a[x] < b[x] {
				if a[y]+a[x] <= b[y] {
					liu(x, y, a, res)
					liu(y, x, a, res)
				} else {
					liu(x, y, b[y]-a[y], a, res)
					liu(y, x, b[y]-a[y], a, res)
					liu(x, y, a[x]-(b[y]-a[y]), a, res)
				}
			} else {
				if a[y]+b[x] <= b[y] {
					liu(x, y, a[y]-a[x], a, res)
					liu(y, x, a[y]-a[x], a, res)
					liu(x, y, b[x]-(a[y]-a[x]), a, res)
				} else {
					liu(x, y, b[y]-a[y], a, res)
					liu(y, x, b[y]-a[y], a, res)
				}
			}
		} else {
			if a[x] < b[x] {
				liu(x, y, a[x], a, res)
			} else {
				liu(x, y, b[x], a, res)
			}
		}
	} else {
		if a[y] != b[y] {
			if a[y] < b[y] {
				liu(y, x, b[y], a, res)
			} else {
				liu(y, x, a[y], a, res)
			}
		}
	}
}

func liu(x, y, flow int, a []int, res []pair) {
	a[x] -= flow
	a[y] += flow
	res = append(res, pair{first: x, second: y, second: flow})
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
