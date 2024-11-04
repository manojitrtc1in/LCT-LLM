package main

import (
	"fmt"
	"math"
)

func main() {
	var l, r int64
	fmt.Scan(&l, &r)
	fmt.Println(giveAns(r) - giveAns(l-1))
}

func giveAns(x int64) int64 {
	id23 := len(fmt.Sprint(x))
	ans := int64(0)
	for i := 2; i < id23; i++ {
		ans += 9 * int64(math.Pow(10, float64(i-2)))
	}
	if id23 > 1 {
		ans += 9
	}
	if id23 == 1 {
		ans += x
	} else {
		firstDigit := int(fmt.Sprint(x)[0] - '0')
		lastDigit := int(fmt.Sprint(x)[id23-1] - '0')
		ans += int64((firstDigit - 1) * int(math.Pow(10, float64(id23-2))))
		s := fmt.Sprint(x)
		for j := 1; j < id23-1; j++ {
			val := int64(1)
			digit := int(s[j] - '0')
			val *= int64(digit * int(math.Pow(10, float64(id23-j-2))))
			ans += val
		}
		if firstDigit <= lastDigit {
			ans++
		}
	}
	return ans
}
