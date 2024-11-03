package main

import (
	"bufio"
	"fmt"
	"math"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"strings"
)

var mod int64 = 1000000007
var mod2 int64 = 998244353
var inp *bufio.Reader = bufio.NewReader(os.Stdin)
var out *bufio.Writer = bufio.NewWriter(os.Stdout)

func main() {
	defer out.Flush()
	g := InVoker{}
	g.main()
}

type InVoker struct{}

func (g *InVoker) main() {
	n := nextInt()
	k := nextInt()
	a := make([]int64, n)
	input(a, n)
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	for k >= 0 {
		heap.Push(&pq, 0)
		k--
	}
	gg := int64(0)
	for i := 0; i < n; i++ {
		cur := heap.Pop(&pq).(int64)
		gg += cur
		cur += a[i]
		heap.Push(&pq, cur)
	}
	fmt.Fprintln(out, gg)
}

type PriorityQueue []int64

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(int64)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func next() string {
	for {
		str, err := inp.ReadString('\n')
		if err == nil || len(str) > 0 {
			return strings.TrimSpace(str)
		}
	}
}

func nextInt() int {
	num, _ := strconv.Atoi(next())
	return num
}

func nextInt64() int64 {
	num, _ := strconv.ParseInt(next(), 10, 64)
	return num
}

func nextFloat64() float64 {
	num, _ := strconv.ParseFloat(next(), 64)
	return num
}

func input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = nextInt64()
	}
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func printSlice(a []int64) {
	for _, val := range a {
		fmt.Fprint(out, val, " ")
	}
}

func printSliceInt(a []int) {
	for _, val := range a {
		fmt.Fprint(out, val, " ")
	}
}

func printSliceFloat64(a []float64) {
	for _, val := range a {
		fmt.Fprint(out, val, " ")
	}
}

func power(x, y int64) int64 {
	gg := int64(1)
	for y > 0 {
		if y%2 == 1 {
			gg = gg * x % mod
		}
		x = x * x % mod
		y /= 2
	}
	return gg
}

func init() {
	buf := make([]byte, 16384)
	inp = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	inp.Read(buf)
}

func main() {
	InVoker := new(InVoker)
	InVoker.main()
	out.Flush()
}
