package main

import (
	"bufio"
	"fmt"
	"math"
	"sort"
)

var (
	eol = '\n'
)

type tuple struct {
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

	m := a[0]
	for _, val := range a {
		if val > m {
			m = val
		}
	}

	itrv := make([]tuple, q)
	for i := 0; i < q; i++ {
		var l, r int
		var p float64
		fmt.Fscan(reader, &l, &r, &p)
		l--
		itrv[i] = tuple{l, r, p}
	}

	sort.Slice(itrv, func(i, j int) bool {
		return itrv[i].r-itrv[i].l < itrv[j].r-itrv[j].l
	})

	itrv = append(itrv, tuple{0, n, 0})

	cur := make(map[int]struct {
		r int
		n []float64
	})

	for _, it := range itrv {
		l, r, p := it.l, it.r, it.p
		be := findLowerBound(cur, l)
		en := findLowerBound(cur, r)

		nv := make([]float64, q*2+1)
		pv := l
		for k := be; k < en; k++ {
			zer := 0
			for pv < k {
				dif := a[pv] - m + q
				if dif > zer {
					zer = dif
				}
				pv++
			}
			for i := 0; i < zer; i++ {
				nv[i] = 0
			}
			tmp := cur[k].n
			for i := 0; i <= q*2; i++ {
				nv[i] *= tmp[i]
			}
		}

		{
			zer := 0
			for pv < r {
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

		nx := make([]float64, q*2+1)
		for i := 0; i <= q*2; i++ {
			nx[i] += (1 - p) * nv[i]
		}
		for i := 0; i < q*2; i++ {
			nx[i+1] += p * nv[i]
		}
		delete(cur, be)
		cur[l] = struct {
			r int
			n []float64
		}{r, nx}
	}

	ans := float64(m)
	sum := 0.0
	ren, top := cur[0].r, cur[0].n
	for i := 0; i <= q*2; i++ {
		if i < q {
			if top[i] >= 1e-6 {
				panic("assertion failed")
			}
		}
		ans += float64(i-q) * (top[i] - sum)
		sum = top[i]
	}
	if top[len(top)-1] <= 1-1e-6 {
		panic("assertion failed")
	}
	fmt.Println(ans)
}

func findLowerBound(m map[int]struct {
	r int
	n []float64
}, key int) int {
	for k := range m {
		if k >= key {
			return k
		}
	}
	return len(m)
}
