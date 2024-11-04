package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func printInt(val int) {
	fmt.Fprint(writer, val)
}

func printString(val string) {
	fmt.Fprint(writer, val)
}

type Set struct {
	data map[int]bool
}

func NewSet() *Set {
	return &Set{
		data: make(map[int]bool),
	}
}

func (s *Set) Insert(val int) {
	s.data[val] = true
}

func (s *Set) Erase(val int) {
	delete(s.data, val)
}

func (s *Set) Contains(val int) bool {
	_, ok := s.data[val]
	return ok
}

func (s *Set) Size() int {
	return len(s.data)
}

type Pair struct {
	first  int
	second int
}

type PairList []Pair

func (p PairList) Len() int {
	return len(p)
}

func (p PairList) Less(i, j int) bool {
	return p[i].first < p[j].first
}

func (p PairList) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func removeLeaf(s []*Set, deg []*Set, v int) {
	if s[v].Size() == 0 {
		deg[c[v]].Erase(Pair{0, v})
		return
	}
	u := s[v].data[0]

	deg[c[v]].Erase(Pair{s[v].Size(), v})
	deg[c[u]].Erase(Pair{s[u].Size(), u})
	s[u].Erase(v)
	s[v].Erase(u)
	deg[c[u]].Insert(Pair{s[u].Size(), u})
}

func eraseGrey(s []*Set, deg []*Set) {
	for deg[0].Size() > 0 {
		ret := deg[0].data[0]
		if ret.first > 1 {
			break
		}
		removeLeaf(s, deg, ret.second)
	}
}

func solve(s []*Set, deg []*Set, beg int) int {
	res := 0
	eraseGrey(s, deg)
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
			ret := deg[beg].data[0]
			if ret.first > 1 {
				break
			}
			removeLeaf(s, deg, ret.second)
			eraseGrey(s, deg)
		}
		beg = 3 - beg
	}
	return res
}

func main() {
	initIO()
	defer flush()

	t := scanInt()
	for i := 0; i < t; i++ {
		n := scanInt()
		c := make([]int, n+1)
		for j := 1; j <= n; j++ {
			c[j] = scanInt()
		}
		s := make([]*Set, n+1)
		st := make([]*Set, n+1)
		deg := make([]*Set, 3)
		degt := make([]*Set, 3)
		for j := 0; j < 3; j++ {
			deg[j] = NewSet()
			degt[j] = NewSet()
		}
		for j := 1; j <= n; j++ {
			s[j] = NewSet()
			st[j] = NewSet()
		}
		for j := 1; j < n; j++ {
			u := scanInt()
			v := scanInt()
			s[u].Insert(v)
			s[v].Insert(u)
			st[u].Insert(v)
			st[v].Insert(u)
		}
		for j := 1; j <= n; j++ {
			deg[c[j]].Insert(Pair{s[j].Size(), j})
			degt[c[j]].Insert(Pair{st[j].Size(), j})
		}
		ans := max(min(solve(s, deg, 1), solve(st, degt, 2)), 1)
		printInt(ans)
		printString(" ")
	}
}
