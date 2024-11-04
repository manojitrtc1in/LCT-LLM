package main

import (
	"fmt"
	"math"
)

func main() {
	var g, sh, j, p, priceFirst, priceSecond int
	fmt.Scan(&g, &sh, &j, &p, &priceFirst, &priceSecond)
	var answer int64

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

func (m Math) GCDLong(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return m.GCDLong(b, a%b)
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
	return m.solveFactorial(number)
}

func (m Math) solveFactorial(number int) int64 {
	if number > 0 {
		return m.solveFactorial(number - 1) * int64(number)
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

type Fraction struct {
	dividend, divider int
}

func NewFraction(dividend, divider int) Fraction {
	f := Fraction{dividend: dividend, divider: divider}
	f.reduce()
	return f
}

func (f *Fraction) reduce() {
	gcd := Math{}.GCD(f.dividend, f.divider)
	f.dividend /= gcd
	f.divider /= gcd
}

func (f *Fraction) AddWithoutReturn(number Fraction) {
	f.Add(number, 0)
}

func (f *Fraction) Add(number Fraction, function int) Fraction {
	var result Fraction
	lcm := Math{}.LCM(f.divider, number.divider)
	if function == 0 {
		f.dividend = (lcm/f.divider)*f.dividend + (lcm/number.divider)*number.dividend
		f.divider = lcm
		f.reduce()
		return result
	}
	result = NewFraction((lcm/f.divider)*f.dividend+(lcm/number.divider)*number.dividend, lcm)
	result.reduce()
	return result
}

func (f *Fraction) MultiplyWithoutReturn(number Fraction) {
	f.Multiply(number, 0)
}

func (f *Fraction) Multiply(number Fraction, function int) Fraction {
	var result Fraction
	first := f.dividend * number.dividend
	second := f.divider * number.divider
	if function == 0 {
		f.dividend = first
		f.divider = second
		f.reduce()
		return result
	}
	result = NewFraction(first, second)
	result.reduce()
	return result
}
