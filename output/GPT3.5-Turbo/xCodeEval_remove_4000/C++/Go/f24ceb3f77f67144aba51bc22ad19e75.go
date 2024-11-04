package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var mod int = 1000000007

type modint struct {
	n int
}

func newModint(n int, special bool) *modint {
	if special {
		return &modint{-1}
	}
	if n >= 0 && n < mod {
		return &modint{n}
	}
	n %= mod
	if n < 0 {
		n += mod
	}
	return &modint{n}
}

func (m *modint) add(other *modint) {
	if m.n == -1 || other.n == -1 {
		panic("Illegal state")
	}
	m.n += other.n
	if m.n >= mod {
		m.n -= mod
	}
}

func (m *modint) subtract(other *modint) {
	if m.n == -1 || other.n == -1 {
		panic("Illegal state")
	}
	m.n -= other.n
	if m.n < 0 {
		m.n += mod
	}
}

func (m *modint) multiply(other *modint) {
	if m.n == -1 || other.n == -1 {
		panic("Illegal state")
	}
	m.n = (m.n * other.n) % mod
}

func (m *modint) divide(other *modint) {
	if other.n == 0 {
		panic("Division by zero")
	}
	if m.n == -1 || other.n == -1 {
		panic("Illegal state")
	}
	m.multiply(other.inverse())
}

func (m *modint) inverse() *modint {
	if m.n == -1 {
		panic("Illegal state")
	}
	x, y := gcd(int64(m.n), int64(mod))
	if x < 0 {
		x += int64(mod)
	}
	return newModint(int(x), false)
}

func gcd(a, b int64) (int64, int64) {
	if a == 0 {
		return 0, 1
	}
	x, y := gcd(b%a, a)
	x, y = y-x*(b/a), x
	return x, y
}

func (m *modint) log(alpha *modint) int {
	if m.n == -1 || alpha.n == -1 {
		panic("Illegal state")
	}
	base := make(map[*modint]int)
	exp := 0
	pow := newModint(1, false)
	inv := newModint(int64(m.n), false)
	alInv := alpha.inverse()
	for exp*exp < mod {
		if inv.n == 1 {
			return exp
		}
		base[inv] = exp
		exp++
		pow.multiply(alpha)
		inv.multiply(alInv)
	}
	step := pow
	for i := 1; ; i++ {
		if val, ok := base[pow]; ok {
			return exp*i + val
		}
		pow.multiply(step)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	m := nextInt(scanner)

	mod = m
	ft := make([]modint, n+1)
	ft[n] = *newModint(1, false)
	for i := n - 1; i >= 1; i-- {
		res := ft[i+1]
		for z := 2; z*i <= n; z++ {
			res.add(&ft[z*i])
		}
		ft[i] = res
	}
	fmt.Println(ft[1])
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}
