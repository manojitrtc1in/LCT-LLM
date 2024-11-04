package main

import (
	"fmt"
	"math"
)

const (
	eps = 1e-9
	MOD = 1e9 + 7
)

type SegTree struct {
	n, N, base int
	nodes      []int64
}

func NewSegTree(n int, init int64) *SegTree {
	N := int(math.Pow(2, math.Ceil(math.Log2(float64(n)))))
	base := N - 1
	nodes := make([]int64, base+N)
	for i := range nodes {
		nodes[i] = init
	}
	return &SegTree{n: n, N: N, base: base, nodes: nodes}
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

func (st *SegTree) updateRec(s, t, l, r, index int, v int64) {
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

func (st *SegTree) Update(k int, v int64) {
	st.updateRec(k, k+1, 0, st.N, 0, v)
}

func (st *SegTree) addRec(s, t, l, r, index int) int64 {
	if s == l && t == r {
		return st.nodes[index]
	} else {
		mid := (l + r) / 2
		indexL := st.leftOf(index)
		indexR := st.rightOf(index)
		var v0, v1 int64
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

func (st *SegTree) Sum(s, t int) int64 {
	return st.addRec(s, t, 0, st.N, 0)
}

type modll struct {
	val int64
}

func (x modll) Modify(value int64) int64 {
	ret := value % int64(MOD)
	if ret < 0 {
		ret += int64(MOD)
	}
	return ret
}

func (x modll) Add(y modll) modll {
	return modll{x.Modify(x.val + y.val)}
}

func (x modll) Sub(y modll) modll {
	return modll{x.Modify(x.val - y.val)}
}

func (x modll) Mul(y modll) modll {
	return modll{x.Modify(x.val * y.val)}
}

func (x modll) Div(y modll) modll {
	return modll{x.Modify(x.val * x.Inv(y.val))}
}

func (x modll) Inv(value int64) int64 {
	if value == 0 {
		return 1 / value
	} else if value == 1 {
		return 1
	}
	return x.Modify(x.Inv(int64(MOD)%value) * x.Modify(-int64(MOD)/value))
}

func (x modll) GetVal() int64 {
	return x.val
}

func lowerBinarySearch(l, r int64, v bsargv_t, evalfunc func(int64, bsargv_t) bool) int64 {
	if r-l == 1 {
		if evalfunc(l, v) {
			return l
		}
		return l - 1
	}
	m := (l + r) / 2
	if evalfunc(m, v) {
		return lowerBinarySearch(m, r, v, evalfunc)
	}
	return lowerBinarySearch(l, m, v, evalfunc)
}

type bsargv_t struct {
	st  *SegTree
	s   int
	sum int64
}

func evalfunc(val int64, v bsargv_t) bool {
	buf := v.st.Sum(v.s, val+1)
	return buf <= v.sum/2
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	st := NewSegTree(n, 0)
	ast := NewSegTree(n, 0)
	lst := NewSegTree(n, 0)
	rst := NewSegTree(n, 0)

	for i := 0; i < n; i++ {
		var w int64
		fmt.Scan(&w)
		st.Update(i, w)
		ast.Update(i, modll{w}.Mul(modll{a[i]}).val)
		lst.Update(i, modll{w}.Mul(modll{int64(n - 1 - i)}).val)
		rst.Update(i, modll{w}.Mul(modll{int64(i)}).val)
	}

	var ans []modll
	for unused := 0; unused < q; unused++ {
		var x int
		fmt.Scan(&x)
		if x < 0 {
			x++
			var y int64
			fmt.Scan(&y)
			st.Update(-x, y)
			ast.Update(-x, modll{y}.Mul(modll{a[-x]}).val)
			lst.Update(-x, modll{y}.Mul(modll{int64(n - 1 - (-x))}).val)
			rst.Update(-x, modll{y}.Mul(modll{int64(-x)}).val)
		} else {
			var y int
			fmt.Scan(&y)
			x--
			y--
			if x == y {
				ans = append(ans, modll{0})
			} else {
				var halfid int
				if y-x == 1 {
					halfid = x
				} else {
					v := bsargv_t{st, x, st.Sum(x, y+1)}
					halfid = int(lowerBinarySearch(int64(x+1), int64(y), v, evalfunc))
				}
				cand0 := st.Sum(x, halfid+1)
				cand1 := st.Sum(halfid+1, y+1)
				var dst int64
				var dstid int
				if cand0 <= cand1 {
					dst = a[halfid+1]
					dstid = halfid + 1
				} else {
					dst = a[halfid]
					dstid = halfid
				}
				buf := modll{0}
				buf = buf.Add(modll{dst}.Mul(modll{st.Sum(x, dstid)}).Sub(ast.Sum(x, dstid)).Sub(lst.Sum(x, dstid).Sub(modll{st.Sum(x, dstid}.Mul(modll{int64(n - 1 - dstid}).val))))
				buf = buf.Add(ast.Sum(dstid, y+1).Sub(modll{dst}.Mul(modll{st.Sum(dstid, y+1)})).Sub(rst.Sum(dstid, y+1).Sub(modll{st.Sum(dstid, y+1)}.Mul(modll{int64(dstid)})))
				ans = append(ans, buf)
			}
		}
	}
	for _, value := range ans {
		fmt.Println(value.GetVal())
	}
}
