package main

import (
	"fmt"
	"math"
)

const (
	maxn = 100100
	mod  = 998244353
	eps  = 1e-10
)

type pll struct {
	first, second int64
}

type Info struct {
	time pll
	p    int64
}

func (a Info) Less(b Info) bool {
	return a.time.first*b.time.second < a.time.second*b.time.first
}

func (a Info) Equal(b Info) bool {
	return a.time.first*b.time.second == a.time.second*b.time.first
}

func (a Info) Greater(b Info) bool {
	return b.Less(a)
}

func Merge(a, b []Info) []Info {
	ans := make([]Info, 0, len(a)+len(b))
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i].Equal(b[j]) {
			ans = append(ans, Info{time: a[i].time, p: (a[i].p + b[j].p) % mod})
			i++
			j++
		} else if a[i].Greater(b[j]) {
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

	for i, j, sum := int64(0), int64(0), int64(0); i < int64(len(a)); i++ {
		for j < int64(len(b)) && rb[j].Greater(ra[i]) {
			sum = (sum + rb[j].p) % mod
			j++
		}
		ra[i].p = (ra[i].p * sum) % mod
	}
	for i, j, sum := int64(0), int64(0), int64(0); j < int64(len(b)); j++ {
		for i < int64(len(a)) && ra[i].Greater(rb[j]) {
			sum = (sum + ra[i].p) % mod
			i++
		}
		rb[j].p = (rb[j].p * sum) % mod
	}
	return Merge(ra, rb)
}

func pow(n, m, mod int64) int64 {
	if m < 0 {
		return 0
	}
	ans := int64(1)
	k := n
	for m > 0 {
		if m&1 != 0 {
			ans = (ans * k) % mod
		}
		k = (k * k) % mod
		m >>= 1
	}
	return ans
}

func main() {
	var n int
	fmt.Scan(&n)

	orig := make([]struct {
		first  int64
		second pll
	}, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&orig[i].first, &orig[i].second.first, &orig[i].second.second)
		orig[i].second.second = (orig[i].second.second * pow(100, mod-2, mod)) % mod
	}

	all_info := make([][4][]Info, maxn)
	all_size := 0

	for l := 0; l < n-1; l++ {
		for cate := 0; cate < 4; cate++ {
			r := l + 1
			p := int64(1)
			dv := int64(0)
			if cate&1 != 0 {
				p = (p * orig[l].second.second) % mod
				dv += orig[l].second.first
			} else {
				p = (p * (mod + 1 - orig[l].second.second)) % mod
				dv -= orig[l].second.first
			}
			if cate&2 != 0 {
				p = (p * orig[r].second.second) % mod
				dv -= orig[r].second.first
			} else {
				p = (p * (mod + 1 - orig[r].second.second)) % mod
				dv += orig[r].second.first
			}
			if dv < 0 {
				dv = 0
			}
			all_info[l][cate] = []Info{{time: pll{orig[r].first - orig[l].first, dv}, p: p}}
			all_size++
		}
	}

	temp_info := make([][]Info, 4)

	for i := 0; (1 << i) < (n - 1); i++ {
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
					for k := range rans1 {
						rans1[k].p = (rans1[k].p * p1) % mod
					}
					rans2 := MergeDp(all_info[no_a][f1+2], all_info[no_b][(f2<<1)+1])
					p2 := pow(orig[no_b].second.second, mod-2, mod)
					for k := range rans2 {
						rans2[k].p = (rans2[k].p * p2) % mod
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
