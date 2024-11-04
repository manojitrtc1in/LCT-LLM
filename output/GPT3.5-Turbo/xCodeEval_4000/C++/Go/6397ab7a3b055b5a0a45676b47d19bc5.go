package main

import (
	"fmt"
	"math"
)

type SegTree struct {
	n     int
	N     int
	base  int
	nodes []int
}

func NewSegTree(n int, init int) *SegTree {
	N := int(math.Pow(2, math.Ceil(math.Log2(float64(n)))))
	base := N - 1
	nodes := make([]int, base+N)
	for i := range nodes {
		nodes[i] = init
	}
	return &SegTree{
		n:     n,
		N:     N,
		base:  base,
		nodes: nodes,
	}
}

func (st *SegTree) leftOf(index int) int {
	if index >= st.base {
		return -1
	} else {
		return index*2 + 1
	}
}

func (st *SegTree) rightOf(index int) int {
	if index >= st.base {
		return -1
	} else {
		return index*2 + 2
	}
}

func (st *SegTree) parentOf(index int) int {
	if index == 0 {
		return -1
	} else {
		return (index - 1) >> 1
	}
}

func (st *SegTree) updateRec(s, t, l, r, index, v int) {
	if s == l && t == r {
		st.nodes[index] = v
	} else {
		mid := (l + r) / 2
		indexL := st.leftOf(index)
		indexR := st.rightOf(index)
		if s < mid && mid < t {
			st.updateRec(s, mid, l, mid, indexL, v)
			st.updateRec(mid, t, mid, r, indexR, v)
		} else if s < mid {
			st.updateRec(s, t, l, mid, indexL, v)
		} else if mid < t {
			st.updateRec(s, t, mid, r, indexR, v)
		}
		st.nodes[index] = st.nodes[indexL] + st.nodes[indexR]
	}
}

func (st *SegTree) addRec(s, t, l, r, index int) int {
	if s == l && t == r {
		return st.nodes[index]
	} else {
		mid := (l + r) / 2
		indexL := st.leftOf(index)
		indexR := st.rightOf(index)
		v0, v1 := 0, 0
		if s < mid && mid < t {
			v0 = st.addRec(s, mid, l, mid, indexL)
			v1 = st.addRec(mid, t, mid, r, indexR)
		} else if s < mid {
			v0 = st.addRec(s, t, l, mid, indexL)
		} else if mid < t {
			v1 = st.addRec(s, t, mid, r, indexR)
		}
		return v0 + v1
	}
}

func (st *SegTree) GetIndexAbove(index int, fromBase bool) []int {
	if fromBase {
		index += st.base
	}
	ret := []int{}
	for index >= 0 {
		ret = append(ret, index)
		index = st.parentOf(index)
	}
	return ret
}

func (st *SegTree) CoverSize(index int) int {
	cnt := 1
	for st.leftOf(index) != -1 {
		index = st.leftOf(index)
		cnt *= 2
	}
	l := index - st.base
	r := int(math.Min(float64(l+cnt), float64(st.n)))
	return int(math.Max(0, float64(r-l)))
}

func (st *SegTree) Update(k, v int) {
	st.updateRec(k, k+1, 0, st.N, 0, v)
}

func (st *SegTree) Sum(s, t int) int {
	return st.addRec(s, t, 0, st.N, 0)
}

type bsargv struct {
	st   *SegTree
	s    int
	sum  int
}

func evalfunc(val int, v bsargv) bool {
	buf := v.st.Sum(v.s, val+1)
	if buf <= v.sum/2 {
		return true
	} else {
		return false
	}
}

func lowerBinarySearch(l, r int, v bsargv, evalfunc func(int, bsargv) bool) int {
	if r-l == 1 {
		if evalfunc(l, v) {
			return l
		} else {
			return l - 1
		}
	}
	m := (l + r) / 2
	if evalfunc(m, v) {
		return lowerBinarySearch(m, r, v, evalfunc)
	} else {
		return lowerBinarySearch(l, m, v, evalfunc)
	}
}

