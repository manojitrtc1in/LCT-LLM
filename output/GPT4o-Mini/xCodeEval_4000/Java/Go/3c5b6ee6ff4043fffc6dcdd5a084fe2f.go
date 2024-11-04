package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strings"
)

type State struct {
	x, y string
}

func (s State) Hash() int {
	return len(s.x) + len(s.y) // Simplified hash function
}

func (s State) Equals(other State) bool {
	return s.x == other.x && s.y == other.y
}

func runs(s string) []int {
	ret := []int{}
	run := 0
	for i := len(s) - 1; i >= 0; i-- {
		if i != len(s)-1 && s[i+1] != s[i] {
			ret = append(ret, run)
			run = 0
		}
		run++
	}
	ret = append(ret, run)
	return ret
}

func slow(s, t string) int {
	que := []State{{s, t}}
	dist := map[State]int{{s, t}: 0}

	for len(que) > 0 {
		st := que[0]
		que = que[1:]

		x, y := st.x, st.y
		curD := dist[st]

		if !strings.Contains(x, "a") || !strings.Contains(x, "b") && !strings.Contains(y, "a") || !strings.Contains(y, "b") {
			return dist[st]
		}

		for i := 0; i <= len(x); i++ {
			for j := 0; j <= len(y); j++ {
				x0, x1 := x[:i], x[i:]
				y0, y1 := y[:j], y[j:]

				nx := y0 + x1
				ny := x0 + y1

				nst := State{nx, ny}
				if _, exists := dist[nst]; !exists {
					dist[nst] = curD + 1
					que = append(que, nst)
				}
			}
		}
	}

	panic("unreachable")
}

func fast(s, t string) int {
	ret := []int{}
	rs := runs(s)
	rt := runs(t)
	areSame := s[0] == t[0]

	for areSame {
		p, q := len(rs), len(rt)
		x, y := -1, -1

		for xx := 0; xx <= 3 && xx <= p; xx++ {
			for yy := 0; yy <= 3 && yy <= q; yy++ {
				if xx+yy == 0 || x+y == xx+yy {
					continue
				}
				if xx%2 == yy%2 {
					continue
				}

				nx := p - xx + yy
				if xx != p && yy != 0 {
					nx--
				}

				ny := q - yy + xx
				if yy != q && xx != 0 {
					ny--
				}

				if nx == 0 || ny == 0 || nx+ny == p+q {
					continue
				}

				var val int
				if (xx == 0 || yy == 0) && (xx+yy)%2 == 1 {
					val = fastDiff(nx, ny) + 1
				} else {
					val = fastSame(nx, ny) + 1
				}

				if fastSame(p, q) == val {
					x = xx
					y = yy
					break
				}
			}
		}

		if (x == 0 || y == 0) && (x+y)%2 == 1 {
			areSame = false
		}

		delS, delT := make([]int, 0, x), make([]int, 0, y)
		ans1, ans2 := 0, 0

		for i := 0; i < x; i++ {
			delta := rs[len(rs)-1]
			ans1 += delta
			delS = append(delS, delta)
			rs = rs[:len(rs)-1]
		}

		for i := 0; i < y; i++ {
			delta := rt[len(rt)-1]
			ans2 += delta
			delT = append(delT, delta)
			rt = rt[:len(rt)-1]
		}

		ret = append(ret, ans1, ans2)

		for i := len(delS) - 1; i >= 0; i-- {
			if i == 0 && len(rt) > 0 {
				rt[len(rt)-1] += delS[i]
			} else {
				rt = append(rt, delS[i])
			}
		}

		for i := len(delT) - 1; i >= 0; i-- {
			if i == 0 && len(rs) > 0 {
				rs[len(rs)-1] += delT[i]
			} else {
				rs = append(rs, delT[i])
			}
		}
	}

	for len(rs) > 1 || len(rt) > 1 {
		p, q := len(rs), len(rt)
		x, y := -1, -1

		for tp := 1; tp <= 3 && tp <= p; tp += 2 {
			for tq := 1; tq <= 3 && tq <= q; tq += 2 {
				newP := p - tp + tq
				if tp != p {
					newP--
				}

				newQ := q - tq + tp
				if tq != q {
					newQ--
				}

				if newP == 0 || newQ == 0 || newP+newQ == p+q {
					continue
				}

				if fastDiff(p, q) == fastDiff(newP, newQ)+1 {
					x = tp
					y = tq
					break
				}
			}
		}

		delS, delT := make([]int, 0, x), make([]int, 0, y)
		ans1, ans2 := 0, 0

		for i := 0; i < x; i++ {
			delta := rs[len(rs)-1]
			ans1 += delta
			delS = append(delS, delta)
			rs = rs[:len(rs)-1]
		}

		for i := 0; i < y; i++ {
			delta := rt[len(rt)-1]
			ans2 += delta
			delT = append(delT, delta)
			rt = rt[:len(rt)-1]
		}

		ret = append(ret, ans1, ans2)

		for i := len(delS) - 1; i >= 0; i-- {
			if i == 0 && len(rt) > 0 {
				rt[len(rt)-1] += delS[i]
			} else {
				rt = append(rt, delS[i])
			}
		}

		for i := len(delT) - 1; i >= 0; i-- {
			if i == 0 && len(rs) > 0 {
				rs[len(rs)-1] += delT[i]
			} else {
				rs = append(rs, delT[i])
			}
		}
	}

	fmt.Println(len(ret) / 2)
	for i := 0; i < len(ret); i += 2 {
		fmt.Println(ret[i], ret[i+1])
	}
	return len(ret) / 2
}

func submit() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	scanner.Scan()
	t := scanner.Text()

	fast(s, t)
}

func fastSame(x, y int) int {
	ret := (x + y) / 2
	if (x+y)%4 == 1 && (x == 1 || y == 1) {
		ret++
	}
	return ret
}

func fastDiff(x, y int) int {
	if x == 1 && y == 1 {
		return 0
	}
	var ret int
	switch (x + y) % 4 {
	case 0:
		ret = (x + y) / 2
		if x%2 == 0 {
			ret--
		}
	case 1:
		ret = (x + y) / 2
		if x == 1 || y == 1 {
			ret++
		}
	case 2:
		ret = (x + y) / 2
		if x != 1 && x != 2 && y != 1 && y != 2 && x%2 == 1 {
			ret--
		}
	case 3:
		ret = (x + y) / 2
	}
	return ret
}

func main() {
	submit()
}

var rng = rand.New(rand.NewSource(0))
var C = 7

func randInt(l, r int) int {
	return l + rng.Intn(r-l+1)
}
