package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 1000000007
const MODL = 1000000000000000003
const eps = 1e-8

type lld int64
type u64 uint64
type pii struct{ first, second int }

func MIN[T comparable](x, y T) T {
	if x < y {
		return x
	}
	return y
}

func MAX[T comparable](x, y T) T {
	if x > y {
		return x
	}
	return y
}

func id1[T comparable](x *T, y T) {
	if *x > y {
		*x = y
	}
}

func id0[T comparable](x *T, y T) {
	if *x < y {
		*x = y
	}
}

func SIZE[T any](x []T) int {
	return len(x)
}

func LENGTH[T any](x string) int {
	return len(x)
}

func MP[T1, T2 any](x T1, y T2) (T1, T2) {
	return x, y
}

func BINT(x int) int {
	return 1 << x
}

func BLLD(x int) lld {
	return 1 << uint(x)
}

func id9(s int, x int) bool {
	return (s&BINT(x)) != 0
}

func id5(s lld, x int) bool {
	return (s&BLLD(x)) != 0
}

func LOWBIT[T any](x T) T {
	return (x ^ (x - 1)) & x
}

func BITCOUNT[T any](x T) int {
	if x == 0 {
		return 0
	}
	return 1 + BITCOUNT(x & (x - 1))
}

const PI = math.Pi
const EPS = 1e-5

func SQR[T any](x T) T {
	return x * x
}

func POW[T any](x T, y int) T {
	if y == 0 {
		return 1
	} else if y%2 == 0 {
		return SQR(POW(x, y/2))
	} else {
		return POW(x, y-1) * x
	}
}

func GCD[T int | int64](x, y T) T {
	if x < 0 {
		return GCD(-x, y)
	}
	if y < 0 {
		return GCD(x, -y)
	}
	if y == 0 {
		return x
	}
	return GCD(y, x%y)
}

func LCM[T int | int64](x, y T) T {
	if x < 0 {
		return LCM(-x, y)
	}
	if y < 0 {
		return LCM(x, -y)
	}
	return x * (y / GCD(x, y))
}

func EEA[T int | int64](a, b T) (T, T, T) {
	x, y := T(0), T(0)
	if a < 0 {
		d, x1, y1 := EEA(-a, b)
		x = -x1
		return d, x, y1
	}
	if b < 0 {
		d, x1, y1 := EEA(a, -b)
		y = -y1
		return d, x1, y
	}
	if b == 0 {
		x = 1
		y = 0
		return a, x, y
	}
	d, x1, y1 := EEA(b, a%b)
	t := x1
	x = y1
	y = t - (a/b)*y1
	return d, x, y
}

func id2[T int | int64](x T) []pii {
	ret := []pii{}
	if x < 0 {
		x = -x
	}
	for i := T(2); x > 1; {
		if x%i == 0 {
			count := 0
			for x%i == 0 {
				x /= i
				count++
			}
			ret = append(ret, MP(i, count))
		}
		i++
		if i > x/i {
			i = x
		}
	}
	return ret
}

func id16[T int | int64](x T) int {
	if x <= 1 {
		return 0
	}
	for i := T(2); SQR(i) <= x; i++ {
		if x%i == 0 {
			return 0
		}
	}
	return 1
}

func id6[T int | int64](x T) T {
	f := id2(x)
	for _, it := range f {
		x = x / it.first * (it.first - 1)
	}
	return x
}

func id14[T int | int64](a T, b ...T) T {
	m := MOD
	if len(b) > 0 {
		m = b[0]
	}
	x, y, _ := EEA(a, m)
	if x != 0 {
		return x
	}
	return 1
}

func id15(til int) []int {
	foo := make([]int, til+1)
	len := 0
	for i := 2; i <= til; i++ {
		if foo[i] == 0 {
			foo[len] = i
			len++
		}
		for j := 0; j < len && foo[j] <= til/i; j++ {
			foo[foo[j]*i] = 1
			if i%foo[j] == 0 {
				break
			}
		}
	}
	foo = append(foo[:len], 0)
	return foo
}

