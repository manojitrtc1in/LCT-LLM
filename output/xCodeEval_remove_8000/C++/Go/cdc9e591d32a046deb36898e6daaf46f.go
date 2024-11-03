package main

import (
	"fmt"
	"math"
	"strings"
)

func b303() {
	var n, m, x, y, a, b int64
	fmt.Scan(&n, &m, &x, &y, &a, &b)

	g := gcd(a, b)
	a /= g
	b /= g

	k := min(m/b, n/a)
	width := k * a
	height := k * b

	x1 := max(x-(width+1)/2, int64(0))
	x2 := min(x1+width, n)
	x1 = x2 - width

	y1 := max(y-(height+1)/2, int64(0))
	y2 := min(y1+height, m)
	y1 = y2 - height

	soln := []int64{x1, y1, x2, y2}
	for _, val := range soln {
		fmt.Print(val, " ")
	}
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func b198() string {
	var n, k int
	fmt.Scan(&n, &k)

	var wall []string
	for i := 0; i < 2; i++ {
		var s string
		fmt.Scan(&s)
		wall = append(wall, s)
	}

	tag := make([][]bool, 2)
	for i := 0; i < 2; i++ {
		tag[i] = make([]bool, n)
		for j := 0; j < n; j++ {
			tag[i][j] = wall[i][j] == 'X'
		}
	}

	queue := make([][]int, 0)
	queue = append(queue, []int{0, 0, 0})

	for len(queue) > 0 {
		w, j, t := queue[0][0], queue[0][1], queue[0][2]
		queue = queue[1:]

		if n < j+1+k {
			return "YES"
		}

		if !tag[w][j+1] {
			tag[w][j+1] = true
			queue = append(queue, []int{w, j + 1, t + 1})
		}

		if j > 0 && t+1 < j && !tag[w][j-1] {
			tag[w][j-1] = true
			queue = append(queue, []int{w, j - 1, t + 1})
		}

		if !tag[1-w][j+k] {
			tag[1-w][j+k] = true
			queue = append(queue, []int{1 - w, j + k, t + 1})
		}
	}

	return "NO"
}

func a442() int {
	var n int
	fmt.Scan(&n)

	xs := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&xs[i])
	}

	charMap := make(map[rune]map[rune]bool)
	digitMap := make(map[rune]map[rune]bool)
	for _, s := range xs {
		charMap[rune(s[0])] = make(map[rune]bool)
		digitMap[rune(s[1])] = make(map[rune]bool)
	}

	for _, s := range xs {
		charMap[rune(s[0])][rune(s[1])] = true
		digitMap[rune(s[1])][rune(s[0])] = true
	}

	id17 := 0
	for _, chars := range charMap {
		allUnique := true
		for ch := range chars {
			if len(digitMap[ch]) > 1 {
				allUnique = false
				break
			}
		}
		if allUnique {
			id17++
		}
	}

	id19 := 0
	for _, digits := range digitMap {
		allUnique := true
		for ch := range digits {
			if len(charMap[ch]) > 1 {
				allUnique = false
				break
			}
		}
		if allUnique {
			id19++
		}
	}

	return int(math.Min(float64(len(digitMap)-1+(len(charMap)-id17-1)), float64(len(charMap)-1+(len(digitMap)-id19-1))))
}

func a163() uint64 {
	var subj, targ string
	fmt.Scan(&subj, &targ)

	pos := make(map[rune][]int)
	for j, ch := range targ {
		pos[ch] = append(pos[ch], j)
	}

	val := uint64(0)

	soln := make([]uint64, len(targ)+1)
	id12 := make([]uint64, len(targ)+1)
	m := uint64(1000000007)

	for _, a := range subj {
		soln, id12 = id12, soln
		for j := range soln {
			soln[j] = 0
		}

		for _, j := range pos[a] {
			soln[j+1] = (1 + id12[j]) % m
		}

		for j := 1; j < len(soln); j++ {
			soln[j] = (soln[j] + soln[j-1]) % m
		}

		val = (val + soln[len(soln)-1]) % m
	}

	return val
}

func main() {
	fmt.Println(a163())
}
