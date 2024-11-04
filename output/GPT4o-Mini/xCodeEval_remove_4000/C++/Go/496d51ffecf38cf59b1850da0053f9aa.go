package main

import (
	"fmt"
	"math"
	"sort"
)

const eps = 0.0000001
const N = 100

var powcnt [N]int
var ans int64

func fastpower(b, p int64) int64 {
	ans := int64(1)
	for p > 0 {
		if p%2 == 1 {
			ans *= b
		}
		b *= b
		p /= 2
	}
	return ans
}

func id0(b, p, m int64) int64 {
	ans := int64(1)
	for p > 0 {
		if p%2 == 1 {
			ans = (ans % m * b % m) % m
		}
		b = (b % m * b % m) % m
		p /= 2
	}
	return ans % m
}

func id1(n int64) string {
	ans := ""
	ch := false
	if n < 0 {
		n *= -1
		ch = true
	}
	if n == 0 {
		return "0"
	}
	for n > 0 {
		mo := n % 10
		ans = string(mo+48) + ans
		n /= 10
	}
	if ch {
		ans = "-" + ans
	}
	return ans
}

func compare(f, s float64) bool {
	return math.Abs(f-s) < eps
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func preprocess(num int64) {
	for i := 30; i >= 0; i-- {
		if num >= (1 << i) {
			num -= (1 << i)
			powcnt[i]++
		}
	}
}

func solve(curp int64) {
	for i := curp; i <= 30; i++ {
		if powcnt[i] > 0 {
			powcnt[i]--
			ans++
			for j := curp; j < i; j++ {
				powcnt[j]++
			}
			break
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	v := make([]int64, 0, m)

	for i := 0; i < n; i++ {
		var x int64
		fmt.Scan(&x)
		preprocess(x)
	}
	for i := 0; i < m; i++ {
		var x int64
		fmt.Scan(&x)
		v = append(v, x)
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i] < v[j]
	})
	for _, value := range v {
		solve(value)
	}
	fmt.Println(ans)
}