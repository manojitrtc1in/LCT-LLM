package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pair struct {
	first  int
	second int
}

type pairPair struct {
	first  pair
	second pair
}

var a []pairPair
var pref [][]int
var ha []int
var haa_0 []int
var haa_1 []int

func ms(l int, r int) {
	if r <= l {
		return
	}
	mid := ((l + r + 1) >> 1) - 1
	ms(l, mid)
	ms(mid+1, r)
	a = append(a, pairPair{pair{l, mid}, pair{mid + 1, r}})
}

var ss string
var p []int

func mss(l int, r int) {
	if r <= l {
		return
	}
	mid := ((l + r + 1) >> 1) - 1
	mss(l, mid)
	mss(mid+1, r)
	i := l
	j := mid + 1
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	s := scanner.Text()
	s = reverse(s)
	n := len(s)

	pref = make([][]int, n+1)
	for i := 0; i <= n; i++ {
		pref[i] = make([]int, 2)
	}

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
		a = make([]pairPair, 0)
		ms(0, n-1)
		reverse(a)
		ans := make([]int, n)
		now := 0

		doesZero := func(ff int) {
			cur := 1
			cnt1 := 0
			cnt2 := 0
			to := a[0]
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			cnt1 = 0
			cnt2 = 0
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

		does := func(delta int, _ int) {
			to := a[_]
			cnt1 := 0
			cnt2 := 0
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			was := now
			fir := make([]int, sz1)
			sec := make([]int, sz2)
			cnt1 = 0
			cnt2 = 0
			f := to.first.first
			now += delta
			for i := now - 1; i >= was; i-- {
				if s[i] == '0' {
					fir[cnt1] = ans[f]
					cnt1++
				} else {
					sec[cnt2] = ans[f]
					cnt2++
				}
				f++
			}
			for cnt1 < sz1 {
				fir[cnt1] = ans[f]
				cnt1++
				f++
			}
			for cnt2 < sz2 {
				sec[cnt2] = ans[f]
				cnt2++
				f++
			}
			for i := to.first.first; i <= to.first.second; i++ {
				ans[i] = fir[i-to.first.first]
			}
			for i := to.second.first; i <= to.second.second; i++ {
				ans[i] = sec[i-to.second.first]
			}
		}

		dp := make([]map[int]bool, len(a)+1)
		for i := 0; i <= len(a); i++ {
			dp[i] = make(map[int]bool)
		}
		dp[0][0] = true
		y := -1e9
		for i := 0; i < len(a); i++ {
			if len(dp[i]) == 0 {
				break
			}
			to := a[i]
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			prevVal := -123
			prevW := -1
			wasCnt1 := 0
			wasCnt2 := 0
			for k, v := range dp[i] {
				cnt1 := 0
				cnt2 := 0
				w := k
				if prevVal+1 == k {
					cnt1 = wasCnt1
					cnt2 = wasCnt2
					w = prevW
					if s[prevVal] == '0' {
						cnt1--
					} else {
						cnt2--
					}
				}
				for w < len(s) && cnt1 < sz1 && cnt2 < sz2 {
					if s[w] == '0' {
						cnt1++
					} else {
						cnt2++
					}
					w++
				}
				if cnt1 < sz1 && cnt2 < sz2 {
					continue
				}
				prevVal = k
				prevW = w
				wasCnt1 = cnt1
				wasCnt2 = cnt2
				if cnt1 == sz1 {
					if s[k] != '0' {
						continue
					}
				} else {
					if s[k] != '1' {
						continue
					}
				}
				if i+1 == len(a) {
					y = max(y, w)
				}
				dp[i+1][w] = true
				for w < len(s) {
					if s[w] == '0' {
						if cnt1+1 < sz1 {
							cnt1++
						} else {
							break
						}
					} else {
						if cnt2+1 < sz2 {
							cnt2++
						} else {
							break
						}
					}
					w++
					dp[i+1][w] = true
					if i+1 == len(a) {
						y = max(y, w)
					}
				}
			}
		}
		if _, ok := dp[len(a)][len(s)]; !ok {
			return 123
		}
		dp = make([]map[int]bool, len(a)+1)
		from := make([]map[int]int, len(a)+1)
		for i := 0; i <= len(a); i++ {
			dp[i] = make(map[int]bool)
			from[i] = make(map[int]int)
		}
		dp[0][0] = true
		for i := 0; i < len(a); i++ {
			if len(dp[i]) == 0 {
				break
			}
			to := a[i]
			for k, v := range dp[i] {
				cnt1 := 0
				cnt2 := 0
				sz1 := to.first.second - to.first.first + 1
				sz2 := to.second.second - to.second.first + 1
				w := k
				for w < len(s) && cnt1 < sz1 && cnt2 < sz2 {
					if s[w] == '0' {
						cnt1++
					} else {
						cnt2++
					}
					w++
				}
				if cnt1 < sz1 && cnt2 < sz2 {
					continue
				}
				if cnt1 == sz1 {
					if s[k] != '0' {
						continue
					}
				} else {
					if s[k] != '1' {
						continue
					}
				}
				dp[i+1][w] = true
				from[i+1][w] = k
				for w < len(s) {
					if s[w] == '0' {
						if cnt1+1 < sz1 {
							cnt1++
						} else {
							break
						}
					} else {
						if cnt2+1 < sz2 {
							cnt2++
						} else {
							break
						}
					}
					w++
					dp[i+1][w] = true
					from[i+1][w] = k
				}
			}
		}
		if _, ok := dp[len(a)][len(s)]; !ok {
			return 123
		}
		x := make([]int, 0)
		now = 0
		ha := len(s)
		for j := len(a); j > 0; j-- {
			f := from[j][ha]
			x = append(x, ha-f)
			ha = f
		}
		reverse(x)
		doesZero(x[0])
		if len(x) != len(a) {
			panic("x size is not equal to a size")
		}
		for ii := 1; ii < len(x); ii++ {
			does(x[ii], ii)
		}
		fmt.Println(n)
		for _, to := range ans {
			fmt.Printf("%d ", to)
		}
		fmt.Println()
		return y
	}

	checkAns1 := func(n int) bool {
		a = make([]pairPair, 0)
		ms(0, n-1)
		reverse(a)
		ans := make([]int, n)
		now := 0

		doesZero := func(ff int) {
			cur := 1
			cnt1 := 0
			cnt2 := 0
			to := a[0]
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			cnt1 = 0
			cnt2 = 0
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

		does := func(delta int, _ int) {
			to := a[_]
			cnt1 := 0
			cnt2 := 0
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			was := now
			fir := make([]int, sz1)
			sec := make([]int, sz2)
			cnt1 = 0
			cnt2 = 0
			f := to.first.first
			now += delta
			for i := now - 1; i >= was; i-- {
				if s[i] == '0' {
					fir[cnt1] = ans[f]
					cnt1++
				} else {
					sec[cnt2] = ans[f]
					cnt2++
				}
				f++
			}
			for cnt1 < sz1 {
				fir[cnt1] = ans[f]
				cnt1++
				f++
			}
			for cnt2 < sz2 {
				sec[cnt2] = ans[f]
				cnt2++
				f++
			}
			for i := to.first.first; i <= to.first.second; i++ {
				ans[i] = fir[i-to.first.first]
			}
			for i := to.second.first; i <= to.second.second; i++ {
				ans[i] = sec[i-to.second.first]
			}
		}

		dp := make([]map[int]bool, len(a)+1)
		for i := 0; i <= len(a); i++ {
			dp[i] = make(map[int]bool)
		}
		dp[0][0] = true
		for i := 0; i < len(a); i++ {
			if len(dp[i]) == 0 {
				break
			}
			to := a[i]
			sz1 := to.first.second - to.first.first + 1
			sz2 := to.second.second - to.second.first + 1
			prevVal := -123
			prevW := -1
			wasCnt1 := 0
			wasCnt2 := 0
			for k, v := range dp[i] {
				cnt1 := 0
				cnt2 := 0
				w := k
				if prevVal+1 == k {
					cnt1 = wasCnt1
					cnt2 = wasCnt2
					w = prevW
					if s[prevVal] == '0' {
						cnt1--
					} else {
						cnt2--
					}
				}
				for w < len(s) && cnt1 < sz1 && cnt2 < sz2 {
					if s[w] == '0' {
						cnt1++
					} else {
						cnt2++
					}
					w++
				}
				if cnt1 < sz1 && cnt2 < sz2 {
					continue
				}
				prevVal = k
				prevW = w
				wasCnt1 = cnt1
				wasCnt2 = cnt2
				if cnt1 == sz1 {
					if s[k] != '0' {
						continue
					}
				} else {
					if s[k] != '1' {
						continue
					}
				}
				dp[i+1][w] = true
				for w < len(s) {
					if s[w] == '0' {
						if cnt1+1 < sz1 {
							cnt1++
						} else {
							break
						}
					} else {
						if cnt2+1 < sz2 {
							cnt2++
						} else {
							break
						}
					}
					w++
					dp[i+1][w] = true
				}
			}
		}
		if _, ok := dp[len(a)][len(s)]; !ok {
			return false
		}
		dp = make([]map[int]bool, len(a)+1)
		from := make([]map[int]int, len(a)+1)
		for i := 0; i <= len(a); i++ {
			dp[i] = make(map[int]bool)
			from[i] = make(map[int]int)
		}
		dp[0][0] = true
		for i := 0; i < len(a); i++ {
			if len(dp[i]) == 0 {
				break
			}
			to := a[i]
			for k, v := range dp[i] {
				cnt1 := 0
				cnt2 := 0
				sz1 := to.first.second - to.first.first + 1
				sz2 := to.second.second - to.second.first + 1
				w := k
				for w < len(s) && cnt1 < sz1 && cnt2 < sz2 {
					if s[w] == '0' {
						cnt1++
					} else {
						cnt2++
					}
					w++
				}
				if cnt1 < sz1 && cnt2 < sz2 {
					continue
				}
				if cnt1 == sz1 {
					if s[k] != '0' {
						continue
					}
				} else {
					if s[k] != '1' {
						continue
					}
				}
				dp[i+1][w] = true
				from[i+1][w] = k
				for w < len(s) {
					if s[w] == '0' {
						if cnt1+1 < sz1 {
							cnt1++
						} else {
							break
						}
					} else {
						if cnt2+1 < sz2 {
							cnt2++
						} else {
							break
						}
					}
					w++
					dp[i+1][w] = true
					from[i+1][w] = k
				}
			}
		}
		if _, ok := dp[len(a)][len(s)]; !ok {
			return false
		}
		x := make([]int, 0)
		now = 0
		ha := len(s)
		for j := len(a); j > 0; j-- {
			f := from[j][ha]
			x = append(x, ha-f)
			ha = f
		}
		reverse(x)
		doesZero(x[0])
		if len(x) != len(a) {
			panic("x size is not equal to a size")
		}
		for ii := 1; ii < len(x); ii++ {
			does(x[ii], ii)
		}
		fmt.Println(n)
		for _, to := range ans {
			fmt.Printf("%d ", to)
		}
		fmt.Println()
		return true
	}

	now := 0
	l := 1
	r := 1e5
	for l <= r {
		mid := ((l + r) >> 1)
		w := checkAns2(mid)
		if w < len(s) {
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

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	_t := 1

	for _t > 0 {
		_t--
		solve()
	}
}
