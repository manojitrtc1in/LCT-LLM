package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Count struct {
	count int
	cost  int64
}

func (c *Count) increment(cost int64, k int) {
	if c.count >= k {
		return
	}
	c.cost += cost
	c.count++
}

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (fs *FastScanner) intNext() int {
	fs.scanner.Scan()
	var n int
	fmt.Sscan(fs.scanner.Text(), &n)
	return n
}

func (fs *FastScanner) id12(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.intNext()
	}
	return arr
}

func solver() {
	fs := NewFastScanner()
	n := fs.intNext()
	k := fs.intNext()
	arr := fs.id12(n)
	sort.Ints(arr)

	counts := make(map[int]*Count)
	counts[0] = &Count{}

	for _, number := range arr {
		num := number
		cost := int64(0)
		for num > 0 {
			if _, exists := counts[num]; !exists {
				counts[num] = &Count{}
			}
			counts[num].increment(cost, k)
			num /= 2
			cost++
		}
		counts[0].increment(cost, k)
	}

	ans := int64(1<<63 - 1)
	for _, count := range counts {
		if count.count >= k {
			if count.cost < ans {
				ans = count.cost
			}
		}
	}
	fmt.Println(ans)
}

func main() {
	solver()
}
