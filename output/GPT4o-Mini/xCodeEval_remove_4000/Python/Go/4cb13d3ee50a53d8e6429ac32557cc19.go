package main

import (
	"bytes"
	"fmt"
	"os"
	"strconv"
)

var mod = 1000000007
var mod1 = 998244353

func main() {
	var n, m, a, b int
	fmt.Scan(&n, &m, &a, &b)
	ans := 3
	if a%m == 1 {
		ans--
	}
	if b%m == 0 || b == n {
		ans--
	}
	if m == 1 {
		fmt.Println(1)
		return
	} else if (a-1)/m == (b-1)/m {
		fmt.Println(1)
		return
	} else if (a%m-b%m)%m == 1 {
		fmt.Println(min(2, ans, (b-1)/m-(a-1)/m+1))
		return
	}
	fmt.Println(min(ans, (b-1)/m-(a-1)/m+1))
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}
