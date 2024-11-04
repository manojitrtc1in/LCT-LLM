package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Int struct {
	arr  []int
	sign int
}

var size int
var max int

func NewInt(a string) *Int {
	arr := make([]int, size+1)
	for i := 0; i <= size; i++ {
		arr[i] = 0
	}
	sign := 0
	if a[0] == '-' {
		sign = 1
		a = a[1:]
	}
	arr[0] = 0
	for len(a) > 9 {
		arr[0]++
		num, _ := strconv.Atoi(a[len(a)-9:])
		arr[arr[0]] = num
		a = a[:len(a)-9]
	}
	arr[0]++
	num, _ := strconv.Atoi(a)
	arr[arr[0]] = num
	return &Int{
		arr:  arr,
		sign: sign,
	}
}

func (a *Int) Copy() *Int {
	arr := make([]int, size+1)
	for i := 0; i <= size; i++ {
		arr[i] = 0
	}
	arr[0] = a.arr[0]
	for i := 1; i <= arr[0]; i++ {
		arr[i] = a.arr[i]
	}
	return &Int{
		arr:  arr,
		sign: a.sign,
	}
}

func (a *Int) Set(b *Int) {
	if a != b {
		a.arr = make([]int, size+1)
		for i := 0; i <= size; i++ {
			a.arr[i] = 0
		}
		a.arr[0] = b.arr[0]
		for i := 1; i <= a.arr[0]; i++ {
			a.arr[i] = b.arr[i]
		}
		a.sign = b.sign
	}
}

func (a *Int) SetString(s string) {
	a.Set(NewInt(s))
}

func (a *Int) String() string {
	res := ""
	if a.sign == 1 {
		res += "-"
	}
	res += strconv.Itoa(a.arr[a.arr[0]])
	for i := a.arr[0] - 1; i >= 1; i-- {
		res += fmt.Sprintf("%09d", a.arr[i])
	}
	return res
}

func (a *Int) GreaterThan(b *Int) bool {
	brr := b.arr
	if a.sign != b.sign {
		return a.sign < b.sign
	}
	if a.sign == 0 {
		if a.arr[0] != brr[0] {
			return a.arr[0] > brr[0]
		}
		for i := a.arr[0]; i >= 1; i-- {
			if a.arr[i] != brr[i] {
				return a.arr[i] > brr[i]
			}
		}
		return false
	}
	if a.arr[0] != brr[0] {
		return a.arr[0] < brr[0]
	}
	for i := a.arr[0]; i >= 1; i-- {
		if a.arr[i] != brr[i] {
			return a.arr[i] < brr[i]
		}
	}
	return false
}

func (a *Int) LessThan(b *Int) bool {
	return b.GreaterThan(a)
}

func (a *Int) EqualTo(b *Int) bool {
	return !(b.GreaterThan(a) || b.LessThan(a))
}

func (a *Int) NotEqualTo(b *Int) bool {
	return !a.EqualTo(b)
}

func (a *Int) LessThanOrEqualTo(b *Int) bool {
	return !a.GreaterThan(b)
}

func (a *Int) GreaterThanOrEqualTo(b *Int) bool {
	return !a.LessThan(b)
}

func (a *Int) Negate() *Int {
	c := a.Copy()
	c.sign = (a.sign + 1) % 2
	return c
}

func (a *Int) Add(b *Int) *Int {
	brr := b.arr
	carry := 0
	c := a.Copy()
	if a.LessThan(NewInt("0")) {
		if b.LessThan(NewInt("0")) {
			if a.arr[0] >= brr[0] {
				for i := 1; i <= brr[0]; i++ {
					c.arr[i] = c.arr[i] + brr[i] + carry
					carry = c.arr[i] / max
					c.arr[i] %= max
				}
				for carry != 0 {
					c.arr[c.arr[0]+1] = c.arr[c.arr[0]+1] + carry
					carry = c.arr[c.arr[0]+1] / max
					c.arr[c.arr[0]+1] %= max
					c.arr[0]++
				}
				if c.arr[0] == a.arr[0]+2 {
					c.arr[0]++
				}
			} else {
				c.Set(b.Add(a))
			}
		} else {
			if a.EqualTo(b.Negate()) {
				c.SetString("0")
			} else if a.Negate().GreaterThan(b) {
				for i := 1; i <= brr[0]; i++ {
					c.arr[i] = c.arr[i] - brr[i] + carry
					if c.arr[i] < 0 {
						carry = -1
						c.arr[i] += max
					} else {
						carry = 0
					}
				}
				for carry != 0 {
					c.arr[c.arr[0]+1] = c.arr[c.arr[0]+1] + carry
					if c.arr[c.arr[0]+1] < 0 {
						carry = -1
						c.arr[c.arr[0]+1] += max
					} else {
						carry = 0
					}
					c.arr[0]++
				}
				for c.arr[c.arr[0]] == 0 && c.arr[0] > 1 {
					c.arr[0]--
				}
			} else {
				c.Set(b.Add(a))
			}
		}
	} else {
		if b.LessThan(NewInt("0")) {
			if a.EqualTo(b.Negate()) {
				c.SetString("0")
			} else if a.GreaterThan(b.Negate()) {
				for i := 1; i <= brr[0]; i++ {
					c.arr[i] = c.arr[i] - brr[i] + carry
					if c.arr[i] < 0 {
						carry = -1
						c.arr[i] += max
					} else {
						carry = 0
					}
				}
				for carry != 0 {
					c.arr[c.arr[0]+1] = c.arr[c.arr[0]+1] + carry
					if c.arr[c.arr[0]+1] < 0 {
						carry = -1
						c.arr[c.arr[0]+1] += max
					} else {
						carry = 0
					}
					c.arr[0]++
				}
				for c.arr[c.arr[0]] == 0 && c.arr[0] > 1 {
					c.arr[0]--
				}
			} else {
				c.Set(b.Add(a))
			}
		} else {
			c.Set(a.Negate().Add(b.Negate()).Negate())
		}
	}
	return c
}

