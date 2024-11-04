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
	for scanner.Scan() {
		line := scanner.Text()
		var buf string
		var x float64
		n, _ := fmt.Sscanf(line, "%s %f", &buf, &x)
		if n == 2 {
			ma[len(ma)-1][buf] = x
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Println("Error reading input file:", err)
		return
	}

	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)

	for _, c := range DELIMS {
		text = strings.ReplaceAll(text, string(c), " ")
	}

	words := strings.Fields(text)
	for _, word := range words {
		word = strings.ToLower(word)
		for i := len(ma) - 1; i >= 0; i-- {
			if val, ok := ma[i][word]; ok {
				p[i] += math.Log(val)
			} else {
				p[i] += math.Log(1E-6)
			}
		}
	}

	sel = 1
	for i := len(p) - 1; i >= 0; i-- {
		if p[i] > p[sel]+EPS {
			sel = i
		}
	}

	fmt.Println(sel + 1)
}