func MOD_STD[T int | int64](x T, m ...T) T {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	return (x%mVal + mVal) % mVal
}

func MOD_ADD[T int | int64](x, y T, m ...T) T {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	return (x + y) % mVal
}

func id4[T int | int64](x, y T, m ...T) T {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	return T((1LL * x * y) % mVal)
}

func id10[T1 int | int64, T2 int | int64](x T1, y T2, m ...T1) T1 {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	if y == 0 {
		return 1 % mVal
	} else if y%2 == 0 {
		z := id10(x, y/2, mVal)
		return id4(z, z, mVal)
	} else {
		return id4(id10(x, y-1, mVal), x, mVal)
	}
}

func id12(x, y lld, m ...lld) lld {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	if x < y {
		x, y = y, x
	}
	z := lld(0)
	for y > 0 {
		if y&1 != 0 {
			z = MOD_ADD(z, x, mVal)
		}
		x = MOD_ADD(x, x, mVal)
		y >>= 1
	}
	return z
}

func id3(x, y lld, m ...lld) lld {
	mVal := MOD
	if len(m) > 0 {
		mVal = m[0]
	}
	if y == 0 {
		return 1 % mVal
	} else if y%2 == 0 {
		z := id3(x, y/2, mVal)
		return id12(z, z, mVal)
	} else {
		return id12(id3(x, y-1, mVal), x, mVal)
	}
}

type MATX[T any] struct {
	hig, wid uint64
	data     []T
}

func NewMATX[T any](hig, wid uint64) *MATX[T] {
	data := make([]T, hig*wid)
	return &MATX[T]{hig: hig, wid: wid, data: data}
}

func (m *MATX[T]) At(x, y uint64) T {
	if x >= m.hig || y >= m.wid {
		var zero T
		return zero
	}
	return m.data[x*m.wid+y]
}

func (m *MATX[T]) Set(x, y uint64, value T) {
	if x < m.hig && y < m.wid {
		m.data[x*m.wid+y] = value
	}
}

func (m *MATX[T]) Add(rhs *MATX[T]) *MATX[T] {
	ret := NewMATX[T](m.hig, m.wid)
	for x := uint64(0); x < m.hig; x++ {
		for y := uint64(0); y < m.wid; y++ {
			ret.Set(x, y, m.At(x, y)+rhs.At(x, y))
		}
	}
	return ret
}

func (m *MATX[T]) Sub(rhs *MATX[T]) *MATX[T] {
	ret := NewMATX[T](m.hig, m.wid)
	for x := uint64(0); x < m.hig; x++ {
		for y := uint64(0); y < m.wid; y++ {
			ret.Set(x, y, m.At(x, y)-rhs.At(x, y))
		}
	}
	return ret
}

func (m *MATX[T]) Mul(rhs *MATX[T]) *MATX[T] {
	ret := NewMATX[T](m.hig, rhs.wid)
	for x := uint64(0); x < m.hig; x++ {
		for y := uint64(0); y < rhs.wid; y++ {
			for z := uint64(0); z < m.wid; z++ {
				ret.Set(x, y, ret.At(x, y)+m.At(x, z)*rhs.At(z, y))
			}
		}
	}
	return ret
}

func (m *MATX[T]) Pow(p uint64) *MATX[T] {
	buff := *m
	ret := NewMATX[T](m.hig, m.wid)
	ret.Set(0, 0, 1) // Set identity
	if p > 0 {
		for i := uint64(1); ; i <<= 1 {
			if p&i != 0 {
				ret = ret.Mul(&buff)
			}
			buff = *buff.Mul(&buff)
			if i > (p >> 1) {
				break
			}
		}
	}
	return ret
}

type complexT[T any] struct {
	r, i T
}

func NewComplexT[T any](x, y T) complexT[T] {
	return complexT[T]{r: x, i: y}
}

