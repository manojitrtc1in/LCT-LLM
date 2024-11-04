package main

import (
	"bufio"
	"fmt"
	"os"
)

type Pair struct {
	idx int
	val int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	a := nextInt(scanner)
	b := nextInt(scanner)
	x := nextInt(scanner)
	y := nextInt(scanner)
	z := nextInt(scanner)

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

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num := 0
	for _, c := range scanner.Bytes() {
		num = num*10 + int(c-'0')
	}
	return num
}