type modll struct {
	val int
}

func NewModll(init int) modll {
	return modll{val: modify(init)}
}

func (m modll) Modify(x int) int {
	ret := x % MOD
	if ret < 0 {
		ret += MOD
	}
	return ret
}

func (m modll) Inv(x int) int {
	if x == 0 {
		return 1 / x
	} else if x == 1 {
		return 1
	} else {
		return m.Modify(m.Inv(MOD%x) * m.Modify(-MOD/x))
	}
}

func (m modll) Add(x modll) modll {
	return modll{val: m.Modify(m.val + x.val)}
}

func (m modll) Sub(x modll) modll {
	return modll{val: m.Modify(m.val - x.val)}
}

func (m modll) Mul(x modll) modll {
	return modll{val: m.Modify(m.val * x.val)}
}

func (m modll) Div(x modll) modll {
	return modll{val: m.Modify(m.val * m.Inv(x.val))}
}

func (m modll) Equal(x modll) bool {
	return m.val == x.val
}

func (m modll) NotEqual(x modll) bool {
	return m.val != x.val
}

func (m modll) Pow(n, p int) modll {
	ret := NewModll(0)
	if p == 0 {
		ret = NewModll(1)
	} else if p == 1 {
		ret = NewModll(n)
	} else {
		ret = m.Pow(n, p/2)
		ret = ret.Mul(ret)
		if p%2 == 1 {
			ret = ret.Mul(NewModll(n))
		}
	}
	return ret
}

func (m modll) Combination(n, r int) modll {
	if n >= r && r >= 0 {
		ret := NewModll(0)
		ret.MakeFacts(n)
		ret.MakeIfacts(n)
		ret = ret.Mul(ret.Facts[n])
		ret = ret.Mul(ret.Ifacts[r])
		ret = ret.Mul(ret.Ifacts[n-r])
		return ret
	} else {
		return NewModll(0)
	}
}

func (m modll) GetFact(n int) modll {
	ret := NewModll(0)
	ret.MakeFacts(n)
	return ret.Facts[n]
}

func (m modll) GetIfact(n int) modll {
	ret := NewModll(0)
	ret.MakeIfacts(n)
	return ret.Ifacts[n]
}

func (m modll) DiscLog(a, b modll) int {
	ret := -1
	m := CeilSqrt(MOD)
	mp := make(map[int]int)
	x := NewModll(1)
	for i := 0; i < m; i++ {
		mp[x.val] = i
		x = x.Mul(a)
	}
	x = NewModll(1).Div(m.Pow(a, m))
	k := b
	for i := 0; i < m; i++ {
		if _, ok := mp[k.val]; !ok {
			k = k.Mul(x)
		} else {
			ret = i*m + mp[k.val]
			break
		}
	}
	return ret
}

func (m modll) MakeFacts(n int) {
	if len(m.Facts) == 0 {
		m.Facts = append(m.Facts, NewModll(1))
	}
	for i := len(m.Facts); i <= n; i++ {
		m.Facts = append(m.Facts, m.Facts[i-1].Mul(NewModll(i)))
	}
}

func (m modll) MakeIfacts(n int) {
	m.MakeInvs(n)
	if len(m.Ifacts) == 0 {
		m.Ifacts = append(m.Ifacts, NewModll(1))
	}
	for i := len(m.Ifacts); i <= n; i++ {
		m.Ifacts = append(m.Ifacts, m.Ifacts[i-1].Mul(m.Invs[i]))
	}
}

func (m modll) MakeInvs(n int) {
	if len(m.Invs) == 0 {
		m.Invs = append(m.Invs, NewModll(0))
		m.Invs = append(m.Invs, NewModll(1))
	}
	for i := len(m.Invs); i <= n; i++ {
		m.Invs = append(m.Invs, m.Invs[MOD%i].Mul(NewModll(MOD-(MOD/i))))
	}
}

