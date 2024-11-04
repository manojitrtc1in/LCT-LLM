package main

import (
	"fmt"
	"sort"
)

const (
	INF  = 1<<31 - 1
	MASK = (1 << 15) - 1
)

type pii struct {
	first  int
	second int
}

type matrix struct {
	mat [77][77]int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func id0(x matrix, y int) matrix {
	if y == 1 {
		return x
	}
	mat2 := id0(x, y/2)
	mat2 = mat2.multiply(mat2)
	if y%2 == 1 {
		mat2 = mat2.multiply(x)
	}
	return mat2
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

func READ() int {
	num := 0
	c := getchar()
	if c == '-' {
		return -READ()
	}
	for c >= '0' && c <= '9' {
		num = (num << 3) + (num << 1) + int(c-'0')
		c = getchar()
	}
	return num
}

func getchar() byte {
	// Implement your own getchar function here
	return ' '
}

func main() {
	id1 := matrix{}
	id1.mat[0][0] = 0
	x := read()
	k := read()
	n := read()
	q := read()
	c := make([]int, k+1)
	for i := 1; i <= k; i++ {
		c[i] = read()
	}
	ws := make([]pii, q)
	for i := 0; i < q; i++ {
		ws[i].first = read()
		ws[i].second = read()
	}
	sort.Slice(ws, func(i, j int) bool {
		return ws[i].first < ws[j].first
	})
	p := make([]int, q)
	wp := make([]int, q)
	wpp := make(map[int]int)
	for i := 0; i < q; i++ {
		p[i] = ws[i].first
		wp[i] = ws[i].second
		wpp[p[i]] = wp[i]
	}
	dy := make([]int, 257)
	cntdy := 0
	yd := make([]int, 77)
	for i := 0; i < (1 << k); i++ {
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
				if bit(j, l) == 0 {
					zyj.mat[ii][dy[(j+MASK)>>1]] = c[l]
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
			id1 = id1.multiply(id0(zyj, to-nowpos))
		}

		nm := zyj
		for j := max(nowpos, to); j < min(n-x+1, p[i]); j++ {
			for ii := 0; ii < cntdy; ii++ {
				jj := yd[ii]
				if jj&1 == 1 {
					for l := 1; l <= k; l++ {
						if bit(jj, l) == 0 {
							nm.mat[ii][dy[(jj+MASK)>>1]] += wpp[j+l]
						}
					}
				}
			}
			id1 = id1.multiply(nm)
			nm = zyj
		}
		nowpos = min(n-x+1, p[i])
	}
	if n-x+1-nowpos > 0 {
		id1 = id1.multiply(id0(zyj, n-x+1-nowpos))
	}

	fmt.Println(id1.mat[0][0])
}

func countBits(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func bit(n, pos int) int {
	return (n >> (pos - 1)) & 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
