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

func newModint(n int, special bool) modint {
	if special {
		return modint{-1}
	}
	if n >= 0 && n < mod {
		return modint{n}
	}
	n %= mod
	if n < 0 {
		n += mod
	}
	return modint{n}
}

func (a modint) add(b modint) modint {
	if a.n == -1 || b.n == -1 {
		panic("Illegal state")
	}
	a.n += b.n
	if a.n >= mod {
		a.n -= mod
	}
	return a
}

func (a modint) sub(b modint) modint {
	if a.n == -1 || b.n == -1 {
		panic("Illegal state")
	}
	a.n -= b.n
	if a.n < 0 {
		a.n += mod
	}
	return a
}

func (a modint) mul(b modint) modint {
	if a.n == -1 || b.n == -1 {
		panic("Illegal state")
	}
	a.n = (a.n * b.n) % mod
	return a
}

func (a modint) div(b modint) modint {
	if b.n == 0 {
		panic("Division by zero")
	}
	if a.n == -1 || b.n == -1 {
		panic("Illegal state")
	}
	return a.mul(b.inv())
}

func (a modint) neg() modint {
	if a.n == -1 {
		panic("Illegal state")
	}
	if a.n == 0 {
		return modint{0}
	}
	return modint{mod - a.n}
}

func (a modint) inv() modint {
	if a.n == -1 {
		panic("Illegal state")
	}
	x, y := gcd(int64(a.n), int64(mod))
	if x < 0 {
		x += int64(mod)
	}
	return modint{int(x)}
}

func gcd(a, b int64) (int64, int64) {
	if a == 0 {
		return 0, 1
	}
	x, y := gcd(b%a, a)
	x -= (b / a) * y
	return y, x
}

func (a modint) log(alpha modint) int {
	if a.n == -1 || alpha.n == -1 {
		panic("Illegal state")
	}
	base := make(map[modint]int)
	exp := 0
	pow := modint{1}
	inv := a
	alInv := alpha.inv()
	for exp*exp < mod {
		if inv.n == 1 {
			return exp
		}
		base[inv] = exp
		exp++
		pow = pow.mul(alpha)
		inv = inv.mul(alInv)
	}
	step := pow
	for i := 1; ; i++ {
		if val, ok := base[pow]; ok {
			return exp*i + val
		}
		pow = pow.mul(step)
	}
}

type FenwickTree struct {
	value []modint
}

func newFenwickTree(size int) *FenwickTree {
	value := make([]modint, size)
	return &FenwickTree{value}
}

func (ft *FenwickTree) add(at int, v modint) {
	for at < len(ft.value) {
		ft.value[at] = ft.value[at].add(v)
		at |= at + 1
	}
}

func (ft *FenwickTree) get(from, to int) modint {
	if from >= to {
		return modint{0}
	}
	return ft.getSum(to-1).sub(ft.getSum(from-1))
}

func (ft *FenwickTree) getSum(to int) modint {
	minim(to, len(ft.value)-1)
	result := modint{0}
	for to >= 0 {
		result = result.add(ft.value[to])
		to = (to & (to + 1)) - 1
	}
	return result
}

func (ft *FenwickTree) clear() {
	for i := range ft.value {
		ft.value[i] = modint{0}
	}
}

func minim(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, _ := strconv.Atoi(readLine(reader))
	m, _ := strconv.Atoi(readLine(reader))

	ft := newFenwickTree(n + 1)
	ft.add(n, newModint(1, false))
	for i := n - 1; i >= 1; i-- {
		res := ft.getSum(i + 1)
		for z := 2; z*i <= n; z++ {
			res = res.add(ft.get(i*z, i*z+z))
		}
		ft.add(i, res)
	}
	fmt.Fprintln(writer, ft.get(1, 2))
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str[:len(str)-1]
}
