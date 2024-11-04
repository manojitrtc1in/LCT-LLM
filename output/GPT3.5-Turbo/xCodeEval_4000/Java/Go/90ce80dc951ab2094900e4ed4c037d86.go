package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	T := 1

	for t := 0; t < T; t++ {
		K := nextInt()
		F := make([]int64, 6)
		for i := 0; i < 6; i++ {
			F[i] = nextInt64()
		}

		q := nextInt()
		W := nextInt()

		solution(K, F, W)
	}
}

func solution(K int, F []int64, W int) {
	res := int64(0)
	ten := []int64{1, 10, 100, 1000, 10000, 100000}

	A := make([]Item, 0)

	K--

	if K == 0 {
		num := strconv.Itoa(W)
		str := reverseString(num)
		score := int64(0)
		for k := 0; k < len(str); k++ {
			d, _ := strconv.Atoi(string(str[k]))
			if d%3 == 0 {
				score += F[k] * int64(d/3)
			}
		}
		msg(strconv.FormatInt(score, 10))
		return
	}

	for i := 0; i < 6; i++ {
		weight := ten[i] * 3

		cur := int64(0)
		for j := 0; j < 32; j++ {
			goVal := int64(1 << j)
			if cur+goVal >= int64(3*K) {
				remain := int64(3*K) - cur
				item := Item{weight * remain, F[i] * remain, i}
				A = append(A, item)
				break
			}
			item := Item{weight * (1 << j), F[i] * (1 << j), i}
			cur += (1 << j)
			A = append(A, item)
		}
	}

	pre := make([]int64, W+1)
	dp := make([]int64, W+1)
	for i := 0; i < len(pre); i++ {
		pre[i] = -1
	}
	pre[0] = 0

	for i := 1; i < len(A); i++ {
		item := A[i-1]
		dp = make([]int64, W+1)
		for j := 0; j < len(dp); j++ {
			dp[j] = -1
		}
		dp[0] = 0
		for j := 1; j < len(dp); j++ {
			dp[j] = max(dp[j], pre[j])
			w := item.w
			val := item.val
			if int64(j) < w || pre[j-int64(w)] == -1 {
				continue
			}
			dp[j] = max(dp[j], pre[j-int64(w)]+val)
			num := strconv.Itoa(W - j)
			str := reverseString(num)
			score := int64(0)
			for k := 0; k < len(str); k++ {
				d, _ := strconv.Atoi(string(str[k]))
				if d%3 == 0 {
					score += F[k] * int64(d/3)
				}
			}
			res = max(res, dp[j]+score)
		}
		pre = dp
	}

	msg(strconv.FormatInt(res, 10))
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func nextInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInt64() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func msg(s string) {
	fmt.Println(s)
}
