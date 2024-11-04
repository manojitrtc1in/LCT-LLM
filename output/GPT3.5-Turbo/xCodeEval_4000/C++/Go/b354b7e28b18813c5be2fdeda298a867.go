package main

import (
	"fmt"
	"math"
	"strings"
)

const (
	C      = 100
	DELIMS = ",.?!\"\\/|#“”@*"
)

var (
	ma  [3]map[string]float64
	p   [10]float64
	sel int
)

func main() {
	ma = [3]map[string]float64{}
	for i := 0; i < 3*C; i++ {
		var buf string
		var x float64
		fmt.Sscanf(cat[i], "%s%f", &buf, &x)
		ma[i/C][buf] = x
	}

	var buf string
	fmt.Scanln(&buf)
	text := ""
	for {
		var line string
		if _, err := fmt.Scanln(&line); err != nil {
			break
		}
		text += line + " "
	}

	text = strings.ReplaceAll(text, "\n", " ")
	for _, delim := range DELIMS {
		text = strings.ReplaceAll(text, string(delim), " ")
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
