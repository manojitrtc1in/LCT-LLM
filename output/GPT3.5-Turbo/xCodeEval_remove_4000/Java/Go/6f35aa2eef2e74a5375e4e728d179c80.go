package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

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

func readLong() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return i
}

func readFloat() float64 {
	i, _ := strconv.ParseFloat(readString(), 64)
	return i
}

func writeString(s string) {
	writer.WriteString(s)
}

func writeInt(i int) {
	writeString(strconv.Itoa(i))
}

func writeLong(i int64) {
	writeString(strconv.FormatInt(i, 10))
}

func writeFloat(f float64) {
	writeString(strconv.FormatFloat(f, 'f', -1, 64))
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

type id7 struct {
	primes []int
	xcums  []int
	isp    []int64
	cachelimit int
	picache map[int64]int64
	id1 map[int64]int64
	cachePhi bool
	cumps [][]int
	FP []int
	M int
	B int
}

func newId7(n int64) *id7 {
	id7 := &id7{}
	id7.primes = id0(int(n))
	id7.xcums = make([]int, (len(id7.primes)>>6)+1)
	id7.isp = make([]int64, (len(id7.primes)>>6)+1)
	for _, p := range id7.primes {
		id7.isp[p>>6] |= 1 << p
	}
	for i := 0; i < len(id7.xcums)-1; i++ {
		id7.xcums[i+1] = id7.xcums[i] + bitsSet(id7.isp[i])
	}
	id7.cumps = make([][]int, id7.M)
	b := []bool{true}
	len := 1
	for i := 0; i < id7.M; i++ {
		len *= id7.FP[i]
		c := make([]bool, len)
		for j := 0; j < id7.FP[i]; j++ {
			copy(c[j*len/id7.FP[i]:], b)
		}
		for k := 0; k < len; k += id7.FP[i] {
			c[k] = false
		}
		id7.cumps[i] = make([]int, len+1)
		for j := 0; j < len; j++ {
			id7.cumps[i][j+1] = id7.cumps[i][j] + boolToInt(c[j])
		}
		id7.FP[i] = len
		b = c
	}
	return id7
}

func (id7 *id7) sqrt(n int64) int64 {
	i := int64(math.Max(0, math.Sqrt(float64(n))-2))
	for i*i <= n {
		i++
	}
	return i - 1
}

func (id7 *id7) id6(n int64) int64 {
	i := int64(math.Max(0, math.Cbrt(float64(n))-2))
	for i*i*i <= n {
		i++
	}
	return i - 1
}

func (id7 *id7) pi(x int64) int64 {
	if x <= int64(id7.cachelimit) {
		ix := int(x)
		return int64(id7.xcums[ix>>6]) + int64(bitsSet(id7.isp[ix>>6]<<^ix))
	}
	if val, ok := id7.picache[x]; ok {
		return val
	}
	A := id7.pi(id7.sqrt(id7.sqrt(x)))
	ret := A + id7.phi(x, A) - id7.P2(x, A) - id7.P3(x, A) - 1
	id7.picache[x] = ret
	return ret
}

func (id7 *id7) phi(x int64, A int64) int64 {
	if A > 0 && A-1 < int64(id7.M) {
		return int64(id7.cumps[A-1][id7.FP[A-1]])*(x/int64(id7.FP[A-1])) + int64(id7.cumps[A-1][int(x%int64(id7.FP[A-1])+1)])
	}
	if A > 0 && x <= int64(id7.primes[A-1])*int64(id7.primes[A-1]) {
		return id7.pi(x) - A + 1
	}
	code := x<<13 | A
	if val, ok := id7.id1[code]; ok {
		return val
	}
	ret := x
	for i := A - 1; i >= 0; i-- {
		ret -= id7.phi(x/int64(id7.primes[i]), i)
	}
	if id7.cachePhi {
		id7.id1[code] = ret
	}
	return ret
}

func (id7 *id7) P2(x int64, A int64) int64 {
	B := id7.pi(id7.sqrt(x))
	ret := int64(0)
	for i := A; i < B; i++ {
		ret += id7.pi(x/int64(id7.primes[i]))
	}
	ret -= (B - A) * (B + A - 1) / 2
	return ret
}

func (id7 *id7) P3(x int64, A int64) int64 {
	C := id7.pi(id7.id6(x))
	ret := int64(0)
	for i := A; i < C; i++ {
		xi := x / int64(id7.primes[i])
		B := id7.pi(id7.sqrt(xi))
		for j := i; j < B; j++ {
			ret += id7.pi(xi/int64(id7.primes[j])) - int64(j)
		}
	}
	return ret
}

func bitsSet(n int64) int {
	count := 0
	for n != 0 {
		n &= n - 1
		count++
	}
	return count
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func solve() {
	n := readLong()
	ans := int64(0)
	ml := newId7(n / 2)
	for i := 0; i < len(ml.primes); i++ {
		plus := ml.pi(n/int64(ml.primes[i])) - int64(i+1)
		if plus <= 0 {
			break
		}
		ans += plus
	}

	for _, p := range ml.primes {
		if int64(p)*int64(p)*int64(p) <= n {
			ans++
		} else {
			break
		}
	}
	writeLong(ans)
}

func main() {
	initIO()
	defer flush()
	solve()
}
