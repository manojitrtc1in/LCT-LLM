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

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readLine())
	return num
}

func readIntArray() []int {
	strs := strings.Split(readLine(), " ")
	arr := make([]int, len(strs))
	for i, str := range strs {
		arr[i], _ = strconv.Atoi(str)
	}
	return arr
}

func writeInt(num int) {
	writer.WriteString(strconv.Itoa(num))
}

func writeString(str string) {
	writer.WriteString(str)
}

func writeLine() {
	writer.WriteString("\n")
}

func flush() {
	writer.Flush()
}

func main() {
	initIO()
	defer flush()

	i1 := readInt()
	for i2 := 0; i2 < i1; i2++ {
		quantity := readIntArray()
		base := readIntArray()
		countValue := make(map[int]int)
		min := len(countValue)

		for i := 0; i < quantity[2]; i++ {
			countValue[base[i]]++
		}

		for i := quantity[2]; i < quantity[0]; i++ {
			countValue[base[i-quantity[2]]]--
			if countValue[base[i-quantity[2]]] == 0 {
				delete(countValue, base[i-quantity[2]])
			}
			countValue[base[i]]++
			min = minInt(min, len(countValue))
		}

		writeInt(min)
		writeLine()
	}
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
