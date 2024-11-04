package main

import (
	"fmt"
	"math"
)

func main() {
	var g, sh, j, p, priceFirst, priceSecond int
	fmt.Scan(&g, &sh, &j, &p, &priceFirst, &priceSecond)
	var answer int64 = 0

	if priceFirst <= priceSecond {
		answer = int64(min(min(sh, j), p))
		p -= int(answer)
		answer *= int64(priceSecond)
		answer += int64(min(p, g) * priceFirst)
	} else {
		answer = int64(min(g, p))
		p -= int(answer)
		answer *= int64(priceFirst)
		answer += int64(min(min(sh, j), p) * priceSecond)
	}
	fmt.Println(answer)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Math struct{}

func (m Math) GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return m.GCD(b, a%b)
}

func (m Math) LCM(a, b int) int {
	return a / m.GCD(a, b) * b
}

func (m Math) Log(value float64, base int) float64 {
	return math.Log(value) / math.Log(float64(base))
}

func (m Math) Factorial(number int) int64 {
	if number < 0 {
		return 0
	}
	return m.id8(number)
}

func (m Math) id8(number int) int64 {
	if number > 0 {
		return m.id8(number - 1) * int64(number)
	}
	return 1
}

type Int struct {
	value int
}

func (i Int) CompareTo(o int) int {
	if i.value < o {
		return -1
	} else if i.value == o {
		return 0
	}
	return 1
}

func (i Int) Equals(obj interface{}) bool {
	if o, ok := obj.(int); ok {
		return i.value == o
	}
	return false
}

func (i Int) HashCode() int {
	return i.value
}

type Pair[T any, T1 any] struct {
	first  T
	second T1
}

func NewPair[T any, T1 any](element T, element1 T1) Pair[T, T1] {
	return Pair[T, T1]{first: element, second: element1}
}

func (p Pair[T, T1]) SetFirst(element T) {
	p.first = element
}

func (p Pair[T, T1]) SetSecond(element T1) {
	p.second = element
}

func (p Pair[T, T1]) Equals(obj interface{}) bool {
	if pair, ok := obj.(Pair[T, T1]); ok {
		return p.first == pair.first && p.second == pair.second
	}
	return false
}

func (p Pair[T, T1]) HashCode() int {
	hashCode := 1
	hashCode = 31*hashCode + hash(p.first)
	hashCode = 31*hashCode + hash(p.second)
	return hashCode
}

func hash[T any](v T) int {
	return 0 // Implement a proper hash function if needed
}
