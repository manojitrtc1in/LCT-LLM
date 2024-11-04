package main

import (
	"fmt"
	"math"
	"strings"
)

type Modular struct {
	value int
}

func NewModular(v int) *Modular {
	return &Modular{value: v}
}

func (m *Modular) Add(o *Modular) *Modular {
	m.value += o.value
	if m.value >= 7 {
		m.value -= 7
	}
	return m
}

func (m *Modular) Subtract(o *Modular) *Modular {
	m.value -= o.value
	if m.value < 0 {
		m.value += 7
	}
	return m
}

func (m *Modular) Multiply(o *Modular) *Modular {
	m.value = (m.value * o.value) % 7
	return m
}

func (m *Modular) Divide(o *Modular) *Modular {
	return m.Multiply(o.Inverse())
}

func (m *Modular) Increment() *Modular {
	m.value++
	return m
}

func (m *Modular) Decrement() *Modular {
	m.value--
	return m
}

func (m *Modular) Exponent(k int) *Modular {
	res := NewModular(1)
	a := NewModular(m.value)
	for k > 0 {
		if k&1 == 1 {
			res.Multiply(a)
		}
		a.Multiply(a)
		k >>= 1
	}
	return res
}

func (m *Modular) Inverse() *Modular {
	return m.Exponent(5)
}

func (m *Modular) String() string {
	return fmt.Sprintf("%d", m.value)
}

type Pair struct {
	first  int
	second int
}

func NewPair(f, s int) *Pair {
	return &Pair{first: f, second: s}
}

func (p *Pair) Add(o *Pair) *Pair {
	return NewPair(p.first+o.first, p.second+o.second)
}

func (p *Pair) Subtract(o *Pair) *Pair {
	return NewPair(p.first-o.first, p.second-o.second)
}

func (p *Pair) Multiply(m int) *Pair {
	return NewPair(p.first*m, p.second*m)
}

func (p *Pair) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type Triple struct {
	first  int
	second int
	third  int
}

func NewTriple(f, s, t int) *Triple {
	return &Triple{first: f, second: s, third: t}
}

func (t *Triple) String() string {
	return fmt.Sprintf("(%d, %d, %d)", t.first, t.second, t.third)
}

type Complex struct {
	real      float64
	imaginary float64
}

func NewComplex(r, i float64) *Complex {
	return &Complex{real: r, imaginary: i}
}

func (c *Complex) Add(o *Complex) *Complex {
	return NewComplex(c.real+o.real, c.imaginary+o.imaginary)
}

func (c *Complex) Subtract(o *Complex) *Complex {
	return NewComplex(c.real-o.real, c.imaginary-o.imaginary)
}

func (c *Complex) Multiply(o *Complex) *Complex {
	return NewComplex(c.real*o.real-c.imaginary*o.imaginary, c.real*o.imaginary+c.imaginary*o.real)
}

func (c *Complex) String() string {
	return fmt.Sprintf("%.8f + %.8fi", c.real, c.imaginary)
}

type String string

func (s String) String() string {
	return string(s)
}

type PairInt struct {
	first  int
	second int
}

func NewPairInt(f, s int) *PairInt {
	return &PairInt{first: f, second: s}
}

func (p *PairInt) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type PairLL struct {
	first  int64
	second int64
}

func NewPairLL(f, s int64) *PairLL {
	return &PairLL{first: f, second: s}
}

func (p *PairLL) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type PairDB struct {
	first  float64
	second float64
}

func NewPairDB(f, s float64) *PairDB {
	return &PairDB{first: f, second: s}
}

func (p *PairDB) String() string {
	return fmt.Sprintf("(%.8f, %.8f)", p.first, p.second)
}

type PairLDB struct {
	first  float64
	second float64
}

func NewPairLDB(f, s float64) *PairLDB {
	return &PairLDB{first: f, second: s}
}

func (p *PairLDB) String() string {
	return fmt.Sprintf("(%.10f, %.10f)", p.first, p.second)
}

type PairIntLL struct {
	first  int
	second int64
}

