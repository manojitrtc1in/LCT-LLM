package main

import (
	"fmt"
)

type Info struct {
	time [2]int64
	p    int64
}

func Merge(a, b []Info) []Info {
	ans := make([]Info, 0)
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i].time[0]*b[j].time[1] == a[i].time[1]*b[j].time[0] {
			ans = append(ans, Info{a[i].time, (a[i].p + b[j].p) % mod})
			i++
			j++
		} else if a[i].time[0]*b[j].time[1] < a[i].time[1]*b[j].time[0] {
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
	rb := make([]Info, len(b))
	copy(ra, a)
	copy(rb, b)
	for i, j, sum := 0, 0, int64(0); i < len(a); i++ {
		for j < len(b) && b[j].time[0]*a[i].time[1] >= b[j].time[1]*a[i].time[0] {
			sum = (sum + b[j].p) % mod
			j++
		}
		ra[i].p = (ra[i].p * sum) % mod
	}
	for i, j, sum := 0, 0, int64(0); j < len(b); j++ {
		for i < len(a) && a[i].time[0]*b[j].time[1] > a[i].time[1]*b[j].time[0] {
			sum = (sum + a[i].p) % mod
			i++
		}
		rb[j].p = (rb[j].p * sum) % mod
	}
	return Merge(ra, rb)
}

func main() {
	var n int
	fmt.Scan(&n)
	orig := make([][3]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&orig[i][0], &orig[i][1], &orig[i][2])
		orig[i][2] = (orig[i][2] * pow(100, mod-2, mod)) % mod
	}

	allInfo := make([][][4]Info, n-1)
	allSize := 0

	for l := 0; l < n-1; l++ {
		for cate := 0; cate < 4; cate++ {
			r := l + 1
			p := int64(1)
			dv := int64(0)
			if cate&1 == 1 {
				p = (p * (mod + 1 - orig[l][2])) % mod
				dv += orig[l][1]
			} else {
				p = (p * orig[l][2]) % mod
				dv -= orig[l][1]
			}
			if cate&2 == 2 {
				p = (p * (mod + 1 - orig[r][2])) % mod
				dv -= orig[r][1]
			} else {
				p = (p * orig[r][2]) % mod
				dv += orig[r][1]
			}
			dv = max(0, dv)
			allInfo[l][cate] = []Info{{[2]int64{orig[r][0] - orig[l][0], dv}, p}}
			allSize++
		}
	}

	for i := 0; (1 << i) < (n - 1); i++ {
		for j := 0; j*(1<<(i+1)) < n-1; j++ {
			noA := j * (1 << (i + 1))
			noB := noA + (1 << i)
			if noB >= n-1 {
				continue
			}
			for f1 := 0; f1 < 2; f1++ {
				for f2 := 0; f2 < 2; f2++ {
					rans1 := MergeDp(allInfo[noA][f1], allInfo[noB][f2<<1])
					p1 := pow(mod+1-orig[noB][2], mod-2, mod)
					for i := 0; i < len(rans1); i++ {
						rans1[i].p = (rans1[i].p * p1) % mod
					}
					rans2 := MergeDp(allInfo[noA][f1+2], allInfo[noB][(f2<<1)+1])
					p2 := pow(orig[noB][2], mod-2, mod)
					for i := 0; i < len(rans2); i++ {
						rans2[i].p = (rans2[i].p * p2) % mod
					}
					tempInfo := Merge(rans1, rans2)
					for i := 0; i < 4; i++ {
						allInfo[noA][i] = tempInfo
					}
				}
			}
		}
	}

	ans := int64(0)
	for cate := 0; cate < 4; cate++ {
		for _, it := range allInfo[0][cate] {
			if it.time[1] != 0 {
				ans = (ans + it.p*it.time[0]%mod*pow(it.time[1], mod-2, mod)) % mod
			}
		}
	}
	fmt.Println(ans)
}

const (
	maxn = 100100
	mod  = 998244353
)

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

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
