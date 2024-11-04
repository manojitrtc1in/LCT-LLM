package main

import (
	"bufio"
	"fmt"
	"math"
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
	for i := 0; i < 3*C && scanner.Scan(); i++ {
		var buf string
		var x float64
		fmt.Sscanf(scanner.Text(), "%s %f", &buf, &x)
		ma[i/C][buf] = x
	}

	scanner = bufio.NewScanner(os.Stdin)
	text := ""
	for scanner.Scan() {
		text += scanner.Text() + " "
	}

	for i := 0; i < len(text); i++ {
		if strings.ContainsRune(DELIMS, rune(text[i])) {
			text = text[:i] + " " + text[i+1:]
		}
	}

	words := strings.Fields(text)
	for _, tok := range words {
		tok = strings.ToLower(tok)
		for i := 0; i < 3; i++ {
			if val, ok := ma[i][tok]; ok {
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
