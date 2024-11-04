package main

import (
	"fmt"
	"sort"
)

const INF = 1e18
const MAXK = 15
const MAXN = 77

type Matrix struct {
	mat [MAXN][MAXN]int64
}

func NewMatrix() Matrix {
	m := Matrix{}
	for i := 0; i < MAXN; i++ {
		for j := 0; j < MAXN; j++ {
			m.mat[i][j] = INF
		}
	}
	return m
}

func (m1 Matrix) Multiply(m2 Matrix) Matrix {
	mat2 := NewMatrix()
	for i := 0; i < MAXN; i++ {
		for j := 0; j < MAXN; j++ {
			for k := 0; k < MAXN; k++ {
				mat2.mat[i][k] = min(mat2.mat[i][k], m1.mat[i][j]+m2.mat[j][k])
			}
		}
	}
	return mat2
}

func id0(x Matrix, y int) Matrix {
	if y == 1 {
		return x
	}
	mat2 := id0(x, y/2)
	mat2 = mat2.Multiply(mat2)
	if y%2 == 1 {
		mat2 = mat2.Multiply(x)
	}
	return mat2
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

var (
	x, k, n, q int
	c          [MAXK]int
	dy         [257]int
	cntdy     int
	yd         [MAXN]int
	p          [27]int
	wp         [27]int
	wpp        = make(map[int]int)
	ws_        [27][2]int
)

func main() {
	id1 := NewMatrix()
	id1.mat[0][0] = 0

	fmt.Scanf("%d%d%d%d", &x, &k, &n, &q)
	for i := 1; i <= k; i++ {
		fmt.Scanf("%d", &c[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scanf("%d%d", &ws_[i][0], &ws_[i][1])
	}
	sort.Slice(ws_[:q], func(i, j int) bool {
		return ws_[i][0] < ws_[j][0]
	})
	for i := 0; i < q; i++ {
		p[i] = ws_[i][0]
		wp[i] = ws_[i][1]
		wpp[p[i]] = wp[i]
	}
	for i := 0; i < (1 << k); i++ {
		if countBits(i) == x {
			yd[cntdy] = i
			dy[i] = cntdy
			cntdy++
		}
	}
	zyj := NewMatrix()
	for ii := 0; ii < cntdy; ii++ {
		j := yd[ii]
		if j&1 != 0 {
			for l := 1; l <= k; l++ {
				if (j&(1<<(l-1))) == 0 {
					zyj.mat[ii][dy[(j+(1<<l-1))>>1]] = int64(c[l])
				}
			}
		} else {
			zyj.mat[ii][dy[j>>1]] = 0
		}
	}
	nowpos := 1
	for i := 0; i < q; i++ {
		to := minInt(n-x+1, p[i]-k-1)
		if to-nowpos > 0 {
			id1 = id1.Multiply(id0(zyj, to-nowpos))
		}

		nm := zyj
		for j := maxInt(nowpos, to); j < minInt(n-x+1, p[i]); j++ {
			for ii := 0; ii < cntdy; ii++ {
				jj := yd[ii]
				if jj&1 != 0 {
					for l := 1; l <= k; l++ {
						if (jj&(1<<(l-1))) == 0 {
							nm.mat[ii][dy[(jj+(1<<l-1))>>1]] += int64(wpp[j+l])
						}
					}
				}
			}
			id1 = id1.Multiply(nm)
			nm = zyj
		}
		nowpos = minInt(n-x+1, p[i])
	}
	if n-x+1-nowpos > 0 {
		id1 = id1.Multiply(id0(zyj, n-x+1-nowpos))
	}

	fmt.Printf("%d\n", id1.mat[0][0])
}

func countBits(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
