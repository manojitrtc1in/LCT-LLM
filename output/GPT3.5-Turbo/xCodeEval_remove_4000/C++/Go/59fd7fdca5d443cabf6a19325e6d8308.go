package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second int
}

type Set struct {
	data []int
}

func NewSet() *Set {
	return &Set{
		data: make([]int, 0),
	}
}

func (s *Set) Insert(x int) {
	s.data = append(s.data, x)
	sort.Ints(s.data)
}

func (s *Set) Erase(x int) {
	idx := sort.SearchInts(s.data, x)
	if idx < len(s.data) && s.data[idx] == x {
		s.data = append(s.data[:idx], s.data[idx+1:]...)
	}
}

func (s *Set) Size() int {
	return len(s.data)
}

func (s *Set) Begin() int {
	if len(s.data) > 0 {
		return s.data[0]
	}
	return -1
}

func (s *Set) End() int {
	if len(s.data) > 0 {
		return s.data[len(s.data)-1]
	}
	return -1
}

func RemoveLeaf(s []*Set, deg []*Set, v int) {
	if s[v].Size() == 0 {
		deg[c[v]].Erase(Pair{0, v})
		return
	}
	u := s[v].Begin()
	deg[c[v]].Erase(Pair{s[v].Size(), v})
	deg[c[u]].Erase(Pair{s[u].Size(), u})
	s[u].Erase(v)
	s[v].Erase(u)
	deg[c[u]].Insert(Pair{s[u].Size(), u})
}

func Solve(s []*Set, deg []*Set, beg int) int {
	res := 0
	for {
		if deg[0].Size() == 0 && deg[1].Size() == 0 && deg[2].Size() == 0 {
			break
		}
		if deg[beg].Size() == 0 {
			beg = 3 - beg
			continue
		}
		res++
		for {
			if deg[beg].Size() == 0 {
				break
			}
			ret := deg[beg].Begin()
			if ret.first > 1 {
				break
			}
			RemoveLeaf(s, deg, ret.second)
		}
		beg = 3 - beg
	}
	return res
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Scan(&n)
		c := make([]int, n+1)
		for j := 1; j <= n; j++ {
			fmt.Scan(&c[j])
		}
		s := make([]*Set, n+1)
		st := make([]*Set, n+1)
		for j := 1; j <= n; j++ {
			s[j] = NewSet()
			st[j] = NewSet()
		}
		deg := make([]*Set, 3)
		degt := make([]*Set, 3)
		for j := 0; j < 3; j++ {
			deg[j] = NewSet()
			degt[j] = NewSet()
		}
		for j := 1; j < n; j++ {
			var u, v int
			fmt.Scan(&u, &v)
			s[u].Insert(v)
			s[v].Insert(u)
			st[u].Insert(v)
			st[v].Insert(u)
		}
		for j := 1; j <= n; j++ {
			deg[c[j]].Insert(Pair{s[j].Size(), j})
			degt[c[j]].Insert(Pair{s[j].Size(), j})
		}
		fmt.Print(max(min(Solve(s, deg, 1), Solve(st, degt, 2)), 1))
		if i < t-1 {
			fmt.Print(" ")
		}
	}
}
