package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type id2 struct {
	id5  bool
	in   *bufio.Reader
	out  *bufio.Writer
	tok  []string
	tokI int
}

func (id *id2) init() {
	if id.id5 {
		id.in = bufio.NewReader(os.Stdin)
		id.out = bufio.NewWriter(os.Stdout)
	} else {
		file, _ := os.Open("input.txt")
		id.in = bufio.NewReader(file)
		file, _ = os.Create("output.txt")
		id.out = bufio.NewWriter(file)
	}
}

func (id *id2) readString() string {
	for id.tokI == len(id.tok) {
		id.tok, _ = id.in.ReadString('\n')
		id.tok = strings.Fields(id.tok)
		id.tokI = 0
	}
	id.tokI++
	return id.tok[id.tokI-1]
}

func (id *id2) readInt() int {
	num, _ := strconv.Atoi(id.readString())
	return num
}

func (id *id2) readLong() int64 {
	num, _ := strconv.ParseInt(id.readString(), 10, 64)
	return num
}

func (id *id2) readDouble() float64 {
	num, _ := strconv.ParseFloat(id.readString(), 64)
	return num
}

func main() {
	id := id2{}
	id.run()
}

func (id *id2) run() {
	id.init()
	id.solve()
	id.out.Flush()
}

func (id *id2) solve() {
	n := id.readInt() - 1
	m := id.readInt()
	a := id.readInt() - 1
	b := id.readInt() - 1
	i := a / m
	j := b / m
	l := a % m
	r := b % m
	if b == n {
		r = m - 1
	}
	if l == 0 && r == m-1 {
		fmt.Fprint(id.out, 1)
		return
	}
	if j-i < 2 {
		fmt.Fprint(id.out, j-i+1)
		return
	}
	if (l != 0 && r == m-1) || (l == 0 && r != m-1) {
		fmt.Fprint(id.out, 2)
		return
	}
	if l-r == 1 {
		fmt.Fprint(id.out, 2)
		return
	}
	fmt.Fprint(id.out, 3)
}

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func id8(a, b int64) []int64 {
	d := make([]int64, 3)
	if a == 0 {
		d[0] = b
		d[1] = 0
		d[2] = 1
	} else {
		d = id8(b%a, a)
		r := d[1]
		d[1] = d[2] - b/a*d[1]
		d[2] = r
	}
	return d
}

func binpow(a int64, n int) int64 {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		b := binpow(a, n/2)
		return b * b
	} else {
		return binpow(a, n-1) * a
	}
}

func id1(a int64, n int, m int64) int64 {
	if m == 1 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		b := id1(a, n/2, m)
		return (b * b) % m
	} else {
		return id1(a, n-1, m)*a % m
	}
}

func phi(n int64) int64 {
	p := Sieve(int(math.Ceil(math.Sqrt(float64(n)))) + 2)
	phi := int64(1)
	for i := 0; i < len(p); i++ {
		x := int64(1)
		for n%p[i] == 0 {
			n /= p[i]
			x *= p[i]
		}
		phi *= x - x/p[i]
	}
	if n != 1 {
		phi *= n - 1
	}
	return phi
}

func f(n int64, x int, k int) int64 {
	if n == 0 {
		return 1
	}
	b := binpow(10, x-1)
	c := n / b
	return (c*int64(k)*binpow(int64(k), x-1) + (c < int64(k))*f(n%b, x-1, k))
}

func fib(n int) int64 {
	if n == 0 {
		return 0
	}
	if n%2 == 0 {
		f1 := fib(n/2 - 1)
		f2 := fib(n/2 + 1)
		return f2*f2 - f1*f1
	} else {
		f1 := fib(n/2)
		f2 := fib(n/2 + 1)
		return f1*f1 + f2*f2
	}
}

func BigFib(n int) *big.Int {
	if n == 0 {
		return big.NewInt(0)
	}
	if n%2 == 0 {
		f1 := BigFib(n/2 - 1)
		f1.Mul(f1, f1)
		f2 := BigFib(n/2 + 1)
		f2.Mul(f2, f2)
		return f2.Sub(f2, f1)
	} else {
		f1 := BigFib(n/2)
		f1.Mul(f1, f1)
		f2 := BigFib(n/2 + 1)
		f2.Mul(f2, f2)
		return f2.Add(f2, f1)
	}
}

type PointD struct {
	x, y float64
}

func d(p1, p2 Point) float64 {
	return math.Sqrt(d2(p1, p2))
}

func d2(p1, p2 Point) float64 {
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
}

func d(p1, p2 PointD) float64 {
	return math.Sqrt(d2(p1, p2))
}

func d2(p1, p2 PointD) float64 {
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
}

func id9(n int64) bool {
	if n == 1 {
		return false
	}
	if n%2 == 0 {
		return false
	}
	for j := int64(3); j < int64(math.Sqrt(float64(n)))+1; j += 2 {
		if n%j == 0 {
			return false
		}
	}
	return true
}

