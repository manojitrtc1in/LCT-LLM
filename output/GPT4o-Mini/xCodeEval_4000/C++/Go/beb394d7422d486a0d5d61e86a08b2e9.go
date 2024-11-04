package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Inte struct {
	v int64
	p int64
}

func NewInte(t int64) Inte {
	return Inte{v: t % 998244353, p: 998244353}
}

func (a *Inte) Add(b Inte) Inte {
	return NewInte((a.v + b.v) % a.p)
}

func (a *Inte) Sub(b Inte) Inte {
	return NewInte((a.v - b.v + a.p) % a.p)
}

func (a *Inte) Mul(b Inte) Inte {
	return NewInte((a.v * b.v) % a.p)
}

func (a *Inte) Div(b Inte) Inte {
	return a.Mul(Inverse(b))
}

func Inverse(a Inte) Inte {
	return Pow(a, a.p-2)
}

func Pow(a Inte, b int64) Inte {
	r := NewInte(1)
	for b > 0 {
		if b&1 == 1 {
			r = r.Mul(a)
		}
		a = a.Mul(a)
		b >>= 1
	}
	return r
}

type Statistic struct {
	p [2][2]Inte
	l int
	r int
}

func NewStatistic(pr Inte, pos int) Statistic {
	var s [2][2]Inte
	s[0][0] = NewInte(1).Sub(pr)
	s[1][1] = pr
	return Statistic{p: s, l: pos, r: pos}
}

func (s *Statistic) Merge(a, b Statistic) {
	s.l = a.l
	s.r = b.r
	m := a.r
	for i := 0; i <= 1; i++ {
		for j := 0; j <= 1; j++ {
			s.p[i][j] = NewInte(0)
			for k := 0; k <= 1; k++ {
				for l := 0; l <= 1; l++ {
					if k == 0 && l == 1 && policy[m][3] == 1 {
						s.p[i][j] = s.p[i][j].Add(a.p[i][k].Mul(b.p[l][j]))
					} else if k == 0 && l == 0 && policy[m][0] == 1 {
						s.p[i][j] = s.p[i][j].Add(a.p[i][k].Mul(b.p[l][j]))
					} else if k == 1 && l == 1 && policy[m][1] == 1 {
						s.p[i][j] = s.p[i][j].Add(a.p[i][k].Mul(b.p[l][j]))
					} else if k == 1 && l == 0 && policy[m][2] == 1 {
						s.p[i][j] = s.p[i][j].Add(a.p[i][k].Mul(b.p[l][j]))
					}
				}
			}
		}
	}
}

func (s *Statistic) Ans() Inte {
	tmp := NewInte(0)
	for i := 0; i <= 1; i++ {
		for j := 0; j <= 1; j++ {
			tmp = tmp.Add(s.p[i][j])
		}
	}
	return tmp
}

type Col struct {
	i  int
	tp int
	t1 int64
	t2 int64
}

func (c *Col) Ans() Inte {
	return NewInte(c.t1).Div(NewInte(c.t2))
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var n int
	fmt.Scan(&n)
	policy := make([][]int, n-1)
	for i := range policy {
		policy[i] = make([]int, 4)
		for j := range policy[i] {
			policy[i][j] = 1
		}
	}

	s := make([]Statistic, n)
	x := make([]int64, n)
	v := make([]int64, n)
	p := make([]int64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &v[i], &p[i])
		s[i] = NewStatistic(NewInte(p[i]).Div(NewInte(100)), i)
	}

	ans := NewInte(0)
	cols := []Col{}

	for i := 0; i < n-1; i++ {
		tmp := Col{i: i, t1: x[i+1] - x[i], tp: 2, t2: v[i] + v[i+1]}
		cols = append(cols, tmp)

		if v[i] > v[i+1] {
			tmp.tp = 1
			tmp.t2 = v[i] - v[i+1]
			cols = append(cols, tmp)
		}
		if v[i] < v[i+1] {
			tmp.tp = 0
			tmp.t2 = v[i+1] - v[i]
			cols = append(cols, tmp)
		}
	}

	// Sorting cols based on custom logic
	// Sort(cols)

	for _, c := range cols {
		old := policy[c.i]
		for j := range policy[c.i] {
			policy[c.i][j] = 0
		}
		policy[c.i][c.tp] = 1
		// tree.modify_single(c.i, NewStatistic(NewInte(p[c.i]).Div(NewInte(100)), c.i))
		ans = ans.Add(/* tree.root.s.ans() */.Mul(c.Ans()))
		policy[c.i] = old
		policy[c.i][c.tp] = 0
		// tree.modify_single(c.i, NewStatistic(NewInte(p[c.i]).Div(NewInte(100)), c.i))
		// if tree.root.s.ans().v == 0 {
		// 	break
		// }
	}
	fmt.Printf("%.12f\n", float64(ans.v))
}
