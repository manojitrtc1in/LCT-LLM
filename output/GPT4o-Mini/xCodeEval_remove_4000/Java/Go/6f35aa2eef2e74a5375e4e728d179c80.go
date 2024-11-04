package main

import (
	"bytes"
	"fmt"
	"math"
	"os"
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
	picache    *id4
	id1        *id4
	cachePhi   bool
	cumps      [][]int
	FP         []int
	M          int
	B          int
}

func newId7(n int64) *id7 {
	assert(n >= 4)

	picache := newId4()
	id1 := newId4()

	s := int(math.Sqrt(float64(n))) * 100
	cachelimit := s
	primes := id0(s)
	xcums := make([]int, (s>>6)+1)
	isp := make([]int64, (s>>6)+1)
	for _, p := range primes {
		isp[p>>6] |= 1 << uint(p)
	}
	for i := 0; i < len(xcums)-1; i++ {
		xcums[i+1] = xcums[i] + int(bitCount(isp[i]))
	}

	cumps := make([][]int, 14)
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

	return &id7{primes: primes, xcums: xcums, isp: isp, cachelimit: cachelimit, picache: picache, id1: id1, cachePhi: true, cumps: cumps, FP: FP, M: M, B: 100}
}

func (i *id7) pi(x int64) int64 {
	if x <= int64(i.cachelimit) {
		ix := int(x)
		return int64(i.xcums[ix>>6] + bitCount(i.isp[ix>>6]<<^uint64(ix)))
	}
	if i.picache.containsKey(x) {
		return i.picache.get(x)
	}

	A := int(i.pi(int64(math.Sqrt(float64(math.Sqrt(float64(x)))))))
	ret := int64(A) + i.phi(x, A) - i.P2(x, A) - i.P3(x, A) - 1
	i.picache.put(x, ret)
	return ret
}

func (i *id7) phi(x int64, A int) int64 {
	if A > 0 && A-1 < i.M {
		return int64(i.cumps[A-1][i.FP[A-1]]*(x/int64(i.FP[A-1]))) + int64(i.cumps[A-1][int(x%int64(i.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(i.primes[A-1])*int64(i.primes[A-1]) {
		return i.pi(x) - int64(A) + 1
	}
	code := x<<13 | int64(A)
	if i.id1.containsKey(code) {
		return i.id1.get(code)
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= i.phi(x/int64(i.primes[i]), i)
	}

	if i.cachePhi {
		i.id1.put(code, ret)
	}
	return ret
}

func (i *id7) P2(x int64, A int) int64 {
	B := int(i.pi(int64(math.Sqrt(float64(x)))))
	ret := int64(0)
	for j := A; j < B; j++ {
		ret += i.pi(x/int64(i.primes[j]))
	}
	ret -= int64(B-A) * (int64(B+A-1)) / 2
	return ret
}

func (i *id7) P3(x int64, A int) int64 {
	C := int(i.pi(id6(x)))
	ret := int64(0)
	for j := A; j < C; j++ {
		xi := x / int64(i.primes[j])
		B := int(i.pi(int64(math.Sqrt(float64(xi)))))
		for k := j; k < B; k++ {
			ret += i.pi(xi/int64(i.primes[k])) - int64(k)
		}
	}
	return ret
}

func id6(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Sqrt(float64(n))))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
}

type id4 struct {
	keys      []int64
	allocated []int64
	scale     int
	rscale    int
	mask      int
	size      int
}

func newId4() *id4 {
	allocated := make([]int64, 4)
	for i := range allocated {
		allocated[i] = NG
	}
	keys := make([]int64, 4)
	return &id4{keys: keys, allocated: allocated, scale: 4, rscale: 2, mask: 3, size: 0}
}

const NG = 0

func (d *id4) containsKey(x int64) bool {
	pos := h(x) & d.mask
	for d.allocated[pos] != NG {
		if x == d.keys[pos] {
			return true
		}
		pos = (pos + 1) & d.mask
	}
	return false
}

func (d *id4) get(x int64) int64 {
	pos := h(x) & d.mask
	for d.allocated[pos] != NG {
		if x == d.keys[pos] {
			return d.allocated[pos]
		}
		pos = (pos + 1) & d.mask
	}
	return NG
}

func (d *id4) put(x, v int64) int64 {
	pos := h(x) & d.mask
	for d.allocated[pos] != NG {
		if x == d.keys[pos] {
			oldval := d.allocated[pos]
			d.allocated[pos] = v
			return oldval
		}
		pos = (pos + 1) & d.mask
	}
	if d.size == d.rscale {
		d.id5(x, v)
	} else {
		d.keys[pos] = x
		d.allocated[pos] = v
	}
	d.size++
	return 0
}

func (d *id4) id5(x, v int64) {
	nscale := d.scale << 1
	nrscale := d.rscale << 1
	nmask := nscale - 1
	nallocated := make([]int64, nscale)
	for i := 0; i < d.scale; i++ {
		nallocated[i] = NG
	}
	nkeys := make([]int64, nscale)
	for i := next(0); i < d.scale; i = next(i + 1) {
		y := d.keys[i]
		pos := h(y) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = y
		nallocated[pos] = d.allocated[i]
	}
	{
		pos := h(x) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = x
		nallocated[pos] = v
	}
	d.allocated = nallocated
	d.keys = nkeys
	d.scale = nscale
	d.rscale = nrscale
	d.mask = nmask
}

func (d *id4) next(itr int) int {
	for itr < d.scale && d.allocated[itr] == NG {
		itr++
	}
	return itr
}

func h(x int64) int {
	x ^= x >> 33
	x *= 0xff51afd7ed558ccd
	x ^= x >> 33
	x *= 0xc4ceb9fe1a85ec53
	x ^= x >> 33
	return int(x)
}

func main() {
	f := F3{primes: id0(400000)}
	f.solve()
}

func bitCount(x int64) int {
	count := 0
	for x > 0 {
		count += int(x & 1)
		x >>= 1
	}
	return count
}

func assert(condition bool) {
	if !condition {
		panic("assertion failed")
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}