func NewPairIntLL(f int, s int64) *PairIntLL {
	return &PairIntLL{first: f, second: s}
}

func (p *PairIntLL) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type PairLLInt struct {
	first  int64
	second int
}

func NewPairLLInt(f int64, s int) *PairLLInt {
	return &PairLLInt{first: f, second: s}
}

func (p *PairLLInt) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type VectorInt []int

func NewVectorInt() *VectorInt {
	return &VectorInt{}
}

func (v *VectorInt) PushBack(x int) {
	*v = append(*v, x)
}

func (v *VectorInt) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorInt) Size() int {
	return len(*v)
}

func (v *VectorInt) Begin() int {
	return (*v)[0]
}

func (v *VectorInt) End() int {
	return (*v)[len(*v)-1]
}

func (v *VectorInt) All() []int {
	return *v
}

func (v *VectorInt) First() int {
	return (*v)[0]
}

func (v *VectorInt) Last() int {
	return (*v)[len(*v)-1]
}

func (v *VectorInt) At(i int) int {
	return (*v)[i]
}

func (v *VectorInt) Set(i, x int) {
	(*v)[i] = x
}

func (v *VectorInt) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorLL []int64

func NewVectorLL() *VectorLL {
	return &VectorLL{}
}

func (v *VectorLL) PushBack(x int64) {
	*v = append(*v, x)
}

func (v *VectorLL) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorLL) Size() int {
	return len(*v)
}

func (v *VectorLL) Begin() int64 {
	return (*v)[0]
}

func (v *VectorLL) End() int64 {
	return (*v)[len(*v)-1]
}

func (v *VectorLL) All() []int64 {
	return *v
}

func (v *VectorLL) First() int64 {
	return (*v)[0]
}

func (v *VectorLL) Last() int64 {
	return (*v)[len(*v)-1]
}

func (v *VectorLL) At(i int) int64 {
	return (*v)[i]
}

func (v *VectorLL) Set(i int, x int64) {
	(*v)[i] = x
}

func (v *VectorLL) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorString []string

func NewVectorString() *VectorString {
	return &VectorString{}
}

func (v *VectorString) PushBack(x string) {
	*v = append(*v, x)
}

func (v *VectorString) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorString) Size() int {
	return len(*v)
}

func (v *VectorString) Begin() string {
	return (*v)[0]
}

func (v *VectorString) End() string {
	return (*v)[len(*v)-1]
}

func (v *VectorString) All() []string {
	return *v
}

func (v *VectorString) First() string {
	return (*v)[0]
}

func (v *VectorString) Last() string {
	return (*v)[len(*v)-1]
}

func (v *VectorString) At(i int) string {
	return (*v)[i]
}

func (v *VectorString) Set(i int, x string) {
	(*v)[i] = x
}

func (v *VectorString) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorChar []byte

func NewVectorChar() *VectorChar {
	return &VectorChar{}
}

func (v *VectorChar) PushBack(x byte) {
	*v = append(*v, x)
}

func (v *VectorChar) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorChar) Size() int {
	return len(*v)
}

func (v *VectorChar) Begin() byte {
	return (*v)[0]
}

func (v *VectorChar) End() byte {
	return (*v)[len(*v)-1]
}

func (v *VectorChar) All() []byte {
	return *v
}

func (v *VectorChar) First() byte {
	return (*v)[0]
}

func (v *VectorChar) Last() byte {
	return (*v)[len(*v)-1]
}

func (v *VectorChar) At(i int) byte {
	return (*v)[i]
}

func (v *VectorChar) Set(i int, x byte) {
	(*v)[i] = x
}

func (v *VectorChar) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorBool []bool

func NewVectorBool() *VectorBool {
	return &VectorBool{}
}

func (v *VectorBool) PushBack(x bool) {
	*v = append(*v, x)
}

func (v *VectorBool) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorBool) Size() int {
	return len(*v)
}

func (v *VectorBool) Begin() bool {
	return (*v)[0]
}

func (v *VectorBool) End() bool {
	return (*v)[len(*v)-1]
}

