package main

import (
	"fmt"
	"math"
)

const nax = 5e5 + 44

var cou [nax]int
var prev [nax]int
var less [nax]int

func sum(l, r int) int {
	if l < 0 || r < 0 || l >= nax || r >= nax {
		panic("index out of bounds")
	}
	return less[r] - less[l]
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cou[x]++
	}
	for i := 1; i < nax; i++ {
		less[i] = less[i-1] + cou[i-1]
	}
	p := 0
	for i := 0; i < nax; i++ {
		prev[i] = p
		if cou[i] > 0 {
			p = i
		}
	}
	var ans int64 = 0
	for y := 2; y < nax; y++ {
		low, high := 2, nax-1
		var all int64 = 0
		for i := 1; i*y < nax; i++ {
			all += int64(i) * int64(sum(i*y, int(math.Min(float64(nax-1), float64(i*y+y)))))
		}
		if all == 0 {
			continue
		}
		for low <= high {
			x := (low + high) / 2
			canGet := false
			if x%y == 0 {
				canGet = (sum(x, nax-1) >= 2 || sum(int(math.Min(float64(nax-1), float64(2*x))), nax-1) >= 1) && (all-2*(int64(x/y)) >= int64(x))
			} else {
				best := int64(-1)
				if sum(x, nax-1) >= 2 {
					save := 0
					smallLoss := x / y
					for i := 0; i < nax; i += y {
						top := int(math.Min(float64(nax-1), float64(i+y)))
						g := prev[top]
						if g != 0 && g >= int(math.Max(float64(i), float64(x))) && g%y >= x%y {
							if cou[g] >= 2 {
								save += 2
							} else {
								save++
								gg := prev[g]
								if gg >= int(math.Max(float64(i), float64(x))) && gg%y >= x%y && gg != 0 {
									save++
								}
							}
						}
					}
					best = int64(all) - int64(smallLoss)*2 - int64(math.Max(0, float64(2-save)))
				}
				if 2*x < nax && sum(2*x, nax-1) >= 1 {
					waste := nax
					for i := 0; i < nax; i += y {
						top := int(math.Min(float64(nax-1), float64(i+y)))
						g := prev[top]
						if g >= 2*x {
							waste = int(math.Min(float64(waste), float64(g/y-(g-2*x)/y)))
						}
					}
					best = int64(math.Max(float64(best), float64(all-waste)))
				}
				if best >= int64(x) {
					canGet = true
				}
			}
			if canGet {
				ans = int64(math.Max(float64(ans), float64(x)*float64(y)))
				low = x + 1
			} else {
				high = x - 1
			}
		}
	}
	fmt.Println(ans)
}
