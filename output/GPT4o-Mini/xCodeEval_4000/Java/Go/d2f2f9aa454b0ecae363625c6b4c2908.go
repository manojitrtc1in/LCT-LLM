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

func (io *IO) readArrayInt() ([]int, error) {
	line, err := io.reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	strs := strings.Fields(line)
	arr := make([]int, len(strs))
	for i, s := range strs {
		arr[i], err = strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
	}
	return arr, nil
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
	gcd := Math{}.gcd(dividend, divider)
	return &Division{dividend / gcd, divider / gcd}
}

func (d *Division) add(other *Division) *Division {
	lcm := Math{}.lcm(d.divider, other.divider)
	newDividend := (lcm/d.divider)*d.dividend + (lcm/other.divider)*other.dividend
	return NewDivision(newDividend, lcm)
}

func main() {
	io := NewIO()
	defer io.flush()

	i1, _ := io.readInt()
	for i2 := 0; i2 < i1; i2++ {
		countValue := make(map[int]int)
		quantity, _ := io.readArrayInt()
		base, _ := io.readArrayInt()

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
			min = minInt(min, len(countValue))
		}
		io.writeInt(min)
	}
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
