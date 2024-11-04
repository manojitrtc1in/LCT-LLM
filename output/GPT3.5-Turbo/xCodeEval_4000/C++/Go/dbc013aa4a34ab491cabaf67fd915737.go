package main

import (
	"fmt"
	"strings"
)

func findSubstrMatch(str, pat string) []int {
	var out []int
	loc := make(map[rune][]int)

	for i, ch := range pat {
		loc[ch] = append(loc[ch], i)
	}

	cache := make([]map[int]int, len(pat))
	for i := range cache {
		cache[i] = make(map[int]int)
	}

	for i, j := 0, 0; i < len(str); i, j = i+1, j+1 {
		if j == len(pat) {
			out = append(out, i-1)
			j = cache[j-1][i]
		}

		if str[i] != pat[j] {
			if j == 0 {
				cache[j][i] = -1
			} else {
				cache[j][i] = cache[j-1][i]
			}
			j = cache[j][i]
		} else {
			cache[j][i] = j + 1
		}
	}

	if j == len(pat) {
		out = append(out, len(str)-1)
	}

	return out
}

func b494() int {
	var str, pat string
	fmt.Scan(&str, &pat)

	loc := findSubstrMatch(str, pat)
	tag := make([]bool, len(str))
	for _, i := range loc {
		tag[i] = true
	}

	soln := make([]int64, len(str))
	cum := make([]int64, len(str))

	soln[0] = int64(tag[0])
	cum[0] = soln[0]

	const mod int64 = 1000000000 + 7
	last := -1
	var carry int64

	for i := 1; i < len(str); i++ {
		if !tag[i] {
			soln[i] = soln[i-1] + carry
			soln[i] %= mod
			cum[i] = (soln[i] + cum[i-1]) % mod
		} else {
			last = i
			j := 1 + i - len(pat)

			soln[i] = soln[i-1] + 1 + int64(j)
			if j > 0 {
				soln[i] += cum[j-1]
			}

			soln[i] %= mod
			cum[i] = (soln[i] + cum[i-1]) % mod

			carry = (soln[i] - soln[i-1] + mod) % mod
		}
	}

	return int((soln[len(soln)-1] + mod) % mod)
}

func main() {
	fmt.Println(b494())
}
