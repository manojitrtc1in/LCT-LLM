package main

import (
	"fmt"
	"math"
	"strings"
)

var a [10]int
var A, B [10]int
var S, Sx, Sy, AS, ASx, ASy, ASz int

func chk(x, y int) {
	copy(A[:], a[:])
	copy(B[:], a[:])
	A[x]--
	B[y]--
	if A[x] < 0 || B[y] < 0 {
		return
	}
	T := 0
	for i := 0; i < 10; i++ {
		T += int(math.Min(float64(A[i]), float64(B[9-i])))
	}
	if T > S {
		S = T
		Sx = x
		Sy = y
	}
}

func main() {
	var s string
	fmt.Scan(&s)
	n := len(s)
	for i := 0; i < n; i++ {
		a[s[i]-'0']++
	}
	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		S = -1
		Sx = Sy = 0
		chk(1, 9)
		chk(2, 8)
		chk(3, 7)
		chk(4, 6)
		chk(5, 5)
		a[0] += i
		if S == -1 {
			if i >= 1 && i >= AS {
				AS = i
				Sx = Sy = 0
				ASz = i
				continue
			}
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
	copy(A[:], a[:])
	copy(B[:], a[:])
	A[ASx]--
	B[ASy]--

	for i := 0; i < 10; i++ {
		for j := 0; j < A[i]-int(math.Min(float64(A[i]), float64(B[9-i]))); j++ {
			fmt.Print(i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < int(math.Min(float64(A[i]), float64(B[9-i]))); j++ {
			fmt.Print(i)
		}
	}
	fmt.Print(ASx)
	for i := 0; i < ASz; i++ {
		fmt.Print("0")
	}
	fmt.Println()

	for i := 0; i < 10; i++ {
		for j := 0; j < B[9-i]-int(math.Min(float64(A[i]), float64(B[9-i]))); j++ {
			fmt.Print(9 - i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < int(math.Min(float64(A[i]), float64(B[9-i]))); j++ {
			fmt.Print(9 - i)
		}
	}
	fmt.Print(ASy)
	for i := 0; i < ASz; i++ {
		fmt.Print("0")
	}
	fmt.Println()
}
