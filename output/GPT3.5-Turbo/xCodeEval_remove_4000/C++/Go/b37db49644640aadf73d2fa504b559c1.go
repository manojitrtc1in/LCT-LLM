package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n, q int
	fmt.Scan(&n)
	fmt.Scan(&q)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	m := -math.MaxInt64
	for i := 0; i < n; i++ {
		if a[i] > m {
			m = a[i]
		}
	}

	itrv := make([]struct {
		l, r int
		p    float64
	}, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&itrv[i].l)
		fmt.Scan(&itrv[i].r)
		fmt.Scan(&itrv[i].p)
		itrv[i].l--
	}
	sort.Slice(itrv, func(i, j int) bool {
		return itrv[i].r-itrv[i].l < itrv[j].r-itrv[j].l
	})
	itrv = append(itrv, struct {
		l, r int
		p    float64
	}{0, n, 0})

	cur := make(map[int]struct {
		first  int
		second []float64
	})

	for _, it := range itrv {
		be := cur[it.l:]
		en := cur[it.r:]

		nv := make([]float64, q*2+1)
		pv := it.l
		for _, c := range be {
			zer := 0
			for pv < c.first {
				dif := a[pv] - m + q
				if dif > zer {
					zer = dif
				}
				pv++
			}
			for i := 0; i < zer; i++ {
				nv[i] = 0
			}
			tmp := c.second
			for i := 0; i <= q*2; i++ {
				nv[i] *= tmp[i]
			}
		}

		zer := 0
		for pv < it.r {
			dif := a[pv] - m + q
			if dif > zer {
				zer = dif
			}
			pv++
		}
		for i := 0; i < zer; i++ {
			nv[i] = 0
		}

		nx := make([]float64, q*2+1)
		for i := 0; i <= q*2; i++ {
			nx[i] += (1 - it.p) * nv[i]
		}
		for i := 0; i < q*2; i++ {
			nx[i+1] += it.p * nv[i]
		}
		for k := range be {
			delete(cur, k)
		}
		cur[it.l] = struct {
			first  int
			second []float64
		}{it.r, nx}
	}

	ans := float64(m)
	sum := 0.0
	ren, top := cur[0]
	if ren != n {
		panic("ren != n")
	}
	for i := 0; i <= q*2; i++ {
		if i < q {
			if top[i] > 1e-6 {
				panic("top[i] > 1e-6")
			}
		}
		ans += float64(i-q) * (top[i] - sum)
		sum = top[i]
	}
	if top[q*2] < 1-1e-6 {
		panic("top[q*2] < 1-1e-6")
	}
	fmt.Println(ans)
}
