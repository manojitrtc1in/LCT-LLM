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

type Pair struct {
	first  int64
	second int64
}

var a [MX]int64

func id0() {
	// No equivalent in Go, as it doesn't require sync with I/O
}

func nod(a, b int64) int64 {
	if b > a {
		a, b = b, a
	}
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func nok(a, b int64) int64 {
	return a * b / nod(a, b)
}

func sp(a int64, b float64) {
	fmt.Printf(fmt.Sprintf("%%.%df\n", a), b)
}

func binpow(a, n int64) int64 {
	if n == 0 {
		return 1
	}
	if n%2 == 1 {
		return binpow(a, n-1) * a
	} else {
		b := binpow(a, n/2)
		return b * b
	}
}

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
	id0()
	t := readInt()
	for i := int64(1); i <= t; i++ {
		solve()
	}
}
