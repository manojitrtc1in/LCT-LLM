package main

import (
	"fmt"
	"math"
	"os"
)

const M = 998244353

func inverse(a, n int) int {
	c := extendedGCD(a, n)
	if c < 0 {
		c += n
	}
	return c
}

func extendedGCD(a, b int) int {
	if b == 0 {
		return 1
	}
	x1 := extendedGCD(b, a%b)
	return x1 - (a/b)*x1
}

func prod(a, b, mod int) int {
	return (int64(a) * int64(b)) % int64(mod)
}

func sum(a, b, mod int) int {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func raz(a, b, mod int) int {
	c := a - b
	if c < 0 {
		c += mod
	}
	return c
}

func main() {
	fin, _ := os.Open("input.txt")
	defer fin.Close()
	fout, _ := os.Create("output.txt")
	defer fout.Close()

	var n, m int
	fmt.Fscanf(fin, "%d %d", &n, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(fin, "%d", &a[i])
	}

	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(fin, "%d", &w[i])
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
		new_probs := make([]int, m+1)
		for d1 := 0; d1 <= i; d1++ {
			d2 := d1 - i
			w1 := W1 + d1
			w2 := W2 + d2
			w0 := w1 + w2
			if probs[d1] > 0 && w2 >= 0 {
				id16 := inverse(w0, M)
				if w2 > 0 {
					new_probs[d1] = sum(new_probs[d1], prod(probs[d1], prod(w2, id16, M), M), M)
				}
				new_probs[d1+1] = sum(new_probs[d1+1], prod(probs[d1], prod(w1, id16, M), M), M)
			}
		}
		probs = new_probs
	}

	id4 := make([]int, m+1)
	id29 := make([]int, m+1)
	id4[0] = 1
	id29[0] = 1

	for i := 1; i <= m; i++ {
		id4[i] = prod(id4[i-1], sum(1, inverse(W1+i-1, M), M), M)
	}

	for i := 1; i <= m; i++ {
		id29[i] = prod(id29[i-1], raz(1, inverse(W2-i+1, M), M), M)
	}

	coef1, coef2 := 0, 0
	for i := 0; i <= m; i++ {
		coef1 = sum(coef1, prod(id4[i], probs[i], M), M)
	}
	for i := 0; i <= m; i++ {
		coef2 = sum(coef2, prod(id29[i], probs[m-i], M), M)
	}

	for i := 0; i < n; i++ {
		if a[i] == 1 {
			fmt.Fprintln(fout, prod(w[i], coef1, M))
		} else {
			fmt.Fprintln(fout, prod(w[i], coef2, M))
		}
	}
}
