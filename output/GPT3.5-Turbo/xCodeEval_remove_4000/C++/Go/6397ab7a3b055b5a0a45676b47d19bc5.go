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

func NewSegTree(n, init int) *SegTree {
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
	}
	return index*2 + 1
}

func (st *SegTree) rightOf(index int) int {
	if index >= st.base {
		return -1
	}
	return index*2 + 2
}

func (st *SegTree) parentOf(index int) int {
	if index == 0 {
		return -1
	}
	return (index - 1) >> 1
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

func (st *SegTree) Update(k, v int) {
	st.updateRec(k, k+1, 0, st.N, 0, v)
}

func (st *SegTree) Sum(s, t int) int {
	return st.addRec(s, t, 0, st.N, 0)
}

func id4(l, r int, v bsargv_t, evalFunc func(int, bsargv_t) bool) int {
	if r-l == 1 {
		if evalFunc(l, v) {
			return l
		} else {
			return l - 1
		}
	}
	m := (l + r) / 2
	if evalFunc(m, v) {
		return id4(m, r, v, evalFunc)
	} else {
		return id4(l, m, v, evalFunc)
	}
}

type bsargv_t struct {
	st   *SegTree
	s    int
	sum  int
}

func evalFunc(val int, v bsargv_t) bool {
	buf := v.st.Sum(v.s, val+1)
	if buf <= v.sum/2 {
		return true
	} else {
		return false
	}
}

const MOD = int(1e9) + 7

type modll struct {
	val int
}

func NewModll(init int) modll {
	return modll{val: modify(init)}
}

func (m modll) modify(x int) int {
	ret := x % MOD
	if ret < 0 {
		ret += MOD
	}
	return ret
}

func (m modll) inv(x int) int {
	if x == 0 {
		return 1 / x
	} else if x == 1 {
		return 1
	} else {
		return m.modify(m.inv(MOD%x) * m.modify(-MOD/x))
	}
}

func (m modll) Add(x modll) modll {
	return modll{val: m.modify(m.val + x.val)}
}

func (m modll) Sub(x modll) modll {
	return modll{val: m.modify(m.val - x.val)}
}

func (m modll) Mul(x modll) modll {
	return modll{val: m.modify(m.val * x.val)}
}

func (m modll) Div(x modll) modll {
	return modll{val: m.modify(m.val * m.inv(x.val))}
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

var facts []modll

func id7(n int) {
	if len(facts) == 0 {
		facts = append(facts, NewModll(1))
	}
	for i := len(facts); i <= n; i++ {
		facts = append(facts, facts[len(facts)-1].Mul(NewModll(i)))
	}
}

var ifacts []modll
var invs []modll

func id1(n int) {
	if len(invs) == 0 {
		invs = append(invs, NewModll(0))
		invs = append(invs, NewModll(1))
	}
	for i := len(invs); i <= n; i++ {
		invs = append(invs, invs[MOD%i].Mul(NewModll(MOD-(MOD/i))))
	}
}

func id0(n int) {
	id1(n)
	if len(ifacts) == 0 {
		ifacts = append(ifacts, NewModll(1))
	}
	for i := len(ifacts); i <= n; i++ {
		ifacts = append(ifacts, ifacts[len(ifacts)-1].Mul(invs[i]))
	}
}

func combination(n, r int) modll {
	if n >= r && r >= 0 {
		ret := NewModll(0)
		id7(n)
		id0(n)
		ret = facts[n].Mul(ifacts[r]).Mul(ifacts[n-r])
		return ret
	} else {
		return NewModll(0)
	}
}

func getFact(n int) modll {
	id7(n)
	return facts[n]
}

func id3(n int) modll {
	id0(n)
	return ifacts[n]
}

func discLog(a, b modll) int {
	ret := -1
	m := id8(MOD)
	mp := make(map[int]int)
	x := NewModll(1)
	for i := 0; i < m; i++ {
		mp[x.val] = i
		x = x.Mul(a)
	}
	x = NewModll(1).Div(a.Pow(m, 0))
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

func main() {
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
	for i := 0; i < q; i++ {
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
					v := bsargv_t{st: st, s: x, sum: st.Sum(x, y+1)}
					halfid = id4(x+1, y, v, evalFunc)
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
				buf = buf.Add(NewModll(dst).Mul(NewModll(st.Sum(x, dstid)))).Sub(ast.Sum(x, dstid)).Sub(NewModll(lst.Sum(x, dstid)).Sub(NewModll(st.Sum(x, dstid)).Mul(NewModll(n-1-dstid))))
				buf = buf.Add(ast.Sum(dstid, y+1)).Sub(NewModll(dst).Mul(NewModll(st.Sum(dstid, y+1)))).Sub(NewModll(rst.Sum(dstid, y+1)).Sub(NewModll(st.Sum(dstid, y+1)).Mul(NewModll(dstid))))
				ans = append(ans, buf)
			}
		}
	}
	for i := range ans {
		fmt.Println(ans[i])
	}
}
