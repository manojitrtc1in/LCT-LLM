package main

import (
	"fmt"
	"math"
	"strings"
)

const inf = 1000000007
const PI = 3.14159265358979323846
const EPS = 1e-8

type pa struct {
	first, second int
}

type pa2 struct {
	x, y int
}

func (p pa2) add(other pa2) pa2 {
	return pa2{p.x + other.x, p.y + other.y}
}

func (p pa2) sub(other pa2) pa2 {
	return pa2{p.x - other.x, p.y - other.y}
}

func (p pa2) less(other pa2) bool {
	if p.y != other.y {
		return p.y < other.y
	}
	return p.x < other.x
}

func (p pa2) greater(other pa2) bool {
	if p.x != other.x {
		return p.x > other.x
	}
	return p.y > other.y
}

func (p pa2) equal(other pa2) bool {
	return p.x == other.x && p.y == other.y
}

func (p pa2) notEqual(other pa2) bool {
	return !p.equal(other)
}

func itos(i int) string {
	return fmt.Sprintf("%d", i)
}

func gcd(v, b int) int {
	if v == 0 {
		return b
	}
	if b == 0 {
		return v
	}
	if v > b {
		return gcd(b, v)
	}
	if v == b {
		return b
	}
	if b%v == 0 {
		return v
	}
	return gcd(v, b%v)
}

type SparsetableMin struct {
	beki int
	cor  int
	vec  [][]int
	lo   []int
}

func (sm *SparsetableMin) init() {
	sm.beki = 19
	sm.cor = 1 << sm.beki
	sm.vec = make([][]int, sm.beki+1)
	for i := range sm.vec {
		sm.vec[i] = make([]int, sm.cor)
	}
	sm.lo = make([]int, sm.cor+1)
	sm.lo[0] = -1
	for i := 1; i <= sm.cor; i++ {
		sm.lo[i] = sm.lo[i>>1] + 1
	}
}

func (sm *SparsetableMin) build() {
	for i := 1; i <= sm.beki; i++ {
		for j := 0; j < sm.cor; j++ {
			if j+(1<<(i-1)) < sm.cor {
				sm.vec[i][j] = int(math.Min(float64(sm.vec[i-1][j]), float64(sm.vec[i-1][j+(1<<(i-1))])))
			} else {
				sm.vec[i][j] = sm.vec[i-1][j]
			}
		}
	}
}

func (sm *SparsetableMin) rangeMin(i, j int) int {
	haba := sm.lo[j-i]
	return int(math.Min(float64(sm.vec[haba][i]), float64(sm.vec[haba][j-(1<<haba)])))
}

type SAIS struct {
	STR   string
	S     []int
	SL    []int
	haba  []pa
	SA    []int
	rank  []int
	LCP   []int
	mojisu int
	len   int
}

func (s *SAIS) makeSuffixArrayString(str string) {
	s.STR = str
	setc := make(map[rune]struct{})
	mapc := make(map[rune]int)
	for _, c := range str {
		setc[c] = struct{}{}
	}
	cnt := 1
	for c := range setc {
		mapc[c] = cnt
		cnt++
	}
	for _, c := range str {
		s.S = append(s.S, mapc[c])
	}
	s.mojisu = cnt
	s.S = append(s.S, 0)
	s.makeSuffixArrayNaibu()
}

