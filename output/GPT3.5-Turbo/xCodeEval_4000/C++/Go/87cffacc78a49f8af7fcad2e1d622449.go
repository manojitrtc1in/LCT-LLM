package main

import (
	"fmt"
)

const (
	M = 1000000007
)

func opp(a, b byte) bool {
	return (a == 'W' && b == 'E') || (a == 'E' && b == 'W') || (a == 'S' && b == 'N') || (a == 'N' && b == 'S')
}

func ccinv(x byte) byte {
	switch x {
	case 'N':
		return 'S'
	case 'S':
		return 'N'
	case 'W':
		return 'E'
	case 'E':
		return 'W'
	}
	return 'W'
}

func main() {
	var r, a, b string
	fmt.Scan(&r)
	fmt.Scan(&a)
	fmt.Scan(&b)
	n := len(a)
	ar := make([]byte, n)
	for i := 0; i < n; i++ {
		ar[i] = ccinv(a[n-i-1])
	}
	va := 0
	vb := 0
	p := 1
	for i := 0; i < n; i++ {
		va = (va*131 + int(ar[i])) % M
		vb = (vb + int(b[n-i-1])*p) % M
		p = (p * 131) % M
		if vb == va {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
