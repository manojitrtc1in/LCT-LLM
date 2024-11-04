package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = scanInt()
	}
	return arr
}

func printInt(val int) {
	fmt.Fprint(writer, val)
}

func printlnInt(val int) {
	fmt.Fprintln(writer, val)
}

type F struct {
	n          int
	m          int
	arr        []int
	required   int
	typeDays   map[int]map[int]bool
}

func (f *F) solver() {
	f.n = scanInt()
	f.m = scanInt()
	f.arr = scanIntArray(f.n)
	f.required = sum(f.arr)
	f.typeDays = make(map[int]map[int]bool)
	for i := 0; i < f.m; i++ {
		d := scanInt()
		typ := scanInt()
		if f.arr[typ-1] <= 0 {
			continue
		}
		if _, ok := f.typeDays[typ]; !ok {
			f.typeDays[typ] = make(map[int]bool)
		}
		f.typeDays[typ][d] = true
	}

	lo := f.required
	hi := 2 * f.required
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
	printlnInt(valid)
}

func (f *F) isEnough(day int) bool {
	totalCoin := day
	req := f.required

	ddays := make([]int, day+1)
	for typ, days := range f.typeDays {
		lastDay := -1
		for d := range days {
			if d <= day {
				lastDay = max(lastDay, d)
			}
		}
		if lastDay == -1 {
			continue
		}
		ddays[lastDay] += f.arr[typ-1]
	}

	removed := 0
	for i := 1; i < day+1; i++ {
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	initIO()
	defer flush()

	f := F{}
	f.solver()
}
