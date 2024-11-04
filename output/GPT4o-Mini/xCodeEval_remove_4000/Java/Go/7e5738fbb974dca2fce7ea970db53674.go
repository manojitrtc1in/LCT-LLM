package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type DSU struct {
	parent []int
	size   []int
}

func NewDSU(n int) *DSU {
	dsu := &DSU{
		parent: make([]int, n),
		size:   make([]int, n),
	}
	for i := range dsu.parent {
		dsu.parent[i] = -1
	}
	return dsu
}

func (dsu *DSU) MakeSet(v int) {
	dsu.parent[v] = v
	dsu.size[v] = 1
}

func (dsu *DSU) FindSet(v int) int {
	if v == dsu.parent[v] {
		return v
	}
	dsu.parent[v] = dsu.FindSet(dsu.parent[v])
	return dsu.parent[v]
}

func (dsu *DSU) UnionSets(a, b int) {
	a = dsu.FindSet(a)
	b = dsu.FindSet(b)
	if a != b {
		if dsu.size[a] < dsu.size[b] {
			a, b = b, a
		}
		dsu.parent[b] = a
		dsu.size[a] += dsu.size[b]
	}
}

func fft(a, b []float64, invert bool) {
	count := len(a)
	for i, j := 1, 0; i < count; i++ {
		bit := count >> 1
		for ; j >= bit; bit >>= 1 {
			j -= bit
		}
		j += bit
		if i < j {
			a[i], a[j] = a[j], a[i]
			b[i], b[j] = b[j], b[i]
		}
	}
	for len := 2; len <= count; len <<= 1 {
		halfLen := len >> 1
		angle := 2 * 3.141592653589793 / float64(len)
		if invert {
			angle = -angle
		}
		id17 := cos(angle)
		id2 := sin(angle)
		for i := 0; i < count; i += len {
			wA, wB := 1.0, 0.0
			for j := 0; j < halfLen; j++ {
				uA, uB := a[i+j], b[i+j]
				vA := a[i+j+halfLen]*wA - b[i+j+halfLen]*wB
				vB := a[i+j+halfLen]*wB + b[i+j+halfLen]*wA
				a[i+j] = uA + vA
				b[i+j] = uB + vB
				a[i+j+halfLen] = uA - vA
				b[i+j+halfLen] = uB - vB
				nextWA := wA*id17 - wB*id2
				wB = wA*id2 + wB*id17
				wA = nextWA
			}
		}
	}
	if invert {
		for i := 0; i < count; i++ {
			a[i] /= float64(count)
			b[i] /= float64(count)
		}
	}
}

func multiply(a, b []int64) []int64 {
	resultSize := highestOneBit(max(len(a), len(b))-1) << 2
	resultSize = max(resultSize, 1)
	aReal := make([]float64, resultSize)
	id10 := make([]float64, resultSize)
	bReal := make([]float64, resultSize)
	id29 := make([]float64, resultSize)
	for i := range a {
		aReal[i] = float64(a[i])
	}
	for i := range b {
		bReal[i] = float64(b[i])
	}
	fft(aReal, id10, false)
	fft(bReal, id29, false)
	for i := 0; i < resultSize; i++ {
		real := aReal[i]*bReal[i] - id10[i]*id29[i]
		id10[i] = id10[i]*bReal[i] + id29[i]*aReal[i]
		aReal[i] = real
	}
	fft(aReal, id10, true)
	result := make([]int64, resultSize)
	for i := 0; i < resultSize; i++ {
		result[i] = int64(round(aReal[i]))
	}
	return result
}

func isPrime(n int64) bool {
	if n < 2 {
		return false
	}
	for x := int64(2); x*x <= n; x++ {
		if n%x == 0 {
			return false
		}
	}
	return true
}

func primeFactors(n int64) []int64 {
	factors := []int64{}
	for x := int64(2); x*x <= n; x++ {
		for n%x == 0 {
			factors = append(factors, x)
			n /= x
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}

func sieve(n int) []int {
	sieve := make([]int, n+1)
	for x := 2; x*x <= n; x++ {
		if sieve[x] != 0 {
			continue
		}
		for u := x * x; u <= n; u += x {
			if sieve[u] == 0 {
				sieve[u] = x
			}
		}
	}
	return sieve
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func phi(n int64) int64 {
	result := float64(n)
	for p := int64(2); p*p <= n; p++ {
		if n%p == 0 {
			for n%p == 0 {
				n /= p
			}
			result *= (1.0 - (1.0 / float64(p)))
		}
	}
	if n > 1 {
		result *= (1.0 - (1.0 / float64(n)))
	}
	return int64(result)
}

type Name struct {
	d, x, y int64
}

func extendedGCD(a, b int64) Name {
	if b == 0 {
		return Name{a, 1, 0}
	}
	n1 := extendedGCD(b, a%b)
	return Name{n1.d, n1.y, n1.x - (a/b)*n1.y}
}

func modExp(a, b, n int64) int64 {
	d := int64(1)
	bString := strconv.FormatInt(b, 2)
	for i := 0; i < len(bString); i++ {
		d = (d * d) % n
		if bString[i] == '1' {
			d = (d * a) % n
		}
	}
	return d
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	s1, _ := reader.ReadString('\n')
	s1 = strings.TrimSpace(s1)
	n, _ := strconv.Atoi(strings.Split(s1, " ")[0])
	k, _ := strconv.Atoi(strings.Split(s1, " ")[1])
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	var stringBuilder strings.Builder

	if k == 0 {
		fmt.Println(s)
		return
	}
	if n == 1 {
		if k >= 1 {
			stringBuilder.WriteString("0")
		} else {
			stringBuilder.WriteString(s)
		}
	} else {
		count := 0
		if s[0] != '1' {
			stringBuilder.WriteString("1")
			count++
		} else {
			stringBuilder.WriteString("1")
		}
		for i := 1; i < n; i++ {
			if count >= k {
				stringBuilder.WriteString(s[i:])
				break
			} else {
				if s[i] == '0' {
					stringBuilder.WriteString("0")
					continue
				} else {
					stringBuilder.WriteString("0")
					count++
				}
			}
		}
	}
	fmt.Println(stringBuilder.String())
}
