package main

import (
	"fmt"
)

const N = 84

var a, b, c, d, e, g, h, l, p int
var s string
var f [N][N][N][2]int

func min(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	fmt.Scanf("%d%s", &n, &s)

	for i := 0; i < n; i++ {
		if i != 0 {
			p[i] = p[i-1] - 1
			h[i] = h[i-1] - 1
			l[i] = l[i-1] - 1
		}

		if s[i] == 'V' {
			d[a] = i
			h[i]++
		} else if s[i] == 'K' {
			e[b] = i
			l[i]++
		} else {
			g[c] = i
			p[i]++
		}
	}

	f[0][0][0][0] = 0
	f[0][0][0][1] = 0

	for i := 0; i <= a; i++ {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				for t := 0; t <= 1; t++ {
					pos := i + j + k

					if i < a {
						min(&f[i+1][j][k][1], f[i][j][k][t]+abs(l[d[i]]-j)+abs(p[d[i]]-k))
					}

					if j < b && t == 0 {
						min(&f[i][j+1][k][0], f[i][j][k][t]+abs(h[e[j]]-i)+abs(p[e[j]]-k))
					}

					if k < c {
						min(&f[i][j][k+1][0], f[i][j][k][t]+abs(h[g[k]]-i)+abs(l[g[k]]-j))
					}
				}
			}
		}
	}

	fmt.Printf("%d\n", min(f[a][b][c][0], f[a][b][c][1])/2)
}
