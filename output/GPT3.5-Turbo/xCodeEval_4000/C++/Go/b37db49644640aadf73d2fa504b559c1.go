package main

import (
	"fmt"
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
	m := a[0]
	for i := 1; i < n; i++ {
		if a[i] > m {
			m = a[i]
		}
	}

	itrv := make([][3]float64, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&itrv[i][0])
		fmt.Scan(&itrv[i][1])
		fmt.Scan(&itrv[i][2])
		itrv[i][0]--
	}
	sort.Slice(itrv, func(i, j int) bool {
		return int(itrv[i][1]-itrv[i][0]) < int(itrv[j][1]-itrv[j][0])
	})
	itrv = append(itrv, [3]float64{0, float64(n), 0})

	cur := make(map[int][2]int)
	for _, v := range itrv {
		l, r, p := int(v[0]), int(v[1]), v[2]
		be := cur[l]
		en := cur[r]

		nv := make([]float64, q*2+1)
		pv := l
		for pv < en[0] {
			zer := 0
			for pv < en[0] && pv < len(a) {
				dif := a[pv] - m + q
				if dif > zer {
					zer = dif
				}
				pv++
			}
			for i := 0; i < zer; i++ {
				nv[i] = 0
			}
			tmp := en[1]
			for i := 0; i <= q*2; i++ {
				nv[i] *= tmp[i]
			}
		}

		zer := 0
		for pv < r && pv < len(a) {
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
			nx[i] += (1 - p) * nv[i]
		}
		for i := 0; i < q*2; i++ {
			nx[i+1] += p * nv[i]
		}
		cur[l] = [2]int{r, nx}
	}

	ans := m
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
		ans += (float64(i) - float64(q)) * (top[i] - sum)
		sum = top[i]
	}
	if top[q*2] < 1-1e-6 {
		panic("top[q*2] < 1-1e-6")
	}
	fmt.Println(ans)
}