func (s *SAIS) makeSuffixArrayNaibu() {
	cnt := s.mojisu
	s.len = len(s.S)

	kosuu := make([]int, cnt)
	for _, c := range s.S {
		kosuu[c]++
	}

	s.haba = append(s.haba, pa{0, 0})
	for i := 1; i < cnt; i++ {
		s.haba = append(s.haba, pa{s.haba[len(s.haba)-1].second + 1, s.haba[len(s.haba)-1].second + kosuu[i]})
	}

	s.SL = make([]int, s.len)
	for i := s.len - 1; i >= 0; i-- {
		if i == s.len-1 {
			s.SL[i] = 1
		} else {
			if s.S[i] < s.S[i+1] {
				s.SL[i] = 1
			} else if s.S[i] > s.S[i+1] {
				s.SL[i] = 0
			} else {
				s.SL[i] = s.SL[i+1]
			}
		}
	}

	LMS := []int{}
	LMS_id := make([]int, s.len)
	rt := 0
	for i := 1; i < s.len; i++ {
		if s.SL[i-1] == 0 && s.SL[i] == 1 {
			LMS = append(LMS, i)
			LMS_id[i] = rt
			rt++
		}
	}
	for i := 0; i < len(LMS)-1; i++ {
		s.SL[LMS[i]] = -(LMS[i+1] - LMS[i] + 1)
	}
	s.SL[s.len-1] = -1

	for i := 0; i < s.len; i++ {
		s.SA = append(s.SA, -1)
	}
	pos := make([]int, cnt)
	for _, v := range s.S {
		if s.SL[v] < 0 {
			s.SA[s.haba[s.S[v]].second-pos[s.S[v]]] = v
			pos[s.S[v]]++
		}
	}

	s.inducedSort(s.SA, s.len, cnt)

	lmsSubOrder := []pa{}
	var maeInd int
	for i := 0; i < s.len; i++ {
		if s.SL[s.SA[i]] < 0 {
			if i == 0 {
				lmsSubOrder = append(lmsSubOrder, pa{s.SA[i], 1})
			} else if lmsSubOrder[len(lmsSubOrder)-1].second == 1 {
				lmsSubOrder = append(lmsSubOrder, pa{s.SA[i], 2})
			} else if s.SL[s.SA[maeInd]] != s.SL[s.SA[i]] {
				lmsSubOrder = append(lmsSubOrder, pa{s.SA[i], lmsSubOrder[len(lmsSubOrder)-1].second + 1})
			} else {
				lmslen := -s.SL[s.SA[maeInd]]
				bo := true
				for j := 0; j < lmslen; j++ {
					if s.S[s.SA[maeInd]+j] != s.S[s.SA[i]+j] {
						bo = false
						break
					}
				}
				if bo {
					lmsSubOrder = append(lmsSubOrder, pa{s.SA[i], lmsSubOrder[len(lmsSubOrder)-1].second})
				} else {
					lmsSubOrder = append(lmsSubOrder, pa{s.SA[i], lmsSubOrder[len(lmsSubOrder)-1].second + 1})
				}
			}
			maeInd = i
		}
	}

	for i := 0; i < cnt; i++ {
		pos[i] = 0
	}
	for i := 0; i < s.len; i++ {
		s.SA[i] = -1
	}

	if len(LMS) == lmsSubOrder[len(lmsSubOrder)-1].second {
		for i := len(LMS) - 1; i >= 0; i-- {
			c := LMS[i]
			s.SA[s.haba[s.S[c]].second-pos[s.S[c]]] = c
			pos[s.S[c]]++
		}
	} else {
		rec := make([]int, len(LMS))
		for i := 0; i < len(LMS); i++ {
			rec[LMS_id[lmsSubOrder[i].first]] = lmsSubOrder[i].second
		}
		ssNaibu := SAIS{}
		ssNaibu.makeSuffixArraySaiki(rec, lmsSubOrder[len(lmsSubOrder)-1].second)

		for i := len(LMS); i > 0; i-- {
			c := LMS[ssNaibu.SA[i]]
			s.SA[s.haba[s.S[c]].second-pos[s.S[c]]] = c
			pos[s.S[c]]++
		}
	}

	s.inducedSort(s.SA, s.len, cnt)
	s.rank = make([]int, s.len)
	for i := 0; i < s.len; i++ {
		s.rank[s.SA[i]] = i
	}
}