func Sieve(n int) []int {
	b := make([]bool, n+1)
	for i := 0; i < n+1; i++ {
		b[i] = true
	}
	b[0] = false
	b[1] = false
	nLong := int64(n)
	j := 0
	for i := 1; i <= n; i++ {
		if b[i] {
			j++
			if int64(i)*int64(i) <= nLong {
				for k := i * i; k <= n; k += i {
					b[k] = false
				}
			}
		}
	}
	p := make([]int, j)
	for i := 2; i <= n; i++ {
		if b[i] {
			p[j] = i
			j++
		}
	}
	return p
}

func id0(s string) [][]int {
	c := []rune(s)
	n := len(c)
	d := make([][]int, 2)
	d[0] = make([]int, n)
	d[1] = make([]int, n)
	l := 0
	r := -1
	for i := 0; i < n; i++ {
		j := min(d[0][l+r-i+1], r-i+1) + 1
		for i-j >= 0 && i+j-1 < n && c[i-j] == c[i+j-1] {
			j++
		}
		d[0][i] = j - 1
		if i+d[0][i]-1 > r {
			r = i + d[0][i] - 1
			l = i - d[0][i]
		}
	}
	l = 0
	r = -1
	for i := 0; i < n; i++ {
		j := min(d[1][l+r-i], r-i) + 1
		for i-j >= 0 && i+j < n && c[i-j] == c[i+j] {
			j++
		}
		d[1][i] = j - 1
		if i+d[1][i] > r {
			r = i + d[1][i]
			l = i - d[1][i]
		}
	}
	return d
}

type Permutation struct {
	a []int
	n int
}

func NewPermutation(n int) *Permutation {
	p := &Permutation{}
	p.n = n
	p.a = make([]int, n)
	for i := 0; i < n; i++ {
		p.a[i] = i
	}
	return p
}

func (p *Permutation) nextPermutation() bool {
	i := p.n - 2
	for i >= 0 && p.a[i] >= p.a[i+1] {
		i--
	}
	if i == -1 {
		return false
	}
	jMin := i + 1
	for j := p.n - 1; j > i; j-- {
		if p.a[i] < p.a[j] && p.a[j] < p.a[jMin] {
			jMin = j
		}
	}
	p.swap(i, jMin)
	for j := 1; j <= (p.n-i)/2; j++ {
		p.swap(i+j, p.n-j)
	}
	return true
}

func (p *Permutation) get(i int) int {
	return p.a[i]
}

func (p *Permutation) swap(i, j int) {
	r := p.a[i]
	p.a[i] = p.a[j]
	p.a[j] = r
}

type Fraction struct {
	numerator   int64
	denominator int64
}

func NewFraction() *Fraction {
	f := &Fraction{}
	f.numerator = 0
	f.denominator = 1
	return f
}

func NewFractionWithNumerator(numerator int64) *Fraction {
	f := &Fraction{}
	f.numerator = numerator
	f.denominator = 1
	return f
}

func NewFractionWithNumeratorAndDenominator(numerator, denominator int64) *Fraction {
	f := &Fraction{}
	f.numerator = numerator
	f.denominator = denominator
	f.Cancellation()
	return f
}

func NewFractionWithFloat(numerator, denominator float64, accuracy int) *Fraction {
	f := &Fraction{}
	f.numerator = int64(numerator * math.Pow(10, float64(accuracy)))
	f.denominator = int64(denominator * math.Pow(10, float64(accuracy)))
	f.Cancellation()
	return f
}

func NewFractionWithString(s string) *Fraction {
	f := &Fraction{}
	if s[0] == '-' {
		f.denominator = -1
		s = s[1:]
	}
	if strings.Contains(s, "/") {
		f.denominator *= int64(strings.Split(s, "/")[1])
	}
	if strings.Contains(s, " ") {
		f.numerator = int64(strings.Split(s, " ")[0])*int64(math.Abs(float64(f.denominator))) + int64(strings.Split(s, " ")[1])
	} else {
		if strings.Contains(s, "/") {
			f.numerator = int64(strings.Split(s, "/")[0])
		} else {
			f.numerator = int64(s) * int64(math.Abs(float64(f.denominator)))
		}
	}
	f.Cancellation()
	return f
}

func (f *Fraction) Cancellation() {
	g := gcd(int64(math.Abs(float64(f.numerator))), int64(math.Abs(float64(f.denominator))))
	f.numerator /= g
	f.denominator /= g
	if f.denominator < 0 {
		f.numerator *= -1
		f.denominator *= -1
	}
}

func (f *Fraction) String() string {
	s := ""
	if f.numerator == 0 {
		return "0"
	}
	if f.numerator < 0 {
		s += "-"
	}
	if int64(math.Abs(float64(f.numerator))) >= f.denominator {
		s += strconv.FormatInt(int64(math.Abs(float64(f.numerator)))/f.denominator, 10) + " "
	}
	if int64(math.Abs(float64(f.numerator)))%f.denominator != 0 {
		s += strconv.FormatInt(int64(math.Abs(float64(f.numerator)))%f.denominator, 10)
	} else {
		s = s[:len(s)-1]
	}
	if f.denominator != 1 {
		s += "/" + strconv.FormatInt(f.denominator, 10)
	}
	return s
}

