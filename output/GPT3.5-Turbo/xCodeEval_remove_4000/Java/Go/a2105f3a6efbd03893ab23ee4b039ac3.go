package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

func readInt64() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return i
}

func readFloat64() float64 {
	i, _ := strconv.ParseFloat(readString(), 64)
	return i
}

func writeString(s string) {
	writer.WriteString(s)
}

func writeInt(i int) {
	writeString(strconv.Itoa(i))
}

func writeInt64(i int64) {
	writeString(strconv.FormatInt(i, 10))
}

func writeFloat64(f float64) {
	writeString(strconv.FormatFloat(f, 'f', -1, 64))
}

func solve() {
	n := readInt64()
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
		writeInt(int(ans))
		return
	}

	primes := id0(400000)
	ml := id7(n / 2)
	for i := 0; i < len(primes); i++ {
		plus := ml.pi(n/primes[i]) - int64(i+1)
		if plus <= 0 {
			break
		}
		ans += plus
	}

	for _, p := range primes {
		if int64(p)*int64(p)*int64(p) <= n {
			ans++
		} else {
			break
		}
	}
	writeInt(int(ans))
}

func main() {
	initIO()
	defer flush()
	solve()
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

type id7 struct {
	primes []int
	xcums  []int
	isp    []int64
	cumps  [][]int
	FP     []int
	M      int
	B      int
}

func newID7(n int64) *id7 {
	id7 := &id7{}
	id7.primes = id0(int(n))
	id7.xcums = make([]int, (len(id7.primes)>>6)+1)
	id7.isp = make([]int64, (len(id7.primes)>>6)+1)
	for _, p := range id7.primes {
		id7.isp[p>>6] |= 1 << p
	}
	for i := 0; i < len(id7.xcums)-1; i++ {
		id7.xcums[i+1] = id7.xcums[i] + int64BitsCount(id7.isp[i])
	}

	id7.cumps = make([][]int, id7.M)
	b := []bool{true}
	len := 1
	for i := 0; i < id7.M; i++ {
		len *= id7.FP[i]
		c := make([]bool, len)
		for j := 0; j < id7.FP[i]; j++ {
			copy(c[j*len:], b)
		}
		for k := 0; k < len; k += id7.FP[i] {
			c[k] = false
		}
		id7.cumps[i] = make([]int, len+1)
		for j := 0; j < len; j++ {
			if c[j] {
				id7.cumps[i][j+1] = id7.cumps[i][j] + 1
			} else {
				id7.cumps[i][j+1] = id7.cumps[i][j]
			}
		}
		id7.FP[i] = len
		b = c
	}

	return id7
}

func (id7 *id7) pi(x int64) int64 {
	if x <= int64(id7.xcums[len(id7.xcums)-1]) {
		ix := int(x)
		return int64(id7.xcums[ix>>6]) + int64BitsCount(id7.isp[ix>>6]<<^ix)
	}
	if picache.containsKey(x) {
		return picache.get(x)
	}

	A := int(id7.pi(sqrt(sqrt(x))))
	ret := int64(A + phi(x, A) - P2(x, A) - P3(x, A) - 1)
	picache.put(x, ret)
	return ret
}

func phi(x int64, A int) int64 {
	if A > 0 && A-1 < id7.M {
		return int64(id7.cumps[A-1][id7.FP[A-1]])*(x/int64(id7.FP[A-1])) + int64(id7.cumps[A-1][int(x%int64(id7.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(id7.primes[A-1])*int64(id7.primes[A-1]) {
		return id7.pi(x) - int64(A) + 1
	}

	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= phi(x/int64(id7.primes[i]), i)
	}

	return ret
}

func P2(x int64, A int) int64 {
	B := int(id7.pi(sqrt(x)))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += id7.pi(x / int64(id7.primes[i]))
	}
	ret -= int64(B-A)*(int64(B)+int64(A)-1)/2
	return ret
}

func P3(x int64, A int) int64 {
	C := int(id7.pi(id6(x)))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(id7.primes[i])
		B := int(id7.pi(sqrt(xi)))
		for j := i; j < B; j++ {
			ret += id7.pi(xi / int64(id7.primes[j])) - int64(j)
		}
	}
	return ret
}

func int64BitsCount(x int64) int {
	count := 0
	for x != 0 {
		x &= x - 1
		count++
	}
	return count
}

type id4 struct {
	keys      []int64
	allocated []int64
	scale     int
	rscale    int
	mask      int
	size      int
}

func newID4() *id4 {
	id4 := &id4{}
	id4.scale = 1 << 2
	id4.rscale = 1 << 1
	id4.mask = id4.scale - 1
	id4.allocated = make([]int64, id4.scale)
	for i := 0; i < id4.scale; i++ {
		id4.allocated[i] = NG
	}
	id4.keys = make([]int64, id4.scale)
	return id4
}

func (id4 *id4) containsKey(x int64) bool {
	pos := h(x) & id4.mask
	for id4.allocated[pos] != NG {
		if x == id4.keys[pos] {
			return true
		}
		pos = (pos + 1) & id4.mask
	}
	return false
}

func (id4 *id4) get(x int64) int64 {
	pos := h(x) & id4.mask
	for id4.allocated[pos] != NG {
		if x == id4.keys[pos] {
			return id4.allocated[pos]
		}
		pos = (pos + 1) & id4.mask
	}
	return NG
}

func (id4 *id4) put(x, v int64) int64 {
	pos := h(x) & id4.mask
	for id4.allocated[pos] != NG {
		if x == id4.keys[pos] {
			oldval := id4.allocated[pos]
			id4.allocated[pos] = v
			return oldval
		}
		pos = (pos + 1) & id4.mask
	}
	if id4.size == id4.rscale {
		id4.id5(x, v)
	} else {
		id4.keys[pos] = x
		id4.allocated[pos] = v
	}
	id4.size++
	return 0
}

func (id4 *id4) inc(x, v int64) int64 {
	pos := h(x) & id4.mask
	for id4.allocated[pos] != NG {
		if x == id4.keys[pos] {
			id4.allocated[pos] += v
			return id4.allocated[pos]
		}
		pos = (pos + 1) & id4.mask
	}
	if id4.size == id4.rscale {
		id4.id5(x, v)
	} else {
		id4.keys[pos] = x
		id4.allocated[pos] = v
	}
	id4.size++
	return v
}

func (id4 *id4) remove(x int64) bool {
	pos := h(x) & id4.mask
	for id4.allocated[pos] != NG {
		if x == id4.keys[pos] {
			id4.size--

			last := pos
			pos = (pos + 1) & id4.mask
			for id4.allocated[pos] != NG {
				lh := h(id4.keys[pos]) & id4.mask

				if lh <= last && last < pos ||
					pos < lh && lh <= last ||
					last < pos && pos < lh {
					id4.keys[last] = id4.keys[pos]
					id4.allocated[last] = id4.allocated[pos]
					last = pos
				}
				pos = (pos + 1) & id4.mask
			}
			id4.keys[last] = 0
			id4.allocated[last] = NG

			return true
		}
		pos = (pos + 1) & id4.mask
	}
	return false
}

func (id4 *id4) id5(x, v int64) {
	nscale := id4.scale << 1
	nrscale := id4.rscale << 1
	nmask := nscale - 1
	nallocated := make([]int64, nscale)
	for i := 0; i < nscale; i++ {
		nallocated[i] = NG
	}
	nkeys := make([]int64, nscale)
	for i := id4.next(0); i < id4.scale; i = id4.next(i + 1) {
		y := id4.keys[i]
		pos := h(y) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = y
		nallocated[pos] = id4.allocated[i]
	}
	{
		pos := h(x) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = x
		nallocated[pos] = v
	}
	id4.allocated = nallocated
	id4.keys = nkeys
	id4.scale = nscale
	id4.rscale = nrscale
	id4.mask = nmask
}

func (id4 *id4) next(itr int) int {
	for itr < id4.scale && id4.allocated[itr] == NG {
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

type id5 struct {
	keys      []int64
	allocated []int64
	scale     int
	rscale    int
	mask      int
	size      int
}

func newID5() *id5 {
	id5 := &id5{}
	id5.scale = 1 << 2
	id5.rscale = 1 << 1
	id5.mask = id5.scale - 1
	id5.allocated = make([]int64, id5.scale)
	for i := 0; i < id5.scale; i++ {
		id5.allocated[i] = NG
	}
	id5.keys = make([]int64, id5.scale)
	return id5
}

func (id5 *id5) containsKey(x int64) bool {
	pos := h(x) & id5.mask
	for id5.allocated[pos] != NG {
		if x == id5.keys[pos] {
			return true
		}
		pos = (pos + 1) & id5.mask
	}
	return false
}

func (id5 *id5) get(x int64) int64 {
	pos := h(x) & id5.mask
	for id5.allocated[pos] != NG {
		if x == id5.keys[pos] {
			return id5.allocated[pos]
		}
		pos = (pos + 1) & id5.mask
	}
	return NG
}

func (id5 *id5) put(x, v int64) int64 {
	pos := h(x) & id5.mask
	for id5.allocated[pos] != NG {
		if x == id5.keys[pos] {
			oldval := id5.allocated[pos]
			id5.allocated[pos] = v
			return oldval
		}
		pos = (pos + 1) & id5.mask
	}
	if id5.size == id5.rscale {
		id5.id6(x, v)
	} else {
		id5.keys[pos] = x
		id5.allocated[pos] = v
	}
	id5.size++
	return 0
}

func (id5 *id5) inc(x, v int64) int64 {
	pos := h(x) & id5.mask
	for id5.allocated[pos] != NG {
		if x == id5.keys[pos] {
			id5.allocated[pos] += v
			return id5.allocated[pos]
		}
		pos = (pos + 1) & id5.mask
	}
	if id5.size == id5.rscale {
		id5.id6(x, v)
	} else {
		id5.keys[pos] = x
		id5.allocated[pos] = v
	}
	id5.size++
	return v
}

func (id5 *id5) remove(x int64) bool {
	pos := h(x) & id5.mask
	for id5.allocated[pos] != NG {
		if x == id5.keys[pos] {
			id5.size--

			last := pos
			pos = (pos + 1) & id5.mask
			for id5.allocated[pos] != NG {
				lh := h(id5.keys[pos]) & id5.mask

				if lh <= last && last < pos ||
					pos < lh && lh <= last ||
					last < pos && pos < lh {
					id5.keys[last] = id5.keys[pos]
					id5.allocated[last] = id5.allocated[pos]
					last = pos
				}
				pos = (pos + 1) & id5.mask
			}
			id5.keys[last] = 0
			id5.allocated[last] = NG

			return true
		}
		pos = (pos + 1) & id5.mask
	}
	return false
}

func (id5 *id5) id6(x, v int64) {
	nscale := id5.scale << 1
	nrscale := id5.rscale << 1
	nmask := nscale - 1
	nallocated := make([]int64, nscale)
	for i := 0; i < nscale; i++ {
		nallocated[i] = NG
	}
	nkeys := make([]int64, nscale)
	for i := id5.next(0); i < id5.scale; i = id5.next(i + 1) {
		y := id5.keys[i]
		pos := h(y) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = y
		nallocated[pos] = id5.allocated[i]
	}
	{
		pos := h(x) & nmask
		for nallocated[pos] != NG {
			pos = (pos + 1) & nmask
		}
		nkeys[pos] = x
		nallocated[pos] = v
	}
	id5.allocated = nallocated
	id5.keys = nkeys
	id5.scale = nscale
	id5.rscale = nrscale
	id5.mask = nmask
}

func (id5 *id5) next(itr int) int {
	for itr < id5.scale && id5.allocated[itr] == NG {
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

const NG = 0

var picache = newID5()

func sqrt(n int64) int64 {
	i := int64(math.Max(0, math.Sqrt(float64(n))-2))
	for i*i <= n {
		i++
	}
	return i - 1
}

func id6(n int64) int64 {
	i := int64(math.Max(0, math.Cbrt(float64(n))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
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