func (c complexT[T]) Add(opn complexT[T]) complexT[T] {
	return NewComplexT(c.r+opn.r, c.i+opn.i)
}

func (c complexT[T]) Sub(opn complexT[T]) complexT[T] {
	return NewComplexT(c.r-opn.r, c.i-opn.i)
}

func (c complexT[T]) Mul(opn complexT[T]) complexT[T] {
	return NewComplexT(c.r*opn.r-c.i*opn.i, c.r*opn.i+c.i*opn.r)
}

func id8[T any](f []complexT[T], len int, id11 int) {
	for i, j := 1, len>>1; i < len-1; i++ {
		if i < j {
			f[i], f[j] = f[j], f[i]
		}
		k := len >> 1
		for j >= k {
			j -= k
			k >>= 1
		}
		if j < k {
			j += k
		}
	}
	for h := 2; h <= len; h <<= 1 {
		wn := NewComplexT(math.Cos(float64(id11)*(-2*PI/float64(h))), math.Sin(float64(id11)*(-2*PI/float64(h))))
		for i := 0; i < len; i += h {
			wm := NewComplexT(1.0, 0.0)
			for j := i; j < i+(h>>1); j++ {
				u := f[j]
				t := wm.Mul(f[j+(h>>1)])
				f[j] = u.Add(t)
				f[j+(h>>1)] = u.Sub(t)
				wm = wm.Mul(wn)
			}
		}
	}
	if id11 == 0 {
		for i := 0; i < len; i++ {
			f[i].r /= T(len) * 1.0
		}
	}
}

type MILLERRABIN struct{}

func (m *MILLERRABIN) witness(a, d, s, n lld) int {
	r := id3(a, d)
	if r == 1 || r == n-1 {
		return 0
	}
	for i := 0; i < int(s)-1; i++ {
		r = id12(r, r)
		if r == 1 {
			return 1
		}
		if r == n-1 {
			return 0
		}
	}
	return 1
}

func (m *MILLERRABIN) test(n lld) int {
	if n <= 2 {
		return 0
	}
	p := n - 1
	s := lld(0)
	for p&1 == 0 {
		p >>= 1
		s++
	}
	primeTable := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
	for _, prime := range primeTable {
		if prime < int(n) && m.witness(lld(prime), p, s, n) != 0 {
			return 0
		}
	}
	return 1
}

func fsign[T float64 | int](x T) int {
	if x > -eps && x < eps {
		return 0
	}
	if x < 0 {
		return -1
	}
	return 1
}

type pointT[T any] struct {
	x, y T
}

func NewPointT[T any](x, y T) pointT[T] {
	return pointT[T]{x: x, y: y}
}

func (p pointT[T]) Sub(rhs pointT[T]) pointT[T] {
	return NewPointT(p.x-rhs.x, p.y-rhs.y)
}

func (p pointT[T]) Cross(rhs pointT[T]) T {
	return p.x*rhs.y - p.y*rhs.x
}

func (p pointT[T]) Dot(rhs pointT[T]) T {
	return p.x*rhs.x + p.y*rhs.y
}

func (p pointT[T]) Dist(rhs pointT[T]) T {
	return math.Sqrt(float64(p.Sub(rhs).Dot(p.Sub(rhs))))
}

type segmentT[T any] struct {
	p, q pointT[T]
}

func NewSegmentT[T any](px, py, qx, qy T) segmentT[T] {
	return segmentT[T]{p: NewPointT(px, py), q: NewPointT(qx, qy)}
}

func (s segmentT[T]) Length() T {
	return s.p.Dist(s.q)
}

