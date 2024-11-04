package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"sort"
	"strconv"
)

const mod = 1000000007
const mod2 = 998244353

var inp = bufio.NewReaderSize(bufio.NewReader(os.Stdin), 1024)
var out = bufio.NewWriter(os.Stdout)

func main() {
	n, k := nextInt(), nextInt()
	a := make([]int64, n)
	input(a, n)
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	for i := 0; i < n/2; i++ {
		a[i], a[n-1-i] = a[n-1-i], a[i]
	}
	pq := make([]int64, k)
	for i := range pq {
		pq[i] = 0
	}
	gg := int64(0)
	for i := 0; i < n; i++ {
		cur := pq[0]
		pq = pq[1:]
		gg += cur
		cur += a[i]
		pq = append(pq, cur)
		sort.Slice(pq, func(i, j int) bool {
			return pq[i] > pq[j]
		})
	}
	fmt.Println(gg)
	out.Flush()
}

func input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = nextInt64()
	}
}

func nextInt() int {
	s := nextString()
	i, _ := strconv.Atoi(s)
	return i
}

func nextInt64() int64 {
	s := nextString()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func nextString() string {
	var s string
	fmt.Fscan(inp, &s)
	return s
}
