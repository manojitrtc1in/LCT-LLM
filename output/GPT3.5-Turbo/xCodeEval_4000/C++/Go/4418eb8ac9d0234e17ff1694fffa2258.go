package main

import (
	"fmt"
)

const (
	maxn = 100100
	mod  = 998244353
)

var (
	n         int
	orig      [maxn]struct {
		first  int64
		second struct {
			first  int64
			second int64
		}
	}
	all_info  [maxn][4][]Info
	temp_info [4][]Info
	all_size  int
)

type Info struct {
	time struct {
		first  int64
		second int64
	}
	p int64
}

func Merge(a, b []Info) []Info {
	ans := make([]Info, 0, len(a)+len(b))
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i].time.first*b[j].time.second == a[i].time.second*b[j].time.first {
			ans = append(ans, Info{
				time: struct {
					first  int64
					second int64
				}{a[i].time.first, a[i].time.second},
				p: (a[i].p + b[j].p) % mod,
			})
			i++
			j++
		} else if a[i].time.first*b[j].time.second < a[i].time.second*b[j].time.first {
			if a[i].p != 0 {
				ans = append(ans, a[i])
			}
			i++
		} else {
			if b[j].p != 0 {
				ans = append(ans, b[j])
			}
			j++
		}
	}
	for i < len(a) {
		ans = append(ans, a[i])
		i++
	}
	for j < len(b) {
		ans = append(ans, b[j])
		j++
	}
	return ans
}

func MergeDp(a, b []Info) []Info {
	ra := make([]Info, len(a))
	copy(ra, a)
	rb := make([]Info, len(b))
	copy(rb, b)
	for i, j, sum := 0, 0, int64(0); i < len(a); i++ {
		for j < len(b) && b[j].time.first*b[j].time.second >= a[i].time.first*a[i].time.second {
			sum = (sum + b[j].p) % mod
			j++
		}
		ra[i].p = (ra[i].p * sum) % mod
	}
	for i, j, sum := 0, 0, int64(0); j < len(b); j++ {
		for i < len(a) && a[i].time.first*a[i].time.second > b[j].time.first*b[j].time.second {
			sum = (sum + a[i].p) % mod
			i++
		}
		rb[j].p = (rb[j].p * sum) % mod
	}
	return Merge(ra, rb)
}

func main() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&orig[i].first, &orig[i].second.first, &orig[i].second.second)
		orig[i].second.second *= pow(100, mod-2, mod)
		orig[i].second.second %= mod
	}

	for l := 0; l < n-1; l++ {
		for cate := 0; cate < 4; cate++ {
			r := l + 1
			p := int64(1)
			dv := int64(0)
			if cate&1 == 1 {
				p = (p * (mod + 1 - orig[l].second.second)) % mod
				dv += orig[l].second.first
			} else {
				dv -= orig[l].second.first
			}
			if cate&2 == 2 {
				p = (p * (mod + 1 - orig[r].second.second)) % mod
				dv -= orig[r].second.first
			} else {
				dv += orig[r].second.first
			}
			dv = max(0, dv)
			p %= mod
			all_info[l][cate] = []Info{{struct {
				first  int64
				second int64
			}{orig[r].first - orig[l].first, dv}, p}}
			all_size++
		}
	}
	for i := 0; (1 << i) < n-1; i++ {
		for j := 0; j*(1<<(i+1)) < n-1; j++ {
			no_a := j * (1 << (i + 1))
			no_b := no_a + (1 << i)
			if no_b >= n-1 {
				continue
			}
			for f1 := 0; f1 < 2; f1++ {
				for f2 := 0; f2 < 2; f2++ {
					rans1 := MergeDp(all_info[no_a][f1], all_info[no_b][f2<<1])
					p1 := pow(mod+1-orig[no_b].second.second, mod-2, mod)
					for i := range rans1 {
						rans1[i].p = (rans1[i].p * p1) % mod
					}
					rans2 := MergeDp(all_info[no_a][f1+2], all_info[no_b][(f2<<1)+1])
					p2 := pow(orig[no_b].second.second, mod-2, mod)
					for i := range rans2 {
						rans2[i].p = (rans2[i].p * p2) % mod
					}
					temp_info[f1+(f2<<1)] = Merge(rans1, rans2)
				}
			}
			for i := 0; i < 4; i++ {
				all_info[no_a][i] = temp_info[i]
			}
		}
	}

	ans := int64(0)
	for cate := 0; cate < 4; cate++ {
		for _, it := range all_info[0][cate] {
			if it.time.second != 0 {
				ans = (ans + it.p*it.time.first%mod*pow(it.time.second, mod-2, mod)) % mod
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func pow(n, m, mod int64) int64 {
	if m < 0 {
		return 0
	}
	ans := int64(1)
	k := n
	for m > 0 {
		if m&1 == 1 {
			ans = (ans * k) % mod
		}
		k = (k * k) % mod
		m >>= 1
	}
	return ans
}