func (s *SAIS) inducedSort(ve []int, length, cnt int) {
	ue := make([]int, cnt)
	for i := 0; i < length; i++ {
		if ve[i] == -1 {
			continue
		}
		if ve[i] == 0 {
			continue
		}
		if s.SL[ve[i]-1] == 0 {
			ve[s.haba[s.S[ve[i]-1]].first+ue[s.S[ve[i]-1]]] = ve[i] - 1
			ue[s.S[ve[i]-1]]++
		}
		if s.SL[ve[i]] < 0 && i > 0 {
			ve[i] = -1
		}
	}
	for i := 0; i < cnt; i++ {
		ue[i] = 0
	}

	for i := length - 1; i >= 0; i-- {
		if ve[i] == -1 {
			continue
		}
		if ve[i] == 0 {
			continue
		}
		if s.SL[ve[i]-1] != 0 {
			ve[s.haba[s.S[ve[i]-1]].second-ue[s.S[ve[i]-1]]] = ve[i] - 1
			ue[s.S[ve[i]-1]]++
		}
	}
	for _, v := range ve {
		if v == -1 {
			panic("Invalid value")
		}
	}
}

func (s *SAIS) makeLCP() {
	s.S = nil
	s.SL = nil
	s.haba = nil

	s.LCP = make([]int, s.len)
	h := 0
	s.LCP[0] = 0
	for i := 0; i < s.len-1; i++ {
		j := s.SA[s.rank[i]-1]
		if h > 0 {
			h--
		}
		for j+h < s.len-1 && i+h < s.len-1 && s.S[j+h] == s.S[i+h] {
			h++
		}
		s.LCP[s.rank[i]-1] = h
	}
}

func (s *SAIS) lowerBound(p string) int {
	m := len(p)
	ue, si := s.len, 0
	var me int
	for ue-si > 1 {
		me = (ue + si) / 2
		if s.STR[s.SA[me]:s.SA[me]+m] < p {
			si = me
		} else {
			ue = me
		}
	}
	return ue
}

func (s *SAIS) exist(p string) bool {
	l := len(p)
	id := s.lowerBound(p)
	return s.STR[s.SA[id]:s.SA[id]+l] == p
}

func (s *SAIS) rangeQuery(p string) pa {
	return pa{s.lowerBound(p), s.lowerBound(p + "{")}
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	ve := make([]int, n)
	cnt := 0
	t := ""
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			ve[i] = cnt
		} else {
			ve[i] = cnt
			cnt++
			if i%2 == 1 {
				t += "b"
			} else {
				t += "a"
			}
		}
	}
	m := len(t)
	if m == 0 {
		var e int
		fmt.Scan(&e)
		for i := 0; i < e; i++ {
			fmt.Println("Yes")
		}
		return
	}
	for i := 0; i < m; i++ {
		t += string('a' ^ 'b' ^ t[i])
	}

	ve = append(ve, cnt)
	ss := SAIS{}
	ss.makeSuffixArrayString(t)
	ss.makeLCP()
	sm := SparsetableMin{}
	sm.init()
	for i := 0; i < len(ss.LCP); i++ {
		sm.vec[0][i] = ss.LCP[i]
	}
	sm.build()
	var q int
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		var l1, l2, p int
		fmt.Scan(&l1, &l2, &p)
		l1--
		l2--
		r1 := l1 + p
		r2 := l2 + p
		if ve[r1]-ve[l1] != ve[r2]-ve[l2] {
			fmt.Println("No")
			continue
		}
		if l1%2 == l2%2 {
			if ve[r1] == ve[l1] || ve[r1] == ve[r2] {
				fmt.Println("Yes")
				continue
			}
			e1 := ss.rank[ve[l1]]
			e2 := ss.rank[ve[l2]]
			if e1 > e2 {
				e1, e2 = e2, e1
			}
			if sm.rangeMin(e1, e2) >= ve[r1]-ve[l1] {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		} else {
			if ve[r1] == ve[l1] {
				fmt.Println("Yes")
				continue
			}
			if ve[r1] == ve[r2] {
				fmt.Println("No")
				continue
			}

			e1 := ss.rank[ve[l1]]
			e2 := ss.rank[ve[l2]+m]
			if e1 > e2 {
				e1, e2 = e2, e1
			}

			if sm.rangeMin(e1, e2) >= ve[r1]-ve[l1] {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}
}
