package main

import (
	"fmt"
	"strings"
)

type pa struct {
	first  int
	second int
}

type SparsetableMin struct {
	vec [][]int
	lo  []int
}

type SAIS struct {
	STR  string
	S    []int
	SL   []int
	haba []pa
	SA   []int
	rank []int
	LCP  []int
	id3  int
	len  int
}

func makeSuffixArrayString(str string) SAIS {
	sais := SAIS{}
	sais.STR = str
	setc := make(map[byte]int)
	for i := 0; i < len(str); i++ {
		setc[str[i]] = 0
	}
	cnt := 1
	for c := range setc {
		setc[c] = cnt
		cnt++
	}
	for i := 0; i < len(str); i++ {
		sais.S = append(sais.S, setc[str[i]])
	}
	sais.id3 = cnt
	sais.S = append(sais.S, 0)
	sais.makeSuffixArrayNaibu()
	return sais
}

func (sais *SAIS) makeSuffixArrayNaibu() {
	cnt := sais.id3
	sais.len = len(sais.S)

	kosuu := make([]int, cnt)
	for _, c := range sais.S {
		kosuu[c]++
	}

	sais.haba = append(sais.haba, pa{0, 0})
	for i := 1; i < cnt; i++ {
		sais.haba = append(sais.haba, pa{sais.haba[i-1].second + 1, sais.haba[i-1].second + kosuu[i]})
	}

	sais.SL = make([]int, sais.len)
	for i := sais.len - 1; i >= 0; i-- {
		if i == sais.len-1 {
			sais.SL[i] = 1
		} else {
			if sais.S[i] < sais.S[i+1] {
				sais.SL[i] = 1
			} else if sais.S[i] > sais.S[i+1] {
				sais.SL[i] = 0
			} else {
				sais.SL[i] = sais.SL[i+1]
			}
		}
	}

	id7 := 0
	LMS := []int{}
	id6 := make([]int, sais.len)
	rt := 0
	for i := 1; i < sais.len; i++ {
		if sais.SL[i-1] == 0 && sais.SL[i] == 1 {
			LMS = append(LMS, i)
			id6[i] = rt
			id7++
			rt++
		}
	}
	for i := 0; i < id7-1; i++ {
		sais.SL[LMS[i]] = -(LMS[i+1] - LMS[i] + 1)
	}
	sais.SL[sais.len-1] = -1

	sais.SA = make([]int, sais.len)
	pos := make([]int, cnt)
	for c := 0; c < sais.len; c++ {
		if sais.SL[c] < 0 {
			sais.SA[sais.haba[sais.S[c]].second-pos[sais.S[c]]] = c
			pos[sais.S[c]]++
		}
	}

	sais.inducedSort(sais.SA, sais.len, cnt)

	ind1 := []pa{}
	ind2 := 0
	for i := 0; i < sais.len; i++ {
		if sais.SL[sais.SA[i]] < 0 {
			if i == 0 {
				ind1 = append(ind1, pa{sais.SA[i], 1})
			} else if ind1[len(ind1)-1].second == 1 {
				ind1 = append(ind1, pa{sais.SA[i], 2})
			} else if sais.SL[sais.SA[ind2]] != sais.SL[sais.SA[i]] {
				ind1 = append(ind1, pa{sais.SA[i], ind1[len(ind1)-1].second + 1})
			} else {
				id5 := -sais.SL[sais.SA[ind2]]
				bo := true
				for j := 0; j < id5; j++ {
					if sais.S[sais.SA[ind2]+j] != sais.S[sais.SA[i]+j] {
						bo = false
						break
					}
				}
				if bo {
					ind1 = append(ind1, pa{sais.SA[i], ind1[len(ind1)-1].second})
				} else {
					ind1 = append(ind1, pa{sais.SA[i], ind1[len(ind1)-1].second + 1})
				}
			}
			ind2 = i
		}
	}

	for i := 0; i < cnt; i++ {
		pos[i] = 0
	}
	for i := 0; i < sais.len; i++ {
		sais.SA[i] = -1
	}

	if id7 == ind1[len(ind1)-1].second {
		for i := id7 - 1; i >= 0; i-- {
			c := ind1[i].first
			sais.SA[sais.haba[sais.S[c]].second-pos[sais.S[c]]] = c
			pos[sais.S[c]]++
		}
	} else {
		rec := make([]int, len(LMS))
		for i := 0; i < id7; i++ {
			rec[id6[ind1[i].first]] = ind1[i].second
		}
		id4 := makeSuffixArraySaiki(rec, ind1[len(ind1)-1].second)

		for i := id7; i > 0; i-- {
			c := LMS[id4.SA[i]]
			sais.SA[sais.haba[sais.S[c]].second-pos[sais.S[c]]] = c
			pos[sais.S[c]]++
		}
	}

	sais.inducedSort(sais.SA, sais.len, cnt)
	sais.rank = make([]int, sais.len)
	for i := 0; i < sais.len; i++ {
		sais.rank[sais.SA[i]] = i
	}
	return
}

