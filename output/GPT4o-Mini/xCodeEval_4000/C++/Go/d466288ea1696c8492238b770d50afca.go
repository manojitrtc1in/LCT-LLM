package main

import (
	"fmt"
	"math/big"
	"strings"
)

var qanak int

type Int struct {
	arr  []*big.Int
	sign int
}

var size int
var max = big.NewInt(1000000000)

func NewInt(a string) *Int {
	i := 0
	arr := make([]*big.Int, size+1)
	for i = 0; i <= size; i++ {
		arr[i] = big.NewInt(0)
	}
	sign := 0
	if a[0] == '-' {
		sign = 1
		a = a[1:]
	}
	arr[0] = big.NewInt(0)
	for len(a) > 9 {
		arr[0].SetInt64(arr[0].Int64() + 1)
		arr[arr[0].Int64()] = num(a[len(a)-9:])
		a = a[:len(a)-9]
	}
	arr[0].SetInt64(arr[0].Int64() + 1)
	arr[arr[0].Int64()] = num(a)
	return &Int{arr: arr, sign: sign}
}

func (a *Int) Greater(b *Int) bool {
	if a.sign != b.sign {
		return a.sign < b.sign
	}
	if a.sign == 0 {
		if a.arr[0].Cmp(b.arr[0]) != 0 {
			return a.arr[0].Cmp(b.arr[0]) > 0
		}
		for i := a.arr[0].Int64(); i >= 1; i-- {
			if a.arr[i].Cmp(b.arr[i]) != 0 {
				return a.arr[i].Cmp(b.arr[i]) > 0
			}
		}
		return false
	}
	if a.arr[0].Cmp(b.arr[0]) != 0 {
		return a.arr[0].Cmp(b.arr[0]) < 0
	}
	for i := a.arr[0].Int64(); i >= 1; i-- {
		if a.arr[i].Cmp(b.arr[i]) != 0 {
			return a.arr[i].Cmp(b.arr[i]) < 0
		}
	}
	return false
}

func (a *Int) Less(b *Int) bool {
	return b.Greater(a)
}

func (a *Int) Equal(b *Int) bool {
	return !(b.Greater(a) || b.Less(a))
}

func (a *Int) NotEqual(b *Int) bool {
	return !a.Equal(b)
}

func (a *Int) LessEqual(b *Int) bool {
	return !a.Greater(b)
}

func (a *Int) GreaterEqual(b *Int) bool {
	return !a.Less(b)
}

func (a *Int) Negate() *Int {
	c := *a
	c.sign = (a.sign + 1) % 2
	return &c
}

func (a *Int) Add(b *Int) *Int {
	c := NewInt("0")
	c.sign = a.sign
	c.arr[0] = big.NewInt(0)

	carry := big.NewInt(0)
	if a.Less(NewInt("0")) {
		if b.Less(NewInt("0")) {
			if a.arr[0].Cmp(b.arr[0]) >= 0 {
				for i := int64(1); i <= b.arr[0].Int64(); i++ {
					c.arr[i] = new(big.Int).Set(a.arr[i])
					c.arr[i].Add(c.arr[i], b.arr[i])
					carry.Set(c.arr[i].Div(c.arr[i], max))
					c.arr[i].Mod(c.arr[i], max)
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					c.arr[i] = new(big.Int).Set(carry)
					carry.Set(c.arr[i].Div(c.arr[i], max))
					c.arr[i].Mod(c.arr[i], max)
					i++
				}
				if i == c.arr[0].Int64()+2 {
					c.arr[0].SetInt64(c.arr[0].Int64() + 1)
				}
			} else {
				c = *b.Add(a)
			}
		} else {
			if a.Equal(b.Negate()) {
				c = *NewInt("0")
			} else if a.Negate().Greater(b) {
				for i := int64(1); i <= b.arr[0].Int64(); i++ {
					c.arr[i] = new(big.Int).Set(a.arr[i])
					c.arr[i].Sub(c.arr[i], b.arr[i])
					if c.arr[i].Cmp(big.NewInt(0)) < 0 {
						carry.SetInt64(-1)
						c.arr[i].Add(c.arr[i], max)
					} else {
						carry.SetInt64(0)
					}
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					c.arr[i].Add(c.arr[i], carry)
					if c.arr[i].Cmp(big.NewInt(0)) < 0 {
						carry.SetInt64(-1)
						c.arr[i].Add(c.arr[i], max)
					} else {
						carry.SetInt64(0)
					}
					i++
				}
				for c.arr[c.arr[0].Int64()].Cmp(big.NewInt(0)) == 0 && c.arr[0].Int64() > 1 {
					c.arr[0].SetInt64(c.arr[0].Int64() - 1)
				}
			} else {
				c = *b.Add(a)
			}
		}
	} else {
		if b.Less(NewInt("0")) {
			if a.Equal(b.Negate()) {
				c = *NewInt("0")
			} else if a.Greater(b.Negate()) {
				for i := int64(1); i <= b.arr[0].Int64(); i++ {
					c.arr[i] = new(big.Int).Set(a.arr[i])
					c.arr[i].Sub(c.arr[i], b.arr[i])
					if c.arr[i].Cmp(big.NewInt(0)) < 0 {
						carry.SetInt64(-1)
						c.arr[i].Add(c.arr[i], max)
					} else {
						carry.SetInt64(0)
					}
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					c.arr[i].Add(c.arr[i], carry)
					if c.arr[i].Cmp(big.NewInt(0)) < 0 {
						carry.SetInt64(-1)
						c.arr[i].Add(c.arr[i], max)
					} else {
						carry.SetInt64(0)
					}
					i++
				}
				for c.arr[c.arr[0].Int64()].Cmp(big.NewInt(0)) == 0 && c.arr[0].Int64() > 1 {
					c.arr[0].SetInt64(c.arr[0].Int64() - 1)
				}
			} else {
				c = *b.Add(a)
			}
		} else {
			c = *b.Negate().Add(a.Negate())
		}
	}
	return &c
}

