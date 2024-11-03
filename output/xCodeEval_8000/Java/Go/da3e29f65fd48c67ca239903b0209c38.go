package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readLine())
	return num
}

func readInts() []int {
	line := readLine()
	strs := strings.Split(line, " ")
	nums := make([]int, len(strs))
	for i, str := range strs {
		nums[i], _ = strconv.Atoi(str)
	}
	return nums
}

func writeInt(num int) {
	writer.WriteString(strconv.Itoa(num))
}

func writeString(str string) {
	writer.WriteString(str)
}

func writeLine() {
	writer.WriteString("\n")
}

func flush() {
	writer.Flush()
}

type math struct{}

func (m *math) gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return m.gcd(b, a%b)
}

func (m *math) lcm(a, b int) int {
	return a / m.gcd(a, b) * b
}

type pair struct {
	first  int
	second int
}

type fraction struct {
	dividend int
	divider  int
}

func newFraction(dividend, divider int) *fraction {
	f := &fraction{dividend: dividend, divider: divider}
	f.reduce()
	return f
}

func (f *fraction) reduce() {
	gcd := math.gcd(f.dividend, f.divider)
	f.dividend /= gcd
	f.divider /= gcd
}

func (f *fraction) add(number *fraction) *fraction {
	lcm := math.lcm(f.divider, number.divider)
	newDividend := (lcm/f.divider)*f.dividend + (lcm/number.divider)*number.dividend
	return newFraction(newDividend, lcm)
}

func (f *fraction) multiply(number *fraction) *fraction {
	newDividend := f.dividend * number.dividend
	newDivider := f.divider * number.divider
	return newFraction(newDividend, newDivider)
}

type graph struct {
	base     [][]int
	used     []bool
	quantity int
	ancestor []int
}

func newGraph() *graph {
	return &graph{}
}

func (g *graph) setBase(base [][]int) {
	g.base = base
}

func (g *graph) getBase() [][]int {
	return g.base
}

func (g *graph) getUsed() []bool {
	return g.used
}

func (g *graph) getQuantity() int {
	return g.quantity
}

func (g *graph) getAncestor() []int {
	return g.ancestor
}

func (g *graph) start(length int) {
	g.used = make([]bool, length)
	g.ancestor = make([]int, length)
	for i := 0; i < length; i++ {
		g.ancestor[i] = -1
	}
	g.quantity = 0
}

func (g *graph) dfs(position int) {
	g.used[position] = true
	g.quantity++
	for _, next := range g.base[position] {
		if !g.used[next] {
			g.ancestor[next] = position
			g.dfs(next)
		}
	}
}

func (g *graph) dijkstra(start, stop, size int) int {
	start--
	stop--
	dist := make([]int, size)
	for i := 0; i < size; i++ {
		if i != start {
			dist[i] = math.MaxInt64
		}
		g.ancestor[i] = start
	}

	queue := make([][]int, 0)
	queue = append(queue, []int{start, 0})
	for len(queue) != 0 {
		getQueue := queue[0]
		queue = queue[1:]
		position := getQueue[0]
		if getQueue[1] > dist[position] {
			continue
		}
		for i := 0; i < len(g.base[position]); i += 2 {
			if dist[position]+g.base[position][i+1] < dist[g.base[position][i]] && !g.used[g.base[position][i]] {
				dist[g.base[position][i]] = dist[position] + g.base[position][i+1]
				g.ancestor[g.base[position][i]] = position
				queue = append(queue, []int{g.base[position][i], dist[g.base[position][i]]})
			}
		}
		g.used[position] = true
	}
	if dist[stop] == math.MaxInt64 {
		return -1
	}
	return dist[stop]
}

func solveFloydWarshall(base [][]int, length, not int) bool {
	for k := 0; k < length; k++ {
		for i := 0; i < length; i++ {
			for j := 0; j < length; j++ {
				if base[i][k] == not || base[k][j] == not {
					continue
				}
				total := base[i][k] + base[k][j]
				if base[i][j] != not {
					base[i][j] = int(math.Min(float64(base[i][j]), float64(total)))
				} else {
					base[i][j] = total
				}
			}
		}
	}
	for index := 0; index < length; index++ {
		if base[index][index] != 0 {
			return false
		}
	}
	return true
}

