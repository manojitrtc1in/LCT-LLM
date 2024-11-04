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

func NewPair(first, second interface{}) Pair {
	return Pair{first: first, second: second}
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
	Pair
}

func NewDivision(dividend, divider interface{}) *Division {
	d := &Division{}
	d.Pair = NewPair(dividend, divider)
	d.reduce()
	return d
}

func (d *Division) reduce() {
	switch d.GetFirst().(type) {
	case int:
		dividend := d.GetFirst().(int)
		divider := d.GetSecond().(int)
		gcd := Math{}.GCD(dividend, divider)
		d.SetFirst(dividend / gcd)
		d.SetSecond(divider / gcd)
	}
}

func (d *Division) AddWithoutReturn(number *Division) {
	d.add(number, 0)
}

func (d *Division) AddWithReturn(number *Division) *Division {
	return d.add(number, 1)
}

func (d *Division) add(number *Division, function int) *Division {
	switch d.GetFirst().(type) {
	case int:
		dividend := d.GetFirst().(int)
		divider := d.GetSecond().(int)
		dividend1 := number.GetFirst().(int)
		divider1 := number.GetSecond().(int)
		lcm := Math{}.LCM(divider, divider1)
		if function == 0 {
			d.SetFirst((lcm/divider)*dividend + (lcm/divider1)*dividend1)
			d.SetSecond(lcm)
			d.reduce()
			return nil
		}
		result := NewDivision((lcm/divider)*dividend+(lcm/divider1)*dividend1, lcm)
		result.reduce()
		return result
	}
	return nil
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var i1 int
	fmt.Fscan(reader, &i1)

	for i2 := 0; i2 < i1; i2++ {
		quantity := readArrayInt(reader)
		base := readArrayInt(reader)

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
		fmt.Fprintln(writer, min)
	}
}

func readArrayInt(reader *bufio.Reader) []int {
	var n int
	fmt.Fscan(reader, &n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	return arr
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
