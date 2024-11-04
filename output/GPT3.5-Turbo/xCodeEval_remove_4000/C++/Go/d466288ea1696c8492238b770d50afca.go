package main

import (
	"fmt"
	"strings"
)

type Int struct {
	arr  []int
	sign int
}

var size int
var max int = 1000000000

func NewInt(a string) *Int {
	i := 0
	arr := make([]int, size+1)
	for i <= size {
		arr[i] = 0
		i++
	}
	sign := 0
	if a[0] == '-' {
		sign = 1
		a = a[1:]
	}
	arr[0] = 0
	for len(a) > 9 {
		arr[0]++
		arr[arr[0]] = num(a[len(a)-9:])
		a = a[:len(a)-9]
	}
	arr[0]++
	arr[arr[0]] = num(a)
	return &Int{arr: arr, sign: sign}
}

func (a *Int) Copy() *Int {
	arr := make([]int, size+1)
	copy(arr, a.arr)
	return &Int{arr: arr, sign: a.sign}
}

func (a *Int) Set(b *Int) {
	a.arr = make([]int, size+1)
	copy(a.arr, b.arr)
	a.sign = b.sign
}

func (a *Int) SetString(s string) {
	a.Set(NewInt(s))
}

func (a *Int) String() string {
	res := ""
	if a.sign == 1 {
		res += "-"
	}
	res += str(a.arr[a.arr[0]])
	for i := a.arr[0] - 1; i >= 1; i-- {
		k := max
		for j := 0; j < 9; j++ {
			res += str((a.arr[i]%k)/(k/10))
			k /= 10
		}
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

func (a *Int) GreaterThanString(s string) bool {
	return a.GreaterThan(NewInt(s))
}

func (a *Int) LessThanString(s string) bool {
	return NewInt(s).GreaterThan(a)
}

func (a *Int) EqualToString(s string) bool {
	return !(NewInt(s).GreaterThan(a) || NewInt(s).LessThan(a))
}

func (a *Int) NotEqualToString(s string) bool {
	return !a.EqualToString(s)
}

func (a *Int) LessThanOrEqualToString(s string) bool {
	return !a.GreaterThan(NewInt(s))
}

func (a *Int) GreaterThanOrEqualToString(s string) bool {
	return !a.LessThan(NewInt(s))
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
					c.arr[i] = c.arr[i] + carry
					carry = c.arr[i] / max
					c.arr[i] %= max
					i++
				}
				if i == c.arr[0]+2 {
					c.arr[0]++
				}
			} else {
				d := a.Copy()
				c.Set(d.Add(b))
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
					c.arr[i] = c.arr[i] + carry
					if c.arr[i] < 0 {
						carry = -1
						c.arr[i] += max
					} else {
						carry = 0
					}
					i++
				}
				for c.arr[c.arr[0]] == 0 && c.arr[0] > 1 {
					c.arr[0]--
				}
			} else {
				d := a.Copy()
				c.Set(d.Add(b))
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
					c.arr[i] = c.arr[i] + carry
					if c.arr[i] < 0 {
						carry = -1
						c.arr[i] += max
					} else {
						carry = 0
					}
					i++
				}
				for c.arr[c.arr[0]] == 0 && c.arr[0] > 1 {
					c.arr[0]--
				}
			} else {
				d := a.Copy()
				c.Set(d.Add(b))
			}
		} else {
			d := a.Negate()
			e := b.Negate()
			c.Set(e.Add(d))
		}
	}
	return c
}

func (a *Int) AddString(s string) *Int {
	return a.Add(NewInt(s))
}

func (a *Int) Sub(b *Int) *Int {
	return a.Add(b.Negate())
}

func (a *Int) SubString(s string) *Int {
	return a.Sub(NewInt(s))
}

