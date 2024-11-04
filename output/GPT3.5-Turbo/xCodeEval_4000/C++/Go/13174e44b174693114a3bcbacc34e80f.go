package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type pair struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

func mp(x, y int) pair {
	return pair{X: x, Y: y}
}

func pb(v []int, x int) []int {
	return append(v, x)
}

func sz(x []int) int {
	return len(x)
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

func uniteSeg(p1, p2 pair, n int) pair {
	if p1.X == -1 || p2.X == -1 {
		return pair{-1, -1}
	}
	np1 := pair{0, raz(p1.Y, p1.X, n)}
	np2 := pair{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np1.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	} else {
		if np2.X <= np1.Y+1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np2.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	}
}

type sparse struct {
	n  int
	sp [][]pair
}

func (s *sparse) construct(v []pair) {
	s.n = len(v)
	r := countTro(s.n - 1)
	s.sp = make([][]pair, r)
	for i := 0; i < r; i++ {
		s.sp[i] = make([]pair, s.n)
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

func (s *sparse) segment(l, r int) pair {
	if l == -1 || r == -1 {
		return pair{-1, -1}
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := countTro(szz) - 1
	return uniteSeg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
}

func countTro(r int) int {
	return 32 - int(math.Log2(float64(r)))
}

func findMinIdx(v []int) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i] < v[ans] {
			ans = i
		}
	}
	return ans
}

func convexHull(a []pair) []int {
	n := len(a)
	if n > 0 {
		mt := findMinIdx(a)
		d := a[mt]
		for i := 0; i < n; i++ {
			a[i].X -= d.X
			a[i].Y -= d.Y
		}

		idx := make([]int, n)
		for i := 0; i < n; i++ {
			idx[i] = i
		}
		sort.Slice(idx, func(i, j int) bool {
			return angdisCmp(a[idx[i]], a[idx[j]])
		})

		h := []int{idx[0]}
		for _, it := range idx[1:] {
			temp := a[it]
			if len(h) >= 2 {
				if areParallel(a[h[len(h)-1]], temp) {
					h = h[:len(h)-1]
				}
				for len(h) >= 3 && npocs(a[h[len(h)-2]], a[h[len(h)-1]], temp) {
					h = h[:len(h)-1]
				}
			}
			h = append(h, it)
		}

		for i := 0; i < n; i++ {
			a[i].X += d.X
			a[i].Y += d.Y
		}
		return h
	} else {
		return []int{}
	}
}

func angdisCmp(a, b pair) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return a.X*a.X+a.Y*a.Y < b.X*b.X+b.Y*b.Y
	}
}

func areParallel(a, b pair) bool {
	return a.X*b.Y == a.Y*b.X
}

func npocs(a, b, c pair) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())

	if n == 1 {
		fmt.Println("0")
		return
	}

	r := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		r[i] = parseInt(scanner.Text())
	}

	zz := countTro(n)
	v := make([]sparse, zz)
	prs := make([]pair, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pair{-1, -1}
		} else {
			prs[i] = uniteSeg(pair{raz(i, r[i], n), i}, pair{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		newPrs := make([]pair, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			newPrs[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(newPrs)
	}

	for i := 0; i < n; i++ {
		myPr := pair{i, i}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			newPr := v[j].segment(myPr.X, myPr.Y)
			if newPr.X != -1 {
				ans += 1 << j
				myPr = newPr
			}
		}
		fmt.Printf("%d ", ans+1)
	}
	fmt.Println()
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}
