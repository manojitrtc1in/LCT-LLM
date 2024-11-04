package main

import (
	"fmt"
	"math"
)

const N = 84

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, a, b, c, d, e, g, h, l, p, f [N]int
	var s [N]byte
	var pos int

	fmt.Scanf("%d%s", &n, &s)

	for i := 0; i < n; i++ {
		if i != 0 {
			p[i] = p[i-1]
			h[i] = h[i-1]
			l[i] = l[i-1]
		}
		if s[i] == 'V' {
			d++
			pos = i
			h[i]++
		}
		if s[i] == 'K' {
			e++
			pos = i
			l[i]++
		}
		if s[i] == 'H' {
			g++
			pos = i
			p[i]++
		}
	}

	for i := 0; i <= a; i++ {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				for t := 0; t <= 1; t++ {
					if i < a {
						minimize(f[i+1][j][k][t], f[i][j][k][t]+abs(l[i]-d[i]-j) + abs(p[i]-d[i]-k))
					}
					if j < b && t == 0 {
						minimize(f[i][j+1][k][t], f[i][j][k][t]+abs(h[j]-e[j]-i) + abs(l[j]-e[j]-k))
					}
					if k < c {
						minimize(f[i][j][k+1][t], f[i][j][k][t]+abs(g[k]-f[k]-i) + abs(l[k]-f[k]-j))
					}
				}
			}
		}
	}

	fmt.Printf("%d\n", min(f[a][b][c][0], f[a][b][c][1])/2)
}

func minimize(a, b int) {
	if a > b {
		a = b
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