func (v *VectorBool) All() []bool {
	return *v
}

func (v *VectorBool) First() bool {
	return (*v)[0]
}

func (v *VectorBool) Last() bool {
	return (*v)[len(*v)-1]
}

func (v *VectorBool) At(i int) bool {
	return (*v)[i]
}

func (v *VectorBool) Set(i int, x bool) {
	(*v)[i] = x
}

func (v *VectorBool) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorFloat []float32

func NewVectorFloat() *VectorFloat {
	return &VectorFloat{}
}

func (v *VectorFloat) PushBack(x float32) {
	*v = append(*v, x)
}

func (v *VectorFloat) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorFloat) Size() int {
	return len(*v)
}

func (v *VectorFloat) Begin() float32 {
	return (*v)[0]
}

func (v *VectorFloat) End() float32 {
	return (*v)[len(*v)-1]
}

func (v *VectorFloat) All() []float32 {
	return *v
}

func (v *VectorFloat) First() float32 {
	return (*v)[0]
}

func (v *VectorFloat) Last() float32 {
	return (*v)[len(*v)-1]
}

func (v *VectorFloat) At(i int) float32 {
	return (*v)[i]
}

func (v *VectorFloat) Set(i int, x float32) {
	(*v)[i] = x
}

func (v *VectorFloat) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorDouble []float64

func NewVectorDouble() *VectorDouble {
	return &VectorDouble{}
}

func (v *VectorDouble) PushBack(x float64) {
	*v = append(*v, x)
}

func (v *VectorDouble) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorDouble) Size() int {
	return len(*v)
}

func (v *VectorDouble) Begin() float64 {
	return (*v)[0]
}

func (v *VectorDouble) End() float64 {
	return (*v)[len(*v)-1]
}

func (v *VectorDouble) All() []float64 {
	return *v
}

func (v *VectorDouble) First() float64 {
	return (*v)[0]
}

func (v *VectorDouble) Last() float64 {
	return (*v)[len(*v)-1]
}

func (v *VectorDouble) At(i int) float64 {
	return (*v)[i]
}

func (v *VectorDouble) Set(i int, x float64) {
	(*v)[i] = x
}

func (v *VectorDouble) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairInt []PairInt

func NewVectorPairInt() *VectorPairInt {
	return &VectorPairInt{}
}

func (v *VectorPairInt) PushBack(x *PairInt) {
	*v = append(*v, *x)
}

func (v *VectorPairInt) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairInt) Size() int {
	return len(*v)
}

func (v *VectorPairInt) Begin() *PairInt {
	return &(*v)[0]
}

func (v *VectorPairInt) End() *PairInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairInt) All() []PairInt {
	return *v
}

func (v *VectorPairInt) First() *PairInt {
	return &(*v)[0]
}

func (v *VectorPairInt) Last() *PairInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairInt) At(i int) *PairInt {
	return &(*v)[i]
}

func (v *VectorPairInt) Set(i int, x *PairInt) {
	(*v)[i] = *x
}

func (v *VectorPairInt) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairLL []PairLL

func NewVectorPairLL() *VectorPairLL {
	return &VectorPairLL{}
}

func (v *VectorPairLL) PushBack(x *PairLL) {
	*v = append(*v, *x)
}

func (v *VectorPairLL) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairLL) Size() int {
	return len(*v)
}

func (v *VectorPairLL) Begin() *PairLL {
	return &(*v)[0]
}

func (v *VectorPairLL) End() *PairLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLL) All() []PairLL {
	return *v
}

func (v *VectorPairLL) First() *PairLL {
	return &(*v)[0]
}

func (v *VectorPairLL) Last() *PairLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLL) At(i int) *PairLL {
	return &(*v)[i]
}

func (v *VectorPairLL) Set(i int, x *PairLL) {
	(*v)[i] = *x
}

func (v *VectorPairLL) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairDB []PairDB

func NewVectorPairDB() *VectorPairDB {
	return &VectorPairDB{}
}

func (v *VectorPairDB) PushBack(x *PairDB) {
	*v = append(*v, *x)
}

