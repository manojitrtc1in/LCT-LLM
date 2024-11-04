package main

import (
	"fmt"
	"math"
	"sort"
)

type DB float64

const (
	PI  = math.Acos(-1)
	INF = 1e10
	EPS = 1e-8
)

func sqr(v DB) DB {
	return v * v
}

func sgn(v DB) int {
	if v < -EPS {
		return -1
	} else if v > EPS {
		return 1
	}
	return 0
}

type PT struct {
	x, y DB
}

func NewPT(x, y DB) PT {
	return PT{x: x, y: y}
}

func (p PT) Add(o PT) PT {
	return NewPT(p.x+o.x, p.y+o.y)
}

func (p *PT) AddAssign(o PT) {
	p.x += o.x
	p.y += o.y
}

func (p PT) Sub(o PT) PT {
	return NewPT(p.x-o.x, p.y-o.y)
}

func (p *PT) SubAssign(o PT) {
	p.x -= o.x
	p.y -= o.y
}

func (p PT) Neg() PT {
	return NewPT(-p.x, -p.y)
}

func (p PT) Mul(c DB) PT {
	return NewPT(p.x*c, p.y*c)
}

func (p *PT) MulAssign(c DB) {
	p.x *= c
	p.y *= c
}

func (p PT) Div(c DB) PT {
	return NewPT(p.x/c, p.y/c)
}

func (p *PT) DivAssign(c DB) {
	p.x /= c
	p.y /= c
}

func (p PT) Less(o PT) bool {
	if sgn(p.x - o.x) != 0 {
		return sgn(p.x - o.x) < 0
	}
	return sgn(p.y - o.y) < 0
}

func (p PT) Equal(o PT) bool {
	return sgn(p.x-o.x) == 0 && sgn(p.y-o.y) == 0
}

func (p PT) NotEqual(o PT) bool {
	return sgn(p.x-o.x) != 0 || sgn(p.y-o.y) != 0
}

func dis(v PT) DB {
	return math.Sqrt(float64(sqr(v.x) + sqr(v.y)))
}

func dis2(v PT) DB {
	return sqr(v.x) + sqr(v.y)
}

func dis(p1, p2 PT) DB {
	return dis(p1.Sub(p2))
}

func dis2(p1, p2 PT) DB {
	return dis2(p1.Sub(p2))
}

func vect(v1, v2 PT) DB {
	return v1.x*v2.y - v2.x*v1.y
}

func vectP(p, p1, p2 PT) DB {
	return vect(p1.Sub(p), p2.Sub(p))
}

func scal(v1, v2 PT) DB {
	return v1.x*v2.x + v1.y*v2.y
}

func scalP(p, p1, p2 PT) DB {
	return scal(p1.Sub(p), p2.Sub(p))
}

func sect(p PT) int {
	if sgn(p.x) == 0 && sgn(p.y) == 0 {
		return 0
	}
	if sgn(p.x) == 0 {
		if sgn(p.y) > 0 {
			return 2
		}
		return 4
	}
	if sgn(p.y) == 0 {
		if sgn(p.x) > 0 {
			return 1
		}
		return 3
	}
	if sgn(p.x) == 1 {
		if sgn(p.y) == 1 {
			return 1
		}
		return 4
	}
	return 3
}

func ang(v PT) DB {
	return math.Atan2(float64(v.y), float64(v.x))
}

func angP(p1, p2 PT) DB {
	return ang(p2.Sub(p1))
}

func ang3(p, p1, p2 PT) DB {
	dy := vectP(p, p1, p2)
	dx := scalP(p, p1, p2)
	if sgn(dy) == 0 {
		dy = 0
	}
	if sgn(dx) == 0 {
		dx = 0
	}
	return math.Atan2(float64(dy), float64(dx))
}

func proj(p, p1, p2 PT) PT {
	return p1.Add(p2.Sub(p1).Mul(scalP(p1, p, p2) / dis2(p1, p2)))
}

func normalLine(p1, p2 PT) PT {
	return NewPT(-(p2.y - p1.y), p2.x-p1.x)
}

func gravityCenter(p []PT, n int) PT {
	var o PT
	for i := 0; i < n; i++ {
		o.AddAssign(p[i])
	}
	return o.Div(DB(n))
}

func main() {
	var n int
	fmt.Scan(&n)
	p := make([]PT, n)
	for i := 0; i < n; i++ {
		var x, y DB
		fmt.Scan(&x, &y)
		p[i] = NewPT(x, y)
	}
	g := gravityCenter(p, n)
	for i := 0; i < n; i++ {
		p[i].SubAssign(g)
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].Less(p[j])
	})
	var q PT
	for i := 0; i < n; i++ {
		fp := sort.Search(n, func(i int) bool {
			return p[i].NotEqual(p[i].Neg())
		})
		if p[fp].NotEqual(p[i].Neg()) {
			q = p[i]
			break
		}
		if i == n-1 {
			fmt.Println("-1")
			return
		}
	}
	v := []PT{}
	for i := 0; i < n; i++ {
		m := p[i].Add(q).Div(2)
		nv := normalLine(NewPT(0, 0), m)
		if sect(nv) >= 3 {
			nv = nv.Neg()
		}
		v = append(v, nv)
	}
	sort.Slice(v, func(i, j int) bool {
		return sect(v[i]) < sect(v[j])
	})
	v = unique(v)
	ans := 0
	d := make([]DB, n)
	for i := 0; i < len(v); i++ {
		for j := 0; j < n; j++ {
			d[j] = scal(v[i], proj(p[j], NewPT(0, 0), v[i])) / dis(v[i])
		}
		sort.Slice(d, func(i, j int) bool {
			return d[i] < d[j]
		})
		flg := true
		for j := 0; j < n/2; j++ {
			if sgn(d[j]+d[n-1-j]) != 0 {
				flg = false
			}
		}
		if flg {
			ans++
		}
	}
	fmt.Println(ans)
}

func unique(v []PT) []PT {
	seen := make(map[PT]struct{})
	result := []PT{}
	for _, pt := range v {
		if _, ok := seen[pt]; !ok {
			seen[pt] = struct{}{}
			result = append(result, pt)
		}
	}
	return result
}
