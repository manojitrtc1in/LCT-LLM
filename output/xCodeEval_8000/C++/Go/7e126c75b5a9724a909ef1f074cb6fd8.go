package main

import (
	"fmt"
	"math"
)

const (
	N1 = 1e5
	B  = 1e5
	N  = 3e8
)

var lp = make([]int, N1+1)
var prime []int

func seive() {
	for i := 2; i <= N1; i++ {
		if lp[i] == 0 {
			lp[i] = i
			prime = append(prime, i)
		}
		for _, j := range prime {
			if j > lp[i] || i*j > N1 {
				break
			}
			lp[i*j] = j
		}
	}
}

func calsum(l, r int) int {
	if l > r {
		return 0
	}
	if l == 0 {
		return csum[r]
	}
	return csum[r] - csum[l-1]
}

func inrange(l, r int) int {
	isp := make([]bool, r-l+1)
	for _, i := range prime {
		if i*i > r {
			break
		}
		st := (l / i) * i
		if st < l {
			st += i
		}
		if st == i {
			st += i
		}
		for cur := st; cur <= r; cur += i {
			isp[cur-l] = false
		}
	}
	ans := 0
	for i, j := 0, l; j <= r; i, j = i+1, j+1 {
		if isp[i] && j%4 == 1 {
			ans++
		}
	}
	if 2 >= l && 2 <= r {
		ans++
	}
	return ans
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	l = int(math.Max(float64(l), 2))
	if l > r {
		fmt.Println(0)
		return
	}

	seive()

	b1 := l / B
	b2 := r / B

