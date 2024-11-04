package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

type Mint struct {
	value int
}

func NewMint(x int) Mint {
	return Mint{x}
}

func (m Mint) Normalize(x int) int {
	v := x % m.value
	if v < 0 {
		v += m.value
	}
	return v
}

func (m Mint) Mod() int {
	return m.value
}

func (m Mint) Add(a, b Mint) Mint {
	return Mint{m.Normalize(a.value + b.value)}
}

func (m Mint) Subtract(a, b Mint) Mint {
	return Mint{m.Normalize(a.value - b.value)}
}

func (m Mint) Multiply(a, b Mint) Mint {
	return Mint{m.Normalize(a.value * b.value)}
}

func (m Mint) Power(a Mint, b int) Mint {
	res := Mint{1}
	x := a
	for b > 0 {
		if b&1 == 1 {
			res = m.Multiply(res, x)
		}
		x = m.Multiply(x, x)
		b >>= 1
	}
	return res
}

func (m Mint) Inverse(a Mint) Mint {
	u, v := 0, 1
	x, y := a.value, m.value
	for x != 0 {
		q := y / x
		y, x = x, y-q*x
		v, u = u-q*v, v
	}
	return Mint{u}
}

func (m Mint) String() string {
	return fmt.Sprintf("%d", m.value)
}

func (m Mint) Equals(a Mint) bool {
	return m.value == a.value
}

func (m Mint) Less(a Mint) bool {
	return m.value < a.value
}

type Modular struct {
	value int
}

func NewModular(x int) Modular {
	return Modular{x}
}

func (m Modular) Normalize(x int) int {
	v := x % m.value
	if v < 0 {
		v += m.value
	}
	return v
}

func (m Modular) Mod() int {
	return m.value
}

func (m Modular) Add(a, b Modular) Modular {
	return Modular{m.Normalize(a.value + b.value)}
}

func (m Modular) Subtract(a, b Modular) Modular {
	return Modular{m.Normalize(a.value - b.value)}
}

func (m Modular) Multiply(a, b Modular) Modular {
	return Modular{m.Normalize(a.value * b.value)}
}

func (m Modular) Power(a Modular, b int) Modular {
	res := Modular{1}
	x := a
	for b > 0 {
		if b&1 == 1 {
			res = m.Multiply(res, x)
		}
		x = m.Multiply(x, x)
		b >>= 1
	}
	return res
}

func (m Modular) Inverse(a Modular) Modular {
	u, v := 0, 1
	x, y := a.value, m.value
	for x != 0 {
		q := y / x
		y, x = x, y-q*x
		v, u = u-q*v, v
	}
	return Modular{u}
}

func (m Modular) String() string {
	return fmt.Sprintf("%d", m.value)
}

func (m Modular) Equals(a Modular) bool {
	return m.value == a.value
}

func (m Modular) Less(a Modular) bool {
	return m.value < a.value
}

type Cerr struct{}

func (c Cerr) Write(p []byte) (n int, err error) {
	return len(p), nil
}

var cerr = Cerr{}

type Random struct {
	seed int64
}

func NewRandom(seed int64) Random {
	return Random{seed}
}

func (r *Random) Next() int {
	r.seed = (r.seed*1103515245 + 12345) & math.MaxInt64
	return int(r.seed)
}

func (r *Random) Shuffle(a []int) {
	n := len(a)
	for i := n - 1; i >= 1; i-- {
		j := r.Next() % (i + 1)
		a[i], a[j] = a[j], a[i]
	}
}

func (r *Random) Permutation(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = i
	}
	r.Shuffle(a)
	return a
}

func (r *Random) Int(min, max int) int {
	return min + r.Next()%(max-min+1)
}

func (r *Random) Long(min, max int64) int64 {
	return min + r.Next()%(max-min+1)
}

func (r *Random) Double() float64 {
	return float64(r.Next()) / math.MaxInt64
}

type Pair struct {
	first  int
	second int
}

type Triple struct {
	first  int
	second int
	third  int
}

type Quadruple struct {
	first  int
	second int
	third  int
	fourth int
}