func (m modll) Combination(n, r int) modll {
	if n >= r && r >= 0 {
		ret := NewModll(0)
		ret.MakeFacts(n)
		ret.MakeIfacts(n)
		ret = ret.Mul(ret.Facts[n])
		ret = ret.Mul(ret.Ifacts[r])
		ret = ret.Mul(ret.Ifacts[n-r])
		return ret
	} else {
		return NewModll(0)
	}
}

func (m modll) GetFact(n int) modll {
	ret := NewModll(0)
	ret.MakeFacts(n)
	return ret.Facts[n]
}

func (m modll) GetIfact(n int) modll {
	ret := NewModll(0)
	ret.MakeIfacts(n)
	return ret.Ifacts[n]
}

func (m modll) DiscLog(a, b modll) int {
	ret := -1
	m := CeilSqrt(MOD)
	mp := make(map[int]int)
	x := NewModll(1)
	for i := 0; i < m; i++ {
		mp[x.val] = i
		x = x.Mul(a)
	}
	x = NewModll(1).Div(m.Pow(a, m))
	k := b
	for i := 0; i < m; i++ {
		if _, ok := mp[k.val]; !ok {
			k = k.Mul(x)
		} else {
			ret = i*m + mp[k.val]
			break
		}
	}
	return ret
}

const (
	eps  = 1e-9
	INFD = math.Inf(1)
	PI   = 3.14159265358979323846
)

func Loop(n int, f func(int)) {
	for i := 0; i < n; i++ {
		f(i)
	}
}

func Loopll(n int, f func(int)) {
	for i := int64(0); i < int64(n); i++ {
		f(int(i))
	}
}

func Loop1(n int, f func(int)) {
	for i := 1; i <= n; i++ {
		f(i)
	}
}

func Loopll1(n int, f func(int)) {
	for i := int64(1); i <= int64(n); i++ {
		f(int(i))
	}
}

func Loopr(n int, f func(int)) {
	for i := n - 1; i >= 0; i-- {
		f(i)
	}
}

func Looprll(n int, f func(int)) {
	for i := int64(n) - 1; i >= 0; i-- {
		f(int(i))
	}
}

func Loopr1(n int, f func(int)) {
	for i := n; i >= 1; i-- {
		f(i)
	}
}

func Looprll1(n int, f func(int)) {
	for i := int64(n); i >= 1; i-- {
		f(int(i))
	}
}

func Foreach(container []int, f func(int)) {
	for _, buf := range container {
		f(buf)
	}
}

func Loopdiag(h, w, sum int, f func(int, int)) {
	i := sum
	j := sum - i
	for i >= 0 && j < w {
		f(i, j)
		i--
		j++
	}
}

func Loopdiagr(h, w, sum int, f func(int, int)) {
	j := sum
	i := sum - j
	for j >= 0 && i < h {
		f(i, j)
		j--
		i++
	}
}

func Loopdiagsym(h, w, gap int, f func(int, int)) {
	i := gap
	j := i - gap
	for i < h && j < w {
		f(i, j)
		i++
		j++
	}
}

func Loopdiagsymr(h, w, gap int, f func(int, int)) {
	i := gap
	j := i - gap
	for i >= 0 && j >= 0 {
		f(i, j)
		i--
		j--
	}
}

func Loopitr(container []int, f func(int, []int)) {
	for i, itr := range container {
		f(i, itr)
	}
}

func printv(vector []int) {
	for _, ex_i := range vector {
		fmt.Printf("%d ", ex_i)
	}
	fmt.Println()
}

func printmx(matrix [][]int) {
	for _, ex_i := range matrix {
		for _, ex_j := range ex_i {
			fmt.Printf("%d ", ex_j)
		}
		fmt.Println()
	}
}

func quickio() {
	// TODO: Implement quickio function
}

func bitmanip(m, val int) int {
	return val & ((1 << m) - 1)
}

type Comp struct {
	type_t int
}

func (c Comp) Less(another Comp) bool {
	return c.type_t < another.type_t
}

