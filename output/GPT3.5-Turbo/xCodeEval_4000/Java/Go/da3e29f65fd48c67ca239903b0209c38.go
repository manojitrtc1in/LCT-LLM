package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initScanner() {
	scanner = bufio.NewScanner(os.Stdin)
}

func initWriter() {
	writer = bufio.NewWriter(os.Stdout)
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	val, _ := strconv.Atoi(readString())
	return val
}

func readIntArray() []int {
	strs := strings.Split(readString(), " ")
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i], _ = strconv.Atoi(s)
	}
	return arr
}

func writeString(str string) {
	writer.WriteString(str)
}

func writeInt(num int) {
	writer.WriteString(strconv.Itoa(num))
}

func writeIntArray(arr []int) {
	strArr := make([]string, len(arr))
	for i, num := range arr {
		strArr[i] = strconv.Itoa(num)
	}
	writer.WriteString(strings.Join(strArr, " "))
}

func flushWriter() {
	writer.Flush()
}

type IO struct{}

func (io IO) readInt() int {
	return readInt()
}

func (io IO) readIntArray() []int {
	return readIntArray()
}

func (io IO) writeIntArray(arr []int) {
	writeIntArray(arr)
}

type Math struct{}

func (math Math) gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return math.gcd(b, a%b)
}

func (math Math) lcm(a, b int) int {
	return a / math.gcd(a, b) * b
}

type Pair struct {
	first  interface{}
	second interface{}
}

func createPair(first, second interface{}) Pair {
	return Pair{first, second}
}

type Fraction struct {
	dividend interface{}
	divider  interface{}
}

func createFraction(dividend, divider interface{}) Fraction {
	return Fraction{dividend, divider}
}

type Graph struct {
	base     [][]int
	used     []bool
	quantity int
	ancestor []int
}

func (graph *Graph) start(length int) {
	graph.used = make([]bool, length)
	graph.ancestor = make([]int, length)
	for i := 0; i < length; i++ {
		graph.ancestor[i] = -1
	}
	graph.quantity = 0
}

func (graph *Graph) dfs(position int) {
	graph.used[position] = true
	graph.quantity++
	for _, next := range graph.base[position] {
		if !graph.used[next] {
			graph.ancestor[next] = position
			graph.dfs(next)
		}
	}
}

func (graph *Graph) dijkstra(start, stop, size int) int {
	start--
	stop--
	dist := make([]int, size)
	for i := 0; i < size; i++ {
		if i != start {
			dist[i] = int(^uint(0) >> 1)
		}
		graph.ancestor[i] = start
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
		for index := 0; index < len(graph.base[position]); index += 2 {
			if dist[position]+graph.base[position][index+1] < dist[graph.base[position][index]] && !graph.used[graph.base[position][index]] {
				dist[graph.base[position][index]] = dist[position] + graph.base[position][index+1]
				graph.ancestor[graph.base[position][index]] = position
				queue = append(queue, []int{graph.base[position][index], dist[graph.base[position][index]]})
			}
		}
		graph.used[position] = true
	}
	if dist[stop] == int(^uint(0)>>1) {
		return -1
	}
	return dist[stop]
}

func main() {
	initScanner()
	initWriter()
	defer flushWriter()

	g := readInt()
	sh := readInt()
	j := readInt()
	p := readInt()
	priceFirst := readInt()
	priceSecond := readInt()
	answer := int64(0)
	if priceFirst <= priceSecond {
		answer = int64(min(min(sh, j), p))
		p -= answer
		answer *= int64(priceSecond)
		answer += int64(min(p, g) * priceFirst)
	} else {
		answer = int64(min(g, p))
		p -= answer
		answer *= int64(priceFirst)
		answer += int64(min(min(sh, j), p) * priceSecond)
	}
	writeInt(int(answer))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	initScanner()
	initWriter()
	defer flushWriter()

	g := readInt()
	sh := readInt()
	j := readInt()
	p := readInt()
	priceFirst := readInt()
	priceSecond := readInt()
	answer := int64(0)
	if priceFirst <= priceSecond {
		answer = int64(min(min(sh, j), p))
		p -= answer
		answer *= int64(priceSecond)
		answer += int64(min(p, g) * priceFirst)
	} else {
		answer = int64(min(g, p))
		p -= answer
		answer *= int64(priceFirst)
		answer += int64(min(min(sh, j), p) * priceSecond)
	}
	writeInt(int(answer))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
