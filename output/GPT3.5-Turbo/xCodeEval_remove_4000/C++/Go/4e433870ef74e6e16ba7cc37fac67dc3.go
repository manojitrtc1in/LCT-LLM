package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	c := make([]int, 0)
	pf := make([]int, 0)
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		if v < 0 {
			c = append(c, -v)
		} else {
			pf = append(pf, v)
		}
	}

	sort.Sort(sort.Reverse(sort.IntSlice(pf)))
	ini := 0
	base := 0
	for _, e := range pf {
		base += ini
		ini += e
	}
	sort.Sort(sort.Reverse(sort.IntSlice(c)))

	if k == 0 {
		for _, e := range c {
			base += ini
			ini -= e
		}
		fmt.Println(base)
		return
	}

	cs := make([]int, len(c)+1)
	for i := 0; i < len(c); i++ {
		cs[i+1] = cs[i] + (i/(k+1))*c[i]
	}
	sf := make([]int, len(c)+1)
	sf2 := make([]int, len(c)+1)
	for i := len(c) - 1; i >= 0; i-- {
		sf[i] = sf[i+1] + c[i]
		sf2[i] = sf2[i+1] + c[i]*i
	}

	ans := -1e18
	for j := 0; j <= len(c); j++ {
		if j*(k+1) < len(c) {
			continue
		}
		cd := (len(c) - j + k) / (k + 1)
		tp := j - cd
		now := ini * j
		now -= sf2[len(c)-tp] + sf[tp]*(cd-(len(c)-tp))
		now -= cs[len(c)-tp]
		if now > ans {
			ans = now
		}
	}

	ans += base
	fmt.Println(ans)
}