func (a *Int) Mul(b *Int) *Int {
	if b.EqualTo(NewInt("0")) {
		a.SetString("0")
	} else if b.EqualTo(NewInt(str(max))) {
		if !a.EqualTo(NewInt("0")) {
			i := a.arr[0]
			for i >= 1 {
				a.arr[i+1] = a.arr[i]
				i--
			}
			a.arr[1] = 0
			a.arr[0]++
		}
	} else if abs(b).LessThan(NewInt(str(max))) {
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
			tmp.Mul(a, NewInt(str(brr[i])))
			res.Mul(res, NewInt(str(max))).Add(tmp)
		}
		a.Set(res)
	}
	a.sign = (a.sign + b.sign) % 2
	return a
}

func (a *Int) MulString(s string) *Int {
	return a.Mul(NewInt(s))
}

func (a *Int) MulInt(k int) *Int {
	return a.Mul(NewInt(str(k)))
}

func (a *Int) MulInt64(k int64) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulInt32(k int32) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulInt16(k int16) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulInt8(k int8) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulUint(k uint) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulUint64(k uint64) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulUint32(k uint32) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulUint16(k uint16) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulUint8(k uint8) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulFloat32(k float32) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulFloat64(k float64) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulComplex64(k complex64) *Int {
	return a.Mul(NewInt(str(int(real(k)))))
}

func (a *Int) MulComplex128(k complex128) *Int {
	return a.Mul(NewInt(str(int(real(k)))))
}

func (a *Int) MulRune(k rune) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulByte(k byte) *Int {
	return a.Mul(NewInt(str(int(k))))
}

func (a *Int) MulStringSlice(k []string) *Int {
	return a.Mul(NewInt(strings.Join(k, "")))
}

func (a *Int) MulIntSlice(k []int) *Int {
	return a.Mul(NewInt(strings.Join(intSliceToStringSlice(k), "")))
}

func (a *Int) MulInt64Slice(k []int64) *Int {
	return a.Mul(NewInt(strings.Join(int64SliceToStringSlice(k), "")))
}

func (a *Int) MulInt32Slice(k []int32) *Int {
	return a.Mul(NewInt(strings.Join(int32SliceToStringSlice(k), "")))
}

func (a *Int) MulInt16Slice(k []int16) *Int {
	return a.Mul(NewInt(strings.Join(int16SliceToStringSlice(k), "")))
}

func (a *Int) MulInt8Slice(k []int8) *Int {
	return a.Mul(NewInt(strings.Join(int8SliceToStringSlice(k), "")))
}

func (a *Int) MulUintSlice(k []uint) *Int {
	return a.Mul(NewInt(strings.Join(uintSliceToStringSlice(k), "")))
}

func (a *Int) MulUint64Slice(k []uint64) *Int {
	return a.Mul(NewInt(strings.Join(uint64SliceToStringSlice(k), "")))
}

func (a *Int) MulUint32Slice(k []uint32) *Int {
	return a.Mul(NewInt(strings.Join(uint32SliceToStringSlice(k), "")))
}

func (a *Int) MulUint16Slice(k []uint16) *Int {
	return a.Mul(NewInt(strings.Join(uint16SliceToStringSlice(k), "")))
}

func (a *Int) MulUint8Slice(k []uint8) *Int {
	return a.Mul(NewInt(strings.Join(uint8SliceToStringSlice(k), "")))
}

func (a *Int) MulFloat32Slice(k []float32) *Int {
	return a.Mul(NewInt(strings.Join(float32SliceToStringSlice(k), "")))
}

func (a *Int) MulFloat64Slice(k []float64) *Int {
	return a.Mul(NewInt(strings.Join(float64SliceToStringSlice(k), "")))
}

func (a *Int) MulComplex64Slice(k []complex64) *Int {
	return a.Mul(NewInt(strings.Join(complex64SliceToStringSlice(k), "")))
}

func (a *Int) MulComplex128Slice(k []complex128) *Int {
	return a.Mul(NewInt(strings.Join(complex128SliceToStringSlice(k), "")))
}