type Vector []int

func NewVector(n int) Vector {
	return make([]int, n)
}

func (v Vector) Size() int {
	return len(v)
}

func (v Vector) Get(i int) int {
	return v[i]
}

func (v Vector) Set(i, x int) {
	v[i] = x
}

func (v Vector) Fill(x int) {
	for i := 0; i < len(v); i++ {
		v[i] = x
	}
}

func (v Vector) Reverse() {
	n := len(v)
	for i := 0; i < n/2; i++ {
		v[i], v[n-1-i] = v[n-1-i], v[i]
	}
}

func (v Vector) Sort() {
	sort.Ints(v)
}

func (v Vector) Shuffle(r Random) {
	r.Shuffle(v)
}

func (v Vector) Permutation(r Random) {
	a := r.Permutation(len(v))
	for i := 0; i < len(v); i++ {
		v[i] = a[i]
	}
}

func (v Vector) Sum() int {
	s := 0
	for i := 0; i < len(v); i++ {
		s += v[i]
	}
	return s
}

func (v Vector) ReverseSum() int {
	s := 0
	for i := len(v) - 1; i >= 0; i-- {
		s += v[i]
	}
	return s
}

func (v Vector) Product() int {
	p := 1
	for i := 0; i < len(v); i++ {
		p *= v[i]
	}
	return p
}

func (v Vector) ReverseProduct() int {
	p := 1
	for i := len(v) - 1; i >= 0; i-- {
		p *= v[i]
	}
	return p
}

func (v Vector) Min() int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := v[0]
	for i := 1; i < len(v); i++ {
		if v[i] < min {
			min = v[i]
		}
	}
	return min
}

func (v Vector) Max() int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := v[0]
	for i := 1; i < len(v); i++ {
		if v[i] > max {
			max = v[i]
		}
	}
	return max
}

func (v Vector) ReverseMin() int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := v[len(v)-1]
	for i := len(v) - 2; i >= 0; i-- {
		if v[i] < min {
			min = v[i]
		}
	}
	return min
}

func (v Vector) ReverseMax() int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := v[len(v)-1]
	for i := len(v) - 2; i >= 0; i-- {
		if v[i] > max {
			max = v[i]
		}
	}
	return max
}

func (v Vector) Unique() Vector {
	if len(v) == 0 {
		return v
	}
	u := make([]int, 0, len(v))
	u = append(u, v[0])
	for i := 1; i < len(v); i++ {
		if v[i] != v[i-1] {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) Contains(x int) bool {
	for i := 0; i < len(v); i++ {
		if v[i] == x {
			return true
		}
	}
	return false
}

func (v Vector) ReverseContains(x int) bool {
	for i := len(v) - 1; i >= 0; i-- {
		if v[i] == x {
			return true
		}
	}
	return false
}

func (v Vector) Index(x int) int {
	for i := 0; i < len(v); i++ {
		if v[i] == x {
			return i
		}
	}
	return -1
}

func (v Vector) ReverseIndex(x int) int {
	for i := len(v) - 1; i >= 0; i-- {
		if v[i] == x {
			return i
		}
	}
	return -1
}

func (v Vector) Count(x int) int {
	c := 0
	for i := 0; i < len(v); i++ {
		if v[i] == x {
			c++
		}
	}
	return c
}

func (v Vector) ReverseCount(x int) int {
	c := 0
	for i := len(v) - 1; i >= 0; i-- {
		if v[i] == x {
			c++
		}
	}
	return c
}

func (v Vector) All(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if !f(v[i]) {
			return false
		}
	}
	return true
}

func (v Vector) Any(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			return true
		}
	}
	return false
}

func (v Vector) None(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			return false
		}
	}
	return true
}

func (v Vector) Filter(f func(int) bool) Vector {
	u := make([]int, 0, len(v))
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) ReverseFilter(f func(int) bool) Vector {
	u := make([]int, 0, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i]) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) Map(f func(int) int) Vector {
	u := make([]int, len(v))
	for i := 0; i < len(v); i++ {
		u[i] = f(v[i])
	}
	return u
}

