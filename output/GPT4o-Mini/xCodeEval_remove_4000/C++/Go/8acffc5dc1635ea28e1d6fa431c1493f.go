package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strings"
)

const (
	C    = 100
	EPS  = 1E-9
	INF  = 1000000000
	INF64 = 1E18
	PI   = 3.1415926535897932384626433832795
)

var (
	DELIMS = ",.?!\"\\/|"
	cat    = [3 * C]string{
		"dealers 0.0038157536113382394",
		"customer 0.0010902153175252113",
		"dealer 9.539384028345599E-4",
		// ... (rest of the data)
		"yasuhiro 0.001006893346758578",
	}
	ma   [3]map[string]float64
	p    [10]float64
	sel  int
)

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	for i := 0; i < 3*C; i++ {
		var word string
		var x float64
		fmt.Sscanf(cat[i], "%s %f", &word, &x)
		if ma[i/C] == nil {
			ma[i/C] = make(map[string]float64)
		}
		ma[i/C][word] = x
	}

	var text string
	for scanner.Scan() {
		text += scanner.Text() + " "
	}

	for i := 0; i < len(text); i++ {
		if strings.Contains(DELIMS, string(text[i])) {
			text = text[:i] + " " + text[i+1:]
		}
	}

	tokens := strings.Fields(strings.ToLower(text))

	for _, tok := range tokens {
		for i := 0; i < 3; i++ {
			if val, ok := ma[i][tok]; ok {
				p[i] += math.Log(val)
			} else {
				p[i] += math.Log(1E-6)
			}
		}
	}

	sel = 0
	for i := 1; i < 3; i++ {
		if p[i] > p[sel]+EPS {
			sel = i
		}
	}

	fmt.Println(sel + 1)
}
