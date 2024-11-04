package main

import (
	"fmt"
	"math"
)

type F3 struct {
	primes []int
}

func (f *F3) divsieve(n int64) [][]int64 {
	K := int(math.Pow(float64(n), 2./3))
	f.tr(K)

	primes := sieveEratosthenes(int(math.Sqrt(float64(n))))
	qs := make([]int64, 0, 50000000)
	f.dfs1(n, 0, K, &qs, primes)
	f.tr(len(qs))

	return nil
}

var ct int

func (f *F3) dfs1(n int64, prev, K int, qs *[]int64, primes []int) {
	if n < int64(K) {
		*qs = append(*qs, n<<32|int64(prev))
		if len(*qs)%100000 == 0 {
			f.tr(len(*qs))
		}
		ct++
		if ct%1000000 == 0 {
			f.tr(ct)
		}
	} else {
		u := binarySearch(primes, int(math.Sqrt(float64(n))))
		if u < 0 {
			u = -u - 2
		}
		for i := u; i >= 0; i-- {
			f.dfs1(n/int64(primes[i]), i, K, qs, primes)
		}
	}
}

func sieveEratosthenes(n int) []int {
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
			if int64(p)*int64(p) > n {
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
	ml := NewMeisselLehmer2(n)
	for i := 0; i < len(f.primes); i++ {
		plus := ml.pi(n/int64(f.primes[i])) - int64(i+1)
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
	picache    *LongHashCounterL
	phicache   *LongHashCounterL
	cachePhi   bool
	cumps      [][]int
	FP         []int
	M          int
	B          int
}

func NewMeisselLehmer2(n int64) *MeisselLehmer2 {
	assert(n >= 4)

	ml := &MeisselLehmer2{
		picache:  NewLongHashCounterL(),
		phicache: NewLongHashCounterL(),
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
		ml.xcums[i+1] = ml.xcums[i] + int(bitCount(ml.isp[i]))
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
		return int64(ml.xcums[ix>>6] + bitCount(ml.isp[ix>>6]<<^uint64(ix)))
	}
	if ml.picache.ContainsKey(x) {
		return ml.picache.Get(x)
	}

	A := int(ml.pi(sqrt(sqrt(x))))
	ret := A + ml.phi(x, A) - ml.P2(x, A) - ml.P3(x, A) - 1
	ml.picache.Put(x, ret)
	return ret
}

func (ml *MeisselLehmer2) phi(x int64, A int) int64 {
	if A > 0 && A-1 < ml.M {
		return int64(ml.cumps[A-1][ml.FP[A-1]]*(x/int64(ml.FP[A-1]))) + int64(ml.cumps[A-1][int(x%int64(ml.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(ml.primes[A-1])*int64(ml.primes[A-1]) {
		return ml.pi(x) - int64(A) + 1
	}
	code := x<<13 | int64(A)
	if ml.phicache.ContainsKey(code) {
		return ml.phicache.Get(code)
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= ml.phi(x/int64(ml.primes[i]), i)
	}

	if ml.cachePhi {
		ml.phicache.Put(code, ret)
	}
	return ret
}

func (ml *MeisselLehmer2) P2(x int64, A int) int64 {
	B := int(ml.pi(sqrt(x)))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += ml.pi(x/int64(ml.primes[i]))
	}
	ret -= int64((B-A)*(B+A-1)) / 2
	return ret
}

func (ml *MeisselLehmer2) P3(x int64, A int) int64 {
	C := int(ml.pi(cbrt(x)))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(ml.primes[i])
		B := int(ml.pi(sqrt(xi)))
		for j := i; j < B; j++ {
			ret += ml.pi(xi/int64(ml.primes[j])) - int64(j)
		}
	}
	return ret
}

func (ml *MeisselLehmer2) sqrt(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Sqrt(float64(n))))-2))
	for i*i <= n {
		i++
	}
	return i - 1
}

func (ml *MeisselLehmer2) cbrt(n int64) int64 {
	i := int64(math.Max(0, float64(int64(math.Cbrt(float64(n))))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
}

type LongHashCounterL struct {
	keys      []int64
	allocated []int64
	scale     int
	rscale    int
	mask      int
	size      int
}

func NewLongHashCounterL() *LongHashCounterL {
	lhc := &LongHashCounterL{
		scale:     1 << 2,
		rscale:    1 << 1,
		mask:      (1 << 2) - 1,
		allocated: make([]int64, 1<<2),
		keys:      make([]int64, 1<<2),
	}
	for i := range lhc.allocated {
		lhc.allocated[i] = NG
	}
	return lhc
}

const NG = 0

func (lhc *LongHashCounterL) ContainsKey(x int64) bool {
	pos := h(x) & lhc.mask
	for lhc.allocated[pos] != NG {
		if x == lhc.keys[pos] {
			return true
		}
		pos = (pos + 1) & lhc.mask
	}
	return false
}

func (lhc *LongHashCounterL) Get(x int64) int64 {
	pos := h(x) & lhc.mask
	for lhc.allocated[pos] != NG {
		if x == lhc.keys[pos] {
			return lhc.allocated[pos]
		}
		pos = (pos + 1) & lhc.mask
	}
	return NG
}

func (lhc *LongHashCounterL) Put(x, v int64) int64 {
	pos := h(x) & lhc.mask
	for lhc.allocated[pos] != NG {
		if x == lhc.keys[pos] {
			oldval := lhc.allocated[pos]
			lhc.allocated[pos] = v
			return oldval
		}
		pos = (pos + 1) & lhc.mask
	}
	if lhc.size == lhc.rscale {
		lhc.resizeAndPut(x, v)
	} else {
		lhc.keys[pos] = x
		lhc.allocated[pos] = v
	}
	lhc.size++
	return 0
}

func (lhc *LongHashCounterL) resizeAndPut(x, v int64) {
	nscale := lhc.scale << 1
	nrscale := lhc.rscale << 1
	nmask := nscale - 1
	nallocated := make([]int64, nscale)
	for i := 0; i < lhc.scale; i++ {
		y := lhc.keys[i]
		pos := h(y) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nallocated[pos] = lhc.allocated[i]
	}
	pos := h(x) & nmask
	for nallocated[pos] != NG {
		pos = (pos + 1) & nmask
	}
	nallocated[pos] = v
	lhc.allocated = nallocated
	lhc.scale = nscale
	lhc.rscale = nrscale
	lhc.mask = nmask
}

func (lhc *LongHashCounterL) next(itr int) int {
	for itr < lhc.scale && lhc.allocated[itr] == NG {
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

func (f *F3) run() {
	var n int64
	fmt.Scan(&n)
	f.solve()
}

func (f *F3) tr(o ...interface{}) {
	fmt.Println(o...)
}

func main() {
	f := &F3{}
	f.primes = sieveEratosthenes(1000000)
	f.run()
}

func bitCount(x int64) int {
	count := 0
	for x > 0 {
		count += int(x & 1)
		x >>= 1
	}
	return count
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func binarySearch(arr []int, x int) int {
	low, high := 0, len(arr)-1
	for low <= high {
		mid := (low + high) / 2
		if arr[mid] < x {
			low = mid + 1
		} else if arr[mid] > x {
			high = mid - 1
		} else {
			return mid
		}
	}
	return -(low + 1)
}
