package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	out    *bufio.Writer
	inf    int64 = 1e10
	primes []int
	si     []int
	mod    int64 = 998244353
	num    int64 = 1e9 + 7
	memo   [][]int64
	n      int
	k      int64
	m      float64
	a      []int
	s      []rune
	pr     map[int]bool
	factors []int
	times   []int
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	t := nextInt(sc)
	for t > 0 {
		n := nextInt(sc)
		k := nextInt64(sc)
		d := nextInt(sc)
		a := make([]int, n)
		hm := make(map[int]int)
		occ := make([]int, n+1)
		id := 0
		for i := 0; i < n; i++ {
			a[i] = nextInt(sc)
			if _, ok := hm[a[i]]; !ok {
				hm[a[i]] = id
				id++
			}
		}
		for i := 0; i < n; i++ {
			a[i] = hm[a[i]]
		}
		ans := 0
		for i := 0; i < d; i++ {
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans++
			}
		}
		ansl := ans
		for i := d; i < n; i++ {
			ans1 := ansl
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans1++
			}
			occ[a[i-d]]--
			if occ[a[i-d]] == 0 {
				ans1--
			}
			ans = min(ans, ans1)
			ansl = ans1
		}
		fmt.Fprintln(out, ans)
		t--
	}
	out.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func inver(x int64) int64 {
	a := x
	e := mod - 2
	res := int64(1)
	for e > 0 {
		if e&1 == 1 {
			res = (res * a) % mod
		}
		a = (a * a) % mod
		e >>= 1
	}
	return res % mod
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	num, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return num
}
