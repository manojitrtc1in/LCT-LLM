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
	fmt.Println(strings.Trim(fmt.Sprint(soln), "[]"))
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

	q := make([][3]int, 0)
	q = append(q, [3]int{0, 0, 0})

	for len(q) > 0 {
		w, j, t := q[0][0], q[0][1], q[0][2]
		q = q[1:]

		if n < j+1+k {
			return "YES"
		}

		if !tag[w][j+1] {
			tag[w][j+1] = true
			q = append(q, [3]int{w, j + 1, t + 1})
		}

		if j > 0 && t+1 < j && !tag[w][j-1] {
			tag[w][j-1] = true
			q = append(q, [3]int{w, j - 1, t + 1})
		}

		if !tag[1-w][j+k] {
			tag[1-w][j+k] = true
			q = append(q, [3]int{1 - w, j + k, t + 1})
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

	for _, a := range xs {
		if charMap[a[0]] == nil {
			charMap[a[0]] = make(map[rune]bool)
		}
		charMap[a[0]][a[1]] = true

		if digitMap[a[1]] == nil {
			digitMap[a[1]] = make(map[rune]bool)
		}
		digitMap[a[1]][a[0]] = true
	}

	id17 := 0
	for _, v := range charMap {
		if allUnique(v) {
			id17++
		}
	}

	id19 := 0
	for _, v := range digitMap {
		if allUnique(v) {
			id19++
		}
	}

	return min(len(digitMap)-1+(len(charMap)-id17-1), len(charMap)-1+(len(digitMap)-id19-1))
}

func allUnique(m map[rune]bool) bool {
	for _, v := range m {
		if !v {
			return false
		}
	}
	return true
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
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
	const m = 1000000007

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
