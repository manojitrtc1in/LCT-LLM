package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	if n == 1 {
		fmt.Println("0")
	} else {
		v := make([]int, n)
		for i := 0; i < n; i++ {
			v[i] = nextInt(scanner)
		}
		p, q := make([]int, n), make([]int, n)
		mx := -1
		for i := 0; i < n; i++ {
			q[v[i]]++
			if q[v[i]] > mx {
				mx = q[v[i]]
			}
		}
		p := -1
		for i := 0; i < n; i++ {
			if q[i] == mx {
				p = i
				break
			}
		}
		u := make([][]int, n+1)
		for i := 0; i < n+1; i++ {
			u[i] = make([]int, 0)
		}
		for i := 0; i < n; i++ {
			if i != p {
				u[q[i]] = append(u[q[i]], i)
			}
		}
		uu := make([]int, 0)
		for i := n; i >= 0; i-- {
			if len(u[i]) > 0 {
				uu = append(uu, i)
			}
		}
		last := 0
		leftmost := make([][]int, n)
		for i := 0; i < n; i++ {
			leftmost[i] = make([]int, q[i]+1)
			for j := 0; j < q[i]+1; j++ {
				leftmost[i][j] = n + 1
			}
			leftmost[i][0] = 0
		}
		ans := 0
		for y := 0; y < min(n, 100); y++ {
			if y != p {
				g := make([]int, n+1)
				b := 0
				for i := 0; i < n; i++ {
					if v[i] == p {
						ans = max(ans, i-g[len(g)-b-1]-1)
						if b > 0 {
							b--
						} else {
							g = append(g, i)
						}
					} else if v[i] == y {
						b++
					}
				}
				ans = max(ans, n-g[len(g)-b-1]-1)
			}
		}
		fmt.Println(ans)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
