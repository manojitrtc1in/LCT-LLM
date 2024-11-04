package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Pair struct {
	first  interface{}
	second interface{}
}

func NewPair(first, second interface{}) *Pair {
	return &Pair{first: first, second: second}
}

func (p *Pair) GetFirst() interface{} {
	return p.first
}

func (p *Pair) GetSecond() interface{} {
	return p.second
}

func (p *Pair) SetFirst(element interface{}) {
	p.first = element
}

func (p *Pair) SetSecond(element interface{}) {
	p.second = element
}

type Math struct{}

func (m *Math) GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return m.GCD(b, a%b)
}

func (m *Math) LCM(a, b int) int {
	return a / m.GCD(a, b) * b
}

type Division struct {
	*Pair
}

func NewDivision(dividend, divider interface{}) *Division {
	d := &Division{NewPair(dividend, divider)}
	d.reduce()
	return d
}

func (d *Division) reduce() {
	switch v := d.GetFirst().(type) {
	case int:
		divider := d.GetSecond().(int)
		gcd := Math{}.GCD(v, divider)
		d.SetFirst(v / gcd)
		d.SetSecond(divider / gcd)
	}
}

func (d *Division) Add(number *Division) *Division {
	dividend := d.GetFirst().(int) * number.GetSecond().(int) + number.GetFirst().(int) * d.GetSecond().(int)
	divider := d.GetSecond().(int) * number.GetSecond().(int)
	return NewDivision(dividend, divider)
}

func (d *Division) Multiply(number *Division) *Division {
	first := d.GetFirst().(int) * number.GetFirst().(int)
	second := d.GetSecond().(int) * number.GetSecond().(int)
	return NewDivision(first, second)
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

	queue := make([][2]int, 0)
	queue = append(queue, [2]int{start, 0})
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
				queue = append(queue, [2]int{g.base[position][index], dist[g.base[position][index]]})
			}
		}
		g.used[position] = true
	}
	if dist[stop] == int(^uint(0)>>1) {
		return -1
	}
	return dist[stop]
}

func readInt(reader *bufio.Reader) (int, error) {
	var n int
	_, err := fmt.Fscan(reader, &n)
	return n, err
}

func readInts(reader *bufio.Reader) ([]int, error) {
	var n int
	_, err := fmt.Fscan(reader, &n)
	if err != nil {
		return nil, err
	}
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		_, err := fmt.Fscan(reader, &arr[i])
		if err != nil {
			return nil, err
		}
	}
	return arr, nil
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	i1, _ := readInt(reader)
	for i2 := 0; i2 < i1; i2++ {
		quantity := readInts(reader)
		base := readInts(reader)
		countValue := make(map[int]int)
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
		fmt.Println(min)
	}
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
