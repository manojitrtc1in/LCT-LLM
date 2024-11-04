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

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readArrayInt() []int {
	scanner.Scan()
	strs := strings.Split(scanner.Text(), " ")
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i], _ = strconv.Atoi(s)
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

	i1 := readInt()
	for i2 := 0; i2 < i1; i2++ {
		countValue := make(map[int]int)
		quantity := readArrayInt()
		base := readArrayInt()
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
		writeInt(min)
		writeLine()
	}

	flush()
}
