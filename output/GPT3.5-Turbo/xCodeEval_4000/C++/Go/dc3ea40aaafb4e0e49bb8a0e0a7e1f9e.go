package main

import (
	"fmt"
	"sort"
)

const (
	Inf = int(0x3f3f3f3f)
	Mod = 1000000007
)

type matrix struct {
	mat [77][77]int
}

func (m matrix) multiply(ma matrix) matrix {
	mat2 := matrix{}
	for i := 0; i < 77; i++ {
		for j := 0; j < 77; j++ {
			for k := 0; k < 77; k++ {
				mat2.mat[i][k] = min(mat2.mat[i][k], m.mat[i][j]+ma.mat[j][k])
			}
		}
	}
	return mat2
}

func ksmii(x matrix, y int) matrix {
	if y == 1 {
		return x
	}
	mat2 := ksmii(x, y/2)
	mat2 = mat2.multiply(mat2)
	if y%2 == 1 {
		mat2 = mat2.multiply(x)
	}
	return mat2
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func read() int {
	num := 0
	c := getchar()
	if c == '-' {
		return -read()
	}
	for c >= '0' && c <= '9' {
		num = (num << 3) + (num << 1) + int(c-'0')
		c = getchar()
	}
	return num
}

func getchar() byte {
	var c byte
	fmt.Scanf("%c", &c)
	return c
}

func main() {
	zyj2 := matrix{}
	zyj2.mat[0][0] = 0
	x := read()
	k := read()
	n := read()
	q := read()
	c := make([]int, k+1)
	for i := 1; i <= k; i++ {
		c[i] = read()
	}
	ws_ := make([]struct{ first, second int }, q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d%d", &ws_[i].first, &ws_[i].second)
	}
	sort.Slice(ws_, func(i, j int) bool {
		return ws_[i].first < ws_[j].first
	})
	p := make([]int, q)
	wp := make([]int, q)
	wpp := make(map[int]int)
	for i := 0; i < q; i++ {
		p[i] = ws_[i].first
		wp[i] = ws_[i].second
		wpp[p[i]] = wp[i]
	}
	dy := make([]int, 257)
	cntdy := 0
	yd := make([]int, 77)
	for i := 0; i < 256; i++ {
		if countBits(i) == x {
			yd[cntdy] = i
			dy[i] = cntdy
			cntdy++
		}
	}
	zyj := matrix{}
	for ii := 0; ii < cntdy; ii++ {
		j := yd[ii]
		if j&1 == 1 {
			for l := 1; l <= k; l++ {
				if j&(1<<l) == 0 {
					zyj.mat[ii][dy[(j+(1<<l))>>1]] = c[l]
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
			zyj2 = zyj2.multiply(ksmii(zyj, to-nowpos))
		}
		nm := zyj
		for j := max(nowpos, to); j < min(n-x+1, p[i]); j++ {
			for ii := 0; ii < cntdy; ii++ {
				jj := yd[ii]
				if jj&1 == 1 {
					for l := 1; l <= k; l++ {
						if jj&(1<<l) == 0 {
							nm.mat[ii][dy[(jj+(1<<l))>>1]] += wpp[j+l]
						}
					}
				}
			}
			zyj2 = zyj2.multiply(nm)
			nm = zyj
		}
		nowpos = min(n-x+1, p[i])
	}
	if n-x+1-nowpos > 0 {
		zyj2 = zyj2.multiply(ksmii(zyj, n-x+1-nowpos))
	}
	fmt.Printf("%d\n", zyj2.mat[0][0])
}

func countBits(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
