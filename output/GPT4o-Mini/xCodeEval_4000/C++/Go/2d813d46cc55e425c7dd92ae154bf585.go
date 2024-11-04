package main

import (
	"bufio"
	"fmt"
	"os"
)

type pos struct {
	i, j int
}

var (
	n, k, c, ans, best int
	a                  [505][505]int
	out                [125005]int
	chk                [125005]int
	di                = [4]int{1, 0, -1, 0}
	dj                = [4]int{0, 1, 0, -1}
)

func scan() (int, int) {
	var x, y int
	fmt.Scan(&x, &y)
	return x, y
}

func solve() {
	n, k = scan()
	var x byte
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			fmt.Scanf(" %c", &x)
			if x == '.' {
				a[i][j] = -1
			} else {
				a[i][j] = 0
			}
		}
	}

	var q []pos
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if a[i][j] == -1 {
				c++
				a[i][j] = c
				q = append(q, pos{i, j})
				for len(q) > 0 {
					t := q[0]
					q = q[1:]
					for k := 0; k < 4; k++ {
						if a[t.i+di[k]][t.j+dj[k]] == -1 {
							a[t.i+di[k]][t.j+dj[k]] = c
							q = append(q, pos{t.i + di[k], t.j + dj[k]})
						}
					}
				}
			}
		}
	}

	for i := 0; i <= n+1; i++ {
		for j := 0; j <= n+1; j++ {
			out[a[i][j]]++
		}
	}

	for addi := 0; addi <= n-k; addi++ {
		for i := addi + 1; i <= addi+k; i++ {
			for j := 0; j < k; j++ {
				out[a[i][j]]--
			}
		}
		for addj := 0; addj <= n-k; addj++ {
			ans = k * k
			for i := addi + 1; i <= addi+k; i++ {
				out[a[i][addj]]++
				out[a[i][addj+k]]--
			}
			for i := addi + 1; i <= addi+k; i++ {
				p := a[i][addj]
				if p > 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
				p = a[i][addj+k+1]
				if p > 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
			}
			for j := addj + 1; j <= addj+k; j++ {
				p := a[addi][j]
				if p > 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
				p = a[addi+k+1][j]
				if p > 0 && chk[p] == 0 {
					chk[p] = 1
					ans += out[p]
				}
			}
			for i := addi + 1; i <= addi+k; i++ {
				chk[a[i][addj]] = 0
				chk[a[i][addj+k+1]] = 0
			}
			for j := addj + 1; j <= addj+k; j++ {
				chk[a[addi][j]] = 0
				chk[a[addi+k+1][j]] = 0
			}
			if ans > best {
				best = ans
			}
		}
		for i := addi + 1; i <= addi+k; i++ {
			for j := n - k + 1; j <= n; j++ {
				out[a[i][j]]++
			}
		}
	}
	fmt.Println(best)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	solve()
}
