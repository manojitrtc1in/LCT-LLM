package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

var (
	l1, r1, l2, r2 int
	k              int
)

func read() bool {
	if _, err := fmt.Scan(&l1, &r1, &l2, &r2, &k); err != nil {
		return false
	}
	return true
}

func calc(x int) int {
	s := strconv.Itoa(x)
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

var nums []int

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
	tot := int64((r1 - l1 + 1) * (r2 - l2 + 1))

	ok := int64(0)
	for i := 1; i < len(nums)-k+1; i++ {
		l := nums[i]
		r := nums[i+k-1]
		pl := nums[i-1] + 1
		pr := math.MaxInt32
		if i+k == len(nums) {
			pr = math.MaxInt32
		} else {
			pr = nums[i+k] - 1
		}
		if l1 <= l && r <= r2 {
			ll := int(math.Max(float64(l1), float64(pl)))
			rr := int(math.Min(float64(r2), float64(pr)))
			ok += int64(math.Max(0, float64(math.Min(l, r1)-ll+1)) * float64(math.Max(0, rr-math.Max(r, l2)+1)))
		}
		if l2 <= l && r <= r1 {
			ll := int(math.Max(float64(l2), float64(pl)))
			rr := int(math.Min(float64(r1), float64(pr)))
			ok += int64(math.Max(0, float64(math.Min(l, r2)-ll+1)) * float64(math.Max(0, rr-math.Max(r, l1)+1)))
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

func main() {
	for read() {
		solve()
	}
}
