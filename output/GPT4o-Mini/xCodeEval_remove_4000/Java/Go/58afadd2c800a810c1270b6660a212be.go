package main

import (
	"bytes"
	"fmt"
	"math"
	"os"
)

type F3 struct {
	input string
	primes []int
}

func id0(n int) []int {
	if n <= 32 {
		primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
		for i, prime := range primes {
			if n < prime {
				return primes[:i]
			}
		}
		return primes
	}

	u := n + 32
	lu := math.Log(float64(u))
	ret := make([]int, int(u/lu+u/lu/lu*1.5))
	ret[0] = 2
	pos := 1

	isnp := make([]int, (n+1)/32/2+1)
	sup := (n + 1) / 32 / 2 + 1

	id3 := []int{3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
	for _, tp := range id3 {
		ret[pos] = tp
		pos++
		ptn := make([]int, tp)
		for i := (tp - 3) / 2; i < tp<<5; i += tp {
			ptn[i>>5] |= 1 << (i & 31)
		}
		for j := 0; j < sup; j += tp {
			for i := 0; i < tp && i+j < sup; i++ {
				isnp[j+i] |= ptn[i]
			}
		}
	}

	magic := []int{0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14}
	h := n / 2
	for i := 0; i < sup; i++ {
		for j := ^isnp[i]; j != 0; j &= j - 1 {
			pp := i<<5 | magic[(j&-j)*0x076be629>>27]
			p := 2*pp + 3
			if p > n {
				break
			}
			ret[pos] = p
			pos++
			if int64(p)*int64(p) > int64(n) {
				continue
			}
			for q := (p*p - 3) / 2; q <= h; q += p {
				isnp[q>>5] |= 1 << q
			}
		}
	}

	return ret[:pos]
}

func (f *F3) solve() {
	var n int64
	fmt.Sscanf(f.input, "%d", &n)
	ans := int64(0)
	ml := newId7(n / 2)
	for i := 0; i < len(f.primes); i++ {
		plus := ml.pi(n/f.primes[i]) - int64(i+1)
		if plus <= 0 {
			break
		}
		ans += plus
	}

	for _, p := range f.primes {
		if int64(p)*int64(p)*int64(p) <= n {
			ans++
		} else {
			break
		}
	}
	fmt.Println(ans)
}

type id7 struct {
	primes []int
	xcums []int
	isp []int64
	cachelimit int
	picache map[int64]int64
	cumps [][]int
	FP []int
	M int
	B int
}

func newId7(n int64) *id7 {
	assert(n >= 4)

	picache := make(map[int64]int64)
	FP := []int{2, 3, 5, 7, 11, 13, 17, 19}
	M := len(FP)
	B := 100

	s := int(math.Sqrt(float64(n))) * B
	cachelimit := s
	primes := id0(s)
	xcums := make([]int, (s>>6)+1)
	isp := make([]int64, (s>>6)+1)
	for _, p := range primes {
		isp[p>>6] |= 1 << uint(p)
	}
	for i := 0; i < len(xcums)-1; i++ {
		xcums[i+1] = xcums[i] + int(bits.OnesCount64(isp[i]))
	}

	cumps := make([][]int, M)
	b := []bool{true}
	len := 1
	for i := 0; i < M; i++ {
		len *= FP[i]
		c := make([]bool, len)
		for j := 0; j < FP[i]; j++ {
			copy(c[j*len:], b)
		}
		for k := 0; k < len; k += FP[i] {
			c[k] = false
		}
		cumps[i] = make([]int, len+1)
		for j := 0; j < len; j++ {
			cumps[i][j+1] = cumps[i][j] + boolToInt(c[j])
		}
		FP[i] = len
		b = c
	}

	return &id7{primes: primes, xcums: xcums, isp: isp, cachelimit: cachelimit, picache: picache, cumps: cumps, FP: FP, M: M, B: B}
}

func (i *id7) pi(x int64) int64 {
	if x <= int64(i.cachelimit) {
		ix := int(x)
		return int64(i.xcums[ix>>6] + bits.OnesCount64(i.isp[ix>>6]<<uint(^ix)))
	}
	if val, exists := i.picache[x]; exists {
		return val
	}

	A := int(i.pi(int64(math.Sqrt(float64(math.Sqrt(float64(x)))))))
	ret := int64(A) + i.phi(x, A) - i.P2(x, A) - i.P3(x, A) - 1
	i.picache[x] = ret
	return ret
}

func (i *id7) phi(x int64, A int) int64 {
	if A > 0 && A-1 < i.M {
		return int64(i.cumps[A-1][i.FP[A-1]])*(x/int64(i.FP[A-1])) + int64(i.cumps[A-1][int(x%int64(i.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(i.primes[A-1])*int64(i.primes[A-1]) {
		return i.pi(x) - int64(A) + 1
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= i.phi(x/int64(i.primes[i]), i)
	}
	return ret
}

func (i *id7) P2(x int64, A int) int64 {
	B := int(i.pi(int64(math.Sqrt(float64(x)))))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += i.pi(x/int64(i.primes[i]))
	}
	ret -= int64(B-A) * (int64(B+A-1) / 2)
	return ret
}

func (i *id7) P3(x int64, A int) int64 {
	C := int(i.pi(id6(x)))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(i.primes[i])
		B := int(i.pi(int64(math.Sqrt(float64(xi)))))
		for j := i; j < B; j++ {
			ret += i.pi(xi/int64(i.primes[j])) - int64(j)
		}
	}
	return ret
}

func id6(n int64) int64 {
	i := int64(math.Max(0, math.Sqrt(float64(n))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
}

func assert(condition bool) {
	if !condition {
		panic("Assertion failed")
	}
}

func main() {
	f := F3{input: "100000000000"}
	f.primes = id0(400000)
	f.solve()
}
