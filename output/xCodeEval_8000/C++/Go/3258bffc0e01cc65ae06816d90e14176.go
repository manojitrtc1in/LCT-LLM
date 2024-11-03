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
	Map map[byte]int
	q int
)

func Input() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s = scanner.Text()
}

func Solve() {
	baseAnswer := 1
	for i := 0; i < len(s); i++ {
		x := s[i]
		if x >= '0' && x <= '9' {
			continue
		}
		if x == '?' {
			q++
			continue
		}
		Map[x]++
	}
	for i := 10; i > 10-len(Map); i-- {
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
	for i := 0; i < q; i++ {
		fmt.Print("0")
	}
}

func main() {
	Input()
	Solve()
}
