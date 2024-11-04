package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007
const INF = 0x7fffffff
const EPS = 1e-12
const OO = 1e15

func checkMin(a *int64, b int64) {
	if b < *a {
		*a = b
	}
}

func checkMax(a *int64, b int64) {
	if b > *a {
		*a = b
	}

}

func main() {
	var n int
	fmt.Scan(&n)

	var a, b int64 = -1, -1

	tttt := int(math.Sqrt(float64(n)))

	for i := 1; i <= tttt+9; i++ {
		if n%i == 0 {
			t := n / i
			zt := int(math.Sqrt(float64(t)))

			for j := 1; j <= zt+9; j++ {
				if t%j == 0 {
					tt := t / j
					if tt >= 1 {
						ttt := (tt + 2) * int64(i+1) * int64(j+2)

						if a == -1 {
							a = ttt
						} else {
							checkMin(&a, ttt)
						}

						if b == -1 {
							b = ttt
						} else {
							checkMax(&b, ttt)
						}
					}
				}
			}

			zz := i
			i = n / i

			t = n / i
			zt = int(math.Sqrt(float64(t)))

			for j := 1; j <= zt+9; j++ {
				if t%j == 0 {
					tt := t / j
					if tt >= 1 {
						ttt := (tt + 2) * int64(i+1) * int64(j+2)

						if a == -1 {
							a = ttt
						} else {
							checkMin(&a, ttt)
						}

						if b == -1 {
							b = ttt
						} else {
							checkMax(&b, ttt)
						}
					}
				}
			}

			i = zz
		}
	}

	fmt.Println(a-n, b-n)
}
