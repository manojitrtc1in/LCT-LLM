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

	fmt.Scanf("%d%s", &n, &s)

	for i := 0; i < n; i++ {
		if i != 0 {
			p[i] = p[i-1]
			h[i] = h[i-1]
			l[i] = l[i-1]
		}
		if s[i] == 'V' {
			d++
			p[i] = i
			h[i]++
		}
		if s[i] == 'K' {
			e++
			l[i] = i
		}
		if s[i] == 'H' {
			g++
			p[i] = i
		}
	}

	for i := 0; i <= a; i++ {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				for t := 0; t <= 1; t++ {
					if i < a {
						mi(f[i+1][j][k][t], f[i][j][k][1]+abs(l[i]-d[i]-j)+abs(p[i]-d[i]-k))
					}
					if j < b && !t {
						mi(f[i][j+1][k][t], f[i][j][k][0]+abs(h[i]-e[j]) + abs(p[i]-e[j]-k))
					}
					if k < c {
						mi(f[i][j][k+1][t], f[i][j][k][0]+abs(g[i]-g[k]) + abs(l[i]-g[k]-j))
					}
				}
			}
		}
	}

	fmt.Printf("%d\n", min(f[a][b][c][0], f[a][b][c][1])/2)
}

func mi(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
