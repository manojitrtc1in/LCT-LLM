package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
	"sort"
)

type Pair struct {
	first  interface{}
	second interface{}
}

func NewPair(first, second interface{}) Pair {
	return Pair{first: first, second: second}
}

type Division struct {
	dividend interface{}
	divisor  interface{}
}

func NewDivision(dividend, divisor interface{}) Division {
	d := Division{dividend: dividend, divisor: divisor}
	d.reduce()
	return d
}

func (d *Division) reduce() {
	switch d.dividend.(type) {
	case int:
		gcd := gcd(int(d.dividend.(int)), int(d.divisor.(int)))
		d.dividend = d.dividend.(int) / gcd
		d.divisor = d.divisor.(int) / gcd
	case int64:
		gcd := gcd(int64(d.dividend.(int64)), int64(d.divisor.(int64)))
		d.dividend = d.dividend.(int64) / gcd
		d.divisor = d.divisor.(int64) / gcd
	case float32:
		gcd := gcd(float32(d.dividend.(float32)), float32(d.divisor.(float32)))
		d.dividend = d.dividend.(float32) / gcd
		d.divisor = d.divisor.(float32) / gcd
	case float64:
		gcd := gcd(float64(d.dividend.(float64)), float64(d.divisor.(float64)))
		d.dividend = d.dividend.(float64) / gcd
		d.divisor = d.divisor.(float64) / gcd
	}
}

func gcd(a, b interface{}) interface{} {
	switch a.(type) {
	case int:
		if b.(int) == 0 {
			return a
		}
		return gcd(b.(int), a.(int)%b.(int))
	case int64:
		if b.(int64) == 0 {
			return a
		}
		return gcd(b.(int64), a.(int64)%b.(int64))
	case float32:
		if b.(float32) == 0 {
			return a
		}
		return gcd(b.(float32), math.Mod(float64(a.(float32)), float64(b.(float32))))
	case float64:
		if b.(float64) == 0 {
			return a
		}
		return gcd(b.(float64), math.Mod(a.(float64), b.(float64)))
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
		fmt.Fprintln(writer, min)
	}
}

func readInts(reader *bufio.Reader) []int {
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
