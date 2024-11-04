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
		// ... (remaining entries)
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
		var x float64
		var buf string
		fmt.Sscanf(cat[i], "%s%lf", &buf, &x)
		if ma[i/100] == nil {
			ma[i/100] = make(map[string]float64)
		}
		ma[i/100][buf] = x
	}

	var text strings.Builder
	for scanner.Scan() {
		text.WriteString(scanner.Text())
		text.WriteString(" ")
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	textStr := text.String()
	for i := 0; i < len(textStr); i++ {
		if strings.ContainsRune(DELIMS, rune(textStr[i])) {
			textStr = textStr[:i] + " " + textStr[i+1:]
		}
	}

	tokens := strings.Fields(textStr)

	for _, tok := range tokens {
		tok = strings.ToLower(tok)
		for i := 0; i < 3; i++ {
			if val, exists := ma[i][tok]; exists {
				p[i] += math.Log(val)
			} else {
				p[i] += math.Log(1E-6)
			}
		}
	}

	sel = 1
	for i := 0; i < 3; i++ {
		if p[i] > p[sel]+EPS {
			sel = i
		}
	}

	fmt.Println(sel + 1)
}
