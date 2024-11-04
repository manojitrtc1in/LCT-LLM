package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type State struct {
	x, y string
}

func (s State) hashCode() int {
	prime := 31
	result := 1
	if s.x != "" {
		result = prime*result + hashCode(s.x)
	}
	if s.y != "" {
		result = prime*result + hashCode(s.y)
	}
	return result
}

func (s State) equals(obj State) bool {
	if s == obj {
		return true
	}
	if obj == nil {
		return false
	}
	if s.getClass() != obj.getClass() {
		return false
	}
	other := obj.(State)
	if s.x == nil {
		if other.x != nil {
			return false
		}
	} else if s.x != other.x {
		return false
	}
	if s.y == nil {
		if other.y != nil {
			return false
		}
	} else if s.y != other.y {
		return false
	}
	return true
}

func runs(s string) []int {
	ret := make([]int, 0)
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
	que := make([]State, 0)
	que = append(que, State{s, t})
	dist := make(map[State]int)
	dist[State{s, t}] = 0

	for len(que) > 0 {
		st := que[0]
		que = que[1:]

		x := st.x
		y := st.y

		curD := dist[st]

		if (strings.Index(x, "a") == -1 || strings.Index(x, "b") == -1) && (strings.Index(y, "a") == -1 || strings.Index(y, "b") == -1) {
			return dist[st]
		}

		for i := 0; i <= len(x); i++ {
			for j := 0; j <= len(y); j++ {
				x0 := x[0:i]
				x1 := x[i:]

				y0 := y[0:j]
				y1 := y[j:]

				nx := y0 + x1
				ny := x0 + y1

				nst := State{nx, ny}
				if _, ok := dist[nst]; !ok {
					dist[nst] = curD + 1
					que = append(que, nst)
				}
			}
		}
	}

	panic("AssertionError")
}

func fast(s, t string) int {
	ret := make([]int, 0)

	rs := runs(s)
	rt := runs(t)
	areSame := s[0] == t[0]

	for areSame {
		p := len(rs)
		q := len(rt)

		x := -1
		y := -1

	shiiit:
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

				if nx == 0 || ny == 0 {
					continue
				}

				if nx+ny == p+q {
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
					break shiiit
				}
			}
		}

		if (x == 0 || y == 0) && (x+y)%2 == 1 {
			areSame = false
		}

		delS := make([]int, x)
		delT := make([]int, y)

		ans1 := 0
		ans2 := 0

		for i := 0; i < x; i++ {
			delta := rs[len(rs)-1]
			rs = rs[:len(rs)-1]
			ans1 += delta
			delS[i] = delta
		}

		for i := 0; i < y; i++ {
			delta := rt[len(rt)-1]
			rt = rt[:len(rt)-1]
			ans2 += delta
			delT[i] = delta
		}

		ret = append(ret, ans1)
		ret = append(ret, ans2)

		reverse(delS)
		reverse(delT)

		for i := 0; i < x; i++ {
			if i == 0 && len(rt) > 0 {
				rt[len(rt)-1] += delS[i]
			} else {
				rt = append(rt, delS[i])
			}
		}

		for i := 0; i < y; i++ {
			if i == 0 && len(rs) > 0 {
				rs[len(rs)-1] += delT[i]
			} else {
				rs = append(rs, delT[i])
			}
		}
	}

	for len(rs) > 1 || len(rt) > 1 {
		p := len(rs)
		q := len(rt)

		x := -1
		y := -1

	shiiit:
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

				if newP == 0 || newQ == 0 {
					continue
				}

				if newP+newQ == p+q {
					continue
				}

				if fastDiff(p, q) == fastDiff(newP, newQ)+1 {
					x = tp
					y = tq
					break shiiit
				}
			}
		}

		delS := make([]int, x)
		delT := make([]int, y)

		ans1 := 0
		ans2 := 0

		for i := 0; i < x; i++ {
			delta := rs[len(rs)-1]
			rs = rs[:len(rs)-1]
			ans1 += delta
			delS[i] = delta
		}

		for i := 0; i < y; i++ {
			delta := rt[len(rt)-1]
			rt = rt[:len(rt)-1]
			ans2 += delta
			delT[i] = delta
		}

		ret = append(ret, ans1)
		ret = append(ret, ans2)

		reverse(delS)
		reverse(delT)

		for i := 0; i < x; i++ {
			if i == 0 && len(rt) > 0 {
				rt[len(rt)-1] += delS[i]
			} else {
				rt = append(rt, delS[i])
			}
		}

		for i := 0; i < y; i++ {
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
	if (x+y)%4 == 0 {
		ret = (x + y) / 2
		if x%2 == 0 {
			ret--
		}
	} else if (x+y)%4 == 1 {
		ret = (x + y) / 2
		if x == 1 || y == 1 {
			ret++
		}
	} else if (x+y)%4 == 2 {
		ret = (x + y) / 2
		if x != 1 && x != 2 && y != 1 && y != 2 && x%2 == 1 {
			ret--
		}
	} else if (x+y)%4 == 3 {
		ret = (x + y) / 2
	} else {
		panic("AssertionError")
	}
	return ret
}

func reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	s := scanString(scanner)
	t := scanString(scanner)

	fast(s, t)
}

func scanString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func scanInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanFloat64(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}
