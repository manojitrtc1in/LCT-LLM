package main

import (
	"bufio"
	"fmt"
	"math"
	"sort"
)

type Query struct {
	l, r int
	p    float64
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1<<20)
	writer := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer writer.Flush()

	var n, q int
	fmt.Fscan(reader, &n, &q)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	m := 0
	for _, val := range a {
		if val > m {
			m = val
		}
	}

	itrv := make([]Query, q)
	for i := 0; i < q; i++ {
		fmt.Fscan(reader, &itrv[i].l, &itrv[i].r, &itrv[i].p)
		itrv[i].l-- // Convert to 0-based index
	}

	sort.Slice(itrv, func(i, j int) bool {
		return (itrv[i].r - itrv[i].l) < (itrv[j].r - itrv[j].l)
	})

	itrv = append(itrv, Query{0, n, 0}) // Add the last query

	cur := make(map[int]struct {
		r int
		n []float64
	})

	for _, q := range itrv {
		be := findLowerBound(cur, q.l)
		en := findLowerBound(cur, q.r)

		nv := make([]float64, q * 2 + 1)
		pv := q.l

		for itr := be; itr != en; {
			zer := 0
			for pv < itr.Key {
				dif := a[pv] - m + q
				if dif > zer {
					zer = dif
				}
				pv++
			}
			for i := 0; i < zer; i++ {
				nv[i] = 0
			}
			tmp := itr.Value.n
			for i := 0; i <= q * 2; i++ {
				nv[i] *= tmp[i]
			}
			itr++
		}

		{
			zer := 0
			for pv < q.r {
				dif := a[pv] - m + q
				if dif > zer {
					zer = dif
				}
				pv++
			}
			for i := 0; i < zer; i++ {
				nv[i] = 0
			}
		}

		nx := make([]float64, q * 2 + 1)
		for i := 0; i <= q * 2; i++ {
			nx[i] += (1 - q.p) * nv[i]
		}
		for i := 0; i < q * 2; i++ {
			nx[i + 1] += q.p * nv[i]
		}
		delete(cur, be)
		cur[q.l] = struct{ r int; n []float64 }{q.r, nx}
	}

	ans := float64(m)
	sum := 0.0
	if len(cur) > 0 {
		first := cur[0]
		ren, top := first.r, first.n
		for i := 0; i <= q * 2; i++ {
			if i < q {
				if top[i] >= 1e-6 {
					panic("assertion failed")
				}
			}
			ans += float64(i - q) * (top[i] - sum)
			sum = top[i]
		}
		if top[len(top)-1] <= 1-1e-6 {
			panic("assertion failed")
		}
	}

	fmt.Println(ans)
}

func findLowerBound(m map[int]struct{ r int; n []float64 }, key int) int {
	for k := range m {
		if k >= key {
			return k
		}
	}
	return -1
}
