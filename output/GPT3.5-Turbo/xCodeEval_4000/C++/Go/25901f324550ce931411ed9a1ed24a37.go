package main

import (
	"fmt"
	"strings"
)

type pa struct {
	first  int
	second int
}

type Sparsetable_min struct {
	beki int
	cor  int
	vec  [][]int
	lo   []int
}

type SAIS struct {
	STR  string
	S    []int
	SL   []int
	haba []pa
	SA   []int
	rank []int
	LCP  []int
	mojisu int
	len int
}

func make_suffix_array_string(str string) []int {
	STR := str
	setc := make(map[byte]int)
	for i := 0; i < len(str); i++ {
		setc[str[i]] = 1
	}
	cnt := 1
	mapc := make(map[byte]int)
	for c := range setc {
		mapc[c] = cnt
		cnt++
	}
	S := make([]int, len(str)+1)
	for i := 0; i < len(str); i++ {
		S[i] = mapc[str[i]]
	}
	mojisu := cnt
	S[len(str)] = 0
	return make_suffix_array_naibu(S, mojisu)
}

func make_suffix_array_saiki(ve []int, max_valu int) []int {
	S := ve
	S = append(S, 0)
	mojisu := max_valu + 1
	return make_suffix_array_naibu(S, mojisu)
}

func make_suffix_array_naibu(S []int, mojisu int) []int {
	cnt := mojisu
	len := len(S)

	kosuu := make([]int, cnt)
	for i := 0; i < len; i++ {
		kosuu[S[i]]++
	}

	haba := make([]pa, 0)
	haba = append(haba, pa{0, 0})
	for i := 1; i < cnt; i++ {
		haba = append(haba, pa{haba[len(haba)-1].second + 1, haba[len(haba)-1].second + kosuu[i]})
	}

	SL := make([]int, len)
	for i := len - 1; i >= 0; i-- {
		if i == len-1 {
			SL[i] = 1
		} else {
			if S[i] < S[i+1] {
				SL[i] = 1
			} else if S[i] > S[i+1] {
				SL[i] = 0
			} else {
				SL[i] = SL[i+1]
			}
		}
	}

	LMS_num := 0
	LMS := make([]int, 0)
	LMS_id := make([]int, len)
	rt := 0
	for i := 1; i < len; i++ {
		if SL[i-1] == 0 && SL[i] == 1 {
			LMS = append(LMS, i)
			LMS_id[i] = rt
			LMS_num++
			rt++
		}
	}
	for i := 0; i < LMS_num-1; i++ {
		SL[LMS[i]] = -(LMS[i+1] - LMS[i] + 1)
	}
	SL[len-1] = -1

	SA := make([]int, len)
	pos := make([]int, cnt)
	for c := 0; c < len; c++ {
		if SL[c] < 0 {
			SA[haba[S[c]].second-pos[S[c]]] = c
			pos[S[c]]++
		}
	}

	induced_sort(SA, len, cnt)

	induced_sort(SA, len, cnt)

	rank := make([]int, len)
	for i := 0; i < len; i++ {
		rank[SA[i]] = i
	}
	return SA
}

func induced_sort(ve []int, len int, cnt int) {
	ue := make([]int, cnt)
	for i := 0; i < len; i++ {
		if ve[i] == -1 {
			continue
		}
		if ve[i] == 0 {
			continue
		}
		if SL[ve[i]-1] == 0 {
			ve[haba[S[ve[i]-1]].first+ue[S[ve[i]-1]]] = ve[i] - 1
			ue[S[ve[i]-1]]++
		}
		if SL[ve[i]] < 0 && i > 0 {
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
		if SL[ve[i]-1] != 0 {
			ve[haba[S[ve[i]-1]].second-ue[S[ve[i]-1]]] = ve[i] - 1
			ue[S[ve[i]-1]]++
		}
	}
	for _, v := range ve {
		if v == -1 {
			fmt.Println("Error")
		}
	}
}

func make_lcp() {
	LCP = make([]int, len)
	h := 0
	LCP[0] = 0
	for i := 0; i < len-1; i++ {
		j := SA[rank[i]-1]
		if h > 0 {
			h--
		}
		for j+h < len-1 && i+h < len-1 {
			if S[j+h] != S[i+h] {
				break
			}
			h++
		}
		LCP[rank[i]-1] = h
	}
}

func lower_bound(p string) int {
	m := len(p)
	ue := len, si := 0, me := 0
	for ue-si > 1 {
		me = (ue + si) / 2
		if strings.Compare(STR[SA[me]:SA[me]+m], p) < 0 {
			si = me
		} else {
			ue = me
		}
	}
	return ue
}

func exist(p string) bool {
	l := len(p)
	id := lower_bound(p)
	return strings.Compare(STR[SA[id]:SA[id]+l], p) == 0
}

func range(p string) pa {
	return pa{lower_bound(p), lower_bound(p + "{")}
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
		t += string('a'^'b'^t[i])
	}

	ve = append(ve, cnt)
	ss := SAIS{}
	ss.make_suffix_array_string(t)
	ss.make_lcp()
	sm := Sparsetable_min{}
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