func (v Vector) ReverseMap(f func(int) int) Vector {
	u := make([]int, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		u[i] = f(v[i])
	}
	return u
}

func (v Vector) SumBy(f func(int) int) int {
	s := 0
	for i := 0; i < len(v); i++ {
		s += f(v[i])
	}
	return s
}

func (v Vector) ReverseSumBy(f func(int) int) int {
	s := 0
	for i := len(v) - 1; i >= 0; i-- {
		s += f(v[i])
	}
	return s
}

func (v Vector) ProductBy(f func(int) int) int {
	p := 1
	for i := 0; i < len(v); i++ {
		p *= f(v[i])
	}
	return p
}

func (v Vector) ReverseProductBy(f func(int) int) int {
	p := 1
	for i := len(v) - 1; i >= 0; i-- {
		p *= f(v[i])
	}
	return p
}

func (v Vector) MinBy(f func(int) int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[0])
	for i := 1; i < len(v); i++ {
		if x := f(v[i]); x < min {
			min = x
		}
	}
	return min
}

func (v Vector) MaxBy(f func(int) int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[0])
	for i := 1; i < len(v); i++ {
		if x := f(v[i]); x > max {
			max = x
		}
	}
	return max
}

func (v Vector) ReverseMinBy(f func(int) int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[len(v)-1])
	for i := len(v) - 2; i >= 0; i-- {
		if x := f(v[i]); x < min {
			min = x
		}
	}
	return min
}

func (v Vector) ReverseMaxBy(f func(int) int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[len(v)-1])
	for i := len(v) - 2; i >= 0; i-- {
		if x := f(v[i]); x > max {
			max = x
		}
	}
	return max
}

func (v Vector) UniqueBy(f func(int) int) Vector {
	if len(v) == 0 {
		return v
	}
	u := make([]int, 0, len(v))
	u = append(u, v[0])
	prev := f(v[0])
	for i := 1; i < len(v); i++ {
		if x := f(v[i]); x != prev {
			u = append(u, v[i])
			prev = x
		}
	}
	return u
}

func (v Vector) ContainsBy(x int, f func(int) int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i]) == x {
			return true
		}
	}
	return false
}

func (v Vector) ReverseContainsBy(x int, f func(int) int) bool {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i]) == x {
			return true
		}
	}
	return false
}

func (v Vector) IndexBy(x int, f func(int) int) int {
	for i := 0; i < len(v); i++ {
		if f(v[i]) == x {
			return i
		}
	}
	return -1
}

func (v Vector) ReverseIndexBy(x int, f func(int) int) int {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i]) == x {
			return i
		}
	}
	return -1
}

func (v Vector) CountBy(x int, f func(int) int) int {
	c := 0
	for i := 0; i < len(v); i++ {
		if f(v[i]) == x {
			c++
		}
	}
	return c
}

func (v Vector) ReverseCountBy(x int, f func(int) int) int {
	c := 0
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i]) == x {
			c++
		}
	}
	return c
}

func (v Vector) AllBy(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if !f(v[i]) {
			return false
		}
	}
	return true
}

func (v Vector) AnyBy(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			return true
		}
	}
	return false
}

func (v Vector) NoneBy(f func(int) bool) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			return false
		}
	}
	return true
}

func (v Vector) FilterBy(f func(int) bool) Vector {
	u := make([]int, 0, len(v))
	for i := 0; i < len(v); i++ {
		if f(v[i]) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) ReverseFilterBy(f func(int) bool) Vector {
	u := make([]int, 0, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i]) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) MapBy(f func(int) int, g func(int) int) Vector {
	u := make([]int, len(v))
	for i := 0; i < len(v); i++ {
		u[i] = f(g(v[i]))
	}
	return u
}

func (v Vector) ReverseMapBy(f func(int) int, g func(int) int) Vector {
	u := make([]int, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		u[i] = f(g(v[i]))
	}
	return u
}

func (v Vector) SumBy2(f func(int, int) int, x int) int {
	s := 0
	for i := 0; i < len(v); i++ {
		s += f(v[i], x)
	}
	return s
}

