package main

import (
	"fmt"
	"math/big"
	"strings"
)

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
		arr[0].Set(arr[0].Add(arr[0], big.NewInt(1)))
		arr[arr[0].Int64()] = num(a[len(a)-9:])
		a = a[:len(a)-9]
	}
	arr[0].Set(arr[0].Add(arr[0], big.NewInt(1)))
	arr[arr[0].Int64()] = num(a)
	return &Int{arr: arr, sign: sign}
}

func (a *Int) Copy() *Int {
	arr := make([]*big.Int, size+1)
	for i := 0; i <= size; i++ {
		arr[i] = big.NewInt(0)
	}
	arr[0] = new(big.Int).Set(a.arr[0])
	for i := int64(1); i <= arr[0].Int64(); i++ {
		arr[i] = new(big.Int).Set(a.arr[i])
	}
	return &Int{arr: arr, sign: a.sign}
}

func (a *Int) SetSign(k int) {
	a.sign = k
}

func (a *Int) GetSign() int {
	return a.sign
}

func (a *Int) GetArr() []*big.Int {
	return a.arr
}

func (a *Int) IsGreater(b *Int) bool {
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

func (a *Int) IsLess(b *Int) bool {
	return b.IsGreater(a)
}

func (a *Int) IsEqual(b *Int) bool {
	return !(b.IsGreater(a) || b.IsLess(a))
}

func (a *Int) IsNotEqual(b *Int) bool {
	return !a.IsEqual(b)
}

func (a *Int) IsLessOrEqual(b *Int) bool {
	return !a.IsGreater(b)
}

func (a *Int) IsGreaterOrEqual(b *Int) bool {
	return !a.IsLess(b)
}

func (a *Int) Negate() *Int {
	c := a.Copy()
	c.SetSign((a.sign + 1) % 2)
	return c
}

func (a *Int) Add(b *Int) *Int {
	carry := big.NewInt(0)
	i := int64(0)
	if a.IsLess(NewInt("0")) {
		if b.IsLess(NewInt("0")) {
			if a.arr[0].Cmp(b.arr[0]) >= 0 {
				for i = 1; i <= b.arr[0].Int64(); i++ {
					a.arr[i].Set(a.arr[i].Add(a.arr[i], b.arr[i]))
					a.arr[i].Set(a.arr[i].Add(a.arr[i], carry))
					carry.Set(a.arr[i].Div(a.arr[i], max))
					a.arr[i].Mod(a.arr[i], max)
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					a.arr[i].Set(a.arr[i].Add(a.arr[i], carry))
					carry.Set(a.arr[i].Div(a.arr[i], max))
					a.arr[i].Mod(a.arr[i], max)
					i++
				}
				if i == a.arr[0].Int64()+2 {
					a.arr[0].Set(a.arr[0].Add(a.arr[0], big.NewInt(1)))
				}
			} else {
				c := a.Copy()
				d := b.Copy()
				return d.Add(c)
			}
		} else {
			if a.IsEqual(b.Negate()) {
				return NewInt("0")
			} else if a.Negate().IsGreater(b) {
				for i = 1; i <= b.arr[0].Int64(); i++ {
					a.arr[i].Set(a.arr[i].Sub(a.arr[i], b.arr[i]))
					if a.arr[i].Cmp(big.NewInt(0)) < 0 {
						a.arr[i].Set(a.arr[i].Add(a.arr[i], max))
						carry.Set(big.NewInt(-1))
					} else {
						carry.Set(big.NewInt(0))
					}
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					a.arr[i].Set(a.arr[i].Add(a.arr[i], carry))
					if a.arr[i].Cmp(big.NewInt(0)) < 0 {
						a.arr[i].Set(a.arr[i].Add(a.arr[i], max))
						carry.Set(big.NewInt(-1))
					} else {
						carry.Set(big.NewInt(0))
					}
					i++
				}
				for a.arr[a.arr[0].Int64()].Cmp(big.NewInt(0)) == 0 && a.arr[0].Cmp(big.NewInt(1)) > 0 {
					a.arr[0].Set(a.arr[0].Sub(a.arr[0], big.NewInt(1)))
				}
			} else {
				c := a.Copy()
				d := b.Copy()
				return d.Add(c)
			}
		}
	} else {
		if b.IsLess(NewInt("0")) {
			if a.IsEqual(b.Negate()) {
				return NewInt("0")
			} else if a.IsGreater(b.Negate()) {
				for i = 1; i <= b.arr[0].Int64(); i++ {
					a.arr[i].Set(a.arr[i].Sub(a.arr[i], b.arr[i]))
					if a.arr[i].Cmp(big.NewInt(0)) < 0 {
						a.arr[i].Set(a.arr[i].Add(a.arr[i], max))
						carry.Set(big.NewInt(-1))
					} else {
						carry.Set(big.NewInt(0))
					}
				}
				for carry.Cmp(big.NewInt(0)) != 0 {
					a.arr[i].Set(a.arr[i].Add(a.arr[i], carry))
					if a.arr[i].Cmp(big.NewInt(0)) < 0 {
						a.arr[i].Set(a.arr[i].Add(a.arr[i], max))
						carry.Set(big.NewInt(-1))
					} else {
						carry.Set(big.NewInt(0))
					}
					i++
				}
				for a.arr[a.arr[0].Int64()].Cmp(big.NewInt(0)) == 0 && a.arr[0].Cmp(big.NewInt(1)) > 0 {
					a.arr[0].Set(a.arr[0].Sub(a.arr[0], big.NewInt(1)))
				}
			} else {
				c := a.Copy()
				d := b.Copy()
				return c.Negate().Add(d.Negate())
			}
		} else {
			c := a.Negate()
			d := b.Negate()
			return c.Add(d)
		}
	}
	return a
}

func (a *Int) Multiply(b *Int) *Int {
	if b.IsEqual(NewInt("0")) {
		return NewInt("0")
	} else if b.IsEqual(NewInt(max.String())) {
		if a.IsEqual(NewInt("0")) {
			return NewInt("0")
		}
		for i := a.arr[0].Int64(); i >= 1; i-- {
			a.arr[i+1].Set(a.arr[i])
		}
		a.arr[1] = big.NewInt(0)
		a.arr[0].Set(a.arr[0].Add(a.arr[0], big.NewInt(1)))
	} else if a.IsLess(NewInt(max.String())) {
		tmp := new(big.Int)
		carry := big.NewInt(0)
		brr := b.GetArr()
		for i := int64(1); i <= a.arr[0].Int64(); i++ {
			tmp.Set(new(big.Int).Mul(a.arr[i], brr[1]))
			tmp.Add(tmp, carry)
			a.arr[i].Set(tmp.Mod(tmp, max))
			carry.Set(tmp.Div(tmp, max))
		}
		if carry.Cmp(big.NewInt(0)) != 0 {
			a.arr[i].Set(carry)
			a.arr[0].Set(a.arr[0].Add(a.arr[0], big.NewInt(1)))
		}
	} else {
		tmp := NewInt("0")
		res := NewInt("0")
		brr := b.GetArr()
		for i := brr[0].Int64(); i >= 1; i-- {
			tmp = a.Multiply(NewInt(brr[i].String()))
			res = res.Multiply(NewInt(max.String()))
			res.Add(tmp)
		}
		a = res
	}
	a.SetSign((a.GetSign() + b.GetSign()) % 2)
	return a
}

func (a *Int) ToString() string {
	var res strings.Builder
	if a.sign == 1 {
		res.WriteString("-")
	}
	res.WriteString(str(a.arr[a.arr[0].Int64()].Int64()))
	for i := a.arr[0].Int64() - 1; i >= 1; i-- {
		k := max.Int64()
		for j := 0; j < 9; j++ {
			res.WriteString(str(a.arr[i].Int64() % k / (k /= 10)))
		}
	}
	return res.String()
}

func num(a string) *big.Int {
	res := big.NewInt(0)
	for i := 0; i < len(a); i++ {
		res.Set(res.Mul(res, big.NewInt(10)))
		res.Set(res.Add(res, big.NewInt(int64(a[i]-'0'))))
	}
	return res
}

func str(a int64) string {
	if a == 0 {
		return "0"
	}
	res := ""
	h := 0
	if a < 0 {
		h = 1
		a = -a
	}
	for a != 0 {
		res = string(a%10+'0') + res
		a /= 10
	}
	if h == 1 {
		res = "-" + res
	}
	return res
}

var qanak int

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
		answer.Multiply(NewInt(str(10 - i - h)))
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
		answer = NewInt("9").Multiply(solve(st, 0))
	} else if s[0] >= 'A' && s[0] <= 'Z' {
		for k := 1; k < 10; k++ {
			st := s
			qanak = 0
			for i := 0; i < len(st); i++ {
				if st[i] == s[0] {
					st = st[:i] + string('0'+k) + st[i+1:]
				}
			}
			answer.Add(solve(st, 1))
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
