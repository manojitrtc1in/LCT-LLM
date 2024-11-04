package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func initScanner() {
	scanner = bufio.NewScanner(os.Stdin)
}

func initWriter() {
	writer = bufio.NewWriter(os.Stdout)
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readString())
	return num
}

func readInts() []int {
	strs := strings.Split(readString(), " ")
	nums := make([]int, len(strs))
	for i, str := range strs {
		nums[i], _ = strconv.Atoi(str)
	}
	return nums
}

func writeString(str string) {
	writer.WriteString(str)
}

func writeInt(num int) {
	writer.WriteString(strconv.Itoa(num))
}

func writeInts(nums []int) {
	strs := make([]string, len(nums))
	for i, num := range nums {
		strs[i] = strconv.Itoa(num)
	}
	writer.WriteString(strings.Join(strs, " "))
}

func writeStringLn(str string) {
	writer.WriteString(str + "\n")
}

func writeIntLn(num int) {
	writer.WriteString(strconv.Itoa(num) + "\n")
}

func writeIntsLn(nums []int) {
	strs := make([]string, len(nums))
	for i, num := range nums {
		strs[i] = strconv.Itoa(num)
	}
	writer.WriteString(strings.Join(strs, " ") + "\n")
}

func flush() {
	writer.Flush()
}

type Pair struct {
	first  int
	second int
}

func createPair(first, second int) Pair {
	return Pair{first, second}
}

type Division struct {
	dividend int
	divider  int
}

func createDivision(dividend, divider int) Division {
	return Division{dividend, divider}
}

func (d *Division) reduce() {
	gcd := gcd(d.dividend, d.divider)
	d.dividend /= gcd
	d.divider /= gcd
}

func (d *Division) add(number Division) {
	d.dividend = d.dividend*number.divider + number.dividend*d.divider
	d.divider *= number.divider
	d.reduce()
}

func (d *Division) multiply(number Division) {
	d.dividend *= number.dividend
	d.divider *= number.divider
	d.reduce()
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func main() {
	initScanner()
	initWriter()
	defer flush()

	i1 := readInt()
	for i2 := 0; i2 < i1; i2++ {
		quantity := readInts()
		base := readInts()
		countValue := make(map[int]int)
		min := len(countValue)
		for i := 0; i < quantity[2]; i++ {
			countValue[base[i]]++
		}
		min = len(countValue)
		for i := quantity[2]; i < quantity[0]; i++ {
			countValue[base[i-quantity[2]]]--
			if countValue[base[i-quantity[2]]] == 0 {
				delete(countValue, base[i-quantity[2]])
			}
			countValue[base[i]]++
			min = minInt(min, len(countValue))
		}
		writeIntLn(min)
	}
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func absInt(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func powInt(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res *= a
		}
		a *= a
		b >>= 1
	}
	return res
}

func sortInts(nums []int) {
	sort.Ints(nums)
}

func reverseInts(nums []int) {
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
}

func main() {
	initScanner()
	initWriter()
	defer flush()

	i1 := readInt()
	for i2 := 0; i2 < i1; i2++ {
		quantity := readInts()
		base := readInts()
		countValue := make(map[int]int)
		min := len(countValue)
		for i := 0; i < quantity[2]; i++ {
			countValue[base[i]]++
		}
		min = len(countValue)
		for i := quantity[2]; i < quantity[0]; i++ {
			countValue[base[i-quantity[2]]]--
			if countValue[base[i-quantity[2]]] == 0 {
				delete(countValue, base[i-quantity[2]])
			}
			countValue[base[i]]++
			min = minInt(min, len(countValue))
		}
		writeIntLn(min)
	}
}
