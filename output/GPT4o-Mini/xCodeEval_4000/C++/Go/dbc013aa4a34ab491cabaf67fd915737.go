package main

import (
	"fmt"
	"math"
	"strings"
)

type int64 int64

func findSubstrMatch(str, pat string) []int {
	var out []int
	loc := make(map[rune][]int)

	for i := len(pat) - 1; i >= 0; i-- {
		loc[rune(pat[i])] = append(loc[rune(pat[i])], i)
	}

	cache := make([]map[int]int, len(pat))
	for i := range cache {
		cache[i] = make(map[int]int)
	}

	i := 0
	for j := 0; j < len(str); i, j = i+1, j+1 {
		if i == len(pat) || pat[i] != str[j] {
			if i == len(pat) {
				out = append(out, j-1)
			}

			first := rollBack(i, str[j], loc)
			last := i - 1
			i = recycle(first, last, pat, loc, cache)
		}
	}

	if i == len(pat) {
		out = append(out, len(str)-1)
	}

	return out
}

func rollBack(last int, chr rune, loc map[rune][]int) int {
	if a, ok := loc[chr]; ok {
		for _, v := range a {
			if v <= last {
				return v
			}
		}
	}
	return -1
}

func recycle(first, last int, pat string, loc map[rune][]int, cache []map[int]int) int {
	if len(pat) < first {
		return -1
	}

	ref := cache[first]
	if val, ok := ref[last]; ok {
		return val
	}

	for i, j := first-1, last; i < first; i, j = i-1, j-1 {
		if pat[i] != pat[j] {
			return ref[last] = recycle(rollBack(first, rune(pat[first]), loc), last, pat, loc, cache)
		}
	}

	return ref[last] = first
}

func erase(str *string, ch rune) {
	*str = strings.ReplaceAll(*str, string(ch), "")
}

func tokenize(str string, sep rune) []string {
	var res []string
	follow, lead := 0, 0

	for {
		for lead < len(str) && rune(str[lead]) != sep {
			lead++
		}
		res = append(res, str[follow:lead])

		if lead < len(str) {
			follow = lead + 1
			lead++
		} else {
			break
		}
	}

	return res
}

func revmatch(i, j, offset int, str []string, vir string, cache [][]map[struct{ int; int }]string) string {
	if i == len(str[0]) || j == len(str[1]) || offset == len(vir) {
		return ""
	}

	pr := struct {
		int
		int
	}{j, offset}

	if val, ok := cache[i][pr]; ok {
		return val
	}

	if str[0][i] != str[1][j] {
		a := revmatch(i+1, j, offset, str, vir, cache)
		b := revmatch(i, j+1, offset, str, vir, cache)
		if len(a) < len(b) {
			return b
		}
		return a
	} else {
		b := revmatch(i+1, j, offset, str, vir, cache)
		c := revmatch(i, j+1, offset, str, vir, cache)
		d := b
		if len(b) < len(c) {
			d = c
		}

		chr := str[0][i]
		var a string
		if chr == vir[offset] {
			a = string(chr) + revmatch(i+1, j+1, offset+1, str, vir, cache)
		} else {
			a = string(chr) + revmatch(i+1, j+1, 0, str, vir, cache)
		}

		fail := len(a) < len(d) || strings.HasPrefix(a, vir[offset:]) || strings.HasPrefix(a, vir)
		if fail {
			return d
		}
		return a
	}
}

func b346() string {
	var str [2]string
	var vir string
	fmt.Scan(&str[0], &vir)

	cache := make([]map[struct{ int; int }]string, len(str[0]))
	for i := range cache {
		cache[i] = make(map[struct{ int; int }]string)
	}

	val := revmatch(0, 0, 0, str[:], vir, cache)
	if val == "" {
		return "0"
	}
	return val
}

func main() {
	fmt.Println(b346())
}