func (v Vector) ReverseSumBy2(f func(int, int) int, x int) int {
	s := 0
	for i := len(v) - 1; i >= 0; i-- {
		s += f(v[i], x)
	}
	return s
}

func (v Vector) ProductBy2(f func(int, int) int, x int) int {
	p := 1
	for i := 0; i < len(v); i++ {
		p *= f(v[i], x)
	}
	return p
}

func (v Vector) ReverseProductBy2(f func(int, int) int, x int) int {
	p := 1
	for i := len(v) - 1; i >= 0; i-- {
		p *= f(v[i], x)
	}
	return p
}

func (v Vector) MinBy2(f func(int, int) int, x int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[0], x)
	for i := 1; i < len(v); i++ {
		if y := f(v[i], x); y < min {
			min = y
		}
	}
	return min
}

func (v Vector) MaxBy2(f func(int, int) int, x int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[0], x)
	for i := 1; i < len(v); i++ {
		if y := f(v[i], x); y > max {
			max = y
		}
	}
	return max
}

func (v Vector) ReverseMinBy2(f func(int, int) int, x int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[len(v)-1], x)
	for i := len(v) - 2; i >= 0; i-- {
		if y := f(v[i], x); y < min {
			min = y
		}
	}
	return min
}

func (v Vector) ReverseMaxBy2(f func(int, int) int, x int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[len(v)-1], x)
	for i := len(v) - 2; i >= 0; i-- {
		if y := f(v[i], x); y > max {
			max = y
		}
	}
	return max
}

func (v Vector) UniqueBy2(f func(int, int) int, x int) Vector {
	if len(v) == 0 {
		return v
	}
	u := make([]int, 0, len(v))
	u = append(u, v[0])
	prev := f(v[0], x)
	for i := 1; i < len(v); i++ {
		if y := f(v[i], x); y != prev {
			u = append(u, v[i])
			prev = y
		}
	}
	return u
}

func (v Vector) ContainsBy2(x int, f func(int, int) int, g func(int) int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) ReverseContainsBy2(x int, f func(int, int) int, g func(int) int) bool {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) IndexBy2(x int, f func(int, int) int, g func(int) int) int {
	for i := 0; i < len(v); i++ {
		if f(v[i], x) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) ReverseIndexBy2(x int, f func(int, int) int, g func(int) int) int {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) CountBy2(x int, f func(int, int) int, g func(int) int) int {
	c := 0
	for i := 0; i < len(v); i++ {
		if f(v[i], x) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) ReverseCountBy2(x int, f func(int, int) int, g func(int) int) int {
	c := 0
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) AllBy2(f func(int, int) bool, x int) bool {
	for i := 0; i < len(v); i++ {
		if !f(v[i], x) {
			return false
		}
	}
	return true
}

func (v Vector) AnyBy2(f func(int, int) bool, x int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x) {
			return true
		}
	}
	return false
}

func (v Vector) NoneBy2(f func(int, int) bool, x int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x) {
			return false
		}
	}
	return true
}

