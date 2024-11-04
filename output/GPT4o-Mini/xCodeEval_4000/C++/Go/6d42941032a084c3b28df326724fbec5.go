package main

import (
	"fmt"
	"math"
)

const M = 998244353

func inverse(a, n int) int {
	c := coolGCD(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func prod(a, b, M int) int {
	return (int64(a) * int64(b)) % int64(M)
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

type pii struct {
	X, Y int
}

func coolGCD(a, b int) pii {
	if b == 0 {
		return pii{1, 0}
	}
	c := a / b
	ans1 := coolGCD(b, a-b*c)
	return pii{ans1.Y, ans1.X - ans1.Y*c}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	W1, W2 := 0, 0
	for i := 0; i < n; i++ {
		if a[i] == 1 {
			W1 += w[i]
		} else {
			W2 += w[i]
		}
	}

	probs := make([]int, m+1)
	probs[0] = 1

	for i := 0; i < m; i++ {
		newProbs := make([]int, m+1)
		for d1 := 0; d1 <= i; d1++ {
			d2 := d1 - i
			w1 := W1 + d1
			w2 := W2 + d2
			w0 := w1 + w2
			if probs[d1] > 0 && w2 >= 0 {
				invW0 := inverse(w0, M)
				if w2 > 0 {
					newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, invW0, M), M), M)
				}
				newProbs[d1+1] = sum(newProbs[d1+1], prod(probs[d1], prod(w1, invW0, M), M), M)
			}
		}
		probs = newProbs
	}

	afterOps1 := make([]int, m+1)
	afterOps2 := make([]int, m+1)
	afterOps1[0] = 1
	afterOps2[0] = 1

	for i := 1; i <= m; i++ {
		afterOps1[i] = prod(afterOps1[i-1], sum(1, inverse(W1+i-1, M), M), M)
	}

	for i := 1; i <= m; i++ {
		afterOps2[i] = prod(afterOps2[i-1], raz(1, inverse(W2-i+1, M), M), M)
	}

	coef1, coef2 := 0, 0
	for i := 0; i <= m; i++ {
		coef1 = sum(coef1, prod(afterOps1[i], probs[i], M), M)
	}
	for i := 0; i <= m; i++ {
		coef2 = sum(coef2, prod(afterOps2[i], probs[m-i], M), M)
	}

	for i := 0; i < n; i++ {
		if a[i] == 1 {
			fmt.Println(prod(w[i], coef1, M))
		} else {
			fmt.Println(prod(w[i], coef2, M))
		}
	}
}
