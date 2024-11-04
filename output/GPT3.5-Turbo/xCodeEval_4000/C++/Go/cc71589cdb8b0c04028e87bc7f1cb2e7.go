package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = acos(-1.0)
	N     = 1000 + 7
)

type pt struct {
	x, y int
}

func sqr(a int) int {
	return a * a
}

func read() (string, bool) {
	reader := bufio.NewReader(os.Stdin)
	s, err := reader.ReadString('\n')
	if err != nil {
		return "", false
	}
	s = strings.TrimSpace(s)
	s = s[4:]
	return s, true
}

func solve(s string) string {
	n := len(s)
	lim := []int64{0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099}
	pr1 := []string{"", "198", "19", "2", "", "", "", "", "", ""}
	pr2 := []string{"", "199", "20", "3", "1", "1", "1", "1", "1", "1"}

	x, _ := strconv.ParseInt(s, 10, 64)
	if x >= lim[n] {
		return pr1[n] + s
	} else {
		return pr2[n] + s
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Uncomment the below line if there is a test case count
	// scanner.Scan()
	// tc, _ := strconv.Atoi(scanner.Text())

	for scanner.Scan() {
		s := scanner.Text()
		fmt.Println(solve(s))
	}
}
