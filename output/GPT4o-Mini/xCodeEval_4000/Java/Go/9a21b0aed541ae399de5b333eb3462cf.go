package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewIO() *IO {
	return &IO{
		reader: bufio.NewReader(os.Stdin),
		writer: bufio.NewWriter(os.Stdout),
	}
}

func (io *IO) readInt() (int, error) {
	line, err := io.reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(strings.TrimSpace(line))
}

func (io *IO) readArrayInt() ([]int, error) {
	line, err := io.reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	strs := strings.Fields(line)
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i], err = strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
	}
	return arr, nil
}

func (io *IO) writeInt(number int) {
	io.writer.WriteString(fmt.Sprintf("%d\n", number))
}

func (io *IO) print() {
	io.writer.Flush()
}

func main() {
	io := NewIO()
	i1, _ := io.readInt()
	for i2 := 0; i2 < i1; i2++ {
		countValue := make(map[int]int)
		quantity, _ := io.readArrayInt()
		base, _ := io.readArrayInt()
		for i := 0; i < quantity[2]; i++ {
			countValue[base[i]]++
		}
		min := len(countValue)
		for i := quantity[2]; i < quantity[0]; i++ {
			countValue[base[i-quantity[2]]]--
			if countValue[base[i-quantity[2]]] == 0 {
				delete(countValue, base[i-quantity[2]])
			}
			countValue[base[i]]++
			min = minInt(min, len(countValue))
		}
		io.writeInt(min)
	}
	io.print()
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

type Division struct {
	dividend, divider int
}

func NewDivision(dividend, divider int) *Division {
	g := gcd(dividend, divider)
	return &Division{dividend / g, divider / g}
}

func (d *Division) Add(other *Division) *Division {
	lcmValue := lcm(d.divider, other.divider)
	newDividend := (lcmValue/d.divider)*d.dividend + (lcmValue/other.divider)*other.dividend
	return NewDivision(newDividend, lcmValue)
}

func (d *Division) Multiply(other *Division) *Division {
	return NewDivision(d.dividend*other.dividend, d.divider*other.divider)
}

type Pair struct {
	first  interface{}
	second interface{}
}

func NewPair(first, second interface{}) *Pair {
	return &Pair{first, second}
}

func (p *Pair) GetFirst() interface{} {
	return p.first
}

func (p *Pair) GetSecond() interface{} {
	return p.second
}

func (p *Pair) SetFirst(first interface{}) {
	p.first = first
}

func (p *Pair) SetSecond(second interface{}) {
	p.second = second
}

type Graph struct {
	base     [][]int
	used     []bool
	quantity int
	ancestor []int
}

func (g *Graph) Start(length int) {
	g.used = make([]bool, length)
	g.ancestor = make([]int, length)
	g.ancestor[0] = -1
	g.quantity = 0
}

func (g *Graph) RibMatrixToDefault(length, quantity int, value [][]int) {
	g.base = make([][]int, length)
	inputBase := make([][]int, length)
	for i := range inputBase {
		inputBase[i] = []int{}
	}
	for i := 0; i < quantity; i++ {
		inputBase[value[i][0]-1] = append(inputBase[value[i][0]-1], value[i][1]-1)
		inputBase[value[i][1]-1] = append(inputBase[value[i][1]-1], value[i][0]-1)
	}
	for i := 0; i < length; i++ {
		g.base[i] = inputBase[i]
	}
	g.Start(length)
}

func (g *Graph) Dijkstra(start, stop, size int) int {
	start--
	stop--
	dist := make([]int, size)
	for i := 0; i < size; i++ {
		if i != start {
			dist[i] = int(^uint(0) >> 1) // Max int
		}
		g.ancestor[i] = start
	}

	queue := [][]int{{start, 0}}
	var position int
	for len(queue) > 0 {
		getQueue := queue[0]
		queue = queue[1:]
		position = getQueue[0]
		if getQueue[1] > dist[position] {
			continue
		}
		for index := 0; index < len(g.base[position]); index += 2 {
			if dist[position]+g.base[position][index+1] < dist[g.base[position][index]] && !g.used[g.base[position][index]] {
				dist[g.base[position][index]] = dist[position] + g.base[position][index+1]
				g.ancestor[g.base[position][index]] = position
				queue = append(queue, []int{g.base[position][index], dist[g.base[position][index]]})
			}
		}
		g.used[position] = true
	}
	if dist[stop] == int(^uint(0)>>1) {
		return -1
	}
	return dist[stop]
}

func main() {
	// The main function can be used to test the Graph and other functionalities.
}
