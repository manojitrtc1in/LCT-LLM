package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	s string
	q int64
)

func Input() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s = scanner.Text()
}

func Solve() {
	baseAnswer := int64(1)
	Map := make(map[rune]int64)
	for _, x := range s {
		if x >= '0' && x <= '9' {
			continue
		}
		if x == '?' {
			q++
			continue
		}
		Map[x]++
	}
	for i := int64(10); i > 10-int64(len(Map)); i-- {
		baseAnswer *= i
	}
	if s[0] >= 'A' && s[0] <= 'J' {
		baseAnswer /= 10
		baseAnswer *= 9
	}
	if s[0] == '?' {
		baseAnswer *= 9
		q--
	}
	fmt.Print(baseAnswer)
	for i := int64(0); i < q; i++ {
		fmt.Print("0")
	}
}

func main() {
	Input()
	Solve()
}