func solveKruskal(edgesMatrix [][]int, countVertex, indexSort int) (int, [][]int) {
	answer := make([][]int, countVertex-1)
	sum := 0
	sortEdges(edgesMatrix, indexSort)
	dsu := newSystemOfDisjointSets(countVertex)
	for i := 0; i < countVertex; i++ {
		dsu.makeSet(i)
	}
	index := 0
	for _, value := range edgesMatrix {
		if dsu.mergeSets(value[0], value[1]) {
			sum += value[indexSort]
			answer[index] = []int{value[0], value[1]}
			index++
		}
	}
	if index < countVertex-1 {
		return -1, nil
	}
	return sum, answer
}

type systemOfDisjointSets struct {
	rank     []int
	ancestor []int
}

func newSystemOfDisjointSets(size int) *systemOfDisjointSets {
	return &systemOfDisjointSets{
		rank:     make([]int, size),
		ancestor: make([]int, size),
	}
}

func (s *systemOfDisjointSets) makeSet(value int) {
	s.ancestor[value] = value
	s.rank[value] = 0
}

func (s *systemOfDisjointSets) findSet(value int) int {
	if value == s.ancestor[value] {
		return value
	}
	s.ancestor[value] = s.findSet(s.ancestor[value])
	return s.ancestor[value]
}

func (s *systemOfDisjointSets) mergeSets(first, second int) bool {
	first = s.findSet(first)
	second = s.findSet(second)
	if first != second {
		if s.rank[first] < s.rank[second] {
			first, second = second, first
		}
		s.ancestor[second] = first
		if s.rank[first] == s.rank[second] {
			s.rank[first]++
		}
		return true
	}
	return false
}

func sortEdges(edgesMatrix [][]int, indexSort int) {
	if indexSort == 0 {
		shellSort(edgesMatrix)
	} else if indexSort == 1 {
		heapSort(edgesMatrix)
	} else if indexSort == 2 {
		mergeSort(edgesMatrix, 0, len(edgesMatrix)-1)
	} else if indexSort == 3 {
		straightMergeSort(edgesMatrix)
	} else if indexSort == 4 {
		insertionSort(edgesMatrix)
	}
}

func shellSort(array [][]int) {
	for gap := len(array) / 2; gap > 0; gap /= 2 {
		for i := gap; i < len(array); i++ {
			temp := array[i]
			j := i
			for j >= gap && array[j-gap][0] > temp[0] {
				array[j] = array[j-gap]
				j -= gap
			}
			array[j] = temp
		}
	}
}

func heapSort(array [][]int) {
	for i := len(array)/2 - 1; i >= 0; i-- {
		shiftDown(array, i, len(array))
	}
	for i := len(array) - 1; i > 0; i-- {
		swap(array, 0, i)
		shiftDown(array, 0, i)
	}
}

func shiftDown(array [][]int, i, n int) {
	tmp := array[i]
	for leftChild(i) < n {
		child := leftChild(i)
		if child != n-1 && array[child][0] < array[child+1][0] {
			child++
		}
		if tmp[0] < array[child][0] {
			array[i] = array[child]
		} else {
			break
		}
		i = child
	}
	array[i] = tmp
}

func leftChild(i int) int {
	return i*2 + 1
}

func swap(array [][]int, i, j int) {
	array[i], array[j] = array[j], array[i]
}

func mergeSort(array [][]int, low, high int) {
	if low < high {
		mid := (low + high) / 2
		mergeSort(array, low, mid)
		mergeSort(array, mid+1, high)
		merge(array, low, mid, high)
	}
}

