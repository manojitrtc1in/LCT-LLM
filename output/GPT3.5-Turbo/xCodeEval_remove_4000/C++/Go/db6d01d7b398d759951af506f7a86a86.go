package main

import (
	"fmt"
	"strings"
)

func main() {
	var a [10]int
	var n int
	var s string
	fmt.Scan(&s)
	n = len(s)
	for i := 0; i < n; i++ {
		a[int(s[i]-'0')]++
	}

	S := -1
	Sx := 0
	Sy := 0
	AS := -1
	ASx := 0
	ASy := 0
	ASz := 0

	chk := func(x, y int) {
		A := a
		B := a
		A[x]--
		B[y]--
		if A[x] < 0 || B[y] < 0 {
			return
		}
		T := 0
		for i := 0; i < 10; i++ {
			T += min(A[i], B[9-i])
		}
		if T > S {
			S = T
			Sx = x
			Sy = y
		}
	}

	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		S = -1
		Sx = 0
		Sy = 0
		chk(1, 9)
		chk(2, 8)
		chk(3, 7)
		chk(4, 6)
		chk(5, 5)
		a[0] += i
		if S == -1 {
			if i >= 1 && i >= AS {
				AS = i
				Sx = 0
				Sy = 0
				ASz = i
			}
			continue
		}
		if S+i+1 > AS {
			AS = S + i + 1
			ASx = Sx
			ASy = Sy
			ASz = i
		}
	}

	if AS <= 0 {
		fmt.Println(s)
		fmt.Println(s)
		return
	}

	if ASx == 0 {
		ASz--
	}

	a[0] -= ASz
	A := a
	B := a
	A[ASx]--
	B[ASy]--

	var resA, resB strings.Builder
	for i := 0; i < 10; i++ {
		for j := 0; j < A[i]-min(A[i], B[9-i]); j++ {
			fmt.Fprintf(&resA, "%d", i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(A[i], B[9-i]); j++ {
			fmt.Fprintf(&resA, "%d", i)
		}
	}
	fmt.Fprintf(&resA, "%d", ASx)
	for i := 0; i < ASz; i++ {
		resA.WriteByte('0')
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < B[9-i]-min(A[i], B[9-i]); j++ {
			fmt.Fprintf(&resB, "%d", 9-i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(A[i], B[9-i]); j++ {
			fmt.Fprintf(&resB, "%d", 9-i)
		}
	}
	fmt.Fprintf(&resB, "%d", ASy)
	for i := 0; i < ASz; i++ {
		resB.WriteByte('0')
	}

	fmt.Println(resA.String())
	fmt.Println(resB.String())
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
