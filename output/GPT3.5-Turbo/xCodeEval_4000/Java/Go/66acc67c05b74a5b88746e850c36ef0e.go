package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	soln()
}

func soln() {
	var a, b, x, y, z int
	fmt.Fscanf(scanner, "%d %d %d %d %d\n", &a, &b, &x, &y, &z)

	ans := int64(0)
	if int64(a) < 2*int64(x) {
		ans += 2*int64(x) - int64(a)
		a = 0
	} else {
		a = a - 2*x
	}

	if int64(b) < 3*int64(z) {
		ans += 3*int64(z) - int64(b)
		b = 0
	} else {
		b = b - 3*z
	}

	if a < b {
		y = y - a
		if y > 0 {
			b = b - a
			a = 0
		} else {
			y = 0
		}
	} else {
		y = y - b
		if y > 0 {
			b = a - b
			a = 0
		} else {
			y = 0
		}
	}

	if y > b {
		ans += int64(b) + 2*(int64(y)-int64(b))
	} else {
		ans += int64(y)
	}

	fmt.Fprintln(writer, ans)
}
