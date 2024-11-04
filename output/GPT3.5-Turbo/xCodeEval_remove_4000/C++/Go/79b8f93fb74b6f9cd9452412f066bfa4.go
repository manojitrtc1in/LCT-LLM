package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const (
	C      = 100
	DELIMS = ",.?!\"\\/|"
)

var (
	ma  [3]map[string]float64
	p   [10]float64
	sel int
)

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		fmt.Println("Error opening input file:", err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for i := 0; i < 3*C; i++ {
		scanner.Scan()
		line := scanner.Text()
		var buf string
		var x float64
		fmt.Sscanf(line, "%s %f", &buf, &x)
		ma[i/C][buf] = x
	}

	scanner = bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()

	for _, c := range DELIMS {
		text = strings.ReplaceAll(text, string(c), " ")
	}

	words := strings.Fields(text)
	for _, word := range words {
		word = strings.ToLower(word)
		for i := 0; i < 3; i++ {
			if val, ok := ma[i][word]; ok {
				p[i] += math.Log(val)
			} else {
				p[i] += math.Log(1E-6)
			}
		}
	}

	sel = 1
	for i := 2; i >= 0; i-- {
		if p[i] > p[sel]+EPS {
			sel = i
		}
	}

	fmt.Println(sel + 1)
}
