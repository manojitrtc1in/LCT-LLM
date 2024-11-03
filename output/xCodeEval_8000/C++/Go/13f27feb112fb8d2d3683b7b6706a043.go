package main

import (
	"bufio"
	"fmt"
	"os"
)

const l = 2

type matrix struct {
	d [2][2]int
}

func (m *matrix) init() {
	for i := 0; i < l; i++ {
		for j := 0; j < l; j++ {
			m.d[i][j] = 0
		}
	}
}

func (m *matrix) sum() int {
	res := 0
	for i := 0; i < l; i++ {
		for j := 0; j < l; j++ {
			res += m.d[i][j]
		}
	}
	return res
}

func multiply(a, b matrix) matrix {
	c := matrix{}
	for i := 0; i < l; i++ {
		for j := 0; j < l; j++ {
			tmp := 0
			for k := 0; k < l; k++ {
				tmp += a.d[i][k] * b.d[k][j]
			}
			c.d[i][j] = tmp
		}
	}
	return c
}

func pow(a matrix, b int) matrix {
	c := matrix{}
	c.init()
	for b > 0 {
		if b&1 == 1 {
			c = multiply(c, a)
		}
		a = multiply(a, a)
		b /= 2
	}
	return c
}

func solve() int {
	ch := readChar()
	if ch == '0' {
		return 1 << 0
	}
	if ch == '1' {
		return 1 << 15
	}
	if ch == '?' {
		return (1 << 3) | (1 << 12)
	}

	x := solve()
	ch = readChar()
	y := solve()

	res := 0
	for i := 0; i < 16; i++ {
		if x&(1<<i) == 0 {
			continue
		}
		for j := 0; j < 16; j++ {
			if y&(1<<j) == 0 {
				continue
			}
			if ch == '^' {
				res |= 1 << (i ^ j)
			}
			if ch == '&' {
				res |= 1 << (i & j)
			}
			if ch == '|' {
				res |= 1 << (i | j)
			}
		}
	}
	readChar()
	return res
}

func main() {
	N := readInt()
	readChar()
	e := solve()
	if e&0x8241 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readChar() byte {
	scanner.Scan()
	return scanner.Bytes()[0]
}

func readInt() int {
	scanner.Scan()
	b := scanner.Bytes()
	n := 0
	for i := 0; i < len(b); i++ {
		n = n*10 + int(b[i]-'0')
	}
	return n
}
