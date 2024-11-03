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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	k := nextInt(scanner)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nextLong(scanner)
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

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextDouble(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func nextLine(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func printIntArray(arr []int) {
	for _, num := range arr {
		fmt.Print(num, " ")
	}
	fmt.Println()
}

func printLongArray(arr []int64) {
	for _, num := range arr {
		fmt.Print(num, " ")
	}
	fmt.Println()
}

func inputIntArray(scanner *bufio.Scanner, n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt(scanner)
	}
	return arr
}

func inputLongArray(scanner *bufio.Scanner, n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextLong(scanner)
	}
	return arr
}