func (v *VectorPairDB) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairDB) Size() int {
	return len(*v)
}

func (v *VectorPairDB) Begin() *PairDB {
	return &(*v)[0]
}

func (v *VectorPairDB) End() *PairDB {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairDB) All() []PairDB {
	return *v
}

func (v *VectorPairDB) First() *PairDB {
	return &(*v)[0]
}

func (v *VectorPairDB) Last() *PairDB {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairDB) At(i int) *PairDB {
	return &(*v)[i]
}

func (v *VectorPairDB) Set(i int, x *PairDB) {
	(*v)[i] = *x
}

func (v *VectorPairDB) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairLDB []PairLDB

func NewVectorPairLDB() *VectorPairLDB {
	return &VectorPairLDB{}
}

func (v *VectorPairLDB) PushBack(x *PairLDB) {
	*v = append(*v, *x)
}

func (v *VectorPairLDB) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairLDB) Size() int {
	return len(*v)
}

func (v *VectorPairLDB) Begin() *PairLDB {
	return &(*v)[0]
}

func (v *VectorPairLDB) End() *PairLDB {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLDB) All() []PairLDB {
	return *v
}

func (v *VectorPairLDB) First() *PairLDB {
	return &(*v)[0]
}

func (v *VectorPairLDB) Last() *PairLDB {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLDB) At(i int) *PairLDB {
	return &(*v)[i]
}

func (v *VectorPairLDB) Set(i int, x *PairLDB) {
	(*v)[i] = *x
}

func (v *VectorPairLDB) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairIntLL []PairIntLL

func NewVectorPairIntLL() *VectorPairIntLL {
	return &VectorPairIntLL{}
}

func (v *VectorPairIntLL) PushBack(x *PairIntLL) {
	*v = append(*v, *x)
}

func (v *VectorPairIntLL) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairIntLL) Size() int {
	return len(*v)
}

func (v *VectorPairIntLL) Begin() *PairIntLL {
	return &(*v)[0]
}

func (v *VectorPairIntLL) End() *PairIntLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairIntLL) All() []PairIntLL {
	return *v
}

func (v *VectorPairIntLL) First() *PairIntLL {
	return &(*v)[0]
}

func (v *VectorPairIntLL) Last() *PairIntLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairIntLL) At(i int) *PairIntLL {
	return &(*v)[i]
}

func (v *VectorPairIntLL) Set(i int, x *PairIntLL) {
	(*v)[i] = *x
}

func (v *VectorPairIntLL) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorPairLLInt []PairLLInt

func NewVectorPairLLInt() *VectorPairLLInt {
	return &VectorPairLLInt{}
}

func (v *VectorPairLLInt) PushBack(x *PairLLInt) {
	*v = append(*v, *x)
}

func (v *VectorPairLLInt) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorPairLLInt) Size() int {
	return len(*v)
}

func (v *VectorPairLLInt) Begin() *PairLLInt {
	return &(*v)[0]
}

func (v *VectorPairLLInt) End() *PairLLInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLLInt) All() []PairLLInt {
	return *v
}

func (v *VectorPairLLInt) First() *PairLLInt {
	return &(*v)[0]
}

func (v *VectorPairLLInt) Last() *PairLLInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorPairLLInt) At(i int) *PairLLInt {
	return &(*v)[i]
}

func (v *VectorPairLLInt) Set(i int, x *PairLLInt) {
	(*v)[i] = *x
}

func (v *VectorPairLLInt) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorVectorInt []VectorInt

func NewVectorVectorInt() *VectorVectorInt {
	return &VectorVectorInt{}
}

func (v *VectorVectorInt) PushBack(x *VectorInt) {
	*v = append(*v, *x)
}

func (v *VectorVectorInt) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorVectorInt) Size() int {
	return len(*v)
}

func (v *VectorVectorInt) Begin() *VectorInt {
	return &(*v)[0]
}

func (v *VectorVectorInt) End() *VectorInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorVectorInt) All() []VectorInt {
	return *v
}