func (f *Fraction) add(f2 *Fraction) *Fraction {
	fResult := NewFraction()
	fResult.denominator = lcm(int64(math.Abs(float64(f.denominator))), int64(math.Abs(float64(f2.denominator))))
	fResult.numerator = f.numerator*fResult.denominator/f.denominator + f2.numerator*fResult.denominator/f2.denominator
	fResult.Cancellation()
	return fResult
}

func (f *Fraction) subtract(f2 *Fraction) *Fraction {
	fResult := NewFraction()
	fResult.denominator = lcm(int64(math.Abs(float64(f.denominator))), int64(math.Abs(float64(f2.denominator))))
	fResult.numerator = f.numerator*fResult.denominator/f.denominator - f2.numerator*fResult.denominator/f2.denominator
	fResult.Cancellation()
	return fResult
}

func (f *Fraction) multiply(f2 *Fraction) *Fraction {
	fResult := NewFraction()
	fResult.numerator = f.numerator * f2.numerator
	fResult.denominator = f.denominator * f2.denominator
	fResult.Cancellation()
	return fResult
}

func (f *Fraction) divide(f2 *Fraction) *Fraction {
	fResult := NewFraction()
	fResult.numerator = f.numerator * f2.denominator
	fResult.denominator = f.denominator * f2.numerator
	fResult.Cancellation()
	return fResult
}

func (f *Fraction) compareTo(f2 *Fraction) int {
	g := gcd(int64(math.Abs(float64(f.denominator))), int64(math.Abs(float64(f2.denominator))))
	res := f.numerator * (f2.denominator / g) - f2.numerator * (f.denominator / g)
	if res < 0 {
		return -1
	}
	if res > 0 {
		return 1
	}
	return 0
}

func (f *Fraction) clone() *Fraction {
	fResult := NewFractionWithNumeratorAndDenominator(f.numerator, f.denominator)
	return fResult
}

func (f *Fraction) floor() *Fraction {
	fResult := f.clone()
	fResult.numerator = (fResult.numerator / fResult.denominator) * fResult.denominator
	return fResult
}

func (f *Fraction) ceil() *Fraction {
	fResult := f.clone()
	fResult.numerator = (fResult.numerator/fResult.denominator + 1) * fResult.denominator
	return fResult
}

func (f *Fraction) binpow(n int) *Fraction {
	if n == 0 {
		return NewFractionWithNumerator(1)
	}
	if n%2 == 0 {
		fResult := f.binpow(n / 2)
		return fResult.multiply(fResult)
	} else {
		return f.binpow(n - 1).multiply(f)
	}
}

type Point struct {
	x, y int
}

func (p1 *Point) d(p2 *Point) float64 {
	return math.Sqrt(p1.d2(p2))
}

func (p1 *Point) d2(p2 *Point) float64 {
	return float64((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y))
}

type PointD struct {
	x, y float64
}

func (p1 *PointD) d(p2 *PointD) float64 {
	return math.Sqrt(p1.d2(p2))
}

func (p1 *PointD) d2(p2 *PointD) float64 {
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
}

func id9(n int64) bool {
	if n == 1 {
		return false
	}
	if n%2 == 0 {
		return false
	}
	for j := int64(3); j < int64(math.Sqrt(float64(n)))+1; j += 2 {
		if n%j == 0 {
			return false
		}
	}
	return true
}

func Sieve(n int) []int {
	b := make([]bool, n+1)
	for i := 0; i < n+1; i++ {
		b[i] = true
	}
	b[0] = false
	b[1] = false
	nLong := int64(n)
	j := 0
	for i := 1; i <= n; i++ {
		if b[i] {
			j++
			if int64(i)*int64(i) <= nLong {
				for k := i * i; k <= n; k += i {
					b[k] = false
				}
			}
		}
	}
	p := make([]int, j)
	for i := 2; i <= n; i++ {
		if b[i] {
			p[j] = i
			j++
		}
	}
	return p
}

func id0(s string) [][]int {
	c := []rune(s)
	n := len(c)
	d := make([][]int, 2)
	d[0] = make([]int, n)
	d[1] = make([]int, n)
	l := 0
	r := -1
	for i := 0; i < n; i++ {
		j := min(d[0][l+r-i+1], r-i+1) + 1
		for i-j >= 0 && i+j-1 < n && c[i-j] == c[i+j-1] {
			j++
		}
		d[0][i] = j - 1
		if i+d[0][i]-1 > r {
			r = i + d[0][i] - 1
			l = i - d[0][i]
		}
	}
	l = 0
	r = -1
	for i := 0; i < n; i++ {
		j := min(d[1][l+r-i], r-i) + 1
		for i-j >= 0 && i+j < n && c[i-j] == c[i+j] {
			j++
		}
		d[1][i] = j - 1
		if i+d[1][i] > r {
			r = i + d[1][i]
			l = i - d[1][i]
		}
	}
	return d
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	id := id2{}
	id.run()
}
