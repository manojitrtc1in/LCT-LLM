package main

import (
	"fmt"
	"math/rand"
	"sort"
)

type Inte struct {
	v int64
	p int64
}

func NewInte(t int64, p int64) *Inte {
	return &Inte{v: t % p, p: p}
}

func (a *Inte) WrapAround() {
	if a.v < 0 {
		a.v = (a.v % a.p + a.p) % a.p
	} else if a.v >= a.p {
		a.v %= a.p
	}
}

func (a *Inte) Add(b *Inte) *Inte {
	c := NewInte(a.v+b.v, a.p)
	c.WrapAround()
	return c
}

func (a *Inte) Sub(b *Inte) *Inte {
	c := NewInte(a.v-b.v, a.p)
	c.WrapAround()
	return c
}

func (a *Inte) Mul(b *Inte) *Inte {
	c := NewInte(a.v*b.v, a.p)
	c.WrapAround()
	return c
}

func (a *Inte) Div(b *Inte) *Inte {
	return a.Mul(Inverse(b))
}

func Inverse(a *Inte) *Inte {
	// Implement modular inverse using Extended Euclidean Algorithm
	return NewInte(1, a.p) // Placeholder
}

type Statistic struct {
	p [2][2]*Inte
	l int
	r int
}

func NewStatistic(pr *Inte, pos int) *Statistic {
	s := &Statistic{}
	s.p[0][0] = NewInte(1-pr.v, pr.p)
	s.p[1][1] = pr
	s.l = pos
	s.r = pos
	return s
}

func (s *Statistic) Merge(a, b *Statistic) {
	s.l = a.l
	s.r = b.r
	m := a.r
	for i := 0; i <= 1; i++ {
		for j := 0; j <= 1; j++ {
			s.p[i][j] = NewInte(0, a.p[0][0].p)
			for k := 0; k <= 1; k++ {
				for l := 0; l <= 1; l++ {
					// Implement policy checks here
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

func (s *Statistic) Ans() *Inte {
	tmp := NewInte(0, s.p[0][0].p)
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
	t1 int
	t2 int
}

func (c *Col) Ans() *Inte {
	return NewInte(int64(c.t1)/int64(c.t2), 998244353)
}

func main() {
	rand.Seed(42) // Seed for random number generation
	var n int
	fmt.Scan(&n)
	policy := make([][]int, n-1)
	for i := range policy {
		policy[i] = make([]int, 4)
		for j := range policy[i] {
			policy[i][j] = 1
		}
	}
	s := make([]*Statistic, n)
	x := make([]int, n)
	v := make([]int, n)
	p := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &v[i], &p[i])
		s[i] = NewStatistic(NewInte(int64(p[i])/100, 998244353), i)
	}

	ans := NewInte(0, 998244353)
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

	sort.Slice(cols, func(i, j int) bool {
		return int64(cols[i].t1)*int64(cols[j].t2) < int64(cols[j].t1)*int64(cols[i].t2)
	})

	for _, c := range cols {
		old := policy[c.i]
		for i := range policy[c.i] {
			policy[c.i][i] = 0
		}
		policy[c.i][c.tp] = 1
		// tree.modify_single(c.i, NewStatistic(NewInte(int64(p[c.i])/100, 998244353), c.i))
		ans = ans.Add(c.Ans())
		policy[c.i] = old
		policy[c.i][c.tp] = 0
		// tree.modify_single(c.i, NewStatistic(NewInte(int64(p[c.i])/100, 998244353), c.i))
		// if tree.root.s.ans().v == 0 {
		// 	break
		// }
	}
	fmt.Println(ans.v)
}
