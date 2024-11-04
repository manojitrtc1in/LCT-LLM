package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type modint int

func (a modint) add(b modint) modint {
	return (a + b) % mod
}

func (a modint) sub(b modint) modint {
	return (a - b + mod) % mod
}

func (a modint) mul(b modint) modint {
	return (a * b) % mod
}

func (a modint) pow(b int) modint {
	res := modint(1)
	for b > 0 {
		if b&1 == 1 {
			res = res.mul(a)
		}
		a = a.mul(a)
		b >>= 1
	}
	return res
}

func (a modint) inv() modint {
	return a.pow(mod - 2)
}

func (a modint) div(b modint) modint {
	return a.mul(b.inv())
}

func (a modint) equal(b modint) bool {
	return a == b
}

func (a modint) notEqual(b modint) bool {
	return a != b
}

func (a modint) lessThan(b modint) bool {
	return a < b
}

func (a modint) lessThanOrEqual(b modint) bool {
	return a <= b
}

func (a modint) greaterThan(b modint) bool {
	return a > b
}

func (a modint) greaterThanOrEqual(b modint) bool {
	return a >= b
}

func (a modint) toString() string {
	return fmt.Sprintf("%d", a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toInt() int {
	return int(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint() uint {
	return uint(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
	return complex(float64(a), 0)
}

func (a modint) toByte() byte {
	return byte(a)
}

func (a modint) toRune() rune {
	return rune(a)
}

func (a modint) toInt8() int8 {
	return int8(a)
}

func (a modint) toInt16() int16 {
	return int16(a)
}

func (a modint) toInt32() int32 {
	return int32(a)
}

func (a modint) toInt64() int64 {
	return int64(a)
}

func (a modint) toUint8() uint8 {
	return uint8(a)
}

func (a modint) toUint16() uint16 {
	return uint16(a)
}

func (a modint) toUint32() uint32 {
	return uint32(a)
}

func (a modint) toUint64() uint64 {
	return uint64(a)
}

func (a modint) toFloat32() float32 {
	return float32(a)
}

func (a modint) toFloat64() float64 {
	return float64(a)
}

func (a modint) toComplex64() complex64 {
	return complex(float32(a), 0)
}

func (a modint) toComplex128() complex128 {
