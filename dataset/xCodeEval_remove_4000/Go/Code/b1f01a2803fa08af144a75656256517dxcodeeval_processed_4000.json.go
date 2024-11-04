package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"unicode/utf8"
)

type Number interface {
	int | int8 | int16 | int32 | int64 | float32 | float64 | byte | uint | uint16 | uint32 | uint64
}

var (
	scanner  *bufio.Scanner
	byWord   bool   

	eof      bool   

	splitter string 

)

func id9(n int) byte {
	return byte('a' + n - 1)
}

func reverse(s string) string {
	size := len(s)
	buf := make([]byte, size)
	for start := 0; start < size; {
		r, n := utf8.DecodeRuneInString(s[start:])
		start += n
		utf8.EncodeRune(buf[size-start:], r)
	}
	return string(buf)
}

func toInt(b byte) int {
	return int(b - '0')
}



func main() {
	for q := Int(); q > 0; q-- {
		n := Int()
		code := Word()
		ans := make([]byte, 0)
		for i := n - 1; i >= 0; i-- {
			if code[i] == '0' {
				ans = append(ans, id9(10*toInt(code[i-2])+toInt(code[i-1])))
				i -= 2
			} else {
				ans = append(ans, id9(toInt(code[i])))
			}
		}
		fmt.Println(reverse(string(ans)))
	}
}



func abs[T Number](a T) T {
	if a > 0 {
		return a
	}
	return -a
}

func min[T Number](a, b T) T {
	if a < b {
		return a
	}
	return b
}

func max[T Number](a, b T) T {
	if a > b {
		return a
	}
	return b
}



func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(id57)
	eof = false
	splitter = " "
}



func id57(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if byWord {
		return bufio.ScanWords(data, atEOF)
	}
	return bufio.ScanLines(data, atEOF)
}



func text(byword bool) string {
	byWord = byword
	if scanner.Scan() {
		return scanner.Text()
	}
	eof = true 

	return ""
}



func EOF() bool {
	return eof
}



func Word() string {
	return text(true)
}



func Words() []string {
	return strings.Split(Line(), splitter)
}



func Line() string {
	return text(false)
}



func Lines() []string {
	var ret []string
	for {
		l := Line()
		if EOF() {
			break
		}
		ret = append(ret, l)
	}
	return ret
}

func Byte() byte {
	return byte(Uint8())
}



func Int() int {
	ret, _ := strconv.ParseInt(Word(), 10, 0)
	return int(ret)
}

func Ints() []int {
	words := Words()
	n := len(words)
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseInt(words[i], 10, 0)
		ret[i] = int(v)
	}
	return ret
}

func Ints2() (int, int) {
	return Int(), Int()
}

func Ints3() (int, int, int) {
	return Int(), Int(), Int()
}

func Ints4() (int, int, int, int) {
	return Int(), Int(), Int(), Int()
}

func Ints5() (int, int, int, int, int) {
	return Int(), Int(), Int(), Int(), Int()
}

func Ints6() (int, int, int, int, int, int) {
	return Int(), Int(), Int(), Int(), Int(), Int()
}

func Ints7() (int, int, int, int, int, int, int) {
	return Int(), Int(), Int(), Int(), Int(), Int(), Int()
}

func Ints8() (int, int, int, int, int, int, int, int) {
	return Int(), Int(), Int(), Int(), Int(), Int(), Int(), Int()
}

func Ints9() (int, int, int, int, int, int, int, int, int) {
	return Int(), Int(), Int(), Int(), Int(), Int(), Int(), Int(), Int()
}

func IntsN(n int) []int {
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		ret[i] = Int()
	}
	return ret
}

func Int8() int8 {
	ret, _ := strconv.ParseInt(Word(), 10, 8)
	return int8(ret)
}

func id104() []int8 {
	words := Words()
	n := len(words)
	ret := make([]int8, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseInt(words[i], 10, 8)
		ret[i] = int8(v)
	}
	return ret
}

func id35() (int8, int8) {
	return Int8(), Int8()
}

func id90() (int8, int8, int8) {
	return Int8(), Int8(), Int8()
}

func id103() (int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8()
}

func id11() (int8, int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8(), Int8()
}

func id4() (int8, int8, int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8(), Int8(), Int8()
}

func id94() (int8, int8, int8, int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8()
}

func id13() (int8, int8, int8, int8, int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8()
}

func id42() (int8, int8, int8, int8, int8, int8, int8, int8, int8) {
	return Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8(), Int8()
}

