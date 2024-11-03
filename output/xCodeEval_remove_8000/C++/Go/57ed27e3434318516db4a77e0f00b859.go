package main

import (
	"fmt"
)

func main() {
	var str string
	fmt.Scan(&str)
	res := int64(1)
	use := make([]bool, 1200)
	zero := int64(0)
	all := int64(10)
	n := len(str)

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
