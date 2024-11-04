package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	MOD7 = 1000000007
	MOD9 = 1000000009
	MODF = 998244353
)

var mod = MOD7

type modint struct {
	n int
}

func newModint(n int64) modint {
	if n >= 0 && n < int64(mod) {
		return modint{int(n)}
	}
	n %= int64(mod)
	if n < 0 {
		n += int64(mod)
	}
	return modint{int(n)}
}

func (a *modint) add(b modint) {
	a.n += b.n
	if a.n >= mod {
		a.n -= mod
	}
}

func (a *modint) sub(b modint) {
	a.n -= b.n
	if a.n < 0 {
		a.n += mod
	}
}

func (a *modint) mul(b modint) {
	a.n = int(int64(a.n) * int64(b.n) % int64(mod))
}

func (a *modint) div(b modint) {
	if b.n == 0 {
		panic("Division by zero")
	}
	a.mul(b.inverse())
}

func (a modint) inverse() modint {
	x, y := 0, 0
	g := gcd(a.n, mod, &x, &y)
	if g != 1 {
		panic("not inversable")
	}
	return newModint(int64(x))
}

func gcd(a, b int, x, y *int) int {
	if a == 0 {
		*x = 0
		*y = 1
		return b
	}
	d := gcd(b%a, a, y, x)
	*y -= (b / a) * (*x)
	return d
}

type Event struct {
	typ int
	at  int
	dx  int
	v   int
}

type TaskD struct{}

func (t *TaskD) solve(n int, x, v, p []int) modint {
	mod = MODF
	pp := make([][]modint, 4*n)
	tmp := make([][]modint, 4*n)
	allowed := make([][]bool, n)
	for i := range allowed {
		allowed[i] = make([]bool, 4)
		for j := range allowed[i] {
			allowed[i][j] = true
		}
	}

	var join func(left, right []modint, result []modint, at int)
	join = func(left, right []modint, result []modint, at int) {
		for i := 0; i < 2; i++ {
			for j := 0; j < 2; j++ {
				for k := 0; k < 2; k++ {
					for l := 0; l < 2; l++ {
						if allowed[at][2*j+k] {
							result[i*2+l].add(left[i*2+j].mul(right[k*2+l]))
						}
					}
				}
			}
		}
	}

	var init func(root, left, right int)
	init = func(root, left, right int) {
		pp[root] = make([]modint, 4)
		tmp[root] = make([]modint, 4)
		if left+1 == right {
			pp[root][0] = newModint(100 - p[left]).div(newModint(100))
			pp[root][3] = newModint(1).sub(pp[root][0])
		} else {
			mid := (left + right) / 2
			init(2*root+1, left, mid)
			init(2*root+2, mid, right)
			join(pp[2*root+1], pp[2*root+2], pp[root], mid)
		}
	}

	init(0, 0, n)

	events := []Event{}
	for i := 1; i < n; i++ {
		events = append(events, Event{2, i, x[i] - x[i-1], v[i] + v[i-1]})
		if v[i] > v[i-1] {
			events = append(events, Event{0, i, x[i] - x[i-1], v[i] - v[i-1]})
		} else if v[i] < v[i-1] {
			events = append(events, Event{3, i, x[i] - x[i-1], v[i-1] - v[i]})
		}
	}
	sort.Slice(events, func(i, j int) bool {
		return events[i].dx*events[j].v < events[j].dx*events[i].v
	})

	var query func(root, left, right, from, to int) bool
	query = func(root, left, right, from, to int) bool {
		if left >= to || right <= from {
			return false
		}
		if left >= from && right <= to {
			copy(tmp[root], pp[root])
			return true
		}
		mid := (left + right) / 2
		lRes := query(2*root+1, left, mid, from, to)
		rRes := query(2*root+2, mid, right, from, to)
		if !lRes {
			copy(tmp[root], tmp[2*root+2])
			return true
		}
		if !rRes {
			copy(tmp[root], tmp[2*root+1])
			return true
		}
		join(tmp[2*root+1], tmp[2*root+2], tmp[root], mid)
		return true
	}

	var recalc func(root, left, right, at int)
	recalc = func(root, left, right, at int) {
		if left >= at || right <= at {
			return
		}
		mid := (left + right) / 2
		recalc(2*root+1, left, mid, at)
		recalc(2*root+2, mid, right, at)
		join(pp[2*root+1], pp[2*root+2], pp[root], mid)
	}

	answer := newModint(0)
	for _, e := range events {
		query(0, 0, n, 0, e.at)
		left := tmp[0][e.typ/2].add(tmp[0][2+e.typ/2])
		query(0, 0, n, e.at, n)
		right := tmp[0][e.typ%2*2].add(tmp[0][e.typ%2*2+1])
		answer.add(newModint(int64(e.dx)).div(int64(e.v)).mul(left).mul(right))
		allowed[e.at][e.typ] = false
		recalc(0, 0, n, e.at)
	}
	return answer
}

func main() {
	var n int
	fmt.Scan(&n)
	x := make([]int, n)
	v := make([]int, n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&v[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}
	solver := TaskD{}
	result := solver.solve(n, x, v, p)
	fmt.Println(result.n)
}
