package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 1e9 + 7
const MX = 200005
const INF = 1e18
const PI = math.Acos(-1)

var a [MX]int64

func readInt() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func readInts(n int) []int64 {
	xs := make([]int64, n)
	for i := 0; i < n; i++ {
		xs[i] = readInt()
	}
	return xs
}

func solve() {
	m := make(map[int64]int64)
	n := readInt()
	s := readInt()
	k := readInt()
	ans := MOD
	cnt := int64(0)

	for i := int64(1); i <= n; i++ {
		a[i] = readInt()
		if i >= k {
			m[a[i-k]]--
			if m[a[i-k]] == 0 {
				cnt--
			}
			m[a[i]]++
			if m[a[i]] == 1 {
				cnt++
			}
			ans = min(ans, cnt)
		} else {
			m[a[i]]++
			if m[a[i]] == 1 {
				cnt++
			}
		}
	}
	ans = min(ans, cnt)
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	t := readInt()
	for i := int64(1); i <= t; i++ {
		solve()
	}
}
