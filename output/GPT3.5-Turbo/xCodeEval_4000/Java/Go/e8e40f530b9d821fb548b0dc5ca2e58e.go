package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &FastScanner{scanner}
}

func (fs *FastScanner) Next() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	num, _ := strconv.Atoi(fs.Next())
	return num
}

func (fs *FastScanner) NextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.NextInt()
	}
	return arr
}

type FastWriter struct {
	writer *bufio.Writer
}

func NewFastWriter() *FastWriter {
	writer := bufio.NewWriter(os.Stdout)
	return &FastWriter{writer}
}

func (fw *FastWriter) Println(a ...interface{}) {
	fmt.Fprintln(fw.writer, a...)
}

func (fw *FastWriter) Close() {
	fw.writer.Flush()
}

type F struct {
	n          int
	m          int
	arr        []int
	required   int
	typeDays   map[int]map[int]bool
}

func (f *F) solver() {
	fs := NewFastScanner()
	fw := NewFastWriter()

	f.n = fs.NextInt()
	f.m = fs.NextInt()
	f.arr = fs.NextIntArray(f.n)
	f.required = sum(f.arr)
	f.typeDays = make(map[int]map[int]bool)

	for i := 0; i < f.m; i++ {
		d := fs.NextInt()
		typ := fs.NextInt()
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

	fw.Println(valid)
	fw.Close()
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
	f := F{}
	f.solver()
}

