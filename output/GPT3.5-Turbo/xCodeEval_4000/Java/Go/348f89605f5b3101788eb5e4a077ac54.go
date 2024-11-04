package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var mod int64 = 1000000007
var mod2 int64 = 998244353

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	k := nextInt(scanner)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt64(scanner)
	}
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
	fmt.Println(gg)
}

type PriorityQueue []int64

func (pq PriorityQueue) Len() int { return len(pq) }
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

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}
