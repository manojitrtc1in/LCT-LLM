package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	iterateMain()
}

var caseid uint

func caseNumber() uint {
	return 1
}

func iterateMain() {
	for total := caseNumber(); caseid < total; caseid++ {
		mainFunc()
	}
}

func mainFunc() {
	var n, k int64
	fmt.Scan(&n, &k)

	c := []int64{}
	pf := []int64{}

	for i := int64(0); i < n; i++ {
		var v int64
		fmt.Scan(&v)
		if v < 0 {
			c = append(c, -v)
		} else {
			pf = append(pf, v)
		}
	}

	sort.Slice(pf, func(i, j int) bool {
		return pf[i] > pf[j]
	})

	ini := int64(0)
	base := int64(0)
	for _, e := range pf {
		base += ini
		ini += e
	}

	sort.Slice(c, func(i, j int) bool {
		return c[i] > c[j]
	})

	if k == 0 {
		for i := len(c) - 1; i >= 0; i-- {
			base += ini
			ini -= c[i]
		}
		fmt.Println(base)
		return
	}

	cs := make([]int64, len(c)+1)
	for i := 0; i < len(c); i++ {
		cs[i+1] = cs[i] + (i/(k+1))*c[i]
	}

	sf := make([]int64, len(c)+1)
	sf2 := make([]int64, len(c)+1)
	for i := len(c) - 1; i >= 0; i-- {
		sf[i] = sf[i+1] + c[i]
		sf2[i] = sf2[i+1] + c[i]*int64(i)
	}

	ans := int64(-1e18)
	for j := int64(0); j <= int64(len(c)); j++ {
		if j*(k+1) < int64(len(c)) {
			continue
		}
		cd := ceilDiv(int64(len(c))-j, k)
		tp := j - cd
		now := ini * j
		now -= sf2[len(c)-int(tp)] + sf[tp]*(cd-(int64(len(c))-tp))
		now -= cs[len(c) - int(tp)]
		if now > ans {
			ans = now
		}
	}

	ans += base
	fmt.Println(ans)
}

func ceilDiv(x, y int64) int64 {
	if y == 0 {
		panic("division by zero")
	}
	return (x + y - 1) / y
}
