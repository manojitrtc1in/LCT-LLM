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

func scanString() string {
	if !scanner.Scan() {
		panic("scanString: Scan failed")
	}
	return scanner.Text()
}

func scanInt() int {
	i, err := strconv.Atoi(scanString())
	if err != nil {
		panic("scanInt: Unable to parse integer")
	}
	return i
}

func scanInt64() int64 {
	i, err := strconv.ParseInt(scanString(), 10, 64)
	if err != nil {
		panic("scanInt64: Unable to parse integer")
	}
	return i
}

func scanFloat64() float64 {
	f, err := strconv.ParseFloat(scanString(), 64)
	if err != nil {
		panic("scanFloat64: Unable to parse float")
	}
	return f
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
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

func id7(n int64) []int {
	assert(n >= 4)

	picache := make(map[int64]int64)
	id1 := make(map[int64]int64)
	cachePhi := false

	FP := []int{2, 3, 5, 7, 11, 13, 17, 19}
	M := len(FP)

	B := 100

	sqrt := func(n int64) int64 {
		i := int64(math.Max(0, math.Sqrt(float64(n))-2))
		for i*i <= n {
			i++
		}
		return i - 1
	}

	id6 := func(n int64) int64 {
		i := int64(math.Max(0, math.Cbrt(float64(n))-2))
		for i*i*i <= n {
			i++
		}
		return i - 1
	}

	phi := func(x int64, A int) int64 {
		if A > 0 && A-1 < M {
			return int64(cumps[A-1][FP[A-1]])*(x/int64(FP[A-1])) + int64(cumps[A-1][int(x%int64(FP[A-1]))+1])
		}
		if A > 0 && x <= int64(primes[A-1])*int64(primes[A-1]) {
			return pi(x) - int64(A) + 1
		}
		code := x<<13 | int64(A)
		if val, ok := id1[code]; ok {
			return val
		}

		ret := x
		for i := A - 1; i >= 0; i-- {
			ret -= phi(x/int64(primes[i]), i)
		}

		if cachePhi {
			id1[code] = ret
		}
		return ret
	}

	P2 := func(x int64, A int) int64 {
		B := int64(pi(sqrt(x)))
		ret := int64(0)
		for i := A; i < int(B); i++ {
			ret += pi(x / int64(primes[i]))
		}
		ret -= (int64(B-A)*(int64(B)+int64(A)-1))/2
		return ret
	}

	P3 := func(x int64, A int) int64 {
		C := int64(pi(id6(x)))
		ret := int64(0)
		for i := A; i < int(C); i++ {
			xi := x / int64(primes[i])
			B := int64(pi(sqrt(xi)))
			for j := i; j < int(B); j++ {
				ret += pi(xi / int64(primes[j])) - int64(j)
			}
		}
		return ret
	}

	pi := func(x int64) int64 {
		if x <= int64(cachelimit) {
			ix := int(x)
			return int64(xcums[ix>>6]) + int64(bitsCount(isp[ix>>6]<<^ix))
		}
		if val, ok := picache[x]; ok {
			return val
		}

		A := int(pi(sqrt(sqrt(float64(x)))))
		ret := int64(A) + phi(x, A) - P2(x, A) - P3(x, A) - 1
		picache[x] = ret
		return ret
	}

	bitsCount := func(x int64) int {
		return bitsCountTable[x&0xff] + bitsCountTable[(x>>8)&0xff] + bitsCountTable[(x>>16)&0xff] + bitsCountTable[(x>>24)&0xff] + bitsCountTable[(x>>32)&0xff] + bitsCountTable[(x>>40)&0xff] + bitsCountTable[(x>>48)&0xff] + bitsCountTable[(x>>56)&0xff]
	}

	bitsCountTable := []int{
		0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
		4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
	}

	cachelimit := int(math.Sqrt(float64(n))) * B
	primes := id0(cachelimit)
	xcums := make([]int, (cachelimit>>6)+1)
	isp := make([]int64, (cachelimit>>6)+1)
	for _, p := range primes {
		isp[p>>6] |= 1 << p
	}
	for i := 0; i < len(xcums)-1; i++ {
		xcums[i+1] = xcums[i] + bitsCount(isp[i])
	}

	cumps := make([][]int, M)
	b := []bool{true}
	len := 1
	for i := 0; i < M; i++ {
		len *= FP[i]
		c := make([]bool, len)
		for j := 0; j < FP[i]; j++ {
			copy(c[j*len/FP[i]:], b)
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

	return primes
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func assert(b bool) {
	if !b {
		panic("assertion failed")
	}
}

func solve() {
	n := scanInt64()
	ans := int64(0)
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
	println(ans)
}

func main() {
	initIO()
	defer flush()
	solve()
}
