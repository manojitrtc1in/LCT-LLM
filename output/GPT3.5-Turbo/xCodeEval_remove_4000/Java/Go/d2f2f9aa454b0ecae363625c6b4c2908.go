package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	i1 := readInt()
	for i2 := 0; i2 < i1; i2++ {
		countValue := make(map[int]int)
		quantity := id7(" ")
		base := id7(" ")
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
			if len(countValue) < min {
				min = len(countValue)
			}
		}
		writeInt(min, "\n")
	}
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func id7(split string) []int {
	scanner.Scan()
	strs := strings.Split(scanner.Text(), split)
	nums := make([]int, len(strs))
	for i, str := range strs {
		nums[i], _ = strconv.Atoi(str)
	}
	return nums
}

func writeInt(num int, end string) {
	writer.WriteString(strconv.Itoa(num))
	writer.WriteString(end)
}
