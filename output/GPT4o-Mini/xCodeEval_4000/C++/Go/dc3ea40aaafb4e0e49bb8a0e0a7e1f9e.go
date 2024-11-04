package main

import (
	"fmt"
	"sort"
)

const (
	LL      = int64
	Inf     = int(0x3f3f3f3f)
	INF     = int64(0x3f3f3f3f3f3f3f3f)
	Mod     = 1000000007
	MatrixSize = 77
)

type Matrix struct {
	mat [MatrixSize][MatrixSize]INT
}

func NewMatrix() Matrix {
	m := Matrix{}
	for i := 0; i < MatrixSize; i++ {
		for j := 0; j < MatrixSize; j++ {
			m.mat[i][j] = INF
		}
	}
	return m
}

func (m Matrix) Multiply(ma Matrix) Matrix {
	mat2 := NewMatrix()
	for i := 0; i < MatrixSize; i++ {
		for j := 0; j < MatrixSize; j++ {
			for k := 0; k < MatrixSize; k++ {
				mat2.mat[i][k] = min(mat2.mat[i][k], m.mat[i][j]+ma.mat[j][k])
			}
		}
	}
	return mat2
}

func ksmii(x Matrix, y int) Matrix {
	if y == 1 {
		return x
	}
	mat2 := ksmii(x, y/2)
	mat2 = mat2.Multiply(mat2)
	if y%2 == 1 {
		mat2 = mat2.Multiply(x)
	}
	return mat2
}

func min(a, b INT) INT {
	if a < b {
		return a
	}
	return b
}

type pii struct {
	first, second int
}

var (
	x, k, n, q int
	c          [15]int
	dy         [257]int
	cntdy      int
	yd         [77]int
	p          [27]int
	wp         [27]int
	wpp        = make(map[int]int)
	ws_        [27]pii
	zyj, zyj2  Matrix
)

func main() {
	zyj2 = NewMatrix()
	zyj2.mat[0][0] = 0
	fmt.Scan(&x, &k, &n, &q)
	for i := 1; i <= k; i++ {
		fmt.Scan(&c[i])
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&ws_[i].first, &ws_[i].second)
	}
	sort.Slice(ws_[:q], func(i, j int) bool {
		return ws_[i].first < ws_[j].first
	})
	for i := 0; i < q; i++ {
		p[i] = ws_[i].first
		wp[i] = ws_[i].second
		wpp[p[i]] = wp[i]
	}
	for i := 0; i < (1 << k); i++ {
		if countBits(i) == x {
			yd[cntdy] = i
			dy[i] = cntdy
			cntdy++
		}
	}
	for ii := 0; ii < cntdy; ii++ {
		j := yd[ii]
		if j&1 != 0 {
			for l := 1; l <= k; l++ {
				if !bit(j, l) {
					zyj.mat[ii][dy[(j|(1<<l))>>1]] = c[l]
				}
			}
		} else {
			zyj.mat[ii][dy[j>>1]] = 0
		}
	}
	nowpos := 1
	for i := 0; i < q; i++ {
		to := min(n-x+1, p[i]-k-1)
		if to-nowpos > 0 {
			zyj2 = zyj2.Multiply(ksmii(zyj, to-nowpos))
		}
		nm := zyj
		for j := max(nowpos, to); j < min(n-x+1, p[i]); j++ {
			for ii := 0; ii < cntdy; ii++ {
				jj := yd[ii]
				if jj&1 != 0 {
					for l := 1; l <= k; l++ {
						if !bit(jj, l) {
							nm.mat[ii][dy[(jj|(1<<l))>>1]] += wpp[j+l]
						}
					}
				}
			}
			zyj2 = zyj2.Multiply(nm)
			nm = zyj
		}
		nowpos = min(n-x+1, p[i])
	}
	if n-x+1-nowpos > 0 {
		zyj2 = zyj2.Multiply(ksmii(zyj, n-x+1-nowpos))
	}
	fmt.Printf("%d\n", zyj2.mat[0][0])
}

func countBits(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func bit(a, b int) bool {
	return (a>>b)&1 == 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
