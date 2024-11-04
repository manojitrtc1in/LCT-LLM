package main

import (
	"bufio"
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
)

type pt struct {
	x int
	y int
}

type pair struct {
	a int
	b int
}

func main() {
	rand.Seed(time.Now().UnixNano())

	const INF = int(1e9)
	const INF64 = int64(1e18)
	const MOD = INF + 7
	const EPS = 1e-9
	const PI = math.Acos(-1.0)

	const N = 100*1000 + 13

	var n, m, k int
	var h int64
	var a [N]pair

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	read := func() bool {
		scanner.Scan()
		h, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		scanner.Scan()
		n, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		m, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ = strconv.Atoi(scanner.Text())

		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i].a, _ = strconv.Atoi(scanner.Text())
			scanner.Scan()
			a[i].b, _ = strconv.Atoi(scanner.Text())
		}

		return true
	}

	used := make([]bool, N)
	mn := make([]int64, N)
	cur := make([]pt, 0)

	add := func(x int64) {
		q := make([]int, 0)
		for i := 0; i < k; i++ {
			q = append(q, i)
		}
		for len(q) > 0 {
			v := q[0]
			q = q[1:]
			if mn[v]+x < mn[(v+x)%k] {
				mn[(v+x)%k] = mn[v] + x
				q = append(q, (v+x)%k)
			}
		}
	}

	recalc := func() {
		cur = make([]pt, 0)
		for i := 0; i < n; i++ {
			if !used[i] && mn[a[i].a%k] <= int64(a[i].a) {
				cur = append(cur, pt{a[i].b, -i})
			}
		}
	}

	solve := func() {
		for i := 0; i < k; i++ {
			mn[i] = h + 1
		}
		mn[1] = 1
		for i := 0; i < len(used); i++ {
			used[i] = false
		}
		recalc()
		for i := 0; i < m; i++ {
			scanner.Scan()
			t, _ := strconv.Atoi(scanner.Text())
			if t == 1 {
				scanner.Scan()
				x, _ := strconv.ParseInt(scanner.Text(), 10, 64)
				add(x)
				recalc()
			} else if t == 2 {
				scanner.Scan()
				x, _ := strconv.Atoi(scanner.Text())
				scanner.Scan()
				y, _ := strconv.Atoi(scanner.Text())
				x--
				if mn[a[x].a%k] <= int64(a[x].a) {
					for j := 0; j < len(cur); j++ {
						if cur[j].y == -x {
							cur = append(cur[:j], cur[j+1:]...)
							break
						}
					}
				}
				a[x].b -= y
				if mn[a[x].a%k] <= int64(a[x].a) {
					cur = append(cur, pt{a[x].b, -x})
				}
			} else if len(cur) > 0 {
				fmt.Println(cur[0].x)
				used[-cur[0].y] = true
				cur = cur[1:]
			} else {
				fmt.Println(0)
			}
		}
	}

	for read() {
		solve()
	}
}