func (a *Int) Subtract(b *Int) *Int {
	return a.Add(b.Negate())
}

func (a *Int) Multiply(b *Int) *Int {
	if b.EqualTo(NewInt("0")) {
		a.SetString("0")
	} else if b.EqualTo(NewInt(strconv.Itoa(max))) {
		if !a.EqualTo(NewInt("0")) {
			for i := a.arr[0]; i >= 1; i-- {
				a.arr[i+1] = a.arr[i]
			}
			a.arr[1] = 0
			a.arr[0]++
		}
	} else if a.Abs().LessThan(NewInt(strconv.Itoa(max))) {
		tmp := int64(0)
		carry := 0
		brr := b.arr
		for i := 1; i <= a.arr[0]; i++ {
			tmp = int64(a.arr[i]) * int64(brr[1]) + int64(carry)
			a.arr[i] = int(tmp % int64(max))
			carry = int(tmp / int64(max))
		}
		if carry != 0 {
			a.arr[a.arr[0]+1] = carry
			a.arr[0]++
		}
	} else {
		tmp := NewInt("0")
		res := NewInt("0")
		brr := b.arr
		for i := brr[0]; i >= 1; i-- {
			tmp.Multiply(a).Multiply(NewInt(strconv.Itoa(brr[i])))
			res.Multiply(NewInt(strconv.Itoa(max))).Add(tmp)
		}
		a.Set(res)
	}
	a.sign = (a.sign + b.sign) % 2
	return a
}

func (a *Int) Abs() *Int {
	if a.LessThan(NewInt("0")) {
		return a.Negate()
	}
	return a
}

func (a *Int) Num(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

func (a *Int) Str(num int) string {
	if num < 0 {
		return "-" + strconv.Itoa(-num)
	}
	return strconv.Itoa(num)
}

func solve(s string, h int) *Int {
	u := make([]bool, 26)
	answer := NewInt("1")
	k := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '?' {
			k++
		}
		if s[i] >= 'A' && s[i] <= 'Z' {
			u[s[i]-'A'] = true
		}
	}
	for i := 0; i < k; i++ {
		qanak++
	}
	k = 0
	for i := 0; i < 26; i++ {
		if u[i] {
			k++
		}
	}
	if k > 10 {
		return NewInt("0")
	}
	for i := 0; i < k; i++ {
		answer.Multiply(NewInt(a.Str(10 - i - h)))
	}
	return answer
}

func main() {
	qanak = 0
	size = 12
	max = 1000000000
	answer := NewInt("0")
	var s string
	fmt.Scan(&s)
	if len(s) == 1 {
		if s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z') {
			answer.SetString("9")
		} else {
			answer.SetString("1")
		}
		fmt.Println(answer)
		return
	}
	if s[0] == '?' {
		st := s[1:]
		answer.Multiply(solve(st))
	} else if s[0] >= 'A' && s[0] <= 'Z' {
		for k := 1; k < 10; k++ {
			st := s
			qanak = 0
			for i := 0; i < len(st); i++ {
				if st[i] == s[0] {
					st[i] = byte('0' + k)
				}
			}
			answer.Add(solve(st, 1))
		}
	} else {
		answer = solve(s)
	}
	fmt.Print(answer)
	for i := 0; i < qanak; i++ {
		fmt.Print(0)
	}
	fmt.Println()
}
