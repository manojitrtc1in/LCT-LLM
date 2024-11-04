package main

import (
	"fmt"
	"math"
	"sort"
)

type Vector2D struct {
	x, y int64
}

func (v Vector2D) CrossProduct(other Vector2D) int64 {
	return v.x*other.y - other.x*v.y
}

func (v Vector2D) Subtract(other Vector2D) Vector2D {
	return Vector2D{v.x - other.x, v.y - other.y}
}

func (v Vector2D) Angle() float64 {
	return math.Atan2(float64(v.x), float64(v.y))
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]Vector2D, n)
	index := make(map[[2]int]int)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		index[[2]int{int(a[i].x), int(a[i].y)}] = i
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i].x < a[j].x
	})

	var d string
	fmt.Scan(&d)

	// Reverse the string
	runes := []rune(d)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	d = string(runes)

	ans := []Vector2D{a[0]}
	a = a[1:]

	for len(a) > 0 {
		td := 1
		if len(d) > 0 {
			if d[len(d)-1] == 'L' {
				td = 1
			} else {
				td = -1
			}
			d = d[:len(d)-1]
		}

		cur := 0
		for i := 0; i < len(a); i++ {
			if a[cur].Subtract(ans[len(ans)-1]).CrossProduct(a[i].Subtract(ans[len(ans)-1]))*int64(td) < 0 {
				cur = i
			}
		}
		ans = append(ans, a[cur])
		a = append(a[:cur], a[cur+1:]...)
	}

	aaa := make([]int, len(ans))
	for i, t := range ans {
		aaa[i] = index[[2]int{int(t.x), int(t.y)}] + 1
	}

	for i, v := range aaa {
		if i == len(aaa)-1 {
			fmt.Print(v)
		} else {
			fmt.Print(v, " ")
		}
	}
	fmt.Println()
}