func id34(n int) []int8 {
	ret := make([]int8, n)
	for i := 0; i < n; i++ {
		ret[i] = Int8()
	}
	return ret
}

func Int16() int16 {
	ret, _ := strconv.ParseInt(Word(), 10, 16)
	return int16(ret)
}

func id84() []int16 {
	words := Words()
	n := len(words)
	ret := make([]int16, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseInt(words[i], 10, 16)
		ret[i] = int16(v)
	}
	return ret
}

func id58() (int16, int16) {
	return Int16(), Int16()
}

func id38() (int16, int16, int16) {
	return Int16(), Int16(), Int16()
}

func id19() (int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16()
}

func id61() (int16, int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16(), Int16()
}

func id66() (int16, int16, int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16(), Int16(), Int16()
}

func id77() (int16, int16, int16, int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16()
}

func id51() (int16, int16, int16, int16, int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16()
}

func id67() (int16, int16, int16, int16, int16, int16, int16, int16, int16) {
	return Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16(), Int16()
}

func id28(n int) []int16 {
	ret := make([]int16, n)
	for i := 0; i < n; i++ {
		ret[i] = Int16()
	}
	return ret
}

func Int32() int32 {
	ret, _ := strconv.ParseInt(Word(), 10, 32)
	return int32(ret)
}

func id10() []int32 {
	words := Words()
	n := len(words)
	ret := make([]int32, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseInt(words[i], 10, 32)
		ret[i] = int32(v)
	}
	return ret
}

func id86() (int32, int32) {
	return Int32(), Int32()
}

func id87() (int32, int32, int32) {
	return Int32(), Int32(), Int32()
}

func id31() (int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32()
}

func id80() (int32, int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32(), Int32()
}

func id40() (int32, int32, int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32(), Int32(), Int32()
}

func id73() (int32, int32, int32, int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32()
}

func id95() (int32, int32, int32, int32, int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32()
}

func id64() (int32, int32, int32, int32, int32, int32, int32, int32, int32) {
	return Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32(), Int32()
}

func id65(n int) []int32 {
	ret := make([]int32, n)
	for i := 0; i < n; i++ {
		ret[i] = Int32()
	}
	return ret
}

func Int64() int64 {
	ret, _ := strconv.ParseInt(Word(), 10, 64)
	return int64(ret)
}

func id55() []int64 {
	words := Words()
	n := len(words)
	ret := make([]int64, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseInt(words[i], 10, 64)
		ret[i] = int64(v)
	}
	return ret
}

func id96() (int64, int64) {
	return Int64(), Int64()
}

func id24() (int64, int64, int64) {
	return Int64(), Int64(), Int64()
}

func id101() (int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64()
}

func id37() (int64, int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64(), Int64()
}

func id8() (int64, int64, int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64(), Int64(), Int64()
}

func id62() (int64, int64, int64, int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64()
}

func id39() (int64, int64, int64, int64, int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64()
}

func id91() (int64, int64, int64, int64, int64, int64, int64, int64, int64) {
	return Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64(), Int64()
}

func id50(n int) []int64 {
	ret := make([]int64, n)
	for i := 0; i < n; i++ {
		ret[i] = Int64()
	}
	return ret
}

func Uint() uint {
	ret, _ := strconv.ParseUint(Word(), 10, 0)
	return uint(ret)
}

func Uints() []uint {
	words := Words()
	n := len(words)
	ret := make([]uint, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseUint(words[i], 10, 0)
		ret[i] = uint(v)
	}
	return ret
}

func id15() (uint, uint) {
	return Uint(), Uint()
}

func id107() (uint, uint, uint) {
	return Uint(), Uint(), Uint()
}

func id45() (uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint()
}

func id69() (uint, uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint(), Uint()
}

func id85() (uint, uint, uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint(), Uint(), Uint()
}

func id54() (uint, uint, uint, uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint()
}

func id92() (uint, uint, uint, uint, uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint()
}

func id6() (uint, uint, uint, uint, uint, uint, uint, uint, uint) {
	return Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint(), Uint()
}

func id21(n int) []uint {
	ret := make([]uint, n)
	for i := 0; i < n; i++ {
		ret[i] = Uint()
	}
	return ret
}

func Uint8() uint8 {
	ret, _ := strconv.ParseUint(Word(), 10, 8)
	return uint8(ret)
}