func (v Vector) FilterBy2(f func(int, int) bool, x int) Vector {
	u := make([]int, 0, len(v))
	for i := 0; i < len(v); i++ {
		if f(v[i], x) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) ReverseFilterBy2(f func(int, int) bool, x int) Vector {
	u := make([]int, 0, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) MapBy2(f func(int, int) int, g func(int) int, x int) Vector {
	u := make([]int, len(v))
	for i := 0; i < len(v); i++ {
		u[i] = f(g(v[i]), x)
	}
	return u
}

func (v Vector) ReverseMapBy2(f func(int, int) int, g func(int) int, x int) Vector {
	u := make([]int, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		u[i] = f(g(v[i]), x)
	}
	return u
}

func (v Vector) SumBy3(f func(int, int, int) int, x, y int) int {
	s := 0
	for i := 0; i < len(v); i++ {
		s += f(v[i], x, y)
	}
	return s
}

func (v Vector) ReverseSumBy3(f func(int, int, int) int, x, y int) int {
	s := 0
	for i := len(v) - 1; i >= 0; i-- {
		s += f(v[i], x, y)
	}
	return s
}

func (v Vector) ProductBy3(f func(int, int, int) int, x, y int) int {
	p := 1
	for i := 0; i < len(v); i++ {
		p *= f(v[i], x, y)
	}
	return p
}

func (v Vector) ReverseProductBy3(f func(int, int, int) int, x, y int) int {
	p := 1
	for i := len(v) - 1; i >= 0; i-- {
		p *= f(v[i], x, y)
	}
	return p
}

func (v Vector) MinBy3(f func(int, int, int) int, x, y int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[0], x, y)
	for i := 1; i < len(v); i++ {
		if z := f(v[i], x, y); z < min {
			min = z
		}
	}
	return min
}

func (v Vector) MaxBy3(f func(int, int, int) int, x, y int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[0], x, y)
	for i := 1; i < len(v); i++ {
		if z := f(v[i], x, y); z > max {
			max = z
		}
	}
	return max
}

func (v Vector) ReverseMinBy3(f func(int, int, int) int, x, y int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[len(v)-1], x, y)
	for i := len(v) - 2; i >= 0; i-- {
		if z := f(v[i], x, y); z < min {
			min = z
		}
	}
	return min
}

func (v Vector) ReverseMaxBy3(f func(int, int, int) int, x, y int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[len(v)-1], x, y)
	for i := len(v) - 2; i >= 0; i-- {
		if z := f(v[i], x, y); z > max {
			max = z
		}
	}
	return max
}

func (v Vector) UniqueBy3(f func(int, int, int) int, x, y int) Vector {
	if len(v) == 0 {
		return v
	}
	u := make([]int, 0, len(v))
	u = append(u, v[0])
	prev := f(v[0], x, y)
	for i := 1; i < len(v); i++ {
		if z := f(v[i], x, y); z != prev {
			u = append(u, v[i])
			prev = z
		}
	}
	return u
}

func (v Vector) ContainsBy3(x, y int, f func(int, int, int) int, g func(int) int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) ReverseContainsBy3(x, y int, f func(int, int, int) int, g func(int) int) bool {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) IndexBy3(x, y int, f func(int, int, int) int, g func(int) int) int {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) ReverseIndexBy3(x, y int, f func(int, int, int) int, g func(int) int) int {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) CountBy3(x, y int, f func(int, int, int) int, g func(int) int) int {
	c := 0
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) ReverseCountBy3(x, y int, f func(int, int, int) int, g func(int) int) int {
	c := 0
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) AllBy3(f func(int, int, int) bool, x, y int) bool {
	for i := 0; i < len(v); i++ {
		if !f(v[i], x, y) {
			return false
		}
	}
	return true
}

func (v Vector) AnyBy3(f func(int, int, int) bool, x, y int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) {
			return true
		}
	}
	return false
}

func (v Vector) NoneBy3(f func(int, int, int) bool, x, y int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) {
			return false
		}
	}
	return true
}

func (v Vector) FilterBy3(f func(int, int, int) bool, x, y int) Vector {
	u := make([]int, 0, len(v))
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) ReverseFilterBy3(f func(int, int, int) bool, x, y int) Vector {
	u := make([]int, 0, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) MapBy3(f func(int, int, int) int, g func(int) int, x, y int) Vector {
	u := make([]int, len(v))
	for i := 0; i < len(v); i++ {
		u[i] = f(g(v[i]), x, y)
	}
	return u
}

func (v Vector) ReverseMapBy3(f func(int, int, int) int, g func(int) int, x, y int) Vector {
	u := make([]int, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		u[i] = f(g(v[i]), x, y)
	}
	return u
}

func (v Vector) SumBy4(f func(int, int, int, int) int, x, y, z int) int {
	s := 0
	for i := 0; i < len(v); i++ {
		s += f(v[i], x, y, z)
	}
	return s
}

func (v Vector) ReverseSumBy4(f func(int, int, int, int) int, x, y, z int) int {
	s := 0
	for i := len(v) - 1; i >= 0; i-- {
		s += f(v[i], x, y, z)
	}
	return s
}

func (v Vector) ProductBy4(f func(int, int, int, int) int, x, y, z int) int {
	p := 1
	for i := 0; i < len(v); i++ {
		p *= f(v[i], x, y, z)
	}
	return p
}

func (v Vector) ReverseProductBy4(f func(int, int, int, int) int, x, y, z int) int {
	p := 1
	for i := len(v) - 1; i >= 0; i-- {
		p *= f(v[i], x, y, z)
	}
	return p
}

func (v Vector) MinBy4(f func(int, int, int, int) int, x, y, z int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[0], x, y, z)
	for i := 1; i < len(v); i++ {
		if w := f(v[i], x, y, z); w < min {
			min = w
		}
	}
	return min
}

