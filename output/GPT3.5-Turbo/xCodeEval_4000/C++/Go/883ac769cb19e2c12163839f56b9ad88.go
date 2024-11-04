package main

import (
	"fmt"
)

const nax = 5e5 + 44

var cou [nax]int
var prev [nax]int
var less [nax]int

func sum(l, r int) int {
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
		if cou[i] != 0 {
			p = i
		}
	}

	var ans int64
	for y := 2; y < nax; y++ {
		low := 2
		high := nax - 1
		all := int64(0)

		for i := 1; i*y < nax; i++ {
			all += int64(i) * int64(sum(i*y, min(nax-1, i*y+y)))
		}

		if all == 0 {
			continue
		}

		for low <= high {
			x := (low + high) / 2
			canGet := false

			if x%y == 0 {
				canGet = (sum(x, nax-1) >= 2 || sum(min(nax-1, 2*x), nax-1) >= 1) && (all-2*(x/y) >= int64(x))
			} else {
				best := int64(-1)

				if sum(x, nax-1) >= 2 {
					save := 0
					smallLoss := x / y

					for i := 0; i < nax; i += y {
						top := min(nax-1, i+y)
						g := prev[top]

						if g != 0 && g >= max(i, x) && g%y >= x%y {
							if cou[g] >= 2 {
								save += 2
							} else {
								save++
								gg := prev[g]

								if gg >= max(i, x) && gg%y >= x%y && gg != 0 {
									save++
								}
							}
						}
					}

					maxi(&best, all-smallLoss*2-max(0, 2-save))
				}

				if 2*x < nax && sum(2*x, nax-1) >= 1 {
					waste := nax

					for i := 0; i < nax; i += y {
						top := min(nax-1, i+y)
						g := prev[top]

						if g >= 2*x {
							mini(&waste, g/y-(g-2*x)/y)
						}
					}

					maxi(&best, all-waste)
				}

				if best >= int64(x) {
					canGet = true
				}
			}

			if canGet {
				maxi(&ans, int64(x)*int64(y))
				low = x + 1
			} else {
				high = x - 1
			}
		}
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a *int64, b int64) {
	if *a < b {
		*a = b
	}
}

func mini(a *int, b int) {
	if *a > b {
		*a = b
	}
}
