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
	a          []Pair
	pref       [100100][2]int
	ha         [20100]int
	haa_0     [20100]int
	haa_1     [20100]int
	ss         string
)

func ms(l, r int) {
	if r <= l {
		return
	}
	mid := (l + r + 1) >> 1 - 1
	ms(l, mid)
	ms(mid+1, r)
	a = append(a, Pair{l, mid})
	a = append(a, Pair{mid + 1, r})
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
	for i, j := l, 0; i <= r; i, j = i+1, j+1 {
		p[i] = b[j]
	}
}

func solve() {
	var s string
	fmt.Scan(&s)
	reverseString(&s)
	for i := 1; i <= len(s); i++ {
		if s[i-1] == '0' {
			pref[i][0] = pref[i-1][0] + 1
			pref[i][1] = pref[i-1][1]
		} else {
			pref[i][1] = pref[i-1][1] + 1
			pref[i][0] = pref[i-1][0]
		}
	}
	id3 := func(n int) int {
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
		// More logic here...
		return 0 // Placeholder return
	}
	// More logic here...
}

func reverseString(s *string) {
	runes := []rune(*s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	*s = string(runes)
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

	_t := 1
	for _t > 0 {
		solve()
		_t--
	}
	fmt.Fprintf(writer, "\nTime : %v\n", float64(os.CLOCKS_PER_SEC)/float64(os.CLOCKS_PER_SEC))
}
