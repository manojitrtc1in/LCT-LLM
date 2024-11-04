package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = int(1e9) + 7
	EPS     = 1e-9
	PI      = math.Pi
)

var (
	l1, r1, l2, r2, k int
	nums              []int
)

func read() bool {
	_, err := fmt.Scan(&l1, &r1, &l2, &r2, &k)
	return err == nil
}

func calc(x int) int {
	s := fmt.Sprintf("%d", x)
	cur := 1 << (len(s) - 1)
	ans := cur*2 - 1
	fl := true
	for i := 0; i < len(s); i++ {
		if s[i] > '7' {
			ans += 2 * cur
		} else if s[i] > '4' {
			ans += cur
		}
		if s[i] != '7' && s[i] != '4' {
			fl = false
			break
		}
		cur >>= 1
	}
	if fl {
		ans++
	}
	return ans
}

func brute(x, num int) {
	nums = append(nums, num)
	if x == 9 {
		return
	}
	brute(x+1, num*10+4)
	brute(x+1, num*10+7)
}

func solve() {
	nums = []int{}
	brute(0, 0)
	sort.Ints(nums)
	tot := int64(r1-l1+1) * int64(r2-l2+1)

	ok := int64(0)
	for i := 1; i <= len(nums)-k; i++ {
		l := nums[i]
		r := nums[i+k-1]
		pl := nums[i-1] + 1
		pr := INF + 7
		if i+k < len(nums) {
			pr = nums[i+k] - 1
		}
		if l1 <= l && r <= r2 {
			ll := max(l1, pl)
			rr := min(r2, pr)
			ok += max(0, min(l, r1)-ll+1) * int64(max(0, rr-max(r, l2)+1))
		}
		if l2 <= l && r <= r1 {
			ll := max(l2, pl)
			rr := min(r1, pr)
			ok += max(0, min(l, r2)-ll+1) * int64(max(0, rr-max(r, l1)+1))
		}
	}
	if k == 1 {
		for _, it := range nums {
			if l1 <= it && it <= r1 && l2 <= it && it <= r2 {
				ok--
			}
		}
	}

	fmt.Printf("%.15f\n", float64(ok)/float64(tot))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	for read() {
		solve()
	}
}
