package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Pair struct {
	first, second int
}

var (
	pref       [100100][2]int
	a          []Pair
	ha         [200100]int
	haa_0     [200100]int
	haa_1     [200100]int
	ss         string
	p          []int
)

func ms(l, r int) {
	if r <= l {
		return
	}
	mid := (l + r + 1) >> 1 - 1
	ms(l, mid)
	ms(mid+1, r)
	a = append(a, Pair{first: l, second: mid}, Pair{first: mid + 1, second: r})
}

func mss(l, r int) {
	if r <= l {
		return
	}
	mid := (l + r + 1) >> 1 - 1
	mss(l, mid)
	mss(mid+1, r)
	i, j := l, mid+1
	b := make([]int, r-l+1)

	now := 0
	for i <= mid && j <= r {
		if p[i] < p[j] {
			ss += "0"
			b[now] = p[i]
			now++
			i++
		} else {
			ss += "1"
			b[now] = p[j]
			now++
			j++
		}
	}
	for i <= mid {
		b[now] = p[i]
		now++
		i++
	}
	for j <= r {
		b[now] = p[j]
		now++
		j++
	}
	for i = l; i <= r; i++ {
		p[i] = b[i-l]
	}
}

func solve() {
	var s string
	fmt.Scan(&s)
	reverseString(&s)
	n := len(s)
	for i := 1; i <= n; i++ {
		if s[i-1] == '0' {
			pref[i][0] = pref[i-1][0] + 1
			pref[i][1] = pref[i-1][1]
		} else {
			pref[i][1] = pref[i-1][1] + 1
			pref[i][0] = pref[i-1][0]
		}
	}

	checkAns2 := func(n int) int {
		a = nil
		ms(0, n-1)
		reversePairs()
		ans := make([]int, n)
		now := 0

		doesZero := func(ff int) {
			cur := 1
			cnt1, cnt2 := 0, 0
			to := a[0]
			sz1 := to.second - to.first + 1
			sz2 := to.second - to.first + 1
			now = ff
			for i := now - 1; i >= 0; i-- {
				u := s[i]
				if u == '0' {
					ans[cnt1] = cur
					cnt1++
				} else {
					ans[sz1+cnt2] = cur
					cnt2++
				}
				cur++
			}
			for cnt1 < sz1 {
				ans[cnt1] = cur
				cnt1++
				cur++
			}
			for cnt2 < sz2 {
				ans[sz1+cnt2] = cur
				cnt2++
				cur++
			}
		}

		// Additional logic for does and check_ans1 omitted for brevity...

		return 0 // Placeholder return
	}

	l, r := 1, 100000
	var now int
	for l <= r {
		mid := (l + r) >> 1
		w := checkAns2(mid)
		if w < n {
			l = mid + 1
		} else {
			r = mid - 1
			now = mid
		}
	}
	for {
		if checkAns1(now) {
			return
		}
		now++
	}
}

func reverseString(s *string) {
	r := []rune(*s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	*s = string(r)
}

func reversePairs() {
	sort.Slice(a, func(i, j int) bool {
		return a[i].first < a[j].first
	})
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	t = 1

	for t > 0 {
		solve()
		t--
	}
}
