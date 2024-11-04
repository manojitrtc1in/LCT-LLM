package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type pii struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func uniteSeg(p1, p2 pii, n int) pii {
	if p1.X == -1 || p2.X == -1 {
		return pii{-1, -1}
	}
	np1 := pii{0, raz(p1.Y, p1.X, n)}
	np2 := pii{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return pii{-1, -1}
		} else {
			return pii{sum(np1.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	} else {
		if np2.X <= np1.Y+1 {
			return pii{-1, -1}
		} else {
			return pii{sum(np2.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	}
}

type sparse struct {
	n  int
	sp [][]pii
}

func countTro(r int) int {
	return 32 - int(math.Log2(float64(r)))
}

func (s *sparse) construct(v []pii) {
	s.n = len(v)
	r := countTro(s.n - 1)
	s.sp = make([][]pii, r)
	for i := 0; i < r; i++ {
		s.sp[i] = make([]pii, s.n)
	}
	for i := 0; i < s.n; i++ {
		s.sp[0][i] = v[i]
	}
	for i := 1; i < r; i++ {
		for j := 0; j < s.n; j++ {
			p1 := s.sp[i-1][j]
			p2 := s.sp[i-1][(j+(1<<(i-1)))%s.n]
			s.sp[i][j] = uniteSeg(p1, p2, s.n)
		}
	}
}

func (s *sparse) segment(l, r int) pii {
	if l == -1 || r == -1 {
		return pii{-1, -1}
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := countTro(szz) - 1
	return uniteSeg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	if n == 1 {
		fmt.Fprintln(writer, "0")
		return
	}

	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &r[i])
	}

	zz := countTro(n) + 1
	v := make([]sparse, zz)
	prs := make([]pii, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pii{-1, -1}
		} else {
			prs[i] = uniteSeg(pii{raz(i, r[i], n), i}, pii{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		newPrs := make([]pii, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			newPrs[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(newPrs)
	}

	for i := 0; i < n; i++ {
		myPr := pii{i, i}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			newPr := v[j].segment(myPr.X, myPr.Y)
			if newPr.X != -1 {
				ans += 1 << j
				myPr = newPr
			}
		}
		fmt.Fprint(writer, ans+1, " ")
	}
	fmt.Fprintln(writer)
}
