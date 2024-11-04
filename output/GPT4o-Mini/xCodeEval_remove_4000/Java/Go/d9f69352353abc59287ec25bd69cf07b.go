package main

import (
	"bytes"
	"fmt"
	"math"
)

type F3 struct {
	primes []int
}

func id0(n int) []int {
	if n <= 32 {
		primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}
		for i := 0; i < len(primes); i++ {
			if n < primes[i] {
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
	fmt.Scan(&n)
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
	primes     []int
	xcums      []int
	isp        []int64
	cachelimit int
	picache    map[int64]int64
	id1        map[int64]int64
	cachePhi   bool
	cumps      [][]int
	FP         []int
	M          int
	B          int
}

func newId7(n int64) *id7 {
	assert(n >= 4)

	picache := make(map[int64]int64)
	id1 := make(map[int64]int64)

	s := int(math.Sqrt(float64(n))) * 100
	cachelimit := s
	primes := id0(s)
	xcums := make([]int, (s>>6)+1)
	isp := make([]int64, (s>>6)+1)
	for _, p := range primes {
		isp[p>>6] |= 1 << uint(p)
	}
	for i := 0; i < len(xcums)-1; i++ {
		xcums[i+1] = xcums[i] + int(countBits(isp[i]))
	}

	cumps := make([][]int, 8)
	FP := []int{2, 3, 5, 7, 11, 13, 17, 19}
	M := len(FP)

	b := []bool{true}
	lenB := 1
	for i := 0; i < M; i++ {
		lenB *= FP[i]
		c := make([]bool, lenB)
		for j := 0; j < FP[i]; j++ {
			copy(c[j*len(b):], b)
		}
		for k := 0; k < lenB; k += FP[i] {
			c[k] = false
		}
		cumps[i] = make([]int, lenB+1)
		for j := 0; j < lenB; j++ {
			cumps[i][j+1] = cumps[i][j] + boolToInt(c[j])
		}
		FP[i] = lenB
		b = c
	}

	return &id7{
		primes:     primes,
		xcums:      xcums,
		isp:        isp,
		cachelimit: cachelimit,
		picache:    picache,
		id1:        id1,
		FP:         FP,
		M:          M,
		B:          100,
	}
}

func (id *id7) pi(x int64) int64 {
	if x <= int64(id.cachelimit) {
		ix := int(x)
		return int64(id.xcums[ix>>6] + countBits(id.isp[ix>>6]<<uint(^ix)))
	}
	if val, exists := id.picache[x]; exists {
		return val
	}

	A := int(id.pi(sqrt(sqrt(x))))
	ret := int64(A) + id.phi(x, A) - id.P2(x, A) - id.P3(x, A) - 1
	id.picache[x] = ret
	return ret
}

func (id *id7) phi(x int64, A int) int64 {
	if A > 0 && A-1 < id.M {
		return int64(id.cumps[A-1][id.FP[A-1]])*(x/int64(id.FP[A-1])) + int64(id.cumps[A-1][int(x%int64(id.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(id.primes[A-1])*int64(id.primes[A-1]) {
		return id.pi(x) - int64(A) + 1
	}
	code := x<<13 | int64(A)
	if val, exists := id.id1[code]; exists {
		return val
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= id.phi(x/int64(id.primes[i]), i)
	}

	if id.cachePhi {
		id.id1[code] = ret
	}
	return ret
}

func (id *id7) P2(x int64, A int) int64 {
	B := int(id.pi(sqrt(x)))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += id.pi(x/int64(id.primes[i]))
	}
	ret -= int64(B-A) * (int64(B+A-1)) / 2
	return ret
}

func (id *id7) P3(x int64, A int) int64 {
	C := int(id.pi(id6(x)))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(id.primes[i])
		B := int(id.pi(sqrt(xi)))
		for j := i; j < B; j++ {
			ret += id.pi(xi/int64(id.primes[j])) - int64(j)
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

func id6(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Pow(float64(n), 1.0/3.0)))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
}

func countBits(n int64) int {
	count := 0
	for n > 0 {
		count += int(n & 1)
		n >>= 1
	}
	return count
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func assert(condition bool) {
	if !condition {
		panic("assertion failed")
	}
}

func main() {
	f := F3{primes: id0(400000)}
	f.solve()
}
