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
var inp *FastReader
var out *bufio.Writer

type id0 struct{}

func main() {
	inp = NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	g := id0{}
	g.main()
}

func (g id0) main() {
	n := inp.NextInt()
	k := inp.NextInt()
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

func sortInt(a []int) {
	sort.Ints(a)
}

func sortLong(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func id1(a []int) {
	rand.Seed(0)
	n := len(a)
	for i := 0; i < n; i++ {
		j := rand.Intn(n)
		temp := a[i]
		a[i] = a[j]
		a[j] = temp
	}
	sortInt(a)
}

func id1Long(a []int64) {
	rand.Seed(0)
	n := len(a)
	for i := 0; i < n; i++ {
		j := rand.Intn(n)
		temp := a[i]
		a[i] = a[j]
		a[j] = temp
	}
	sortLong(a)
}

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) Next() string {
	for {
		st, _ := fr.br.ReadString('\n')
		if st != "" {
			return strings.TrimSpace(st)
		}
	}
}

func (fr *FastReader) NextInt() int {
	num, _ := strconv.Atoi(fr.Next())
	return num
}

func (fr *FastReader) NextLong() int64 {
	num, _ := strconv.ParseInt(fr.Next(), 10, 64)
	return num
}

func (fr *FastReader) NextDouble() float64 {
	num, _ := strconv.ParseFloat(fr.Next(), 64)
	return num
}

func (fr *FastReader) NextLine() string {
	str, _ := fr.br.ReadString('\n')
	return strings.TrimSpace(str)
}

func input(a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = inp.NextLong()
	}
}

type PriorityQueue []int64

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i] > pq[j] }

func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

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

func (pq *PriorityQueue) Peek() interface{} {
	return (*pq)[0]
}

func (pq *PriorityQueue) IsEmpty() bool {
	return len(*pq) == 0
}

func (pq *PriorityQueue) Clear() {
	*pq = (*pq)[:0]
}

func (pq *PriorityQueue) Size() int {
	return len(*pq)
}

func (pq *PriorityQueue) Values() []int64 {
	return *pq
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func printInt(a []int) {
	n := len(a)
	for i := 0; i < n; i++ {
		fmt.Print(a[i], " ")
	}
}

func printLong(a []int64) {
	n := len(a)
	for i := 0; i < n; i++ {
		fmt.Print(a[i], " ")
	}
}

func main() {
	g := id0{}
	g.main()
}