func (a *Int) MulRuneSlice(k []rune) *Int {
	return a.Mul(NewInt(strings.Join(runeSliceToStringSlice(k), "")))
}

func (a *Int) MulByteSlice(k []byte) *Int {
	return a.Mul(NewInt(strings.Join(byteSliceToStringSlice(k), "")))
}

func (a *Int) MulStringSliceSlice(k [][]string) *Int {
	return a.Mul(NewInt(strings.Join(stringSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulIntSliceSlice(k [][]int) *Int {
	return a.Mul(NewInt(strings.Join(intSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt64SliceSlice(k [][]int64) *Int {
	return a.Mul(NewInt(strings.Join(int64SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt32SliceSlice(k [][]int32) *Int {
	return a.Mul(NewInt(strings.Join(int32SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt16SliceSlice(k [][]int16) *Int {
	return a.Mul(NewInt(strings.Join(int16SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt8SliceSlice(k [][]int8) *Int {
	return a.Mul(NewInt(strings.Join(int8SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUintSliceSlice(k [][]uint) *Int {
	return a.Mul(NewInt(strings.Join(uintSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint64SliceSlice(k [][]uint64) *Int {
	return a.Mul(NewInt(strings.Join(uint64SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint32SliceSlice(k [][]uint32) *Int {
	return a.Mul(NewInt(strings.Join(uint32SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint16SliceSlice(k [][]uint16) *Int {
	return a.Mul(NewInt(strings.Join(uint16SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint8SliceSlice(k [][]uint8) *Int {
	return a.Mul(NewInt(strings.Join(uint8SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulFloat32SliceSlice(k [][]float32) *Int {
	return a.Mul(NewInt(strings.Join(float32SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulFloat64SliceSlice(k [][]float64) *Int {
	return a.Mul(NewInt(strings.Join(float64SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulComplex64SliceSlice(k [][]complex64) *Int {
	return a.Mul(NewInt(strings.Join(complex64SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulComplex128SliceSlice(k [][]complex128) *Int {
	return a.Mul(NewInt(strings.Join(complex128SliceSliceToStringSlice(k), "")))
}

func (a *Int) MulRuneSliceSlice(k [][]rune) *Int {
	return a.Mul(NewInt(strings.Join(runeSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulByteSliceSlice(k [][]byte) *Int {
	return a.Mul(NewInt(strings.Join(byteSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulStringSliceSliceSlice(k [][][]string) *Int {
	return a.Mul(NewInt(strings.Join(stringSliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulIntSliceSliceSlice(k [][][]int) *Int {
	return a.Mul(NewInt(strings.Join(intSliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt64SliceSliceSlice(k [][][]int64) *Int {
	return a.Mul(NewInt(strings.Join(int64SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt32SliceSliceSlice(k [][][]int32) *Int {
	return a.Mul(NewInt(strings.Join(int32SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt16SliceSliceSlice(k [][][]int16) *Int {
	return a.Mul(NewInt(strings.Join(int16SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulInt8SliceSliceSlice(k [][][]int8) *Int {
	return a.Mul(NewInt(strings.Join(int8SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUintSliceSliceSlice(k [][][]uint) *Int {
	return a.Mul(NewInt(strings.Join(uintSliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint64SliceSliceSlice(k [][][]uint64) *Int {
	return a.Mul(NewInt(strings.Join(uint64SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint32SliceSliceSlice(k [][][]uint32) *Int {
	return a.Mul(NewInt(strings.Join(uint32SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint16SliceSliceSlice(k [][][]uint16) *Int {
	return a.Mul(NewInt(strings.Join(uint16SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulUint8SliceSliceSlice(k [][][]uint8) *Int {
	return a.Mul(NewInt(strings.Join(uint8SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulFloat32SliceSliceSlice(k [][][]float32) *Int {
	return a.Mul(NewInt(strings.Join(float32SliceSliceSliceToStringSlice(k), "")))
}

func (a *Int) MulFloat64SliceSliceSlice(k [][][]float64) *Int {
