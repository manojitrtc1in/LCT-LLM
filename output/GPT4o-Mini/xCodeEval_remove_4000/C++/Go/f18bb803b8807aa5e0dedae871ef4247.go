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
	id0 := int64(0)
	for djg > 0 {
		id0 += b.bit[djg]
		djg -= (djg & -djg)
	}
	return id0
}

var n, w int
var x, y [100007]float64
var cnt = make(map[float64]int)
var as [100007]float64
var cnta int
var bs [100007]struct {
	val float64
	idx int
}

func main() {
	fmt.Scan(&n, &w)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		x[i] = float64(a) / float64(b+w)
		y[i] = float64(a) / float64(b-w)
		cnt[y[i]]++
	}

	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(cnt[y[i]] - 1)
	}
	ans /= 2

	for i := 0; i < n; i++ {
		as[i] = x[i]
	}
	sort.Float64s(as[:n])
	cnta = unique(as[:n])

	for i := 0; i < n; i++ {
		bs[i] = struct {
			val float64
			idx int
		}{y[i], i}
	}
	sort.Slice(bs[:n], func(i, j int) bool {
		return bs[i].val < bs[j].val
	})

	now := 0
	bit := B1T{n: 100007}
	for i := 0; i < n; i++ {
		for now < n && bs[now].val < bs[i].val {
			id := lowerBound(as[:cnta], x[bs[now].idx])
			bit.add(100006-id, 1)
			now++
		}
		id := lowerBound(as[:cnta], x[bs[i].idx])
		ans += bit.sum(100006 - id)
	}

	fmt.Println(ans)
	fmt.Println(ans)
}

func unique(arr []float64) int {
	if len(arr) == 0 {
		return 0
	}
	sort.Float64s(arr)
	j := 0
	for i := 1; i < len(arr); i++ {
		if arr[i] != arr[j] {
			j++
			arr[j] = arr[i]
		}
	}
	return j + 1
}

func lowerBound(arr []float64, target float64) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}
