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

func solver() int64 {
	reader := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Fscan(reader, &n, &k)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
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
	return ans
}

func main() {
	result := solver()
	fmt.Println(result)
}
