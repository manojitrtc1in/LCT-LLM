package main

import (
	"fmt"
	"sort"
)

var (
	t, la, ma, at int
	to            [1000005]int
	p             [1000005]int
	pp            [1000005]pair
	s             set
	m             [300]map[int]int
	x             [289][289]int
	xx            [289][299]byte
)

type pair struct {
	first  []int
	second int
}

type set map[vector]int

type vector []int

func go(aa vector, bb, cc int) {
	q := make([]pair, 0)
	q = append(q, pair{aa, pair{bb, cc}})
	s[aa] = true
	for len(q) > 0 {
		a := q[0].first
		b := q[0].second.first
		c := q[0].second.second
		q = q[1:]
		it := m[at][b]
		if it == 0 {
			m[at][b] = c
		} else {
			m[at][b] = min(it, c)
		}
		if c >= 10 {
			continue
		}
		c++
		for i := 0; i+1 < len(a); i++ {
			if a[i] != a[i+1] {
				a[i]--
				if _, ok := s[a]; !ok {
					s[a] = true
					q = append(q, pair{a, pair{b / (a[i] + 1) * a[i], c}})
				}
				a[i]++
			}
		}
		if len(a) > 0 {
			if a[len(a)-1] == 2 {
				a = a[:len(a)-1]
				if _, ok := s[a]; !ok {
					s[a] = true
					q = append(q, pair{a, pair{b / 2, c}})
				}
				a = append(a, 2)
			} else {
				a[len(a)-1]--
				if _, ok := s[a]; !ok {
					s[a] = true
					q = append(q, pair{a, pair{b / (a[len(a)-1] + 1) * a[len(a)-1], c}})
				}
				a[len(a)-1]++
			}
		}
		a = append(a, 2)
		if b*2 <= MAGIC {
			if _, ok := s[a]; !ok {
				s[a] = true
				q = append(q, pair{a, pair{b * 2, c}})
			}
		}
	}
	s = make(set)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	for i := 2; i < 1000005; i++ {
		if p[i] == 0 {
			p[i] = i
			if i <= 1000005/i {
				for j := i * i; j < 1000005; j += i {
					if p[j] == 0 {
						p[j] = i
					}
				}
			}
		}
	}

	for i := 1; i <= 1000000; i++ {
		pp[i].second = i
		la = -1
		ta = i
		for ta != 1 {
			if p[ta] == la {
				pp[i].first[len(pp[i].first)-1]++
			} else {
