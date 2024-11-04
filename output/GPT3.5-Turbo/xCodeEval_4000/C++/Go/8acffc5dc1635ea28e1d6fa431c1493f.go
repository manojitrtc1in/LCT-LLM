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
	DELIMS = ",.?!\"\\/|#��@*"
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

	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)

	for _, c := range DELIMS {
		text = strings.ReplaceAll(text, string(c), " ")
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