func id72() []uint8 {
	words := Words()
	n := len(words)
	ret := make([]uint8, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseUint(words[i], 10, 8)
		ret[i] = uint8(v)
	}
	return ret
}

func id25() (uint8, uint8) {
	return Uint8(), Uint8()
}

func id43() (uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8()
}

func id68() (uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8()
}

func id110() (uint8, uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8(), Uint8()
}

func id14() (uint8, uint8, uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8()
}

func id48() (uint8, uint8, uint8, uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8()
}

func id44() (uint8, uint8, uint8, uint8, uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8()
}

func id5() (uint8, uint8, uint8, uint8, uint8, uint8, uint8, uint8, uint8) {
	return Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8(), Uint8()
}

func id93(n int) []uint8 {
	ret := make([]uint8, n)
	for i := 0; i < n; i++ {
		ret[i] = Uint8()
	}
	return ret
}

func Uint16() uint16 {
	ret, _ := strconv.ParseUint(Word(), 10, 16)
	return uint16(ret)
}

func id63() []uint16 {
	words := Words()
	n := len(words)
	ret := make([]uint16, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseUint(words[i], 10, 16)
		ret[i] = uint16(v)
	}
	return ret
}

func id102() (uint16, uint16) {
	return Uint16(), Uint16()
}

func id29() (uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16()
}

func id41() (uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16()
}

func id70() (uint16, uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16(), Uint16()
}

func id46() (uint16, uint16, uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16()
}

func id76() (uint16, uint16, uint16, uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16()
}

func id59() (uint16, uint16, uint16, uint16, uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16()
}

func id22() (uint16, uint16, uint16, uint16, uint16, uint16, uint16, uint16, uint16) {
	return Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16(), Uint16()
}

func id82(n int) []uint16 {
	ret := make([]uint16, n)
	for i := 0; i < n; i++ {
		ret[i] = Uint16()
	}
	return ret
}

func Uint32() uint32 {
	ret, _ := strconv.ParseUint(Word(), 10, 32)
	return uint32(ret)
}

func id105() []uint32 {
	words := Words()
	n := len(words)
	ret := make([]uint32, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseUint(words[i], 10, 32)
		ret[i] = uint32(v)
	}
	return ret
}

func id97() (uint32, uint32) {
	return Uint32(), Uint32()
}

func id33() (uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32()
}

func id89() (uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32()
}

func id16() (uint32, uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32(), Uint32()
}

func id71() (uint32, uint32, uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32()
}

func id12() (uint32, uint32, uint32, uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32()
}

func id79() (uint32, uint32, uint32, uint32, uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32()
}

func id81() (uint32, uint32, uint32, uint32, uint32, uint32, uint32, uint32, uint32) {
	return Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32(), Uint32()
}

func id0(n int) []uint32 {
	ret := make([]uint32, n)
	for i := 0; i < n; i++ {
		ret[i] = Uint32()
	}
	return ret
}

func Uint64() uint64 {
	ret, _ := strconv.ParseUint(Word(), 10, 64)
	return uint64(ret)
}

func id53() []uint64 {
	words := Words()
	n := len(words)
	ret := make([]uint64, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseUint(words[i], 10, 64)
		ret[i] = uint64(v)
	}
	return ret
}

func id83() (uint64, uint64) {
	return Uint64(), Uint64()
}

func id20() (uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64()
}

func id52() (uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64()
}

func id47() (uint64, uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64(), Uint64()
}

func id30() (uint64, uint64, uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64()
}

func id99() (uint64, uint64, uint64, uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64()
}

func id18() (uint64, uint64, uint64, uint64, uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64()
}

func id17() (uint64, uint64, uint64, uint64, uint64, uint64, uint64, uint64, uint64) {
	return Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64(), Uint64()
}

func id2(n int) []uint64 {
	ret := make([]uint64, n)
	for i := 0; i < n; i++ {
		ret[i] = Uint64()
	}
	return ret
}

func Float32() float32 {
	ret, _ := strconv.ParseFloat(Word(), 32)
	return float32(ret)
}

func id32() []float32 {
	words := Words()
	n := len(words)
	ret := make([]float32, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseFloat(words[i], 32)
		ret[i] = float32(v)
	}
	return ret
}

func id100() (float32, float32) {
	return Float32(), Float32()
}

func id36() (float32, float32, float32) {
	return Float32(), Float32(), Float32()
}

func id98() (float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32()
}

func id1() (float32, float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32(), Float32()
}

