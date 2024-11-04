package main

import (
	"fmt"
	"sort"
)

type B1T struct {
	bit [100007]int64
	n   int
}

func (b *B1T) add(djg int, x int64) {
	for djg <= b.n {
		b.bit[djg] += x
		djg += (djg & -djg)
	}
}

func (b *B1T) sum(djg int) int64 {
	var s0m int64 = 0
	for djg > 0 {
		s0m += b.bit[djg]
		djg -= (djg & -djg)
	}
	return s0m
}

func main() {
	var n, w int
	fmt.Scan(&n, &w)

	x := make([]float64, n)
	y := make([]float64, n)
	cnt := make(map[float64]int)
	as := make([]float64, n)
	bs := make([]struct {
		val float64
		idx int
	}, n)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		x[i] = float64(a) / float64(b+w)
		y[i] = float64(a) / float64(b-w)
		cnt[y[i]]++
	}

	var ans int64 = 0
	for i := 0; i < n; i++ {
		ans += int64(cnt[y[i]] - 1)
	}
	ans /= 2

	for i := 0; i < n; i++ {
		as[i] = x[i]
	}
	sort.Float64s(as)
	cnta := unique(as)

	for i := 0; i < n; i++ {
		bs[i] = struct {
			val float64
			idx int
		}{y[i], i}
	}
	sort.Slice(bs, func(i, j int) bool {
		return bs[i].val < bs[j].val
	})

	bit := B1T{n: 100007}
	now := 0
	for i := 0; i < n; i++ {
		for now < n && bs[now].val < bs[i].val {
			id := lowerBound(as, x[bs[now].idx])
			bit.add(100006-id, 1)
			now++
		}
		id := lowerBound(as, x[bs[i].idx])
		ans += bit.sum(100006 - id)
	}

	fmt.Println(ans)
}

func unique(arr []float64) int {
	sort.Float64s(arr)
	j := 0
	for i := 1; i < len(arr); i++ {
		if arr[j] != arr[i] {
			j++
			arr[j] = arr[i]
		}
	}
	return j + 1
}

func lowerBound(arr []float64, target float64) int {
	lo, hi := 0, len(arr)
	for lo < hi {
		mid := (lo + hi) / 2
		if arr[mid] < target {
			lo = mid + 1
		} else {
			hi = mid
		}
	}
	return lo
}