func (v Vector) MaxBy4(f func(int, int, int, int) int, x, y, z int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[0], x, y, z)
	for i := 1; i < len(v); i++ {
		if w := f(v[i], x, y, z); w > max {
			max = w
		}
	}
	return max
}

func (v Vector) ReverseMinBy4(f func(int, int, int, int) int, x, y, z int) int {
	if len(v) == 0 {
		return math.MaxInt64
	}
	min := f(v[len(v)-1], x, y, z)
	for i := len(v) - 2; i >= 0; i-- {
		if w := f(v[i], x, y, z); w < min {
			min = w
		}
	}
	return min
}

func (v Vector) ReverseMaxBy4(f func(int, int, int, int) int, x, y, z int) int {
	if len(v) == 0 {
		return math.MinInt64
	}
	max := f(v[len(v)-1], x, y, z)
	for i := len(v) - 2; i >= 0; i-- {
		if w := f(v[i], x, y, z); w > max {
			max = w
		}
	}
	return max
}

func (v Vector) UniqueBy4(f func(int, int, int, int) int, x, y, z int) Vector {
	if len(v) == 0 {
		return v
	}
	u := make([]int, 0, len(v))
	u = append(u, v[0])
	prev := f(v[0], x, y, z)
	for i := 1; i < len(v); i++ {
		if w := f(v[i], x, y, z); w != prev {
			u = append(u, v[i])
			prev = w
		}
	}
	return u
}

func (v Vector) ContainsBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) ReverseContainsBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) bool {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y, z) == g(x) {
			return true
		}
	}
	return false
}

func (v Vector) IndexBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) int {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) ReverseIndexBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) int {
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y, z) == g(x) {
			return i
		}
	}
	return -1
}

func (v Vector) CountBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) int {
	c := 0
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) ReverseCountBy4(x, y, z int, f func(int, int, int, int) int, g func(int) int) int {
	c := 0
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y, z) == g(x) {
			c++
		}
	}
	return c
}

func (v Vector) AllBy4(f func(int, int, int, int) bool, x, y, z int) bool {
	for i := 0; i < len(v); i++ {
		if !f(v[i], x, y, z) {
			return false
		}
	}
	return true
}

func (v Vector) AnyBy4(f func(int, int, int, int) bool, x, y, z int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) {
			return true
		}
	}
	return false
}

func (v Vector) NoneBy4(f func(int, int, int, int) bool, x, y, z int) bool {
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) {
			return false
		}
	}
	return true
}

func (v Vector) FilterBy4(f func(int, int, int, int) bool, x, y, z int) Vector {
	u := make([]int, 0, len(v))
	for i := 0; i < len(v); i++ {
		if f(v[i], x, y, z) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) ReverseFilterBy4(f func(int, int, int, int) bool, x, y, z int) Vector {
	u := make([]int, 0, len(v))
	for i := len(v) - 1; i >= 0; i-- {
		if f(v[i], x, y, z) {
			u = append(u, v[i])
		}
	}
	return u
}

func (v Vector) MapBy4(f func(int, int, int, int) int, g func(int) int, x, y, z int) Vector {
	u := make([]int, len(v))
	for i := 0; i < len(v); i++ {
		u[i] = f(g(v[i]), x, y, z)
	}
	return u
}

