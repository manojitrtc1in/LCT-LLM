package main

import (
	"fmt"
	"math/cmplx"
)

type ModInt struct {
	v uint
	mod uint
}

func NewModInt(value int64, mod uint) ModInt {
	return ModInt{normS(uint(value%int64(mod) + int64(mod)), mod), mod}
}

func (m ModInt) normS(x uint) uint {
	if x < m.mod {
		return x
	}
	return x - m.mod
}

func (m ModInt) Add(b ModInt) ModInt {
	return NewModInt(int64(m.normS(m.v + b.v)), m.mod)
}

func (m ModInt) Sub(b ModInt) ModInt {
	return NewModInt(int64(m.normS(m.v + m.mod - b.v)), m.mod)
}

func (m ModInt) Mul(b ModInt) ModInt {
	return NewModInt(int64((uint64(m.v) * uint64(b.v)) % m.mod), m.mod)
}

func (m ModInt) Inv() ModInt {
	x, y := int64(0), int64(0)
	g := extgcd(int64(m.v), int64(m.mod), &x, &y)
	return NewModInt(uint((x+m.mod)%m.mod), m.mod)
}

func extgcd(a, b int64, x, y *int64) int64 {
	p := []int64{a, 1, 0}
	q := []int64{b, 0, 1}
	for q[0] != 0 {
		t := p[0] / q[0]
		for i := 0; i < 3; i++ {
			p[i] -= t * q[i]
			p[i], q[i] = q[i], p[i]
		}
	}
	if p[0] < 0 {
		for i := 0; i < 3; i++ {
			p[i] = -p[i]
		}
	}
	*x, *y = p[1], p[2]
	return p[0]
}

func (m ModInt) Pow(p int64) ModInt {
	if p < 0 {
		return m.Inv().Pow(-p)
	}
	a := NewModInt(1, m.mod)
	x := m
	for p > 0 {
		if p&1 != 0 {
			a = a.Mul(x)
		}
		x = x.Mul(x)
		p >>= 1
	}
	return a
}

func (m ModInt) String() string {
	return fmt.Sprintf("%d", m.v)
}

func fft(typeFlag bool, c []complex128) {
	N := len(c)
	s := bsr(N)
	buf := make([][]complex128, 30)
	if buf[s] == nil {
		buf[s] = make([]complex128, N)
		for i := 0; i < N; i++ {
			buf[s][i] = cmplx.Rect(1, float64(i*2*math.Pi/float64(N)))
		}
	}
	a := make([]complex128, N)
	copy(a, c)
	b := make([]complex128, N)

	for i := 1; i <= s; i++ {
		W := 1 << (s - i)
		for y := 0; y < N/2; y += W {
			now := buf[s][y]
			if typeFlag {
				now = cmplx.Conj(now)
			}
			for x := 0; x < W; x++ {
				l := a[y<<1|x]
				r := now * a[y<<1|x|W]
				b[y|x] = l + r
				b[y|x|N>>1] = l - r
			}
		}
		copy(a, b)
	}
	copy(c, a)
}

func bsr(x int) int {
	return 31 - bits.LeadingZeros32(uint32(x))
}

func main() {
	var N int
	fmt.Scan(&N)

	fact := make([]ModInt, 2000010)
	ifact := make([]ModInt, 2000010)
	InitFact(fact, ifact)

	solve := func(N int64) ModInt {
		res := NewModInt(0, 998244353)
		for i := int64(0); i <= N; i++ {
			if i == 0 {
				for j := int64(1); j <= N; j++ {
					res = res.Add(NewModInt(-1, 998244353).Pow(i+j).Mul(Choose(N, j)).Mul(NewModInt(3, 998244353).Pow(j + N*(N-j))))
				}
			} else {
				res = res.Add(NewModInt(-1, 998244353).Pow(i).Mul(Choose(N, i)).Mul((NewModInt(3, 998244353).Pow(N-i).Sub(NewModInt(1, 998244353))).Pow(N).Sub(NewModInt(3, 998244353).Pow((N-i)*N))).Mul(3))
				res = res.Add(NewModInt(-1, 998244353).Pow(i).Mul(Choose(N, i)).Mul(NewModInt(3, 998244353).Pow(i + N*(N-i))))
			}
		}
		return res
	}

	fmt.Println(solve(int64(N)).String())
}

func InitFact(fact, ifact []ModInt) {
	fact[0] = NewModInt(1, 998244353)
	for i := 1; i < len(fact); i++ {
		fact[i] = fact[i-1].Mul(NewModInt(int64(i), 998244353))
	}
	ifact[len(fact)-1] = fact[len(fact)-1].Inv()
	for i := len(fact) - 2; i >= 0; i-- {
		ifact[i] = ifact[i+1].Mul(NewModInt(int64(i+1), 998244353))
	}
}

func Choose(a, b int64) ModInt {
	if b < 0 || a < b {
		return NewModInt(0, 998244353)
	}
	return fact[a].Mul(ifact[b]).Mul(ifact[a-b])
}
