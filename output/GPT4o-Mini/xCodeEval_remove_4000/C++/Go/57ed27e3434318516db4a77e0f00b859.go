package main

import (
	"fmt"
)

const N = int(1e6) + 9

var (
	C   [N]int
	n   int
	str string
	use [1200]bool
)

func Add(x, d int) {
	for x <= n {
		C[x] += d
		x += lowBit(x)
	}
}

func Sum(x int) int {
	res := 0
	for x > 0 {
		res += C[x]
		x ^= lowBit(x)
	}
	return res
}

func lowBit(x int) int {
	return x & -x
}

func main() {
	fmt.Scan(&str)
	res := int64(1)
	zero := int64(0)
	all := int64(10)
	n = len(str)

	for i := 0; i < n; i++ {
		if i == 0 {
			if str[i] >= 'A' && str[i] <= 'J' {
				res *= 9
				all--
				use[str[i]] = true
			} else if str[i] == '?' {
				res *= 9
			}
		} else {
			if str[i] >= 'A' && str[i] <= 'J' {
				if use[str[i]] {
					continue
				}
				use[str[i]] = true
				res *= all
				all--
			} else if str[i] == '?' {
				zero++
			}
		}
	}
	fmt.Print(res)
	for zero > 0 {
		fmt.Print("0")
		zero--
	}
	fmt.Println()
}
