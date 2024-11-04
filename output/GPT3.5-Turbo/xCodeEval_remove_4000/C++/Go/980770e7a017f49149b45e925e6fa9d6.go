package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := -1
	b := -1

	tttt := int(math.Sqrt(float64(n)))

	for i := 1; i <= tttt+9; i++ {
		if n%i == 0 {
			t := n / i

			zt := int(math.Sqrt(float64(t)))

			for j := 1; j <= zt+9; j++ {
				if t%j == 0 {
					tt := t / j

					if tt >= 1 {
						ttt := (tt + 2) * (i + 1) * (j + 2)

						if a == -1 {
							a = ttt
						} else if ttt < a {
							a = ttt
						}

						if b == -1 {
							b = ttt
						} else if ttt > b {
							b = ttt
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
						ttt := (tt + 2) * (i + 1) * (j + 2)

						if a == -1 {
							a = ttt
						} else if ttt < a {
							a = ttt
						}

						if b == -1 {
							b = ttt
						} else if ttt > b {
							b = ttt
						}
					}
				}
			}

			i = zz
		}
	}

	fmt.Println(a - n, b - n)
}