func (sais *SAIS) inducedSort(ve []int, len int, cnt int) {
	ue := make([]int, cnt)
	for i := 0; i < len; i++ {
		if ve[i] == -1 {
			continue
		}
		if ve[i] == 0 {
			continue
		}
		if sais.SL[ve[i]-1] == 0 {
			ve[sais.haba[sais.S[ve[i]-1]].first+ue[sais.S[ve[i]-1]]] = ve[i] - 1
			ue[sais.S[ve[i]-1]]++
		}
		if sais.SL[ve[i]] < 0 && i > 0 {
			ve[i] = -1
		}
	}
	for i := 0; i < cnt; i++ {
		ue[i] = 0
	}

	for i := len - 1; i >= 0; i-- {
		if ve[i] == -1 {
			continue
		}
		if ve[i] == 0 {
			continue
		}
		if sais.SL[ve[i]-1] != 0 {
			ve[sais.haba[sais.S[ve[i]-1]].second-ue[sais.S[ve[i]-1]]] = ve[i] - 1
			ue[sais.S[ve[i]-1]]++
		}
	}
	for _, v := range ve {
		if v == -1 {
			panic("v == -1")
		}
	}
}

func (sais *SAIS) makeLCP() {
	sais.LCP = make([]int, sais.len)
	h := 0
	sais.LCP[0] = 0
	for i := 0; i < sais.len-1; i++ {
		j := sais.SA[sais.rank[i]-1]
		if h > 0 {
			h--
		}
		for ; j+h < sais.len-1 && i+h < sais.len-1; h++ {
			if sais.S[j+h] != sais.S[i+h] {
				break
			}
		}
		sais.LCP[sais.rank[i]-1] = h
	}
	return
}

func (sais *SAIS) lowerBound(p string) int {
	m := len(p)
	ue := sais.len
	si := 0
	var me int
	for ue-si > 1 {
		me = (ue + si) / 2
		if strings.Compare(sais.STR[sais.SA[me]:], p) < 0 {
			si = me
		} else {
			ue = me
		}
	}
	return ue
}

func (sais *SAIS) exist(p string) bool {
	l := len(p)
	id := sais.lowerBound(p)
	return strings.Compare(sais.STR[sais.SA[id]:], p) == 0
}

func (sais *SAIS) range(p string) pa {
	return pa{sais.lowerBound(p), sais.lowerBound(p + "{")}
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
	ss := makeSuffixArrayString(t)
	ss.makeLCP()
	sm := SparsetableMin{}
	sm.shoki1()
	for i := 0; i < len(ss.LCP); i++ {
		sm.vec[0][i] = ss.LCP[i]
	}
	sm.shoki2()
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
			if sm.rangemin(e1, e2) >= ve[r1]-ve[l1] {
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
			if sm.rangemin(e1, e2) >= ve[r1]-ve[l1] {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}
}
