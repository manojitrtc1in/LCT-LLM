package main

import (
	"fmt"
	"strings"
)

func update(s string) string {
	result := ""
	for i := 0; i < len(s); i++ {
		if s[i]-'A' >= 0 && s[i]-'A' < 26 {
			result += string(s[i]-'A'+'a')
		} else if s[i]-'a' >= 0 && s[i]-'a' < 26 {
			result += string(s[i])
		}
	}
	return result
}

func main() {
	t1 := []string{
		"the",
		"said",
		"and",
		"bank",
		"market",
		"billion",
		"for",
		"stg",
		"mln",
		"with",
		"that",
		"march",
		"from",
		"money",
		"exchange",
		"currency",
		"had",
		"dollar",
		"its",
		"have",
		"will",
		"pct",
		"treasury",
		"but",
		"banks",
		"not",
		"bills",
		"would",
		"foreign",
		"was",
		"today",
		"this",
		"dlrs",
		"dealers",
		"which",
		"their",
		"system",
		"new",
		"central",
		"currencies",
		"they",
		"around",
		"monetary",
		"year",
		"were",
		"one",
		"rates",
		"markets",
		"liquidity",
		"japan",
		"dollars",
		"trading",
		"assistance",
		"are",
		"some",
		"has",
		"policy",
		"early",
		"against",
		"rate",
		"prices",
		"funds",
		"england",
		"more",
		"london",
		"last",
		"fed",
		"could",
		"baker",
		"after",
		"two",
		"told",
		"intervention",
		"help",
		"fall",
		"economic",
		"arab",
		"also",
		"yen",
		"while",
		"shortage",
		"securities",
		"other",
		"major",
		"commodity",
		"than",
		"paris",
		"option",
		"bundesbank",
		"bond",
		"trade",
		"states",
		"official",
		"now",
		"much",
		"house",