func merge(array [][]int, low, mid, high int) {
	n := high - low + 1
	temp := make([][]int, n)
	i, j, k := low, mid+1, 0
	for i <= mid || j <= high {
		if i > mid {
			temp[k] = array[j]
			j++
		} else if j > high {
			temp[k] = array[i]
			i++
		} else if array[i][0] < array[j][0] {
			temp[k] = array[i]
			i++
		} else {
			temp[k] = array[j]
			j++
		}
		k++
	}
	for j = 0; j < n; j++ {
		array[low+j] = temp[j]
	}
}

func straightMergeSort(array [][]int) {
	length := (len(array) + 1) / 2
	zeroBuffer := make([][]int, length)
	firstBuffer := make([][]int, 0)
	for index := 0; index < length; index++ {
		arrayIndex := index * 2
		nextArrayIndex := index*2 + 1
		if nextArrayIndex < len(array) {
			if array[arrayIndex][0] > array[nextArrayIndex][0] {
				zeroBuffer[index] = []int{array[nextArrayIndex][0], array[arrayIndex][0]}
			} else {
				zeroBuffer[index] = []int{array[arrayIndex][0]}
			}
		} else {
			zeroBuffer[index] = []int{array[arrayIndex][0]}
		}
	}
	position := false
	pointer0, pointer, pointer1, number := 0, 0, 0, 4
	var newPointer, count int
	var newBuffer, oldBuffer [][]int
	length = (len(array) + 3) / 4
	for {
		pointer0 = 0
		count = (number / 2) - 1
		if !position {
			firstBuffer = make([][]int, length)
			newBuffer = firstBuffer
			oldBuffer = zeroBuffer
		} else {
			zeroBuffer = make([][]int, length)
			newBuffer = zeroBuffer
			oldBuffer = firstBuffer
		}
		for i := 0; i < length; i++ {
			pointer = 0
			pointer1 = 0
			newPointer = pointer0 + 1
			if length == 1 {
				for g := 0; g < len(array); g++ {
					if pointer > count || oldBuffer[pointer0][pointer] == 0 {
						array[g] = oldBuffer[newPointer][pointer1]
						pointer1++
					} else if pointer1 > count || oldBuffer[newPointer][pointer1] == 0 {
						if oldBuffer[pointer0][pointer] == 0 {
							continue
						}
						array[g] = oldBuffer[pointer0][pointer]
						pointer++
					} else if oldBuffer[pointer0][pointer] >= oldBuffer[newPointer][pointer1] {
						array[g] = oldBuffer[newPointer][pointer1]
						pointer1++
					} else {
						array[g] = oldBuffer[pointer0][pointer]
						pointer++
					}
				}
				return
			}
			for g := 0; g < number; g++ {
				if pointer > count || oldBuffer[pointer0][pointer] == 0 {
					if oldBuffer[newPointer][pointer1] == 0 {
						continue
					}
					newBuffer[i][g] = oldBuffer[newPointer][pointer1]
					pointer1++
				} else if pointer1 > count || oldBuffer[newPointer][pointer1] == 0 {
					if oldBuffer[pointer0][pointer] == 0 {
						continue
					}
					newBuffer[i][g] = oldBuffer[pointer0][pointer]
					pointer++
				} else if oldBuffer[pointer0][pointer] >= oldBuffer[newPointer][pointer1] {
					newBuffer[i][g] = oldBuffer[newPointer][pointer1]
					pointer1++
				} else {
					newBuffer[i][g] = oldBuffer[pointer0][pointer]
					pointer++
				}
			}
			pointer0 += 2
		}
		position = !position
		length = (length + 1) / 2
		number *= 2
	}
}

func insertionSort(elements [][]int) {
	for i := 1; i < len(elements); i++ {
		key := elements[i]
		j := i - 1
		for j >= 0 && key[0] < elements[j][0] {
			elements[j+1] = elements[j]
			j--
		}
		elements[j+1] = key
	}
}

func main() {
	initIO()
	defer flush()

	g := new(graph)
	g.base = make([][]int, 0)

	g.base = append(g.base, readInts())
	g.start(g.base[0][0])

	for i := 0; i < g.base[0][1]; i++ {
		g.base = append(g.base, readInts())
	}

	g.dfs(0)

	writeInt(g.quantity, "\n")
}
