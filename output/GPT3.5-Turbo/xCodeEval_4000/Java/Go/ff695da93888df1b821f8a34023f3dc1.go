package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var l, r int64
	fmt.Scan(&l, &r)
	fmt.Println(giveAns(r) - giveAns(l-1))
}

func giveAns(x int64) int64 {
	numOfDigits := int64(len(strconv.FormatInt(x, 10)))
	ans := int64(0)
	for i := int64(2); i < numOfDigits; i++ {
		ans += 9 * int64(math.Pow(10, float64(i-2)))
	}
	if numOfDigits > 1 {
		ans += 9
	}
	if numOfDigits == 1 {
		ans += x
	} else {
		firstDigit, _ := strconv.Atoi(string(strconv.FormatInt(x, 10)[0]))
		lastDigit, _ := strconv.Atoi(string(strconv.FormatInt(x, 10)[numOfDigits-1]))
		ans += int64(firstDigit-1) * int64(math.Pow(10, float64(numOfDigits-2)))
		s := strconv.FormatInt(x, 10)
		for j := int64(1); j < numOfDigits-1; j++ {
			val := int64(1)
			digit, _ := strconv.Atoi(string(s[j]))
			val *= (1 * int64(digit) * int64(math.Pow(10, float64(numOfDigits-j-2))))
			ans += val
		}
		if firstDigit <= lastDigit {
			ans++
		}
	}
	return ans
}
