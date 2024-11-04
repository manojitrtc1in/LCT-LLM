package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, a, b, c, d, e, g, h, l, p int
	var f [200][200][200][2]int
	var s string

	fmt.Scanf("%d%s", &n, &s)
	for i := 0; i < n; i++ {
		if i != 0 {
			p = p
			h = h
			l = l
		}
		if s[i] == 'V' {
			d = a
			a++
		}
		if s[i] == 'K' {
			e = b
			b++
		}
		if s[i] == 'H' {
			g = c
			c++
		}
	}

	for i := 0; i <= a; i++ {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				for t := 0; t <= 1; t++ {
					if i < a {
						f[i+1][j][k][1] = min(f[i+1][j][k][1], f[i][j][k][t]+abs(l[d+i]-j)+abs(p[d+i]-k))
					}
					if j < b && t == 0 {
						f[i][j+1][k][0] = min(f[i][j+1][k][0], f[i][j][k][t]+abs(h[e+j]-i)+abs(p[e+j]-k))
					}
					if k < c {
						f[i][j][k+1][0] = min(f[i][j][k+1][0], f[i][j][k][t]+abs(h[g+k]-i)+abs(l[g+k]-j))
					}
				}
			}
		}
	}

	fmt.Printf("%d\n", min(f[a][b][c][0], f[a][b][c][1])/2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