func id7() (float32, float32, float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32(), Float32(), Float32()
}

func id56() (float32, float32, float32, float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32()
}

func id108() (float32, float32, float32, float32, float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32()
}

func id23() (float32, float32, float32, float32, float32, float32, float32, float32, float32) {
	return Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32(), Float32()
}

func id106(n int) []float32 {
	ret := make([]float32, n)
	for i := 0; i < n; i++ {
		ret[i] = Float32()
	}
	return ret
}

func Float64() float64 {
	ret, _ := strconv.ParseFloat(Word(), 64)
	return float64(ret)
}

func id60() []float64 {
	words := Words()
	n := len(words)
	ret := make([]float64, n)
	for i := 0; i < n; i++ {
		v, _ := strconv.ParseFloat(words[i], 64)
		ret[i] = float64(v)
	}
	return ret
}

func id74() (float64, float64) {
	return Float64(), Float64()
}

func id27() (float64, float64, float64) {
	return Float64(), Float64(), Float64()
}

func id3() (float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64()
}

func id75() (float64, float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64(), Float64()
}

func id109() (float64, float64, float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64(), Float64(), Float64()
}

func id26() (float64, float64, float64, float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64()
}

func id49() (float64, float64, float64, float64, float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64()
}

func id88() (float64, float64, float64, float64, float64, float64, float64, float64, float64) {
	return Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64(), Float64()
}

func id78(n int) []float64 {
	ret := make([]float64, n)
	for i := 0; i < n; i++ {
		ret[i] = Float64()
	}
	return ret
}

func Words2() (string, string) {
	return Word(), Word()
}

func Words3() (string, string, string) {
	return Word(), Word(), Word()
}

func Words4() (string, string, string, string) {
	return Word(), Word(), Word(), Word()
}

func Words5() (string, string, string, string, string) {
	return Word(), Word(), Word(), Word(), Word()
}

func Words6() (string, string, string, string, string, string) {
	return Word(), Word(), Word(), Word(), Word(), Word()
}

func Words7() (string, string, string, string, string, string, string) {
	return Word(), Word(), Word(), Word(), Word(), Word(), Word()
}

func Words8() (string, string, string, string, string, string, string, string) {
	return Word(), Word(), Word(), Word(), Word(), Word(), Word(), Word()
}

func Words9() (string, string, string, string, string, string, string, string, string) {
	return Word(), Word(), Word(), Word(), Word(), Word(), Word(), Word(), Word()
}

func WordsN(n int) []string {
	ret := make([]string, n)
	for i := 0; i < n; i++ {
		ret[i] = Word()
	}
	return ret
}

func Lines2() (string, string) {
	return Line(), Line()
}

func Lines3() (string, string, string) {
	return Line(), Line(), Line()
}

func Lines4() (string, string, string, string) {
	return Line(), Line(), Line(), Line()
}

func Lines5() (string, string, string, string, string) {
	return Line(), Line(), Line(), Line(), Line()
}

func Lines6() (string, string, string, string, string, string) {
	return Line(), Line(), Line(), Line(), Line(), Line()
}

func Lines7() (string, string, string, string, string, string, string) {
	return Line(), Line(), Line(), Line(), Line(), Line(), Line()
}

func Lines8() (string, string, string, string, string, string, string, string) {
	return Line(), Line(), Line(), Line(), Line(), Line(), Line(), Line()
}

func Lines9() (string, string, string, string, string, string, string, string, string) {
	return Line(), Line(), Line(), Line(), Line(), Line(), Line(), Line(), Line()
}

func LinesN(n int) []string {
	ret := make([]string, n)
	for i := 0; i < n; i++ {
		ret[i] = Line()
	}
	return ret
}

func Bytes2() (byte, byte) {
	return Byte(), Byte()
}

func Bytes3() (byte, byte, byte) {
	return Byte(), Byte(), Byte()
}

func Bytes4() (byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte()
}

func Bytes5() (byte, byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte(), Byte()
}

func Bytes6() (byte, byte, byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte(), Byte(), Byte()
}

func Bytes7() (byte, byte, byte, byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte()
}

func Bytes8() (byte, byte, byte, byte, byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte()
}

func Bytes9() (byte, byte, byte, byte, byte, byte, byte, byte, byte) {
	return Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte(), Byte()
}

func BytesN(n int) []byte {
	ret := make([]byte, n)
	for i := 0; i < n; i++ {
		ret[i] = Byte()
	}
	return ret
}