func (s segmentT[T]) Contain(pnt pointT[T], ignoreEndpoint int) int {
	if ignoreEndpoint != 0 {
		return fsign(s.p.Sub(pnt).Cross(s.q.Sub(pnt))) == 0 &&
			fsign((pnt.x-s.p.x)*(pnt.x-s.q.x)) < 0 &&
			fsign((pnt.y-s.p.y)*(pnt.y-s.q.y)) < 0
	} else {
		return fsign(s.p.Sub(pnt).Cross(s.q.Sub(pnt))) == 0 &&
			fsign((pnt.x-s.p.x)*(pnt.x-s.q.x)) <= 0 &&
			fsign((pnt.y-s.p.y)*(pnt.y-s.q.y)) <= 0
	}
}

func (s segmentT[T]) Intersection(sa, sb segmentT[T], ignoreEndpoint int) int {
	if ignoreEndpoint == 0 {
		if sa.Contain(sb.p, 0) != 0 || sa.Contain(sb.q, 0) != 0 || sb.Contain(sa.p, 0) != 0 || sb.Contain(sa.q, 0) != 0 {
			return 1
		}
	}
	return fsign(sa.p.Cross(sa.q, sb.p))*fsign(sa.p.Cross(sa.q, sb.q)) < 0 &&
		fs(sign(sb.p.Cross(sb.q, sa.p))*fsign(sb.p.Cross(sb.q, sa.q)) < 0
}

func (s segmentT[T]) IntersectionWith(rhs segmentT[T], ignoreEndpoint int) int {
	return s.Intersection(s, rhs, ignoreEndpoint)
}

type id13 struct {
	foo map[int]int
}

func NewId13() *id13 {
	return &id13{foo: make(map[int]int)}
}

func (id *id13) Clear() {
	id.foo = make(map[int]int)
}

func (id *id13) Put(key int, val int) {
	if val == 0 {
		return
	}
	if _, exists := id.foo[key]; exists {
		id.foo[key] += val
	} else {
		id.foo[key] = val
	}
}

func (id *id13) Pop(key int, val int) int {
	res := 0
	if v, exists := id.foo[key]; exists {
		if v > val {
			res = val
			id.foo[key] -= val
		} else {
			res = v
			delete(id.foo, key)
		}
	}
	return res
}

var (
	n    int
	a    [110000]lld
	_seq [50]int
	_sup [50]int
	seq  [50]int
	sup  [50]int
)

func process(from int) int {
	copy(seq[:], _seq[:])
	copy(sup[:], _sup[:])
	if from+from < seq[0] {
		return 1
	}
	open := NewId13()
	close := NewId13()
	open.Put(0, from-(seq[0]-from))
	close.Put(0, seq[0]-from)
	for i := 1; i < 45; i++ {
		ext := open.Pop(i-1, seq[i])
		seq[i] -= ext
		open.Put(i, ext)
		ext = close.Pop(i-1, seq[i])
		sup[i] += seq[i] - ext
		close.Put(i, ext)
		cls := open.Pop(i, sup[i])
		sup[i+1] += sup[i] - cls
		close.Put(i, cls)
	}
	if sup[45] != 0 {
		return 1
	}
	return 0
}

func find(lef, rig int) int {
	for lef <= rig {
		mid := (lef + rig) >> 1
		if process(mid) == 0 {
			if mid == lef || process(mid-1) != 0 {
				return mid
			}
			rig = mid - 1
		} else {
			lef = mid + 1
		}
	}
	return -1
}

func main() {
	for {
		if _, err := fmt.Scan(&n); err != nil {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < 50; i++ {
			_seq[i] = 0
			_sup[i] = 0
		}
		cur := 0
		for i := 0; i < n; i++ {
			for a[i] >= (1<<(cur+1)) {
				cur++
			}
			if a[i] == (1 << cur) {
				_seq[cur]++
			} else {
				_sup[cur]++
			}
		}
		if process(_seq[0]) != 0 {
			fmt.Println("-1")
		} else {
			hig := _seq[0]
			low := find(1, hig)
			for i := low; i <= hig; i++ {
				if i != low {
					fmt.Print(" ")
				}
				fmt.Print(i)
			}
			fmt.Println()
		}
	}
}
