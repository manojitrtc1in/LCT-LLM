package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type IO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewIO() *IO {
	return &IO{
		reader: bufio.NewReader(os.Stdin),
		writer: bufio.NewWriter(os.Stdout),
	}
}

func (io *IO) readInt() (int, error) {
	line, err := io.reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	return strconv.Atoi(strings.TrimSpace(line))
}

func (io *IO) writeInt(number int) {
	io.writer.WriteString(fmt.Sprintf("%d\n", number))
}

func (io *IO) flush() {
	io.writer.Flush()
}

type Math struct{}

func (m *Math) gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return m.gcd(b, a%b)
}

func (m *Math) lcm(a, b int) int {
	return a / m.gcd(a, b) * b
}

type Division struct {
	dividend, divider int
}

func NewDivision(dividend, divider int) *Division {
	g := Math{}.gcd(dividend, divider)
	return &Division{dividend / g, divider / g}
}

func (d *Division) add(other *Division) *Division {
	lcm := Math{}.lcm(d.divider, other.divider)
	newDividend := (lcm/d.divider)*d.dividend + (lcm/other.divider)*other.dividend
	return NewDivision(newDividend, lcm)
}

func (d *Division) multiply(other *Division) *Division {
	return NewDivision(d.dividend*other.dividend, d.divider*other.divider)
}

func main() {
	io := NewIO()
	defer io.flush()

	var n int
	n, _ = io.readInt()

	for i := 0; i < n; i++ {
		countValue := make(map[int]int)
		quantity := readArray(io)
		base := readArray(io)

		for j := 0; j < quantity[2]; j++ {
			countValue[base[j]]++
		}

		min := len(countValue)
		for j := quantity[2]; j < quantity[0]; j++ {
			countValue[base[j-quantity[2]]]--
			if countValue[base[j-quantity[2]]] == 0 {
				delete(countValue, base[j-quantity[2]])
			}
			countValue[base[j]]++
			min = minInt(min, len(countValue))
		}
		io.writeInt(min)
	}
}

func readArray(io *IO) []int {
	line, _ := io.reader.ReadString('\n')
	strs := strings.Fields(line)
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i], _ = strconv.Atoi(s)
	}
	return arr
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
