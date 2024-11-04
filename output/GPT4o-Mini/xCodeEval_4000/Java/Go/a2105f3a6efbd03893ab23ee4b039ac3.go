package main

import (
	"bytes"
	"fmt"
	"math"
)

type F3 struct {
	primes []int
}

func sieveEratosthenes(n int) []int {
	if n <= 32 {
		primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
		for i, p := range primes {
			if n < p {
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

	tprimes := []int{3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
	for _, tp := range tprimes {
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
	fmt.Scan(&n)
	ans := int64(0)
	if n <= 10 {
		if n >= 6 {
			ans++
		}
		if n >= 8 {
			ans++
		}
		if n >= 10 {
			ans++
		}
		fmt.Println(ans)
		return
	}

	ml := NewMeisselLehmer2(n / 2)
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

type MeisselLehmer2 struct {
	primes     []int
	xcums      []int
	isp        []int64
	cachelimit int
	picache    map[int64]int64
	phicache   map[int64]int64
	cumps      [][]int
	FP         []int
	M          int
	B          int
}

func NewMeisselLehmer2(n int64) *MeisselLehmer2 {
	assert(n >= 4)

	ml := &MeisselLehmer2{
		picache: make(map[int64]int64),
		phicache: make(map[int64]int64),
		FP:      []int{2, 3, 5, 7, 11, 13, 17, 19},
		M:       8,
		B:       100,
	}

	s := int(math.Sqrt(float64(n))) * ml.B
	ml.cachelimit = s
	ml.primes = sieveEratosthenes(s)
	ml.xcums = make([]int, (s>>6)+1)
	ml.isp = make([]int64, (s>>6)+1)
	for _, p := range ml.primes {
		ml.isp[p>>6] |= 1 << uint(p)
	}
	for i := 0; i < len(ml.xcums)-1; i++ {
		ml.xcums[i+1] = ml.xcums[i] + bits.OnesCount(uint(ml.isp[i]))
	}

	ml.cumps = make([][]int, ml.M)
	b := []bool{true}
	len := 1
	for i := 0; i < ml.M; i++ {
		len *= ml.FP[i]
		c := make([]bool, len)
		for j := 0; j < ml.FP[i]; j++ {
			copy(c[j*len:], b)
		}
		for k := 0; k < len; k += ml.FP[i] {
			c[k] = false
		}
		ml.cumps[i] = make([]int, len+1)
		for j := 0; j < len; j++ {
			ml.cumps[i][j+1] = ml.cumps[i][j] + boolToInt(c[j])
		}
		ml.FP[i] = len
		b = c
	}
	return ml
}

func (ml *MeisselLehmer2) pi(x int64) int64 {
	if x <= int64(ml.cachelimit) {
		ix := int(x)
		return int64(ml.xcums[ix>>6] + bits.OnesCount(uint(ml.isp[ix>>6]<<^uint(ix)))
	}
	if val, ok := ml.picache[x]; ok {
		return val
	}

	A := int(ml.pi(sqrt(sqrt(x))))
	ret := A + ml.phi(x, A) - ml.P2(x, A) - ml.P3(x, A) - 1
	ml.picache[x] = ret
	return ret
}

func (ml *MeisselLehmer2) phi(x int64, A int) int64 {
	if A > 0 && A-1 < ml.M {
		return int64(ml.cumps[A-1][ml.FP[A-1]]*(x/int64(ml.FP[A-1]))) + int64(ml.cumps[A-1][x%int64(ml.FP[A-1])+1])
	}
	if A > 0 && x <= int64(ml.primes[A-1])*int64(ml.primes[A-1]) {
		return ml.pi(x) - int64(A) + 1
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= ml.phi(x/int64(ml.primes[i]), i)
	}
	return ret
}

func (ml *MeisselLehmer2) P2(x int64, A int) int64 {
	B := int(ml.pi(sqrt(x)))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += ml.pi(x / int64(ml.primes[i]))
	}
	ret -= int64(B-A) * (int64(B+A-1) / 2)
	return ret
}

func (ml *MeisselLehmer2) P3(x int64, A int) int64 {
	C := int(ml.pi(cbrt(x)))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(ml.primes[i])
		B := int(ml.pi(sqrt(xi)))
		for j := i; j < B; j++ {
			ret += ml.pi(xi / int64(ml.primes[j])) - int64(j)
		}
	}
	return ret
}

func sqrt(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Sqrt(float64(n))))-2))
	for i*i <= n {
		i++
	}
	return i - 1
}

func cbrt(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Cbrt(float64(n))))-2))
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

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	f := F3{primes: sieveEratosthenes(400000)}
	f.solve()
}
