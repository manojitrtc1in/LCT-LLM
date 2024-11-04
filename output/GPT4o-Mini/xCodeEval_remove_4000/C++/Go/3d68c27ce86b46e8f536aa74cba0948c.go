package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	INPUT_FILE  = "input.txt"
	OUTPUT_FILE = "output.txt"
)

type popu struct {
	v []int
	q map[int]int
	p int
	z int
}

func (p *popu) add(t int) {
	p.q[t] = p.v[t]
}

func (p *popu) remove(t int) {
	delete(p.q, t)
}

func newPopu(n, p int) *popu {
	v := make([]int, n)
	q := make(map[int]int)
	for i := 0; i < n; i++ {
		if i != p {
			q[i] = v[i]
		}
	}
	return &popu{v: v, q: q, p: p, z: 0}
}

func (p *popu) maxEl() int {
	maxIndex := -1
	maxValue := math.MinInt
	for k, v := range p.q {
		if v > maxValue {
			maxValue = v
			maxIndex = k
		}
	}
	return maxIndex
}

func (p *popu) isPopu() bool {
	return p.v[p.maxEl()] >= p.z
}

func (p *popu) change(t, val int) {
	if t == p.p {
		p.z += val
	} else {
		p.remove(t)
		p.v[t] += val
		p.add(t)
	}
}

func anotherMain() int {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println("0")
		return 0
	} else {
		v := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&v[i])
			v[i]-- // Decrement to match 0-based index
		}

		q := make([]int, n)
		mx := [2]int{0, 0} // [count, index]
		for i := 0; i < n; i++ {
			q[v[i]]++
			if q[v[i]] > mx[0] {
				mx = [2]int{q[v[i]], v[i]}
			}
		}

		p := mx[1]
		u := make([][]int, n+1)
		for i := 0; i < n; i++ {
			if i != p {
				u[q[i]] = append(u[q[i]], i)
			}
		}

		uu := []int{}
		for i := n; i >= 0; i-- {
			if len(u[i]) > 0 {
				uu = append(uu, i)
			}
		}

		last := 0
		leftmost := make([][]int, n)
		for i := 0; i < n; i++ {
			leftmost[i] = make([]int, q[i]+1)
			for j := range leftmost[i] {
				leftmost[i][j] = n + 1
			}
			leftmost[i][0] = 0
		}

		ans := 0
		for i := 0; i < n; i++ {
			if v[i] != p {
				q[v[i]]++
			}
		}

		for y := 0; y < int(math.Min(float64(n), 100.0)); y++ {
			if y != p {
				g := make([]int, n+1)
				b := 0
				for i := 0; i < n; i++ {
					if v[i] == p {
						ans = int(math.Max(float64(ans), float64(i-g[len(g)-b-1]-1)))
						if b > 0 {
							b--
						} else {
							g = append(g, i)
						}
					} else if v[i] == y {
						b++
					}
				}
				ans = int(math.Max(float64(ans), float64(n-g[len(g)-b-1]-1)))
			}
		}

		fmt.Println(ans)
	}
	return 0
}

func main() {
	AMR := anotherMain()
	fmt.Println("Result:", AMR)
}
