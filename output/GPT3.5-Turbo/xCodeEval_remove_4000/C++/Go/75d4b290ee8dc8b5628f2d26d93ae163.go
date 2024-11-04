package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

const MOD7 = 1000000007
const MOD9 = 1000000009
const MODF = 998244353

var mod = MOD7

type modint struct {
	n int
}

func newModint(n int) modint {
	if n >= 0 && n < mod {
		return modint{n: n}
	}
	n %= mod
	if n < 0 {
		n += mod
	}
	return modint{n: n}
}

func (a modint) add(b modint) modint {
	a.n += b.n
	if a.n >= mod {
		a.n -= mod
	}
	return a
}

func (a modint) sub(b modint) modint {
	a.n -= b.n
	if a.n < 0 {
		a.n += mod
	}
	return a
}

func (a modint) mul(b modint) modint {
	a.n = (a.n * b.n) % mod
	return a
}

func (a modint) div(b modint) modint {
	if b.n == 0 {
		panic("Division by zero")
	}
	return a.mul(b.inverse())
}

func (a modint) inverse() modint {
	var x, y int64
	g := gcd(int64(a.n), int64(mod), &x, &y)

	if g != 1 {
		panic("not inversable")
	}

	return modint{n: int(x)}
}

func (a modint) log(alpha modint) int {
	base := make(map[modint]int)
	exp := 0
	pow := modint{1}
	inv := a
	alInv := alpha.inverse()
	for exp*exp < mod {
		if inv.n == 1 {
			return exp
		}
		base[inv] = exp
		exp++
		pow = pow.mul(alpha)
		inv = inv.mul(alInv)
	}
	step := pow
	for i := 1; ; i++ {
		if _, ok := base[pow]; ok {
			return exp*i + base[pow]
		}
		pow = pow.mul(step)
	}
}

func gcd(a, b int64, x, y *int64) int64 {
	if a == 0 {
		*x = 0
		*y = 1
		return b
	}
	var x1, y1 int64
	d := gcd(b%a, a, &x1, &y1)
	*x = y1 - (b/a)*x1
	*y = x1
	return d
}

type Event struct {
	typ int
	at  int
	dx  int
	v   int
}

type Events []Event

func (e Events) Len() int           { return len(e) }
func (e Events) Less(i, j int) bool { return int64(e[i].dx)*int64(e[j].v) < int64(e[j].dx)*int64(e[i].v) }
func (e Events) Swap(i, j int)      { e[i], e[j] = e[j], e[i] }

func solve(n int, x, v, p []int) modint {
	pp := make([][]modint, 4*n)
	tmp := make([][]modint, 4*n)
	allowed := make([][]bool, n)
	for i := 0; i < n; i++ {
		allowed[i] = make([]bool, 4)
		for j := 0; j < 4; j++ {
			allowed[i][j] = true
		}
	}
	join := func(left, right, result []modint, at int) {
		for i := 0; i < 2; i++ {
			for j := 0; j < 2; j++ {
				for k := 0; k < 2; k++ {
					for l := 0; l < 2; l++ {
						if allowed[at][2*j+k] {
							result[i*2+l] = result[i*2+l].add(left[i*2+j].mul(right[k*2+l]))
						}
					}
				}
			}
		}
	}
	init := func(root, left, right int) {
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
	events := make(Events, 0)
	for i := 1; i < n; i++ {
		events = append(events, Event{2, i, x[i] - x[i-1], v[i] + v[i-1]})
		if v[i] > v[i-1] {
			events = append(events, Event{0, i, x[i] - x[i-1], v[i] - v[i-1]})
		} else if v[i] < v[i-1] {
			events = append(events, Event{3, i, x[i] - x[i-1], v[i-1] - v[i]})
		}
	}
	sort.Sort(events)
	query := func(root, left, right, from, to int) bool {
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
	recalc := func(root, left, right, at int) {
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
		answer = answer.add(newModint(e.dx).div(newModint(e.v)).mul(left).mul(right))
		allowed[e.at][e.typ] = false
		recalc(0, 0, n, e.at)
	}
	return answer
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	x := make([]int, n)
	v := make([]int, n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &x[i], &v[i], &p[i])
	}

	mod = MODF
	answer := solve(n, x, v, p)
	fmt.Fprintln(writer, answer)
}
