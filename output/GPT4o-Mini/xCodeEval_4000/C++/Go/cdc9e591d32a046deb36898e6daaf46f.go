package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

type int64 = int64

const DOUBLE_INF = math.Inf(1)
const DOUBLE_NAN = math.NaN()

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func b303() {
	var n, m, x, y, a, b int64
	fmt.Scan(&n, &m, &x, &y, &a, &b)

	g := gcd(a, b)
	a /= g
	b /= g

	k := min(m/b, n/a)
	width := k * a
	height := k * b

	x1 := max(x-(width+1)/2, 0)
	x2 := min(x1+width, n)
	x1 = x2 - width

	y1 := max(y-(height+1)/2, 0)
	y2 := min(y1+height, m)
	y1 = y2 - height

	soln := []int64{x1, y1, x2, y2}
	fmt.Println(soln)
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

func xsolve(w, j, t, jumpSize int, wall []string, cache map[[3]int]bool) bool {
	n := len(wall[0])
	if j >= n {
		return true
	} else if j < t || wall[w][j] != '-' {
		return false
	} else {
		tpl := [3]int{w, j, t}

		if _, exists := cache[tpl]; exists {
			return false
		}

		cache[tpl] = true

		if xsolve(1-w, j+jumpSize, t+1, jumpSize, wall, cache) ||
			xsolve(w, j+1, t+1, jumpSize, wall, cache) ||
			(j > 0 && xsolve(w, j-1, t+1, jumpSize, wall, cache)) {
			return true
		}

		return false
	}
}

func b198() string {
	var n, k int
	fmt.Scan(&n, &k)
	wall := make([]string, 2)
	for i := range wall {
		fmt.Scan(&wall[i])
	}

	cache := make(map[[3]int]bool)
	cache[[3]int{0, 0, math.MaxInt}] = true
	cache[[3]int{1, n, math.MaxInt}] = true

	flag := xsolve(1, k, 1, k, wall, cache) || xsolve(0, 1, 1, k, wall, cache)

	if flag {
		return "YES"
	}
	return "NO"
}

func a442() int {
	var xs []string
	fmt.Scan(&xs)

	charMap := make(map[byte]map[byte]struct{})
	digitMap := make(map[byte]map[byte]struct{})

	for _, a := range xs {
		if charMap[a[0]] == nil {
			charMap[a[0]] = make(map[byte]struct{})
		}
		charMap[a[0]][a[1]] = struct{}{}

		if digitMap[a[1]] == nil {
			digitMap[a[1]] = make(map[byte]struct{})
		}
		digitMap[a[1]][a[0]] = struct{}{}
	}

	digitOwn := 0
	for k, v := range charMap {
		allUnique := true
		for ch := range v {
			if len(digitMap[ch]) != 1 {
				allUnique = false
				break
			}
		}
		if allUnique {
			digitOwn++
		}
	}

	charOwn := 0
	for k, v := range digitMap {
		allUnique := true
		for ch := range v {
			if len(charMap[ch]) != 1 {
				allUnique = false
				break
			}
		}
		if allUnique {
			charOwn++
		}
	}

	return min(len(digitMap)-1+(digitOwn < len(charMap)-1), len(charMap)-1+(charOwn < len(digitMap)-1))
}

func a163() uint64 {
	var subj, targ string
	fmt.Scan(&subj, &targ)

	pos := make(map[byte][]int)
	for j := 0; j < len(targ); j++ {
		pos[targ[j]] = append(pos[targ[j]], j)
	}

	val := uint64(0)
	soln := make([]uint64, len(targ)+1)
	xsoln := make([]uint64, len(targ)+1)
	m := uint64(1000000007)

	for _, a := range subj {
		copy(xsoln, soln)
		soln = make([]uint64, len(soln))

		for _, j := range pos[byte(a)] {
			soln[j+1] = (1 + xsoln[j]) % m
		}

		for i := 1; i < len(soln); i++ {
			soln[i] = (soln[i] + soln[i-1]) % m
		}
		val = (val + soln[len(soln)-1]) % m
	}
	return val
}

func main() {
	fmt.Println(a163())
}
