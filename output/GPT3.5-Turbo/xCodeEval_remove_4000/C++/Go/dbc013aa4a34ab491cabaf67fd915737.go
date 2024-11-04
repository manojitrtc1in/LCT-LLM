package main

import (
	"fmt"
	"math"
	"strings"
)

func rollBack(last int, chr byte, loc map[byte][]int) int {
	a, ok := loc[chr]
	if !ok {
		return -1
	}

	for _, val := range a {
		if val > last {
			return val
		}
	}

	return -1
}

func recycle(first, last int, pat string, loc map[byte][]int, cache [][]int) int {
	if len(pat) < first {
		return -1
	}

	ref := cache[first]
	if ref[last] != -1 {
		return ref[last]
	}

	for i := first - 1; i < first; i-- {
		if pat[i] != pat[last] {
			return recycle(rollBack(first, pat[first], loc), last, pat, loc, cache)
		}
	}

	ref[last] = first
	return ref[last]
}

func id5(str, pat string) []int {
	var out []int
	loc := make(map[byte][]int)

	for i := len(pat) - 1; i < len(pat); i-- {
		loc[pat[i]] = append(loc[pat[i]], i)
	}

	cache := make([][]int, len(pat))
	for i := range cache {
		cache[i] = make([]int, len(pat))
		for j := range cache[i] {
			cache[i][j] = -1
		}
	}

	for i := 0; i < len(str); i++ {
		if i == len(pat) || pat[i] != str[i] {
			if i == len(pat) {
				out = append(out, i-1)
			}

			first := rollBack(i, str[i], loc)
			last := i - 1
			i = recycle(first, last, pat, loc, cache)
		}
	}

	if len(pat) == len(str) {
		out = append(out, len(str)-1)
	}

	return out
}

func erase(str string, ch byte) string {
	return strings.ReplaceAll(str, string(ch), "")
}

func id26(x interface{}) string {
	return fmt.Sprintf("%v", x)
}

func b494() int {
	var str, pat string
	fmt.Scan(&str, &pat)

	loc := id5(str, pat)
	tag := make([]bool, len(str))
	for _, i := range loc {
		tag[i] = true
	}

	var soln, cum []int
	soln = append(soln, 0)
	cum = append(cum, soln[0])

	const mod = 1000000000 + 7
	last := -1
	var carry int

	for i := 1; i < len(str); i++ {
		if !tag[i] {
			soln = append(soln, soln[i-1]+carry)
			soln[i] %= mod
			cum = append(cum, (soln[i]+cum[i-1])%mod)
		} else {
			last = i
			j := 1 + i - len(pat)

			soln = append(soln, soln[i-1]+1+j)
			if j > 0 {
				soln[i] += cum[j-1]
			}

			soln[i] %= mod
			cum = append(cum, (soln[i]+cum[i-1])%mod)

			carry = (soln[i] - soln[i-1] + mod) % mod
		}
	}

	return (soln[len(soln)-1] + mod) % mod
}

func main() {
	fmt.Println(b494())
}