func (v *VectorVectorInt) First() *VectorInt {
	return &(*v)[0]
}

func (v *VectorVectorInt) Last() *VectorInt {
	return &(*v)[len(*v)-1]
}

func (v *VectorVectorInt) At(i int) *VectorInt {
	return &(*v)[i]
}

func (v *VectorVectorInt) Set(i int, x *VectorInt) {
	(*v)[i] = *x
}

func (v *VectorVectorInt) String() string {
	return fmt.Sprintf("%v", *v)
}

type VectorVectorLL []VectorLL

func NewVectorVectorLL() *VectorVectorLL {
	return &VectorVectorLL{}
}

func (v *VectorVectorLL) PushBack(x *VectorLL) {
	*v = append(*v, *x)
}

func (v *VectorVectorLL) PopBack() {
	*v = (*v)[:len(*v)-1]
}

func (v *VectorVectorLL) Size() int {
	return len(*v)
}

func (v *VectorVectorLL) Begin() *VectorLL {
	return &(*v)[0]
}

func (v *VectorVectorLL) End() *VectorLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorVectorLL) All() []VectorLL {
	return *v
}

func (v *VectorVectorLL) First() *VectorLL {
	return &(*v)[0]
}

func (v *VectorVectorLL) Last() *VectorLL {
	return &(*v)[len(*v)-1]
}

func (v *VectorVectorLL) At(i int) *VectorLL {
	return &(*v)[i]
}

func (v *VectorVectorLL) Set(i int, x *VectorLL) {
	(*v)[i] = *x
}

func (v *VectorVectorLL) String() string {
	return fmt.Sprintf("%v", *v)
}

func main() {
	t := si()
	for t > 0 {
		print(solve())
		t--
	}
}

func dag(g *VectorVectorInt, cur *VectorInt) int {
	get := func(v int) int {
		for i := 0; i < cur.Size(); i++ {
			if cur.At(i) == v {
				return i
			}
		}
		return -1
	}

	n := cur.Size()
	dp := make([]bool, 1<<n)
	reach := make([]int, n)

	for i := 0; i < n; i++ {
		for _, s := range g.At(cur.At(i)).All() {
			reach[i] |= 1 << get(s)
		}
	}

	res := 0
	dp[0] = true
	for m := 1; m < 1<<n; m++ {
		for i := 0; i < n; i++ {
			if m&(1<<i) != 0 {
				dp[m] = dp[m] || (dp[m^(1<<i)] && (reach[i]&m) == 0)
			}
		}
		if dp[m] {
			res = int(math.Max(float64(res), float64(pct(m))))
		}
	}

	return res
}

func solve() int {
	n := si()
	s := ss(n)
	t := ss(n)
	get := func(c byte) int {
		return int(c - 'a')
	}

	G := NewVectorVectorInt()
	g := NewVectorVectorInt()
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(s[i])
			b := get(t[i])
			G.PushBack(NewVectorInt())
			G.At(a).PushBack(b)
			G.PushBack(NewVectorInt())
			G.At(b).PushBack(a)
			g.PushBack(NewVectorInt())
			g.At(a).PushBack(b)
		}
	}

	cur := NewVectorInt()
	vis := make([]bool, 20)
	dfs := func(v int) {
		vis[v] = true
		cur.PushBack(v)
		for _, s := range G.At(v).All() {
			if !vis[s] {
				dfs(s)
			}
		}
	}

	res := 0
	for i := 0; i < 20; i++ {
		if !vis[i] {
			cur = NewVectorInt()
			dfs(i)
			s := dag(g, cur)
			res += 2*cur.Size() - 1 - s
		}
	}

	return res
}

func si() int {
	var x int
	fmt.Scan(&x)
	return x
}

func ss(n int) string {
	var x string
	fmt.Scan(&x)
	return x
}

func pct(x int) int {
	return strings.Count(fmt.Sprintf("%b", x), "1")
}

func main() {
	t := si()
	for t > 0 {
		print(solve())
		t--
	}
}

func print(args ...interface{}) {
	fmt.Println(args...)
}
