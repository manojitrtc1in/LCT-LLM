package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type F struct {
	n, m      int
	arr       []int
	required  int
	typeDays  map[int][]int
}

func (f *F) solver() {
	f.required = sum(f.arr)
	f.typeDays = make(map[int][]int)

	for i := 0; i < f.m; i++ {
		var d, typ int
		fmt.Scan(&d, &typ)
		if f.arr[typ-1] <= 0 {
			continue
		}
		f.typeDays[typ] = append(f.typeDays[typ], d)
	}

	lo, hi := f.required, 2*f.required
	valid := hi
	for lo <= hi {
		mid := (lo + hi) / 2
		if f.isEnough(mid) {
			valid = mid
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}
	fmt.Println(valid)
}

func (f *F) isEnough(day int) bool {
	totalCoin := day
	req := f.required

	ddays := make([]int, day+1)
	for typ, days := range f.typeDays {
		sort.Ints(days)
		for _, d := range days {
			if d <= day {
				ddays[d] += f.arr[typ-1]
			}
		}
	}

	removed := 0
	for i := 1; i <= day; i++ {
		coins := i - removed
		toRemove := min(coins, ddays[i])
		removed += toRemove
		totalCoin -= toRemove
		req -= toRemove
	}

	return req*2 <= totalCoin
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

func min(ins ...int) int {
	minVal := ins[0]
	for _, v := range ins[1:] {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var f F
	fmt.Fscan(reader, &f.n, &f.m)
	f.arr = make([]int, f.n)
	for i := 0; i < f.n; i++ {
		fmt.Fscan(reader, &f.arr[i])
	}
	f.solver()
}
