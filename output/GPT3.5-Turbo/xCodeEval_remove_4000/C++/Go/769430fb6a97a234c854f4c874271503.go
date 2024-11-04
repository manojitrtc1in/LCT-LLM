package main

import (
	"fmt"
)

func umax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func umin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func abs(a int) int {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a int, b int) int {
	return a / gcd(a, b) * b
}

func modpow(a int, n int, temp int) int {
	res := 1
	y := a
	for n > 0 {
		if n&1 == 1 {
			res = (res * y) % temp
		}
		y = (y * y) % temp
		n /= 2
	}
	return res % temp
}

func ison(mask int, pos int) int {
	return (mask & (1 << pos))
}

type vi []int
type vvi [][]int
type pii struct {
	first  int
	second int
}

func cbit(n int) int {
	k := 0
	for n != 0 {
		n &= (n - 1)
		k++
	}
	return k
}

func nbit(n int) int {
	k := 0
	for n != 0 {
		n /= 2
		k++
	}
	return k
}

const mod = 1e9 + 7

func sgn(x int) int {
	if x < 0 {
		return -1
	} else {
		return 1
	}
}

const eps = 1e-7
const pi = 3.14159265358979323846

func inc(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func dec(x *int, y int) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func chmax(x *int, y int) {
	if y > *x {
		*x = y
	}
}

func mulm(x *int, y int) {
	*x *= y
	if *x >= mod {
		*x -= mod
	}
}

func xo(i int) int {
	if (i & 3) == 0 {
		return i
	}
	if (i & 3) == 1 {
		return 1
	}
	if (i & 3) == 2 {
		return i + 1
	}
	return 0
}

type ver struct {
	first  int
	second pii
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	var num []int
	for r > 0 {
		num = append(num, r%10)
		r /= 10
	}
	n := len(num)
	for i := 0; i < n/2; i++ {
		num[i], num[n-i-1] = num[n-i-1], num[i]
	}
	ans := 0
	dp := make([][][][][]int, 20)
	memo := make([][][][][]int, 20)
	for i := 0; i < 20; i++ {
		dp[i] = make([][][][]int, 2)
		memo[i] = make([][][][]int, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([][][]int, 2)
			memo[i][j] = make([][][]int, 2)
			for k := 0; k < 2; k++ {
				dp[i][j][k] = make([][]int, 10)
				memo[i][j][k] = make([][]int, 10)
				for l := 0; l < 10; l++ {
					dp[i][j][k][l] = make([]int, 10)
					memo[i][j][k][l] = make([]int, 10)
				}
			}
		}
	}
	ans = solve(0, 1, 0, 0, 0, dp, memo, num, n)

	num = nil
	for l > 0 {
		num = append(num, l%10)
		l /= 10
	}
	n = len(num)
	for i := 0; i < n/2; i++ {
		num[i], num[n-i-1] = num[n-i-1], num[i]
	}
	ans -= solve(0, 1, 0, 0, 0, dp, memo, num, n)

	num = nil
	for k > 0 {
		num = append(num, k%10)
		k /= 10
	}
	if num[0] == num[n-1] {
		ans++
	}
	fmt.Println(ans)
}

func solve(ind int, ti int, st int, f int, pd int, dp [][][][][]int, memo [][][][][]int, num []int, n int) int {
	if ind == n {
		if st > 0 && f == pd {
			return 1
		}
		return 0
	}
	if memo[ind][ti][st][f][pd] == 1 {
		return dp[ind][ti][st][f][pd]
	}
	res := 0
	memo[ind][ti][st][f][pd] = 1
	if ti == 1 {
		for i := 0; i < num[ind]; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i, dp, memo, num, n)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i, dp, memo, num, n)
				} else {
					res += solve(ind+1, 0, st, f, i, dp, memo, num, n)
				}
			}
		}
		if num[ind] == 0 {
			res += solve(ind+1, 1, st, f, 0, dp, memo, num, n)
		} else {
			if st == 0 {
				res += solve(ind+1, 1, 1, num[ind], num[ind], dp, memo, num, n)
			} else {
				res += solve(ind+1, 1, st, f, num[ind], dp, memo, num, n)
			}
		}
	} else {
		for i := 0; i < 10; i++ {
			if i == 0 {
				res += solve(ind+1, 0, st, f, i, dp, memo, num, n)
			}
			if i > 0 {
				if st == 0 {
					res += solve(ind+1, 0, 1, i, i, dp, memo, num, n)
				} else {
					res += solve(ind+1, 0, st, f, i, dp, memo, num, n)
				}
			}
		}
	}
	dp[ind][ti][st][f][pd] = res
	return res
}