type P struct {
	fst int
	snd int
}

type Pll struct {
	fst int
	snd int
}

type Cdouble struct {
	real  float64
	imag  float64
}

func nearlyeq(x, y float64) bool {
	return math.Abs(x-y) < eps
}

func inrange(x, t int) bool {
	return x >= 0 && x < t
}

func inrangev(xs []int, t int) bool {
	for _, x := range xs {
		if !(x >= 0 && x < t) {
			return false
		}
	}
	return true
}

func ceillog2(x int) int {
	ret := 0
	x--
	for x > 0 {
		ret++
		x >>= 1
	}
	return ret
}

func rndf(x float64) int {
	return int(x + math.Copysign(0.5, x))
}

func floorsqrt(x int) int {
	m := int(math.Sqrt(float64(x)))
	if m*m <= x {
		return m
	} else {
		return m - 1
	}
}

func ceilsqrt(x int) int {
	m := int(math.Sqrt(float64(x)))
	if x <= m*m {
		return m
	} else {
		return m + 1
	}
}

func rnddiv(a, b int) int {
	if a/b+(a%b*2 >= b) == 1 {
		return a/b + 1
	} else {
		return a / b
	}
}

func ceildiv(a, b int) int {
	if a/b+(a%b == 0) == 1 {
		return a/b + 1
	} else {
		return a / b
	}
}

func gcd(m, n int) int {
	if n == 0 {
		return m
	} else {
		return gcd(n, m%n)
	}
}

func lcm(m, n int) int {
	return m * n / gcd(m, n)
}

const MOD = int(1e9 + 7)

func main() {
	quickio()
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	st := NewSegTree(n, 0)
	ast := NewSegTree(n, 0)
	lst := NewSegTree(n, 0)
	rst := NewSegTree(n, 0)
	for i := 0; i < n; i++ {
		var w int
		fmt.Scan(&w)
		st.Update(i, w)
		ast.Update(i, NewModll(w).Mul(NewModll(a[i])))
		lst.Update(i, NewModll(w).Mul(NewModll(n-1-i)))
		rst.Update(i, NewModll(w).Mul(NewModll(i)))
	}
	ans := []modll{}
	for unused := 0; unused < q; unused++ {
		var x int
		fmt.Scan(&x)
		if x < 0 {
			x++
			var y int
			fmt.Scan(&y)
			st.Update(-x, y)
			ast.Update(-x, NewModll(y).Mul(NewModll(a[-x])))
			lst.Update(-x, NewModll(y).Mul(NewModll(n-1-(-x))))
			rst.Update(-x, NewModll(y).Mul(NewModll(-x)))
		} else {
			var y int
			fmt.Scan(&y)
			x--
			y--
			if x == y {
				ans = append(ans, NewModll(0))
			} else {
				var halfid int
				if y-x == 1 {
					halfid = x
				} else {
					v := bsargv{st: st, s: x, sum: st.Sum(x, y+1)}
					halfid = lowerBinarySearch(x+1, y, v, evalfunc)
				}
				cand0 := st.Sum(x, halfid+1)
				cand1 := st.Sum(halfid+1, y+1)
				var dst int
				var dstid int
				if cand0 <= cand1 {
					dst = a[halfid+1]
					dstid = halfid + 1
				} else {
					dst = a[halfid]
					dstid = halfid
				}
				buf := NewModll(0)
				buf = buf.Add(NewModll(dst).Mul(NewModll(st.Sum(x, dstid))))
				buf = buf.Sub(ast.Sum(x, dstid))
				buf = buf.Sub(lst.Sum(x, dstid).Sub(NewModll(st.Sum(x, dstid)).Mul(NewModll(n-1-dstid))))
				buf = buf.Add(rst.Sum(dstid, y+1).Sub(NewModll(st.Sum(dstid, y+1)).Mul(NewModll(dstid))))
				ans = append(ans, buf)
			}
		}
	}
	for _, a := range ans {
		fmt.Println(a)
	}
}