func (a *Int) Multiply(b *Int) *Int {
	c := NewInt("0")
	if b.Equal(NewInt("0")) {
		c = *NewInt("0")
	} else if b.Equal(NewInt(max.String())) {
		if a.Equal(NewInt("0")) {
			c = *NewInt("0")
		} else {
			for i := a.arr[0].Int64(); i >= 1; i-- {
				c.arr[i+1] = new(big.Int).Set(a.arr[i])
			}
			c.arr[1] = big.NewInt(0)
			c.arr[0].SetInt64(c.arr[0].Int64() + 1)
		}
	} else if a.Less(NewInt(max.String())) {
		tmp := new(big.Int)
		carry := big.NewInt(0)
		for i := int64(1); i <= a.arr[0].Int64(); i++ {
			tmp.Set(new(big.Int).Mul(a.arr[i], b.arr[1]))
			tmp.Add(tmp, carry)
			c.arr[i].Set(tmp.Mod(tmp, max))
			carry.Set(tmp.Div(tmp, max))
		}
		if carry.Cmp(big.NewInt(0)) != 0 {
			c.arr[i] = new(big.Int).Set(carry)
			c.arr[0].SetInt64(c.arr[0].Int64() + 1)
		}
	} else {
		tmp := NewInt("0")
		res := NewInt("0")
		for i := b.arr[0].Int64(); i >= 1; i-- {
			tmp = a.Multiply(NewInt(b.arr[i].String()))
			res = res.Multiply(NewInt(max.String())).Add(tmp)
		}
		c = res
	}
	c.sign = (a.sign + b.sign) % 2
	return c
}

func (a *Int) ToString() string {
	var res strings.Builder
	if a.sign == 1 {
		res.WriteString("-")
	}
	res.WriteString(a.arr[a.arr[0].Int64()].String())
	for i := a.arr[0].Int64() - 1; i >= 1; i-- {
		k := max
		for j := 0; j < 9; j++ {
			res.WriteString(fmt.Sprintf("%d", new(big.Int).Div(a.arr[i], k).Int64()))
			k.Div(k, big.NewInt(10))
		}
	}
	return res.String()
}

func num(a string) *big.Int {
	res := big.NewInt(0)
	for _, char := range a {
		res.Mul(res, big.NewInt(10))
		res.Add(res, big.NewInt(int64(char-'0')))
	}
	return res
}

func abs(a *Int) *Int {
	if a.Less(NewInt("0")) {
		return a.Negate()
	}
	return a
}

func solve(s string, h int) *Int {
	u := make([]bool, 26)
	answer := NewInt("1")
	k := 0
	for _, char := range s {
		if char == '?' {
			k++
		}
		if char >= 'A' && char <= 'Z' {
			u[char-'A'] = true
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
		answer = answer.Multiply(NewInt(fmt.Sprintf("%d", 10-i-h)))
	}
	return answer
}

func main() {
	qanak = 0
	size = 12
	answer := NewInt("0")
	var s string
	fmt.Scan(&s)
	if len(s) == 1 {
		if s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z') {
			answer = NewInt("9")
		} else {
			answer = NewInt("1")
		}
		fmt.Println(answer.ToString())
		return
	}
	if s[0] == '?' {
		st := s[1:]
		answer = answer.Multiply(solve(st, 0))
	} else if s[0] >= 'A' && s[0] <= 'Z' {
		for k := 1; k < 10; k++ {
			st := s
			qanak = 0
			for i := 0; i < len(st); i++ {
				if st[i] == s[0] {
					st = st[:i] + string('0'+k) + st[i+1:]
				}
			}
			answer = answer.Add(solve(st, 1))
		}
	} else {
		answer = solve(s, 0)
	}
	fmt.Print(answer.ToString())
	for i := 0; i < qanak; i++ {
		fmt.Print("0")
	}
	fmt.Println()
}
