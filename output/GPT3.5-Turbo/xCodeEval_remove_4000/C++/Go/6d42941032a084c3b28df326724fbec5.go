package main

import (
	"fmt"
)

const M = 998244353

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
	W1 := 0
	W2 := 0
	for i := 0; i < n; i++ {
		if a[i] != 0 {
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
			if probs[d1] != 0 && w2 >= 0 {
				id16 := inverse(w0, M)
				if w2 > 0 {
					newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, id16, M), M), M)
				}
				newProbs[d1+1] = sum(newProbs[d1+1], prod(probs[d1], prod(w1, id16, M), M), M)
			}
		}
		probs = newProbs
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
	coef1 := 0
	coef2 := 0
	for i := 0; i <= m; i++ {
		coef1 = sum(coef1, prod(id4[i], probs[i], M), M)
	}
	for i := 0; i <= m; i++ {
		coef2 = sum(coef2, prod(id29[i], probs[m-i], M), M)
	}
	for i := 0; i < n; i++ {
		if a[i] != 0 {
			fmt.Println(prod(w[i], coef1, M))
		} else {
			fmt.Println(prod(w[i], coef2, M))
		}
	}
}

func prod(a, b, M int) int {
	return (a * b) % M
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

func inverse(a, n int) int {
	c := id20(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id20(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	t := a / b
	ans1 := id20(b, a-t*b)
	return ans1.Y, ans1.X - ans1.Y*t
}

func id19(a, b, n int) int {
	k := sqrt(n)
	a1 := id39(a, n)
	l := k + 20
	a2 := po_p(a1, k, n)
	seq1 := make([]int, k)
	seq2 := make([]int, l)
	seq1[0] = 1
	for i := 1; i < k; i++ {
		seq1[i] = pr_p(seq1[i-1], a, n)
	}
	seq2[0] = b
	for i := 1; i < l; i++ {
		seq2[i] = pr_p(seq2[i-1], a2, n)
	}
	e := equal_elements(seq1, seq2)
	if e.X == -1 {
		return -1
	} else {
		return e.X + e.Y*k
	}
}

func equal_elements(u, v []int) (int, int) {
	ans := make([]int, 2)
	ans[0] = -1
	ans[1] = -1
	m := len(u)
	n := len(v)
	i := 0
	j := 0
	for i < m && j < n {
		if u[i] < v[j] {
			i++
		} else if v[j] < u[i] {
			j++
		} else {
			ans[0] = i
			ans[1] = j
			j++
		}
	}
	return ans[0], ans[1]
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func sqrt(x int) int {
	ans := 0
	for x > 0 {
		ans++
		x >>= 1
	}
	return ans
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}
