package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	first  int
	second int
}

type DSU struct {
	p  []int
	sz []int
}

func NewDSU(n int) *DSU {
	dsu := &DSU{
		p:  make([]int, n),
		sz: make([]int, n),
	}
	for i := 1; i < n; i++ {
		dsu.p[i] = i
		dsu.sz[i] = 1
	}
	return dsu
}

func (dsu *DSU) Find(u int) int {
	if dsu.p[u] == u {
		return u
	}
	dsu.p[u] = dsu.Find(dsu.p[u])
	return dsu.p[u]
}

func (dsu *DSU) Unite(u, v int) bool {
	pu := dsu.Find(u)
	pv := dsu.Find(v)
	if pu != pv {
		dsu.p[pu] = pv
		dsu.sz[pv] += dsu.sz[pu]
		return true
	}
	return false
}

func removeLeaf(s [][]int, deg [][]Pair, v int) {
	if len(s[v]) == 0 {
		deg[c[v]] = remove(deg[c[v]], Pair{0, v})
		return
	}
	u := s[v][0]
	deg[c[v]] = remove(deg[c[v]], Pair{len(s[v]), v})
	deg[c[u]] = remove(deg[c[u]], Pair{len(s[u]), u})
	s[u] = removeElement(s[u], v)
	s[v] = removeElement(s[v], u)
	deg[c[u]] = append(deg[c[u]], Pair{len(s[u]), u})
}

func id5(s [][]int, deg [][]Pair) {
	for {
		if len(deg[0]) == 0 {
			break
		}
		ret := deg[0][0]
		if ret.first > 1 {
			break
		}
		removeLeaf(s, deg, ret.second)
	}
}

func solve(s [][]int, deg [][]Pair, beg int) int {
	res := 0
	id5(s, deg)
	for {
		if len(deg[0]) == 0 && len(deg[1]) == 0 && len(deg[2]) == 0 {
			break
		}
		if len(deg[beg]) == 0 {
			beg = 3 - beg
			continue
		}
		res++
		for {
			if len(deg[beg]) == 0 {
				break
			}
			ret := deg[beg][0]
			if ret.first > 1 {
				break
			}
			removeLeaf(s, deg, ret.second)
			id5(s, deg)
		}
		beg = 3 - beg
	}
	return res
}

func remove(deg []Pair, p Pair) []Pair {
	for i, v := range deg {
		if v == p {
			return append(deg[:i], deg[i+1:]...)
		}
	}
	return deg
}

func removeElement(slice []int, elem int) []int {
	for i, v := range slice {
		if v == elem {
			return append(slice[:i], slice[i+1:]...)
		}
	}
	return slice
}

var c []int
var s [][]int
var st [][]int
var deg [][]Pair
var degt [][]Pair

func main() {
	var t, n int
	fmt.Scan(&t)
	c = make([]int, 200007)
	s = make([][]int, 200007)
	st = make([][]int, 200007)
	deg = make([][]Pair, 3)
	degt = make([][]Pair, 3)

	for i := 0; i < t; i++ {
		fmt.Scan(&n)
		for j := 1; j <= n; j++ {
			fmt.Scan(&c[j])
		}
		for j := 1; j < n; j++ {
			var u, v int
			fmt.Scan(&u, &v)
			s[u] = append(s[u], v)
			s[v] = append(s[v], u)
			st[u] = append(st[u], v)
			st[v] = append(st[v], u)
		}
		for j := 1; j <= n; j++ {
			deg[c[j]] = append(deg[c[j]], Pair{len(s[j]), j})
			degt[c[j]] = append(degt[c[j]], Pair{len(s[j]), j})
		}
		fmt.Println(max(min(solve(s, deg, 1), solve(st, degt, 2)), 1))
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
