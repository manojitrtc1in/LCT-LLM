package main

import (
	"fmt"
)

func checkMin(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func min(a, b, c int) int {
	if a < b && a < c {
		return a
	} else if b < c {
		return b
	} else {
		return c
	}
}

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
	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		S = -1
		Sx = 0
		Sy = 0
		chk(&a, &S, &Sx, &Sy, 1, 9)
		chk(&a, &S, &Sx, &Sy, 2, 8)
		chk(&a, &S, &Sx, &Sy, 3, 7)
		chk(&a, &S, &Sx, &Sy, 4, 6)
		chk(&a, &S, &Sx, &Sy, 5, 5)
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
	A := make([]int, 10)
	B := make([]int, 10)
	copy(A[:], a[:])
	copy(B[:], a[:])
	A[ASx]--
	B[ASy]--
	for i := 0; i < 10; i++ {
		for j := 0; j < A[i]-min(A[i], B[9-i]); j++ {
			fmt.Print(i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(A[i], B[9-i]); j++ {
			fmt.Print(i)
		}
	}
	fmt.Print(ASx)
	for i := 0; i < ASz; i++ {
		fmt.Print(0)
	}
	fmt.Println()
	for i := 0; i < 10; i++ {
		for j := 0; j < B[9-i]-min(A[i], B[9-i]); j++ {
			fmt.Print(9 - i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(A[i], B[9-i]); j++ {
			fmt.Print(9 - i)
		}
	}
	fmt.Print(ASy)
	for i := 0; i < ASz; i++ {
		fmt.Print(0)
	}
	fmt.Println()
}

func chk(a *[10]int, S *int, Sx *int, Sy *int, x, y int) {
	A := *a
	B := *a
	A[x]--
	B[y]--
	if A[x] < 0 || B[y] < 0 {
		return
	}
	T := 0
	for i := 0; i < 10; i++ {
		T += min(A[i], B[9-i])
	}
	checkMin(S, T)
	if *S == T {
		*Sx = x
		*Sy = y
	}
}
