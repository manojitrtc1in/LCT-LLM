package main

import (
	"fmt"
	"math"
	"sort"
)

const eol = '\n'

type i64 int64

func main() {
	iterateMain()
}

func iterateMain() {
	for counter := 1; counter <= caseNumber(); counter++ {
		mainCase()
	}
}

func caseNumber() int {
	return 1
}

func mainCase() {
	var n, k i64
	fmt.Scan(&n, &k)
	c := []i64{}
	pf := []i64{}

	for i := i64(0); i < n; i++ {
		var v i64
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

	ini := i64(0)
	base := i64(0)
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

	cs := make([]i64, len(c)+1)
	for i := 0; i < len(c); i++ {
		cs[i+1] = cs[i] + (i / (k + 1)) * c[i]
	}

	sf := make([]i64, len(c)+1)
	sf2 := make([]i64, len(c)+1)
	for i := len(c) - 1; i >= 0; i-- {
		sf[i] = sf[i+1] + c[i]
		sf2[i] = sf2[i+1] + c[i]*i64(i)
	}

	ans := i64(-1e18)
	for j := 0; j <= len(c); j++ {
		if j*(k+1) < len(c) {
			continue
		}
		cd := ceilDiv(len(c)-j, k)
		tp := j - cd
		now := ini * j
		now -= sf2[len(c)-tp] + sf[tp]*(cd-(len(c)-tp))
		now -= cs[len(c)-tp]
		chge(&ans, now)
	}

	ans += base
	fmt.Println(ans)
}

func ceilDiv(x, y i64) i64 {
	if y == 0 {
		panic("division by zero")
	}
	if y < 0 {
		x, y = -x, -y
	}
	if x < 0 {
		return x / y
	}
	return (x + y - 1) / y
}

func chge(ans *i64, now i64) {
	if now > *ans {
		*ans = now
	}
}
