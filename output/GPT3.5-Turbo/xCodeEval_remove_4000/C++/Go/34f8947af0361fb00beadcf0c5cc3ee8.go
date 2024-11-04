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
	var n, a, b, c, d int
	var s string
	fmt.Scan(&n, &s)

	p := make([]int, n)
	h := make([]int, n)
	l := make([]int, n)
	f := make([][]int, a+1)
	for i := range f {
		f[i] = make([]int, b+1)
		for j := range f[i] {
			f[i][j] = math.MaxInt32
		}
	}

	for i := 0; i < n; i++ {
		if i != 0 {
			p[i] = p[i-1]
			h[i] = h[i-1]
			l[i] = l[i-1]
		}

		if s[i] == 'V' {
			d++
			h[i]++
		} else if s[i] == 'K' {
			e++
			l[i]++
		} else {
			g++
			p[i]++
		}
	}

	for i := 0; i <= a; i++ {
		for j := 0; j <= b; j++ {
			for k := 0; k <= c; k++ {
				for t := 0; t <= 1; t++ {
					if i < a {
						f[i+1][j][k][1] = min(f[i+1][j][k][1], f[i][j][k][t]+abs(l[d][i]-j)+abs(p[d][i]-k))
					}
					if j < b && t == 0 {
						f[i][j+1][k][0] = min(f[i][j+1][k][0], f[i][j][k][t]+abs(h[e][j]-i)+abs(p[e][j]-k))
					}
					if k < c {
						f[i][j][k+1][0] = min(f[i][j][k+1][0], f[i][j][k][t]+abs(h[g][k]-i)+abs(l[g][k]-j))
					}
				}
			}
		}
	}

	fmt.Println(min(f[a][b][c][0], f[a][b][c][1])/2)
}
