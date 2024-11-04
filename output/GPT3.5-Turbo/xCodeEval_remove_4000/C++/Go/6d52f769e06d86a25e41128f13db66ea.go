package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"strconv"
	"time"
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v pt) String() string {
	str := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			str += ", "
		}
		str += strconv.Itoa(v[i])
	}
	str += "]"
	return str
}

var rnd *rand.Rand

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)
)

var l1, r1, l2, r2 int
var k int

func read() bool {
	_, err := fmt.Scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k)
	if err != nil {
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
		pr := INF + 7
		if i+k < len(nums) {
			pr = nums[i+k] - 1
		}
		if l1 <= l && r <= r2 {
			ll := int(math.Max(float64(l1), float64(pl)))
			rr := int(math.Min(float64(r2), float64(pr)))
			ok += int64(math.Max(0, math.Min(float64(l), float64(r1))-float64(ll)+1)) * int64(math.Max(0, float64(rr)-math.Max(float64(r), float64(l2))+1))
		}
		if l2 <= l && r <= r1 {
			ll := int(math.Max(float64(l2), float64(pl)))
			rr := int(math.Min(float64(r1), float64(pr)))
			ok += int64(math.Max(0, math.Min(float64(l), float64(r2))-float64(ll)+1)) * int64(math.Max(0, float64(rr)-math.Max(float64(r), float64(l1))+1))
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
	rnd = rand.New(rand.NewSource(time.Now().UnixNano()))

	tc := 0
	fmt.Scanf("%d", &tc)
	for tc > 0 {
		read()
		solve()
		tc--
	}
}
