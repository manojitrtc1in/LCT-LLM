package main

import (
	"fmt"
)

var k, m int

func res(s, n int) {
	dem := 10
	if s > k {
		return
	}
	if k-s < 10 {
		for m > 0 && dem < 100 {
			fmt.Printf("%d0%d", dem, k-s)
			if n < 10 {
				fmt.Print("000")
			} else if n < 100 {
				fmt.Print("00")
			} else if n < 1000 {
				fmt.Print("0")
			}
			fmt.Println(n)
			m--
			dem++
		}
		return
	} else if k-s < 100 {
		fmt.Printf("00%d", k-s)
	} else if k-s < 1000 {
		fmt.Printf("0%d", k-s)
	} else if k-s < 10000 {
		fmt.Print(k - s)
	}
	if n < 10 {
		fmt.Print("000")
	} else if n < 100 {
		fmt.Print("00")
	} else if n < 1000 {
		fmt.Print("0")
	}
	fmt.Println(n)
	m--
}

func process() {
	var a, b, c, d, s int
	for i := 0; i < 9999; i++ {
		x := make([]bool, 10000)
		a = i
		d = a % 10
		a /= 10
		c = a % 10
		a /= 10
		b = a % 10
		a /= 10
		s = a * b * c * d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a - b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a - b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a - b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a - b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a*b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a*b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a*b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a*b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a*b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a*b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a*b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a*b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -(a + b*c + d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -(-a + b*c + d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -(a + b*c - d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -(-a + b*c - d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b*c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = (-a + b*c + d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = (a + b*c - d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = (-a + b*c - d)
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b + c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b - c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b + c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a - b - c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b + c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a + b - c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -a - b + c*d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -10*a - b + c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b - c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b + c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b - c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b + 10*c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = 10*a + b - 10*c - d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = -10*a - b + 10*c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
		}
		s = a + b + 10*c + d
		if s > 0 && !x[s] {
			x[s] = true
			res(s, i)
		}
		if m == 0 {
			return
